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

void ConeScanWidget::on_coneScanBeginSampleButton_clicked()
{
	d_scan.reset(new ConeScan(d_panel.get(), d_controller, d_panelImageProcess.get()));
	
}
 