#pragma once

#include "ui_linedetscanwidget.h"
#include <memory>

class MotorControlWidget;
struct SetupData;
class LineDetScanInterface;
class ControllerInterface;
class LineDetScanWidget : public QWidget
{
	Q_OBJECT

public:
	LineDetScanWidget(MotorControlWidget* in_motorControl, ControllerInterface* in_controller, SetupData* in_setupData, QWidget *parent = Q_NULLPTR);
	~LineDetScanWidget();

	void onNetworkStsChanged(bool in_netWorkSts);
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private:
	Ui::LineDetScanWidget ui;
	QAction *showMotorTableAction;
	MotorControlWidget* d_motorControl;
	SetupData* d_setupData;
	unsigned short d_rayNum;
	unsigned short d_detNum;
	void disableAllControls();
	void initiliseControls();
	std::unique_ptr<LineDetScanInterface> d_scan;
	ControllerInterface* d_controller;
private slots:
	void showMotorTable();
	void on_startButton_clicked();
};
