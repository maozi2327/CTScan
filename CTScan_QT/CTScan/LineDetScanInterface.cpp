#include "stdafx.h"
#include "linedetscaninterface.h"
#include "../Public/util/iulog.h"
#include "linedetnetwork.h"
#include "linedetimageprocess.h"
#include "../Public/util/thread.h"
#include "controllerinterface.h"
#include <algorithm>

ICT_HEADER23 LineDetScanInterface::d_ictHeader;
LineDetScanInterface::LineDetScanInterface(ControllerInterface * in_controller, LineDetNetWork* in_lineDetNetWork)
	: d_controller(in_controller), d_lineDetNetWork(in_lineDetNetWork)
{

}

LineDetScanInterface::~LineDetScanInterface()
{

}

void LineDetScanInterface::stopScan()
{
	d_controller->stopAll();
	d_lineDetNetWork->clearRowList();
}

void LineDetScanInterface::saveOrgFile()
{
	QString fileFullName(d_orgPath + d_fileName);
	d_lineDetImageProcess->saveOrgFile(fileFullName, &d_ictHeader, d_lineDetNetWork->getRowList(), 1);
}

bool LineDetScanInterface::setGenerialFileHeader()
{
	d_ictHeader.MainVersion = MainVersion23;							//定义数据文件头主版本号
	d_ictHeader.SubVersion = SubVersion23;							//定义数据文件头次版本号

	d_ictHeader.DataFormat.DataType = LONGDATA;						//数据类型: 长整型
	d_ictHeader.DataFormat.appendColAtRow = 2;						//每行附加数据个数
	strcpy_s(d_ictHeader.SystemParameter.ModelOfCT, d_setupData->szDeviceModel);//CT设备型号
	d_ictHeader.DataFormat.dataColAtRow
		= d_setupData->lineDetData[d_lineDetIndex].NumberOfSystemHorizontalDetector;

	//设置射线源参数
	if (d_rayType == RayType::Accelerator)
	{
		d_ictHeader.SystemParameter.RaySort = 0;
		d_ictHeader.SystemParameter.RayEngery = d_setupData->acceleratorData[d_AccIndex].rayEnergy;
		d_ictHeader.SystemParameter.RayDosage = d_setupData->acceleratorData[d_AccIndex].rayDoseRate;
		d_ictHeader.SystemParameter.SynchFrequency = d_setupData->acceleratorData[d_AccIndex].syncFreqDefine[d_accFrecIndex];
	}
	else if (d_rayType == RayType::Tube)
	{
		d_ictHeader.SystemParameter.RaySort = 0;
		d_ictHeader.SystemParameter.RayEngery = d_setupData->acceleratorData[d_AccIndex].rayEnergy;
		d_ictHeader.SystemParameter.RayDosage = d_setupData->acceleratorData[d_AccIndex].rayDoseRate;
		d_ictHeader.SystemParameter.SynchFrequency = 250;
	}

	//设置探测器参数
	d_ictHeader.SystemParameter.AmplifyMultiple = d_setupData->lineDetData[d_lineDetIndex].AmplifyMultiple;
	d_ictHeader.SystemParameter.IntegralTime = d_setupData->lineDetData[d_lineDetIndex].IntegralTime;
	d_ictHeader.ScanParameter.DetectorStyle
		= d_setupData->lineDetData[d_lineDetIndex].LineDetType;
	d_ictHeader.ScanParameter.NumberOfSystemHorizontalDetector
		= d_setupData->lineDetData[d_lineDetIndex].NumberOfSystemHorizontalDetector;
	d_ictHeader.ScanParameter.SerialNo1OfMiddleHorizontalDetector
		= d_setupData->lineDetData[d_lineDetIndex].BeginSerialNoOfCt2Detector;
	d_ictHeader.ScanParameter.SerialNo2OfMiddleHorizontalDetector
		= d_setupData->lineDetData[d_lineDetIndex].EndSerialNoOfCt2Detector;
	d_ictHeader.ScanParameter.NumberofSystemVerticalDetector = 1;
	d_ictHeader.ScanParameter.SpaceOfHorizontalDetector	= 0;
	d_ictHeader.ScanParameter.SpaceOfVerticalDetector = 0;
	d_ictHeader.ScanParameter.HorizontalSectorAngle = d_setupData->lineDetData[d_lineDetIndex].HorizontalDetectorAngle;
	d_ictHeader.ScanParameter.VerticalSectorAngle = 0;
	d_ictHeader.ScanParameter.RadialPosition = d_controller->readAxisPostion(Axis::objRadial);
	d_ictHeader.ScanParameter.SourceDetectorDistance = d_controller->readAxisPostion(Axis::detRadial);
	d_ictHeader.ScanParameter.CollimationSize = d_colimateSize;
	d_ictHeader.ScanParameter.LayerThickness = d_layerThickness;
	d_ictHeader.ScanParameter.SampleTime = d_sampleTime / 1000;
	d_ictHeader.ScanParameter.SetupSynchPulseNumber
		= (WORD)(d_ictHeader.ScanParameter.SampleTime * d_ictHeader.SystemParameter.SynchFrequency);
	
	//设置时间
	QString time = QDateTime::currentDateTime().time().toString();
	QByteArray byteArray = time.toLatin1();
	strcpy_s(d_ictHeader.Task.DateTime.Date, byteArray.data());
	QString date = QDateTime::currentDateTime().date().toString(Qt::ISODate);
	byteArray = date.toLatin1();
	strcpy_s(d_ictHeader.Task.DateTime.Time, byteArray);

	strcpy_s(d_ictHeader.ScanParameter.FilenameTemperature, "");
	strcpy_s(d_ictHeader.ScanParameter.FilenameOfCTdata, "");
	strcpy_s(d_ictHeader.ScanParameter.FilenameOf2CTdata, "");
	strcpy_s(d_ictHeader.ScanParameter.FilenameOfPictureData, "");
	return true;
}

void LineDetScanInterface::CalculateView_ValidDetector(float in_diameter)
{
	int systemDetector = d_setupData->lineDetData[d_lineDetIndex].NumberOfSystemHorizontalDetector;
	int calibrateDetector = d_setupData->lineDetData[d_lineDetIndex].NumberOfCalibrateHorizontalDetector;
	int realSysDetectorNum = systemDetector - calibrateDetector;
	float delta = d_setupData->lineDetData[d_lineDetIndex].HorizontalDetectorAngle / 180 * PI;

	int leftMiddle = d_ictHeader.ScanParameter.SerialNo1OfMiddleHorizontalDetector;
	int rightMiddle = d_ictHeader.ScanParameter.SerialNo2OfMiddleHorizontalDetector;

	if (d_standardInterpolation)		//确定3代扫描有效探测器数Nv
	{
		int	Nv;

		if (leftMiddle == rightMiddle)
			Nv = 2 * std::min<int>(rightMiddle, systemDetector - rightMiddle - 1) + 1;
		else
			Nv = 2 * std::min<int>(rightMiddle, systemDetector - rightMiddle);
		
		d_ictHeader.ScanParameter.NumberOfValidHorizontalDetector = Nv;
		in_diameter = 2 * d_SOD * (float)sin(delta*(Nv - 1) / 2);
	}
	else 
	{
		float beta = (float)(2 * asin(in_diameter / 2 / d_SOD));        //计算视场D占用的扇角beta
		int	Nv;

		if (leftMiddle == rightMiddle)
			Nv = 2 * (int)(beta / 2 / delta) + 1;
		else															//探测器不通过扇面中心线， 有效探测器设置为偶数
			Nv = 2 * (int)(beta / 2 / delta);

		if (Nv > realSysDetectorNum)
			Nv = realSysDetectorNum;

		d_ictHeader.ScanParameter.NumberOfValidHorizontalDetector = Nv;
		in_diameter = 2 * in_diameter * (float)sin(delta*(Nv - 1) / 2);
	}

	d_ictHeader.ScanParameter.ViewDiameter = (float)((int)(100.0 * in_diameter)) / 100;
}

bool LineDetScanInterface::canScan()
{	//初始化，探测器，执行命令
	if (!d_lineDetNetWork->getConnected())
	{
		LOG_ERROR(QString::fromLocal8Bit("探测器未连接！"));
		return false;
	}

	if (!d_controller->getConnected())
		return false;

	if (!d_controller->readReadyStatus())
		return false;

	if (!d_controller->readRunStatus())
		return false;

	return true;
}
