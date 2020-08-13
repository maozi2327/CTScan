#pragma once

#include "ui_linedetscanwidget.h"
#include <memory>
#include <vector>
#include <map>
#include "../Public/headers/setupdata.h"

struct CT3Data;
class MotorControlWidget;
class LineDetScanInterface;
class ControllerInterface;
class LineDetNetWork;
class LineDetScanWidget : public QWidget
{
	Q_OBJECT

public:
	LineDetScanWidget(MotorControlWidget* in_motorControl, int in_rayId, int in_lineDetId, const
		std::vector<ScanMode>& in_scanMode, SetupData* in_setupData, 
		LineDetNetWork* in_lineDetNetWork, ControllerInterface* in_controller, QWidget *parent = Q_NULLPTR);

	~LineDetScanWidget();

	void onNetworkStsChanged(bool in_netWorkSts);
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private:
	Ui::LineDetScanWidget ui;
	QAction *showMotorTableAction;
	MotorControlWidget* d_motorControlDialog;
	SetupData* d_setupData;
	LineDetNetWork* d_lineDetNetWork;
	ControllerInterface* d_controller;
	unsigned short d_rayNum;
	unsigned short d_detNum;
	void disableAllControls();
	void initiliseControls();
	void initiliseCt3Controls(CT3Data& in_data);
	void initiliseCt2Controls(CT2Data& in_data);
	void initiliseDrControls(DrScanData& in_data);
	std::map<ScanMode, LineDetScanInterface*> d_scanMap;
	std::unique_ptr<LineDetScanInterface> d_scan;
private slots:
	void showMotorTable();
	void on_Ct3StartButton_clicked();
	void on_saveDirButton_clicked();
	void on_ct3MultiLayerComboBox_currentIndexChanged(const QString& in_text);
	void on_ct3LayerPosLineEdit_returnd();
};
