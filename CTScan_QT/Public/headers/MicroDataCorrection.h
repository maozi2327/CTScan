/***********************************************************
函数名：_nCTCreateBKGData

定义：  创建暗场校正数据

入口参数：
////////////// 原始暗场数据文件只能有一个来源，另外一个赋值NULL ////////////////
unsigned short** pusBKGSrc :		原始暗场校正数据
char* pcBKGSrc :                    原始暗场校正数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

/////////// 生成后的暗场校正数据可以以数据输出，也可以以文件方式输出 ///////////
unsigned short* pusBKGDes :   暗场校正后的数据文件
char* pcBKGDes :              暗场校正后的数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下三个参数无效/////////////////////
int iLines_Input :					    校正源数据行数
int iCollums_Input :					校正源数据列数
int iFrames_Input :                     校正源数据帧数
////////////////////////////////////////////////////////////////////////////////

函数返回值：
int IRet :   0表示产生成功
***********************************************************/
int _nCTCreateBKGData
(
	unsigned short** pusBKGSrc,
	char* pcBKGSrc,
	unsigned short* pusBKGDes,
	char* pcBKGDes,
	int iLines_Input,
	int iCollums_Input,
	int iFrames_Input
);

/***********************************************************
函数名：_nCTCreateAIRData

定义：  创建空气校正参数文件

入口参数：
////////////// 原始空气数据文件只能有一个来源，另外一个赋值NULL ////////////////
unsigned short** pusAIRSrc :		原始空气校正数据
char* pcAIRSrc :                    原始空气校正数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

/////////// 生成后的空气校正数据可以以数据输出，也可以以文件方式输出 ///////////
float* pfAIRDes :				空气校正后的数据文件
char* pcAIRDes :				空气校正后的数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

///////// 已经生成的暗场校正数据可以以数据输入，也可以以文件方式输入 ///////////
unsigned short* pusBKG :			已经生成的暗场校正数据
char* pcBKG :					    已经生成的暗场校正数据文件
////////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下三个参数无效/////////////////////
int iLines_Input :					    校正源数据行数
int iCollums_Input :					校正源数据列数
int iFrames_Input :                     校正源数据帧数
////////////////////////////////////////////////////////////////////////////////

函数返回值：
int IRet :    0表示产生成功
***********************************************************/
int _nCTCreateAIRData
(
	unsigned short** pusAIRSrc,
	char* pcAIRSrc,
	float* pfAIRDes,
	char* pcAIRDes,
	unsigned short* pusBKG,
	char* pcBKG,
	int iLines_Input,
	int iCollums_Input,
	int iFrames_Input
);

/***********************************************************
函数名：_nCTCreateNonlinearAIRData

定义：  创建非线性空气校正数据

入口参数：
//////////// 原始非线性空气数据只能有一个来源，另外一个赋值NULL ////////////////
unsigned short** pusNLAIRSrc :  非线性空气校正源数据
char* pcNLAIRSrcFolder :        非线性空气校正源文件夹（若干TIFF文件）
////////////////////////////////////////////////////////////////////////////////

///////// 生成非线性空气校正数据可以以数据输出，也可以以文件方式输出 ////////////
float* pfNLAIRDes :		  非线性空气校正生成数据
char* pcNLAIRDes :        非线性空气校正生成文件（TIFF文件）
////////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下三个参数无效/////////////////////
int iLines_Input :					非线性空气校正源数据行数
int iCollums_Input :				非线性空气校正源数据列数
int iViews_Input :                  非线性空气校正源数据视角（文件）数
////////////////////////////////////////////////////////////////////////////////

int* piProgress :                   进度条值
int iProgressStart :				进度条起始值
int iProgressEnd :					进度条结束值

函数返回值：
	int IRet :    0表示产生成功
***********************************************************/
int _nCTCreateNonlinearAIRData
(
	unsigned short** pusNLAIRSrc,
	char* pcNLAIRSrcFolder,
	float* pfNLAIRDes,
	char* pcNLAIRDes,
	int iLines_Input,
	int iCollums_Input,
	int iFiles_Input,
	int* piProgress,
	int iProgressStart,
	int iProgressEnd
);

/***********************************************************
函数名：_nCTCreateDefectMap

定义：  创建坏像素地图，
        通过空气与背景数据，找到图像中的奇点，并标记为坏像素
		奇点确定规则：
		1.全部像素平均值上下浮动全局阈值以外的值作为奇点
		2.在排除以上奇点后，剩下区域的50 * 50局部区域内像素平均值上下浮动局部阈值的点作为奇点。

入口参数:
///////////// 暗场源数据只能有一个来源，另外一个赋值NULL //////////////////////
unsigned short* pusBKGSrc :	           暗场源数据
char* pcBKGSrc :					   暗场源文件
////////////////////////////////////////////////////////////////////////////////

double dBKGRatio :                     暗场数坏像素据比例阈值
								       0 - 1;

///////////// 亮场源数据只能有一个来源，另外一个赋值NULL //////////////////////
unsigned short* pusAIRSrc :	           亮场源数据
char* pcAIRSrc :					   亮场源文件
////////////////////////////////////////////////////////////////////////////////

double dAIRRatio :                     亮场数坏像素据比例阈值
									   0 - 1;

///////////// 生成坏像素地图可以以数据输出，也可以以文件方式输出 ///////////////
unsigned short* pusDefectMap :     生成坏像素地图数据
char* pcDefectMap :				   生成坏像素地图文件
////////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下两个参数无效/////////////////////
int iLines_Input :				   输入行数
int iCollums_Input :			   输入列数
////////////////////////////////////////////////////////////////////////////////

函数返回值:
int IRet :    0表示产生成功
***********************************************************/
int _nCTCreateDefectMap
(
	unsigned short* pusBKGSrc,
	char* pcBKGSrc,
	float fBKGRatio,
	unsigned short* pusAIRSrc,
	char* pcAIRSrc,
	float fAIRRatio,
	unsigned short* pusDefectMap,
	char* pcDefectMap,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTCreateDefectData

定义：  创建坏像素参数文件

入口参数:
////////////// 坏像素校正源数据只能有一个来源，另外一个赋值NULL ////////////////
unsigned short* pusDefectSrc :   坏像素校正源数据
char* pcDefectSrc :              坏像素校正源文件夹（若干TIFF文件）
////////////////////////////////////////////////////////////////////////////////

/////////// 生成坏像素校正数据可以以数据输出，也可以以文件方式输出 /////////////
void* pDefectDes :				生成坏像素校正数据
char* pcDefectDes :				生成坏像素校正数据全路径文件名
////////////////////////////////////////////////////////////////////////////////

int iLines_Input :				 坏像素校正源数据行数
int iCollums_Input :			 坏像素校正源数据列数

函数返回值:
int IRet :    0表示产生成功
***********************************************************/
int _nCTCreateDefectData
(
	unsigned short* pusDefectSrc,
	char* pcDefectSrc,
	void* pDefectDes,
	char* pcDefectDes,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTBKGCorrection

定义：  进行暗场校正

入口参数：
/////////////////原始数据文件只能有一个来源，另外一个赋值NULL///////////////////
unsigned short* pusSrcData :			原始数据文件
char* pcSrcData :                       原始数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

/////////// 暗场校正后的数据可以以数据输出，也可以以文件方式输出////////////////
unsigned short* pusSrcData_BKGCorr :   暗场校正后的数据文件
char* pcSrcData_BKGCorr :              暗场校正后的数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

///////////// 暗场校正数据可以以数据输出，也可以以文件方式输出//////////////////
unsigned short* pusBKGCorr :			暗场校正数据
char* pcBKGCorr :                       tiff格式的暗场校正文件
///////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下两个参数无效/////////////////////
int iLines_Input :					    源数据行数
int iCollums_Input :					源数据列数
////////////////////////////////////////////////////////////////////////////////

函数返回值：
int IRet :   0表示产生成功
***********************************************************/
int _nCTBKGCorrection
(
	unsigned short* pusSrcData,
	char* pcSrcData,
	unsigned short* pusSrcData_BKGCorr,
	char* pcSrcData_BKGCorr,
	unsigned short* pusBKGCorr,
	char* pcBKGCorr,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTAIRCorrection

定义：  进行空气校正

入口参数：
/////////////////原始数据文件只能有一个来源，另外一个赋值NULL///////////////////
unsigned short* pusSrcData :		原始数据文件
char* pcSrcData :                   原始数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

/////////// 空气校正后的数据可以以数据输出，也可以以文件方式输出////////////////
unsigned short* pusSrc_AIRCorr :    空气校正后的数据文件
char* pcSrc_AIRCorr :               空气校正后的数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

///////////// 空气校正数据可以以数据输出，也可以以文件方式输出//////////////////
float* pfAIRCorr :		空气校正数据
char* pcAIRCorr :       tiff格式的空气校正文件
///////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下两个参数无效/////////////////////
int iLines_Input :					    源数据行数
int iCollums_Input :					源数据列数
////////////////////////////////////////////////////////////////////////////////

函数返回值：
int IRet :   0表示产生成功
***********************************************************/
int _nCTAIRCorrection
(
	unsigned short* pusSrcData,
	char* pcSrcData,
	unsigned short* pusSrcData_AIRCorr,
	char* pcSrcData_AIRCorr,
	float* pfAIRCorr,
	char* pcAIRCorr,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTDefectCorrection

定义：  进行坏像素校正

入口参数：
/////////////////原始数据文件只能有一个来源，另外一个赋值NULL///////////////////
unsigned short* pusSrcData :			原始数据文件
char* pcSrcData :                       原始数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

/////////// 坏像素校正后的数据可以以数据输出，也可以以文件方式输出 //////////////
unsigned short* pusSrcData_DefectCorr :    坏像素校正后的数据文件
char* pcSrcData_DefectCorr :               坏像素校正后的数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

///////////// 坏像素校正数据可以以数据输出，也可以以文件方式输出////////////////
void* pDefectCorr :                坏像素校正数据
char* pcDefectCorr :               dat格式的坏像素校正文件
////////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下两个参数无效/////////////////////
int iLines_Input :					    源数据行数
int iCollums_Input :					源数据列数
////////////////////////////////////////////////////////////////////////////////

函数返回值：
int IRet :   0表示产生成功
***********************************************************/
int _nCTDefectCorrection
(
	unsigned short* pusSrcData,
	char* pcSrcData,
	unsigned short* pusSrcData_DefectCorr,
	char* pcSrcData_DefectCorr,
	void* pDefectCorr,
	char* pcDefectCorr,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTNonLinearAIRCorrection

定义：  进行非线性空气校正

入口参数：
/////////////////原始数据文件只能有一个来源，另外一个赋值NULL///////////////////
unsigned short* pusSrcData :			原始数据文件
char* pcSrcData :                       原始数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

///////// 非线性空气校正后的数据可以以数据输出，也可以以文件方式输出 ///////////
unsigned short* pusSrcData_NLAIRCorr :  非线性空气校正后的数据文件
char* pcSrcData_NLAIRCorr :             非线性空气校正后的数据文件路径全名
////////////////////////////////////////////////////////////////////////////////

//////////// 非线性空气校正数据可以以数据输出，也可以以文件方式输出/////////////
float* pfNLAIRCorr :                    非线性空气校正数据
char* pcNLAIRCorr :                     tiff格式的非线性空气校正文件
////////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下两个参数无效/////////////////////
int iLines_Input :					    源数据行数
int iCollums_Input :					源数据列数
////////////////////////////////////////////////////////////////////////////////

函数返回值：
int IRet :   0表示产生成功
***********************************************************/
int _nCTNonLinearAIRCorrection
(
	unsigned short* pusSrcData,
	char* pcSrcData,
	unsigned short* pusSrcData_NLAIRCorr,
	char* pcSrcData_NLAIRCorr,
	float* pfNLAIRCorr,
	char* pcNLAIRCorr,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTNonLinearAIRCorrectionFolder

定义：  进行批量非线性空气校正

入口参数：
	int* piProgress:						校正进度情况(0-100)
	char* pcSrcFolder :						原始数据文件夹路径全名
	char* pcSrcFolder_NonLinearAIRCorr :    非线性空气校正后的数据文件夹路径全名
	char* pcNonLinearAIRFile :				tiff格式的非线性空气校正文件

函数返回值：
	int IRet :   0表示产生成功
***********************************************************/
int _nCTNonLinearAIRCorrectionFolder
(
	int* piProgress,
	char* pcSrcFolder,
	char* pcSrcFolder_NonLinearAIRCorr,
	char* pcNonLinearAIRFile
);

/***********************************************************
函数名：_nCTBinModeProcess

定义：  按照bin模式合并像素
        该函数会将图片中的每个个BinHeight * BinWidth的区域合并为一个像素
		合并后的图像高度 DesHeight = SrcHeight / BinHeight
		合并后的图像宽度 DesWidth = SrcWidth  / BinWidth 
		DesHeight与DesWidth的小数位将被截断

入口参数：
/////////////////原始数据文件只能有一个来源，另外一个赋值NULL///////////////////
unsigned short* pusSrc :    数据格式的源数据
char* pcSrc :               文件格式的源数据
////////////////////////////////////////////////////////////////////////////////

//////////////// Bin模式数据可以以数据输出，也可以以文件方式输出////////////////
unsigned short* pusBinDes :	 bin模式输出内容（数据方式）			  
char* pcBinDes :			 bin模式输出内容（文件方式）
////////////////////////////////////////////////////////////////////////////////

/////////////////如果输入的源数据为文件，则以下两个参数无效/////////////////////
int iLines_Input :			 源数据行数
int iCollums_Input :		 源数据列数
////////////////////////////////////////////////////////////////////////////////

int iBinHeight :			 Bin模式的合并高度        
int iBinWidth :				 Bin模式的合并宽度

函数返回值：
int IRet :   0表示产生成功
***********************************************************/
int _nCTBinModeProcess
(
	unsigned short* pusSrc,
	char* pcSrc,
	unsigned short* pusBinDes,
	char* pcBinDes,
	int iLines_Input,
	int iCollums_Input,
	int iBinHeight,
	int iBinWidth
);

/***********************************************************
函数名：_nCTRotationProcess

定义：  进行旋转处理

入口参数：
//////////////// 原始数据文件只能有一个来源，另外一个赋值NULL //////////////////
unsigned short* pusSrc :			源数据
char* pcSrc :						源数据文件
////////////////////////////////////////////////////////////////////////////////

//////////////// 旋转数据可以以数据输出，也可以以文件方式输出 //////////////////
unsigned short* pusRotationDes :	旋转生成数据数据格式
char* pcRotationDes :				旋转生成数据文件格式
////////////////////////////////////////////////////////////////////////////////

int iRotationType :					旋转类型
									0--顺时针旋转
									1--逆时针旋转
									2--左右颠倒
									3--上下颠倒

////////////////// 该参数仅在旋转类型为顺时针，逆时针时有效 ////////////////////
int iRotationAngle :				旋转角度
									0--90度
									1--180度
									2--270度
////////////////////////////////////////////////////////////////////////////////

//////////////// 如果输入的源数据为文件，则以下两个参数无效 ////////////////////
int iLines_Input :					行数
int iCollums_Input :				列数
////////////////////////////////////////////////////////////////////////////////

函数返回值 :
int IRet :   0表示产生成功
***********************************************************/
int _nCTRotationProcess
(
	unsigned short* pusSrc,
	char* pcSrc,
	unsigned short* pusRotationDes,
	char* pcRotationDes,
	int iRotationType,
	int iRotationAngle,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTMergeFrames

定义：  进行帧合并处理

入口参数：
//////////////// 源数据文件只能有一个来源，另外一个赋值NULL ////////////////////
unsigned short** pusSrc :			源数据
									pusSrc[a][b]: a表示帧，b表示像素
char* pcSrc :						源数据文件
////////////////////////////////////////////////////////////////////////////////

///////////// 合并生成数据可以以数据输出，也可以以文件方式输出 /////////////////
unsigned short* pusMergeDes :	合并生成数据数据格式
char* pcMergeDes :				合并生成数据文件格式
////////////////////////////////////////////////////////////////////////////////

//////////////// 如果输入的源数据为文件，则以下两个参数无效 ////////////////////
int iFrames_Input :                 帧数
int iLines_Input :					行数
int iCollums_Input :				列数
////////////////////////////////////////////////////////////////////////////////

函数返回值 :
int IRet :   0表示产生成功
***********************************************************/
int _nCTMergeFrames
(
	unsigned short** pusSrc,
	char* pcSrc,
	unsigned short* pusMergeDes,
	char* pcMergeDes,
	int iFrames_Input,
	int iLines_Input,
	int iCollums_Input
);

/***********************************************************
函数名：_nCTAutoCenter

定义：  自动旋转中心计算

入口参数：
	float fSOD					：   当前SOD值
	float fSDD					：   当前SDD值
	float fSOD_N				：   SOD靠近射线源端的值
	float fSOD_F				：	 SOD远离射线源端的值
	float fSDD_N				：	 SDD靠近射线源端的值
	float fSDD_F				：   SDD远离射线源端的值
	float fCenter_SOD_N_SDD_N	：   当SOD为靠近射线源，SDD为靠近射线源的中心值
	float fCenter_SOD_N_SDD_F	：   当SOD为靠近射线源，SDD为远离射线源的中心值
	float fCenter_SOD_F_SDD_N	：	 当SOD为远离射线源，SDD为靠近射线源的中心值
	float fCenter_SOD_F_SDD_F	：	 当SOD为远离射线源，SDD为远离射线源的中心值
	float* pfCenter				：   计算出的当前旋转中心值

函数返回值：
	int IRet :   0表示产生成功
***********************************************************/
int _nCTAutoCenter
(
	float fSOD,
	float fSDD,
	float fSOD_N,
	float fSOD_F,
	float fSDD_N,
	float fSDD_F,
	float fCenter_SOD_N_SDD_N,
	float fCenter_SOD_N_SDD_F,
	float fCenter_SOD_F_SDD_N,
	float fCenter_SOD_F_SDD_F,
	float* pfCenter
);

/***********************************************************
函数名：_nCTViewFilter

定义：  进行分度图像滤波

入口参数：
	/////////////////原始数据文件只能有一个来源，另外一个赋值NULL///////////////////
	unsigned short* pusSrcData :				原始数据文件
	char* pcSrcData :							原始数据文件路径全名
	////////////////////////////////////////////////////////////////////////////////

	/////////// 滤波校正后的数据可以以数据输出，也可以以文件方式输出 //////////////
	unsigned short* pusSrcData_FilterCorr :     滤波校正后的数据文件
	char* pcSrcData_FilterCorr :                滤波校正后的数据文件路径全名
	////////////////////////////////////////////////////////////////////////////////

	/////////////////如果输入的源数据为文件，则以下两个参数无效/////////////////////
	int iLines_Input :							源数据行数
	int iCollums_Input :						源数据列数
	////////////////////////////////////////////////////////////////////////////////

函数返回值：
	int IRet :   0表示产生成功
***********************************************************/
int _nCTViewFilter
(
	unsigned short* pusSrcData,
	char* pcSrcData,
	unsigned short* pusSrcData_FilterCorr,
	char* pcSrcData_FilterCorr,
	int iLines_Input,
	int iCollums_Input
);

/*************************
面阵数据拼接

输入：
	char* pcPath_A ：             第一个CT原始数据文件夹路径
	char* pcPath_B ：             第二个CT原始数据文件夹路径
	char* pcSplicingPath ：       生成的拼接数据文件夹路径
	int* piProgress ：            进度值

返回值： 
	int IRet :   0表示产生成功
**************************/
int _nCTDataSplicing
(
	char* pcPath_A,
	char* pcPath_B,
	char* pcSplicingPath,
	int* piProgress
);
/***********************************************************
函数名：_nCTDataSplicing_Detector

定义：  面阵数据拼接(面阵移动)

输入：
char* pcPath_A ：        第一个CT原始数据文件夹路径
char* pcPath_B ：        第二个CT原始数据文件夹路径
char* pcSplicingPath ：  生成的拼接数据文件夹路径
int* piProgress ：       进度值

返回值：
int IRet :   0表示产生成功
***********************************************************/
int _nCTDataSplicing_Detector
	(
	char* pcPath_A,
	char* pcPath_B,
	char* pcSplicingPath,
	int* piProgress
	);