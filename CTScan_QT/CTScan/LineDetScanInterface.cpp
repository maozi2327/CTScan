#include "stdafx.h"
#include "LineDetScanInterface.h"
#include "LineDetNetWork.h"
#include "LineDetImageProcess.h"
#include <algorithm>

LineDetScanInterface::~LineDetScanInterface()
{

}

void LineDetScanInterface::stopScan()
{
	d_controler->stopAll();
	d_lineDetNetWork->clearRowList();
}

void LineDetScanInterface::saveOrgFile()
{
	d_lineDetImageProcess->saveOrgFile(d_fileName, &d_ictHeader, d_lineDetNetWork->getRowList(), 1);
}

bool LineDetScanInterface::setGenerialFileHeader()
{
	d_ictHeader.MainVersion = MainVersion23;							//���������ļ�ͷ���汾��
	d_ictHeader.SubVersion = SubVersion23;							//���������ļ�ͷ�ΰ汾��

	d_ictHeader.DataFormat.DataType = LONGDATA;						//��������: ������
	d_ictHeader.DataFormat.appendColAtRow = 2;						//ÿ�и������ݸ���
	strcpy_s(d_ictHeader.SystemParameter.ModelOfCT, d_setupData->szDeviceModel);//CT�豸�ͺ�
	d_ictHeader.DataFormat.dataColAtRow
		= d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].NumberOfSystemHorizontalDetector;

	//��������Դ����
	if (d_rayType == RayType::Accelerator)
	{
		d_ictHeader.SystemParameter.RaySort = 0;
		d_ictHeader.SystemParameter.RayEngery = d_setupData->acceleratorData.AcceleratorParameter[d_AccIndex].rayEnergy;
		d_ictHeader.SystemParameter.RayDosage = d_setupData->acceleratorData.AcceleratorParameter[d_AccIndex].rayDoseRate;
		d_ictHeader.SystemParameter.SynchFrequency = d_setupData->acceleratorData.AcceleratorParameter[d_AccIndex].syncFreqDefine[d_accFrecIndex];
	}
	else if (d_rayType == RayType::Tube)
	{
		d_ictHeader.SystemParameter.RaySort = 0;
		d_ictHeader.SystemParameter.RayEngery = d_setupData->acceleratorData.AcceleratorParameter[d_AccIndex].rayEnergy;
		d_ictHeader.SystemParameter.RayDosage = d_setupData->acceleratorData.AcceleratorParameter[d_AccIndex].rayDoseRate;
		d_ictHeader.SystemParameter.SynchFrequency = 250;
	}

	//����̽��������
	d_ictHeader.SystemParameter.AmplifyMultiple = d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].AmplifyMultiple;
	d_ictHeader.SystemParameter.IntegralTime = d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].IntegralTime;
	d_ictHeader.ScanParameter.DetectorStyle
		= d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].LineDetType;
	d_ictHeader.ScanParameter.NumberOfSystemHorizontalDetector
		= d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].NumberOfSystemHorizontalDetector;
	d_ictHeader.ScanParameter.SerialNo1OfMiddleHorizontalDetector
		= d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].BeginSerialNoOfCt2Detector;
	d_ictHeader.ScanParameter.SerialNo2OfMiddleHorizontalDetector
		= d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].EndSerialNoOfCt2Detector;
	d_ictHeader.ScanParameter.NumberofSystemVerticalDetector = 1;
	d_ictHeader.ScanParameter.SpaceOfHorizontalDetector	= 0;
	d_ictHeader.ScanParameter.SpaceOfVerticalDetector = 0;
	d_ictHeader.ScanParameter.HorizontalSectorAngle = d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].HorizontalDetectorAngle;
	d_ictHeader.ScanParameter.VerticalSectorAngle = 0;
	d_ictHeader.ScanParameter.RadialPosition = d_SOD;
	d_ictHeader.ScanParameter.SourceDetectorDistance = d_SDD;
	d_ictHeader.ScanParameter.CollimationSize = d_colimateSize;
	d_ictHeader.ScanParameter.LayerThickness = d_layerThickness;
	d_ictHeader.ScanParameter.SampleTime = d_sampleTime / 1000;
	d_ictHeader.ScanParameter.SetupSynchPulseNumber
		= (WORD)(d_ictHeader.ScanParameter.SampleTime * d_ictHeader.SystemParameter.SynchFrequency);
	
	//����ʱ��
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
}

void LineDetScanInterface::CalculateView_ValidDetector(float in_diameter)
{
	int systemDetector = d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].NumberOfSystemHorizontalDetector;
	int calibrateDetector = d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].NumberOfCalibrateHorizontalDetector;
	int realSysDetectorNum = systemDetector - calibrateDetector;
	float delta = d_setupData->lineDetData.lineDetParameter[d_lineDetIndex].HorizontalDetectorAngle / 180 * PI;

	int leftMiddle = d_ictHeader.ScanParameter.SerialNo1OfMiddleHorizontalDetector;
	int rightMiddle = d_ictHeader.ScanParameter.SerialNo2OfMiddleHorizontalDetector;

	//ȷ��3��ɨ����Ч̽������Nv
	if (d_standardInterpolation)
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
		//�����ӳ�Dռ�õ��Ƚ�beta
		float beta = (float)(2 * asin(in_diameter / 2 / d_SOD));
		int	Nv;

		if (leftMiddle == rightMiddle)
			Nv = 2 * (int)(beta / 2 / delta) + 1;
		else															//̽������ͨ�����������ߣ� ��Ч̽��������Ϊż��
			Nv = 2 * (int)(beta / 2 / delta);

		if (Nv > realSysDetectorNum)
			Nv = realSysDetectorNum;

		d_ictHeader.ScanParameter.NumberOfValidHorizontalDetector = Nv;
		in_diameter = 2 * in_diameter * (float)sin(delta*(Nv - 1) / 2);
	}

	d_ictHeader.ScanParameter.ViewDiameter = (float)((int)(100.0 * in_diameter)) / 100;
}