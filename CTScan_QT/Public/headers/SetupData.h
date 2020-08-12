#pragma once
#include <vector>
#include "CtrlData.h"
#include "IctHeader.h"
#include "machineType.h"
#include <map>
#include <tuple>
//系统参数设置数据结构文件

/*
上位机IP地址设置:
IP地址:		192.168.2.124
子网掩码:	255.255.255.0
默认网关:	192.168.2.1

DNS服务器:	202.202.0.33
*/

#define	MAX_PARA_ITEM	    20										//最大参数项
#define	MAX_STR_LENGTH	    100										//最大字符串长度
#define MAX_PASSWORD_LENGTH 32                                      //最大密码串长度
#define	MAX_BLOCK		    160										//以8为单位的最大探测模块数(必须与在AcquireInterface.h中定义一致)
#define	MAX_COMMONMODE_ITEM	20										//最大常用模式项数
#define	MAX_SCANCONFIG_ITEM	32										//最大扫描组态项数

enum class ScanMode
{
	NO_SCAN = -1,												//无扫描操作
	CT1_SCAN,														//Ⅰ代扫描
	CT2_SCAN,														//Ⅱ代扫描
	CT3_SCAN,														//Ⅲ代扫描
	DR_SCAN,														//DR扫描
	LOCAL_SCAN,														//局部扫描
	HELIX_SCAN,														//螺旋扫描
	CONE_SCAN,														//锥束扫描
	CONEHELIX_SCAN,													//锥束螺旋扫描
	BKG_SCAN,														//本底校正扫描(固定采集512个分度)
	AIR_SCAN,														//空气校正扫描(固定采集512个分度)
	CAL_LAYER_ZERO_SCAN,											//标定分层零点扫描(固定采集400点)
	CAL_CENTER_SCAN,												//标定回转中心扫描
	LARGE_VIEW_SCAN,												//大视场扫描(回转中心偏置扫描)
	CONFIG_SCAN,                                            //组态扫描
	//2017.03.29增加
	DEF_MAP_SCAN,											//坏像素校正扫描
	CONEPOINT_SCAN,											//点对点锥束扫描（到位一次采集一次，不需要同步脉冲）
	CROSS_SCAN,												//交错扫描（分度角加对搓采束）
	SINGLE_CROSS_SCAN,										//静态交错(只移动射线源)扫描（分度角加对搓采束）
	CONE_LARGE_VIEW_SCAN,									//锥束大视场扫描
	CONEHELIX_POINT_SCAN,									//锥束螺旋点位扫描
	//CONE_SCAN_2TABLE,										//锥束扫描
	CONE_JOINT_SCAN,                                        //锥束拼接扫描
	CONE_JOINT_ROT_SCAN,                                        //锥束拼接扫描
	_MAX_SCANMODE_ITEM
};
//射线源符号名定义
enum
{
	TUBE_SPELLMAN	=	0,											//X射线管: 使用SPELLMAN高压电源
	TUBE_COMET,														//X射线管: 使用COMET高压电源
	ACCELERATOR,													//电子直线加速器
	ACCELERATOR_NV,													//电子直线加速器(不监控状态)
	ACCELERATOR_7103,												//电子直线加速器(7103)
	HAMAMATSU_12161,												//滨松12161
	TUBE_COMET_IVARIO,                                              //TUBE_COMET_IVARIO
	WORX_225,
	UNKNOW_RAY														//未知射线源(如WORX)
};
//探测器符号定义定义探测器类型(PANEL_PECMOS-[默认],PANEL_PEFPD,PANEL_GNCCD,UNKOWN_PANEL)
enum
{
	PANEL_PECMOS = 0,												//PE CMOS探测器
	PANEL_PESI_0822,												//PE 非晶SI探测器
	PANEL_PESI_1622,												//PE 非晶SI探测器
	PANEL_PESI_1621,												//PE 非晶SI探测器
	PANEL_PESI_1611,												//PE 非晶SI探测器
	PANEL_VARIANSI_1313,											//VARIAN 非晶SI探测器
	PANEL_VARIANSI_2530,											//VARIAN 非晶SI探测器
	PANEL_HAMACMOS,													//HAMAMATSU CMOS探测器
	PANEL_GNCCD,													//高能所CCD探测器
	UNKOWN_PANEL													//未知探测器
};

//控制器符号定义
enum
{
	CTRLER_SIMOTION	= 0,											//NEWPORT控制器
	CTRLER_UMAC,													//UMAC控制器
	CTRLER_PI,														//PI控制器
	CTRLER_PI_UMAC,													//
	UNKOWN_CTRLER													//未知控制器
};

//图像/视频/图片监视模式定义
enum
{
	PICTURE			=	0,											//图片
	VIDEO,															//视频
	IMAGE															//图像
};

//定义线阵数据处理方式
enum
{
	DP_DLL		= 0,												//动态库
	DP_SERVER														//服务器
};

//定义面阵数据处理方式
enum
{
	DP_DETDLL		= 0,											//探测器自带动态库
	//DP_SERVER														//校正函数调用服务器
};

//定义控制端口通信方式
enum
{
	SERIAL_PORT	= 0,												//串行通信端口
	TCP_IP															//TCP/IP网络
};

//定义扫描方式名义值
enum
{
	sDR_SCAN	=	0,												//DR扫描
	sCT_SCAN,														//CT扫描
	sLV_SCAN                                                        //大视场扫描
};

//定义文件命令方式名义值
enum
{
	mDATE	=	0,													//默认命名方式："年月日+4位序号"
	mDATE_NAME_NO                                                   //"年月日_名称_编号_4位序号"，如九院
};

//扫描常用模式数据结构定义
struct _CommonModeData
{
	int		mode;													//扫描模式(1-CT2;2-CT3;3-DR;4-LOCAL)
	WORD	matrix;													//图像矩阵
	float	diameter;												//视场直径(mm)
	//int		deflectionPos;										//偏摆位置(0-无, 1-位置1, 2-位置2, 3-位置3, 4-位置4)
	//short	rotationAngle;											//旋转角度(°)
	int     sampletime;                                             //采样时间(ms)
	int     collimate;												//准直器选择代号(1/2/3)
	float   layerthick;                                             //断层厚度(mm)
	int     syncfreq;                                               //同步频率(Hz)
	float   orientation;                                            //扫描方位(°)
	float	layerspace;												//层间距(mm)
	int     layercnt;                                               //扫描层数
	float	drstartpos;												//DR起始位置(mm)
	float	drlen;													//DR扫描长度(mm)
	int		equspace;												//(需要？)比例模式(DR：0-等比例, 1-不等比例；CT：0-当前层, 1-等层距，2-变层距)
	float	ctlayerpos;												//CT断层位置(mm)
	int		ct2scanmode;											//2代及局部CT扫描方式(0-扫描方式1, 1-扫描方式2，2-扫描方式3)
	int     checksum;                                               //常用模式文件数据校验和
};

//扫描组态单个数据结构定义(线阵)
struct _LineScanConfig
{
	int		mode;													//扫描模式(0-DR, 1-CT，2-大视场CT)
	WORD	matrix;													//图像矩阵
	float	diameter;												//视场直径(mm)
	short	rotationAngle;											//旋转角度(°)
	float	drXs;													//DR起始坐标(mm)
	float	drXe;													//DR结束坐标(mm)
	float	ctX;													//CT坐标(mm)
};

//扫描组态单个数据结构定义(面阵)
struct _PanScanConfig
{
	int		mode;													//扫描模式(0-DR拍片)
	float	orientationAngle;										//扫描方位(°)
	float	layerPos;												//断层位置(mm)
	float	translationPos;											//平移位置(mm)
	float	sod;													//SOD(mm)
	float	sdd;													//SDD(mm)
	float	deflectionPos;											//偏摆角度(mm)
	int		frameCnt;												//采集帧数
};


//2017.02.19增加
//钨门位置数据结构定义
struct _WDoorPosData
{
	float   upDoorPos,												//上钨门位置   
			downDoorPos,											//下钨门位置   
			leftDoorPos,											//左钨门位置   
			rightDoorPos;											//右钨门位置   
};					

//几何参数测量结果信息数据结构定义

//运动轴定义(对立式系统)
//R-旋转轴
//X-径向轴；
//Y-平移轴；
//Z-升降轴(分层运动方向)；
union _SysAxisConfig
{
	struct{
		//*********************status1: 8 bits*****************************
		BYTE	interpolation_define		:1;						//插值运动轴定义:0-不存在;1-存在
		BYTE	sliceThickness_define		:1;						//层厚运动轴定义:0-不存在;1-存在
		BYTE	collimator_define			:1;						//准直运动轴定义:0-不存在;1-存在
		BYTE	deflection_define			:1;						//偏摆运动轴定义:0-不存在;1-存在
		BYTE								:4;						//保留

		//*********************status2: 8 bits*****************************
		BYTE	object_axisR_define			:1;						//工件R方向运动轴定义:0-不存在;1-存在
		BYTE	object_axisX_define			:1;						//工件X方向运动轴定义:0-不存在;1-存在
		BYTE	object_axisY_define			:1;						//工件Y方向运动轴定义:0-不存在;1-存在
		BYTE	object_axisZ_define			:1;						//工件Z方向运动轴定义:0-不存在;1-存在
		BYTE								:4;						//保留

		//*********************status3: 8 bits*****************************
		BYTE	source_axisX_define			:1;						//射线源X方向运动轴定义:0-不存在;1-存在
		BYTE	source_axisY_define			:1;						//射线源Y方向运动轴定义:0-不存在;1-存在
		BYTE	source_axisZ_define			:1;						//射线源Z方向运动轴定义:0-不存在;1-存在
		BYTE								:5;						//保留

		//*********************status4: 8 bits*****************************
		BYTE	detector_axisX_define		:1;						//探测器X方向运动轴定义:0-不存在;1-存在
		BYTE	detector_axisY_define		:1;						//探测器Y方向运动轴定义:0-不存在;1-存在
		BYTE	detector_axisZ_define		:1;						//探测器Z方向运动轴定义:0-不存在;1-存在
		BYTE								:5;						//保留
	}s;
	BYTE b[4];
};

//2017.10.05增加
//工件参数信息定义
struct _WorkPieceInfoData
{
	wchar_t	WorkpieceName[MAX_STR_LENGTH];							//工件名称
	wchar_t	WorkpieceModel[MAX_STR_LENGTH];							//工件型号
	wchar_t	WorkpieceNumber[MAX_STR_LENGTH];						//工件编号
	wchar_t	WorkpieceBatch[MAX_STR_LENGTH];							//工件批次
	wchar_t	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//工件壳体材料
	wchar_t	WorkpieceFillMaterial[MAX_STR_LENGTH];					//工件填充材料
	wchar_t	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//工件制造单位
	wchar_t	WorkpieceMakeDate[MAX_STR_LENGTH];						//工件制造日期
	wchar_t	WorkpieceTestPosition[MAX_STR_LENGTH];					//检测部位
};

//扫描组态整体数据结构定义
struct kVRayData 
{
	char	ID;
	char rayType[16];
	float rayEnergy;												//射线能量,单位:KV
	float rayDoseRate;											//射线剂量率, 单位:cGy/min/m
};
struct AcceleratorData
{
	char	ID;
	char rayType[16];
	float rayEnergy;												//射线能量,单位:KV
	float rayDoseRate;
	unsigned short accRiseTime;											//加速器出束上升时间(ms)
	std::vector<int> syncFreqDefine;								//同步频率定义(Hz)
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
	short	NumberOfSystemHorizontalDetector;               //射线平面方向系统探测器数(此参数为探测器总数)
	short	NumberOfCalibrateHorizontalDetector;            //射线平面方向校正用探测器数(此参数为校正用探测器数量)
	short	BeginSerialNoOfCt2Detector;                     //2代扫描开始探测器序号(从0开始)
	short	EndSerialNoOfCt2Detector;                       //2代扫描结束探测器序号(从0开始)
	short	AmplifyMultiple;								//采样放大倍数, 典型值6
	short	IntegralTime;									//采样积分时间(us), 典型值70
	short	DelayTime;										//采样延迟时间(us), 典型值10
	short	nFIFOdepth;										//数据采集FIFO通道深度, 典型值64
	short	nChnnelMask;									//数据采集FIFO通道掩码(2进制表示, 每位代表64通道)
	short	nDetectorChnnelAmount;							//探测器通道数(由上面2参数计算获得,可能大于物理探测器数)
	float	HorizontalSectorAngle;                          //射线平面方向扇角
	float	HorizontalDetectorAngle;						//水平方向单个探测器夹角(°)
	int		nBlockMapTable[MAX_BLOCK];						
	char	szAcquireClientIP[32];							//采集客户端IP地址
	unsigned short nAcquireClientPort;						//采集客户端端口地址
	float	SourceDetectorDistance;							//射线源探测器距离
															
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
	char rotAngle;			//镜像，90 = 1, 180 = 2, 270 = 3
	char mirror;			//镜像，x = 1, y = 2
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
//系统设置数据结构定义

using rayDetScanmode = std::pair<std::pair<int, int>, ScanMode>; /*ray, det, scanmode*/

struct SetupData
{
	char szDeviceModel[32];                              //设备型号
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
	std::vector<Axis> sysAxisDefine;						//系统运动轴定义

	int		interpolationModeDefine;								//插值方式定义(SIMULATION/PHYSICS)
	int		ct3InterpolationFlag;									//3代CT扫描插值数定义(0/1)
	int		drInterpolationFlag;									//DR扫描插值数定义(0/1)
	int		drScanModeDefine;										//DR扫描方式定义(P_DIR/BI_DIR)
	int		drScanAngleDefine;										//DR扫描角度数定义(ONE_ANGLE/MULTI_ANGLE)
	int		translationModeDefine;									//2代扫描平移方式定义(P_DIR/BI_DIR)
	float	minGeometryResolution;									//图像最小几何分辨率(mm, D/M)
	float	minInterpolationSpace;									//最小插值间距(mm, 用于3代CT和DR扫描)
	float	minTranslationSpace;									//最小平移间距(mm, 用于2代CT和局部扫描)
	float	minLayerSpace;									        //最小分层间距(mm, 用于DR分层扫描)
	float	largeViewCenterOffset;									//大视场扫描回转中心偏置(mm)
	float	largeFocalCenterOffset;									//大焦点情况回转中心偏移值(mm)
	float	smallFocalCenterOffset;									//小焦点情况回转中心偏移值(mm)
	wchar_t	szUnderCtrlerIP[32];									//控制客户端IP地址
	unsigned short nUnderCtrlerPort;								//控制客户端端口地址
	float	CurSOD;													//焦点到旋转中心距离(当前旋转中心径向位置)(mm)
	float	CurSDD;													//焦点到中心探测器距离(当前探测器径向位置)(mm)
};

#define	RTBUF_LEN	256						//定义接收/发送缓冲区长度
struct COMM_PACKET
{
	BYTE	tagHead[3];						//包头(0x55,0xaa,0x5a)
	BYTE	typeCode;						//类型码
	WORD	tagLen;							//包长(=参数字节数+3, 实际命令数据包长度=包长+4)
	BYTE	data[RTBUF_LEN - 6];			//命令参数
};

