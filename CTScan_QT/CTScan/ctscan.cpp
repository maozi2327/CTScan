#include "stdafx.h"
#include "ctscan.h"
#include "MotorControl.h"
#include "raypanelmotionwidget.h"
#include "simotioncontroller.h"
#include "linedetscanwidget.h"
CTScan::CTScan(QWidget *parent)
    : QMainWindow(parent)
	, d_lineDetScanWidget(new LineDetScanWidget(d_motorControl.get())), d_panel(PanelFactory::getPanel())
	, d_rayPanelMotion(new RayPanelMotion()), d_imageWidgetManager(new ImageWidgetManager())
	, d_controller(new SimotionController()), d_motorControl(new MotorControl(d_controller.get()))
{
    ui.setupUi(this);
}

CTScan::~CTScan()
{
}

void CTScan::on_ray1LineDetButton_clicked()
{
	d_lineDetScanWidget->show();
}

void CTScan::on_ray1PanelDetButton_clicked()
{
}

void CTScan::on_ray2LineDetButton_clicked()
{
}

void CTScan::on_ray2PanelDetButton_clicked()
{
}

//void CTScan::on_pushButton_clicked()
//{
//	//if(!d_rayPanelMotion->isVisible())
//	//	d_rayPanelMotion->show();
//	d_imageWidgetManager->showImageInNewWindow(QString());
//}
void CTScan::cut()
{
	//infoLabel->setText(tr("Invoked <b>Edit|Cut</b>"));
}


void CTScan::copy()
{
	//infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void CTScan::paste()
{
	//infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}
void CTScan::contextMenuEvent(QContextMenuEvent *event)
{
	cutAct = new QAction(tr("Cu&t"), this);
	cutAct->setShortcuts(QKeySequence::Cut);
	cutAct->setStatusTip(tr("Cut the current selection's contents to the "
		"clipboard"));
	connect(cutAct, &QAction::triggered, this, &CTScan::cut);

	copyAct = new QAction(tr("&Copy"), this);
	copyAct->setShortcuts(QKeySequence::Copy);
	copyAct->setStatusTip(tr("Copy the current selection's contents to the "
		"clipboard"));
	connect(copyAct, &QAction::triggered, this, &CTScan::copy);

	pasteAct = new QAction(tr("&Paste"), this);
	pasteAct->setShortcuts(QKeySequence::Paste);
	pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
		"selection"));
	connect(pasteAct, &QAction::triggered, this, &CTScan::paste);
	QMenu menu(this);
	menu.addAction(cutAct);
	menu.addAction(copyAct);
	menu.addAction(pasteAct);
	menu.exec(event->globalPos());
}
