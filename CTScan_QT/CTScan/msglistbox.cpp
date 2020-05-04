#include "stdafx.h"
#include "msglistbox.h"

MsgListBox::MsgListBox(QString& in_logFileName, QWidget *parent)
	: QWidget(parent)
{
	CIULog::Init(in_logFileName);
	ui.setupUi(this);
}

MsgListBox::~MsgListBox()
{
}

void MsgListBox::logError(QString & in_log)
{
	CIULog::Log(LOG_LEVEL::LOG_LEVEL_ERROR, __FUNCSIG__, __LINE__, in_log);
}

