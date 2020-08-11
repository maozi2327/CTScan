#pragma once

#include "IctHeader.h"
//#define USE_IN_CONTROL                                    //在控制程序中使用时定义
//通信协议: 重庆真测科技股份有限公司"CD系列工业CT计算机通信协议"V4.0版
//该版本修改了数据结构和命令及状态定义, 与V4.0以下版本不兼容
//控制系统数据结构定义
//2013.9.22:
//1. 几何结构参数中增加Ⅱ代/局部扫描扇角(分度角), Ⅱ代扫描探测器数*相邻探测器夹角可能不等于该值
//2. 适用于CTScan V4.0以上版本

const float PI = (float)3.1415926;									//常数PI

#ifndef	BYTE
typedef unsigned char   BYTE;
#endif
#ifndef	WORD
typedef unsigned short  WORD;
#endif
#ifndef	DWORD
typedef unsigned long   DWORD;
#endif

#define	TUNE_PROJECTIONS	512							            //校正扫描投影数
#define CAL_LAYERZERO_SPACE (float)0.5                              //分层零点标定扫描间距(mm)

#define CAL_LAYERZERO_MOVESTEP (WORD)(200.0) //分层零点标定投影数(200.0mm/0.25mm)
#define CAL_RADIALZERO_MOVESTEP (WORD)(100.0) //径向零点标定投影数(100.0mm/0.5mm)
#define CAL_TRANSLATION_MOVESTEP (WORD)(100.0) //平移零点标定投影数(100.0mm/0.5mm)

#define CAL_LAYERZERO_PROJECTIONS (WORD)(CAL_LAYERZERO_MOVESTEP/CAL_LAYERZERO_SPACE) //分层零点标定投影数(200.0mm/0.25mm)
#define CAL_RADIALZERO_PROJECTIONS (WORD)(CAL_RADIALZERO_MOVESTEP/CAL_LAYERZERO_SPACE) //径向零点标定投影数(100.0mm/0.5mm)
#define CAL_TRANSLATION_PROJECTIONS (WORD)(CAL_TRANSLATION_MOVESTEP/CAL_LAYERZERO_SPACE) //平移零点标定投影数(60.0mm/0.5mm)

//探测器结构形式名定义
#ifndef	_DETECTOR_STRUCT_NAME
#define	_DETECTOR_STRUCT_NAME
enum{
	ARC_DETECTOR	=	0,									//弧形探测器
	LINE_DETECTOR,											//直线探测器
	PANEL_DETECTOR											//平板探测器
};
#endif

//定义子系统代号(0-控制；1-加速器；2-线阵；3-面阵；4-调平系统；5-触发板)
enum{
	SS_UNDERCTRLER	= 0,											//控制子系统（控制系统）
	SS_ACCELERATOR,													//加速器子系统
	SS_LINEDETECTOR,												//线阵子系统
	SS_PANELDETECTOR,												//面阵子系统
	SS_BANLANCESYSTEM,												//调平子系统
	SS_TRIGGERBOARD,												//触发板子系统

	SS_SERVER_CLIENT												//客户端-服务器间内部通信
};

//定义客户端-服务器间内部通信用状态                               
enum{
	STS_INNER_NULL								= -1,			//无效状态
	STS_INNER_LINKSTS							= 0x00			//连接状态									0x00
};

//子系统连接状态结构定义
struct	_SubSysLinkSts{
	BYTE		*pRay_linked;											//射线源连接状态
	BYTE		*pLineDet_linked;										//线阵连接状态
	BYTE		*pPanDet_linked;										//面阵源连接状态
	BYTE		*pUnderCtrler_linked;									//底层控制器源连接状态
	BYTE		*pBanlance_linked;									//调平系统连接状态
};


//2代扫描模式名义值定义
//0-360度,	1-180度,	2-180度间隔
enum{
	_CT2_360	=	0,
	_CT2_180,
	_CT2_180SPACE
};

#define	nAcceleratSpace	25                                  //DR加减速距离(mm)

#pragma pack(1)                                             //设定连接程序按字节对齐, 保证结构正确对齐
//32bits系统配置字结构定义
struct SysConfig
{
	//*********************b[0]*****************************	
	BYTE	SliceCameraExist				:1;			//断层摄像头定义
	BYTE									:1;			//未用
	BYTE	LaserExist						:1;			//激光器定义
	BYTE									:3;			//未用
	BYTE	MarkerExist						:1;			//标记单元定义
	BYTE	MarkerWork						:1;			//标记单元工作定义

	//*********************b[1]*****************************	
	BYTE									:8;				//保留

	//*********************b[2]*****************************	
	BYTE									:8;				//未用
														
	//*********************b[3]*****************************	
	BYTE									:8;				//保留
};


//系统几何结构参数定义
struct GeometryParameter{
	char	szDeviceModel[32];                              //设备型号
	WORD	CtrlerType;										//控制器类型定义( 0-CTRLER_SIMOTION/ 1-CTRLER_UMAC/2-UNKOWN_CTRLER)
	WORD	PanDetectorType;								//当前使用的面阵探测器类型(PANEL_PECMOS-[默认],PANEL_PEFPD,PANEL_GNCCD,UNKOWN_PANEL)
	WORD	DetectorInUse;									//当前使用的探测器结构(0-弧形, 1-直线, 2-平板)
	//3代扫描扇角=(NumberOfSystemHorizontalDetector - 1)*HorizontalDetectorAngle
	//此扇角为两侧探测器中心线之间的夹角
	WORD	NumberOfSystemHorizontalDetector;               //射线平面方向系统探测器数(此参数为探测器总数)
	WORD	NumberofSystemVerticalDetector;                 //射线平面垂直方向系统探测器数(此参数为探测器总数)
	//2017.04.17增加
	WORD	NumberOfCalibrateHorizontalDetector;            //射线平面方向校正用探测器数(此参数为校正用探测器数量)
	////////////////////////////////
	//面阵参数
	WORD	NumberOfHorizontalPanDetector;					//射线平面方向面阵探测器数(平板探测器专用, 此参数为探测器总数)
	WORD	NumberofVerticalPanDetector;					//射线平面垂直方向面阵探测器数(平板探测器专用, 此参数为探测器总数)
	float   PanDetectorUnitSize;							//面阵探测器单元宽度(mm)
	//2017.05.05增加
	//float	SDDforPanDetetor;								//定义面阵探测器时源-探距(mm)
	////////////////////////////////
	WORD	SerialNo1OfMiddleHorizontalDetector;            //射线平面方向中心探测器序号1(弧形/直线探测器, 从0开始计算)
	WORD	SerialNo2OfMiddleHorizontalDetector;            //射线平面方向中心探测器序号2(弧形/直线探测器, 从0开始计算)
	//2代扫描扇角=EndSerialNoOfCt2Detector - BeginSerialNoOfCt2Detector + 1
	WORD	BeginSerialNoOfCt2Detector;                     //2代扫描开始探测器序号(从0开始)
	WORD	EndSerialNoOfCt2Detector;                       //2代扫描结束探测器序号(从0开始)

	float	SpaceOfHorizontalDetector;                      //射线平面方向探测器间距(mm, 平板探测器专用)
	float	SpaceOfVerticalDetector;                        //射线平面垂直方向探测器间距(mm, 平板探测器专用)
	float	HorizontalSectorAngle;                          //射线平面方向扇角(°,与系统探测器数相关, 定义为两侧探测器中心线之间夹角)
	float	VerticalSectorAngle;							//射线平面垂直方向扇角(°,与系统探测器数相关, 定义为两侧探测器中心线之间夹角)
	float	HorizontalDetectorAngle;						//水平方向单个探测器夹角(°)
	float	VerticalDetectorAngle;							//垂直方向单个探测器夹角(°)
	float	Ct2GraduationAngle;								//2代/局部扫描分度角(°, 可能不等于Ⅱ代扫描扇角)

	float	RadialPosition;                                 //焦点到旋转中心距离(当前径向位置)(mm)    
	float	SourceDetectorDistance;                         //焦点到探测器前端面距离(mm)
	float	SourceDetectorDistance1;						//焦点到探测器插值钢带距离(mm)

	//float	TranslationMaxCoordinate,                       //平移最大坐标(mm)
	//		TranslationMinCoordinate;                       //平移最小坐标(mm)
	//float	SliceMaxCoordinate,                             //分层最大坐标(mm)
	//		SliceMinCoordinate;                             //分层最小坐标(mm)
	//float	RadialMaxCoordinate,                            //径向最大坐标(mm, 小转台)
	//		RadialMinCoordinate;                            //径向最小坐标(mm, 大转台)
	float	CurSOD;											//焦点到旋转中心距离(当前旋转中心径向位置)(mm)    
	float	CurSDD;											//焦点到中心探测器距离(当前探测器径向位置)(mm)    

	float	SliceMaxCoordinate,                             //分层最大坐标(mm)
			SliceMinCoordinate;                             //分层最小坐标(mm)

	float	SourceXMaxCoordinate,							//射线源径向最大坐标(mm)
			SourceXMinCoordinate;							//射线源径向最小坐标(mm)
	float	DetectorXMaxCoordinate,							//探测器径向最大坐标(mm)
			DetectorXMinCoordinate;							//探测器径向最小坐标(mm)
	float	ObjectXMaxCoordinate,							//工件径向最大坐标(mm)
			ObjectXMinCoordinate;							//工件径向最小坐标(mm)

	float	SourceYMaxCoordinate,                           //射线源平移最大坐标(mm)
			SourceYMinCoordinate;                           //射线源平移最小坐标(mm)
	float	DetectorYMaxCoordinate,                         //探测器平移最大坐标(mm)
			DetectorYMinCoordinate;                         //探测器平移最小坐标(mm)
	float	ObjectYMaxCoordinate,                           //工件平移最大坐标(mm)
			ObjectYMinCoordinate;                           //工件平移最小坐标(mm)

	float	MaxViewDiameter;								//最大视场直径(mm)
	SysConfig	Config;										//系统配置字
};
enum class RayType
{
	Accelerator = 0,
	Tube
};

//坐标轴名定义(共17个轴)
//X-径向；Y-平移；Z-升降
//
//enum class AxisDefinition
//{					
//	AxGraduation      = 0,									//分度                     0
//	AxObjTranslation,										//工件平移                 1
//	AxInterpolation,										//插值                     2
//	AxLayer1,												//射线源分层               3
//	AxLayer2,												//探测器分层               4
//	AxObjRadial,											//工件径向                 5
//	AxSliceThick,											//断层厚度(后准直孔高度)   6
//	AxCollimator,											//准直孔宽度               7
//	AxObjVertical,											//工件Z方向运动轴			8
//	AxRayRadial,											//射线源X方向运动轴			9
//	AxRayTranslation,										//射线源Y方向运动轴			10
//	AxDetRadial,											//探测器X方向运动轴			11
//	AxDetTranslation,										//探测器Y方向运动轴			12
//	AxDeflection,											//偏摆运动					13
//	_MaxiumAxis                                             //                          14
//};					
//const int MaxiumAxis = static_cast<int>(AxisDefinition::_MaxiumAxis);                         //最大轴数目
//
////运动轴设定的最低和最高运动速度
//struct AxisSetSpeedData
//{
//	float	min[MaxiumAxis];								//最低速度(依次对应上面各运动轴)
//	float	max[MaxiumAxis];								//最高速度(依次对应上面各运动轴)
//};

//运动轴状态字结构
struct AxisStatus{
	float	Temperature;									//温度
	float	Torque;											//扭矩
	DWORD	ErrCode;										//轴错误代码
};



#ifndef USE_IN_CONTROL
//运动方向名义值定义
//在控制系统中使用本文件时因在PCL839.H中已定义, 需要屏蔽该定义
enum{
	P_DIR			= 0,                                    //正方向
	N_DIR                                                   //负方向
};
#endif

//扫描运动方式名义值定义
enum{
//	P_DIR			= 0,                                    //正方向扫描
	BI_DIR			= 1                                     //双向扫描
};
//扫描启动方式名义值定义
enum{
	IMMEDIACY		= 0,									//立即启动扫描
	BTN_START												//由射线源出束按钮启动扫描
};
//DR扫描角度名义值定义
enum{
	ONE_ANGLE		= 0,									//单角度扫描
	MULTI_ANGLE												//多角度扫描
};
//插值方式名义值定义
enum{
	SIMULATION		= 0,									//模拟插值
	PHYSICS													//物理插值
};
////扫描模式字符串名
//const wchar_t szScanModeText[14][32]={
//	_T("Ⅰ代扫描"),_T("Ⅱ代CT扫描"),_T("Ⅲ代CT扫描"),_T("DR扫描"),
//	_T("局部扫描"),_T("螺旋扫描"),_T("锥束扫描"),_T("锥束螺旋扫描"),
//	_T("背景校正"),_T("空气校正"),_T("标定分层零点扫描"),_T("标定回转中心扫描"),
//	_T("大视场扫描"),_T("组态扫描")};


//分层控制方式名义值定义
enum{
	CURRENT_LAYER_SCAN	= 0,								//当前层扫描
	EQU_LAYER_SPACE_SCAN,									//等层距扫描
	CHANGE_LAYER_SPACE_SCAN									//变层距扫描
};

////////////////////////////////////////////////////////////////////////////////////////////
//CD系列工业CT通用命令字定义                                
enum{
	CMD_NULL								= -1,			//无命令

    CMD_POWER_CTRL							= 0x00,			//电源控制									0x00
	CMD_OFF_BEAM,											//停止射线源出束							0x01

	CMD_POLL_STATUS							= 0x10,			//查询底层控制器状态						0x10
	CMD_UPLOAD_CONTROL_SYSTEM_STATUS,              			//上传控制系统状态							0x11
//	CMD_UPLOAD_RAY_STATUS,                      			//上传射线源控制器状态
	CMD_DOWNLOAD_WORKZERO,                      			//下载工作零位								0x12
	CMD_UPLOAD_WORKZERO,                        			//上传工作零位								0x13
	CMD_UPLOAD_ENCODER_COUNT,                   			//上传编码器计数值							0x14
	CMD_UPLOAD_RASTER_COUNT,                    			//上传光栅计数值							0x15
	CMD_UPLOAD_COLLIMATOR_STATUS,              				//上传准直器状态							0x16
	CMD_DOWNLOAD_ACCELATOR_FREQ,                			//下载加速器同步频率						0x17
	CMD_UPLOAD_ACCELATOR_FREQ,                  			//上传加速器同步频率						0x18
	CMD_UPLOAD_GRADUATION_BASE,								//读Ⅲ代CT扫描起始分度号					0x19
	CMD_DOWNLOAD_GEOMETRY_PARA,								//下载系统几何结构参数						0x1a
	CMD_UPLOAD_GEOMETRY_PARA,								//上传系统几何结构参数命令					0x1b
	CMD_UPLOAD_SCENE_KEY,                       			//上传现场控制单元按键状态					0x1c
	CMD_UPLOAD_FAULT_CODE,                      			//上传前10次故障代码						0x1d
	CMD_CLEAR_FAULT_CODE_TBL,                   			//清除故障代码表							0x1e
	CMD_CLEAR_SAVE_FLAG,                                    //清除存盘标志命令							0x1f
	CMD_UPLOAD_LASTCMD_RESULT,								//上传前次命令执行结果						0x20
	CMD_UPLOAD_DIAGNICS_RESULT,								//上传故障诊断结果							0x21
	CMD_UPLOAD_POWER_STATUS,								//上传电源状态								0x22
	CMD_DOWNLOAD_AXIS_SPEED,								//下载运动轴设定速度						0x23
	CMD_UPLOAD_AXIS_SPEED,									//上传运动轴设定速度						0x24

	CMD_STOP								= 0x30,         //中断现行操作								0x30
	CMD_SEEK_ABS_ZERO,										//运动初始化(各运动初始化)					0x31
	CMD_SEEK_AXIS_ABS_ZERO,									//单轴初始化								0x32
	CMD_GOTO_WORK_ZERO,										//运动回零(各运动从当前位置返回工作零位)	0x33
 	CMD_AXIS_GOTO_WORK_ZERO,                    			//指定坐标返回工作零位						0x34
	CMD_AXIS_REL_MOVE,										//单轴相对移动(EL有效时停止)				0x35
    CMD_AXIS_ABS_MOVE,										//单轴绝对移动(EL有效时停止)				0x36
    CMD_AXIS_CONT_MOVE,										//单轴连续运动(EL有效时停止)				0x37
	CMD_AXIS_GOTO_SDP,                          			//单轴运动到SD+								0x38
	CMD_AXIS_GOTO_SDN,                          			//单轴运动到SD-								0x39
	CMD_AXIS_GOTO_ELP,                          			//单轴运动到EL+								0x3a
	CMD_AXIS_GOTO_ELN,                          			//单轴运动到EL-								0x3b
    CMD_SLICE_REL_MOVE,										//分层坐标相对移动(以探测器轴为基准)		0x3c
    CMD_SLICE_ABS_MOVE,										//分层坐标绝对移动(以探测器轴为基准)		0x3d
    CMD_SLICE_CONT_MOVE,									//分层坐标连续移动							0x3e
    CMD_SLICE_THICKNESS_ADJUST,								//断层厚度调节								0x3f
    CMD_COLLIMATOR_SWITCH,									//准直器选择								0x40
	CMD_SET_RADIAL_POS,                                     //设置径向位置								0x41
	CMD_DIAGNICS,                               			//运动系统诊断								0x42
	//2017.02.18更新
    CMD_SLICE_STODLASER_ABS_MOVE,							//测距：射线源激光对准探测器上测距面后绝对移动(以探测器轴为基准)	0x43
    CMD_SAIMDLASER_AUTOCALM_MOVE,							//找准：射线源激光对准探测器上接收器后自动校准运动(保持探测器轴不动)	0x44
	//2017.03.02更新
	CMD_LASER_MEASURING_MOVE,								//配合激光干涉仪测精度运动					0x45
    CMD_SAIMDLASER_GOTO_LAST_POS,							//找准：将射线平移、射线升降、探测平移、探测升降定位至前次激光对准接收器的位置	0x46
	//2017.04.26更新
    CMD_SLICE_OFFSET_ABS_MOVE,								//分层偏移运动绝对移动(升降轴)				0x47
	CMD_TO_TRANS_POS,										//去运输位：将射线单元及探测单元共6轴定位至运输位置	0x48
	//2017.09.26更新
    CMD_DET_SELECT,											//线阵/面阵切换命令							0x49

	CMD_CT_SCAN								= 0x60,			//CT扫描									0x60
	CMD_LARGEVIEW_SCAN,                                     //大视场CT扫描								0x61
	CMD_DR_SCAN,                                			//DR扫描									0x62
	CMD_NEXT_SCAN,                  						//启动下一层CT扫描/2代平移					0x63
	CMD_HELIX_SCAN,											//螺旋CT扫描								0x64
	CMD_LOCAL_SCAN,											//局部扫描									0x65
	CMD_CONE_SCAN,											//锥束扫描									0x66
	CMD_BACK_BEGIN_POS,										//运动返回扫描前位置(扫描前需记录各坐标位置)0x67
	CMD_RAY_TUNE,											//射线(空气)校正(固定采集512个数据)			0x68
	CMD_BKG_TUNE,											//背景校正(固定采集512个数据)				0x69
	CMD_CAL_LAYER_ZERO,                                     //分层零点标定								0x6a
	CMD_SIMULATION_CT3,                                     //模拟3代CT扫描(512分度)					0x6b
	//2017.06.26更新
	CMD_CONEPOINT_SCAN,										//锥束点位扫描								0x6c
	//2017.09.05更新
	CMD_CROSS_SCAN,											//交错扫描									0x6d
	CMD_SINGLE_CROSS_SCAN,									//静态交错扫描								0x6e

	CMD_CONE_LARGE_VIEW_SCAN,								//锥束大视场扫描							0x6f
	CMD_HELIX_POINT_SCAN,									//锥束螺旋点位扫描							0x70

	CMD_DOWNLOAD_COORDINATE_LAMP_ENHANCE	= 0x80,			//向增强型现场控制单元下传坐标值(浮点格式),指示灯状态
    CMD_DOWNLOAD_LAMP_FACILITY,								//向简易型现场控制单元下传指示灯状态

    CMD_DOOR_OPENorCLOSE					= 0x90,			//送料/防护门控制命令						0x90
	CMD_MARK,											    //标记单元控制							0x93
	
	//工件小车控制命令
	CMD_POLL_STATUS_OV						= 0xA0,			//工件小车查询系统状态
	CMD_SET_ABS_ZERO_OV,									//工件小车位置清零
	CMD_FLATCAR_MOVE_OV,									//工件小车运动控制
	CMD_RESET_FREQ_CONVTER_OV,								//工件小车故障复位
	
	//调平系统控制命令
	CMD_STOP_TP								= 0xB0,			//调平系统终止现行操作
	CMD_POLL_STATUS_TP,										//调平系统查询系统状态
	CMD_POWER_OFF_TP,										//调平系统断电控制
	CMD_POWER_ON_TP,										//调平系统上电控制
	CMD_1KEY_LEVELLING_TP,									//调平系统整体一键调平控制
	CMD_1PLAT1KEY_LEVELLING_TP,								//调平系统单平台一键调平控制
	CMD_1PLATFORM_UP_TP,									//调平系统单平台整体上升控制
	CMD_1PLATFORM_DOWN_TP,									//调平系统单平台整体下降控制
	CMD_1LEG_UP_TP,											//调平系统单腿升降控制
	CMD_1LEG_DOWN_TP,										//调平系统单腿下降控制
	CMD_RESET_SENSOR,										//传感器复位：1-传感器1(探测器侧)；2-传感器2(加速器侧)；3-传感器3(工件侧)
	CMD_1PLAT_SMALL_TP,										//单平台水平微调：1-探测器平台；2-加速器平台；
	CMD_1PLAT_RETURN,										//平台撤收：1-探测器平台；2-加速器平台；
	CMD_RESET_AXES_ALARM									//清除电机轴报警；
};

////////////////////////////////////////////////////////////////////////////////////////////
////CD系列工业CT通用状态字定义
enum{
    STS_AxGraduation_COORDINATION			= 0,			//分度坐标位置								0x00
    STS_AxTranslation_COORDINATION,							//平移坐标位置								0x01
    STS_AxInterpolation_COORDINATION,						//插值坐标位置								0x02
    STS_AxLayer1_COORDINATION,								//分层1(射线源分层)运动坐标					0x03
    STS_AxLayer2_COORDINATION,								//分层2(探测器分层)运动坐标					0x04
    STS_AxRadial_COORDINATION,								//径向运动坐标								0x05
    STS_AxSliceThick_COORDINATION,							//断层厚度调节运动坐标						0x06
    STS_AxCollimator_COORDINATION,							//准直孔选择运动坐标						0x07

	STS_ALL_COORDINATION,                       			//所有坐标位置						   		0x08
	STS_SYSTEM_STATUS,										//系统状态							   		0x09
	//调整了顺序
	STS_IO_REGISTER,                            			//I/O寄存器状态								0x0a

	STS_CONTROL_SYSTEM,										//控制系统状态					   			0x0b
	STS_SCENE_KEY_STATUS,                       			//现场操作台按键信息			   			0x0c
	STS_COLLIMATOR_STATUS,                     				//准直器状态					   			0x0d
//	STS_RAY_CONTROLLER_STATUS,                  			//射线源控制器状态
	STS_WORKZERO,                               			//工作零位						   			0x0e
	STS_ENCODER_COUNT,                          			//电机编码器计数值							0x0f
	STS_RASTER_COUNT,                           			//光栅计数值					   			0x10
	STS_FAULT_CODE,                             			//故障代码包				   				0x11
	STS_ACCELATOR_FREQ,                         			//加速器同步频率				   			0x12
	STS_GRADUATION_BASE,									//Ⅲ代CT扫描起始分度号						0x13
	STS_GEOMETRY_PARA,										//系统几何结构参数信息						0x14
	STS_LASTCMD_MESSAGE,									//前次命令信息					   			0x15
	STS_DIAGNICS_RESULT,									//诊断命令执行结果代码						0x16
	STS_POWER,												//电源状态									0x17
	STS_AXIS_SPEED,											//运动轴设定速度							0x18
	STS_AUTOCALM_ZERO,										//自动校准零点后，返回所得零点参数

    STS_SCENE_KEY_ENHANCE					= 0x80,			//增强型现场控制单元向底层控制器发送的按键信息
    STS_SCENE_KEY_FACILITY,									//简易型现场控制单元向底层控制器发送的按键信息

	STS_LASERMEAS_VALUE						= 0xA0,			//激光测距状态								0xA0

	STS_ACC_STATUS							= 0xF0,			//加速器状态								0xA0

	//工件小车状态
	STS_POLL_STATUS_OV						= 0xB0,			//工件小车状态								0xB0

	//调平系统状态
	STS_POLL_STATUS_TP						= 0xC0			//调平系统状态								0xC0
};					
					
//状态/故障码定义					
enum{
	SUCCESS									= 0x00,			//成功										0x00
	EXECUTION,												//正在执行									0x01
	
	fGraguationInit,										//分度轴初始化失败							0x02
	fTranslationInit,										//平移轴初始化失败							0x03
	fInterpolationInit,										//插值轴初始化失败							0x04
	fLayer1Init,											//射线源分层轴初始化失败					0x05
	fLayer2Init,											//探测器分层轴初始化失败					0x06
	fRadialInit,											//径向轴初始化失败							0x07
	fSliceThicknessInit,									//断层厚度轴初始化失败						0x08
	fCollimatorInit,										//准直器轴初始化失败						0x09

	fGraduationPosition,									//分度轴定位故障							0x0a
	fTranslationPosition,									//平移轴定位故障							0x0b
	fInterpolationPosition,									//插值轴定位故障							0x0c
	fLayer1Position,										//射线源分层轴定位故障						0x0d
	fLayer2Position,										//探测器分层轴定位故障						0x0e
	fRadialPosition,										//探测器分层轴定位故障						0x0f
	fSliceThicknessPosition,								//断层厚度轴定位故障						0x10
	fCollimatorPosition,									//准直器轴定位故障							0x11

	fOpenDoor,												//开防护门故障								0x12
	fCloseDoor,												//开防护门故障								0x13
	fMovementLimit,											//运动限位									0x14
	fMoveTimeOut,											//运动超时									0x19
			
    fStartupCheckError,										//StartupCheck错误							0x15
    fDrInitPos,												//DR扫描初始化位置错误						0x16
    fCTInitPos,												//CT扫描初始化位置错误						0x17
    fUnavailableCMD,										//无效命令									0x18
	
	sIsUnready,												//系统未就绪								0x1a
	sIsDoorClosing,											//防护门处于关闭状态						0x1b
	sIsDoorOpen,											//防护门处于打开状态						0x1c
	
	sfEND													//故障/状态结束符							0x1d
};	

//状态/故障名定义					
const char szNameOfFaultStatus[][64]={
	"成功",
	"正在执行",

	"分度轴初始化失败",
	"平移轴初始化失败",
	"插值轴初始化失败",
	"射线源分层轴初始化失败",
	"探测器分层轴初始化失败",
	"径向轴初始化失败",
	"层厚轴初始化失败",
	"准直器轴初始化失败",

	"分度轴定位故障",
	"平移轴定位故障",
	"插值轴定位故障",
	"射线源分层轴定位故障",
	"探测器分层轴定位故障",
	"径向轴定位故障",
	"层厚轴定位故障",
	"准直器轴定位故障",

	"开防护门故障",
	"开防护门故障",
	"运动限位",
	"运动超时",

	"StartupCheck错误",
	"DR扫描初始化位置错误",
	"CT扫描初始化位置错误",
	"无效命令",

	"系统未就绪",
	"防护门处于关闭状态",
	"防护门处于打开状态",

	""
};

//接收图像系统缺陷标记信息后的返回状态定义
enum{
		dMarkCmdDownload	= 0,							//	0		命令已下达到控制系统
		dCtrlNetNoLink,										//	1		控制网络未连接
		dSysNotReady,										//	2		系统未就绪
		dMarkUnitUndefineOrNotWork,							//	3		未定义标记单元或标记单元未工作
		dSysBusy,											//	4		系统忙
		dSysFault,											//	5		系统故障
		dWaitDefectMsg,										//	6		等待缺陷信息
		dUnknowError										//	other	未知错误
};

//系统状态字结构
/******        高电平有效        ******/
union SysStatus{
	struct{
		//*********************status1: 16 bits*****************************
		BYTE	graduation_zero_found			:1;			//分度运动零位已找到(1)
		BYTE	translation_zero_found			:1;			//平移运动零位已找到(1)
		BYTE	interpolation_zero_found		:1;			//插值运动零位已找到(1)
		BYTE	layer1_zero_found				:1;			//射线源分层运动零位已找到(1)
		BYTE	layer2_zero_found				:1;			//探测器分层运动零位已找到(1)
		BYTE	radial_zero_found				:1;			//径向运动零位已找到(1)
		BYTE	sliceThick_zero_found			:1;			//断层厚度调节零位已找到(1)
		BYTE	collimator_zero_found			:1;			//准直器选择零位已找到(1)
								
		//2017.05.26更改
		BYTE	detRadial_zero_found			:1;			//探测径向零位已找到(1)
		BYTE	detTranslation_zero_found		:1;			//探测平移零位已找到(1)
		BYTE	rayRadial_zero_found			:1;			//射线径向零位已找到(1)
		BYTE	rayTranslation_zero_found		:1;			//射线平移零位已找到(1)
		BYTE	tableVertical_zero_found			:1;			//工件升降零位已找到(1)
		BYTE	deflection_zero_found			:1;			//偏摆零位已找到(1)
		BYTE									:2;			//保留

		//*********************status2: 16 bits*****************************
		BYTE	graduation_org					:1;			//分度参考信号					0-无效	1-有效
		BYTE	translation_org					:1;			//平移参考信号					0-无效	1-有效
		BYTE	interpolation_org				:1;			//插值参考信号					0-无效	1-有效
		BYTE	layer1_org						:1;			//分层1(射线源分层)参考信号		0-无效	1-有效
		BYTE	layer2_org						:1;			//分层2(探测器分层)参考信号		0-无效	1-有效
		BYTE	radial_org						:1;			//径向参考信号					0-无效	1-有效
		BYTE	sliceThick_org					:1;			//层厚参考信号					0-无效	1-有效
		BYTE	collimator_org					:1;			//准直器参考信号				0-无效	1-有效
					
		BYTE	graduation_alarm				:1;			//分度运动告警					0-正常	1-告警
		BYTE	translation_alarm				:1;			//平移运动告警					0-正常	1-告警
		BYTE	interpolation_alarm				:1;			//插值运动告警					0-正常	1-告警
		BYTE	layer1_alarm					:1;			//分层1(射线源分层)运动告警		0-正常	1-告警
		BYTE	layer2_alarm					:1;			//分层2(探测器分层)运动告警		0-正常	1-告警
		BYTE	radial_alarm					:1;			//径向运动告警					0-正常	1-告警
		BYTE	sliceThick_alarm				:1;			//层厚调节运动告警				0-正常	1-告警
		BYTE	collimator_alarm				:1;			//准直器选择运动告警			0-正常	1-告警
					
		//*********************status3: 16 bits*****************************
		BYTE	translation_SDp					:1;			//平移SD+						0-无效	1-有效
		BYTE	translation_SDn					:1;			//平移SD-						0-无效	1-有效
		BYTE	interpolation_SDp				:1;			//插值SD+						0-无效	1-有效
		BYTE	interpolation_SDn				:1;			//插值SD-						0-无效	1-有效
		BYTE	layer1_SDp						:1;			//分层1(射线源分层)SD+			0-无效	1-有效
		BYTE	layer1_SDn						:1;			//分层1(射线源分层)SD-			0-无效	1-有效
		BYTE	layer2_SDp						:1;			//分层2(探测器分层)SD+			0-无效	1-有效
		BYTE	layer2_SDn						:1;			//分层2(探测器分层)SD-			0-无效	1-有效

		BYTE	radial_SDp						:1;			//径向SD+						0-无效	1-有效
		BYTE	radial_SDn						:1;			//径向SD-						0-无效	1-有效
		BYTE	sliceThick_SDp					:1;			//层厚调节SD+					0-无效	1-有效
		BYTE	sliceThick_SDn					:1;			//层厚调节SD-					0-无效	1-有效
		BYTE	collimator_SDp					:1;			//准直器选择SD+					0-无效	1-有效
		BYTE	collimator_SDn					:1;			//准直器选择SD-					0-无效	1-有效
		BYTE									:2;     	//保留
						
		//*********************status4: 16 bits*****************************
		BYTE	translation_ELp					:1;			//平移EL+						0-无效	1-有效
		BYTE	translation_ELn					:1;			//平移EL-						0-无效	1-有效
		BYTE	interpolation_ELp				:1;			//插值EL+						0-无效	1-有效
		BYTE	interpolation_ELn				:1;			//插值EL-						0-无效	1-有效
		BYTE	layer1_ELp						:1;			//分层1(射线源分层)EL+			0-无效	1-有效
		BYTE	layer1_ELn						:1;			//分层1(射线源分层)EL-			0-无效	1-有效
		BYTE	layer2_ELp						:1;			//分层2(探测器分层)EL+			0-无效	1-有效
		BYTE	layer2_ELn						:1;			//分层2(探测器分层)EL-			0-无效	1-有效
					
		BYTE	radial_ELp						:1;			//径向EL+						0-无效	1-有效
		BYTE	radial_ELn						:1;			//径向EL-						0-无效	1-有效
		BYTE	sliceThick_ELp					:1;			//层厚调节EL+					0-无效	1-有效
		BYTE	sliceThick_ELn					:1;			//层厚调节EL-					0-无效	1-有效
		BYTE	collimator_ELp					:1;			//准直器选择EL+					0-无效	1-有效
		BYTE	collimator_ELn					:1;			//准直器选择EL-					0-无效	1-有效
		BYTE									:2;     	//保留

		//*********************status5: 16 bits*****************************
		BYTE	collimator_pos					:2;			//准直器位置编码				00-1#准直孔 01-2#准直孔	10-3#准直孔  11-不确定
		BYTE	scene_link						:1;			//现场控制单元连接状态			0-未连接	1-已连接
		BYTE	sceneKey_up						:1;			//现场按钮状态指示				0-按下		1-释放
		BYTE	bRaySourceSel					:1;			//射线源选择					0-1#射线源	1-2#射线源
		BYTE	table_setting					:1;			//转台安装大台面				0-小台面	1-大台面
		BYTE	no_man_active					:1;			//主机室人员活动状态			0-有		1-无
		BYTE	mazeDoorClose					:1;			//迷宫门状态					0-开启		1-关闭

		BYTE	TADoorState						:2;			//送料门A状态					00-半开	01-关闭	10-打开	11-故障
		BYTE	TBDoorState						:2;			//送料门B状态					00-半开	01-关闭	10-打开	11-故障
		BYTE									:4; 		//保留

		//*********************status6: 16 bits*****************************
		BYTE	cameraPowerOpen					:1;			//断面摄像电源					0-关闭	1-打开
		BYTE	laserPowerOpen					:1;			//激光器电源					0-关闭	1-打开
		BYTE	detPowerOpen					:1;			//探测电源						0-关闭	1-打开
		BYTE	drvPowerOpen					:1;			//动力电源						0-关闭	1-打开
		BYTE	main_emg_up						:1;			//主控台急停按钮				0-按下	1-释放
		BYTE	testingRoom_emg_up				:1;			//检测室急停按钮				0-按下	1-释放
		//2017.05.30增加
		BYTE	panDetPowerOpen					:1;			//面阵电源						0-关闭	1-打开
		BYTE	lightPowerOpen					:1;			//照明电源						0-关闭	1-打开
		
		//2017.07.31增加
		BYTE	panDetAtWorkPos					:1;			//面阵位于工作位				0-无效	1-在工作位
		BYTE	panDetAtReturnPos				:1;			//面阵位于撤收位				0-无效	1-在撤收位
		//2017.09.26增加
		BYTE	changingDet						:1;			//切换探测器状态				0-停止		1-正在切换
		BYTE	panDet_Inuse			        :1;			//探测器使用状态				0-当前使用线阵	1-当前使用面阵
		BYTE									:4; 		//保留
		 
		//*********************status7: 16 bits*****************************
		//此16位称为控制系统状态
		BYTE	autoMode				        :1;			//手动/自动状态					0-手动		1-自动
		BYTE	seekingZero						:1;			//运动初始化状态				0-停止		1-正在找零
		BYTE	sys_zero_found			        :1;			//系统零位状态					0-未确定	1-已确定
		BYTE	motorRun				        :1;			//电机运行状态					0-所有电机停止	1-有电机运行
		BYTE	scanning				        :1;			//扫描状态						0-结束		1-正在扫描
		BYTE	cmdRun					        :1;			//命令执行指示					0-无		1-正在执行命令
		BYTE	sliceThickAdjusting				:1;			//层厚调节指示					0-停止		1-正在进行
		BYTE	collimatorSelecting				:1;			//准直器切换指示				0-停止		1-正在进行

		BYTE	ready					        :1;     	//系统初始化完成				0-未完成	1-完成
		BYTE	idle					        :1;     	//系统空闲标志					0-忙		1-空闲
		BYTE	warn					        :1;     	//系统告警						0-正常		1-告警
		BYTE	fault					        :1;     	//系统故障						0-正常		1-故障
		BYTE	save					        :1;     	//采集数据存盘指示				0-不动作	1-通知存盘
		BYTE	lock					        :1;     	//联锁指示						0-未联锁	1-已联锁
		BYTE	onBeamTip						:1;     	//加速器出束提示				0-不提示	1-提示出束
		BYTE	waitNextScan			        :1;     	//CT扫描等待状态				0-无		1-等待CMD_NEXT_SCAN命令
					
		//*********************status8: 16 bits*****************************
		//2017.05.26更改
		BYTE	detRadial_org					:1;			//探测径向参考信号				0-无效	1-有效
		BYTE	detTranslation_org				:1;			//探测平移参考信号				0-无效	1-有效
		BYTE	rayRadial_org					:1;			//射线径向参考信号				0-无效	1-有效
		BYTE	rayTranslation_org				:1;			//射线平移参考信号				0-无效	1-有效
		BYTE	objVertical_org					:1;			//工件升降参考信号				0-无效	1-有效
		BYTE	deflection_org					:1;			//偏摆参考信号					0-无效	1-有效
		BYTE									:2;			//保留
					
		BYTE	detRadial_alarm					:1;			//探测径向告警					0-正常	1-告警
		BYTE	detTranslation_alarm			:1;			//探测平移告警					0-正常	1-告警
		BYTE	rayRadial_alarm					:1;			//射线径向告警					0-正常	1-告警
		BYTE	rayTranslation_alarm			:1;			//射线平移告警					0-正常	1-告警
		BYTE	objVertical_alarm				:1;			//工件升降告警					0-正常	1-告警
		BYTE	deflection_alarm				:1;			//偏摆告警						0-正常	1-告警
		BYTE									:2;			//保留

		//*********************status9: 16 bits*****************************
		BYTE	detRadial_SDp					:1;			//探测径向SD+						0-无效	1-有效
		BYTE	detRadial_SDn					:1;			//探测径向SD-						0-无效	1-有效
		BYTE	detTranslation_SDp				:1;			//探测平移SD+						0-无效	1-有效
		BYTE	detTranslation_SDn				:1;			//探测平移SD-						0-无效	1-有效
		BYTE	rayRadial_SDp					:1;			//射线径向SD+						0-无效	1-有效
		BYTE	rayRadial_SDn					:1;			//射线径向SD-						0-无效	1-有效
		BYTE	rayTranslation_SDp				:1;			//射线平移SD+						0-无效	1-有效
		BYTE	rayTranslation_SDn				:1;			//射线平移SD-						0-无效	1-有效

		BYTE	objVertical_SDp					:1;			//工件升降SD+						0-无效	1-有效
		BYTE	objVertical_SDn					:1;			//工件升降SD-						0-无效	1-有效
		BYTE	deflection_SDp					:1;			//偏摆SD+						0-无效	1-有效
		BYTE	deflection_SDn					:1;			//偏摆SD-						0-无效	1-有效
		BYTE									:4; 		//保留

		//*********************status10: 16 bits*****************************
		BYTE	detRadial_ELp					:1;			//探测径向EL+						0-无效	1-有效
		BYTE	detRadial_ELn					:1;			//探测径向EL-						0-无效	1-有效
		BYTE	detTranslation_ELp				:1;			//探测平移EL+						0-无效	1-有效
		BYTE	detTranslation_ELn				:1;			//探测平移EL-						0-无效	1-有效
		BYTE	rayRadial_ELp					:1;			//射线径向EL+						0-无效	1-有效
		BYTE	rayRadial_ELn					:1;			//射线径向EL-						0-无效	1-有效
		BYTE	rayTranslation_ELp				:1;			//射线平移EL+						0-无效	1-有效
		BYTE	rayTranslation_ELn				:1;			//射线平移EL-						0-无效	1-有效

		BYTE	objVertical_ELp					:1;			//工件升降EL+						0-无效	1-有效
		BYTE	objVertical_ELn					:1;			//工件升降EL-						0-无效	1-有效
		BYTE	deflection_ELp					:1;			//偏摆EL+						0-无效	1-有效
		BYTE	deflection_ELn					:1;			//偏摆EL-						0-无效	1-有效
		BYTE									:4; 		//保留
	}s; 
	WORD	u[10];
	BYTE	b[20];
};

//控制系统状态字结构
/******        高电平有效        ******/
union ControlSystemStatus{
	struct{
		//*********************status12: 16 bits*****************************
		//此16位称为控制系统状态
		BYTE	autoMode						:1;     	//手动/自动状态					0-手动		1-自动
		BYTE	seekingZero						:1;     	//运动初始化状态				0-停止		1-正在找零
		BYTE	sys_zero_found					:1;     	//系统零位状态					0-未确定	1-已确定
		BYTE	motorRun						:1;     	//电机运行状态					0-所有电机停止	1-有电机运行
		BYTE	scanning						:1;     	//扫描状态						0-结束		1-正在扫描
		BYTE	cmdRun							:1;     	//命令执行指示					0-无		1-正在执行命令
		BYTE	sliceThickAdjusting				:1;     	//层厚调节指示					0-停止		1-正在进行
		BYTE	collimatorSelecting				:1;     	//准直器切换指示				0-停止		1-正在进行

		BYTE	ready					        :1;     	//系统初始化完成				0-未完成	1-完成
		BYTE	idle					        :1;     	//系统空闲标志					0-忙		1-空闲
		BYTE	warn					        :1;     	//系统告警						0-正常		1-告警
		BYTE	fault					        :1;     	//系统故障						0-正常		1-故障
		BYTE	save					        :1;     	//采集数据存盘指示				0-不动作	1-通知存盘
		BYTE	lock					        :1;     	//联锁指示						0-未联锁	1-已联锁
		BYTE	onBeamTip						:1;     	//加速器出束提示				0-不提示	1-提示出束
		BYTE	waitNextScan			        :1;     	//CT扫描等待状态				0-无		1-等待CMD_NEXT_SCAN命令
	}s;					
	WORD	u;
};

//运动坐标值
struct Coordination{
	float	graduation;										//分度
	float   objTranslation;									//工件平移                
	float   interpolation;									//插值                    
	float   layer1;											//射线源分层              
	float   layer2;											//探测器分层              
	float   objRadial;										//工件径向                
	float   sliceThickness;									//断层厚度(后准直孔高度)  
	float   collimator;										//准直孔宽度              
	float   detRadial;										//探测器X方向运动轴			
	float   detTranslation;									//探测器Y方向运动轴			
	float   rayRadial;										//射线源X方向运动轴			
	float   rayTranslation;									//射线源Y方向运动轴			
	float   objVertical;									//工件Z方向运动轴			
	float   deflection;										//偏摆运动					
};						

//I/O端口状态
union IoRegStatus{
	struct{
		BYTE	out[4];										//输出寄存器状态
		BYTE	in[4];										//输入端口状态
	}s;					
	BYTE	data[8];
};

//单轴指定距离运动命令CMD_AXIS_MOVE_STEP参数字结构
struct AxisMoveStepCmdData{
	BYTE	axisNo;											//轴代号
	float	distance;										//运动距离(mm)
};					

//单轴连续运动命令CMD_AXIS_MOVE_CONTINEOUS参数字结构
struct AxisMoveContCmdData{
	BYTE	axisNo;
	union{
		BYTE	b;										    //轴代号
		struct{					
			BYTE		    :7;					
			BYTE	dir	    :1;							    //运动方向(P_DIR/N_DIR)
		}s;					
	}dir;					
};

//分层连续运动命令CMD_SLICE_MOVE_CONTINEOUS参数字结构
union SliceMoveContCmdData{
	BYTE	b;											    //轴代号
	struct{					
		BYTE		        :7;					
		BYTE	dir		    :1;							    //运动方向(P_DIR/N_DIR)
	}s;					
};

//准直孔宽度选择命令CMD_COLLIMATE_WIDTH_SWITCH参数字结构
struct CollimateWidthSwitchCmdData{
	BYTE	holeNo;										    //准直孔代号:0-2
};					
					
//断层厚度调节命令CMD_COLLIMATE_HEIGHT_ADJUST参数字结构
struct LayerThicknessAdjustCmdData{
	float	layerThickness;								    //断层厚度(mm)
};					
					
//单轴运动到指定位置命令CMD_AXIS_GOTO_SPECIFIC_POS参数字结构
struct AxisGotoSpecificPosCmdData{
	BYTE	axisNo;										    //轴代号
	float	pos;										    //运动位置(mm或度)
};					

//分层运动到指定位置命令CMD_SLICE_GOTO_SPECIFIC_POS参数字结构
struct SliceGotoSpecificPosCmdData{
	float	pos;										    //运动位置(mm)
};	
				
//标记控制命令CMD_MARK数据结构
struct MarkCtrlCmdData{
	float	horizontalCoordinate;						//缺陷水平坐标(单位：mm)
	float	verticalCoordinate;							//缺陷垂直坐标(单位：mm)
	float	rotationAngle;								//缺陷角度 (单位：°)
};
					
//扫描命令参数字结构
//CT命令状态位定义
//2017.04.26增加btnStartScan, autoStopBeam
union CT23StsBit{
	struct{												//2代扫描位结构
		BYTE  btnStartScan		:1;							//0-立即启动扫描,		1-等待出束按钮启动扫描
		BYTE  changeLayerSpace	:1;							//0-等层距扫描,	    1-变层距扫描
		BYTE            		:1;							//0-普通3代扫描,	1-
		BYTE  czAmountInc1		:1;							//0-标准插值数,	    1-插值数加1
		BYTE  autoStopBeam		:1;							//0-扫描结束不停束,	1-扫描结束停止出束
		BYTE  currentLayer		:1;							//0-按给定参数分层, 1-当前层扫描
		BYTE  biDirTranslation	:1;							//2代扫描时:0-正向平移, 1-2代CT双向平移
		BYTE  thirdGeneration	:1;							//0-2代CT扫描,		1-3代CT扫描
	}s;					
	struct{												//3代扫描位结构
		BYTE  btnStartScan		:1;							//0-立即启动扫描,		1-等待出束按钮启动扫描
		BYTE  changeLayerSpace	:1;							//0-等层距扫描,	    1-变层距扫描
		BYTE            		:1;							//0-普通3代扫描,	1-大视场2代+3代混合扫描
		BYTE  czAmountInc1		:1;							//0-标准插值数,	    1-插值数加1
		BYTE  autoStopBeam		:1;							//0-扫描结束不停束,	1-扫描结束停止出束
		BYTE  currentLayer		:1;							//0-按给定参数分层, 1-当前层扫描
		BYTE  physiInterpolation:1;							//3代扫描时:0-模拟插值, 1-物理插值
		BYTE  thirdGeneration	:1;							//0-2代CT扫描,		1-3代CT扫描
	}s1;					
	BYTE  c;
};
//DR命令状态位定义
//2017.04.26增加autoStopBeam
union DRStsBit{
	struct{
		BYTE  physiInterpolation:1;							//0-模拟插值,		1-物理插值
		BYTE  multiAngle		:1;							//0-单角度扫描,		1-多角度扫描
		BYTE  twoVehicle		:1;							//0-1个检测小车,	1-2个检测小车
		BYTE  czAmountInc1		:1;							//0-标准插值数,		1-插值数加1
		BYTE  autoStopBeam		:1;						    //0-扫描结束不停束,	1-扫描结束停止出束
		BYTE  biDirScan			:1;							//0-正向扫描,		1-双向扫描
		BYTE  btnStartScan		:1;							//0-接收命令后立即开始扫描, 1-射线源出束按钮启动扫描
		BYTE  thirdGeneration	:1;							//0-2代拼接扫描,	1-3代插值扫描
   }s;					
   BYTE  c;
};
//局部CT扫描命令状态位定义
union LocalStsBit{
	struct{
		BYTE					:5;							//D0-4
		BYTE	currentLayer	:1;							//D5: 0-按给定参数分层, 1-当前层扫描
		BYTE	biDirTranslation:1;							//D6: 0-正向平移, 1-双向平移
		BYTE					:1;							//D7: 
	}s;
	BYTE	c;
};
//螺旋CT命令状态位定义
union HelixStsBit{
	struct{
		BYTE  physiInterpolation:1;							//0-模拟插值,		1-物理插值
		BYTE  biDirScan			:1;							//0-正向分层,		1-螺旋回扫,
		BYTE			        :1;					
		BYTE  czAmountInc1		:1;							//0-标准插值数,	1-插值数加1,
		BYTE				    :1;							
		BYTE  currentLayer		:1;							//0-按给定层位置扫描,1-当前层位置开始扫描 
		BYTE				    :2;							//
	}s;					
	BYTE  c;					
};
//锥束CT命令状态位定义
union ConeStsBit{
	struct{
		BYTE  translationCone   :1;							//0-普通锥束扫描,	1-平移锥束扫描
		BYTE				    :4;        					
		BYTE  currentLayer		:1;							//0-按给定参数确定层位置,1-当前层位置
		BYTE				    :1;        
		BYTE  coneHelix			:1;							//0-锥束扫描,		1-锥束螺旋扫描
             					
   }s;					
   BYTE  c;
};

//2/3代CT扫描命令CMD_CT_SCAN参数字结构
struct CT23ScanCmdData{
	CT23StsBit	stsBit;										//命令状态位
	BYTE	interpolationAmount;							//3代扫描探测器位置数(插值次数)DM(>=1)
	WORD	projectionAmount;								//投影次数PN
	BYTE	reserved1;										//保留
	WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
	float   viewDiameter;									//视场直径(mm)
	short	orientInc;										//分度方位角增量(度,0-360)
	WORD	ct2Mode;									    //2代扫描模式(0-360度,1-180度,2-180度间隔)
	WORD	sliceAmount;									//扫描层数SN
	BYTE	tabelNumber;									//扫描转台代号(高4位为0时,以低4位表示的转台中心为原点进行扫描;
														    //高4位不为0时,以高低4位表示的两个转台轴心连线中心为原点进行扫描)
	float	centerOffset;								   	//回转中心偏移(mm)
	float	firstLayerOffset;							   	//第1层偏移(mm)
	float	layerSpace;									   	//相邻层间距(mm)
};					
					
//大视场CT扫描命令CMD_LARGEVIEW_SCAN参数字结构
struct LargeViewCTScanCmdData{
	CT23StsBit	stsBit;										//命令状态位
	BYTE	interpolationAmount;							//3代扫描探测器位置数(插值次数)DM(>=1)
	WORD	projectionAmount;								//投影次数PN
	BYTE	reserved1;										//保留
	WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
	float   viewDiameter;									//视场直径(mm)
	short	orientInc;										//分度方位角增量(度,0-360)
	WORD	sliceAmount;									//扫描层数SN
	float	centerOffset;								   	//回转中心偏移(mm)
	float	firstLayerOffset;							   	//第1层偏移(mm)
	float	layerSpace;									   	//相邻层间距(mm)
};					
					
//DR扫描命令CMD_DR_SCAN参数字结构
struct DRScanCmdData{
	DRStsBit	stsBit;										//命令状态位
	BYTE    interpolationAmount;							//DR扫描探测器位置数(插值次数)DM(>=1)
	WORD	projectionAmount;								//分层投影次数PN
	WORD	angleAmount;									//多个角度DR扫描时的角度数AN
	BYTE	reserved1;										//保留
	WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
	float	viewDiameter;									//视场直径(mm)
	short	orientInc;										//分度方位角增量(度,0-360)
	float	centerOffset;								   	//回转中心偏移(mm)
	float	firstLayerOffset;								//起始扫描坐标(Xs,mm)
	float	layerSpace;										//相邻层间距(mm)
	BYTE	reserved2;										//保留
	BYTE	tabelNumber;									//扫描转台代号(高4位为0时,以低4位表示的转台中心为原点进行扫描;
};

//局部扫描命令CMD_LOCAL_SCAN参数字结构
struct LocalScanCmdData{
	LocalStsBit	stsBit;										//命令状态位
	BYTE	ct2Mode;									    //2代扫描模式(0-360度,1-180度,2-180度间隔)
	WORD	projectionAmount;								//分层投影次数PN
	WORD	sliceAmount;									//扫描层数SN
	WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
	float	localViewDiameter;								//局部区域视场直径(mm)
	float	localCenterSpace;								//局部区域中心至回转中心距离(mm)
	float	orientAngle;									//回转中心至局部区域中心连线与水平方向(X轴)夹角(度)
	float	centerOffset;								   	//回转中心偏移(mm)
	float	firstLayerOffset;								//第1层偏移(mm)
	float	layerSpace;										//层间距(mm)
};					

//螺旋扫描命令CMD_HELIX_SCAN参数字结构
struct HelixScanCmdData{
	HelixStsBit	stsBit;										//命令状态位
	BYTE	interpolationAmount;							//螺旋扫描探测器位置数(插值次数)DM(>=1)
	WORD	projectionAmount;								//投影次数PN
	WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
	float	viewDiameter;									//视场直径(mm)
	WORD	circleAmount;									//分度圆周数CN
	short	orientInc;										//分度方位角增量(度,0-360)
	float	centerOffset;								   	//回转中心偏移(mm)
	float	firstLayerOffset;								//第1层偏移(mm)
	float	helixSpace;										//螺距(mm)
};

////锥束螺旋扫描命令CMD_CONE_SCAN参数字结构
//struct ConeScanCmdData{
//	ConeStsBit	stsBit;										//命令状态位 
//	WORD	projectionAmount;							    //投影次数PN
//	WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
//	short	orientInc;									   	//分度方位角增量(度,0-360)
//	WORD	circleAmount;								   	//分度圆周数CN
//	float	centerOffset;								   	//回转中心偏移(mm)
//	float	firstLayerOffset;							   	//第1层偏移(mm)
//	float	helixSpace;									   	//螺距(mm)
//}ConeScanCmdData;					
		
//锥束螺旋扫描命令CMD_CONE_SCAN参数字结构
struct ConeScanCmdData{
	ConeStsBit	stsBit;										//命令状态位 
	WORD	projectionAmount;							    //投影次数PN
	//WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
	float 	sampleTime;										//投影采样时间Tp(4-2000ms)
	WORD	frame;											//帧数
	short	orientInc;									   	//分度方位角增量(度,0-360)
	BYTE	b180Scan;									//180度扫描标志(0-360度;1-180度)
	WORD	circleAmount;								   	//分度圆周数CN
	float	centerOffset;								   	//回转中心偏移(mm)
	float	firstLayerOffset;							   	//第1层偏移(mm)
	float	helixSpace;									   	//螺距(mm)
	WORD	crossGradAngle;									//交错扫描用分度角（30°，45°，60°，90°）
	BYTE	bCrossEquAngle;								//交错扫描用等间距/等角度标志(0-等间距，1-等角度)
	BYTE	bEnableDetYMove;							//探测器平移轴运动与否(0-不运动，1-运动)
};					

//分层零点标定命令CMD_CAL_LAYER_ZERO参数字结构
struct CalAxisZeroCmdData{
	BYTE	axisType;										//校正轴：0-分层；1-升降；2-径向
	float	firstLayerOffset;							   	//第1分层偏移(mm)
	WORD	sampleTime;										//投影采样时间Tp(4-2000ms)
};					
					
//电源控制命令CMD_POWER_CTRL参数字结构
union PowerCtrlCmd{
   struct{
	   BYTE	onDetPower		:1;								//0-关闭探测器电源,		1-打开探测器电源
	   BYTE	onDrvPower		:1;								//0-关闭动力电源,		1-打开动力电源
	   BYTE onCamera	    :1;								//0-关闭摄像头电源,		1-打开摄像头电源
	   BYTE	onLaser			:1;								//0-关闭激光器电源,		1-打开激光器电源
	   BYTE	onPanDetPower	:1;								//0-关闭面阵探测器电源,		1-打开面阵探测器电源
	   BYTE	onLight			:1;								//0-关闭照明电源,		1-打开照明电源
	   BYTE	onPanDetWorkPos :1;								//0-关闭面阵工作位电磁铁电源,		1-打开面阵工作位电磁铁电源
	   BYTE	onPanDetReturnPos :1;							//0-关闭面阵撤收位电磁铁电源,		1-打开面阵撤收位电磁铁电源

	   BYTE	detPowerMask	:1;                             //0-禁止控制探测器电源, 1-允许控制探测器电源
	   BYTE drvPowerMask	:1;								//0-禁止控制动力电源,	1-允许控制动力电源
	   BYTE cameraMask		:1;                             //0-禁止控制摄像头电源, 1-允许控制摄像头电源
	   BYTE laserMask		:1;                             //0-禁止控制激光器电源, 1-允许控制激光器电源
	   BYTE	panDetPowerMask	:1;								//0-禁止面阵探测器电源,		1-允许面阵探测器电源
	   BYTE	lightMask		:1;								//0-禁止照明电源,		1-允许照明电源
	   BYTE	panDetWorkPosMask	:1;							//0-禁止面阵工作位电磁铁电源,	1-允许面阵工作位电磁铁电源
	   BYTE	panDetReturnPosMask	:1;							//0-禁止面阵撤收位电磁铁电源,	1-允许面阵撤收位电磁铁电源
   }s;
   BYTE  b;
};

//调平状态反馈结构
struct BanlanceCtrlSts{
	struct{
		//平台1支腿状态
		BYTE	plat1Leg3Drive_fault	:1;								//平台1支腿3驱动器故障：	0-无故障,	1-有故障
		BYTE	plat1Leg3OnGround		:1;								//平台1支腿3触地指示：		0-未触地,	1-已经触地
		BYTE	plat1Leg3_ELp			:1;								//平台1支腿3上限位：		0-无效,		1-有效
		BYTE	plat1Leg3_ELn			:1;								//平台1支腿3下限位：		0-无效,		1-有效
		BYTE	plat1Leg4Drive_fault	:1;								//平台1支腿4驱动器故障：	0-无故障,	1-有故障
		BYTE	plat1Leg4OnGround		:1;								//平台1支腿4触地指示：		0-未触地,	1-已经触地
		BYTE	plat1Leg4_ELp			:1;								//平台1支腿4上限位：		0-无效,		1-有效
		BYTE	plat1Leg4_ELn			:1;								//平台1支腿4下限位：		0-无效,		1-有效

		BYTE	plat1Leg1Drive_fault	:1;								//平台1支腿1驱动器故障：	0-无故障,	1-有故障
		BYTE	plat1Leg1OnGround		:1;								//平台1支腿1触地指示：		0-未触地,	1-已经触地
		BYTE	plat1Leg1_ELp			:1;								//平台1支腿1上限位：		0-无效,		1-有效
		BYTE	plat1Leg1_ELn			:1;								//平台1支腿1下限位：		0-无效,		1-有效
		BYTE	plat1Leg2Drive_fault	:1;								//平台1支腿2驱动器故障：	0-无故障,	1-有故障
		BYTE	plat1Leg2OnGround		:1;								//平台1支腿2触地指示：		0-未触地,	1-已经触地
		BYTE	plat1Leg2_ELp			:1;								//平台1支腿2上限位：		0-无效,		1-有效
		BYTE	plat1Leg2_ELn			:1;								//平台1支腿2下限位：		0-无效,		1-有效
																
		//平台2支腿状态
		BYTE	plat2Leg3Drive_fault	:1;								//平台2支腿3驱动器故障：	0-无故障,	1-有故障
		BYTE	plat2Leg3OnGround		:1;								//平台2支腿3触地指示：		0-未触地,	1-已经触地
		BYTE	plat2Leg3_ELp			:1;								//平台2支腿3上限位：		0-无效,		1-有效
		BYTE	plat2Leg3_ELn			:1;								//平台2支腿3下限位：		0-无效,		1-有效
		BYTE	plat2Leg4Drive_fault	:1;								//平台2支腿4驱动器故障：	0-无故障,	1-有故障
		BYTE	plat2Leg4OnGround		:1;								//平台2支腿4触地指示：		0-未触地,	1-已经触地
		BYTE	plat2Leg4_ELp			:1;								//平台2支腿4上限位：		0-无效,		1-有效
		BYTE	plat2Leg4_ELn			:1;								//平台2支腿4下限位：		0-无效,		1-有效

		BYTE	plat2Leg1Drive_fault	:1;								//平台2支腿1驱动器故障：	0-无故障,	1-有故障
		BYTE	plat2Leg1OnGround		:1;								//平台2支腿1触地指示：		0-未触地,	1-已经触地
		BYTE	plat2Leg1_ELp			:1;								//平台2支腿1上限位：		0-无效,		1-有效
		BYTE	plat2Leg1_ELn			:1;								//平台2支腿1下限位：		0-无效,		1-有效
		BYTE	plat2Leg2Drive_fault	:1;								//平台2支腿2驱动器故障：	0-无故障,	1-有故障
		BYTE	plat2Leg2OnGround		:1;								//平台2支腿2触地指示：		0-未触地,	1-已经触地
		BYTE	plat2Leg2_ELp			:1;								//平台2支腿2上限位：		0-无效,		1-有效
		BYTE	plat2Leg2_ELn			:1;								//平台2支腿2下限位：		0-无效,		1-有效
																			  
		BYTE	scene_emg_down			:1;								//手柄急停按钮				0-释放		1-按下
		BYTE	plat1_lock_ok			:1;								//平台1安全插销互锁状态		0-无效		1-有效
		BYTE	plat2_lock_ok			:1;								//平台2安全插销互锁状态		0-无效		1-有效
		BYTE	reserve2				:5;								//保留

		BYTE	plat1_banlanced			:1;								//平台1已调平指示：			0-未调平,	1-已调平
		BYTE	plat2_banlanced			:1;								//平台2已调平指示：			0-未调平,	1-已调平
		BYTE	plat1_emg_down			:1;								//平台1急停按钮				0-释放		1-按下
		BYTE	plat2_emg_down			:1;								//平台2急停按钮				0-释放		1-按下
		BYTE	plat1_moving			:1;								//平台1运动指示				0-停止		1-运动中
		BYTE	plat2_moving			:1;								//平台2运动指示				0-停止		1-运动中
		BYTE	sceneCtrlFlag			:1;								//本地控制指示				0-现场		1-远程
		BYTE	remoteCtrlFlag			:1;								//远程控制指示				0-现场		1-远程
	}s;
	BYTE	plat1AngleX[4];												//平台1X方向角度，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat1AngleY[4];												//平台1Y方向角度，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat2AngleX[4];												//平台2X方向角度，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat2AngleY[4];												//平台2Y方向角度，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat3AngleX[4];												//平台3X方向角度，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat3AngleY[4];												//平台3Y方向角度，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	
	BYTE	plat1Leg1Pos[4];											//平台1支腿1位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat1Leg2Pos[4];											//平台1支腿2位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat1Leg3Pos[4];											//平台1支腿3位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat1Leg4Pos[4];											//平台1支腿4位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数

	BYTE	plat2Leg1Pos[4];											//平台1支腿1位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat2Leg2Pos[4];											//平台1支腿2位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat2Leg3Pos[4];											//平台1支腿3位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
	BYTE	plat2Leg4Pos[4];											//平台1支腿4位置，4字节BCD数：高4位符号位(0-正,1-负)，高字整数，低字小数
};

//调平系统提示面板用结构
struct BanlanceTipSts{
	struct{
		//平台1支腿状态
		BYTE	plat1Leg1Moving			:1;								//平台1支腿1运行指示：	0-停止,	1-运行
		BYTE	plat1Leg2Moving			:1;								//平台1支腿2运行指示：	0-停止,	1-运行
		BYTE	plat1Leg3Moving			:1;								//平台1支腿3运行指示：	0-停止,	1-运行
		BYTE	plat1Leg4Moving			:1;								//平台1支腿4运行指示：	0-停止,	1-运行
		//平台2支腿状态
		BYTE	plat2Leg1Moving			:1;								//平台2支腿1运行指示：	0-停止,	1-运行
		BYTE	plat2Leg2Moving			:1;								//平台2支腿2运行指示：	0-停止,	1-运行
		BYTE	plat2Leg3Moving			:1;								//平台2支腿3运行指示：	0-停止,	1-运行
		BYTE	plat2Leg4Moving			:1;								//平台2支腿4运行指示：	0-停止,	1-运行

		BYTE	reserve1				:8;								//保留
	}s;
	float	plat1Leg1Pos;												//平台1支腿1位置
	float	plat1Leg2Pos;												//平台1支腿2位置
	float	plat1Leg3Pos;												//平台1支腿3位置
	float	plat1Leg4Pos;												//平台1支腿4位置

	float	plat2Leg1Pos;												//平台1支腿1位置
	float	plat2Leg2Pos;												//平台1支腿2位置
	float	plat2Leg3Pos;												//平台1支腿3位置
	float	plat2Leg4Pos;												//平台1支腿4位置
};

//激光测距数据反馈结构
struct LaserMeasValueSts{
	//struct{
	//	BYTE	stoDLaserAimed1				:1;					//激光接收器对准信号			0-未对准		1-已对准
	//	BYTE	stoDLaserAimed2				:1;					//激光接收器对准信号			0-未对准		1-已对准
	//	BYTE	stoDLaserAimed3				:1;					//激光接收器对准信号			0-未对准		1-已对准
	//	BYTE	reserve1					:5;					//保留

	//	BYTE	reserve2					:8;					//保留
	//}s;
	struct{
		BYTE	stoDLaserAimed1;					//激光接收器对准信号			0-未对准		1-已对准
		BYTE	stoDLaserAimed2;					//激光接收器对准信号			0-未对准		1-已对准
		BYTE	stoDLaserAimed3;					//激光接收器对准信号			0-未对准		1-已对准
		BYTE	reserve1[5];			//保留

		BYTE	reserve2[8];					//保留
	}s;

	BYTE	stoDLaserValue[8];								//加速器测探测器激光器测距值(mm)
	float   stoOLaserValue1,								//加速器测工件激光器测距值(mm)
			stoOLaserValue2,								//加速器测工件激光器测距值(mm)
			stoOLaserValue3;								//加速器测工件激光器测距值(mm)
};

//CMD_SAIMDLASER_GOTO_LAST_POS
//将运动系统定位到源-探激光与其接收器对准位置
struct SAimDLaserGotoLastPosCmd{
	float   layer1,											//分层1(mm)
			layer2,											//分层2(mm)
			rayVertical,									//射线升降(mm)
			lineDetVertical;								//线阵升降(mm)
};

//工作零位数据结构(浮点数据)
struct FWorkZero{
	float   graduation,										//分度(度)
			objTranslation,									//工件平移(mm)
			interpolation,									//插值(mm)
			layer1,											//分层1(mm)
			layer2,										    //分层2(mm)
			objRadial,										//工件径向(mm)
			sliceThick,										//层厚(mm)
			collimator1,									//准直孔1工作位置至编码器距离(mm)
			collimator2,									//准直孔2工作位置至编码器距离(mm)
			collimator3,									//准直孔3工作位置至编码器距离(mm)
			objVertical,									//工件升降(mm)
			rayRadial,										//射线源径向运动轴		   
			rayTranslation,									//射线源平移运动轴	 
			detRadial,										//探测器径向运动轴	   
			detTranslation,									//探测器平移运动轴	
			deflection;										//偏摆运动(度)    
};					
					
//系统数据文件结构(底层控制器用)
struct SysData{
	char		head[32];									//文件头字符串
	FWorkZero   zero;										//系统工作零位数据结构
	long		ltOffset;									//断层厚度偏移
	BYTE		currentZzq;									//当前准直器
	WORD		synFreq;									//加速器同步频率(Hz)
	BYTE		varifySum;									//构形文件校验和
};
union USysData{
	SysData  s;
	BYTE		b[sizeof(SysData)];
};

//定义使用WM_COPYDATA消息接收数据结构
struct MYCDSRET_FLAG{
	int     nResult;												//状态码返回标志
	wchar_t	desFilePath[MAX_PATH];									//全路径目标数据文件名
};

//定义WM_COPYDATA消息中线阵面阵标志
enum{
	CPDT_LINE_DET		=	0,                                     //指示线阵
	CPDT_PAN_DET,													//指示面阵
	CPDT_CONE_LARGEVIEW_ONLY							//
};

//定义使用WM_COPYDATA消息发送数据结构
struct FILENAME_FLAG{
	UINT    bDetTypeLine_Pan;										//线阵/面阵标志
	//线阵参数
	char	parFilePath[MAX_PATH];									//参数文件路径
	char	orgFileName[MAX_PATH];									//全路径原始数据文件名
	int		bReconstruction;										//处理完数据重建图像标志:1-Reconstruction
	//面阵参数
	ICT_HEADER23 d_ictHeaderForPan;										//数据头结构变量
	char	darkFilePath[MAX_PATH];									//全路径暗场数据文件名
	char	gainFilePath[MAX_PATH];									//全路径增益数据文件名
	char	defectFilePath[MAX_PATH];								//全路径坏像素数据文件名
	char	saveFilePath[MAX_PATH];									//全路径CT数据文件名
	int		nCrossTransCnt;												//交错扫描平移次数
	BOOL	bDarkCorrectFlag;										//暗场校正标志
	BOOL	bGainCorrectFlag;										//增益校正标志
	BOOL	bDefectCorrectFlag;										//坏像素校正标志
	BOOL	bFrameAverageFlag;										//帧平均标志
	BOOL	b2TableScan;											//双转台扫描
	BOOL	bLastImageFlag;											//是否最后一幅图像标志(通常为面阵采集用)
	float   fDefectMarkPecent;										//坏像素标记所使用的百分比(PE非晶硅探测器用)
	//公共参数
	char	desFilePath[MAX_PATH];									//目的文件路径
	int		nScanMode;												//当前欲执行的扫描模式, -1表示无
	int		bSaveOrg;												//原始数据保存标志:	1-Save
};


/*----------------------------------------------------------------------*/
/*                       通信命令缓冲器数据结构                         */
/* 1. 缓冲器采用二维数据结构,可存放 9 个命令包(不含包头和校验和).       */
/* 2. 用header(头指针)和tailer(尾指针)指示缓冲器状态,两指针相同表示缓冲 */
/*    器为空,其初值均为 0, 范围为: 0 to 9.                              */
/* 3. 命令接收程序从尾部将命令包放入缓冲器                              */
/* 4. 缓冲器命令扫描程序从头部取出命令包,取出命令后使header+1.          */
/* 5. 命令接收中断收到一个完整命令后,先调用命令过滤器,若返回True,表示命 */
/*    令已被处理,否则使tailer+1.                                        */
/*----------------------------------------------------------------------*/
#pragma pack()											    //设定连接程序按8字节对齐(VC编译器缺省)


