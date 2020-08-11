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
	d_ictHeader.ScanParameter.NumberOfTable = 1;					//У��ɨ��ת̨����
	d_ictHeader.ScanParameter.LargeViewCenterOffset = 0;			//���ӳ�ɨ���ת����ƫ��(ͬʱ���ڶ�ת̨ɨ���ת����ƫ��)
	d_ictHeader.ScanParameter.Pixels = TUNE_PROJECTIONS;			//V2.3�ж���Ϊ����ƽ��ͼ�����ظ���(ͶӰ��M), ȡ��V2.2�д��ű�ʾ��ʽ

	d_ictHeader.ScanParameter.Azimuth = 0;							//CTɨ��ʱ�ֶ���ʼ��λ��(��),��DRɨ��Ƕ�
	d_ictHeader.ScanParameter.SpaceBetweenLayer						//CT���/DR�ֲ���, ��λ:mm
		=0;
	d_ictHeader.ScanParameter.GraduationDirection = P_DIR;			//�ֶȷ���:N_DIR-˳ʱ��(������), P_DIR-��ʱ��(������)

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

#define	RTBUF_LEN	256						//�������/���ͻ���������
//struct COMM_PACKET {
//	BYTE	tagHead[3];						//��ͷ(0x55,0xaa,0x5a)
//	BYTE	typeCode;						//������
//	WORD	tagLen;							//����(=�����ֽ���+3, ʵ���������ݰ�����=����+4)
//	BYTE	data[RTBUF_LEN - 6];			//�������
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
