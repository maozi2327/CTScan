#include "stdafx.h"
#include "ctscan.h"

CTScan::CTScan(QWidget *parent)
    : QMainWindow(parent), d_rayPanelMotion(std::make_unique<RayPanelMotion>())
{
    ui.setupUi(this);
}

void CTScan::on_pushButton_clicked()
{
	if(!d_rayPanelMotion->isVisible())
		d_rayPanelMotion->show();
}
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