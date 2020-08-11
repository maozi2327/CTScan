#include "stdafx.h"
#include "LineDetNetWork.h"
#include "LineDetAirTune.h"
#include "LineDetImageProcess.h"
#include "../Public/util/Thread.h"
#include "../Public/util/functions.h"
#include "controllerinterface.h"

bool LineDetAirTune::setGenerialFileHeader()
{
	LineDetScanInterface::setGenerialFileHeader();
	d_ictHeader.ScanParameter.NumberOfTable = 1;					//校正扫描转台数量
	d_ictHeader.ScanParameter.LargeViewCenterOffset = 0;			//大视场扫描回转中心偏置(同时用于多转台扫描回转中心偏移)
	d_ictHeader.ScanParameter.Pixels = TUNE_PROJECTIONS;			//V2.3中定义为射线平面图像像素个数(投影数M), 取消V2.2中代号表示方式

	d_ictHeader.ScanParameter.Azimuth = 0;							//CT扫描时分度起始方位角(°),或DR扫描角度
	d_ictHeader.ScanParameter.SpaceBetweenLayer						//CT层距/DR分层厚度, 单位:mm
		=0;
	d_ictHeader.ScanParameter.GraduationDirection = P_DIR;			//分度方向:N_DIR-顺时针(负方向), P_DIR-逆时针(正方向)

	d_ictHeader.ScanParameter.ViewDiameter = 300;
	d_ictHeader.ScanParameter.NumberOfValidHorizontalDetector = 
		d_setupData->lineDetData[d_lineDetIndex].NumberOfSystemHorizontalDetector;
	d_ictHeader.ScanParameter.InterpolationFlag = 0;
	d_ictHeader.ScanParameter.NumberOfInterpolation = 1;
	d_ictHeader.ScanParameter.NumberOfGraduation = TUNE_PROJECTIONS;
	d_ictHeader.ScanParameter.DelaminationMode = 0;
	d_ictHeader.ScanParameter.TotalLayers = 1;
	return false;
}

#define	RTBUF_LEN	256						//定义接收/发送缓冲区长度
//struct COMM_PACKET {
//	BYTE	tagHead[3];						//包头(0x55,0xaa,0x5a)
//	BYTE	typeCode;						//类型码
//	WORD	tagLen;							//包长(=参数字节数+3, 实际命令数据包长度=包长+4)
//	BYTE	data[RTBUF_LEN - 6];			//命令参数
//};

void LineDetAirTune::sendCmdToControl()
{
	char buf[RTBUF_LEN];
	COMM_PACKET* ptr = (COMM_PACKET*)buf;
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = static_cast<char>(ScanMode::AIR_SCAN);
	ptr->tagLen = 3 + 0;
	d_controller->sendToControl(buf, 6);
}

void LineDetAirTune::scanThread()
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



void LineDetAirTune::saveFile()
{
	saveOrgFile();
	d_lineDetImageProcess->createBkgDat(d_fileName, d_installDirectory);
}

LineDetAirTune::LineDetAirTune(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor) : LineDetScanInterface(in_controller, in_lineDetNetWor)
{

}


LineDetAirTune::~LineDetAirTune()
{

}

bool LineDetAirTune::checkScanAble()
{
	return false;
}

bool LineDetAirTune::startScan()
{
	if (!checkScanAble())
		return false;

	setGenerialFileHeader();
	sendCmdToControl();
	d_scanThread.reset(new Thread(std::bind(&LineDetAirTune::scanThread, this), std::ref(d_threadRun)));
	d_scanThread->detach();
	return true;
}

void LineDetAirTune::stopScan()
{
	LineDetScanInterface::stopScan();
}
