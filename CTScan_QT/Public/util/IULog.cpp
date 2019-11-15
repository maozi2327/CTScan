#include <QtCore>
#include "IULog.h"
#define MAX_LINE_LENGTH 256

LOG_LEVEL CIULog::d_logLevel = LOG_LEVEL::LOG_LEVEL_INFO;
QFile CIULog::d_logFile;
bool CIULog::Init(QString pszLogFileName)
{
    if (pszLogFileName.size() == 0)
		return false;

	int slashIndex  = pszLogFileName.lastIndexOf('\\');

	if (slashIndex == -1)
		return false;

	QString folderName = pszLogFileName.left(pszLogFileName.size() - slashIndex);
	QDir  logDir;

	if(logDir.mkpath(folderName) == false)
		return false;
		
	d_logFile.setFileName(pszLogFileName);
	d_logFile.open(QIODevice::ReadWrite);
	return true;
}

void CIULog::Uninit()
{
	d_logFile.close();
}

void CIULog::SetLevel(LOG_LEVEL nLevel)
{
    d_logLevel = nLevel;
}

bool CIULog::Log(LOG_LEVEL nLevel, char* pszFmt, ...)
{
    if (nLevel < d_logLevel)
        return false;
    
    char szTime[64] = { 0 };
    QString strDebugInfo(QDateTime::currentDateTime().toString("hh:mm:ss.zzz"));
	
	QString strLevel("[INFO]");
	strDebugInfo.append(strLevel);
	va_list ap;
	va_start(ap, pszFmt);
	QString apString;
	apString.sprintf(pszFmt, ap);
	strDebugInfo.append(apString);
	strDebugInfo += "\r\n";	
	d_logFile.seek(d_logFile.size());
	d_logFile.write(strDebugInfo.toLocal8Bit());
	d_logFile.flush();
    return true;
}

bool CIULog::Log(LOG_LEVEL nLevel, char* pszFunctionSig, int nLineNo, char* pszFmt, ...)
{
	if (nLevel < d_logLevel)
		return false;

	char szTime[64] = { 0 };
	QString strDebugInfo;
	strDebugInfo.sprintf("[%s: %d]", pszFunctionSig, nLineNo);
	strDebugInfo.append(QDateTime::currentDateTime().toString("hh:mm:ss.zzz"));

	QString strLevel("[INFO]");

	if (nLevel == LOG_LEVEL::LOG_LEVEL_WARNING)
		strLevel = "[Warning]";
	else if (nLevel == LOG_LEVEL::LOG_LEVEL_ERROR)
		strLevel = "[Error]";

	strDebugInfo.append(strLevel);
	va_list ap;
	va_start(ap, pszFmt);
	QString apString;
	apString.sprintf(pszFmt, ap);
	strDebugInfo.append(apString);
	strDebugInfo += "\r\n";
	d_logFile.seek(d_logFile.size());
	d_logFile.write(strDebugInfo.toLocal8Bit());
	d_logFile.flush();
	return true;
}

