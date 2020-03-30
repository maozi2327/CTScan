#include "stdafx.h"
#include <thread>
#include <functional>
#include <chrono>
#include "CT3Scan.h"
#include "../Public/util/IULog.h"

CT3Scan::CT3Scan(ControlerInterface* in_controler) : LineDetScanInterface(in_controler)
{

}
//更新进度条
//检查扫描结束
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
	d_ictHeader.DataFormat.graduationBase = 0;						//3代扫描起始分度
	int	i, N;														//整数变量
	int	Matrix;														//矩阵尺寸
	float diameter;													//视场直径
	float rotAngle;                                                 //旋转角度
	float space;													//层间距
	int scanPosSel;													//CT分层方式:0-当前层, 1-等层距, 2-不等层距
	float centerOffset;								   				//回转中心偏移(mm)

	d_ictHeader.ScanParameter.ScanMode = CT3_SCAN;

	//对无关参数设置默认值
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
		LOG_WARNING("插值次数太多！视场直径%d, 图像矩阵%d", diameter, Matrix);
		return false;
	}
}

void CT3Scan::stopScan()
{

}
