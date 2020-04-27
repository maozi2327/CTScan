#include "stdafx.h"
#include <functional>
#include <chrono>
#include "CT3Scan.h"
#include "LineDetNetWork.h"
#include "LineDetImageProcess.h"
#include "../Public/util/IULog.h"
#include "../Public/util/Thread.h"
#include "MotorControl.h"
#include "functions.h"

CT3Scan::CT3Scan(ControllerInterface* in_controller) : LineDetScanInterface(in_controller)
{
	;
}

CT3Scan::~CT3Scan()
{
	d_scanThread->stopThread();
}

//���½�����
//���ɨ�����
void CT3Scan::scanThread()
{
	while (d_threadRun)
	{
		emit(signalGraduationCount(d_lineDetNetWork->getGraduationCount()));
		
		if (d_controller->readSaveStatus())
		{
			saveFile();
			stopScan();
			d_threadRun = false;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

#define	RTBUF_LEN	256						//�������/���ͻ���������
struct COMM_PACKET {
	BYTE	tagHead[3];						//��ͷ(0x55,0xaa,0x5a)
	BYTE	typeCode;						//������
	WORD	tagLen;							//����(=�����ֽ���+3, ʵ���������ݰ�����=����+4)
	BYTE	data[RTBUF_LEN - 6];			//�������
};

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
	cmdData.firstLayerOffset = d_scanPos;
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
	d_lineDetImageProcess->dispose(d_installDirectory, d_fileName, d_destFileName);
}

bool CT3Scan::startScan()
{
	sendCmdToControl();
	d_scanThread.reset(new Thread(std::bind(&CT3Scan::scanThread, this), std::ref(d_threadRun)));
	return d_scanThread->detach();
}

bool CT3Scan::setGenerialFileHeader()
{
	LineDetScanInterface::setGenerialFileHeader();

	d_ictHeader.DataFormat.graduationBase = 0;						//3��ɨ����ʼ�ֶ�
	int	i, N;														//��������
	int	Matrix;														//����ߴ�
	float diameter;													//�ӳ�ֱ��
	float rotAngle;                                                 //��ת�Ƕ�
	float space;													//����
	int scanPosSel;													//CT�ֲ㷽ʽ:0-��ǰ��, 1-�Ȳ��, 2-���Ȳ��
	float centerOffset;								   				//��ת����ƫ��(mm)

	d_ictHeader.ScanParameter.ScanMode = static_cast<char>(ScanMode::CT3_SCAN);

	//���޹ز�������Ĭ��ֵ
	d_ictHeader.ScanParameter.NumberofValidVerticalDetector = 
		d_setupData->lineDetData[d_lineDetIndex].NumberOfSystemHorizontalDetector;
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
	d_ictHeader.ScanParameter.LeftSerialNoOfTable = 0;
	d_ictHeader.ScanParameter.NumberOfTable = 1;
	d_ictHeader.ScanParameter.LargeViewCenterOffset = 0;
	d_ictHeader.ScanParameter.Pixels = Matrix;
	d_ictHeader.ScanParameter.NumberOfGraduation = Matrix;
	d_ictHeader.ScanParameter.Azimuth = rotAngle;
	d_ictHeader.ScanParameter.SpaceBetweenLayer = space;
	d_ictHeader.ScanParameter.GraduationDirection = P_DIR;
	d_ictHeader.ScanParameter.DelaminationMode = 0;

	CalculateView_ValidDetector(diameter);

	d_ictHeader.ScanParameter.InterpolationFlag = d_setupData->ct3InterpolationFlag;
	d_ictHeader.ScanParameter.NumberOfInterpolation = (float)Matrix / d_ictHeader.ScanParameter.NumberOfValidHorizontalDetector + 1;
	N = d_ictHeader.ScanParameter.NumberOfSystemHorizontalDetector;
	float d = PI * d_ictHeader.ScanParameter.HorizontalSectorAngle / (180 * (N - 1));
	d *= d_ictHeader.ScanParameter.SourceDetectorDistance;
	N = d_ictHeader.ScanParameter.NumberOfInterpolation;

	if ((d / N < d_setupData->minInterpolationSpace) || (N > 80)) 
	{
		LOG_WARNING("��ֵ����̫�࣡�ӳ�ֱ��%d, ͼ�����%d", diameter, Matrix);
		return false;
	}

	return true;
}

bool CT3Scan::checkScanAble()
{
	return false;
}

void CT3Scan::stopScan()
{

}
