#ifndef	__SETUPDATA_H
#define	__SETUPDATA_H

#include "CtrlData.h"
//系统参数设置数据结构文件

/*
上位机IP地址设置:
IP地址:		192.168.2.124
子网掩码:	255.255.255.0
默认网关:	192.168.2.1

DNS服务器:	202.202.0.33
*/
//const char szAcquireClientIP[]="192.168.2.120";						//采集客户端IP地址
const wchar_t szAcquireClientIP[]=_T("192.168.2.120");						//采集客户端IP地址
const unsigned short nAcquireClientPort	= 4000;						//采集客户端端口地址

const wchar_t szCtoSIP[]=_T("192.168.1.122");						//客户端-服务器IP地址
const wchar_t szUnerCtrlerIP[]=_T("192.168.0.124");					//控制客户端IP地址
const unsigned short nUnerCtrlerPort	= 8000;						//控制客户端端口地址

//const char szAcquireInterfaceIP[]="192.168.2.120";					//采集卡IP地址
#define	nComPortMaxNum	8											//定义串行通信端口最大数量
const char szCom[nComPortMaxNum][16]={"COM1","COM2","COM3","COM4","COM5","COM6","COM7","COM8"};

#define	MAX_PARA_ITEM	    20										//最大参数项
#define	MAX_STR_LENGTH	    100										//最大字符串长度
#define MAX_PASSWORD_LENGTH 32                                      //最大密码串长度
#define	MAX_BLOCK		    160										//以8为单位的最大探测模块数(必须与在AcquireInterface.h中定义一致)
#define	MAX_COMMONMODE_ITEM	20										//最大常用模式项数
#define	MAX_SCANCONFIG_ITEM	32										//最大扫描组态项数

//扫描模式字符串名
const wchar_t szScanModeText[20][32]={
	_T("Ⅰ代扫描"),_T("Ⅱ代CT扫描"),_T("Ⅲ代CT扫描"),_T("DR扫描"),
	_T("局部扫描"),_T("螺旋扫描"),_T("锥束扫描"),_T("锥束螺旋扫描"),
	_T("背景校正"),_T("空气校正"),_T("标定零点扫描"),_T("标定回转中心扫描"),
	_T("大视场扫描"),_T("组态扫描"),_T("坏像素校正"),_T("锥束点位扫描"),
	_T("锥束交错扫描"),_T("单向交错扫描"),_T("锥束大视场扫描"),_T("锥束螺旋点位扫描")};

const wchar_t szAxisName[][14]={_T("分度"),_T("工件平移"),_T("插值"),_T("分层1"),_T("分层2"),_T("工件径向"),_T("层厚"),_T("准直器"),_T("工件升降"),_T("射线径向"),_T("射线平移"),_T("探测径向"),_T("探测平移"),_T("偏摆")};

//const   wchar_t    szSingleAxisName[][16]={_T("旋转R"),_T("径向X"),_T("平移Y"),_T("升降Z"),_T("旋转R"),_T("径向X"),
//	_T("平移Y"),_T("升降Z"),_T("旋转R"),_T("径向X"),_T("平移Y"),_T("升降Z")};
const wchar_t szSingleAxisName[][14]={_T("分度"),_T("工件平移"),_T("插值"),_T("射线分层"),_T("探测分层"),_T("工件径向"),_T("层厚"),_T("准直器"),_T("工件升降"),_T("射线径向"),_T("射线平移"),_T("探测径向"),_T("探测平移"),_T("偏摆")};

//射线源符号名定义
enum{
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
enum{
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
enum{
	CTRLER_SIMOTION	= 0,											//NEWPORT控制器
	CTRLER_UMAC,													//UMAC控制器
	CTRLER_PI,														//PI控制器
	CTRLER_PI_UMAC,													//
	UNKOWN_CTRLER													//未知控制器
};

//图像/视频/图片监视模式定义
enum{
	PICTURE			=	0,											//图片
	VIDEO,															//视频
	IMAGE															//图像
};

//定义线阵数据处理方式
enum{
	DP_DLL		= 0,												//动态库
	DP_SERVER														//服务器
};

//定义面阵数据处理方式
enum{
	DP_DETDLL		= 0,											//探测器自带动态库
	//DP_SERVER														//校正函数调用服务器
};

//定义控制端口通信方式
enum{
	SERIAL_PORT	= 0,												//串行通信端口
	TCP_IP															//TCP/IP网络
};

//定义扫描方式名义值
enum{
	sDR_SCAN	=	0,												//DR扫描
	sCT_SCAN,														//CT扫描
	sLV_SCAN                                                        //大视场扫描
};

//定义文件命令方式名义值
enum{
	mDATE	=	0,													//默认命名方式："年月日+4位序号"
	mDATE_NAME_NO                                                   //"年月日_名称_编号_4位序号"，如九院
};

//扫描常用模式数据结构定义
typedef	struct _CommonModeData{
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
}CommonModeData;

//扫描组态单个数据结构定义(线阵)
typedef	struct _LineScanConfig{
	int		mode;													//扫描模式(0-DR, 1-CT，2-大视场CT)
	WORD	matrix;													//图像矩阵
	float	diameter;												//视场直径(mm)
	short	rotationAngle;											//旋转角度(°)
	float	drXs;													//DR起始坐标(mm)
	float	drXe;													//DR结束坐标(mm)
	float	ctX;													//CT坐标(mm)
}LineScanConfig;

//扫描组态单个数据结构定义(面阵)
typedef	struct _PanScanConfig{
	int		mode;													//扫描模式(0-DR拍片)
	float	orientationAngle;										//扫描方位(°)
	float	layerPos;												//断层位置(mm)
	float	translationPos;											//平移位置(mm)
	float	sod;													//SOD(mm)
	float	sdd;													//SDD(mm)
	float	deflectionPos;											//偏摆角度(mm)
	int		frameCnt;												//采集帧数
}PanScanConfig;


//2017.02.19增加
//钨门位置数据结构定义
typedef struct _WDoorPosData{
	float   upDoorPos,												//上钨门位置   
			downDoorPos,											//下钨门位置   
			leftDoorPos,											//左钨门位置   
			rightDoorPos;											//右钨门位置   
}WDoorPosData;					

//几何参数测量结果信息数据结构定义
typedef struct _GeoAdjInfoData{
	FWorkZero geoWorkZeroOld;									//前相关零点参数
	FWorkZero geoWorkZeroNew;									//新相关零点参数

	float   rayPlatAngleX;											//射线平台倾角X
	float   rayPlatAngleY;											//射线平台倾角Y
	float   detPlatAngleX;											//探测平台倾角X
	float   detPlatAngleY;											//探测平台倾角Y
	float   objPlatAngleX;											//工件平台倾角X
	float   objPlatAngleY;											//工件平台倾角Y

	float   fStoDAngle;												//源-探夹角
	float   fStoOAngle;												//源-物夹角
	float	fDefMoveOldPos;											//工件偏摆缸运动原位值
	float   fDefMoveSetPos;											//工件偏摆缸运动设定值

	float   fWDoorLeftPos;											//左钨门调整后位置
	float   fWDoorRightPos;											//右钨门调整后位置
	WDoorPosData wDoorPosForLineDet;								//线阵使用时钨门位置
	WDoorPosData wDoorPosForPanDet;									//面阵使用时钨门位置

	float	stodLaserMeasRefDistance;								//射线源测探测器激光测距参考距离(mm)
	float	stodLaserMeasRealDistance1;								//射线源测探测器激光测距实测距离(mm)
	float	stodLaserMeasRealDistance2;								//射线源测探测器激光测距实测距离(mm)
	float	stodLaserMeasLeftPos;									//源-探测距左移至零位设定位置(mm)
	float	stodLaserMeasRightPos;									//源-探测距右移全行程设定位置(mm)

	float	stooLaser12MeasRefDistance;								//源-物激光器1和2测距平移方向参考距离(mm)
	float	stooLaser13MeasRefDistance;								//源-物激光器1和3测距平移方向参考距离(mm)
	float	stooLaserDeflectionRadius;								//源-物测距偏摆运动旋转半径(mm)
	float	stooLaserMeasRefDistance;								//射线源测工件小车激光测距参考距离(mm)
	float	stooLaserMeasRealDistance1;								//射线源测工件小车激光测距实测距离(mm)
	float	stooLaserMeasRealDistance2;								//射线源测工件小车激光测距实测距离(mm)
	float	stooLaserMeasRealDistance3;								//射线源测工件小车激光测距实测距离(mm)

	float	hStoDLaserOffsetDistance;								//源-探激光测距水平方向偏移距离(mm,激光偏线阵右侧为正,左侧为负)
	float	vStoDLaserOffsetDistance;								//源-探激光测距竖直方向偏移距离(mm,激光偏上方为正,下方为负)

	float	detectorDistanceLineToPan;								//定义面阵与线阵中心探测器之间距离(mm)

	Coordination toTransPosCord;									//运输位坐标定义
}GeoAdjInfoData;

//运动轴定义(对立式系统)
//R-旋转轴
//X-径向轴；
//Y-平移轴；
//Z-升降轴(分层运动方向)；
typedef union _SysAxisConfig{
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
}SysAxisConfig;

//2017.10.05增加
//工件参数信息定义
typedef struct _WorkPieceInfoData{
	wchar_t	WorkpieceName[MAX_STR_LENGTH];							//工件名称
	wchar_t	WorkpieceModel[MAX_STR_LENGTH];							//工件型号
	wchar_t	WorkpieceNumber[MAX_STR_LENGTH];						//工件编号
	wchar_t	WorkpieceBatch[MAX_STR_LENGTH];							//工件批次
	wchar_t	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//工件壳体材料
	wchar_t	WorkpieceFillMaterial[MAX_STR_LENGTH];					//工件填充材料
	wchar_t	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//工件制造单位
	wchar_t	WorkpieceMakeDate[MAX_STR_LENGTH];						//工件制造日期
	wchar_t	WorkpieceTestPosition[MAX_STR_LENGTH];					//检测部位
}WorkPieceInfoData;

//扫描组态整体数据结构定义
typedef struct _ScanConfigData{
	int		nScanConfigItem;										//组态扫描数据项数
	LineScanConfig	lineScanConfig[MAX_SCANCONFIG_ITEM];			//组态扫描数据(线阵)
	PanScanConfig	panScanConfig[MAX_SCANCONFIG_ITEM];				//组态扫描数据(面阵)
	WorkPieceInfoData	workPiece;									//工件参数信息
    wchar_t szFileDate[10];                                         //文件日期
	WORD	nFileSerial;											//文件序号(更改定义并保存在config.dat中，防止删除CTScan.dat文件后旧数据被替换问题)
	int     checksum;                                               //校验和(不包括校验数据位)	
}ScanConfigData;

//系统设置数据结构定义
typedef struct _SetupData{
	GeometryParameter	geometryPara;								//系统几何结构参数

	int		rayDefine;												//射线源定义(TUBE_SPELLMAN/TUBE_COMET/ACCELERATOR/ACCELERATOR_NV/UNKNOW_TUBE)
	float	rayEnergy;												//射线能量,单位:KV
	float	rayDoseRate;											//射线剂量率, 单位:cGy/min/m
	int		nMonitorMode;											//图像/视频/图片监视模式定义(0-图片PICTURE, 1-视频VIDEO, 2-图像IMAGE)

	WORD	AmplifyMultiple;										//采样放大倍数, 典型值6
	WORD	IntegralTime;											//采样积分时间(us), 典型值70
	WORD	IntegralTime2;											//第二采样积分时间(us), 典型值70(用于双射线源情况)
	WORD	DelayTime;												//采样延迟时间(us), 典型值10
	WORD	DelayTime2;												//第二采样延迟时间(us), 典型值10(用于双射线源情况)
	WORD	nFIFOdepth;												//数据采集FIFO通道深度, 典型值64
	WORD	nChnnelMask;											//数据采集FIFO通道掩码(2进制表示, 每位代表64通道)
	WORD	nDetectorChnnelAmount;									//探测器通道数(由上面2参数计算获得,可能大于物理探测器数)
	int		nBlockMapTable[MAX_BLOCK];								//探测模块映射表,从0开始,以8通道为单位,最大1280通道,-1表示未用

	int		scanModeDefine[MAX_PARA_ITEM];							//扫描模式定义
	int		scanModeItems;											//扫描模式定义个数
	int		scanModeCurSel;											//扫描模式当前选择索引值(-1表示未选择)

	WORD	scanMatrixDefine[MAX_PARA_ITEM];						//扫描矩阵定义(M)
	int		scanMatrixItems;										//扫描矩阵定义个数
	int		scanMatrixCurSel;										//扫描矩阵当前选择索引值(-1表示未选择)
	int     scanMatrix;

	float	scanViewDefine[MAX_PARA_ITEM];							//扫描视场定义(mm, D)
	int		scanViewItems;											//扫描视场定义个数
	int		scanViewCurSel;											//扫描视场当前选择索引值(-1表示未选择)

	float	layerThickDefine[MAX_PARA_ITEM];						//断层厚度定义(mm)
	int		layerThickItems;										//断层厚度定义个数
	int		layerThickCurSel;										//断层厚度当前选择索引值(-1表示未选择)

	WORD	sampleTimeDefine[MAX_PARA_ITEM];						//采样时间定义(ms)
	int		sampleTimeItems;										//采样时间定义个数
	int		sampleTimeCurSel;										//采样时间当前选择索引值(-1表示未选择)
	float   sampleTime;												

	int		collimateDefine[MAX_PARA_ITEM];							//准直孔代号定义
	int		collimateItems;											//准直孔定义个数
	int		collimateCurSel;										//准直孔当前选择索引值(-1表示未选择)
	
	WORD	syncFreqDefine[MAX_PARA_ITEM];							//同步频率定义(Hz)
	int		syncFreqItems;											//同步频率定义个数
	int		syncFreqCurSel;											//同步频率当前选择索引值(-1表示未选择)

	SysAxisConfig	sysAxisDefine;									//系统运动轴定义

	float	kVScaleDefine;											//X射线管电压变换因子定义(kV/bit)
	float	mAScaleDefine;											//X射线管电流变换因子定义(mA/bit)

	int		interpolationModeDefine;								//插值方式定义(SIMULATION/PHYSICS)
	int		ct3InterpolationFlag;									//3代CT扫描插值数定义(0/1)
	int		drInterpolationFlag;									//DR扫描插值数定义(0/1)
	int		drScanModeDefine;										//DR扫描方式定义(P_DIR/BI_DIR)
	int		drScanAngleDefine;										//DR扫描角度数定义(ONE_ANGLE/MULTI_ANGLE)
	int		translationModeDefine;									//2代扫描平移方式定义(P_DIR/BI_DIR)
	int		transferModeDefine;										//2代扫描数据传输方式定义(WHOLE/BATCH)
	int		tabelInOut;												//转台进出控制选择值(P_DIR/N_DIR/DISABLE)
	int		workpieceAmount;										//同时检测的工件数量(1/2)

	short	orientIncDefine;										//分度方位角增量定义(度,0-360)
	float	layerPositionDefine;									//断层位置定义(mm)
	float	layerSpaceDefine;										//层间距定义(mm)
	float	drScanLengthDefine;										//DR扫描长度(mm)
	float	minGeometryResolution;									//图像最小几何分辨率(mm, D/M)
	float	minInterpolationSpace;									//最小插值间距(mm, 用于3代CT和DR扫描)
	float	minTranslationSpace;									//最小平移间距(mm, 用于2代CT和局部扫描)
	float	minLayerSpace;									        //最小分层间距(mm, 用于DR分层扫描)
	float	largeViewCenterOffset;									//大视场扫描回转中心偏置(mm)
	float	largeFocalCenterOffset;									//大焦点情况回转中心偏移值(mm)
	float	smallFocalCenterOffset;									//小焦点情况回转中心偏移值(mm)

	//char	m_testUnit[MAX_STR_LENGTH];								//送检单位
	//char	m_testTaskNumber[MAX_STR_LENGTH];						//任务编号
	//char	m_testTaskName[MAX_STR_LENGTH];							//任务名称
	//char	m_testStaff[MAX_STR_LENGTH];							//检测人员

	//char	WorkpieceName[MAX_STR_LENGTH];							//工件名称
	//char	WorkpieceModel[MAX_STR_LENGTH];							//工件型号
	//char	WorkpieceNumber[MAX_STR_LENGTH];						//工件编号
	//char	WorkpieceBatch[MAX_STR_LENGTH];							//工件批次
	//char	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//工件壳体材料
	//char	WorkpieceFillMaterial[MAX_STR_LENGTH];					//工件填充材料
	//char	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//工件制造单位
	//char	WorkpieceMakeDate[MAX_STR_LENGTH];						//工件制造日期
	//char	WorkpieceTestPosition[MAX_STR_LENGTH];					//检测部位

	//char	WorkpieceName2[MAX_STR_LENGTH];							//工件名称
	//char	WorkpieceModel2[MAX_STR_LENGTH];						//工件型号
	//char	WorkpieceNumber2[MAX_STR_LENGTH];						//工件编号
	//char	WorkpieceBatch2[MAX_STR_LENGTH];						//工件批次
	//char	WorkpieceShellMaterial2[MAX_STR_LENGTH]; 				//工件壳体材料
	//char	WorkpieceFillMaterial2[MAX_STR_LENGTH];					//工件填充材料
	//char	WorkpieceManufacturer2[MAX_STR_LENGTH]; 				//工件制造单位
	//char	WorkpieceMakeDate2[MAX_STR_LENGTH];						//工件制造日期
	//char	WorkpieceTestPosition2[MAX_STR_LENGTH];					//检测部位
	wchar_t	m_testUnit[MAX_STR_LENGTH];								//送检单位
	wchar_t	m_testTaskNumber[MAX_STR_LENGTH];						//任务编号
	wchar_t	m_testTaskName[MAX_STR_LENGTH];							//任务名称
	wchar_t	m_testStaff[MAX_STR_LENGTH];							//检测人员

	WorkPieceInfoData workPiece;									//工件参数信息
	WorkPieceInfoData workPiece2;									//工件2参数信息

	//wchar_t	WorkpieceName[MAX_STR_LENGTH];							//工件名称
	//wchar_t	WorkpieceModel[MAX_STR_LENGTH];							//工件型号
	//wchar_t	WorkpieceNumber[MAX_STR_LENGTH];						//工件编号
	//wchar_t	WorkpieceBatch[MAX_STR_LENGTH];							//工件批次
	//wchar_t	WorkpieceShellMaterial[MAX_STR_LENGTH]; 				//工件壳体材料
	//wchar_t	WorkpieceFillMaterial[MAX_STR_LENGTH];					//工件填充材料
	//wchar_t	WorkpieceManufacturer[MAX_STR_LENGTH]; 					//工件制造单位
	//wchar_t	WorkpieceMakeDate[MAX_STR_LENGTH];						//工件制造日期
	//wchar_t	WorkpieceTestPosition[MAX_STR_LENGTH];					//检测部位

	//wchar_t	WorkpieceName2[MAX_STR_LENGTH];							//工件名称
	//wchar_t	WorkpieceModel2[MAX_STR_LENGTH];						//工件型号
	//wchar_t	WorkpieceNumber2[MAX_STR_LENGTH];						//工件编号
	//wchar_t	WorkpieceBatch2[MAX_STR_LENGTH];						//工件批次
	//wchar_t	WorkpieceShellMaterial2[MAX_STR_LENGTH]; 				//工件壳体材料
	//wchar_t	WorkpieceFillMaterial2[MAX_STR_LENGTH];					//工件填充材料
	//wchar_t	WorkpieceManufacturer2[MAX_STR_LENGTH]; 				//工件制造单位
	//wchar_t	WorkpieceMakeDate2[MAX_STR_LENGTH];						//工件制造日期
	//wchar_t	WorkpieceTestPosition2[MAX_STR_LENGTH];					//检测部位

	int		nValidCom[nComPortMaxNum];								//有效串行端口, [.]为TRUE时该串口有效(COM1-COM8)
	int		commCtrlPortNum;										//控制用通信端口号(0-7,-1表示无)
	int		commRayPortNum;											//射线源用通信端口号(0-7,-1表示无)
	int		commA23PortNum;											//A23转接板用通信端口号(0-7,-1表示无)
	int		commTPPortNum;											//调平系统用通信端口号(0-7,-1表示无)

	//WORD	nFileSerial;											//文件序号(更改定义并保存在config.dat中，防止删除CTScan.dat文件后旧数据被替换问题)
    //wchar_t szFileDate[10];                                         //文件日期

    //char    szFileDate[10];                                         //文件日期
	//char	szOrgFilePath[MAX_PATH];								//原始数据文件路径
	//char	szCtFilePath[MAX_PATH];									//校正后CT数据文件路径
	//char	szDrFilePath[MAX_PATH];									//校正后DR数据文件路径
	//char	szLogFilePath[MAX_PATH];								//日志文件路径
	//char	szCtrlDebugPassword[MAX_PASSWORD_LENGTH];				//控制系统调试密码字符串
	//char	szDataDebugPassword[MAX_PASSWORD_LENGTH];				//数据系统调试密码字符串
	//char	szDataViewPassword[MAX_PASSWORD_LENGTH];				//数据察看密码字符串

	wchar_t	szCurrentFullFileName[MAX_PATH];						//面阵用当前全文件名(年月日+4位序号/年月日_名称_编号_4位序号)
	WORD    nInterFileSerial;										//内部文件序号
	wchar_t	szOrgFilePath[MAX_PATH];								//原始数据文件路径
	wchar_t	szCtFilePath[MAX_PATH];									//校正后CT数据文件路径
	wchar_t	szDrFilePath[MAX_PATH];									//校正后DR数据文件路径
	wchar_t	szLogFilePath[MAX_PATH];								//日志文件路径
	wchar_t	szDarkFullPathFileName[MAX_PATH];						//暗场全路径文件名
	wchar_t	szGainFullPathFileName[MAX_PATH];						//亮场全路径文件名
	wchar_t	szDefMapFullPathFileName[MAX_PATH];						//坏像素图全路径文件名
	wchar_t	szCtrlDebugPassword[MAX_PASSWORD_LENGTH];				//控制系统调试密码字符串
	wchar_t	szDataDebugPassword[MAX_PASSWORD_LENGTH];				//数据系统调试密码字符串
	wchar_t	szDataViewPassword[MAX_PASSWORD_LENGTH];				//数据察看密码字符串

	int		bCtrlPasswordPassed;									//控制系统调试口令通过标志
	int		bDataPasswordPassed;									//数据系统调试口令通过标志
	int		bDataViewPasswordPassed;								//数据察看口令通过标志

	BYTE	bComb;													//合并采样数据标志(TRUE:合并, FALSE:不合并)
	BYTE	bDispose;												//数据处理方式(DP_DLL:动态库, DP_SERVER:服务器)
	BYTE	bRadialPosCtrl;											//径向位置控制标志(TRUE:允许, FALSE:禁止)

	int		nPanelMode;												//平板探测器采集模式(0-2)
	float	fPanelFrameRate;										//平板探测器采集帧速率(1.0,2.0,3.0,3.75,5.0,7.5,15,30)	

	BYTE	bMulitiTurntableConfig;									//多转台结构标志(TRUE:多个转台, FALSE:单个转台)
	BYTE	bMulitiTurntableScan;									//多转台扫描标志(TRUE:多小转台, FALSE:单个大转台)
	float	turntableCenterDistance;								//多小转台CT设备相邻小转台中心距
	WORD	nMiddleTurntableSerialNo1;								//多小转台CT设备扇面中心小转台序号1(左侧, 从0开始)
	WORD	nMiddleTurntableSerialNo2;								//多小转台CT设备扇面中心小转台序号2(右侧, 从0开始)

	WORD	turntableConfigDefine[MAX_PARA_ITEM][2];				//多小转台CT设备CT/DR扫描时小转台组合方式(形如2,4等)
	int		turntableConfigItems;									//多小转台CT设备CT/DR扫描时小转台组合方式定义个数
	int		turntableConfigCurSel;									//多小转台CT设备CT/DR扫描时小转台组合方式当前选择索引值(-1表示未选择)

	//2013.08.27增加
	int		scanStartModeDefine;									//扫描启动方式定义(IMMEDIACY/BTN_START)
	int		scanEndStopBeamModeDefine;								//扫描结束停束方式定义(AUTO/BTN_END)

	//char	szAcquireClientIP[32];									//采集客户端IP地址
	wchar_t	szAcquireClientIP[32];									//采集客户端IP地址
	unsigned short nAcquireClientPort;								//采集客户端端口地址
	wchar_t	szUnderCtrlerIP[32];									//控制客户端IP地址
	unsigned short nUnderCtrlerPort;								//控制客户端端口地址

	wchar_t	szClientToServerIP[32];									//客户端-服务器IP地址
	unsigned short nClientToServerPort;								//客户端-服务器端口地址
	int		ctrlCommModeDefine;										//控制通信模式定义(SERIAL_PORT/TCP_IP)

	WORD	accRiseTime;											//加速器出束上升时间(ms)
	float	sliceAxisAcc;											//分层轴加速度(mm/s2)

	BOOL	bEnableAmpAdjust;										//几何放大倍数(径向距离)调整使能控制标志(0-径向距离不可调整;1-可调整)
	int		nDarkGainFrameCnt;										//暗场/增益校正帧数定义
	//2017.04.04增加
	int		nPanDetAcqFrameCnt;										//面阵采集帧数定义
	int		nPanDetPulseCnt;										//面阵采集脉冲数定义

	float   fDefectMarkPecent;										//坏像素标记所使用的百分比(PE非晶硅探测器用)
// 	int		nScanConfigItem;										//组态扫描数据项数
// 	ScanConfig	scanConfig[MAX_SCANCONFIG_ITEM];					//组态扫描数据
 	float   configScanDiameter;                                     //组态扫描视场直径
	ScanConfigData scanConfigData;									//组态扫描整体数据结构定义
	BOOL bLaserMeasuringMoveCtrl;									//激光干涉仪精度测量控制标志

	BYTE    clientServerMode;										//主程序工作方式（CLIENTMODE-作为客户端;SERVERMODE-作为服务器;SERVERDEBUGMODE-作为服务器调试模式）
	AxisSetSpeedData axisSpeed;										//运动轴设定的最低和最高运动速度
	//2017.02.23增加
	GeoAdjInfoData geoAdjInfoData;									//几何参数测量结果信息

	float	CurSOD;													//焦点到旋转中心距离(当前旋转中心径向位置)(mm)    
	float	CurSDD;													//焦点到中心探测器距离(当前探测器径向位置)(mm)    

	BOOL	bLineDetExist;											//系统配置有线阵探测器
	BOOL	bPanDetExist;											//系统配置有面阵探测器

	//2017.10.4增加
	BYTE	nFileNamingMode;										//文件命名方式(DATE-年月日+4位序号,DATE_NAME_NO-年月日_名称_编号_4位序号  )
	BOOL	bRemoteSyncCtrl;										//同步文件到远程计算机标志(0-不同步[默认],1-需要同步文件到远程计算机)
	BOOL	bMulitiTurntableCtrl;									//多转台需独立控制标志(0-不控制[默认],1-允许小转台独立控制界面)
	BYTE	CheckSum;												//设置数据结构检查和(整个结构的字节累加和=0, 包括检查和字节)
}SetupData;

#endif

