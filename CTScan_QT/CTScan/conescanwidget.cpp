#include "stdafx.h"
#include "conescanwidget.h"
#include "conescan.h"
#include "scanprogresswidget.h"
ConeScanWidget::ConeScanWidget(ControllerInterface* in_controller, QWidget *parent)
	: QWidget(parent)
	, d_panel(PanelFactory::getPanel()), d_controller(in_controller)
	, d_panelImageProcess(PanelImageProcessFactory::getPanelImageProcess())
{
	ui.setupUi(this);
}

ConeScanWidget::~ConeScanWidget()
{

}

void ConeScanWidget::on_scanProgressUpdated()
{
	int thisRound, allProgress;
	QString msg;
	d_scan->getScanProgress(thisRound, allProgress, msg);
	d_scanProgressWidget->setProgress(thisRound, allProgress, msg);
}

void ConeScanWidget::on_coneScanBeginSampleButton_clicked()
{
	d_scan.reset(new ConeScan(d_panel.get(), d_controller, d_panelImageProcess.get()));
	d_scan->setDisposeFlag(ui.bkgTuneCheckBox->isChecked(), ui.airTuneCheckBox->isChecked(),
		ui.defectTuneCheckBox->isChecked(), true);
}
 