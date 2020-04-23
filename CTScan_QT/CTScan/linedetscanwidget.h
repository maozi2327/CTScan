#pragma once

#include "ui_linedetscanwidget.h"

class MotorControl;
class LineDetScanWidget : public QWidget
{
	Q_OBJECT

public:
	LineDetScanWidget(MotorControl* in_motorControl, QWidget *parent = Q_NULLPTR);
	~LineDetScanWidget();

	void onNetworkStsChanged(bool in_netWorkSts);
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private:
	Ui::LineDetScanWidget ui;
	QAction *showMotorTableAction;
	MotorControl* d_motorControl;

	void disableAllControls();
private slots:
	void showMotorTable();
};
