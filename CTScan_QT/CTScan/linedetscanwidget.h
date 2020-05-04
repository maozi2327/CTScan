#pragma once

#include "ui_linedetscanwidget.h"
#include <memory>
#include <vector>
#include <map>
#include "../Public/headers/setupdata.h"
class MotorControlWidget;
struct CT3Data;
class LineDetScanInterface;
class ControllerInterface;
class LineDetScanWidget : public QWidget
{
	Q_OBJECT

public:
	LineDetScanWidget(MotorControlWidget* in_motorControl, std::vector<LineDetScanInterface*>& in_scan,
		SetupData* in_setupData, QWidget *parent = Q_NULLPTR);
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
	unsigned short d_rayNum;
	unsigned short d_detNum;
	void disableAllControls();
	void initiliseControls();
	void initiliseCt3Controls(CT3Data& in_data);
	void initiliseCt2Controls();
	void initiliseDrControls();
	std::map<ScanMode, LineDetScanInterface*> d_scanMap;
private slots:
	void showMotorTable();
	void on_startButton_clicked();
	void on_saveDirButton_clicked();
	void on_ct3MultiLayerComboBox_currentIndexChanged(const QString& in_text);
	void on_ct3LayerPosLineEdit_returnd();
};
