#include "stdafx.h"
#include <thread>
#include <functional>
#include <chrono>
#include "CT3Scan.h"
#include "../Public/util/IULog.h"

CT3Scan::CT3Scan(ControlerInterface* in_controler) : LineDetScanInterface(in_controler)
{

}
//���½�����
//���ɨ�����
void CT3Scan::scanThread()
{
	while (d_threadRun)
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void CT3Scan::startScan()
{
	std::thread runThread(std::bind(&CT3Scan::scanThread, this));
	runThread.detach();
}

bool CT3Scan::setGenerialFileHeader()
{
	d_ictHeader.DataFormat.graduationBase = 0;						//3��ɨ����ʼ�ֶ�
	int	i, N;														//��������
	int	Matrix;														//����ߴ�
	float diameter;													//�ӳ�ֱ��
	float rotAngle;                                                 //��ת�Ƕ�
	float space;													//����
	int scanPosSel;													//CT�ֲ㷽ʽ:0-��ǰ��, 1-�Ȳ��, 2-���Ȳ��
	float centerOffset;								   				//��ת����ƫ��(mm)

	d_ictHeader.ScanParameter.ScanMode = CT3_SCAN;

	//���޹ز�������Ĭ��ֵ
	d_ictHeader.ScanParameter.NumberofValidVerticalDetector = 
		d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].NumberOfSystemHorizontalDetector;
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
}

void CT3Scan::stopScan()
{

}
