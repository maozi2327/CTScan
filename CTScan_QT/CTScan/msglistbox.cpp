#include "stdafx.h"
#include "msglistbox.h"
#include <string>
#include <regex>

MsgListBox::MsgListBox(QString& in_logFileName, QWidget *parent)
	: QWidget(parent)
{
	CIULog::Init(in_logFileName);
	ui.setupUi(this);
}

MsgListBox::~MsgListBox()
{
}
QString extractMsg(QString& in_msg)
{
	in_msg.insert(1, QDateTime::currentDateTime().toString("hh:mm:ss.zzz"));
	std::string text = in_msg.toLocal8Bit();
	std::string pattern("\\[([^\\]]+)\\]");    //只能达到匹配成[xxxx]的程度
	//std::string pattern("(?=\\[)[^\\]]*");   //只能达到匹配成[xxxx的程度
	std::regex r(pattern);
	std::smatch result;
	QString output;

	if (std::regex_search(text, result, r))
	{
		std::string temp = result.str();
		std::string tempp(temp, 1, temp.size() - 2);
		output = QString::fromLocal8Bit(tempp.data());
	}

	return output;
}

void MsgListBox::logError(QString& in_msg)
{
	ui.listWidget->addItem(extractMsg(in_msg));
	CIULog::Log(LOG_LEVEL::LOG_LEVEL_ERROR, in_msg);
	show();
}

void MsgListBox::logInfo(QString & in_msg)
{
	ui.listWidget->addItem(extractMsg(in_msg));
	CIULog::Log(LOG_LEVEL::LOG_LEVEL_INFO, in_msg);
	show();
}

void MsgListBox::logBug(QString & in_msg)
{
	ui.listWidget->addItem(extractMsg(in_msg));
	CIULog::Log(LOG_LEVEL::LOG_LEVEL_BUG, in_msg);
	show();
}

void MsgListBox::closeEvent(QCloseEvent * event)
{
	hide();
}

