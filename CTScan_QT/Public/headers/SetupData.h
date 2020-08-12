#pragma once
#include <vector>
#include "CtrlData.h"
#include "IctHeader.h"
#include "machineType.h"
#include <map>
#include <tuple>
//ϵͳ�����������ݽṹ�ļ�

/*
��λ��IP��ַ����:
IP��ַ:		192.168.2.124
��������:	255.255.255.0
Ĭ������:	192.168.2.1

DNS������:	202.202.0.33
*/

#define	MAX_PARA_ITEM	    20										//��������
#define	MAX_STR_LENGTH	    100										//����ַ�������
#define MAX_PASSWORD_LENGTH 32                                      //������봮����
#define	MAX_BLOCK		    160										//��8Ϊ��λ�����̽��ģ����(��������AcquireInterface.h�ж���һ��)
#define	MAX_COMMONMODE_ITEM	20										//�����ģʽ����
#define	MAX_SCANCONFIG_ITEM	32										//���ɨ����̬����

enum class ScanMode
{
	NO_SCAN = -1,												//��ɨ�����
	CT1_SCAN,														//���ɨ��
	CT2_SCAN,														//���ɨ��
	CT3_SCAN,														//���ɨ��
	DR_SCAN,														//DRɨ��
	LOCAL_SCAN,														//�ֲ�ɨ��
	HELIX_SCAN,														//����ɨ��
	CONE_SCAN,														//׶��ɨ��
	CONEHELIX_SCAN,													//׶������ɨ��
	BKG_SCAN,														//����У��ɨ��(�̶��ɼ�512���ֶ�)
	AIR_SCAN,														//����У��ɨ��(�̶��ɼ�512���ֶ�)
	CAL_LAYER_ZERO_SCAN,											//�궨�ֲ����ɨ��(�̶��ɼ�400��)
	CAL_CENTER_SCAN,												//�궨��ת����ɨ��
	LARGE_VIEW_SCAN,												//���ӳ�ɨ��(��ת����ƫ��ɨ��)
	CONFIG_SCAN,                                            //��̬ɨ��
	//2017.03.29����
	DEF_MAP_SCAN,											//������У��ɨ��
	CONEPOINT_SCAN,											//��Ե�׶��ɨ�裨��λһ�βɼ�һ�Σ�����Ҫͬ�����壩
	CROSS_SCAN,												//����ɨ�裨�ֶȽǼӶԴ������
	SINGLE_CROSS_SCAN,										//��̬����(ֻ�ƶ�����Դ)ɨ�裨�ֶȽǼӶԴ������
	CONE_LARGE_VIEW_SCAN,									//׶�����ӳ�ɨ��
	CONEHELIX_POINT_SCAN,									//׶��������λɨ��
	//CONE_SCAN_2TABLE,										//׶��ɨ��
	CONE_JOINT_SCAN,                                        //׶��ƴ��ɨ��
	CONE_JOINT_ROT_SCAN,                                        //׶��ƴ��ɨ��
	_MAX_SCANMODE_ITEM
};
//����Դ����������
enum
{
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
enum
{
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
enum
{
	CTRLER_SIMOTION	= 0,											//NEWPORT������
	CTRLER_UMAC,													//UMAC������
	CTRLER_PI,														//PI������
	CTRLER_PI_UMAC,													//
	UNKOWN_CTRLER													//δ֪������
};

//ͼ��/��Ƶ/ͼƬ����ģʽ����
enum
{
	PICTURE			=	0,											//ͼƬ
	VIDEO,															//��Ƶ
	IMAGE															//ͼ��
};

//�����������ݴ���ʽ
enum
{
	DP_DLL		= 0,												//��̬��
	DP_SERVER														//������
};

//�����������ݴ���ʽ
enum
{
	DP_DETDLL		= 0,											//̽�����Դ���̬��
	//DP_SERVER														//У���������÷�����
};

//������ƶ˿�ͨ�ŷ�ʽ
enum
{
	SERIAL_PORT	= 0,												//����ͨ�Ŷ˿�
	TCP_IP															//TCP/IP����
};

//����ɨ�跽ʽ����ֵ
enum
{
	sDR_SCAN	=	0,												//DRɨ��
	sCT_SCAN,														//CTɨ��
	sLV_SCAN                                                        //���ӳ�ɨ��
};

//�����ļ����ʽ����ֵ
enum
{
	mDATE	=	0,													//Ĭ��������ʽ��"������+4λ���"
	mDATE_NAME_NO                                                   //"������_����_���_4λ���"�����Ժ
};

//ɨ�賣��ģʽ���ݽṹ����
struct _CommonModeData
{
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
};

//ɨ����̬�������ݽṹ����(����)
struct _LineScanConfig
{
	int		mode;													//ɨ��ģʽ(0-DR, 1-CT��2-���ӳ�CT)
	WORD	matrix;													//ͼ�����
	float	diameter;												//�ӳ�ֱ��(mm)
	short	rotationAngle;											//��ת�Ƕ�(��)
	float	drXs;													//DR��ʼ����(mm)
	float	drXe;													//DR��������(mm)
	float	ctX;													//CT����(mm)
};

//ɨ����̬�������ݽṹ����(����)
struct _PanScanConfig
{
	int		mode;													//ɨ��ģʽ(0-DR��Ƭ)
	float	orientationAngle;										//ɨ�跽λ(��)
	float	layerPos;												//�ϲ�λ��(mm)
	float	translationPos;											//ƽ��λ��(mm)
	float	sod;													//SOD(mm)
	float	sdd;													//SDD(mm)
	float	deflectionPos;											//ƫ�ڽǶ�(mm)
	int		frameCnt;												//�ɼ�֡��
};


//2017.02.19����
//����λ�����ݽṹ����
struct _WDoorPosData
{
	float   upDoorPos,												//������λ��   
			downDoorPos,											//������λ��   
			leftDoorPos,											//������λ��   
			rightDoorPos;											//������λ��   
};					

//���β������������Ϣ���ݽṹ����

//�˶��ᶨ��(����ʽϵͳ)
//R-��ת��
//X-�����᣻
//Y-ƽ���᣻
//Z-������(�ֲ��˶�����)��
union _SysAxisConfig
{
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
};

//2017.10.05����
//����������Ϣ����
struct _WorkPieceInfoData
{
	wchar_t	WorkpieceName[MAX_STR_LENGTH];							//��������
	wchar_t	WorkpieceModel[MAX_STR_LENGTH];							//�����ͺ�
	wchar_t	WorkpieceNumber[MAX_STR_LENGTH];						//�������
	wchar_t	WorkpieceBatch[MAX_STR_LENGTH];							//��������
	wchar_t	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//�����������
	wchar_t	WorkpieceFillMaterial[MAX_STR_LENGTH];					//����������
	wchar_t	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//�������쵥λ
	wchar_t	WorkpieceMakeDate[MAX_STR_LENGTH];						//������������
	wchar_t	WorkpieceTestPosition[MAX_STR_LENGTH];					//��ⲿλ
};

//ɨ����̬�������ݽṹ����
struct kVRayData 
{
	char	ID;
	char rayType[16];
	float rayEnergy;												//��������,��λ:KV
	float rayDoseRate;											//���߼�����, ��λ:cGy/min/m
};
struct AcceleratorData
{
	char	ID;
	char rayType[16];
	float rayEnergy;												//��������,��λ:KV
	float rayDoseRate;
	unsigned short accRiseTime;											//��������������ʱ��(ms)
	std::vector<int> syncFreqDefine;								//ͬ��Ƶ�ʶ���(Hz)
};
enum class LineDetNum
{
	lineDet1 = 0,
	lineDet2,
	lineDet3,
	lineDet4
};
struct LineDetData
{
	char	ID;
	char	LineDetType;
	short	NumberOfSystemHorizontalDetector;               //����ƽ�淽��ϵͳ̽������(�˲���Ϊ̽��������)
	short	NumberOfCalibrateHorizontalDetector;            //����ƽ�淽��У����̽������(�˲���ΪУ����̽��������)
	short	BeginSerialNoOfCt2Detector;                     //2��ɨ�迪ʼ̽�������(��0��ʼ)
	short	EndSerialNoOfCt2Detector;                       //2��ɨ�����̽�������(��0��ʼ)
	short	AmplifyMultiple;								//�����Ŵ���, ����ֵ6
	short	IntegralTime;									//��������ʱ��(us), ����ֵ70
	short	DelayTime;										//�����ӳ�ʱ��(us), ����ֵ10
	short	nFIFOdepth;										//���ݲɼ�FIFOͨ�����, ����ֵ64
	short	nChnnelMask;									//���ݲɼ�FIFOͨ������(2���Ʊ�ʾ, ÿλ����64ͨ��)
	short	nDetectorChnnelAmount;							//̽����ͨ����(������2����������,���ܴ�������̽������)
	float	HorizontalSectorAngle;                          //����ƽ�淽���Ƚ�
	float	HorizontalDetectorAngle;						//ˮƽ���򵥸�̽�����н�(��)
	int		nBlockMapTable[MAX_BLOCK];						
	char	szAcquireClientIP[32];							//�ɼ��ͻ���IP��ַ
	unsigned short nAcquireClientPort;						//�ɼ��ͻ��˶˿ڵ�ַ
	float	SourceDetectorDistance;							//����Դ̽��������
															
};
struct PanDetData
{
	char	ID;
	char PandetType[32];
	short horizontalPixels;
	short verticalPixels;
	short pixelBlockLeft;
	short pixelBlockRight;
	float pixelSize;
	char rotAngle;			//����90 = 1, 180 = 2, 270 = 3
	char mirror;			//����x = 1, y = 2
};
struct CT2Data
{
	unsigned short Ray;
	unsigned short Det;
	std::vector<unsigned short> View;
	std::vector<unsigned short> Matrix;
	std::vector<unsigned short> SampleTime;
	unsigned char translationModeDefine;
};
struct CT3Data
{
	unsigned short Ray;
	unsigned short Det;
	std::vector<unsigned short> View;
	std::vector<unsigned short> Matrix;
	std::vector<unsigned short> SampleTime;
	unsigned char ct3InterpolationFlag;
};
struct DrScanData
{
	unsigned short Ray;
	unsigned short Det;
	std::vector<unsigned short> View;
	std::vector<unsigned short> Matrix;
	std::vector<unsigned short> SampleTime;
	unsigned char drScanModeDefine;
	unsigned char drInterpolationFlag;
	unsigned char drScanAngleDefine;
};
struct ConeScanData
{
	unsigned short Ray;
	unsigned short Det;
	std::vector<unsigned short> Matrix;
};
struct ConeJointRotScanData
{
	unsigned short Ray;
	unsigned short Det;
	std::vector<unsigned short> Matrix;
	std::vector<unsigned short> View;
};
//ϵͳ�������ݽṹ����

using rayDetScanmode = std::pair<std::pair<int, int>, ScanMode>; /*ray, det, scanmode*/

struct SetupData
{
	char szDeviceModel[32];                              //�豸�ͺ�
	unsigned short lineDetNum;
	unsigned short panDetNum;
	unsigned short kVRayNum;
	unsigned short acceleratorNum;
	std::vector<kVRayData> kVRayData;
	std::vector<AcceleratorData> acceleratorData;
	std::vector<LineDetData> lineDetData;
	std::vector<PanDetData> panDetData;
	std::multimap<rayDetScanmode, int> matrix;
	std::multimap<rayDetScanmode, int> scanview;
	std::multimap<rayDetScanmode, int> sampleTime;
	unsigned short ct3DataNum;
	std::vector<CT3Data> ct3Data;
	unsigned short ct2DataNum;
	std::vector<CT2Data> ct2Data;
	unsigned short drDataNum;
	std::vector<DrScanData> drScanData;
	unsigned short ConeScanDataNum;
	std::vector<ConeScanData> coneScanData;
	unsigned short ConeJointRotScanDataNum;
	std::vector<ConeJointRotScanData> coneJointRotScanData;
	//std::vector<int> layerThickDefine;
	//std::vector<int> sampleTimeDefine;
	//std::vector<int> collimateDefine;
	std::vector<Axis> sysAxisDefine;						//ϵͳ�˶��ᶨ��

	int		interpolationModeDefine;								//��ֵ��ʽ����(SIMULATION/PHYSICS)
	int		ct3InterpolationFlag;									//3��CTɨ���ֵ������(0/1)
	int		drInterpolationFlag;									//DRɨ���ֵ������(0/1)
	int		drScanModeDefine;										//DRɨ�跽ʽ����(P_DIR/BI_DIR)
	int		drScanAngleDefine;										//DRɨ��Ƕ�������(ONE_ANGLE/MULTI_ANGLE)
	int		translationModeDefine;									//2��ɨ��ƽ�Ʒ�ʽ����(P_DIR/BI_DIR)
	float	minGeometryResolution;									//ͼ����С���ηֱ���(mm, D/M)
	float	minInterpolationSpace;									//��С��ֵ���(mm, ����3��CT��DRɨ��)
	float	minTranslationSpace;									//��Сƽ�Ƽ��(mm, ����2��CT�;ֲ�ɨ��)
	float	minLayerSpace;									        //��С�ֲ���(mm, ����DR�ֲ�ɨ��)
	float	largeViewCenterOffset;									//���ӳ�ɨ���ת����ƫ��(mm)
	float	largeFocalCenterOffset;									//�󽹵������ת����ƫ��ֵ(mm)
	float	smallFocalCenterOffset;									//С���������ת����ƫ��ֵ(mm)
	wchar_t	szUnderCtrlerIP[32];									//���ƿͻ���IP��ַ
	unsigned short nUnderCtrlerPort;								//���ƿͻ��˶˿ڵ�ַ
	float	CurSOD;													//���㵽��ת���ľ���(��ǰ��ת���ľ���λ��)(mm)
	float	CurSDD;													//���㵽����̽��������(��ǰ̽��������λ��)(mm)
};

#define	RTBUF_LEN	256						//�������/���ͻ���������
struct COMM_PACKET
{
	BYTE	tagHead[3];						//��ͷ(0x55,0xaa,0x5a)
	BYTE	typeCode;						//������
	WORD	tagLen;							//����(=�����ֽ���+3, ʵ���������ݰ�����=����+4)
	BYTE	data[RTBUF_LEN - 6];			//�������
};

