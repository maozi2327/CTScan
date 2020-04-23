#include "stdafx.h"
#include "linedetscanwidget.h"
#include "MotorControl.h"

LineDetScanWidget::LineDetScanWidget(MotorControl* in_motorControl, QWidget *parent)
	: QWidget(parent)
	, d_motorControl(in_motorControl)
{
	ui.setupUi(this);
}

LineDetScanWidget::~LineDetScanWidget()
{

}

void LineDetScanWidget::onNetworkStsChanged(bool in_netWorkSts)
{
	ui.startButton->setEnabled(in_netWorkSts);
	ui.startButton->setEnabled(in_netWorkSts);
	ui.scanModeTab->setEnabled(in_netWorkSts);
}

void LineDetScanWidget::contextMenuEvent(QContextMenuEvent * event)
{
	showMotorTableAction = new QAction(tr("&paste"), this);
	connect(showMotorTableAction, &QAction::triggered, this, &LineDetScanWidget::showMotorTable);
	QMenu menu(this);
	menu.addAction(showMotorTableAction);
	menu.exec(event->globalPos());
}

void LineDetScanWidget::disableAllControls()
{
}

void LineDetScanWidget::showMotorTable()
{
	d_motorControl->show();
}
