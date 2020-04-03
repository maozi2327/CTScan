#ifndef __CTENCRYPT_H
#define __CTENCRYPT_H


#include "GlobalVal.h"

#define	SUCCESS					0						//�ɹ�
#define	ERR_OPEN_FILE			6						//�����ļ�����
#define	ERR_INPUT_PARAMETER	    30						//���������������
#define	ERR_INVALID_FILENAME	31						//��Ч�ļ���
#define	ERR_INVALID_VERSION	    32						//�ļ�ͷ�汾��Ч
#define	ERR_DATA_IN_FILE		33						//�ļ����ݴ���
#define	ERR_NOCALL_FSEQUENCE	34						//δ��˳����ú���
#define	ERR_INVALID_LIST		35						//��Ч����ָ��
#define	ERR_INVALID_MEMORY	    36						//�����ڴ�ʧ��
#define	ERR_NOENOUGH_DATA		37						//���ݲ���

using namespace std;

/********************************************************************************
��������EncryptHeader

���壺  ����CT�����ļ�ͷ

��ڲ�����
	shared_ptr<ICT_HEADER23> pInHeader �� ���ļ�ͷ
	shared_ptr<BYTE> &pEnHeader ��        ���ܺ���ļ�ͷ
	WORD &wSize ��						  ���ܺ���ļ�ͷ�ߴ�

��������ֵ��
	0		:	����ɹ�
	����	:	�������
*********************************************************************************/
int EncryptHeader
(
	shared_ptr<ICT_HEADER23> pInHeader,
	shared_ptr<BYTE> &pEnHeader,
	WORD &wSize
);

/********************************************************************************
��������EncryptItemContent

���壺  ����CT�����ļ�

��ڲ�����
	shared_ptr<BYTE> pbItemContent �� ������������
	shared_ptr<BYTE> pbPassword ��    ����
	int iContentSize ��               ���ݳ���

��������ֵ��
	0		:	����ɹ�
	����	:	�������
*********************************************************************************/
int EncryptItemContent
(
	WORD &wEnCount,
	shared_ptr<BYTE> pbItemContent,
	shared_ptr<BYTE> pbPassword,
	int iContentSize
);

/********************************************************************************
��������unchainHeader

���壺  ����CT�����ļ�ͷ

��ڲ�����
	shared_ptr<BYTE> pEnHeader ��       ��������ͷ
	shared_ptr<ICT_HEADER23> pHeader �� ��������ͷ
	WORD &wSize ��                      ��������ͷ��С

��������ֵ��
	0			:	 ����ɹ�
	����		:	 �������
*********************************************************************************/
int UnchainHeader
(
	shared_ptr<BYTE> pEnHeader,
	shared_ptr<ICT_HEADER23> pHeader,
	WORD &wSize
);

/********************************************************************************
��������EncryptDataFromBuf

���壺  ���ܻ������е�CT����
		�㷨 y=x^K0 + Kj (j=0-127[���볤��Ϊ128], j��ֵȡdNpwdj)

��ڲ�����
	shared_ptr<BYTE> pBuf ��       ���ݻ�����
	shared_ptr<BYTE> pbPassword �� ����
	ULONG nBytes ��                ���ݳ��ȣ��ֽ��ͣ�

��������ֵ��
	0			:	 ����ɹ�
	����		:	 �������
*********************************************************************************/
int EncryptDataFromBuf
(
	shared_ptr<BYTE> pBuf,
	shared_ptr<BYTE> pbPassword,
	ULONG nBytes
);

/********************************************************************************
��������unchainData

���壺  ��������

��ڲ�����
	shared_ptr<GlobalVal> pGVal ��ȫ�ֱ���ָ��

��������ֵ��
	0			:	 ����ɹ�
	����		:	 �������
*********************************************************************************/
int UnchainData(std::shared_ptr<GlobalVal> pGVal);

/********************************************************************************
��������convertHead21To22

���壺  ��ԭVer2.1���ļ�ͷת��ΪVer2.2��ʽ

��ڲ�����
	shared_ptr<ICT_HEADER23> pHeader  :	  �ļ�ͷ

��������ֵ��

*********************************************************************************/
void convertHead21To22(shared_ptr<ICT_HEADER23> pHeader);

/********************************************************************************
��������convertHead22To23

���壺  ��ԭVer2.2���ļ�ͷת��ΪVer2.3��ʽ

��ڲ�����
	shared_ptr<ICT_HEADER23> pHeader  :	  �ļ�ͷ

��������ֵ��

*********************************************************************************/
void convertHead22To23(shared_ptr<ICT_HEADER23> pHeader);

/********************************************************************************
��������InitItemEncrypt

���壺  ORG��������ܳ�ʼ��

��ڲ�����
	WORD &wEnCount ��				  ���ܼ���

��������ֵ��

*********************************************************************************/
void InitItemEncrypt(WORD &wEnCount);












/***************************************************************************/
/************* Ϊ��֤�ϰ汾�����ܹ�����ʹ�ã��ṩ���½ӿ� ******************/
/***************************************************************************/
#ifdef CTDISPOSE_EXPORTS
#define CTDISPOSE_API __declspec(dllexport)
#else
#define CTDISPOSE_API __declspec(dllimport)
#endif

/********************************************************************************
��������encryptHeader

���壺  ����CT�����ļ�ͷ���ϰ汾�ӿڷ�װ��

��ڲ�����
	void *srcHead ��     �������ļ�ͷ��ָ��
	int *nRet ��		 �������ؽ��ָ��(�ɹ�ʱ����0, ���򷵻ش������)
	WORD *Size ��        ���ܺ��ļ�ͷ�ֽ������ָ��

��������ֵ��
	void* pRet ��        ����ʧ��ʱ����NULL��
	                     ���óɹ�ʱ���ؼ��ܺ���ļ�ͷָ��
*********************************************************************************/
extern "C" CTDISPOSE_API void* encryptHeader
(
	void *srcHead, 
	int *nRet, 
	WORD *Size
);

/********************************************************************************
��������unchainHeader

���壺  ����CT�����ļ�ͷ���ϰ汾�ӿڷ�װ��

��ڲ�����
	void *srcHead ��     �����ܵ��ļ�ͷָ��
	int *nRet ��		 �������ؽ��ָ��(�ɹ�ʱ����0, ���򷵻ش������)
	WORD *Size ��        ���ܺ��ļ�ͷ�ֽ������ָ��

��������ֵ��
	void* pRet ��        ����ʧ��ʱ����NULL��
						 ���óɹ�ʱ���ؽ��ܺ���ļ�ͷָ��
*********************************************************************************/
extern "C" CTDISPOSE_API void* unchainHeader
(
	void *srcHead, 
	int *nRet, 
	WORD *Size
);

/********************************************************************************
��������releaseHeadBuf

���壺  �ͷŵ���encryptHeader(..)/unchainHeader(..)
        ������Ļ��������ϰ汾�ӿڷ�װ��

��ڲ�����

��������ֵ��

*********************************************************************************/
extern "C" CTDISPOSE_API void releaseHeadBuf();

/********************************************************************************
��������encryptDataFromBuf

���壺  ���ܻ������е�CT���ݣ��ϰ汾�ӿڷ�װ��

��ڲ�����
	void *dataBuf ��		���������ݻ�����ָ��
	ULONG nBytes ��			�����������ֽ���

��������ֵ��
	iRet �� �ɹ�ʱ����0
*********************************************************************************/
extern "C" CTDISPOSE_API int encryptDataFromBuf
(
	void *dataBuf,
	ULONG nBytes
);

/********************************************************************************
��������unchainDataToBuf

���壺  ���ܻ������е�CT���ݣ��ϰ汾�ӿڷ�װ��

��ڲ�����
	void *dataBuf ��		���������ݻ�����ָ��
	ULONG nBytes ��			�����������ֽ���

��������ֵ��
	iRet �� �ɹ�ʱ����0
*********************************************************************************/
extern "C" CTDISPOSE_API int unchainDataToBuf
(
	void *dataBuf,
	ULONG nBytes
);

/********************************************************************************
��������InitDataUnchain

���壺  ��ʼ�����ݽ��ܣ��ϰ汾�ӿڷ�װ��
		��ʼ��������������ȫ�ֱ�����

��ڲ�����

��������ֵ��
	
*********************************************************************************/
extern "C" CTDISPOSE_API void InitDataUnchain();

/********************************************************************************
��������UnchainNBytesData

���壺  ���ܻ������е�N�ֽ����ݣ��ϰ汾�ӿڷ�װ��
		
��ڲ�����
	void *dataBuf ��		���������ݻ�����ָ��
	ULONG nBytes ��			�����������ֽ���

��������ֵ��

*********************************************************************************/
extern "C" CTDISPOSE_API void UnchainNBytesData
(
	void *dataBuf, 
	ULONG nBytes
);




#endif


