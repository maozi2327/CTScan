#pragma once
#include <QFile>
#include <QString>

enum class LOG_LEVEL
{
    LOG_LEVEL_INFO,
    LOG_LEVEL_ERROR,
	LOG_LEVEL_BUG,
};

//e.g. LOG_INFO(_T("GroupID=%u, GroupName=%s, GroupName=%s."), lpGroupInfo->d_nGroupCode, lpGroupInfo->d_strAccount.c_str(), lpGroupInfo->d_strName.c_str());


class CIULog
{
public:
    static bool Init(QString& pszLogFileName);
	static void Uninit();

    static void SetLevel(LOG_LEVEL nLevel);
	
	//������߳�ID�ź����ں���ǩ�����к�
	//static bool Log(LOG_LEVEL nLevel, QString& pszFmt);
	//����߳�ID�ź����ں���ǩ�����к�
	static bool Log(LOG_LEVEL nLevel, QString& pszFmt);
private:
    CIULog() = delete;
    ~CIULog() = delete;

    CIULog(const CIULog& rhs) = delete;
    CIULog& operator=(const CIULog& rhs) = delete;
	
private:
	static QFile d_logFile;
    static LOG_LEVEL d_logLevel;            //��־����
};