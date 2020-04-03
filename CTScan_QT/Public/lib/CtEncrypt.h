#ifndef __CTENCRYPT_H
#define __CTENCRYPT_H


#include "GlobalVal.h"

#define	SUCCESS					0						//成功
#define	ERR_OPEN_FILE			6						//打开新文件错误
#define	ERR_INPUT_PARAMETER	    30						//函数输入参数错误
#define	ERR_INVALID_FILENAME	31						//无效文件名
#define	ERR_INVALID_VERSION	    32						//文件头版本无效
#define	ERR_DATA_IN_FILE		33						//文件数据错误
#define	ERR_NOCALL_FSEQUENCE	34						//未按顺序调用函数
#define	ERR_INVALID_LIST		35						//无效链表指针
#define	ERR_INVALID_MEMORY	    36						//申请内存失败
#define	ERR_NOENOUGH_DATA		37						//数据不足

using namespace std;

/********************************************************************************
函数名：EncryptHeader

定义：  加密CT数据文件头

入口参数：
	shared_ptr<ICT_HEADER23> pInHeader ： 入文件头
	shared_ptr<BYTE> &pEnHeader ：        加密后的文件头
	WORD &wSize ：						  加密后的文件头尺寸

函数返回值：
	0		:	处理成功
	其他	:	错误代码
*********************************************************************************/
int EncryptHeader
(
	shared_ptr<ICT_HEADER23> pInHeader,
	shared_ptr<BYTE> &pEnHeader,
	WORD &wSize
);

/********************************************************************************
函数名：EncryptItemContent

定义：  加密CT数据文件

入口参数：
	shared_ptr<BYTE> pbItemContent ： 加密数据内容
	shared_ptr<BYTE> pbPassword ：    密码
	int iContentSize ：               数据长度

函数返回值：
	0		:	处理成功
	其他	:	错误代码
*********************************************************************************/
int EncryptItemContent
(
	WORD &wEnCount,
	shared_ptr<BYTE> pbItemContent,
	shared_ptr<BYTE> pbPassword,
	int iContentSize
);

/********************************************************************************
函数名：unchainHeader

定义：  解密CT数据文件头

入口参数：
	shared_ptr<BYTE> pEnHeader ：       加密数据头
	shared_ptr<ICT_HEADER23> pHeader ： 解密数据头
	WORD &wSize ：                      加密数据头大小

函数返回值：
	0			:	 处理成功
	其他		:	 错误代码
*********************************************************************************/
int UnchainHeader
(
	shared_ptr<BYTE> pEnHeader,
	shared_ptr<ICT_HEADER23> pHeader,
	WORD &wSize
);

/********************************************************************************
函数名：EncryptDataFromBuf

定义：  加密缓冲区中的CT数据
		算法 y=x^K0 + Kj (j=0-127[密码长度为128], j初值取dNpwdj)

入口参数：
	shared_ptr<BYTE> pBuf ：       数据缓冲区
	shared_ptr<BYTE> pbPassword ： 密码
	ULONG nBytes ：                数据长度（字节型）

函数返回值：
	0			:	 处理成功
	其他		:	 错误代码
*********************************************************************************/
int EncryptDataFromBuf
(
	shared_ptr<BYTE> pBuf,
	shared_ptr<BYTE> pbPassword,
	ULONG nBytes
);

/********************************************************************************
函数名：unchainData

定义：  解密数据

入口参数：
	shared_ptr<GlobalVal> pGVal ：全局变量指针

函数返回值：
	0			:	 处理成功
	其他		:	 错误代码
*********************************************************************************/
int UnchainData(std::shared_ptr<GlobalVal> pGVal);

/********************************************************************************
函数名：convertHead21To22

定义：  将原Ver2.1版文件头转换为Ver2.2格式

入口参数：
	shared_ptr<ICT_HEADER23> pHeader  :	  文件头

函数返回值：

*********************************************************************************/
void convertHead21To22(shared_ptr<ICT_HEADER23> pHeader);

/********************************************************************************
函数名：convertHead22To23

定义：  将原Ver2.2版文件头转换为Ver2.3格式

入口参数：
	shared_ptr<ICT_HEADER23> pHeader  :	  文件头

函数返回值：

*********************************************************************************/
void convertHead22To23(shared_ptr<ICT_HEADER23> pHeader);

/********************************************************************************
函数名：InitItemEncrypt

定义：  ORG数据项加密初始化

入口参数：
	WORD &wEnCount ：				  加密计数

函数返回值：

*********************************************************************************/
void InitItemEncrypt(WORD &wEnCount);












/***************************************************************************/
/************* 为保证老版本代码能够正常使用，提供以下接口 ******************/
/***************************************************************************/
#ifdef CTDISPOSE_EXPORTS
#define CTDISPOSE_API __declspec(dllexport)
#else
#define CTDISPOSE_API __declspec(dllimport)
#endif

/********************************************************************************
函数名：encryptHeader

定义：  加密CT数据文件头（老版本接口封装）

入口参数：
	void *srcHead ：     待加密文件头的指针
	int *nRet ：		 函数返回结果指针(成功时返回0, 否则返回错误代号)
	WORD *Size ：        加密后文件头字节数存放指针

函数返回值：
	void* pRet ：        调用失败时返回NULL，
	                     调用成功时返回加密后的文件头指针
*********************************************************************************/
extern "C" CTDISPOSE_API void* encryptHeader
(
	void *srcHead, 
	int *nRet, 
	WORD *Size
);

/********************************************************************************
函数名：unchainHeader

定义：  解密CT数据文件头（老版本接口封装）

入口参数：
	void *srcHead ：     待解密的文件头指针
	int *nRet ：		 函数返回结果指针(成功时返回0, 否则返回错误代号)
	WORD *Size ：        解密后文件头字节数存放指针

函数返回值：
	void* pRet ：        调用失败时返回NULL，
						 调用成功时返回解密后的文件头指针
*********************************************************************************/
extern "C" CTDISPOSE_API void* unchainHeader
(
	void *srcHead, 
	int *nRet, 
	WORD *Size
);

/********************************************************************************
函数名：releaseHeadBuf

定义：  释放调用encryptHeader(..)/unchainHeader(..)
        函数后的缓冲区（老版本接口封装）

入口参数：

函数返回值：

*********************************************************************************/
extern "C" CTDISPOSE_API void releaseHeadBuf();

/********************************************************************************
函数名：encryptDataFromBuf

定义：  加密缓冲区中的CT数据（老版本接口封装）

入口参数：
	void *dataBuf ：		待加密数据缓冲区指针
	ULONG nBytes ：			待加密数据字节数

函数返回值：
	iRet ： 成功时返回0
*********************************************************************************/
extern "C" CTDISPOSE_API int encryptDataFromBuf
(
	void *dataBuf,
	ULONG nBytes
);

/********************************************************************************
函数名：unchainDataToBuf

定义：  解密缓冲区中的CT数据（老版本接口封装）

入口参数：
	void *dataBuf ：		待解密数据缓冲区指针
	ULONG nBytes ：			待解密数据字节数

函数返回值：
	iRet ： 成功时返回0
*********************************************************************************/
extern "C" CTDISPOSE_API int unchainDataToBuf
(
	void *dataBuf,
	ULONG nBytes
);

/********************************************************************************
函数名：InitDataUnchain

定义：  初始化数据解密（老版本接口封装）
		初始化后的链表加密用全局变量中

入口参数：

函数返回值：
	
*********************************************************************************/
extern "C" CTDISPOSE_API void InitDataUnchain();

/********************************************************************************
函数名：UnchainNBytesData

定义：  解密缓冲区中的N字节数据（老版本接口封装）
		
入口参数：
	void *dataBuf ：		待解密数据缓冲区指针
	ULONG nBytes ：			待解密数据字节数

函数返回值：

*********************************************************************************/
extern "C" CTDISPOSE_API void UnchainNBytesData
(
	void *dataBuf, 
	ULONG nBytes
);




#endif


