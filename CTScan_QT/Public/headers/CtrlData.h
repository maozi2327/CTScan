#pragma once

#include "IctHeader.h"
//#define USE_IN_CONTROL                                    //�ڿ��Ƴ�����ʹ��ʱ����
//ͨ��Э��: �������Ƽ��ɷ����޹�˾"CDϵ�й�ҵCT�����ͨ��Э��"V4.0��
//�ð汾�޸������ݽṹ�����״̬����, ��V4.0���°汾������
//����ϵͳ���ݽṹ����
//2013.9.22:
//1. ���νṹ���������Ӣ��/�ֲ�ɨ���Ƚ�(�ֶȽ�), ���ɨ��̽������*����̽�����нǿ��ܲ����ڸ�ֵ
//2. ������CTScan V4.0���ϰ汾

const float PI = (float)3.1415926;									//����PI

#ifndef	BYTE
typedef unsigned char   BYTE;
#endif
#ifndef	WORD
typedef unsigned short  WORD;
#endif
#ifndef	DWORD
typedef unsigned long   DWORD;
#endif

#define	TUNE_PROJECTIONS	512							            //У��ɨ��ͶӰ��
#define CAL_LAYERZERO_SPACE (float)0.5                              //�ֲ����궨ɨ����(mm)

#define CAL_LAYERZERO_MOVESTEP (WORD)(200.0) //�ֲ����궨ͶӰ��(200.0mm/0.25mm)
#define CAL_RADIALZERO_MOVESTEP (WORD)(100.0) //�������궨ͶӰ��(100.0mm/0.5mm)
#define CAL_TRANSLATION_MOVESTEP (WORD)(100.0) //ƽ�����궨ͶӰ��(100.0mm/0.5mm)

#define CAL_LAYERZERO_PROJECTIONS (WORD)(CAL_LAYERZERO_MOVESTEP/CAL_LAYERZERO_SPACE) //�ֲ����궨ͶӰ��(200.0mm/0.25mm)
#define CAL_RADIALZERO_PROJECTIONS (WORD)(CAL_RADIALZERO_MOVESTEP/CAL_LAYERZERO_SPACE) //�������궨ͶӰ��(100.0mm/0.5mm)
#define CAL_TRANSLATION_PROJECTIONS (WORD)(CAL_TRANSLATION_MOVESTEP/CAL_LAYERZERO_SPACE) //ƽ�����궨ͶӰ��(60.0mm/0.5mm)

//̽�����ṹ��ʽ������
#ifndef	_DETECTOR_STRUCT_NAME
#define	_DETECTOR_STRUCT_NAME
enum{
	ARC_DETECTOR	=	0,									//����̽����
	LINE_DETECTOR,											//ֱ��̽����
	PANEL_DETECTOR											//ƽ��̽����
};
#endif

//������ϵͳ����(0-���ƣ�1-��������2-����3-����4-��ƽϵͳ��5-������)
enum{
	SS_UNDERCTRLER	= 0,											//������ϵͳ������ϵͳ��
	SS_ACCELERATOR,													//��������ϵͳ
	SS_LINEDETECTOR,												//������ϵͳ
	SS_PANELDETECTOR,												//������ϵͳ
	SS_BANLANCESYSTEM,												//��ƽ��ϵͳ
	SS_TRIGGERBOARD,												//��������ϵͳ

	SS_SERVER_CLIENT												//�ͻ���-���������ڲ�ͨ��
};

//����ͻ���-���������ڲ�ͨ����״̬                               
enum{
	STS_INNER_NULL								= -1,			//��Ч״̬
	STS_INNER_LINKSTS							= 0x00			//����״̬									0x00
};

//��ϵͳ����״̬�ṹ����
struct	_SubSysLinkSts{
	BYTE		*pRay_linked;											//����Դ����״̬
	BYTE		*pLineDet_linked;										//��������״̬
	BYTE		*pPanDet_linked;										//����Դ����״̬
	BYTE		*pUnderCtrler_linked;									//�ײ������Դ����״̬
	BYTE		*pBanlance_linked;									//��ƽϵͳ����״̬
};


//2��ɨ��ģʽ����ֵ����
//0-360��,	1-180��,	2-180�ȼ��
enum{
	_CT2_360	=	0,
	_CT2_180,
	_CT2_180SPACE
};

#define	nAcceleratSpace	25                                  //DR�Ӽ��پ���(mm)

#pragma pack(1)                                             //�趨���ӳ����ֽڶ���, ��֤�ṹ��ȷ����
//32bitsϵͳ�����ֽṹ����
struct SysConfig
{
	//*********************b[0]*****************************	
	BYTE	SliceCameraExist				:1;			//�ϲ�����ͷ����
	BYTE									:1;			//δ��
	BYTE	LaserExist						:1;			//����������
	BYTE									:3;			//δ��
	BYTE	MarkerExist						:1;			//��ǵ�Ԫ����
	BYTE	MarkerWork						:1;			//��ǵ�Ԫ��������

	//*********************b[1]*****************************	
	BYTE									:8;				//����

	//*********************b[2]*****************************	
	BYTE									:8;				//δ��
														
	//*********************b[3]*****************************	
	BYTE									:8;				//����
};


//ϵͳ���νṹ��������
struct GeometryParameter{
	char	szDeviceModel[32];                              //�豸�ͺ�
	WORD	CtrlerType;										//���������Ͷ���( 0-CTRLER_SIMOTION/ 1-CTRLER_UMAC/2-UNKOWN_CTRLER)
	WORD	PanDetectorType;								//��ǰʹ�õ�����̽��������(PANEL_PECMOS-[Ĭ��],PANEL_PEFPD,PANEL_GNCCD,UNKOWN_PANEL)
	WORD	DetectorInUse;									//��ǰʹ�õ�̽�����ṹ(0-����, 1-ֱ��, 2-ƽ��)
	//3��ɨ���Ƚ�=(NumberOfSystemHorizontalDetector - 1)*HorizontalDetectorAngle
	//���Ƚ�Ϊ����̽����������֮��ļн�
	WORD	NumberOfSystemHorizontalDetector;               //����ƽ�淽��ϵͳ̽������(�˲���Ϊ̽��������)
	WORD	NumberofSystemVerticalDetector;                 //����ƽ�洹ֱ����ϵͳ̽������(�˲���Ϊ̽��������)
	//2017.04.17����
	WORD	NumberOfCalibrateHorizontalDetector;            //����ƽ�淽��У����̽������(�˲���ΪУ����̽��������)
	////////////////////////////////
	//�������
	WORD	NumberOfHorizontalPanDetector;					//����ƽ�淽������̽������(ƽ��̽����ר��, �˲���Ϊ̽��������)
	WORD	NumberofVerticalPanDetector;					//����ƽ�洹ֱ��������̽������(ƽ��̽����ר��, �˲���Ϊ̽��������)
	float   PanDetectorUnitSize;							//����̽������Ԫ���(mm)
	//2017.05.05����
	//float	SDDforPanDetetor;								//��������̽����ʱԴ-̽��(mm)
	////////////////////////////////
	WORD	SerialNo1OfMiddleHorizontalDetector;            //����ƽ�淽������̽�������1(����/ֱ��̽����, ��0��ʼ����)
	WORD	SerialNo2OfMiddleHorizontalDetector;            //����ƽ�淽������̽�������2(����/ֱ��̽����, ��0��ʼ����)
	//2��ɨ���Ƚ�=EndSerialNoOfCt2Detector - BeginSerialNoOfCt2Detector + 1
	WORD	BeginSerialNoOfCt2Detector;                     //2��ɨ�迪ʼ̽�������(��0��ʼ)
	WORD	EndSerialNoOfCt2Detector;                       //2��ɨ�����̽�������(��0��ʼ)

	float	SpaceOfHorizontalDetector;                      //����ƽ�淽��̽�������(mm, ƽ��̽����ר��)
	float	SpaceOfVerticalDetector;                        //����ƽ�洹ֱ����̽�������(mm, ƽ��̽����ר��)
	float	HorizontalSectorAngle;                          //����ƽ�淽���Ƚ�(��,��ϵͳ̽���������, ����Ϊ����̽����������֮��н�)
	float	VerticalSectorAngle;							//����ƽ�洹ֱ�����Ƚ�(��,��ϵͳ̽���������, ����Ϊ����̽����������֮��н�)
	float	HorizontalDetectorAngle;						//ˮƽ���򵥸�̽�����н�(��)
	float	VerticalDetectorAngle;							//��ֱ���򵥸�̽�����н�(��)
	float	Ct2GraduationAngle;								//2��/�ֲ�ɨ��ֶȽ�(��, ���ܲ����ڢ��ɨ���Ƚ�)

	float	RadialPosition;                                 //���㵽��ת���ľ���(��ǰ����λ��)(mm)    
	float	SourceDetectorDistance;                         //���㵽̽����ǰ�������(mm)
	float	SourceDetectorDistance1;						//���㵽̽������ֵ�ִ�����(mm)

	//float	TranslationMaxCoordinate,                       //ƽ���������(mm)
	//		TranslationMinCoordinate;                       //ƽ����С����(mm)
	//float	SliceMaxCoordinate,                             //�ֲ��������(mm)
	//		SliceMinCoordinate;                             //�ֲ���С����(mm)
	//float	RadialMaxCoordinate,                            //�����������(mm, Сת̨)
	//		RadialMinCoordinate;                            //������С����(mm, ��ת̨)
	float	CurSOD;											//���㵽��ת���ľ���(��ǰ��ת���ľ���λ��)(mm)    
	float	CurSDD;											//���㵽����̽��������(��ǰ̽��������λ��)(mm)    

	float	SliceMaxCoordinate,                             //�ֲ��������(mm)
			SliceMinCoordinate;                             //�ֲ���С����(mm)

	float	SourceXMaxCoordinate,							//����Դ�����������(mm)
			SourceXMinCoordinate;							//����Դ������С����(mm)
	float	DetectorXMaxCoordinate,							//̽���������������(mm)
			DetectorXMinCoordinate;							//̽����������С����(mm)
	float	ObjectXMaxCoordinate,							//���������������(mm)
			ObjectXMinCoordinate;							//����������С����(mm)

	float	SourceYMaxCoordinate,                           //����Դƽ���������(mm)
			SourceYMinCoordinate;                           //����Դƽ����С����(mm)
	float	DetectorYMaxCoordinate,                         //̽����ƽ���������(mm)
			DetectorYMinCoordinate;                         //̽����ƽ����С����(mm)
	float	ObjectYMaxCoordinate,                           //����ƽ���������(mm)
			ObjectYMinCoordinate;                           //����ƽ����С����(mm)

	float	MaxViewDiameter;								//����ӳ�ֱ��(mm)
	SysConfig	Config;										//ϵͳ������
};
enum class RayType
{
	Accelerator = 0,
	Tube
};

//������������(��17����)
//X-����Y-ƽ�ƣ�Z-����
//
//enum class AxisDefinition
//{					
//	AxGraduation      = 0,									//�ֶ�                     0
//	AxObjTranslation,										//����ƽ��                 1
//	AxInterpolation,										//��ֵ                     2
//	AxLayer1,												//����Դ�ֲ�               3
//	AxLayer2,												//̽�����ֲ�               4
//	AxObjRadial,											//��������                 5
//	AxSliceThick,											//�ϲ���(��׼ֱ�׸߶�)   6
//	AxCollimator,											//׼ֱ�׿��               7
//	AxObjVertical,											//����Z�����˶���			8
//	AxRayRadial,											//����ԴX�����˶���			9
//	AxRayTranslation,										//����ԴY�����˶���			10
//	AxDetRadial,											//̽����X�����˶���			11
//	AxDetTranslation,										//̽����Y�����˶���			12
//	AxDeflection,											//ƫ���˶�					13
//	_MaxiumAxis                                             //                          14
//};					
//const int MaxiumAxis = static_cast<int>(AxisDefinition::_MaxiumAxis);                         //�������Ŀ
//
////�˶����趨����ͺ�����˶��ٶ�
//struct AxisSetSpeedData
//{
//	float	min[MaxiumAxis];								//����ٶ�(���ζ�Ӧ������˶���)
//	float	max[MaxiumAxis];								//����ٶ�(���ζ�Ӧ������˶���)
//};

//�˶���״̬�ֽṹ
struct AxisStatus{
	float	Temperature;									//�¶�
	float	Torque;											//Ť��
	DWORD	ErrCode;										//��������
};



#ifndef USE_IN_CONTROL
//�˶���������ֵ����
//�ڿ���ϵͳ��ʹ�ñ��ļ�ʱ����PCL839.H���Ѷ���, ��Ҫ���θö���
enum{
	P_DIR			= 0,                                    //������
	N_DIR                                                   //������
};
#endif

//ɨ���˶���ʽ����ֵ����
enum{
//	P_DIR			= 0,                                    //������ɨ��
	BI_DIR			= 1                                     //˫��ɨ��
};
//ɨ��������ʽ����ֵ����
enum{
	IMMEDIACY		= 0,									//��������ɨ��
	BTN_START												//������Դ������ť����ɨ��
};
//DRɨ��Ƕ�����ֵ����
enum{
	ONE_ANGLE		= 0,									//���Ƕ�ɨ��
	MULTI_ANGLE												//��Ƕ�ɨ��
};
//��ֵ��ʽ����ֵ����
enum{
	SIMULATION		= 0,									//ģ���ֵ
	PHYSICS													//�����ֵ
};
////ɨ��ģʽ�ַ�����
//const wchar_t szScanModeText[14][32]={
//	_T("���ɨ��"),_T("���CTɨ��"),_T("���CTɨ��"),_T("DRɨ��"),
//	_T("�ֲ�ɨ��"),_T("����ɨ��"),_T("׶��ɨ��"),_T("׶������ɨ��"),
//	_T("����У��"),_T("����У��"),_T("�궨�ֲ����ɨ��"),_T("�궨��ת����ɨ��"),
//	_T("���ӳ�ɨ��"),_T("��̬ɨ��")};


//�ֲ���Ʒ�ʽ����ֵ����
enum{
	CURRENT_LAYER_SCAN	= 0,								//��ǰ��ɨ��
	EQU_LAYER_SPACE_SCAN,									//�Ȳ��ɨ��
	CHANGE_LAYER_SPACE_SCAN									//����ɨ��
};

////////////////////////////////////////////////////////////////////////////////////////////
//CDϵ�й�ҵCTͨ�������ֶ���                                
enum{
	CMD_NULL								= -1,			//������

    CMD_POWER_CTRL							= 0x00,			//��Դ����									0x00
	CMD_OFF_BEAM,											//ֹͣ����Դ����							0x01

	CMD_POLL_STATUS							= 0x10,			//��ѯ�ײ������״̬						0x10
	CMD_UPLOAD_CONTROL_SYSTEM_STATUS,              			//�ϴ�����ϵͳ״̬							0x11
//	CMD_UPLOAD_RAY_STATUS,                      			//�ϴ�����Դ������״̬
	CMD_DOWNLOAD_WORKZERO,                      			//���ع�����λ								0x12
	CMD_UPLOAD_WORKZERO,                        			//�ϴ�������λ								0x13
	CMD_UPLOAD_ENCODER_COUNT,                   			//�ϴ�����������ֵ							0x14
	CMD_UPLOAD_RASTER_COUNT,                    			//�ϴ���դ����ֵ							0x15
	CMD_UPLOAD_COLLIMATOR_STATUS,              				//�ϴ�׼ֱ��״̬							0x16
	CMD_DOWNLOAD_ACCELATOR_FREQ,                			//���ؼ�����ͬ��Ƶ��						0x17
	CMD_UPLOAD_ACCELATOR_FREQ,                  			//�ϴ�������ͬ��Ƶ��						0x18
	CMD_UPLOAD_GRADUATION_BASE,								//�����CTɨ����ʼ�ֶȺ�					0x19
	CMD_DOWNLOAD_GEOMETRY_PARA,								//����ϵͳ���νṹ����						0x1a
	CMD_UPLOAD_GEOMETRY_PARA,								//�ϴ�ϵͳ���νṹ��������					0x1b
	CMD_UPLOAD_SCENE_KEY,                       			//�ϴ��ֳ����Ƶ�Ԫ����״̬					0x1c
	CMD_UPLOAD_FAULT_CODE,                      			//�ϴ�ǰ10�ι��ϴ���						0x1d
	CMD_CLEAR_FAULT_CODE_TBL,                   			//������ϴ����							0x1e
	CMD_CLEAR_SAVE_FLAG,                                    //������̱�־����							0x1f
	CMD_UPLOAD_LASTCMD_RESULT,								//�ϴ�ǰ������ִ�н��						0x20
	CMD_UPLOAD_DIAGNICS_RESULT,								//�ϴ�������Ͻ��							0x21
	CMD_UPLOAD_POWER_STATUS,								//�ϴ���Դ״̬								0x22
	CMD_DOWNLOAD_AXIS_SPEED,								//�����˶����趨�ٶ�						0x23
	CMD_UPLOAD_AXIS_SPEED,									//�ϴ��˶����趨�ٶ�						0x24

	CMD_STOP								= 0x30,         //�ж����в���								0x30
	CMD_SEEK_ABS_ZERO,										//�˶���ʼ��(���˶���ʼ��)					0x31
	CMD_SEEK_AXIS_ABS_ZERO,									//�����ʼ��								0x32
	CMD_GOTO_WORK_ZERO,										//�˶�����(���˶��ӵ�ǰλ�÷��ع�����λ)	0x33
 	CMD_AXIS_GOTO_WORK_ZERO,                    			//ָ�����귵�ع�����λ						0x34
	CMD_AXIS_REL_MOVE,										//��������ƶ�(EL��Чʱֹͣ)				0x35
    CMD_AXIS_ABS_MOVE,										//��������ƶ�(EL��Чʱֹͣ)				0x36
    CMD_AXIS_CONT_MOVE,										//���������˶�(EL��Чʱֹͣ)				0x37
	CMD_AXIS_GOTO_SDP,                          			//�����˶���SD+								0x38
	CMD_AXIS_GOTO_SDN,                          			//�����˶���SD-								0x39
	CMD_AXIS_GOTO_ELP,                          			//�����˶���EL+								0x3a
	CMD_AXIS_GOTO_ELN,                          			//�����˶���EL-								0x3b
    CMD_SLICE_REL_MOVE,										//�ֲ���������ƶ�(��̽������Ϊ��׼)		0x3c
    CMD_SLICE_ABS_MOVE,										//�ֲ���������ƶ�(��̽������Ϊ��׼)		0x3d
    CMD_SLICE_CONT_MOVE,									//�ֲ����������ƶ�							0x3e
    CMD_SLICE_THICKNESS_ADJUST,								//�ϲ��ȵ���								0x3f
    CMD_COLLIMATOR_SWITCH,									//׼ֱ��ѡ��								0x40
	CMD_SET_RADIAL_POS,                                     //���þ���λ��								0x41
	CMD_DIAGNICS,                               			//�˶�ϵͳ���								0x42
	//2017.02.18����
    CMD_SLICE_STODLASER_ABS_MOVE,							//��ࣺ����Դ�����׼̽�����ϲ���������ƶ�(��̽������Ϊ��׼)	0x43
    CMD_SAIMDLASER_AUTOCALM_MOVE,							//��׼������Դ�����׼̽�����Ͻ��������Զ�У׼�˶�(����̽�����᲻��)	0x44
	//2017.03.02����
	CMD_LASER_MEASURING_MOVE,								//��ϼ�������ǲ⾫���˶�					0x45
    CMD_SAIMDLASER_GOTO_LAST_POS,							//��׼��������ƽ�ơ�����������̽��ƽ�ơ�̽��������λ��ǰ�μ����׼��������λ��	0x46
	//2017.04.26����
    CMD_SLICE_OFFSET_ABS_MOVE,								//�ֲ�ƫ���˶������ƶ�(������)				0x47
	CMD_TO_TRANS_POS,										//ȥ����λ�������ߵ�Ԫ��̽�ⵥԪ��6�ᶨλ������λ��	0x48
	//2017.09.26����
    CMD_DET_SELECT,											//����/�����л�����							0x49

	CMD_CT_SCAN								= 0x60,			//CTɨ��									0x60
	CMD_LARGEVIEW_SCAN,                                     //���ӳ�CTɨ��								0x61
	CMD_DR_SCAN,                                			//DRɨ��									0x62
	CMD_NEXT_SCAN,                  						//������һ��CTɨ��/2��ƽ��					0x63
	CMD_HELIX_SCAN,											//����CTɨ��								0x64
	CMD_LOCAL_SCAN,											//�ֲ�ɨ��									0x65
	CMD_CONE_SCAN,											//׶��ɨ��									0x66
	CMD_BACK_BEGIN_POS,										//�˶�����ɨ��ǰλ��(ɨ��ǰ���¼������λ��)0x67
	CMD_RAY_TUNE,											//����(����)У��(�̶��ɼ�512������)			0x68
	CMD_BKG_TUNE,											//����У��(�̶��ɼ�512������)				0x69
	CMD_CAL_LAYER_ZERO,                                     //�ֲ����궨								0x6a
	CMD_SIMULATION_CT3,                                     //ģ��3��CTɨ��(512�ֶ�)					0x6b
	//2017.06.26����
	CMD_CONEPOINT_SCAN,										//׶����λɨ��								0x6c
	//2017.09.05����
	CMD_CROSS_SCAN,											//����ɨ��									0x6d
	CMD_SINGLE_CROSS_SCAN,									//��̬����ɨ��								0x6e

	CMD_CONE_LARGE_VIEW_SCAN,								//׶�����ӳ�ɨ��							0x6f
	CMD_HELIX_POINT_SCAN,									//׶��������λɨ��							0x70

	CMD_DOWNLOAD_COORDINATE_LAMP_ENHANCE	= 0x80,			//����ǿ���ֳ����Ƶ�Ԫ�´�����ֵ(�����ʽ),ָʾ��״̬
    CMD_DOWNLOAD_LAMP_FACILITY,								//��������ֳ����Ƶ�Ԫ�´�ָʾ��״̬

    CMD_DOOR_OPENorCLOSE					= 0x90,			//����/�����ſ�������						0x90
	CMD_MARK,											    //��ǵ�Ԫ����							0x93
	
	//����С����������
	CMD_POLL_STATUS_OV						= 0xA0,			//����С����ѯϵͳ״̬
	CMD_SET_ABS_ZERO_OV,									//����С��λ������
	CMD_FLATCAR_MOVE_OV,									//����С���˶�����
	CMD_RESET_FREQ_CONVTER_OV,								//����С�����ϸ�λ
	
	//��ƽϵͳ��������
	CMD_STOP_TP								= 0xB0,			//��ƽϵͳ��ֹ���в���
	CMD_POLL_STATUS_TP,										//��ƽϵͳ��ѯϵͳ״̬
	CMD_POWER_OFF_TP,										//��ƽϵͳ�ϵ����
	CMD_POWER_ON_TP,										//��ƽϵͳ�ϵ����
	CMD_1KEY_LEVELLING_TP,									//��ƽϵͳ����һ����ƽ����
	CMD_1PLAT1KEY_LEVELLING_TP,								//��ƽϵͳ��ƽ̨һ����ƽ����
	CMD_1PLATFORM_UP_TP,									//��ƽϵͳ��ƽ̨������������
	CMD_1PLATFORM_DOWN_TP,									//��ƽϵͳ��ƽ̨�����½�����
	CMD_1LEG_UP_TP,											//��ƽϵͳ������������
	CMD_1LEG_DOWN_TP,										//��ƽϵͳ�����½�����
	CMD_RESET_SENSOR,										//��������λ��1-������1(̽������)��2-������2(��������)��3-������3(������)
	CMD_1PLAT_SMALL_TP,										//��ƽ̨ˮƽ΢����1-̽����ƽ̨��2-������ƽ̨��
	CMD_1PLAT_RETURN,										//ƽ̨���գ�1-̽����ƽ̨��2-������ƽ̨��
	CMD_RESET_AXES_ALARM									//�������ᱨ����
};

////////////////////////////////////////////////////////////////////////////////////////////
////CDϵ�й�ҵCTͨ��״̬�ֶ���
enum{
    STS_AxGraduation_COORDINATION			= 0,			//�ֶ�����λ��								0x00
    STS_AxTranslation_COORDINATION,							//ƽ������λ��								0x01
    STS_AxInterpolation_COORDINATION,						//��ֵ����λ��								0x02
    STS_AxLayer1_COORDINATION,								//�ֲ�1(����Դ�ֲ�)�˶�����					0x03
    STS_AxLayer2_COORDINATION,								//�ֲ�2(̽�����ֲ�)�˶�����					0x04
    STS_AxRadial_COORDINATION,								//�����˶�����								0x05
    STS_AxSliceThick_COORDINATION,							//�ϲ��ȵ����˶�����						0x06
    STS_AxCollimator_COORDINATION,							//׼ֱ��ѡ���˶�����						0x07

	STS_ALL_COORDINATION,                       			//��������λ��						   		0x08
	STS_SYSTEM_STATUS,										//ϵͳ״̬							   		0x09
	//������˳��
	STS_IO_REGISTER,                            			//I/O�Ĵ���״̬								0x0a

	STS_CONTROL_SYSTEM,										//����ϵͳ״̬					   			0x0b
	STS_SCENE_KEY_STATUS,                       			//�ֳ�����̨������Ϣ			   			0x0c
	STS_COLLIMATOR_STATUS,                     				//׼ֱ��״̬					   			0x0d
//	STS_RAY_CONTROLLER_STATUS,                  			//����Դ������״̬
	STS_WORKZERO,                               			//������λ						   			0x0e
	STS_ENCODER_COUNT,                          			//�������������ֵ							0x0f
	STS_RASTER_COUNT,                           			//��դ����ֵ					   			0x10
	STS_FAULT_CODE,                             			//���ϴ����				   				0x11
	STS_ACCELATOR_FREQ,                         			//������ͬ��Ƶ��				   			0x12
	STS_GRADUATION_BASE,									//���CTɨ����ʼ�ֶȺ�						0x13
	STS_GEOMETRY_PARA,										//ϵͳ���νṹ������Ϣ						0x14
	STS_LASTCMD_MESSAGE,									//ǰ��������Ϣ					   			0x15
	STS_DIAGNICS_RESULT,									//�������ִ�н������						0x16
	STS_POWER,												//��Դ״̬									0x17
	STS_AXIS_SPEED,											//�˶����趨�ٶ�							0x18
	STS_AUTOCALM_ZERO,										//�Զ�У׼���󣬷�������������

    STS_SCENE_KEY_ENHANCE					= 0x80,			//��ǿ���ֳ����Ƶ�Ԫ��ײ���������͵İ�����Ϣ
    STS_SCENE_KEY_FACILITY,									//�������ֳ����Ƶ�Ԫ��ײ���������͵İ�����Ϣ

	STS_LASERMEAS_VALUE						= 0xA0,			//������״̬								0xA0

	STS_ACC_STATUS							= 0xF0,			//������״̬								0xA0

	//����С��״̬
	STS_POLL_STATUS_OV						= 0xB0,			//����С��״̬								0xB0

	//��ƽϵͳ״̬
	STS_POLL_STATUS_TP						= 0xC0			//��ƽϵͳ״̬								0xC0
};					
					
//״̬/�����붨��					
enum{
	SUCCESS									= 0x00,			//�ɹ�										0x00
	EXECUTION,												//����ִ��									0x01
	
	fGraguationInit,										//�ֶ����ʼ��ʧ��							0x02
	fTranslationInit,										//ƽ�����ʼ��ʧ��							0x03
	fInterpolationInit,										//��ֵ���ʼ��ʧ��							0x04
	fLayer1Init,											//����Դ�ֲ����ʼ��ʧ��					0x05
	fLayer2Init,											//̽�����ֲ����ʼ��ʧ��					0x06
	fRadialInit,											//�������ʼ��ʧ��							0x07
	fSliceThicknessInit,									//�ϲ������ʼ��ʧ��						0x08
	fCollimatorInit,										//׼ֱ�����ʼ��ʧ��						0x09

	fGraduationPosition,									//�ֶ��ᶨλ����							0x0a
	fTranslationPosition,									//ƽ���ᶨλ����							0x0b
	fInterpolationPosition,									//��ֵ�ᶨλ����							0x0c
	fLayer1Position,										//����Դ�ֲ��ᶨλ����						0x0d
	fLayer2Position,										//̽�����ֲ��ᶨλ����						0x0e
	fRadialPosition,										//̽�����ֲ��ᶨλ����						0x0f
	fSliceThicknessPosition,								//�ϲ����ᶨλ����						0x10
	fCollimatorPosition,									//׼ֱ���ᶨλ����							0x11

	fOpenDoor,												//�������Ź���								0x12
	fCloseDoor,												//�������Ź���								0x13
	fMovementLimit,											//�˶���λ									0x14
	fMoveTimeOut,											//�˶���ʱ									0x19
			
    fStartupCheckError,										//StartupCheck����							0x15
    fDrInitPos,												//DRɨ���ʼ��λ�ô���						0x16
    fCTInitPos,												//CTɨ���ʼ��λ�ô���						0x17
    fUnavailableCMD,										//��Ч����									0x18
	
	sIsUnready,												//ϵͳδ����								0x1a
	sIsDoorClosing,											//�����Ŵ��ڹر�״̬						0x1b
	sIsDoorOpen,											//�����Ŵ��ڴ�״̬						0x1c
	
	sfEND													//����/״̬������							0x1d
};	

//״̬/����������					
const char szNameOfFaultStatus[][64]={
	"�ɹ�",
	"����ִ��",

	"�ֶ����ʼ��ʧ��",
	"ƽ�����ʼ��ʧ��",
	"��ֵ���ʼ��ʧ��",
	"����Դ�ֲ����ʼ��ʧ��",
	"̽�����ֲ����ʼ��ʧ��",
	"�������ʼ��ʧ��",
	"������ʼ��ʧ��",
	"׼ֱ�����ʼ��ʧ��",

	"�ֶ��ᶨλ����",
	"ƽ���ᶨλ����",
	"��ֵ�ᶨλ����",
	"����Դ�ֲ��ᶨλ����",
	"̽�����ֲ��ᶨλ����",
	"�����ᶨλ����",
	"����ᶨλ����",
	"׼ֱ���ᶨλ����",

	"�������Ź���",
	"�������Ź���",
	"�˶���λ",
	"�˶���ʱ",

	"StartupCheck����",
	"DRɨ���ʼ��λ�ô���",
	"CTɨ���ʼ��λ�ô���",
	"��Ч����",

	"ϵͳδ����",
	"�����Ŵ��ڹر�״̬",
	"�����Ŵ��ڴ�״̬",

	""
};

//����ͼ��ϵͳȱ�ݱ����Ϣ��ķ���״̬����
enum{
		dMarkCmdDownload	= 0,							//	0		�������´ﵽ����ϵͳ
		dCtrlNetNoLink,										//	1		��������δ����
		dSysNotReady,										//	2		ϵͳδ����
		dMarkUnitUndefineOrNotWork,							//	3		δ�����ǵ�Ԫ���ǵ�Ԫδ����
		dSysBusy,											//	4		ϵͳæ
		dSysFault,											//	5		ϵͳ����
		dWaitDefectMsg,										//	6		�ȴ�ȱ����Ϣ
		dUnknowError										//	other	δ֪����
};

//ϵͳ״̬�ֽṹ
/******        �ߵ�ƽ��Ч        ******/
union SysStatus{
	struct{
		//*********************status1: 16 bits*****************************
		BYTE	graduation_zero_found			:1;			//�ֶ��˶���λ���ҵ�(1)
		BYTE	translation_zero_found			:1;			//ƽ���˶���λ���ҵ�(1)
		BYTE	interpolation_zero_found		:1;			//��ֵ�˶���λ���ҵ�(1)
		BYTE	layer1_zero_found				:1;			//����Դ�ֲ��˶���λ���ҵ�(1)
		BYTE	layer2_zero_found				:1;			//̽�����ֲ��˶���λ���ҵ�(1)
		BYTE	radial_zero_found				:1;			//�����˶���λ���ҵ�(1)
		BYTE	sliceThick_zero_found			:1;			//�ϲ��ȵ�����λ���ҵ�(1)
		BYTE	collimator_zero_found			:1;			//׼ֱ��ѡ����λ���ҵ�(1)
								
		//2017.05.26����
		BYTE	detRadial_zero_found			:1;			//̽�⾶����λ���ҵ�(1)
		BYTE	detTranslation_zero_found		:1;			//̽��ƽ����λ���ҵ�(1)
		BYTE	rayRadial_zero_found			:1;			//���߾�����λ���ҵ�(1)
		BYTE	rayTranslation_zero_found		:1;			//����ƽ����λ���ҵ�(1)
		BYTE	tableVertical_zero_found			:1;			//����������λ���ҵ�(1)
		BYTE	deflection_zero_found			:1;			//ƫ����λ���ҵ�(1)
		BYTE									:2;			//����

		//*********************status2: 16 bits*****************************
		BYTE	graduation_org					:1;			//�ֶȲο��ź�					0-��Ч	1-��Ч
		BYTE	translation_org					:1;			//ƽ�Ʋο��ź�					0-��Ч	1-��Ч
		BYTE	interpolation_org				:1;			//��ֵ�ο��ź�					0-��Ч	1-��Ч
		BYTE	layer1_org						:1;			//�ֲ�1(����Դ�ֲ�)�ο��ź�		0-��Ч	1-��Ч
		BYTE	layer2_org						:1;			//�ֲ�2(̽�����ֲ�)�ο��ź�		0-��Ч	1-��Ч
		BYTE	radial_org						:1;			//����ο��ź�					0-��Ч	1-��Ч
		BYTE	sliceThick_org					:1;			//���ο��ź�					0-��Ч	1-��Ч
		BYTE	collimator_org					:1;			//׼ֱ���ο��ź�				0-��Ч	1-��Ч
					
		BYTE	graduation_alarm				:1;			//�ֶ��˶��澯					0-����	1-�澯
		BYTE	translation_alarm				:1;			//ƽ���˶��澯					0-����	1-�澯
		BYTE	interpolation_alarm				:1;			//��ֵ�˶��澯					0-����	1-�澯
		BYTE	layer1_alarm					:1;			//�ֲ�1(����Դ�ֲ�)�˶��澯		0-����	1-�澯
		BYTE	layer2_alarm					:1;			//�ֲ�2(̽�����ֲ�)�˶��澯		0-����	1-�澯
		BYTE	radial_alarm					:1;			//�����˶��澯					0-����	1-�澯
		BYTE	sliceThick_alarm				:1;			//�������˶��澯				0-����	1-�澯
		BYTE	collimator_alarm				:1;			//׼ֱ��ѡ���˶��澯			0-����	1-�澯
					
		//*********************status3: 16 bits*****************************
		BYTE	translation_SDp					:1;			//ƽ��SD+						0-��Ч	1-��Ч
		BYTE	translation_SDn					:1;			//ƽ��SD-						0-��Ч	1-��Ч
		BYTE	interpolation_SDp				:1;			//��ֵSD+						0-��Ч	1-��Ч
		BYTE	interpolation_SDn				:1;			//��ֵSD-						0-��Ч	1-��Ч
		BYTE	layer1_SDp						:1;			//�ֲ�1(����Դ�ֲ�)SD+			0-��Ч	1-��Ч
		BYTE	layer1_SDn						:1;			//�ֲ�1(����Դ�ֲ�)SD-			0-��Ч	1-��Ч
		BYTE	layer2_SDp						:1;			//�ֲ�2(̽�����ֲ�)SD+			0-��Ч	1-��Ч
		BYTE	layer2_SDn						:1;			//�ֲ�2(̽�����ֲ�)SD-			0-��Ч	1-��Ч

		BYTE	radial_SDp						:1;			//����SD+						0-��Ч	1-��Ч
		BYTE	radial_SDn						:1;			//����SD-						0-��Ч	1-��Ч
		BYTE	sliceThick_SDp					:1;			//������SD+					0-��Ч	1-��Ч
		BYTE	sliceThick_SDn					:1;			//������SD-					0-��Ч	1-��Ч
		BYTE	collimator_SDp					:1;			//׼ֱ��ѡ��SD+					0-��Ч	1-��Ч
		BYTE	collimator_SDn					:1;			//׼ֱ��ѡ��SD-					0-��Ч	1-��Ч
		BYTE									:2;     	//����
						
		//*********************status4: 16 bits*****************************
		BYTE	translation_ELp					:1;			//ƽ��EL+						0-��Ч	1-��Ч
		BYTE	translation_ELn					:1;			//ƽ��EL-						0-��Ч	1-��Ч
		BYTE	interpolation_ELp				:1;			//��ֵEL+						0-��Ч	1-��Ч
		BYTE	interpolation_ELn				:1;			//��ֵEL-						0-��Ч	1-��Ч
		BYTE	layer1_ELp						:1;			//�ֲ�1(����Դ�ֲ�)EL+			0-��Ч	1-��Ч
		BYTE	layer1_ELn						:1;			//�ֲ�1(����Դ�ֲ�)EL-			0-��Ч	1-��Ч
		BYTE	layer2_ELp						:1;			//�ֲ�2(̽�����ֲ�)EL+			0-��Ч	1-��Ч
		BYTE	layer2_ELn						:1;			//�ֲ�2(̽�����ֲ�)EL-			0-��Ч	1-��Ч
					
		BYTE	radial_ELp						:1;			//����EL+						0-��Ч	1-��Ч
		BYTE	radial_ELn						:1;			//����EL-						0-��Ч	1-��Ч
		BYTE	sliceThick_ELp					:1;			//������EL+					0-��Ч	1-��Ч
		BYTE	sliceThick_ELn					:1;			//������EL-					0-��Ч	1-��Ч
		BYTE	collimator_ELp					:1;			//׼ֱ��ѡ��EL+					0-��Ч	1-��Ч
		BYTE	collimator_ELn					:1;			//׼ֱ��ѡ��EL-					0-��Ч	1-��Ч
		BYTE									:2;     	//����

		//*********************status5: 16 bits*****************************
		BYTE	collimator_pos					:2;			//׼ֱ��λ�ñ���				00-1#׼ֱ�� 01-2#׼ֱ��	10-3#׼ֱ��  11-��ȷ��
		BYTE	scene_link						:1;			//�ֳ����Ƶ�Ԫ����״̬			0-δ����	1-������
		BYTE	sceneKey_up						:1;			//�ֳ���ť״ָ̬ʾ				0-����		1-�ͷ�
		BYTE	bRaySourceSel					:1;			//����Դѡ��					0-1#����Դ	1-2#����Դ
		BYTE	table_setting					:1;			//ת̨��װ��̨��				0-С̨��	1-��̨��
		BYTE	no_man_active					:1;			//��������Ա�״̬			0-��		1-��
		BYTE	mazeDoorClose					:1;			//�Թ���״̬					0-����		1-�ر�

		BYTE	TADoorState						:2;			//������A״̬					00-�뿪	01-�ر�	10-��	11-����
		BYTE	TBDoorState						:2;			//������B״̬					00-�뿪	01-�ر�	10-��	11-����
		BYTE									:4; 		//����

		//*********************status6: 16 bits*****************************
		BYTE	cameraPowerOpen					:1;			//���������Դ					0-�ر�	1-��
		BYTE	laserPowerOpen					:1;			//��������Դ					0-�ر�	1-��
		BYTE	detPowerOpen					:1;			//̽���Դ						0-�ر�	1-��
		BYTE	drvPowerOpen					:1;			//������Դ						0-�ر�	1-��
		BYTE	main_emg_up						:1;			//����̨��ͣ��ť				0-����	1-�ͷ�
		BYTE	testingRoom_emg_up				:1;			//����Ҽ�ͣ��ť				0-����	1-�ͷ�
		//2017.05.30����
		BYTE	panDetPowerOpen					:1;			//�����Դ						0-�ر�	1-��
		BYTE	lightPowerOpen					:1;			//������Դ						0-�ر�	1-��
		
		//2017.07.31����
		BYTE	panDetAtWorkPos					:1;			//����λ�ڹ���λ				0-��Ч	1-�ڹ���λ
		BYTE	panDetAtReturnPos				:1;			//����λ�ڳ���λ				0-��Ч	1-�ڳ���λ
		//2017.09.26����
		BYTE	changingDet						:1;			//�л�̽����״̬				0-ֹͣ		1-�����л�
		BYTE	panDet_Inuse			        :1;			//̽����ʹ��״̬				0-��ǰʹ������	1-��ǰʹ������
		BYTE									:4; 		//����
		 
		//*********************status7: 16 bits*****************************
		//��16λ��Ϊ����ϵͳ״̬
		BYTE	autoMode				        :1;			//�ֶ�/�Զ�״̬					0-�ֶ�		1-�Զ�
		BYTE	seekingZero						:1;			//�˶���ʼ��״̬				0-ֹͣ		1-��������
		BYTE	sys_zero_found			        :1;			//ϵͳ��λ״̬					0-δȷ��	1-��ȷ��
		BYTE	motorRun				        :1;			//�������״̬					0-���е��ֹͣ	1-�е������
		BYTE	scanning				        :1;			//ɨ��״̬						0-����		1-����ɨ��
		BYTE	cmdRun					        :1;			//����ִ��ָʾ					0-��		1-����ִ������
		BYTE	sliceThickAdjusting				:1;			//������ָʾ					0-ֹͣ		1-���ڽ���
		BYTE	collimatorSelecting				:1;			//׼ֱ���л�ָʾ				0-ֹͣ		1-���ڽ���

		BYTE	ready					        :1;     	//ϵͳ��ʼ�����				0-δ���	1-���
		BYTE	idle					        :1;     	//ϵͳ���б�־					0-æ		1-����
		BYTE	warn					        :1;     	//ϵͳ�澯						0-����		1-�澯
		BYTE	fault					        :1;     	//ϵͳ����						0-����		1-����
		BYTE	save					        :1;     	//�ɼ����ݴ���ָʾ				0-������	1-֪ͨ����
		BYTE	lock					        :1;     	//����ָʾ						0-δ����	1-������
		BYTE	onBeamTip						:1;     	//������������ʾ				0-����ʾ	1-��ʾ����
		BYTE	waitNextScan			        :1;     	//CTɨ��ȴ�״̬				0-��		1-�ȴ�CMD_NEXT_SCAN����
					
		//*********************status8: 16 bits*****************************
		//2017.05.26����
		BYTE	detRadial_org					:1;			//̽�⾶��ο��ź�				0-��Ч	1-��Ч
		BYTE	detTranslation_org				:1;			//̽��ƽ�Ʋο��ź�				0-��Ч	1-��Ч
		BYTE	rayRadial_org					:1;			//���߾���ο��ź�				0-��Ч	1-��Ч
		BYTE	rayTranslation_org				:1;			//����ƽ�Ʋο��ź�				0-��Ч	1-��Ч
		BYTE	objVertical_org					:1;			//���������ο��ź�				0-��Ч	1-��Ч
		BYTE	deflection_org					:1;			//ƫ�ڲο��ź�					0-��Ч	1-��Ч
		BYTE									:2;			//����
					
		BYTE	detRadial_alarm					:1;			//̽�⾶��澯					0-����	1-�澯
		BYTE	detTranslation_alarm			:1;			//̽��ƽ�Ƹ澯					0-����	1-�澯
		BYTE	rayRadial_alarm					:1;			//���߾���澯					0-����	1-�澯
		BYTE	rayTranslation_alarm			:1;			//����ƽ�Ƹ澯					0-����	1-�澯
		BYTE	objVertical_alarm				:1;			//���������澯					0-����	1-�澯
		BYTE	deflection_alarm				:1;			//ƫ�ڸ澯						0-����	1-�澯
		BYTE									:2;			//����

		//*********************status9: 16 bits*****************************
		BYTE	detRadial_SDp					:1;			//̽�⾶��SD+						0-��Ч	1-��Ч
		BYTE	detRadial_SDn					:1;			//̽�⾶��SD-						0-��Ч	1-��Ч
		BYTE	detTranslation_SDp				:1;			//̽��ƽ��SD+						0-��Ч	1-��Ч
		BYTE	detTranslation_SDn				:1;			//̽��ƽ��SD-						0-��Ч	1-��Ч
		BYTE	rayRadial_SDp					:1;			//���߾���SD+						0-��Ч	1-��Ч
		BYTE	rayRadial_SDn					:1;			//���߾���SD-						0-��Ч	1-��Ч
		BYTE	rayTranslation_SDp				:1;			//����ƽ��SD+						0-��Ч	1-��Ч
		BYTE	rayTranslation_SDn				:1;			//����ƽ��SD-						0-��Ч	1-��Ч

		BYTE	objVertical_SDp					:1;			//��������SD+						0-��Ч	1-��Ч
		BYTE	objVertical_SDn					:1;			//��������SD-						0-��Ч	1-��Ч
		BYTE	deflection_SDp					:1;			//ƫ��SD+						0-��Ч	1-��Ч
		BYTE	deflection_SDn					:1;			//ƫ��SD-						0-��Ч	1-��Ч
		BYTE									:4; 		//����

		//*********************status10: 16 bits*****************************
		BYTE	detRadial_ELp					:1;			//̽�⾶��EL+						0-��Ч	1-��Ч
		BYTE	detRadial_ELn					:1;			//̽�⾶��EL-						0-��Ч	1-��Ч
		BYTE	detTranslation_ELp				:1;			//̽��ƽ��EL+						0-��Ч	1-��Ч
		BYTE	detTranslation_ELn				:1;			//̽��ƽ��EL-						0-��Ч	1-��Ч
		BYTE	rayRadial_ELp					:1;			//���߾���EL+						0-��Ч	1-��Ч
		BYTE	rayRadial_ELn					:1;			//���߾���EL-						0-��Ч	1-��Ч
		BYTE	rayTranslation_ELp				:1;			//����ƽ��EL+						0-��Ч	1-��Ч
		BYTE	rayTranslation_ELn				:1;			//����ƽ��EL-						0-��Ч	1-��Ч

		BYTE	objVertical_ELp					:1;			//��������EL+						0-��Ч	1-��Ч
		BYTE	objVertical_ELn					:1;			//��������EL-						0-��Ч	1-��Ч
		BYTE	deflection_ELp					:1;			//ƫ��EL+						0-��Ч	1-��Ч
		BYTE	deflection_ELn					:1;			//ƫ��EL-						0-��Ч	1-��Ч
		BYTE									:4; 		//����
	}s; 
	WORD	u[10];
	BYTE	b[20];
};

//����ϵͳ״̬�ֽṹ
/******        �ߵ�ƽ��Ч        ******/
union ControlSystemStatus{
	struct{
		//*********************status12: 16 bits*****************************
		//��16λ��Ϊ����ϵͳ״̬
		BYTE	autoMode						:1;     	//�ֶ�/�Զ�״̬					0-�ֶ�		1-�Զ�
		BYTE	seekingZero						:1;     	//�˶���ʼ��״̬				0-ֹͣ		1-��������
		BYTE	sys_zero_found					:1;     	//ϵͳ��λ״̬					0-δȷ��	1-��ȷ��
		BYTE	motorRun						:1;     	//�������״̬					0-���е��ֹͣ	1-�е������
		BYTE	scanning						:1;     	//ɨ��״̬						0-����		1-����ɨ��
		BYTE	cmdRun							:1;     	//����ִ��ָʾ					0-��		1-����ִ������
		BYTE	sliceThickAdjusting				:1;     	//������ָʾ					0-ֹͣ		1-���ڽ���
		BYTE	collimatorSelecting				:1;     	//׼ֱ���л�ָʾ				0-ֹͣ		1-���ڽ���

		BYTE	ready					        :1;     	//ϵͳ��ʼ�����				0-δ���	1-���
		BYTE	idle					        :1;     	//ϵͳ���б�־					0-æ		1-����
		BYTE	warn					        :1;     	//ϵͳ�澯						0-����		1-�澯
		BYTE	fault					        :1;     	//ϵͳ����						0-����		1-����
		BYTE	save					        :1;     	//�ɼ����ݴ���ָʾ				0-������	1-֪ͨ����
		BYTE	lock					        :1;     	//����ָʾ						0-δ����	1-������
		BYTE	onBeamTip						:1;     	//������������ʾ				0-����ʾ	1-��ʾ����
		BYTE	waitNextScan			        :1;     	//CTɨ��ȴ�״̬				0-��		1-�ȴ�CMD_NEXT_SCAN����
	}s;					
	WORD	u;
};

//�˶�����ֵ
struct Coordination{
	float	graduation;										//�ֶ�
	float   objTranslation;									//����ƽ��                
	float   interpolation;									//��ֵ                    
	float   layer1;											//����Դ�ֲ�              
	float   layer2;											//̽�����ֲ�              
	float   objRadial;										//��������                
	float   sliceThickness;									//�ϲ���(��׼ֱ�׸߶�)  
	float   collimator;										//׼ֱ�׿��              
	float   detRadial;										//̽����X�����˶���			
	float   detTranslation;									//̽����Y�����˶���			
	float   rayRadial;										//����ԴX�����˶���			
	float   rayTranslation;									//����ԴY�����˶���			
	float   objVertical;									//����Z�����˶���			
	float   deflection;										//ƫ���˶�					
};						

//I/O�˿�״̬
union IoRegStatus{
	struct{
		BYTE	out[4];										//����Ĵ���״̬
		BYTE	in[4];										//����˿�״̬
	}s;					
	BYTE	data[8];
};

//����ָ�������˶�����CMD_AXIS_MOVE_STEP�����ֽṹ
struct AxisMoveStepCmdData{
	BYTE	axisNo;											//�����
	float	distance;										//�˶�����(mm)
};					

//���������˶�����CMD_AXIS_MOVE_CONTINEOUS�����ֽṹ
struct AxisMoveContCmdData{
	BYTE	axisNo;
	union{
		BYTE	b;										    //�����
		struct{					
			BYTE		    :7;					
			BYTE	dir	    :1;							    //�˶�����(P_DIR/N_DIR)
		}s;					
	}dir;					
};

//�ֲ������˶�����CMD_SLICE_MOVE_CONTINEOUS�����ֽṹ
union SliceMoveContCmdData{
	BYTE	b;											    //�����
	struct{					
		BYTE		        :7;					
		BYTE	dir		    :1;							    //�˶�����(P_DIR/N_DIR)
	}s;					
};

//׼ֱ�׿��ѡ������CMD_COLLIMATE_WIDTH_SWITCH�����ֽṹ
struct CollimateWidthSwitchCmdData{
	BYTE	holeNo;										    //׼ֱ�״���:0-2
};					
					
//�ϲ��ȵ�������CMD_COLLIMATE_HEIGHT_ADJUST�����ֽṹ
struct LayerThicknessAdjustCmdData{
	float	layerThickness;								    //�ϲ���(mm)
};					
					
//�����˶���ָ��λ������CMD_AXIS_GOTO_SPECIFIC_POS�����ֽṹ
struct AxisGotoSpecificPosCmdData{
	BYTE	axisNo;										    //�����
	float	pos;										    //�˶�λ��(mm���)
};					

//�ֲ��˶���ָ��λ������CMD_SLICE_GOTO_SPECIFIC_POS�����ֽṹ
struct SliceGotoSpecificPosCmdData{
	float	pos;										    //�˶�λ��(mm)
};	
				
//��ǿ�������CMD_MARK���ݽṹ
struct MarkCtrlCmdData{
	float	horizontalCoordinate;						//ȱ��ˮƽ����(��λ��mm)
	float	verticalCoordinate;							//ȱ�ݴ�ֱ����(��λ��mm)
	float	rotationAngle;								//ȱ�ݽǶ� (��λ����)
};
					
//ɨ����������ֽṹ
//CT����״̬λ����
//2017.04.26����btnStartScan, autoStopBeam
union CT23StsBit{
	struct{												//2��ɨ��λ�ṹ
		BYTE  btnStartScan		:1;							//0-��������ɨ��,		1-�ȴ�������ť����ɨ��
		BYTE  changeLayerSpace	:1;							//0-�Ȳ��ɨ��,	    1-����ɨ��
		BYTE            		:1;							//0-��ͨ3��ɨ��,	1-
		BYTE  czAmountInc1		:1;							//0-��׼��ֵ��,	    1-��ֵ����1
		BYTE  autoStopBeam		:1;							//0-ɨ�������ͣ��,	1-ɨ�����ֹͣ����
		BYTE  currentLayer		:1;							//0-�����������ֲ�, 1-��ǰ��ɨ��
		BYTE  biDirTranslation	:1;							//2��ɨ��ʱ:0-����ƽ��, 1-2��CT˫��ƽ��
		BYTE  thirdGeneration	:1;							//0-2��CTɨ��,		1-3��CTɨ��
	}s;					
	struct{												//3��ɨ��λ�ṹ
		BYTE  btnStartScan		:1;							//0-��������ɨ��,		1-�ȴ�������ť����ɨ��
		BYTE  changeLayerSpace	:1;							//0-�Ȳ��ɨ��,	    1-����ɨ��
		BYTE            		:1;							//0-��ͨ3��ɨ��,	1-���ӳ�2��+3�����ɨ��
		BYTE  czAmountInc1		:1;							//0-��׼��ֵ��,	    1-��ֵ����1
		BYTE  autoStopBeam		:1;							//0-ɨ�������ͣ��,	1-ɨ�����ֹͣ����
		BYTE  currentLayer		:1;							//0-�����������ֲ�, 1-��ǰ��ɨ��
		BYTE  physiInterpolation:1;							//3��ɨ��ʱ:0-ģ���ֵ, 1-�����ֵ
		BYTE  thirdGeneration	:1;							//0-2��CTɨ��,		1-3��CTɨ��
	}s1;					
	BYTE  c;
};
//DR����״̬λ����
//2017.04.26����autoStopBeam
union DRStsBit{
	struct{
		BYTE  physiInterpolation:1;							//0-ģ���ֵ,		1-�����ֵ
		BYTE  multiAngle		:1;							//0-���Ƕ�ɨ��,		1-��Ƕ�ɨ��
		BYTE  twoVehicle		:1;							//0-1�����С��,	1-2�����С��
		BYTE  czAmountInc1		:1;							//0-��׼��ֵ��,		1-��ֵ����1
		BYTE  autoStopBeam		:1;						    //0-ɨ�������ͣ��,	1-ɨ�����ֹͣ����
		BYTE  biDirScan			:1;							//0-����ɨ��,		1-˫��ɨ��
		BYTE  btnStartScan		:1;							//0-���������������ʼɨ��, 1-����Դ������ť����ɨ��
		BYTE  thirdGeneration	:1;							//0-2��ƴ��ɨ��,	1-3����ֵɨ��
   }s;					
   BYTE  c;
};
//�ֲ�CTɨ������״̬λ����
union LocalStsBit{
	struct{
		BYTE					:5;							//D0-4
		BYTE	currentLayer	:1;							//D5: 0-�����������ֲ�, 1-��ǰ��ɨ��
		BYTE	biDirTranslation:1;							//D6: 0-����ƽ��, 1-˫��ƽ��
		BYTE					:1;							//D7: 
	}s;
	BYTE	c;
};
//����CT����״̬λ����
union HelixStsBit{
	struct{
		BYTE  physiInterpolation:1;							//0-ģ���ֵ,		1-�����ֵ
		BYTE  biDirScan			:1;							//0-����ֲ�,		1-������ɨ,
		BYTE			        :1;					
		BYTE  czAmountInc1		:1;							//0-��׼��ֵ��,	1-��ֵ����1,
		BYTE				    :1;							
		BYTE  currentLayer		:1;							//0-��������λ��ɨ��,1-��ǰ��λ�ÿ�ʼɨ�� 
		BYTE				    :2;							//
	}s;					
	BYTE  c;					
};
//׶��CT����״̬λ����
union ConeStsBit{
	struct{
		BYTE  translationCone   :1;							//0-��ͨ׶��ɨ��,	1-ƽ��׶��ɨ��
		BYTE				    :4;        					
		BYTE  currentLayer		:1;							//0-����������ȷ����λ��,1-��ǰ��λ��
		BYTE				    :1;        
		BYTE  coneHelix			:1;							//0-׶��ɨ��,		1-׶������ɨ��
             					
   }s;					
   BYTE  c;
};

//2/3��CTɨ������CMD_CT_SCAN�����ֽṹ
struct CT23ScanCmdData{
	CT23StsBit	stsBit;										//����״̬λ
	BYTE	interpolationAmount;							//3��ɨ��̽����λ����(��ֵ����)DM(>=1)
	WORD	projectionAmount;								//ͶӰ����PN
	BYTE	reserved1;										//����
	WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
	float   viewDiameter;									//�ӳ�ֱ��(mm)
	short	orientInc;										//�ֶȷ�λ������(��,0-360)
	WORD	ct2Mode;									    //2��ɨ��ģʽ(0-360��,1-180��,2-180�ȼ��)
	WORD	sliceAmount;									//ɨ�����SN
	BYTE	tabelNumber;									//ɨ��ת̨����(��4λΪ0ʱ,�Ե�4λ��ʾ��ת̨����Ϊԭ�����ɨ��;
														    //��4λ��Ϊ0ʱ,�Ըߵ�4λ��ʾ������ת̨������������Ϊԭ�����ɨ��)
	float	centerOffset;								   	//��ת����ƫ��(mm)
	float	firstLayerOffset;							   	//��1��ƫ��(mm)
	float	layerSpace;									   	//���ڲ���(mm)
};					
					
//���ӳ�CTɨ������CMD_LARGEVIEW_SCAN�����ֽṹ
struct LargeViewCTScanCmdData{
	CT23StsBit	stsBit;										//����״̬λ
	BYTE	interpolationAmount;							//3��ɨ��̽����λ����(��ֵ����)DM(>=1)
	WORD	projectionAmount;								//ͶӰ����PN
	BYTE	reserved1;										//����
	WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
	float   viewDiameter;									//�ӳ�ֱ��(mm)
	short	orientInc;										//�ֶȷ�λ������(��,0-360)
	WORD	sliceAmount;									//ɨ�����SN
	float	centerOffset;								   	//��ת����ƫ��(mm)
	float	firstLayerOffset;							   	//��1��ƫ��(mm)
	float	layerSpace;									   	//���ڲ���(mm)
};					
					
//DRɨ������CMD_DR_SCAN�����ֽṹ
struct DRScanCmdData{
	DRStsBit	stsBit;										//����״̬λ
	BYTE    interpolationAmount;							//DRɨ��̽����λ����(��ֵ����)DM(>=1)
	WORD	projectionAmount;								//�ֲ�ͶӰ����PN
	WORD	angleAmount;									//����Ƕ�DRɨ��ʱ�ĽǶ���AN
	BYTE	reserved1;										//����
	WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
	float	viewDiameter;									//�ӳ�ֱ��(mm)
	short	orientInc;										//�ֶȷ�λ������(��,0-360)
	float	centerOffset;								   	//��ת����ƫ��(mm)
	float	firstLayerOffset;								//��ʼɨ������(Xs,mm)
	float	layerSpace;										//���ڲ���(mm)
	BYTE	reserved2;										//����
	BYTE	tabelNumber;									//ɨ��ת̨����(��4λΪ0ʱ,�Ե�4λ��ʾ��ת̨����Ϊԭ�����ɨ��;
};

//�ֲ�ɨ������CMD_LOCAL_SCAN�����ֽṹ
struct LocalScanCmdData{
	LocalStsBit	stsBit;										//����״̬λ
	BYTE	ct2Mode;									    //2��ɨ��ģʽ(0-360��,1-180��,2-180�ȼ��)
	WORD	projectionAmount;								//�ֲ�ͶӰ����PN
	WORD	sliceAmount;									//ɨ�����SN
	WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
	float	localViewDiameter;								//�ֲ������ӳ�ֱ��(mm)
	float	localCenterSpace;								//�ֲ�������������ת���ľ���(mm)
	float	orientAngle;									//��ת�������ֲ���������������ˮƽ����(X��)�н�(��)
	float	centerOffset;								   	//��ת����ƫ��(mm)
	float	firstLayerOffset;								//��1��ƫ��(mm)
	float	layerSpace;										//����(mm)
};					

//����ɨ������CMD_HELIX_SCAN�����ֽṹ
struct HelixScanCmdData{
	HelixStsBit	stsBit;										//����״̬λ
	BYTE	interpolationAmount;							//����ɨ��̽����λ����(��ֵ����)DM(>=1)
	WORD	projectionAmount;								//ͶӰ����PN
	WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
	float	viewDiameter;									//�ӳ�ֱ��(mm)
	WORD	circleAmount;									//�ֶ�Բ����CN
	short	orientInc;										//�ֶȷ�λ������(��,0-360)
	float	centerOffset;								   	//��ת����ƫ��(mm)
	float	firstLayerOffset;								//��1��ƫ��(mm)
	float	helixSpace;										//�ݾ�(mm)
};

////׶������ɨ������CMD_CONE_SCAN�����ֽṹ
//struct ConeScanCmdData{
//	ConeStsBit	stsBit;										//����״̬λ 
//	WORD	projectionAmount;							    //ͶӰ����PN
//	WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
//	short	orientInc;									   	//�ֶȷ�λ������(��,0-360)
//	WORD	circleAmount;								   	//�ֶ�Բ����CN
//	float	centerOffset;								   	//��ת����ƫ��(mm)
//	float	firstLayerOffset;							   	//��1��ƫ��(mm)
//	float	helixSpace;									   	//�ݾ�(mm)
//}ConeScanCmdData;					
		
//׶������ɨ������CMD_CONE_SCAN�����ֽṹ
struct ConeScanCmdData{
	ConeStsBit	stsBit;										//����״̬λ 
	WORD	projectionAmount;							    //ͶӰ����PN
	//WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
	float 	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
	WORD	frame;											//֡��
	short	orientInc;									   	//�ֶȷ�λ������(��,0-360)
	BYTE	b180Scan;									//180��ɨ���־(0-360��;1-180��)
	WORD	circleAmount;								   	//�ֶ�Բ����CN
	float	centerOffset;								   	//��ת����ƫ��(mm)
	float	firstLayerOffset;							   	//��1��ƫ��(mm)
	float	helixSpace;									   	//�ݾ�(mm)
	WORD	crossGradAngle;									//����ɨ���÷ֶȽǣ�30�㣬45�㣬60�㣬90�㣩
	BYTE	bCrossEquAngle;								//����ɨ���õȼ��/�ȽǶȱ�־(0-�ȼ�࣬1-�ȽǶ�)
	BYTE	bEnableDetYMove;							//̽����ƽ�����˶����(0-���˶���1-�˶�)
};					

//�ֲ����궨����CMD_CAL_LAYER_ZERO�����ֽṹ
struct CalAxisZeroCmdData{
	BYTE	axisType;										//У���᣺0-�ֲ㣻1-������2-����
	float	firstLayerOffset;							   	//��1�ֲ�ƫ��(mm)
	WORD	sampleTime;										//ͶӰ����ʱ��Tp(4-2000ms)
};					
					
//��Դ��������CMD_POWER_CTRL�����ֽṹ
union PowerCtrlCmd{
   struct{
	   BYTE	onDetPower		:1;								//0-�ر�̽������Դ,		1-��̽������Դ
	   BYTE	onDrvPower		:1;								//0-�رն�����Դ,		1-�򿪶�����Դ
	   BYTE onCamera	    :1;								//0-�ر�����ͷ��Դ,		1-������ͷ��Դ
	   BYTE	onLaser			:1;								//0-�رռ�������Դ,		1-�򿪼�������Դ
	   BYTE	onPanDetPower	:1;								//0-�ر�����̽������Դ,		1-������̽������Դ
	   BYTE	onLight			:1;								//0-�ر�������Դ,		1-��������Դ
	   BYTE	onPanDetWorkPos :1;								//0-�ر�������λ�������Դ,		1-��������λ�������Դ
	   BYTE	onPanDetReturnPos :1;							//0-�ر�������λ�������Դ,		1-��������λ�������Դ

	   BYTE	detPowerMask	:1;                             //0-��ֹ����̽������Դ, 1-�������̽������Դ
	   BYTE drvPowerMask	:1;								//0-��ֹ���ƶ�����Դ,	1-������ƶ�����Դ
	   BYTE cameraMask		:1;                             //0-��ֹ��������ͷ��Դ, 1-�����������ͷ��Դ
	   BYTE laserMask		:1;                             //0-��ֹ���Ƽ�������Դ, 1-������Ƽ�������Դ
	   BYTE	panDetPowerMask	:1;								//0-��ֹ����̽������Դ,		1-��������̽������Դ
	   BYTE	lightMask		:1;								//0-��ֹ������Դ,		1-����������Դ
	   BYTE	panDetWorkPosMask	:1;							//0-��ֹ������λ�������Դ,	1-����������λ�������Դ
	   BYTE	panDetReturnPosMask	:1;							//0-��ֹ������λ�������Դ,	1-����������λ�������Դ
   }s;
   BYTE  b;
};

//��ƽ״̬�����ṹ
struct BanlanceCtrlSts{
	struct{
		//ƽ̨1֧��״̬
		BYTE	plat1Leg3Drive_fault	:1;								//ƽ̨1֧��3���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat1Leg3OnGround		:1;								//ƽ̨1֧��3����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat1Leg3_ELp			:1;								//ƽ̨1֧��3����λ��		0-��Ч,		1-��Ч
		BYTE	plat1Leg3_ELn			:1;								//ƽ̨1֧��3����λ��		0-��Ч,		1-��Ч
		BYTE	plat1Leg4Drive_fault	:1;								//ƽ̨1֧��4���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat1Leg4OnGround		:1;								//ƽ̨1֧��4����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat1Leg4_ELp			:1;								//ƽ̨1֧��4����λ��		0-��Ч,		1-��Ч
		BYTE	plat1Leg4_ELn			:1;								//ƽ̨1֧��4����λ��		0-��Ч,		1-��Ч

		BYTE	plat1Leg1Drive_fault	:1;								//ƽ̨1֧��1���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat1Leg1OnGround		:1;								//ƽ̨1֧��1����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat1Leg1_ELp			:1;								//ƽ̨1֧��1����λ��		0-��Ч,		1-��Ч
		BYTE	plat1Leg1_ELn			:1;								//ƽ̨1֧��1����λ��		0-��Ч,		1-��Ч
		BYTE	plat1Leg2Drive_fault	:1;								//ƽ̨1֧��2���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat1Leg2OnGround		:1;								//ƽ̨1֧��2����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat1Leg2_ELp			:1;								//ƽ̨1֧��2����λ��		0-��Ч,		1-��Ч
		BYTE	plat1Leg2_ELn			:1;								//ƽ̨1֧��2����λ��		0-��Ч,		1-��Ч
																
		//ƽ̨2֧��״̬
		BYTE	plat2Leg3Drive_fault	:1;								//ƽ̨2֧��3���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat2Leg3OnGround		:1;								//ƽ̨2֧��3����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat2Leg3_ELp			:1;								//ƽ̨2֧��3����λ��		0-��Ч,		1-��Ч
		BYTE	plat2Leg3_ELn			:1;								//ƽ̨2֧��3����λ��		0-��Ч,		1-��Ч
		BYTE	plat2Leg4Drive_fault	:1;								//ƽ̨2֧��4���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat2Leg4OnGround		:1;								//ƽ̨2֧��4����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat2Leg4_ELp			:1;								//ƽ̨2֧��4����λ��		0-��Ч,		1-��Ч
		BYTE	plat2Leg4_ELn			:1;								//ƽ̨2֧��4����λ��		0-��Ч,		1-��Ч

		BYTE	plat2Leg1Drive_fault	:1;								//ƽ̨2֧��1���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat2Leg1OnGround		:1;								//ƽ̨2֧��1����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat2Leg1_ELp			:1;								//ƽ̨2֧��1����λ��		0-��Ч,		1-��Ч
		BYTE	plat2Leg1_ELn			:1;								//ƽ̨2֧��1����λ��		0-��Ч,		1-��Ч
		BYTE	plat2Leg2Drive_fault	:1;								//ƽ̨2֧��2���������ϣ�	0-�޹���,	1-�й���
		BYTE	plat2Leg2OnGround		:1;								//ƽ̨2֧��2����ָʾ��		0-δ����,	1-�Ѿ�����
		BYTE	plat2Leg2_ELp			:1;								//ƽ̨2֧��2����λ��		0-��Ч,		1-��Ч
		BYTE	plat2Leg2_ELn			:1;								//ƽ̨2֧��2����λ��		0-��Ч,		1-��Ч
																			  
		BYTE	scene_emg_down			:1;								//�ֱ���ͣ��ť				0-�ͷ�		1-����
		BYTE	plat1_lock_ok			:1;								//ƽ̨1��ȫ��������״̬		0-��Ч		1-��Ч
		BYTE	plat2_lock_ok			:1;								//ƽ̨2��ȫ��������״̬		0-��Ч		1-��Ч
		BYTE	reserve2				:5;								//����

		BYTE	plat1_banlanced			:1;								//ƽ̨1�ѵ�ƽָʾ��			0-δ��ƽ,	1-�ѵ�ƽ
		BYTE	plat2_banlanced			:1;								//ƽ̨2�ѵ�ƽָʾ��			0-δ��ƽ,	1-�ѵ�ƽ
		BYTE	plat1_emg_down			:1;								//ƽ̨1��ͣ��ť				0-�ͷ�		1-����
		BYTE	plat2_emg_down			:1;								//ƽ̨2��ͣ��ť				0-�ͷ�		1-����
		BYTE	plat1_moving			:1;								//ƽ̨1�˶�ָʾ				0-ֹͣ		1-�˶���
		BYTE	plat2_moving			:1;								//ƽ̨2�˶�ָʾ				0-ֹͣ		1-�˶���
		BYTE	sceneCtrlFlag			:1;								//���ؿ���ָʾ				0-�ֳ�		1-Զ��
		BYTE	remoteCtrlFlag			:1;								//Զ�̿���ָʾ				0-�ֳ�		1-Զ��
	}s;
	BYTE	plat1AngleX[4];												//ƽ̨1X����Ƕȣ�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat1AngleY[4];												//ƽ̨1Y����Ƕȣ�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat2AngleX[4];												//ƽ̨2X����Ƕȣ�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat2AngleY[4];												//ƽ̨2Y����Ƕȣ�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat3AngleX[4];												//ƽ̨3X����Ƕȣ�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat3AngleY[4];												//ƽ̨3Y����Ƕȣ�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	
	BYTE	plat1Leg1Pos[4];											//ƽ̨1֧��1λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat1Leg2Pos[4];											//ƽ̨1֧��2λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat1Leg3Pos[4];											//ƽ̨1֧��3λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat1Leg4Pos[4];											//ƽ̨1֧��4λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��

	BYTE	plat2Leg1Pos[4];											//ƽ̨1֧��1λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat2Leg2Pos[4];											//ƽ̨1֧��2λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat2Leg3Pos[4];											//ƽ̨1֧��3λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
	BYTE	plat2Leg4Pos[4];											//ƽ̨1֧��4λ�ã�4�ֽ�BCD������4λ����λ(0-��,1-��)����������������С��
};

//��ƽϵͳ��ʾ����ýṹ
struct BanlanceTipSts{
	struct{
		//ƽ̨1֧��״̬
		BYTE	plat1Leg1Moving			:1;								//ƽ̨1֧��1����ָʾ��	0-ֹͣ,	1-����
		BYTE	plat1Leg2Moving			:1;								//ƽ̨1֧��2����ָʾ��	0-ֹͣ,	1-����
		BYTE	plat1Leg3Moving			:1;								//ƽ̨1֧��3����ָʾ��	0-ֹͣ,	1-����
		BYTE	plat1Leg4Moving			:1;								//ƽ̨1֧��4����ָʾ��	0-ֹͣ,	1-����
		//ƽ̨2֧��״̬
		BYTE	plat2Leg1Moving			:1;								//ƽ̨2֧��1����ָʾ��	0-ֹͣ,	1-����
		BYTE	plat2Leg2Moving			:1;								//ƽ̨2֧��2����ָʾ��	0-ֹͣ,	1-����
		BYTE	plat2Leg3Moving			:1;								//ƽ̨2֧��3����ָʾ��	0-ֹͣ,	1-����
		BYTE	plat2Leg4Moving			:1;								//ƽ̨2֧��4����ָʾ��	0-ֹͣ,	1-����

		BYTE	reserve1				:8;								//����
	}s;
	float	plat1Leg1Pos;												//ƽ̨1֧��1λ��
	float	plat1Leg2Pos;												//ƽ̨1֧��2λ��
	float	plat1Leg3Pos;												//ƽ̨1֧��3λ��
	float	plat1Leg4Pos;												//ƽ̨1֧��4λ��

	float	plat2Leg1Pos;												//ƽ̨1֧��1λ��
	float	plat2Leg2Pos;												//ƽ̨1֧��2λ��
	float	plat2Leg3Pos;												//ƽ̨1֧��3λ��
	float	plat2Leg4Pos;												//ƽ̨1֧��4λ��
};

//���������ݷ����ṹ
struct LaserMeasValueSts{
	//struct{
	//	BYTE	stoDLaserAimed1				:1;					//�����������׼�ź�			0-δ��׼		1-�Ѷ�׼
	//	BYTE	stoDLaserAimed2				:1;					//�����������׼�ź�			0-δ��׼		1-�Ѷ�׼
	//	BYTE	stoDLaserAimed3				:1;					//�����������׼�ź�			0-δ��׼		1-�Ѷ�׼
	//	BYTE	reserve1					:5;					//����

	//	BYTE	reserve2					:8;					//����
	//}s;
	struct{
		BYTE	stoDLaserAimed1;					//�����������׼�ź�			0-δ��׼		1-�Ѷ�׼
		BYTE	stoDLaserAimed2;					//�����������׼�ź�			0-δ��׼		1-�Ѷ�׼
		BYTE	stoDLaserAimed3;					//�����������׼�ź�			0-δ��׼		1-�Ѷ�׼
		BYTE	reserve1[5];			//����

		BYTE	reserve2[8];					//����
	}s;

	BYTE	stoDLaserValue[8];								//��������̽�������������ֵ(mm)
	float   stoOLaserValue1,								//�������⹤�����������ֵ(mm)
			stoOLaserValue2,								//�������⹤�����������ֵ(mm)
			stoOLaserValue3;								//�������⹤�����������ֵ(mm)
};

//CMD_SAIMDLASER_GOTO_LAST_POS
//���˶�ϵͳ��λ��Դ-̽���������������׼λ��
struct SAimDLaserGotoLastPosCmd{
	float   layer1,											//�ֲ�1(mm)
			layer2,											//�ֲ�2(mm)
			rayVertical,									//��������(mm)
			lineDetVertical;								//��������(mm)
};

//������λ���ݽṹ(��������)
struct FWorkZero{
	float   graduation,										//�ֶ�(��)
			objTranslation,									//����ƽ��(mm)
			interpolation,									//��ֵ(mm)
			layer1,											//�ֲ�1(mm)
			layer2,										    //�ֲ�2(mm)
			objRadial,										//��������(mm)
			sliceThick,										//���(mm)
			collimator1,									//׼ֱ��1����λ��������������(mm)
			collimator2,									//׼ֱ��2����λ��������������(mm)
			collimator3,									//׼ֱ��3����λ��������������(mm)
			objVertical,									//��������(mm)
			rayRadial,										//����Դ�����˶���		   
			rayTranslation,									//����Դƽ���˶���	 
			detRadial,										//̽���������˶���	   
			detTranslation,									//̽����ƽ���˶���	
			deflection;										//ƫ���˶�(��)    
};					
					
//ϵͳ�����ļ��ṹ(�ײ��������)
struct SysData{
	char		head[32];									//�ļ�ͷ�ַ���
	FWorkZero   zero;										//ϵͳ������λ���ݽṹ
	long		ltOffset;									//�ϲ���ƫ��
	BYTE		currentZzq;									//��ǰ׼ֱ��
	WORD		synFreq;									//������ͬ��Ƶ��(Hz)
	BYTE		varifySum;									//�����ļ�У���
};
union USysData{
	SysData  s;
	BYTE		b[sizeof(SysData)];
};

//����ʹ��WM_COPYDATA��Ϣ�������ݽṹ
struct MYCDSRET_FLAG{
	int     nResult;												//״̬�뷵�ر�־
	wchar_t	desFilePath[MAX_PATH];									//ȫ·��Ŀ�������ļ���
};

//����WM_COPYDATA��Ϣ�����������־
enum{
	CPDT_LINE_DET		=	0,                                     //ָʾ����
	CPDT_PAN_DET,													//ָʾ����
	CPDT_CONE_LARGEVIEW_ONLY							//
};

//����ʹ��WM_COPYDATA��Ϣ�������ݽṹ
struct FILENAME_FLAG{
	UINT    bDetTypeLine_Pan;										//����/�����־
	//�������
	char	parFilePath[MAX_PATH];									//�����ļ�·��
	char	orgFileName[MAX_PATH];									//ȫ·��ԭʼ�����ļ���
	int		bReconstruction;										//�����������ؽ�ͼ���־:1-Reconstruction
	//�������
	ICT_HEADER23 d_ictHeaderForPan;										//����ͷ�ṹ����
	char	darkFilePath[MAX_PATH];									//ȫ·�����������ļ���
	char	gainFilePath[MAX_PATH];									//ȫ·�����������ļ���
	char	defectFilePath[MAX_PATH];								//ȫ·�������������ļ���
	char	saveFilePath[MAX_PATH];									//ȫ·��CT�����ļ���
	int		nCrossTransCnt;												//����ɨ��ƽ�ƴ���
	BOOL	bDarkCorrectFlag;										//����У����־
	BOOL	bGainCorrectFlag;										//����У����־
	BOOL	bDefectCorrectFlag;										//������У����־
	BOOL	bFrameAverageFlag;										//֡ƽ����־
	BOOL	b2TableScan;											//˫ת̨ɨ��
	BOOL	bLastImageFlag;											//�Ƿ����һ��ͼ���־(ͨ��Ϊ����ɼ���)
	float   fDefectMarkPecent;										//�����ر����ʹ�õİٷֱ�(PE�Ǿ���̽������)
	//��������
	char	desFilePath[MAX_PATH];									//Ŀ���ļ�·��
	int		nScanMode;												//��ǰ��ִ�е�ɨ��ģʽ, -1��ʾ��
	int		bSaveOrg;												//ԭʼ���ݱ����־:	1-Save
};


/*----------------------------------------------------------------------*/
/*                       ͨ������������ݽṹ                         */
/* 1. ���������ö�ά���ݽṹ,�ɴ�� 9 �������(������ͷ��У���).       */
/* 2. ��header(ͷָ��)��tailer(βָ��)ָʾ������״̬,��ָ����ͬ��ʾ���� */
/*    ��Ϊ��,���ֵ��Ϊ 0, ��ΧΪ: 0 to 9.                              */
/* 3. ������ճ����β������������뻺����                              */
/* 4. ����������ɨ������ͷ��ȡ�������,ȡ�������ʹheader+1.          */
/* 5. ��������ж��յ�һ�����������,�ȵ������������,������True,��ʾ�� */
/*    ���ѱ�����,����ʹtailer+1.                                        */
/*----------------------------------------------------------------------*/
#pragma pack()											    //�趨���ӳ���8�ֽڶ���(VC������ȱʡ)


