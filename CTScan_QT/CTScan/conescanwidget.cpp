#include "stdafx.h"
#include "conescanwidget.h"
#include "conescan.h"
#include "../PanelDll/panel.h"

ConeScanWidget::ConeScanWidget(MotorControlWidget* in_motorControl, int in_rayId, int in_panelDetId, const std::vector<ScanMode>& in_scanMode,
	SetupData* in_setupData, Panel* in_panel, ControllerInterface* in_controller, QWidget *parent)
	: QWidget(parent), d_panel(in_panel), d_controller(in_controller), d_rayNum(in_rayId), d_detNum(in_panelDetId), d_setupData(in_setupData)
{
	ui.setupUi(this);

	for (auto& scanMode : in_scanMode)
	{
		if (scanMode == ScanMode::CONE_SCAN)
		{
			auto itr = std::find_if(d_setupData->coneScanData.begin(), d_setupData->coneScanData.end(),
				[=](ConeScanData& in_Data)
			{	return in_Data.Ray == in_rayId && in_Data.Det == in_panelDetId; });

			initiliseConeScanControls(*itr);
		}
		else if (scanMode == ScanMode::CONE_JOINT_ROT_SCAN)
		{
			auto itr = std::find_if(d_setupData->coneJointRotScanData.begin(), d_setupData->coneJointRotScanData.end(),
				[=](ConeJointRotScanData& in_Data)
			{	return in_Data.Ray == in_rayId && in_Data.Det == in_panelDetId; });

			initiliseConeJointRotScanControls(*itr);
		}
	}
}

ConeScanWidget::~ConeScanWidget()
{

}

void ConeScanWidget::setConeScanProgress(int in_progress, const QString & in_msg)
{
	ui.coneScanAllProgressBar->setValue(in_progress);
	ui.coneScanProgressStaticLabel->setText(in_msg);
}

void ConeScanWidget::initiliseConeScanControls(ConeScanData & in_data)
{

}

void ConeScanWidget::initiliseConeJointRotScanControls(ConeJointRotScanData & in_data)
{

}

void ConeScanWidget::on_scanProgressUpdated()
{
	int thisRound, allProgress;
	QString msg;
	d_scan->getScanProgress(thisRound, allProgress, msg);

	if (dynamic_cast<ConeScan*>(d_scan.get()))
		setConeScanProgress(allProgress, msg);

}

void ConeScanWidget::on_coneScanBeginSampleButton_clicked()
{
	d_scan.reset(new ConeScan(d_panel, d_controller, d_panelImageProcess.get()));
	d_scan->setDisposeFlag(ui.bkgTuneCheckBox->isChecked(), ui.airTuneCheckBox->isChecked(),
		ui.defectTuneCheckBox->isChecked(), true);
}
 