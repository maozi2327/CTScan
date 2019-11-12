#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ctscan.h"
#include "rayPanelMotionWidget.h"
#include <memory>
class CTScan : public QMainWindow
{
    Q_OBJECT

public:
    CTScan(QWidget *parent = Q_NULLPTR);
public slots:
	void on_pushButton_clicked();
private slots:
	void cut();
	void copy();
	void paste();
protected:
	void contextMenuEvent(QContextMenuEvent *event);
private:
    Ui::CTScanClass ui;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;
	std::unique_ptr<RayPanelMotion> d_rayPanelMotion;
};
//#ifdef TABLETRANSLATION
//#ifdef TABLERADIAL
//#ifdef DETLAYER
//#ifdef DETTRANSLATION
//#ifdef DETTRADIAL
//#ifdef RAYLAYER
//#ifdef DEFLECT
//#endif