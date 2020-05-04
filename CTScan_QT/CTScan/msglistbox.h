#pragma once

#include <QWidget>
#include "ui_msglistbox.h"
#include "../Public/util/iulog.h"

//e.g. LOG_INFO(_T("GroupID=%u, GroupName=%s, GroupName=%s."), lpGroupInfo->d_nGroupCode, lpGroupInfo->d_strAccount.c_str(), lpGroupInfo->d_strName.c_str());
//#define LOG_INFO(info)     MsgListBox::Log(LOG_LEVEL::LOG_LEVEL_INFO, info)
//#define LOG_WARNING(warning)    MsgListBox::Log(LOG_LEVEL::LOG_LEVEL_WARNING, __FUNCSIG__, __LINE__,warning)
//#define LOG_ERROR(error)      MsgListBox::Log(LOG_LEVEL::LOG_LEVEL_ERROR, __FUNCSIG__,__LINE__, error)

class MsgListBox : public QWidget
{
	Q_OBJECT

public:
	MsgListBox(QString& in_logFileName, QWidget *parent = Q_NULLPTR);
	~MsgListBox();
	void logError(QString& in_log);
private:
	Ui::MsgListBox ui;
};
