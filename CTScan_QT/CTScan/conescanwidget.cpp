#include "stdafx.h"
#include "conescanwidget.h"
#include "conescan.h"
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

void ConeScanWidget::setConeScanProgress(int in_progress, const QString & in_msg)
{
	ui.coneScanAllProgressBar->setValue(in_progress);
	ui.coneScanProgressStaticLabel->setText(in_msg);
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
	d_scan.reset(new ConeScan(d_panel.get(), d_controller, d_panelImageProcess.get()));
	d_scan->setDisposeFlag(ui.bkgTuneCheckBox->isChecked(), ui.airTuneCheckBox->isChecked(),
		ui.defectTuneCheckBox->isChecked(), true);
}
 