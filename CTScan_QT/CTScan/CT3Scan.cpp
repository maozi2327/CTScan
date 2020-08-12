#include "stdafx.h"
#include <functional>
#include <chrono>
#include "ct3scan.h"
#include "linedetnetwork.h"
#include "linedetimageprocess.h"
#include "../Public/util/IULog.h"
#include "../Public/util/Thread.h"
#include "../Public/util/functions.h"
#include "motorcontrolwidget.h"
#include "../Public/headers/setupdata.h"
#include "../Public/util/macro.h"
#include "simotioncontroller.h"

CT3Scan::CT3Scan(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWork, 
	CT3Data& in_data) : LineDetScanInterface(in_controller, in_lineDetNetWork)
	, d_ct3Data(in_data)
{
	;
}

CT3Scan::~CT3Scan()
{
	if(d_scanThread.get() != nullptr)
		d_scanThread->stopThread();
}

bool CT3Scan::setScanParameter(float in_layer, int in_matrix, float in_view, 
	int in_sampleTime, float in_angle)
{
	d_layer = in_layer;
	d_matrix = in_matrix;
	d_view = in_view;
	d_sampleTime = in_sampleTime;
	d_angle = in_angle;
	return true;
}

//更新进度条
//检查扫描结束
void CT3Scan::scanThread()
{
	if (d_lineDetNetWork->startExtTrigAcquire())
	{
		sendCmdToControl();

		while (d_threadRun)
		{
			emit(signalGraduationCount(d_lineDetNetWork->getGraduationCount()));

			if (d_controller->readSaveStatus())
			{
				saveFile();
				stopScan();
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	else
		;
}


void CT3Scan::sendCmdToControl()
{
	char buf[RTBUF_LEN];
	CT23ScanCmdData	cmdData, *pCmdData;
	cmdData.stsBit.s.changeLayerSpace = 0;
	cmdData.stsBit.s.czAmountInc1 = d_ictHeader.ScanParameter.InterpolationFlag;
	cmdData.stsBit.s.currentLayer = 0;
	cmdData.stsBit.s1.physiInterpolation = d_setupData->interpolationModeDefine;
	cmdData.stsBit.s.thirdGeneration = 1;
	cmdData.interpolationAmount = (BYTE)d_ictHeader.ScanParameter.NumberOfInterpolation;
	cmdData.projectionAmount = d_ictHeader.ScanParameter.Pixels;
	cmdData.sampleTime = (WORD)(1000 * d_ictHeader.ScanParameter.SampleTime);
	cmdData.viewDiameter = d_ictHeader.ScanParameter.ViewDiameter;
	cmdData.orientInc = (short)d_ictHeader.ScanParameter.Azimuth;
	cmdData.ct2Mode = 0;
	cmdData.sliceAmount = d_ictHeader.ScanParameter.TotalLayers;
	cmdData.tabelNumber = 0;
	cmdData.reserved1 = 0;
	cmdData.centerOffset = 0;
	cmdData.stsBit.s.btnStartScan = 0;
	cmdData.stsBit.s.autoStopBeam = 0;
	cmdData.firstLayerOffset = d_layer;
	cmdData.layerSpace = 0;
	COMM_PACKET* ptr = (COMM_PACKET*)buf;
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_CT_SCAN;
	ptr->tagLen = 3 + sizeof(CT23ScanCmdData);
	memcpy(buf + 6, &cmdData, sizeof(cmdData));
	d_controller->sendToControl(buf, 6 + sizeof(CT23ScanCmdData));
}


void CT3Scan::saveFile()
{
	saveOrgFile();
	QString orgFilaName(d_orgPath + d_fileName + ".org");
	QString disposedFilaName(d_orgPath + d_fileName);
	d_lineDetImageProcess->dispose(d_installDirectory, orgFilaName, disposedFilaName);
}

bool CT3Scan::beginScan()
{	
	if (canScan())
	{
		d_scanThread.reset(new Thread(std::bind(&CT3Scan::scanThread, this), 
			std::ref(d_threadRun)));
		return d_scanThread->detach();
	}	
	else
		return false;
}

CT3Data CT3Scan::getData()
{
	return d_ct3Data;
}

bool CT3Scan::setGenerialFileHeader()
{
	LineDetScanInterface::setGenerialFileHeader();

	d_ictHeader.DataFormat.graduationBase = 0;						//3代扫描起始分度
	d_ictHeader.ScanParameter.ScanMode = static_cast<char>(ScanMode::CT3_SCAN);
	d_ictHeader.ScanParameter.NumberOfGraduation = d_matrix;
	d_ictHeader.ScanParameter.Azimuth = d_angle;
	d_ictHeader.ScanParameter.NumberofValidVerticalDetector =
		d_setupData->lineDetData[d_lineDetIndex].NumberOfSystemHorizontalDetector;
	//对无关参数设置默认值
	d_ictHeader.ScanParameter.RadialDistanceInLocal = 0;
	d_ictHeader.ScanParameter.AngleInLocal = 0;
	d_ictHeader.ScanParameter.HelixScanPitch = 0;
	d_ictHeader.ScanParameter.FirstSectStartCoordinateOfDR = 0;
	d_ictHeader.ScanParameter.SecondSectStartCoordinateOfDR = 0;
	d_ictHeader.ScanParameter.TotalLayers2 = 0;
	d_ictHeader.ScanParameter.Ct2ScanMode = 0;
	d_ictHeader.ScanParameter.DataTransferMode = 1;
	d_ictHeader.ScanParameter.NumberOfTranslation = 0;
	d_ictHeader.ReconstructParameter.NumberOfGraduationOfCt2 = 0;
	d_ictHeader.ReconstructParameter.SerialOfGraduationOfCt2 = 0;
	d_ictHeader.ScanParameter.ViewDiameter = d_viewDiameter;
	d_ictHeader.ScanParameter.NumberOfTable = 1;
	d_ictHeader.ScanParameter.LargeViewCenterOffset = 0;
	d_ictHeader.ScanParameter.Pixels = d_matrix;
	d_ictHeader.ScanParameter.GraduationDirection = P_DIR;
	d_ictHeader.ScanParameter.DelaminationMode = 0;
	CalculateView_ValidDetector(d_view);
	d_ictHeader.ScanParameter.InterpolationFlag = d_setupData->ct3InterpolationFlag;
	d_ictHeader.ScanParameter.NumberOfInterpolation = (float)d_matrix / d_ictHeader.ScanParameter.NumberOfValidHorizontalDetector + 1;
	int N = d_ictHeader.ScanParameter.NumberOfSystemHorizontalDetector;
	float d = PI * d_ictHeader.ScanParameter.HorizontalSectorAngle / (180 * (N - 1));
	d *= d_ictHeader.ScanParameter.SourceDetectorDistance;
	N = d_ictHeader.ScanParameter.NumberOfInterpolation;

	if ((d / N < d_setupData->minInterpolationSpace) || (N > 80)) 
	{
		//LOG_WARNING("插值次数太多！视场直径%.0f, 图像矩阵%d", d_view, d_matrix);
		return false;
	}

	return true;
}

bool CT3Scan::canScan()
{
	QString str;

	if(!LineDetScanInterface::canScan())
	{
		LOG_ERROR(str.fromLocal8Bit("控制器未就绪"));
		return false;
	}

	if (!d_controller->checkReadyToScan())
	{
		LOG_ERROR(str.fromLocal8Bit("控制器未就绪"));
		return false;
	}

	return true;
}

void CT3Scan::stopScan()
{
	d_threadRun = false;
}
