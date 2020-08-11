#ifndef __CTDISPOSE_H
#define __CTDISPOSE_H


/********************************* 宏定义 ***********************************/
//定义16位校正操作使能字
#define	EN_BKGTUNE				0x0001		// 允许背景校正
#define	EN_AIRTUNE				0x0002		// 允许空气校正
#define	EN_SENSITIVE			0x0004		// 允许灵敏度校正（一致性校正）
#define	EN_RANGE				0x0008		// 允许动态范围校正
#define	EN_CROSSTALK			0x0010		// 允许串扰校正
#define	EN_PULSEDOSE			0x0020		// 允许单脉冲剂量校正
#define	EN_HARDEN				0x0040		// 允许硬化校正
#define	EN_ABNORMALDETECTOR 	0x0080		// 允许处理异常探测器
#define EN_MOVETWOPIXELS        0x0100      // 允许使用多扫的CT分度来进行一致性校正
#define EN_DEFECT               0x0200      // 允许进行坏像素校正
#define EN_DOSEDOWN             0x0400      // 允许射线掉束校正
#define	EN_SAVEEXTORG			0x8000		// 允许保存处理后的原始数据
 
//定义函数返回代码
#define	SUCCESS					0			// 成功
#define	ERR_NO_FILE				1			// 文件不存在
#define	ERR_IN_FILEHEAD	    	2			// 文件头错误(尺寸不匹配)
#define	ERR_NO_DATA				3			// 文件无数据
#define	ERR_DATA				4			// 数据错误
#define	ERR_UNFINISH			5			// 数据处理失败(未完成)
#define	ERR_OPEN_FILE			6			// 打开新文件错误
#define	ERR_WRITE_FILE			7			// 写文件错误
#define	ERR_DATA_SORT			8			// 排序错(数据不足)
#define	ERR_IN_MEMORY			9			// 内存分配错误
#define	ERR_OPEN_BKG_FILE		10			// 本底数据文件不存在
#define	ERR_BKG_DATA			11			// 本底数据文件错误
#define	ERR_OPEN_AIR_FILE		12			// 空气系数文件不存在
#define	ERR_AIR_DATA			13			// 空气系数文件错误
#define	ERR_SCAN_MODE			14			// 无效扫描方式
#define	ERR_INTERP_TUNE_fI	    15		   	// 插值校正失败,第一个插值点无数据
#define	ERR_INTERP_TUNE_lI	    16		    // 插值校正失败,最后一个插值点无数据
#define	ERR_INTERP_TUNE_0AVE	17			// 插值校正失败,探测器数据均值出现0
#define	ERR_IN_FILEFORMAT		18			// 文件版本或格式错误
#define	ERR_IN_COLLIMATE		19			// 准直孔代号错误
#define	ERR_IN_RANGE_TUNE		20			// 动态范围校正失败(扫描方式不匹配，未校正)
#define	ERR_IN_BIAS				21			// 动态范围校正失败(校正探测器数据方差太大或均值太小)
#define	ERR_IN_MEAN				22			// 剂量校正失败(校正探测器数据均值太小)
#define	ERR_UPDATE_BKG			23			// 本底数据错误,未更新
#define	ERR_OPEN_HD_FILE		24			// 硬化校正系数文件不存在
#define	ERR_HD_DATA				25			// 硬化校正系数数据文件错误
#define	ERR_IN_DATAFORMAT		26			// 数据格式错误
#define	ERR_IN_FdNORMAL	    	27			// 分度规范化
#define	ERR_IN_FdSERIAL	    	28			// 分度序号规范化
#define	ERR_IN_SCANMODE	    	41			// 不支持该扫描方式(旋转中心确定)
#define	ERR_IN_SCANRANGE	    42			// 不支持该扫描范围(旋转中心确定)
#define ERR_IN_DATA_GRA         43          // 分度出现错误
#define ERR_IN_PARAMETER        44          // 入参错误
#define ERR_IN_FUNC             45          // 内部函数出现错误

#define	MAX_DATA		1000000				// 探测器最大数据(10^6)
#define	MIN_DATA		1000				// 探测器最小数据
#define	MAX_SQR_BIAS	100					// 判断探测器是否被遮挡的方差限
#define MAX_DELTA       3                   // 判断是否到达了跳跃点
#define	PASSWORD		1					// 写数据文件加密开关(为1时加密, 为0时不加密)
#define	COEFF_FLAG	    0xa55a				// 系数文件头标志

#define DATA_MIN        100                 // 数据最小值

const char dSzResult[][128] = 
{
	"成功",									// 0
	"文件不存在",
	"文件头错误(尺寸不匹配)",
	"文件无数据",
	"数据错误",
	"数据处理失败(未完成)",
	"打开新文件错误",
	"写文件错误",
	"排序错(数据不足)",
	"内存分配错误",

	"本底数据文件不存在",									// 10
	"本底数据文件错误",
	"空气系数文件不存在",
	"空气系数文件错误",
	"无效扫描方式",
	"插值校正失败,第一个插值点无数据",
	"插值校正失败,最后一个插值点无数据",
	"插值校正失败,探测器数据均值出现0",
	"文件格式错误",
	"准直孔代号错误",

	"动态范围校正失败(扫描方式不匹配，未校正)",				// 20
	"动态范围校正失败(校正探测器数据方差太大或均值太小)",
	"剂量校正失败(校正探测器数据均值太小)",
	"本底数据错误,未更新",
	"硬化校正系数文件不存在",
	"硬化校正系数数据文件错误",								// 26
	"分度规范化",											// 27
	"",
	"",
	"",

	"函数输入参数错误",										// 30
	"无效文件名",											// 32
	"文件头版本无效",										// 33  
	"文件数据错误",											// 34
	"未按顺序调用函数",										// 35
	"无效链表指针"											// 36
	"申请内存失败",
	"数据不足",
	"",
	"",

	"",														// 40
	"不支持该扫描方式",										// 41
	"不支持该扫描范围",										// 42
	"分度出现错误",                                         // 43
	"函数入参错误"                                          // 44
};

/********************************* 结构体 ***********************************/
//定义系数文件头格式
typedef	struct _Coefficient
{
	WORD nFlag;
	WORD nType;
	WORD nRow;
	WORD nCol;
}Coefficient;

/********************************************************************************
函数名：fDataDispose

定义：  数据校正

入口参数：
	char *pcSys  :		 系统路径（文件夹）
	char *pcSrcFile  :   源文件路径
	char *pcDesFolder  : 目标文件的文件夹路径
	char *pcDesFile  :   目标文件的文件路径全名（用于输出）
	WORD operate :       操作使能字

函数返回值：
	0			:	 处理成功
	其他		:	 错误代码
*********************************************************************************/
int fDataDispose
(
	char *pcSys,
	char *pcSrcFile,
	char *pcDesFolder,
	char *pcDesFile,
	WORD wOperate
);

/********************************************************************************
函数名：fDataDispose_Linear

定义：  数据校正
		直线运动插值

入口参数：
	char *pcSys  :		 系统路径（文件夹）
	char *pcSrcFile  :   源文件路径
	char *pcDesFolder  : 目标文件的文件夹路径
	char *pcDesFile  :   目标文件的文件路径全名（用于输出）
	WORD operate :       操作使能字

函数返回值：
	0			:	 处理成功
	其他		:	 错误代码
*********************************************************************************/
int fDataDispose_Linear
(
	char *pcSys,
	char *pcSrcFile,
	char *pcDesFolder,
	char *pcDesFile,
	WORD wOperate
);

/********************************************************************************
函数名：fCreateBkgData

定义：  生成暗场校正数据

入口参数：
	char *pcSys  :	   系统文件夹路径
	char *pcSrc  :     源文件路径

函数返回值：
	0			:	   处理成功
	其他		:	   错误代码
*********************************************************************************/
int fCreateBkgData
(
	char *pcSys,
	char *pcSrc
);

/********************************************************************************
函数名：fCreateAirRatio

定义：  生成空气校正数据

入口参数：
	char *pcSys  :		系统文件夹路径
	char *pcSrc   :     源文件路径

函数返回值：
	0			:	处理成功	
    其他		:	错误代码
*********************************************************************************/
int fCreateAirRatio
(
	char *pcSys, 
	char *pcSrc
);

/********************************************************************************
函数名：fCreateAirRatio_Linear

定义：  生成空气校正数据
		直线运动插值

入口参数：
	char *pcSys			:	系统文件夹路径
	char *pcSrcFolder   :	源文件路径文件夹
							该文件夹内的空气文件依据插值顺序命名位：
							AIR_000.ORG
							AIR_001.ORG
							....
	int iInterpolation  :   插值次数

函数返回值：
	0			:		处理成功
	其他		:		错误代码
*********************************************************************************/
int fCreateAirRatio_Linear
(
	char *pcSys,
	char *pcSrcFolder,
	int iInterpolation
);

/********************************************************************************
函数名：saveOrgHeaderAndList

定义：  将文件头和链表中数据加密后保存到文件中
        生成ORG数据
		控制使用的代码，用于保存为ORG，不要修改

入口参数：
	char *pcDesFile ： 目标生成文件名
	void *pHeader ：   文件头指针
	void *pListItem ： 文件数据指针
	int iPw ：         加密标识
					   如果pw为1, 保存的是加密后的数据, 原链表中的数据已经加密.
				       如果pw为0, 保存的数据未加密.

函数返回值：
	0			:	处理成功
	其他		:	错误代码
*********************************************************************************/
int saveOrgHeaderAndList
(
	char *pcDesFile,
	void *pHeader,
	void *pListItem,
	int iPw
);

/********************************************************************************
函数名：DR2BMP

定义：  

入口参数：
	char *pcDRSrc ： DR文件路径全名

函数返回值：
	0			:	处理成功
	其他		:	错误代码
*********************************************************************************/
int DR2BMP(char *pcDRSrc);

#endif
