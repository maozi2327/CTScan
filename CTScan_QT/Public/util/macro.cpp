#include "stdafx.h"
#include "macro.h"

QString makeMessage(const char* pszFmt, ...)
{
	QString firstPar;
	firstPar.fromLocal8Bit(pszFmt);
	QByteArray byteArr = firstPar.toUtf8();
	QString msg;
	va_list ap;
	va_start(ap, pszFmt);
	msg.sprintf(byteArr.data(), ap);
	va_end(ap);
	return msg;
}