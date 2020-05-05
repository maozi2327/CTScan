#pragma once

#include <QWidget>
#include "ui_msglistbox.h"
#include "../Public/util/iulog.h"

class MsgListBox : public QWidget
{
	Q_OBJECT

public:
	MsgListBox(QString& in_logFileName, QWidget *parent = Q_NULLPTR);
	~MsgListBox();
	void logError(QString& in_msg);
	void logInfo(QString& in_msg);
	void logBug(QString& in_msg);
private:
	Ui::MsgListBox ui;

protected:
	void closeEvent(QCloseEvent * event);
};
