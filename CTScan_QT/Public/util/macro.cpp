#include "macro.h"

QString makeMessage(const char* pszFmt, ...)
{
	QString firstPare;
	firstPare.fromLocal8Bit(pszFmt);
	QByteArray byteArr = firstPare.toUtf8();
	QString msg;
	va_list ap;
	va_start(ap, pszFmt);
	msg.sprintf(byteArr.data(), ap);
	va_end(ap);
	return msg;
}