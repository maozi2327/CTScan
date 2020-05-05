#pragma once
#define LOGSIGNAL	void infoMsgSignal(QString info);\
					void errorMsgSignal(QString error);\
					void bugMsgSignal(QString bug);

#define LOG_ERROR(MSG) emit(errorMsgSignal(QString("[") + MSG + ']' + \
	'[' + QString(__FUNCSIG__) + ']' + '[' + QString::number(__LINE__) + ']'));