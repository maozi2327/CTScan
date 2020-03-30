#ifndef	__SETUPDATA_H
#define	__SETUPDATA_H

#include "CtrlData.h"
//ϵͳ�����������ݽṹ�ļ�

/*
��λ��IP��ַ����:
IP��ַ:		192.168.2.124
��������:	255.255.255.0
Ĭ������:	192.168.2.1

DNS������:	202.202.0.33
*/
//const char szAcquireClientIP[]="192.168.2.120";						//�ɼ��ͻ���IP��ַ
const wchar_t szAcquireClientIP[]=_T("192.168.2.120");						//�ɼ��ͻ���IP��ַ
const unsigned short nAcquireClientPort	= 4000;						//�ɼ��ͻ��˶˿ڵ�ַ

const wchar_t szCtoSIP[]=_T("192.168.1.122");						//�ͻ���-������IP��ַ
const wchar_t szUnerCtrlerIP[]=_T("192.168.0.124");					//���ƿͻ���IP��ַ
const unsigned short nUnerCtrlerPort	= 8000;						//���ƿͻ��˶˿ڵ�ַ

//const char szAcquireInterfaceIP[]="192.168.2.120";					//�ɼ���IP��ַ
#define	nComPortMaxNum	8											//���崮��ͨ�Ŷ˿��������
const char szCom[nComPortMaxNum][16]={"COM1","COM2","COM3","COM4","COM5","COM6","COM7","COM8"};

#define	MAX_PARA_ITEM	    20										//��������
#define	MAX_STR_LENGTH	    100										//����ַ�������
#define MAX_PASSWORD_LENGTH 32                                      //������봮����
#define	MAX_BLOCK		    160										//��8Ϊ��λ�����̽��ģ����(��������AcquireInterface.h�ж���һ��)
#define	MAX_COMMONMODE_ITEM	20										//�����ģʽ����
#define	MAX_SCANCONFIG_ITEM	32										//���ɨ����̬����

//ɨ��ģʽ�ַ�����
const wchar_t szScanModeText[20][32]={
	_T("���ɨ��"),_T("���CTɨ��"),_T("���CTɨ��"),_T("DRɨ��"),
	_T("�ֲ�ɨ��"),_T("����ɨ��"),_T("׶��ɨ��"),_T("׶������ɨ��"),
	_T("����У��"),_T("����У��"),_T("�궨���ɨ��"),_T("�궨��ת����ɨ��"),
	_T("���ӳ�ɨ��"),_T("��̬ɨ��"),_T("������У��"),_T("׶����λɨ��"),
	_T("׶������ɨ��"),_T("���򽻴�ɨ��"),_T("׶�����ӳ�ɨ��"),_T("׶��������λɨ��")};

const wchar_t szAxisName[][14]={_T("�ֶ�"),_T("����ƽ��"),_T("��ֵ"),_T("�ֲ�1"),_T("�ֲ�2"),_T("��������"),_T("���"),_T("׼ֱ��"),_T("��������"),_T("���߾���"),_T("����ƽ��"),_T("̽�⾶��"),_T("̽��ƽ��"),_T("ƫ��")};

//const   wchar_t    szSingleAxisName[][16]={_T("��תR"),_T("����X"),_T("ƽ��Y"),_T("����Z"),_T("��תR"),_T("����X"),
//	_T("ƽ��Y"),_T("����Z"),_T("��תR"),_T("����X"),_T("ƽ��Y"),_T("����Z")};
const wchar_t szSingleAxisName[][14]={_T("�ֶ�"),_T("����ƽ��"),_T("��ֵ"),_T("���߷ֲ�"),_T("̽��ֲ�"),_T("��������"),_T("���"),_T("׼ֱ��"),_T("��������"),_T("���߾���"),_T("����ƽ��"),_T("̽�⾶��"),_T("̽��ƽ��"),_T("ƫ��")};

//����Դ����������
enum{
	TUBE_SPELLMAN	=	0,											//X���߹�: ʹ��SPELLMAN��ѹ��Դ
	TUBE_COMET,														//X���߹�: ʹ��COMET��ѹ��Դ
	ACCELERATOR,													//����ֱ�߼�����
	ACCELERATOR_NV,													//����ֱ�߼�����(�����״̬)
	ACCELERATOR_7103,												//����ֱ�߼�����(7103)
	HAMAMATSU_12161,												//����12161
	TUBE_COMET_IVARIO,                                              //TUBE_COMET_IVARIO
	WORX_225,
	UNKNOW_RAY														//δ֪����Դ(��WORX)
};
//̽�������Ŷ��嶨��̽��������(PANEL_PECMOS-[Ĭ��],PANEL_PEFPD,PANEL_GNCCD,UNKOWN_PANEL)
enum{
	PANEL_PECMOS = 0,												//PE CMOS̽����
	PANEL_PESI_0822,												//PE �Ǿ�SI̽����
	PANEL_PESI_1622,												//PE �Ǿ�SI̽����
	PANEL_PESI_1621,												//PE �Ǿ�SI̽����
	PANEL_PESI_1611,												//PE �Ǿ�SI̽����
	PANEL_VARIANSI_1313,											//VARIAN �Ǿ�SI̽����
	PANEL_VARIANSI_2530,											//VARIAN �Ǿ�SI̽����
	PANEL_HAMACMOS,													//HAMAMATSU CMOS̽����
	PANEL_GNCCD,													//������CCD̽����
	UNKOWN_PANEL													//δ֪̽����
};

//���������Ŷ���
enum{
	CTRLER_SIMOTION	= 0,											//NEWPORT������
	CTRLER_UMAC,													//UMAC������
	CTRLER_PI,														//PI������
	CTRLER_PI_UMAC,													//
	UNKOWN_CTRLER													//δ֪������
};

//ͼ��/��Ƶ/ͼƬ����ģʽ����
enum{
	PICTURE			=	0,											//ͼƬ
	VIDEO,															//��Ƶ
	IMAGE															//ͼ��
};

//�����������ݴ���ʽ
enum{
	DP_DLL		= 0,												//��̬��
	DP_SERVER														//������
};

//�����������ݴ���ʽ
enum{
	DP_DETDLL		= 0,											//̽�����Դ���̬��
	//DP_SERVER														//У���������÷�����
};

//������ƶ˿�ͨ�ŷ�ʽ
enum{
	SERIAL_PORT	= 0,												//����ͨ�Ŷ˿�
	TCP_IP															//TCP/IP����
};

//����ɨ�跽ʽ����ֵ
enum{
	sDR_SCAN	=	0,												//DRɨ��
	sCT_SCAN,														//CTɨ��
	sLV_SCAN                                                        //���ӳ�ɨ��
};

//�����ļ����ʽ����ֵ
enum{
	mDATE	=	0,													//Ĭ��������ʽ��"������+4λ���"
	mDATE_NAME_NO                                                   //"������_����_���_4λ���"�����Ժ
};

//ɨ�賣��ģʽ���ݽṹ����
typedef	struct _CommonModeData{
	int		mode;													//ɨ��ģʽ(1-CT2;2-CT3;3-DR;4-LOCAL)
	WORD	matrix;													//ͼ�����
	float	diameter;												//�ӳ�ֱ��(mm)
	//int		deflectionPos;										//ƫ��λ��(0-��, 1-λ��1, 2-λ��2, 3-λ��3, 4-λ��4)
	//short	rotationAngle;											//��ת�Ƕ�(��)
	int     sampletime;                                             //����ʱ��(ms)
	int     collimate;												//׼ֱ��ѡ�����(1/2/3)
	float   layerthick;                                             //�ϲ���(mm)
	int     syncfreq;                                               //ͬ��Ƶ��(Hz)
	float   orientation;                                            //ɨ�跽λ(��)
	float	layerspace;												//����(mm)
	int     layercnt;                                               //ɨ�����
	float	drstartpos;												//DR��ʼλ��(mm)
	float	drlen;													//DRɨ�賤��(mm)
	int		equspace;												//(��Ҫ��)����ģʽ(DR��0-�ȱ���, 1-���ȱ�����CT��0-��ǰ��, 1-�Ȳ�࣬2-����)
	float	ctlayerpos;												//CT�ϲ�λ��(mm)
	int		ct2scanmode;											//2�����ֲ�CTɨ�跽ʽ(0-ɨ�跽ʽ1, 1-ɨ�跽ʽ2��2-ɨ�跽ʽ3)
	int     checksum;                                               //����ģʽ�ļ�����У���
}CommonModeData;

//ɨ����̬�������ݽṹ����(����)
typedef	struct _LineScanConfig{
	int		mode;													//ɨ��ģʽ(0-DR, 1-CT��2-���ӳ�CT)
	WORD	matrix;													//ͼ�����
	float	diameter;												//�ӳ�ֱ��(mm)
	short	rotationAngle;											//��ת�Ƕ�(��)
	float	drXs;													//DR��ʼ����(mm)
	float	drXe;													//DR��������(mm)
	float	ctX;													//CT����(mm)
}LineScanConfig;

//ɨ����̬�������ݽṹ����(����)
typedef	struct _PanScanConfig{
	int		mode;													//ɨ��ģʽ(0-DR��Ƭ)
	float	orientationAngle;										//ɨ�跽λ(��)
	float	layerPos;												//�ϲ�λ��(mm)
	float	translationPos;											//ƽ��λ��(mm)
	float	sod;													//SOD(mm)
	float	sdd;													//SDD(mm)
	float	deflectionPos;											//ƫ�ڽǶ�(mm)
	int		frameCnt;												//�ɼ�֡��
}PanScanConfig;


//2017.02.19����
//����λ�����ݽṹ����
typedef struct _WDoorPosData{
	float   upDoorPos,												//������λ��   
			downDoorPos,											//������λ��   
			leftDoorPos,											//������λ��   
			rightDoorPos;											//������λ��   
}WDoorPosData;					

//���β������������Ϣ���ݽṹ����
typedef struct _GeoAdjInfoData{
	FWorkZero geoWorkZeroOld;									//ǰ���������
	FWorkZero geoWorkZeroNew;									//�����������

	float   rayPlatAngleX;											//����ƽ̨���X
	float   rayPlatAngleY;											//����ƽ̨���Y
	float   detPlatAngleX;											//̽��ƽ̨���X
	float   detPlatAngleY;											//̽��ƽ̨���Y
	float   objPlatAngleX;											//����ƽ̨���X
	float   objPlatAngleY;											//����ƽ̨���Y

	float   fStoDAngle;												//Դ-̽�н�
	float   fStoOAngle;												//Դ-��н�
	float	fDefMoveOldPos;											//����ƫ�ڸ��˶�ԭλֵ
	float   fDefMoveSetPos;											//����ƫ�ڸ��˶��趨ֵ

	float   fWDoorLeftPos;											//�����ŵ�����λ��
	float   fWDoorRightPos;											//�����ŵ�����λ��
	WDoorPosData wDoorPosForLineDet;								//����ʹ��ʱ����λ��
	WDoorPosData wDoorPosForPanDet;									//����ʹ��ʱ����λ��

	float	stodLaserMeasRefDistance;								//����Դ��̽����������ο�����(mm)
	float	stodLaserMeasRealDistance1;								//����Դ��̽����������ʵ�����(mm)
	float	stodLaserMeasRealDistance2;								//����Դ��̽����������ʵ�����(mm)
	float	stodLaserMeasLeftPos;									//Դ-̽�����������λ�趨λ��(mm)
	float	stodLaserMeasRightPos;									//Դ-̽�������ȫ�г��趨λ��(mm)

	float	stooLaser12MeasRefDistance;								//Դ-�Ｄ����1��2���ƽ�Ʒ���ο�����(mm)
	float	stooLaser13MeasRefDistance;								//Դ-�Ｄ����1��3���ƽ�Ʒ���ο�����(mm)
	float	stooLaserDeflectionRadius;								//Դ-����ƫ���˶���ת�뾶(mm)
	float	stooLaserMeasRefDistance;								//����Դ�⹤��С��������ο�����(mm)
	float	stooLaserMeasRealDistance1;								//����Դ�⹤��С��������ʵ�����(mm)
	float	stooLaserMeasRealDistance2;								//����Դ�⹤��С��������ʵ�����(mm)
	float	stooLaserMeasRealDistance3;								//����Դ�⹤��С��������ʵ�����(mm)

	float	hStoDLaserOffsetDistance;								//Դ-̽������ˮƽ����ƫ�ƾ���(mm,����ƫ�����Ҳ�Ϊ��,���Ϊ��)
	float	vStoDLaserOffsetDistance;								//Դ-̽��������ֱ����ƫ�ƾ���(mm,����ƫ�Ϸ�Ϊ��,�·�Ϊ��)

	float	detectorDistanceLineToPan;								//������������������̽����֮�����(mm)

	Coordination toTransPosCord;									//����λ���궨��
}GeoAdjInfoData;

//�˶��ᶨ��(����ʽϵͳ)
//R-��ת��
//X-�����᣻
//Y-ƽ���᣻
//Z-������(�ֲ��˶�����)��
typedef union _SysAxisConfig{
	struct{
		//*********************status1: 8 bits*****************************
		BYTE	interpolation_define		:1;						//��ֵ�˶��ᶨ��:0-������;1-����
		BYTE	sliceThickness_define		:1;						//����˶��ᶨ��:0-������;1-����
		BYTE	collimator_define			:1;						//׼ֱ�˶��ᶨ��:0-������;1-����
		BYTE	deflection_define			:1;						//ƫ���˶��ᶨ��:0-������;1-����
		BYTE								:4;						//����

		//*********************status2: 8 bits*****************************
		BYTE	object_axisR_define			:1;						//����R�����˶��ᶨ��:0-������;1-����
		BYTE	object_axisX_define			:1;						//����X�����˶��ᶨ��:0-������;1-����
		BYTE	object_axisY_define			:1;						//����Y�����˶��ᶨ��:0-������;1-����
		BYTE	object_axisZ_define			:1;						//����Z�����˶��ᶨ��:0-������;1-����
		BYTE								:4;						//����

		//*********************status3: 8 bits*****************************
		BYTE	source_axisX_define			:1;						//����ԴX�����˶��ᶨ��:0-������;1-����
		BYTE	source_axisY_define			:1;						//����ԴY�����˶��ᶨ��:0-������;1-����
		BYTE	source_axisZ_define			:1;						//����ԴZ�����˶��ᶨ��:0-������;1-����
		BYTE								:5;						//����

		//*********************status4: 8 bits*****************************
		BYTE	detector_axisX_define		:1;						//̽����X�����˶��ᶨ��:0-������;1-����
		BYTE	detector_axisY_define		:1;						//̽����Y�����˶��ᶨ��:0-������;1-����
		BYTE	detector_axisZ_define		:1;						//̽����Z�����˶��ᶨ��:0-������;1-����
		BYTE								:5;						//����
	}s;
	BYTE b[4];
}SysAxisConfig;

//2017.10.05����
//����������Ϣ����
typedef struct _WorkPieceInfoData{
	wchar_t	WorkpieceName[MAX_STR_LENGTH];							//��������
	wchar_t	WorkpieceModel[MAX_STR_LENGTH];							//�����ͺ�
	wchar_t	WorkpieceNumber[MAX_STR_LENGTH];						//�������
	wchar_t	WorkpieceBatch[MAX_STR_LENGTH];							//��������
	wchar_t	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//�����������
	wchar_t	WorkpieceFillMaterial[MAX_STR_LENGTH];					//����������
	wchar_t	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//�������쵥λ
	wchar_t	WorkpieceMakeDate[MAX_STR_LENGTH];						//������������
	wchar_t	WorkpieceTestPosition[MAX_STR_LENGTH];					//��ⲿλ
}WorkPieceInfoData;

//ɨ����̬�������ݽṹ����
typedef struct _ScanConfigData{
	int		nScanConfigItem;										//��̬ɨ����������
	LineScanConfig	lineScanConfig[MAX_SCANCONFIG_ITEM];			//��̬ɨ������(����)
	PanScanConfig	panScanConfig[MAX_SCANCONFIG_ITEM];				//��̬ɨ������(����)
	WorkPieceInfoData	workPiece;									//����������Ϣ
    wchar_t szFileDate[10];                                         //�ļ�����
	WORD	nFileSerial;											//�ļ����(���Ķ��岢������config.dat�У���ֹɾ��CTScan.dat�ļ�������ݱ��滻����)
	int     checksum;                                               //У���(������У������λ)	
}ScanConfigData;

//ϵͳ�������ݽṹ����
typedef struct _SetupData{
	GeometryParameter	geometryPara;								//ϵͳ���νṹ����

	int		rayDefine;												//����Դ����(TUBE_SPELLMAN/TUBE_COMET/ACCELERATOR/ACCELERATOR_NV/UNKNOW_TUBE)
	float	rayEnergy;												//��������,��λ:KV
	float	rayDoseRate;											//���߼�����, ��λ:cGy/min/m
	int		nMonitorMode;											//ͼ��/��Ƶ/ͼƬ����ģʽ����(0-ͼƬPICTURE, 1-��ƵVIDEO, 2-ͼ��IMAGE)

	WORD	AmplifyMultiple;										//�����Ŵ���, ����ֵ6
	WORD	IntegralTime;											//��������ʱ��(us), ����ֵ70
	WORD	IntegralTime2;											//�ڶ���������ʱ��(us), ����ֵ70(����˫����Դ���)
	WORD	DelayTime;												//�����ӳ�ʱ��(us), ����ֵ10
	WORD	DelayTime2;												//�ڶ������ӳ�ʱ��(us), ����ֵ10(����˫����Դ���)
	WORD	nFIFOdepth;												//���ݲɼ�FIFOͨ�����, ����ֵ64
	WORD	nChnnelMask;											//���ݲɼ�FIFOͨ������(2���Ʊ�ʾ, ÿλ����64ͨ��)
	WORD	nDetectorChnnelAmount;									//̽����ͨ����(������2����������,���ܴ�������̽������)
	int		nBlockMapTable[MAX_BLOCK];								//̽��ģ��ӳ���,��0��ʼ,��8ͨ��Ϊ��λ,���1280ͨ��,-1��ʾδ��

	int		scanModeDefine[MAX_PARA_ITEM];							//ɨ��ģʽ����
	int		scanModeItems;											//ɨ��ģʽ�������
	int		scanModeCurSel;											//ɨ��ģʽ��ǰѡ������ֵ(-1��ʾδѡ��)

	WORD	scanMatrixDefine[MAX_PARA_ITEM];						//ɨ�������(M)
	int		scanMatrixItems;										//ɨ����������
	int		scanMatrixCurSel;										//ɨ�����ǰѡ������ֵ(-1��ʾδѡ��)
	int     scanMatrix;

	float	scanViewDefine[MAX_PARA_ITEM];							//ɨ���ӳ�����(mm, D)
	int		scanViewItems;											//ɨ���ӳ��������
	int		scanViewCurSel;											//ɨ���ӳ���ǰѡ������ֵ(-1��ʾδѡ��)

	float	layerThickDefine[MAX_PARA_ITEM];						//�ϲ��ȶ���(mm)
	int		layerThickItems;										//�ϲ��ȶ������
	int		layerThickCurSel;										//�ϲ��ȵ�ǰѡ������ֵ(-1��ʾδѡ��)

	WORD	sampleTimeDefine[MAX_PARA_ITEM];						//����ʱ�䶨��(ms)
	int		sampleTimeItems;										//����ʱ�䶨�����
	int		sampleTimeCurSel;										//����ʱ�䵱ǰѡ������ֵ(-1��ʾδѡ��)
	float   sampleTime;												

	int		collimateDefine[MAX_PARA_ITEM];							//׼ֱ�״��Ŷ���
	int		collimateItems;											//׼ֱ�׶������
	int		collimateCurSel;										//׼ֱ�׵�ǰѡ������ֵ(-1��ʾδѡ��)
	
	WORD	syncFreqDefine[MAX_PARA_ITEM];							//ͬ��Ƶ�ʶ���(Hz)
	int		syncFreqItems;											//ͬ��Ƶ�ʶ������
	int		syncFreqCurSel;											//ͬ��Ƶ�ʵ�ǰѡ������ֵ(-1��ʾδѡ��)

	SysAxisConfig	sysAxisDefine;									//ϵͳ�˶��ᶨ��

	float	kVScaleDefine;											//X���߹ܵ�ѹ�任���Ӷ���(kV/bit)
	float	mAScaleDefine;											//X���߹ܵ����任���Ӷ���(mA/bit)

	int		interpolationModeDefine;								//��ֵ��ʽ����(SIMULATION/PHYSICS)
	int		ct3InterpolationFlag;									//3��CTɨ���ֵ������(0/1)
	int		drInterpolationFlag;									//DRɨ���ֵ������(0/1)
	int		drScanModeDefine;										//DRɨ�跽ʽ����(P_DIR/BI_DIR)
	int		drScanAngleDefine;										//DRɨ��Ƕ�������(ONE_ANGLE/MULTI_ANGLE)
	int		translationModeDefine;									//2��ɨ��ƽ�Ʒ�ʽ����(P_DIR/BI_DIR)
	int		transferModeDefine;										//2��ɨ�����ݴ��䷽ʽ����(WHOLE/BATCH)
	int		tabelInOut;												//ת̨��������ѡ��ֵ(P_DIR/N_DIR/DISABLE)
	int		workpieceAmount;										//ͬʱ���Ĺ�������(1/2)

	short	orientIncDefine;										//�ֶȷ�λ����������(��,0-360)
	float	layerPositionDefine;									//�ϲ�λ�ö���(mm)
	float	layerSpaceDefine;										//���ඨ��(mm)
	float	drScanLengthDefine;										//DRɨ�賤��(mm)
	float	minGeometryResolution;									//ͼ����С���ηֱ���(mm, D/M)
	float	minInterpolationSpace;									//��С��ֵ���(mm, ����3��CT��DRɨ��)
	float	minTranslationSpace;									//��Сƽ�Ƽ��(mm, ����2��CT�;ֲ�ɨ��)
	float	minLayerSpace;									        //��С�ֲ���(mm, ����DR�ֲ�ɨ��)
	float	largeViewCenterOffset;									//���ӳ�ɨ���ת����ƫ��(mm)
	float	largeFocalCenterOffset;									//�󽹵������ת����ƫ��ֵ(mm)
	float	smallFocalCenterOffset;									//С���������ת����ƫ��ֵ(mm)

	//char	m_testUnit[MAX_STR_LENGTH];								//�ͼ쵥λ
	//char	m_testTaskNumber[MAX_STR_LENGTH];						//������
	//char	m_testTaskName[MAX_STR_LENGTH];							//��������
	//char	m_testStaff[MAX_STR_LENGTH];							//�����Ա

	//char	WorkpieceName[MAX_STR_LENGTH];							//��������
	//char	WorkpieceModel[MAX_STR_LENGTH];							//�����ͺ�
	//char	WorkpieceNumber[MAX_STR_LENGTH];						//�������
	//char	WorkpieceBatch[MAX_STR_LENGTH];							//��������
	//char	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//�����������
	//char	WorkpieceFillMaterial[MAX_STR_LENGTH];					//����������
	//char	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//�������쵥λ
	//char	WorkpieceMakeDate[MAX_STR_LENGTH];						//������������
	//char	WorkpieceTestPosition[MAX_STR_LENGTH];					//��ⲿλ

	//char	WorkpieceName2[MAX_STR_LENGTH];							//��������
	//char	WorkpieceModel2[MAX_STR_LENGTH];						//�����ͺ�
	//char	WorkpieceNumber2[MAX_STR_LENGTH];						//�������
	//char	WorkpieceBatch2[MAX_STR_LENGTH];						//��������
	//char	WorkpieceShellMaterial2[MAX_STR_LENGTH]; 				//�����������
	//char	WorkpieceFillMaterial2[MAX_STR_LENGTH];					//����������
	//char	WorkpieceManufacturer2[MAX_STR_LENGTH]; 				//�������쵥λ
	//char	WorkpieceMakeDate2[MAX_STR_LENGTH];						//������������
	//char	WorkpieceTestPosition2[MAX_STR_LENGTH];					//��ⲿλ
	wchar_t	m_testUnit[MAX_STR_LENGTH];								//�ͼ쵥λ
	wchar_t	m_testTaskNumber[MAX_STR_LENGTH];						//������
	wchar_t	m_testTaskName[MAX_STR_LENGTH];							//��������
	wchar_t	m_testStaff[MAX_STR_LENGTH];							//�����Ա

	WorkPieceInfoData workPiece;									//����������Ϣ
	WorkPieceInfoData workPiece2;									//����2������Ϣ

	//wchar_t	WorkpieceName[MAX_STR_LENGTH];							//��������
	//wchar_t	WorkpieceModel[MAX_STR_LENGTH];							//�����ͺ�
	//wchar_t	WorkpieceNumber[MAX_STR_LENGTH];						//�������
	//wchar_t	WorkpieceBatch[MAX_STR_LENGTH];							//��������
	//wchar_t	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//�����������
	//wchar_t	WorkpieceFillMaterial[MAX_STR_LENGTH];					//����������
	//wchar_t	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//�������쵥λ
	//wchar_t	WorkpieceMakeDate[MAX_STR_LENGTH];						//������������
	//wchar_t	WorkpieceTestPosition[MAX_STR_LENGTH];					//��ⲿλ

	//wchar_t	WorkpieceName2[MAX_STR_LENGTH];							//��������
	//wchar_t	WorkpieceModel2[MAX_STR_LENGTH];						//�����ͺ�
	//wchar_t	WorkpieceNumber2[MAX_STR_LENGTH];						//�������
	//wchar_t	WorkpieceBatch2[MAX_STR_LENGTH];						//��������
	//wchar_t	WorkpieceShellMaterial2[MAX_STR_LENGTH]; 				//�����������
	//wchar_t	WorkpieceFillMaterial2[MAX_STR_LENGTH];					//����������
	//wchar_t	WorkpieceManufacturer2[MAX_STR_LENGTH]; 				//�������쵥λ
	//wchar_t	WorkpieceMakeDate2[MAX_STR_LENGTH];						//������������
	//wchar_t	WorkpieceTestPosition2[MAX_STR_LENGTH];					//��ⲿλ

	int		nValidCom[nComPortMaxNum];								//��Ч���ж˿�, [.]ΪTRUEʱ�ô�����Ч(COM1-COM8)
	int		commCtrlPortNum;										//������ͨ�Ŷ˿ں�(0-7,-1��ʾ��)
	int		commRayPortNum;											//����Դ��ͨ�Ŷ˿ں�(0-7,-1��ʾ��)
	int		commA23PortNum;											//A23ת�Ӱ���ͨ�Ŷ˿ں�(0-7,-1��ʾ��)
	int		commTPPortNum;											//��ƽϵͳ��ͨ�Ŷ˿ں�(0-7,-1��ʾ��)

	//WORD	nFileSerial;											//�ļ����(���Ķ��岢������config.dat�У���ֹɾ��CTScan.dat�ļ�������ݱ��滻����)
    //wchar_t szFileDate[10];                                         //�ļ�����

    //char    szFileDate[10];                                         //�ļ�����
	//char	szOrgFilePath[MAX_PATH];								//ԭʼ�����ļ�·��
	//char	szCtFilePath[MAX_PATH];									//У����CT�����ļ�·��
	//char	szDrFilePath[MAX_PATH];									//У����DR�����ļ�·��
	//char	szLogFilePath[MAX_PATH];								//��־�ļ�·��
	//char	szCtrlDebugPassword[MAX_PASSWORD_LENGTH];				//����ϵͳ���������ַ���
	//char	szDataDebugPassword[MAX_PASSWORD_LENGTH];				//����ϵͳ���������ַ���
	//char	szDataViewPassword[MAX_PASSWORD_LENGTH];				//���ݲ쿴�����ַ���

	wchar_t	szCurrentFullFileName[MAX_PATH];						//�����õ�ǰȫ�ļ���(������+4λ���/������_����_���_4λ���)
	WORD    nInterFileSerial;										//�ڲ��ļ����
	wchar_t	szOrgFilePath[MAX_PATH];								//ԭʼ�����ļ�·��
	wchar_t	szCtFilePath[MAX_PATH];									//У����CT�����ļ�·��
	wchar_t	szDrFilePath[MAX_PATH];									//У����DR�����ļ�·��
	wchar_t	szLogFilePath[MAX_PATH];								//��־�ļ�·��
	wchar_t	szDarkFullPathFileName[MAX_PATH];						//����ȫ·���ļ���
	wchar_t	szGainFullPathFileName[MAX_PATH];						//����ȫ·���ļ���
	wchar_t	szDefMapFullPathFileName[MAX_PATH];						//������ͼȫ·���ļ���
	wchar_t	szCtrlDebugPassword[MAX_PASSWORD_LENGTH];				//����ϵͳ���������ַ���
	wchar_t	szDataDebugPassword[MAX_PASSWORD_LENGTH];				//����ϵͳ���������ַ���
	wchar_t	szDataViewPassword[MAX_PASSWORD_LENGTH];				//���ݲ쿴�����ַ���

	int		bCtrlPasswordPassed;									//����ϵͳ���Կ���ͨ����־
	int		bDataPasswordPassed;									//����ϵͳ���Կ���ͨ����־
	int		bDataViewPasswordPassed;								//���ݲ쿴����ͨ����־

	BYTE	bComb;													//�ϲ��������ݱ�־(TRUE:�ϲ�, FALSE:���ϲ�)
	BYTE	bDispose;												//���ݴ���ʽ(DP_DLL:��̬��, DP_SERVER:������)
	BYTE	bRadialPosCtrl;											//����λ�ÿ��Ʊ�־(TRUE:����, FALSE:��ֹ)

	int		nPanelMode;												//ƽ��̽�����ɼ�ģʽ(0-2)
	float	fPanelFrameRate;										//ƽ��̽�����ɼ�֡����(1.0,2.0,3.0,3.75,5.0,7.5,15,30)	

	BYTE	bMulitiTurntableConfig;									//��ת̨�ṹ��־(TRUE:���ת̨, FALSE:����ת̨)
	BYTE	bMulitiTurntableScan;									//��ת̨ɨ���־(TRUE:��Сת̨, FALSE:������ת̨)
	float	turntableCenterDistance;								//��Сת̨CT�豸����Сת̨���ľ�
	WORD	nMiddleTurntableSerialNo1;								//��Сת̨CT�豸��������Сת̨���1(���, ��0��ʼ)
	WORD	nMiddleTurntableSerialNo2;								//��Сת̨CT�豸��������Сת̨���2(�Ҳ�, ��0��ʼ)

	WORD	turntableConfigDefine[MAX_PARA_ITEM][2];				//��Сת̨CT�豸CT/DRɨ��ʱСת̨��Ϸ�ʽ(����2,4��)
	int		turntableConfigItems;									//��Сת̨CT�豸CT/DRɨ��ʱСת̨��Ϸ�ʽ�������
	int		turntableConfigCurSel;									//��Сת̨CT�豸CT/DRɨ��ʱСת̨��Ϸ�ʽ��ǰѡ������ֵ(-1��ʾδѡ��)

	//2013.08.27����
	int		scanStartModeDefine;									//ɨ��������ʽ����(IMMEDIACY/BTN_START)
	int		scanEndStopBeamModeDefine;								//ɨ�����ͣ����ʽ����(AUTO/BTN_END)

	//char	szAcquireClientIP[32];									//�ɼ��ͻ���IP��ַ
	wchar_t	szAcquireClientIP[32];									//�ɼ��ͻ���IP��ַ
	unsigned short nAcquireClientPort;								//�ɼ��ͻ��˶˿ڵ�ַ
	wchar_t	szUnderCtrlerIP[32];									//���ƿͻ���IP��ַ
	unsigned short nUnderCtrlerPort;								//���ƿͻ��˶˿ڵ�ַ

	wchar_t	szClientToServerIP[32];									//�ͻ���-������IP��ַ
	unsigned short nClientToServerPort;								//�ͻ���-�������˿ڵ�ַ
	int		ctrlCommModeDefine;										//����ͨ��ģʽ����(SERIAL_PORT/TCP_IP)

	WORD	accRiseTime;											//��������������ʱ��(ms)
	float	sliceAxisAcc;											//�ֲ�����ٶ�(mm/s2)

	BOOL	bEnableAmpAdjust;										//���ηŴ���(�������)����ʹ�ܿ��Ʊ�־(0-������벻�ɵ���;1-�ɵ���)
	int		nDarkGainFrameCnt;										//����/����У��֡������
	//2017.04.04����
	int		nPanDetAcqFrameCnt;										//����ɼ�֡������
	int		nPanDetPulseCnt;										//����ɼ�����������

	float   fDefectMarkPecent;										//�����ر����ʹ�õİٷֱ�(PE�Ǿ���̽������)
// 	int		nScanConfigItem;										//��̬ɨ����������
// 	ScanConfig	scanConfig[MAX_SCANCONFIG_ITEM];					//��̬ɨ������
 	float   configScanDiameter;                                     //��̬ɨ���ӳ�ֱ��
	ScanConfigData scanConfigData;									//��̬ɨ���������ݽṹ����
	BOOL bLaserMeasuringMoveCtrl;									//��������Ǿ��Ȳ������Ʊ�־

	BYTE    clientServerMode;										//����������ʽ��CLIENTMODE-��Ϊ�ͻ���;SERVERMODE-��Ϊ������;SERVERDEBUGMODE-��Ϊ����������ģʽ��
	AxisSetSpeedData axisSpeed;										//�˶����趨����ͺ�����˶��ٶ�
	//2017.02.23����
	GeoAdjInfoData geoAdjInfoData;									//���β������������Ϣ

	float	CurSOD;													//���㵽��ת���ľ���(��ǰ��ת���ľ���λ��)(mm)    
	float	CurSDD;													//���㵽����̽��������(��ǰ̽��������λ��)(mm)    

	BOOL	bLineDetExist;											//ϵͳ����������̽����
	BOOL	bPanDetExist;											//ϵͳ����������̽����

	//2017.10.4����
	BYTE	nFileNamingMode;										//�ļ�������ʽ(DATE-������+4λ���,DATE_NAME_NO-������_����_���_4λ���  )
	BOOL	bRemoteSyncCtrl;										//ͬ���ļ���Զ�̼������־(0-��ͬ��[Ĭ��],1-��Ҫͬ���ļ���Զ�̼����)
	BOOL	bMulitiTurntableCtrl;									//��ת̨��������Ʊ�־(0-������[Ĭ��],1-����Сת̨�������ƽ���)
	BYTE	CheckSum;												//�������ݽṹ����(�����ṹ���ֽ��ۼӺ�=0, ���������ֽ�)
}SetupData;

#endif

