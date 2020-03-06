#include "stdafx.h"
#include "LineDetScanInterface.h"

LineDetScanInterface::~LineDetScanInterface()
{

}

void LineDetScanInterface::setGenerialFileHeader()
{
	char strDeviceModel[32];

	CString str;													//�ַ�������
	int	i;															//��������

	//���ð汾��Ϣ
	ictHeader.MainVersion = MainVersion23;							//���������ļ�ͷ���汾��
	ictHeader.SubVersion = SubVersion23;							//���������ļ�ͷ�ΰ汾��

	ictHeader.DataFormat.graduationBase = 0;						//3��ɨ����ʼ�ֶ�
	ictHeader.DataFormat.DataType = LONGDATA;						//��������: ������
	ictHeader.DataFormat.dataColAtRow
		= setupData.geometryPara.NumberOfSystemHorizontalDetector;	//ϵͳ̽��������
	ictHeader.DataFormat.appendColAtRow = 2;						//ÿ�и������ݸ���

	strcpy_s(ictHeader.SystemParameter.ModelOfCT, setupData.geometryPara.szDeviceModel);//CT�豸�ͺ�
	ictHeader.SystemParameter.RaySort = setupData.rayDefine;		//����Դ����(TUBE/ACCELERATOR/ISOTOPE);
	ictHeader.SystemParameter.RayEngery = setupData.rayEnergy / 1000;	//��������(MeV)
	ictHeader.SystemParameter.RayDosage = setupData.rayDoseRate;	//���߼�����(cGy/min/m)
	i = setupData.syncFreqCurSel;									//��ȡͬ��Ƶ��(Hz)
	if (i < 0)														//δѡ��ͬ��Ƶ��, ������Ϊ250Hz
		ictHeader.SystemParameter.SynchFrequency = 250;
	else
		ictHeader.SystemParameter.SynchFrequency = setupData.syncFreqDefine[i];
	ictHeader.SystemParameter.AmplifyMultiple = setupData.AmplifyMultiple;//�����Ŵ���
	if (sysStatus.s.bRaySourceSel)
		ictHeader.SystemParameter.IntegralTime = setupData.IntegralTime2;//��������ʱ��(us)
	else
		ictHeader.SystemParameter.IntegralTime = setupData.IntegralTime;//��������ʱ��(us)

	//����ɨ�����
	//1. ���νṹ����
	ictHeader.ScanParameter.DetectorStyle							//��ǰʹ�õ�̽�����ṹ(0-����, 1-ֱ��, 2-ƽ��)
		= setupData.geometryPara.DetectorInUse;
	ictHeader.ScanParameter.NumberOfSystemHorizontalDetector		//����ƽ�淽��ϵͳ̽������(�˲���Ϊ̽��������)
		= setupData.geometryPara.NumberOfSystemHorizontalDetector;
	ictHeader.ScanParameter.SerialNo1OfMiddleHorizontalDetector		//����ƽ�淽������̽�������1(����/ֱ��̽����, ��0��ʼ����)
		= setupData.geometryPara.SerialNo1OfMiddleHorizontalDetector;
	ictHeader.ScanParameter.SerialNo2OfMiddleHorizontalDetector		//����ƽ�淽������̽�������2(����/ֱ��̽����, ��0��ʼ����)
		= setupData.geometryPara.SerialNo2OfMiddleHorizontalDetector;
	ictHeader.ScanParameter.NumberofSystemVerticalDetector			//����ƽ�洹ֱ����ϵͳ̽������(ƽ��̽����ר��, �˲���Ϊ̽��������)
		= setupData.geometryPara.NumberofSystemVerticalDetector;
	ictHeader.ScanParameter.SpaceOfHorizontalDetector				//����ƽ�淽��̽�������(mm, ƽ��̽����ר��)
		= setupData.geometryPara.SpaceOfHorizontalDetector;
	ictHeader.ScanParameter.SpaceOfVerticalDetector					//����ƽ�洹ֱ����̽�������(mm, ƽ��̽����ר��)
		= setupData.geometryPara.SpaceOfVerticalDetector;
	ictHeader.ScanParameter.HorizontalSectorAngle					//����ƽ�淽���Ƚ�(��,��ϵͳ̽���������, ����Ϊ����̽����������֮��н�)
		= setupData.geometryPara.HorizontalSectorAngle;
	ictHeader.ScanParameter.VerticalSectorAngle						//����ƽ�洹ֱ�����Ƚ�(��,��ϵͳ̽���������, ����Ϊ����̽����������֮��н�)
		= setupData.geometryPara.VerticalSectorAngle;

	int j = setupData.scanModeCurSel;									//��ȡɨ��ģʽ����
	int Mode = setupData.scanModeDefine[j];								//ModeΪɨ��ģʽ����

	if (Mode == CT2_SCAN)
		ictHeader.ScanParameter.RadialPosition = 700;							//���㵽��ת���ľ���Q(����λ��)(mm)    
	else
		ictHeader.ScanParameter.RadialPosition							//���㵽��ת���ľ���Q(����λ��)(mm)    
		= setupData.geometryPara.RadialPosition;
	ictHeader.ScanParameter.SourceDetectorDistance					//���㵽̽��������P(mm)
		= setupData.geometryPara.SourceDetectorDistance;
	ictHeader.ScanParameter.BeginSerialNoOfCt2Detector				//���ɨ�迪ʼ̽�������(��0��ʼ), V2.3������
		= setupData.geometryPara.BeginSerialNoOfCt2Detector;
	ictHeader.ScanParameter.EndSerialNoOfCt2Detector				//���ɨ�����̽�������(��0��ʼ), V2.3������
		= setupData.geometryPara.EndSerialNoOfCt2Detector;

	i = setupData.collimateCurSel;									//��ȡ׼ֱ������
	i = setupData.collimateDefine[i];
	ictHeader.ScanParameter.CollimationSize = i;					//׼ֱ���ߴ����:0,1,2...   ׼ֱ�����
	i = setupData.layerThickCurSel;									//��ȡ�ϲ���
	ictHeader.ScanParameter.LayerThickness							//�ϲ���(mm)(׼ֱ���߶�)
		= setupData.layerThickDefine[i];

	//	ictHeader.ScanParameter.SetupSynchPulseNumber = 0;				//Ԥ��ͬ��������(���������, ��V2.3�汾�в���ʹ��)
	i = setupData.sampleTimeCurSel;									//��ȡ����ʱ��
	ictHeader.ScanParameter.SampleTime 								//����ʱ��, ��λ:��
		= (float)setupData.sampleTimeDefine[i] / 1000;				//msת��Ϊs
	ictHeader.ScanParameter.SetupSynchPulseNumber					//Ԥ��������
		= (WORD)(ictHeader.ScanParameter.SampleTime * ictHeader.SystemParameter.SynchFrequency);

	//���ò���������Ϣ
	//���ò������ڼ�ʱ��(20�ֽ�:2003-07-10 16:35:12 )
	CTime tm = CTime::GetCurrentTime();								//ȡ�õ�ǰʱ��

	str = tm.Format("%Y-%m-%d");
	//�½���������ʽת��һ��
	wchar_t strWChar[50];
	char strChar[50];
	wcscpy_s(strWChar, str);
	//ע�⣺ת������=�ַ�������+1;
	//WChar2Char(strWChar,wcslen(strWChar)+1,strChar,wcslen(strWChar)+1);
	myWChar2Char((CString)strWChar, strChar);
	strcpy_s(ictHeader.Task.DateTime.Date, strChar);

	str = tm.Format("%H:%M:%S");
	wcscpy_s(strWChar, str);
	//ע�⣺ת������=�ַ�������+1;
	//WChar2Char(strWChar,wcslen(strWChar)+1,strChar,wcslen(strWChar)+1);
	myWChar2Char((CString)strWChar, strChar);
	strcpy_s(ictHeader.Task.DateTime.Time, strChar);


	myWChar2Char((CString)setupData.m_testUnit, ictHeader.Task.SubmitUnit);
	myWChar2Char((CString)setupData.m_testTaskNumber, ictHeader.Task.Number);
	myWChar2Char((CString)setupData.m_testTaskName, ictHeader.Task.Name);
	myWChar2Char((CString)setupData.m_testStaff, ictHeader.Task.Toastmaster);

	myWChar2Char((CString)setupData.workPiece.WorkpieceName, ictHeader.Workpiece.WorkpieceName);
	myWChar2Char((CString)setupData.workPiece.WorkpieceModel, ictHeader.Workpiece.WorkpieceModel);
	myWChar2Char((CString)setupData.workPiece.WorkpieceNumber, ictHeader.Workpiece.WorkpieceNumber);
	myWChar2Char((CString)setupData.workPiece.WorkpieceBatch, ictHeader.Workpiece.WorkpieceBatch);
	myWChar2Char((CString)setupData.workPiece.WorkpieceShellMaterial, ictHeader.Workpiece.WorkpieceShellMaterial);
	myWChar2Char((CString)setupData.workPiece.WorkpieceFillMaterial, ictHeader.Workpiece.WorkpieceFillMaterial);
	myWChar2Char((CString)setupData.workPiece.WorkpieceManufacturer, ictHeader.Workpiece.WorkpieceManufacturer);
	myWChar2Char((CString)setupData.workPiece.WorkpieceMakeDate, ictHeader.Workpiece.WorkpieceMakeDate);
	myWChar2Char((CString)setupData.workPiece.WorkpieceTestPosition, ictHeader.Workpiece.WorkpieceTestPosition);

	myWChar2Char((CString)setupData.workPiece2.WorkpieceName, ictHeader.Workpiece.WorkpieceName2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceModel, ictHeader.Workpiece.WorkpieceModel2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceNumber, ictHeader.Workpiece.WorkpieceNumber2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceBatch, ictHeader.Workpiece.WorkpieceBatch2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceShellMaterial, ictHeader.Workpiece.WorkpieceShellMaterial2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceFillMaterial, ictHeader.Workpiece.WorkpieceFillMaterial2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceManufacturer, ictHeader.Workpiece.WorkpieceManufacturer2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceMakeDate, ictHeader.Workpiece.WorkpieceMakeDate2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceTestPosition, ictHeader.Workpiece.WorkpieceTestPosition2);
	//�ļ���Ϣ
	strcpy_s(ictHeader.ScanParameter.FilenameTemperature, "");		//̽��ϵͳʵʱ�¶ȼ�¼�ļ���
	strcpy_s(ictHeader.ScanParameter.FilenameOfCTdata, "");			//CT�����ļ���,��Windows�ļ���������ַ���(���ڴ��CT��DR��׶��ɨ������)
	strcpy_s(ictHeader.ScanParameter.FilenameOf2CTdata, "");			//������ݱ߲ɱߴ��ļ���(�������ļ������ϱ��(00-31))
	strcpy_s(ictHeader.ScanParameter.FilenameOfPictureData, "");		//ͼ�������ļ���, ��Windows�ļ���������ַ���

	return(TRUE);
}
