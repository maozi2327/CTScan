#pragma once

#include <QWidget>
#include <memory>
#include "ui_conescanwidget.h"
#include "../Public/headers/setupdata.h"

class PanelImageProcess;
class ConeScanInterface;
class ControllerInterface;
class MotorControlWidget;
class Panel;

class ConeScanWidget : public QWidget
{
	Q_OBJECT

public:
	ConeScanWidget(MotorControlWidget* in_motorControl, int in_rayId, int in_panelDetId, const
		std::vector<ScanMode>& in_scanMode, SetupData* in_setupData,
		Panel* in_panel, ControllerInterface* in_controller, QWidget *parent = Q_NULLPTR);

	~ConeScanWidget();

private:
	Ui::ConeScanWidget ui;
	std::unique_ptr<ConeScanInterface> d_scan;
	std::unique_ptr<PanelImageProcess> d_panelImageProcess;
	unsigned short d_rayNum;
	unsigned short d_detNum;
	MotorControlWidget* d_motorControlDialog;
	SetupData* d_setupData;
	ControllerInterface* d_controller;
	Panel* d_panel;
	void setConeScanProgress(int in_progress, const QString& in_msg);
	void initiliseConeScanControls(ConeScanData& in_data);
	void initiliseConeJointRotScanControls(ConeJointRotScanData& in_data);
private slots:
	void on_coneScanBeginSampleButton_clicked();
	void on_scanProgressUpdated();
};
