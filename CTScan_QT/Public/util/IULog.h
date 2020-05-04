#pragma once
#include <QFile>
#include <QString>

enum class LOG_LEVEL
{
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
};

//e.g. LOG_INFO(_T("GroupID=%u, GroupName=%s, GroupName=%s."), lpGroupInfo->d_nGroupCode, lpGroupInfo->d_strAccount.c_str(), lpGroupInfo->d_strName.c_str());
#define LOG_INFO(info)     CIULog::Log(LOG_LEVEL::LOG_LEVEL_INFO, info)
#define LOG_WARNING(warning)    CIULog::Log(LOG_LEVEL::LOG_LEVEL_WARNING, __FUNCSIG__, __LINE__, warning)
#define LOG_ERROR(error)      CIULog::Log(LOG_LEVEL::LOG_LEVEL_ERROR, __FUNCSIG__,__LINE__, error)

class CIULog
{
public:
    static bool Init(QString& pszLogFileName);
	static void Uninit();

    static void SetLevel(LOG_LEVEL nLevel);
	
	//不输出线程ID号和所在函数签名、行号
	static bool Log(LOG_LEVEL nLevel, QString& pszFmt);
	//输出线程ID号和所在函数签名、行号
	static bool Log(LOG_LEVEL nLevel, char* pszFunctionSig, int nLineNo, QString& pszFmt);
private:
    CIULog() = delete;
    ~CIULog() = delete;

    CIULog(const CIULog& rhs) = delete;
    CIULog& operator=(const CIULog& rhs) = delete;
	
private:
	static QFile d_logFile;
    static LOG_LEVEL d_logLevel;            //日志级别
};