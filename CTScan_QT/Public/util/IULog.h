#ifndef __LOG_H__
#define __LOG_H__

#define LOG_API
#include <QFile>
enum class LOG_LEVEL
{
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
};

//注意：如果打印的日志信息中有中文，则格式化字符串要用_T()宏包裹起来，
//e.g. LOG_INFO(_T("GroupID=%u, GroupName=%s, GroupName=%s."), lpGroupInfo->d_nGroupCode, lpGroupInfo->d_strAccount.c_str(), lpGroupInfo->d_strName.c_str());
#define LOG_INFO(...)     CIULog::Log(LOG_LEVEL::LOG_LEVEL_INFO, __VA_ARGS__)
#define LOG_WARNING(...)    CIULog::Log(LOG_LEVEL::LOG_LEVEL_WARNING, __FUNCSIG__, __LINE__,__VA_ARGS__)
#define LOG_ERROR(...)      CIULog::Log(LOG_LEVEL::LOG_LEVEL_ERROR, __FUNCSIG__,__LINE__, __VA_ARGS__)

class LOG_API CIULog
{
public:
    static bool Init(QString pszLogFileName);
	static void Uninit();

    static void SetLevel(LOG_LEVEL nLevel);
	
	//不输出线程ID号和所在函数签名、行号
	static bool Log(LOG_LEVEL nLevel, char* pszFmt, ...);
	//输出线程ID号和所在函数签名、行号
	static bool Log(LOG_LEVEL nLevel, char* pszFunctionSig, int nLineNo, char* pszFmt, ...);
private:
    CIULog() = delete;
    ~CIULog() = delete;

    CIULog(const CIULog& rhs) = delete;
    CIULog& operator=(const CIULog& rhs) = delete;
	
private:
	static QFile d_logFile;
    static LOG_LEVEL d_logLevel;            //日志级别
};

#endif // !__LOG_H__