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
#include "linedetnetwork.h"
#include "msglistbox.h"

CTScan::CTScan(QWidget *parent)
    : QMainWindow(parent)
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

	QString logFileFullName = d_workDir + "/log/" + QDateTime::currentDateTime().date().toString(Qt::ISODate)
		+ '/' + time;
	d_msg.reset(new MsgListBox(logFileFullName));
	ui.setupUi(this);
	connect(d_controller.get(), &ControllerInterface::netWorkStsSginal
		, this, &CTScan::controllerNetWorkStsSlot, Qt::QueuedConnection);
	tray = new QSystemTrayIcon(this);
	tray->setIcon(QIcon(":/images/ico.png"));

	for (int i = 0; i != d_setupData->lineDetNum; ++i)
	{
		std::unique_ptr<LineDetNetWork> ptr(new LineDetNetWork(d_setupData->lineDetData[i].nAcquireClientPort));
		d_lineDetNetWorkMap.insert({ d_setupData->lineDetData[i].LineDetID,  std::move(ptr) });
	}
		
	auto& data = d_setupData->ct3Data;
	auto matrixItr = std::find_if(data.begin(), data.end(),	[](CT3Data elem) { return elem.Det == 1 && elem.Ray == 1; });

	if (matrixItr != data.end())
	{
		std::unique_ptr<LineDetScanInterface> scan(new CT3Scan(d_controller.get(),
			d_lineDetNetWorkMap[matrixItr->Det].get(), *matrixItr));
		connect(scan.get(), &LineDetScanInterface::errorMsgSignal, this, &CTScan::errorMsgSlot);
		d_rayDetScanMap[{1, 1}].push_back(std::move(scan));
	}

	using pair = std::pair<std::pair<int, int>, std::vector<std::unique_ptr<LineDetScanInterface>>>;
	auto& uniquePtrVector = d_rayDetScanMap[{1, 1}];
	std::vector<LineDetScanInterface*> scanVector(uniquePtrVector.size());
	std::transform(uniquePtrVector.begin(), uniquePtrVector.end(), scanVector.begin(),
		[](std::unique_ptr<LineDetScanInterface>& elem) { return elem.get(); });

	d_lineDetScanWidget[std::pair<int, int>(1 ,1)].reset(new LineDetScanWidget(d_motorControl.get(), scanVector, d_setupData.get()));
	d_line1Det1ScanWidget.reset(new LineDetScanWidget(d_motorControl.get(), scanVector, d_setupData.get()));
}

CTScan::~CTScan()
{

}

void CTScan::on_ray1LineDet1Button_clicked()
{
	//QString fileName("0000.tif");
	//d_panelImageProcess->loadAirData(fileName);
	//d_line1Det1ScanWidget->show();
	//tray->show();
}

void CTScan::on_ray1PanelDet1Button_clicked()
{
	d_conesc
}

void CTScan::on_ray2LineDet1Button_clicked()
{

}

void CTScan::on_ray2PanelDet1Button_clicked()
{

}

void CTScan::controllerNetWorkStsSlot(bool sts)
{
	d_line1Det1ScanWidget->onNetworkStsChanged(sts);
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

//void CTScan::on_pushButton_clicked()
//{
//	//if(!d_rayPanelMotion->isVisible())
//	//	d_rayPanelMotion->show();
//	d_imageWidgetManager->showImageInNewWindow(QString());
//}
void CTScan::cut()
{
	hide();                 /* 最小化到托盘 */
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
