#pragma once
#include <QString>
#define LOGSIGNAL	void infoMsgSignal(QString info);\
					void errorMsgSignal(QString error);\
					void bugMsgSignal(QString bug);

#define LOG_ERROR(MSG) emit(errorMsgSignal(QString("[") + MSG + ']' + \
	'[' + QString(__FUNCSIG__) + ']' + '[' + QString::number(__LINE__) + ']'))

#define LOG_BUG(MSG) emit(errorMsgSignal(QString("[") + MSG + ']' + \
	'[' + QString(__FUNCSIG__) + ']' + '[' + QString::number(__LINE__) + ']'))

#define LOG_INFO(MSG) emit(errorMsgSignal(QString("[") + MSG + ']'))

QString makeMessage(const char* pszFmt, ...);