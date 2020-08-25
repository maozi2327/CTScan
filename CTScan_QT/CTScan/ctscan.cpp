#include "stdafx.h"
#include "ctscan.h"
#include "motorcontrolwidget.h"
#include "raypanelmotionwidget.h"
#include "simotioncontroller.h"
#include "linedetscanwidget.h"
#include "conescanwidget.h"
#include "setupdataparser.h"
#include "../Public/headers/panelimageprocess.h"
#include "../Public/headers/SetupData.h"
#include "msglistbox.h"
#include "ct3Scan.h"
#include "ct2Scan.h"
#include "drscan.h"
#include "linedetnetwork.h"
#include "msglistbox.h"

CTScan::CTScan(QWidget *parent)
    : QMainWindow(parent)
	, d_scanWidget(nullptr)
	, d_rayPanelMotion(new RayPanelMotion()), d_imageWidgetManager(new ImageWidgetManager())
	, d_controller(new SimotionController()), d_motorControl(new MotorControlWidget(d_controller.get()))
	, d_setupData(new SetupData), d_setupDataPaser(new SetupDataParser(d_setupData.get()))
	, d_workDir(QCoreApplication::applicationDirPath())
{
	QString time = QDateTime::currentDateTime().time().toString();
	auto i = time.length();

	for (auto index = 0; index != i; ++index)
		if (time[index] == ':')
			time[index] = '-';

	QString logFileFullName = d_workDir + "/log/" + 
		QDateTime::currentDateTime().date().toString(Qt::ISODate) + '/' + time;
	d_msg.reset(new MsgListBox(logFileFullName));
	ui.setupUi(this);
	connect(d_controller.get(), &ControllerInterface::netWorkStsSginal
		, this, &CTScan::controllerNetWorkStsSlot, Qt::QueuedConnection);
	d_tray = new QSystemTrayIcon(this);
	d_tray->setIcon(QIcon(":/images/ico.png"));

	connect(d_tray,&QSystemTrayIcon::activated, this, &CTScan::on_activatedSysTrayIcon);

	for (int i = 0; i != d_setupData->lineDetNum; ++i)
	{
		std::unique_ptr<LineDetNetWork> ptr(new LineDetNetWork(d_setupData->lineDetData[i].nAcquireClientPort));
		d_lineDetNetWorkMap.insert({ d_setupData->lineDetData[i].ID,  std::move(ptr) });
	}

	//查找同一种扫描方式有几种射线源和探测器组合，有几种就初始化几个线阵扫描和面阵扫描的widget
	for (auto& matrixItr : d_setupData->ct3Data)
		d_lineDetScanModeMap[{ matrixItr.Ray, matrixItr.Det }].push_back(ScanMode::CT3_SCAN);

	for (auto& matrixItr : d_setupData->ct2Data)
		d_lineDetScanModeMap[{ matrixItr.Ray, matrixItr.Det }].push_back(ScanMode::CT2_SCAN);

	for (auto& matrixItr : d_setupData->drScanData)
		d_lineDetScanModeMap[{ matrixItr.Ray, matrixItr.Det }].push_back(ScanMode::DR_SCAN);

	for (auto& matrixItr : d_setupData->coneScanData)
		d_panelDetScanModeMap[{ matrixItr.Ray, matrixItr.Det }].push_back(ScanMode::CONE_SCAN);

	for (auto& matrixItr : d_setupData->coneJointRotScanData)
		d_panelDetScanModeMap[{ matrixItr.Ray, matrixItr.Det }].push_back(ScanMode::CONE_JOINT_ROT_SCAN);
}

CTScan::~CTScan()
{

}

void CTScan::on_ray0LineDet0Button_clicked()
{
	if (d_lineDetScanWidget[{0, 0}].get() == nullptr)
	{
		auto widget = new LineDetScanWidget(d_motorControl.get(), 0, 0,
			d_lineDetScanModeMap[{ 0, 0}], d_setupData.get(), d_lineDetNetWorkMap[0].get(), d_controller.get(), this);
		d_lineDetScanWidget[{0, 0}].reset(widget);
	}
	
	if(d_scanWidget != nullptr && d_scanWidget->isVisible())
		d_scanWidget->hide();

	d_scanWidget = d_lineDetScanWidget[{0, 0}].get();
	d_scanWidget->setGeometry((QRect(400, 400, 520, 730)));
	d_scanWidget->show();
	//hide();
	//QString fileName("0000.tif");
	//d_panelImageProcess->loadAirData(fileName);
}

void CTScan::on_ray0PanelDet0Button_clicked()
{
	if (d_panelDetScanWidget[{0, 0}].get() == nullptr)
	{
		auto widget = new ConeScanWidget(d_motorControl.get(), 0, 0,
			d_panelDetScanModeMap[{0, 0}], d_setupData.get(), nullptr, d_controller.get(), this);
		d_panelDetScanWidget[{0, 0}].reset(widget);
	}

	if (d_scanWidget != nullptr && d_scanWidget->isVisible())
		d_scanWidget->hide();

	d_scanWidget = d_panelDetScanWidget[{0, 0}].get();
	d_scanWidget->setGeometry((QRect(400, 400, 1520, 1730)));
	d_scanWidget->show();
}

void CTScan::on_ray1LineDet0Button_clicked()
{

}

void CTScan::on_ray1PanelDet0Button_clicked()
{

}

void CTScan::controllerNetWorkStsSlot(bool sts)
{
	//d_line1Det1ScanWidget->onNetworkStsChanged(sts);
}

void CTScan::errorMsgSlot(QString msg)
{
	d_msg->logError(msg);
}

void CTScan::infoMsgSlot(QString msg)
{
}

void CTScan::bugMsgSlot(QString msg)
{
}

void CTScan::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) 
	{
	case QSystemTrayIcon::Trigger:
		break;
	case QSystemTrayIcon::DoubleClick:
		this->showNormal();
		break;
	default:
		break;
	}
}

//void CTScan::on_pushButton_clicked()
//{
//	//if(!d_rayPanelMotion->isVisible())
//	//	d_rayPanelMotion->show();
//	d_imageWidgetManager->showImageInNewWindow(QString());
//}
void CTScan::cut()
{
	hide();                 /* 最小化到托盘 */
	d_tray->show();
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

void CTScan::changeEvent(QEvent * event)
{
	if ((event->type() == QEvent::WindowStateChange) && isMinimized())
	{
		hide();
		d_tray->show();
	}
}
