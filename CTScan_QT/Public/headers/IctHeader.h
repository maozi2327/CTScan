//-----------------------------------------------------------------------------
//工业CT数据采集/处理文件头定义(V2.3)
//重庆大学ICT研究中心,明视科技分公司.								2005.01.19
//增加三维CT扫描参数												2006.04.20
//V2.3版本开始作为重庆真测科技股份有限公司数据文件格式				2010.05.19

//2007.07.13修改如下:
//1. 将SpaceBetweenLayer(多层CT层距)和LayerThicknessOfDR(DR分层厚度)合并为LayerThickness(分层厚度)
//2. 增加TotalLayers2(第二段DR扫描总层数)
//3. 增加FirstSectStartCoordinateOfDR(第一段DR扫描起始坐标X1),SecondSectStartCoordinateOfDR(第二段DR扫描起始坐标X3)

//2007.07.26修改如下:
//1. 增加重建参数

//2007.10.04修改如下:
//1. 将LayerThickness命名修改为SpaceBetweenLayer
//2. 增加2代扫描重建参数: NumberOfGraduationOfCt2,SerialOfGraduationOfCt2
//3. 增加3代扫描起始分度号: graduationBase
//3. 增加射线平面方向中心探测器序号SerialNo1OfMiddleHorizontalDetector/SerialNo2OfMiddleHorizontalDetector
//   用于数据校正时确定中间探测器(扇面中心射线通过探测器时序号1/2相同;
//   扇面中心射线通过两个探测器中间时,序号1/2相差1)

//2008.04.24修改如下:
//	 ICT_HEADER 改为ICT_HEADER21表示2.1版本格式, 对应DATAFORMAT21, 数据总行数为 WORD
//   增加ICT_HEADER22表示2.2版本格式, 对应DATAFORMAT22, 数据总行数改为 DWORD
//   扫描参数中增加NumberOfTable表示扫描时使用的转台数量

//2008.10.06增加测试工件信息:
//1. 增加工件生产线和工件制造日期项
//2. 为适应DR系统单车双工件模式, 增加工件2名称,编号,生产线,制造日期信息; 
//   原来的工件名称,编号及新增的工件生产线和工件制造日期项作为工件1的有关信息.

//2009.06.17修改如下:
//1. 将原CT扫描起始方位角Azimuth, 在DR扫描方式下定义为DR扫描角度

//2010.05.19修改:
//1. 版本号定义为V2.3
//2. 将射线平面图像尺寸代号Pixels修改为直接表示像素个数
//3. 增加Ⅱ代扫描开始/结束探测器序号BeginSerialNoOfCt2Detector/EndSerialNoOfCt2Detector
//4. V2.3中不使用预置同步脉冲数SetupSynchPulseNumber,该字段保留
//5. V2.3中不使用第二段DR扫描总层数TotalLayers2,该字段保留
//6. V2.3中不使用第二段DR扫描起始坐标SecondSectStartCoordinateOfDR,该字段保留

//2011.12.26修改:
//1. 在结构SCANPARAMETER中增加大视场扫描回转中心偏置参数LargeViewCenterOffset

//2013.01.08修改:
//1. 在结构SCANPARAMETER中增加多个小转台扫描情况下左侧转台序号(0开始)LeftSerialNoOfTable
//-----------------------------------------------------------------------------
#ifndef __ICTHEADER_H
#define __ICTHEADER_H

#ifndef	ULONG
#define	ULONG	unsigned long
#endif

#ifndef	DWORD
#define	DWORD	unsigned long
#endif

#ifndef	WORD
#define	WORD	unsigned short
#endif

#ifndef	BYTE
#define	BYTE	unsigned char
#endif

#define	MainVersion21	2											//定义主版本号
#define	SubVersion21	1											//定义次版本号
#define	MainVersion22	2											//定义主版本号
#define	SubVersion22	2											//定义次版本号
#define	MainVersion23	2											//定义主版本号
#define	SubVersion23	3											//定义次版本号

//探测器结构形式名定义
#ifndef	_DETECTOR_STRUCT_NAME
#define	_DETECTOR_STRUCT_NAME
enum{
	ARC_DETECTOR	=	0,											//弧形探测器
	LINE_DETECTOR,													//直线探测器
	PANEL_DETECTOR													//平板探测器
};
#endif

//扫描方式: 0-Ⅰ代扫描,1-Ⅱ代扫描,2-Ⅲ代扫描,3-DR扫描，4-局部扫描,5-螺旋扫描,6-锥束扫描,7-锥束螺旋扫描
//          8-背景扫描,9-空气扫描,10-分层零点标定扫描,11-回转中心标定扫描,12-大视场扫描 
//扫描模式符号名定义
#ifndef	_SCAN_MODE_NAME
#define	_SCAN_MODE_NAME
enum{
	NO_SCAN		=	-1,												//无扫描操作
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
	_MAX_SCANMODE_ITEM
};
#endif

//定义数据类型
enum{
	CHARDATA	=	1,												//字符型
	INTDATA,														//整型
	LONGDATA,														//长整型
	FLOATDATA,														//浮点型
	DOUBLEDATA														//双精度型
};

#define	PWDLEN		128												//定义密码串长度

//****** 日期,时间信息 20 bytes *********************************************************
typedef struct  _DATE_TIME{
	char	Date[11];					     						//格式:2003/07/10,以ASCIZ结束
	char	Time[9];					     						//格式:16:35:12,以ASCIZ结束
}DATE_TIME;

//****** 测试任务信息 256 bytes *********************************************************
typedef	struct	_TASKMESSAGE{
	DATE_TIME DateTime;												//测试日期及时间(20字节:2003/07/10 16:35:12 )
	char	Number[32];												//试验任务编号(32字节)
	char	Name[64];												//试验任务名称(64字节),格式:汉字区位码
	char	Toastmaster[16];										//试验主持人(16字节),格式:汉字区位码
	char	SubmitUnit[64];											//送检单位(64字节)

	BYTE	reserved[60];											//保留字节
}TASKMESSAGE;

//****** 测试工件信息 640 bytes *********************************************************
//V2.3以前版本使用
typedef	struct	_WORKPIECEMESSAGE{
	char	WorkpieceName[32];										//工件1名称, 格式:汉字区位码
	char	WorkpieceSort[32];										//工件1类别, 格式:汉字区位码
	char	WorkpieceNumber[32];									//工件1编号, 格式:汉字区位码
	char	WorkpieceModel[32];										//工件1型号, 格式:汉字区位码
	char	WorkpieceBatch[32];										//工件1批次, 格式:汉字区位码
	char	WorkpieceShellMaterial[64];  							//工件1壳体材料, 格式:汉字区位码
	char	WorkpieceFillMaterial[64];								//工件1填充材料, 格式:汉字区位码
	char	WorkpieceManufacturer[64]; 								//工件1制造单位, 格式:汉字区位码
	char	TestPosition[32];										//工件1检测部位, 格式:汉字区位码
	char	ZeroPointDefineAlongAxis[32];							//工件1轴向零点文字定义, 格式:汉字区位码
	char	ZeroPointDefineAlongCircle[64];							//工件1圆周零点文字定义, 格式:汉字区位码
	float	WorkpieceZeroPointAlongAxis;							//工件1轴向零点坐标(相对于系统坐标零点)
	float	WorkpieceMaxDiameter;									//工件1最大直径, 单位:mm
	float	WorkpieceDiameter;										//工件1检测部位外径, 单位:mm
	float	WorkpieceLength;										//工件1长度, 单位:mm
	float	WorkpieceBeginCoordinate;								//工件1起始坐标值
	float	WorkpieceEndCoordinate;									//工件1结束坐标值
	float	WorkpieceWeight;										//工件1质量, 单位:kg
	float	MaxDensity;												//工件1最大密度, 单位:g/cm3

	//2008.10.6增加
	char	WorkpieceProductLine[16];								//工件1生产线(炉号..)
	char	WorkpieceMakeDate[16];									//工件1制造日期
	char	Workpiece2Name[16];										//工件2名称, 格式:汉字区位码
	char	Workpiece2Number[16];									//工件2编号, 格式:汉字区位码
	char	Workpiece2ProductLine[16];								//工件2制造单位/生产线(炉号..)
	char	Workpiece2MakeDate[16];									//工件2制造日期

	BYTE	reserved[32];											//保留字节
}WORKPIECEMESSAGE;

//****** 测试工件信息 640 bytes *********************************************************
//V2.3版本使用
typedef	struct	_WORKPIECEMESSAGE23{
	char	WorkpieceName[32];										//工件1名称
	char	WorkpieceModel[32];										//工件1型号
	char	WorkpieceNumber[32];									//工件1编号
	char	WorkpieceBatch[32];										//工件1批次
	char	WorkpieceShellMaterial[32];  							//工件1壳体材料
	char	WorkpieceFillMaterial[32];								//工件1填充材料
	char	WorkpieceManufacturer[32]; 								//工件1制造单位/生产线(炉号..)
	char	WorkpieceMakeDate[16];									//工件1制造日期
	char	WorkpieceTestPosition[32];								//工件1检测部位

	char	WorkpieceName2[32];										//工件2名称
	char	WorkpieceModel2[32];									//工件2型号
	char	WorkpieceNumber2[32];									//工件2编号
	char	WorkpieceBatch2[32];									//工件2批次
	char	WorkpieceShellMaterial2[32];  							//工件2壳体材料
	char	WorkpieceFillMaterial2[32];								//工件2填充材料
	char	WorkpieceManufacturer2[32]; 							//工件2制造单位/生产线(炉号..)
	char	WorkpieceMakeDate2[16];									//工件2制造日期
	char	WorkpieceTestPosition2[32];								//工件2检测部位

	BYTE	reserved[96];											//保留字节
}WORKPIECEMESSAGE23;

//****** 扫描参数信息 380 bytes **********************************************************
typedef	struct	_SCANPARAMETER{
	WORD	ScanMode;												//扫描方式: 0-Ⅰ代扫描,1-Ⅱ代扫描,2-Ⅲ代扫描,3-DR扫描，4-局部扫描,5-螺旋扫描,6-锥束扫描
	WORD	Ct2ScanMode;											//2代扫描模式:  0-360°,1-180°,2-180°间隔
		//Ⅱ代扫描时,双向表示平移为正反两个方向采集数据
		//Ⅲ代扫描时,双向表示相邻两层插值方向相反
		//DR扫描时,双向表示分层为正反两个方向采集数据
	WORD	ScanDirectionMode;										//扫描方向: 0-单向,1-双向
	WORD	DataTransferMode;										//数据传送方式: 0-整体传送, 1-边扫描边传送

	WORD	Pixels;													//V2.3中定义为射线平面图像像素个数(投影数), 取消V2.2中代号表示方式
	float	ViewDiameter;											//视场直径(mm)
	float	RadialDistanceInLocal;									//局部扫描时扫描视场中心至回转中心距离(mm)
	float	AngleInLocal;											//局部扫描时回转中心与扫描视场中心连线与射线平面正半轴起始夹角(°)

	WORD	CollimationSize;										//准直器尺寸代号:0,1,2...   准直器宽度
	float	LayerThickness;											//断层厚度(mm)(准直器高度)
	WORD	DetectorStyle;											//当前使用的探测器结构(0-弧形, 1-直线, 2-平板)
	WORD	NumberOfSystemHorizontalDetector;						//射线平面方向系统探测器数(此参数为探测器总数)
	WORD	NumberOfValidHorizontalDetector;						//射线平面方向有效探测器数(视场范围内的探测器数量)
	WORD	SerialNo1OfMiddleHorizontalDetector;					//射线平面方向中心探测器序号1(弧形/直线探测器, 从0开始计算)
	WORD	SerialNo2OfMiddleHorizontalDetector;					//射线平面方向中心探测器序号2(弧形/直线探测器, 从0开始计算)
	WORD	NumberofSystemVerticalDetector;							//射线平面垂直方向系统探测器数(平板探测器专用, 此参数为探测器总数)
	WORD	NumberofValidVerticalDetector;							//射线平面垂直方向有效探测器数(平板探测器专用)
	float	SpaceOfHorizontalDetector;								//射线平面方向探测器间距(mm, 平板探测器专用)
	float	SpaceOfVerticalDetector;								//射线平面垂直方向探测器间距(mm, 平板探测器专用)
	float	HorizontalSectorAngle;									//射线平面方向扇角(°,与系统探测器数相关, 定义为两侧探测器中心线之间夹角)
	float	VerticalSectorAngle;									//射线平面垂直方向扇角(°,与系统探测器数相关, 定义为两侧探测器中心线之间夹角)
	float	RadialPosition;											//焦点到旋转中心距离(径向位置)(mm)    
	float	SourceDetectorDistance;									//焦点到探测器距离(mm)
	float	Azimuth;												//CT扫描时分度起始方位角(°),或DR扫描角度
	WORD	GraduationDirection;									//分度方向:N_DIR-顺时针(负方向),P_DIR-逆时针(正方向)
	WORD	NumberOfGraduation;										//分度次数(指单螺距、锥束扫描、或二维CT旋转一周分度数)
	WORD	InterpolationFlag;										//插值数标志:0-标准插值,1-插值数＋1
	WORD	NumberOfInterpolation;									//3代/DR/螺旋扫描插值次数(标准插值次数)
	WORD	NumberOfTranslation;									//2代平移采样点数
	WORD	DelaminationMode;										//CT分层方式:0-等层距,1-不等层距,2-当前层距
	float	HelixScanPitch;											//螺旋扫描螺距大小,单位:mm
	WORD	TotalLayers;											//CT扫描总层数或第一段DR扫描总层数
	WORD	TotalLayers2;											//第二段DR扫描总层数,只有一段DR扫描时填写0. V2.3版本不用
	float	CurrentLayerCoordinate;									//当前层坐标,单位:mm
	float	SpaceBetweenLayer;										//CT层距/DR分层厚度(层间距,两段DR扫描时每段层间距相同),单位:mm
	float	FirstSectStartCoordinateOfDR;							//第一段DR扫描起始坐标Z1, 单位:mm
	float	SecondSectStartCoordinateOfDR;							//第二段DR扫描起始坐标Z3, 单位:mm
	WORD	SetupSynchPulseNumber;									//预置同步脉冲数(加速器情况, 在V2.3版本中不再使用)
	float	SampleTime;												//采样时间, 单位:秒
	WORD	UsedScanTime;											//实际扫描时间(s)
	float	TemperatureValue;										//探测系统设置温度值(°)
	char	FilenameTemperature[32];								//探测系统实时温度记录文件名
	char	FilenameOfCTdata[32];									//DR,CT数据文件名(用于存放CT、DR、锥束扫描数据)
	char	FilenameOf2CTdata[32];									//Ⅱ代数据边采边传文件名(即数据文件名加上编号(00-31))
	char	FilenameOfPictureData[32];								//图像数据文件名, 按Windows文件名定义的字符串
	WORD	NumberOfTable;											//扫描检测使用的转台数量(缺省为1, 2表示两个转台)
	
	WORD	BeginSerialNoOfCt2Detector;								//Ⅱ代扫描开始探测器序号(从0开始), V2.3中新增
	WORD	EndSerialNoOfCt2Detector;								//Ⅱ代扫描结束探测器序号(从0开始), V2.3中新增

	WORD	LeftSerialNoOfTable;									//多个小转台扫描情况下左侧转台序号(0开始)
	//为了保持编译时对齐
	BYTE	reserved1[2];											//保留字节
	float	LargeViewCenterOffset;									//大视场扫描回转中心偏置(同时用作多转台扫描中心偏移)

	BYTE	reserved2[106];											//保留字节
}SCANPARAMETER;
//说明:
//(1) 射线平面方向单个探测器夹角Ah=射线平面方向扇角/(射线平面方向系统探测器数-1)
//(2) 射线平面垂直方向单个探测器夹角Av=射线平面垂直方向扇角/(射线平面垂直方向系统探测器数-1)
//(3) Ⅲ代扫描时, 射线平面方向有效探测器数Nv和视场直径D的计算方法(D首先从界面输入):
//		1) 转台中心处探测器等效间距t=射线平面方向单个探测器夹角Ah*焦点到旋转中心距离Q
//		2) Nv = UINT(D/t)		UINT(.)为向上取整函数.
//			探测器过扇面中心线时(SerialNo1OfMiddleHorizontalDetector==SerialNo2OfMiddleHorizontalDetector), 
//			最终的有效探测器数取不小于Nv的奇数;否则取偶数.
//		3) 计算出Nv后对D进行修正: 
//			D = 2*Q*sin[(Nv-1)/2*Ah]
//(4) 标准插值数=UINT(射线平面图像像素个数Pixels/射线平面方向系统探测器数Na), UINT(.)为向上取整函数.
//(5) Ⅱ代扫描使用的探测器数N2=Ⅱ代扫描结束探测器序号 - Ⅱ代扫描开始探测器序号 + 1
//(6) Ⅱ代扫描扇角=Ⅱ代扫描使用的探测器数N2*射线平面方向单个探测器夹角Ah
//(7) Ⅱ代扫描分度角由分度数确定
//向上取整函数y=UINT(x)定义:
//		if INT(x)==x
//			y = x;
//		else
//			y = INT(x)+1

//****** 系统参数信息 192 bytes ***********************************************************
typedef	struct	_SYSTEMPARAMETER{
	char	ModelOfCT[32];											//CT设备型号
	WORD	RaySort;												//射线源类型:0-X球管,1-加速器,2-钴60,3-铯137
	float	RayEngery;												//射线能量(MeV)
	float	RayDosage;												//射线剂量率(cGy/min/m)
	WORD	SynchFrequency;											//同步频率(Hz)
	WORD	AmplifyMultiple;										//采样放大倍数
	WORD	IntegralTime;											//采样积分时间(us)

	BYTE	reserved[140];											//保留字节
}SYSTEMPARAMETER;

//****** II代CT重建信息 128 bytes *********************************************************
typedef	struct	_RECONSTRUCTMESSAGE{
	BYTE	Ct2ReconstructPara[64];									//2代CT扫描分度重建标志(每个分度1字节,0-该分度未重建,1-该分度已重建)
	float	Zmax;													//FDK并行重建用
	float	Zmin;													//FDK并行重建用
	float	RotationAngle;											//三代重建图像旋转角度
	float	PixelMax;												//原始重建图像最大值
	float	PixelMin;												//原始重建图像最小值
	WORD	VolumeLayer;											//三维重建层数
	WORD	VolumeWidth;											//三维重建宽度
	float	SpaceBetweenPixel;										//像素之间宽度
	BYTE	NumberOfGraduationOfCt2;								//分度总数(2代CT扫描, 2007.10.04增加)
	BYTE	SerialOfGraduationOfCt2;								//分度序号(2代CT扫描, 2007.10.04增加)
	BYTE	reserved[32];											//保留字节
}RECONSTRUCTMESSAGE;

//****** 图像识别信息 64 bytes ***********************************************************
typedef	struct	_IDENTIFYMESSAGE{
	WORD	DefectMode;												//缺陷类型: 0-装配,1-导爆索,2-其它(气孔,裂缝,脱粘),默认为0
	char	NumberofTemplate[32];									//识别模板编号(字符串), 输入方式参照word打印页码格式; 例如,1-3表示模板编号从1到3; 1,4,6,8表示识别模板分别为1,4,6,8
	BYTE	reserved[30];											//保留字节
}IDENTIFYMESSAGE;

//****** 数据格式信息 32 bytes  (V2.1版本用)***********************************************************
typedef	struct	_DATAFORMAT21{
	WORD	DataType;												//数据存储类型: char=01,int=02,unsigned long=03,float=04,double=05
	WORD	TotalLines;												//数据总行数  
	WORD	dataColAtRow;											//每行数据个数(不包括附加数据)
	WORD	appendColAtRow;											//每行中前导附加数据个数
	WORD	graduationBase;											//3代扫描分度起始号(2007.10.04增加)
	BYTE	reserved[22];											//保留字节
}DATAFORMAT21;

#pragma pack(1)														//按字节对齐数据
//****** 数据格式信息 32 bytes  (V2.2版本以上用)***********************************************************
typedef	struct	_DATAFORMAT{
	WORD	DataType;												//数据存储类型: char=01,int=02,unsigned long=03,float=04,double=05
	DWORD	TotalLines;												//数据总行数  .2008-01-23由WORD改为DWORD,同时版本号从V2.1 改为V2.2
	WORD	dataColAtRow;											//每行数据个数(不包括附加数据)
	WORD	appendColAtRow;											//每行中前导附加数据个数
	WORD	graduationBase;											//3代扫描分度起始号(2007.10.04增加)
	BYTE	reserved[20];											//保留字节
}DATAFORMAT;
//非标准V22数据格式
typedef	struct	_X22DATAFORMAT{
	WORD	DataType;												//数据存储类型: char=01,int=02,unsigned long=03,float=04,double=05
	DWORD	TotalLines;												//数据总行数  .2008-01-23由RORD改为DWORD,同时版本号从V2.1 改为V2.2
	WORD	dataColAtRow;											//每行数据个数(不包括附加数据)
	WORD	appendColAtRow;											//每行中前导附加数据个数
	WORD	graduationBase;											//3代扫描分度起始号(2007.10.04增加)
	BYTE	reserved[20];											//保留字节
}X22DATAFORMAT;
#pragma pack(8)														//按缺省值对齐数据

//****** 保留字节长度 *******************************************************************
#define	RESERVEDBYTES	2048-4-2-PWDLEN-sizeof(TASKMESSAGE)-sizeof(WORKPIECEMESSAGE)-sizeof(SCANPARAMETER)-sizeof(SYSTEMPARAMETER)-sizeof(RECONSTRUCTMESSAGE)-sizeof(IDENTIFYMESSAGE)-sizeof(DATAFORMAT)

//****** 头文件信息(V2.1版本使用) *********************************************************************
typedef	struct _ICT_HEADER21{
	BYTE				MainVersion;								//版本标识(主版本号: 0x02)
	BYTE				SubVersion;									//版本标识(次版本号: 0x01)
	BYTE				reserved1[2];								//保留
	TASKMESSAGE			Task;										//测试任务信息
	WORKPIECEMESSAGE	Workpiece;									//测试工件信息
	SCANPARAMETER		ScanParameter;								//扫描参数
	SYSTEMPARAMETER		SystemParameter;							//系统参数
	RECONSTRUCTMESSAGE	ReconstructParameter;						//重建参数
	IDENTIFYMESSAGE		IdentifyMessage;							//图像识别信息
	DATAFORMAT21		DataFormat;									//数据格式
	BYTE	       		reserved2[RESERVEDBYTES];					//保留(316)
	WORD				SizeofHeader;								//文件头尺寸: >2048(文件头尺寸为随机长度)
	BYTE				Password[PWDLEN];							//加密字符串
}ICT_HEADER21;


//****** 头文件信息 (V2.2版本使用)*********************************************************************
typedef	struct _ICT_HEADER22{
	BYTE				MainVersion;								//版本标识(主版本号: 0x02)
	BYTE				SubVersion;									//版本标识(次版本号: 0x02)
	BYTE				reserved1[2];								//保留
	TASKMESSAGE			Task;										//测试任务信息
	WORKPIECEMESSAGE	Workpiece;									//测试工件信息
	SCANPARAMETER		ScanParameter;								//扫描参数
	SYSTEMPARAMETER		SystemParameter;							//系统参数
	RECONSTRUCTMESSAGE	ReconstructParameter;						//重建参数
	IDENTIFYMESSAGE		IdentifyMessage;							//图像识别信息
	DATAFORMAT			DataFormat;									//数据格式
	BYTE	       		reserved2[RESERVEDBYTES];					//保留(316)
	WORD				SizeofHeader;								//文件头尺寸: >2048(文件头尺寸为随机长度)
	BYTE				Password[PWDLEN];							//加密字符串
}ICT_HEADER22;

//****** 保留字节长度 *******************************************************************
#define	RESERVEDBYTES23	2048-4-2-PWDLEN-sizeof(TASKMESSAGE)-sizeof(WORKPIECEMESSAGE23)-sizeof(SCANPARAMETER)-sizeof(SYSTEMPARAMETER)-sizeof(RECONSTRUCTMESSAGE)-sizeof(IDENTIFYMESSAGE)-sizeof(DATAFORMAT)
//****** 头文件信息 (V2.3版本使用)*********************************************************************
typedef	struct _ICT_HEADER{
	BYTE				MainVersion;								//版本标识(主版本号: 0x02)
	BYTE				SubVersion;									//版本标识(次版本号: 0x03)
	BYTE				reserved1[2];								//保留
	TASKMESSAGE			Task;										//测试任务信息
	WORKPIECEMESSAGE23	Workpiece;									//测试工件信息
	SCANPARAMETER		ScanParameter;								//扫描参数
	SYSTEMPARAMETER		SystemParameter;							//系统参数
	RECONSTRUCTMESSAGE	ReconstructParameter;						//重建参数
	IDENTIFYMESSAGE		IdentifyMessage;							//图像识别信息
	DATAFORMAT			DataFormat;									//数据格式
	BYTE	       		reserved2[RESERVEDBYTES];					//保留(316)
	WORD				SizeofHeader;								//文件头尺寸: >2048(文件头尺寸为随机长度)
	BYTE				Password[PWDLEN];							//加密字符串
}ICT_HEADER;

//****** 头文件信息 (V2.2版本使用---非标准)*********************************************************************
typedef	struct _X22ICT_HEADER{
	BYTE				MainVersion;								//版本标识(主版本号: 0x02)
	BYTE				SubVersion;									//版本标识(次版本号: 0x02)
	BYTE				reserved1[2];								//保留
	TASKMESSAGE			Task;										//测试任务信息
	WORKPIECEMESSAGE	Workpiece;									//测试工件信息
	SCANPARAMETER		ScanParameter;								//扫描参数
	SYSTEMPARAMETER		SystemParameter;							//系统参数
	RECONSTRUCTMESSAGE	ReconstructParameter;						//重建参数
	IDENTIFYMESSAGE		IdentifyMessage;							//图像识别信息
	X22DATAFORMAT		DataFormat;									//数据格式
	BYTE	       		reserved2[RESERVEDBYTES+sizeof(DATAFORMAT)-sizeof(X22DATAFORMAT)];//保留(316)
	WORD				SizeofHeader;								//文件头尺寸: >2048(文件头尺寸为随机长度)
	BYTE				Password[PWDLEN];							//加密字符串
}X22ICT_HEADER;

//螺旋CT扫描工件实际高度 = 扫描总层数*螺距
//文件头之后按照先行后列的顺序依次存放数据
//系统提供若干个动态库函数完成各部分信息的加密和解密
#endif
