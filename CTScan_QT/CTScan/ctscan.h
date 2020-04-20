#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ctscan.h"
#include "ImageWidgetManager.h"
#include "controlerinterface.h"
#include "conescaninterface.h"
#include "..\PanelDll\panel.h"
#include <memory>

class RayPanelMotion;
class MotorControl;
class CTScan : public QMainWindow
{
    Q_OBJECT

public:
    CTScan(QWidget *parent = Q_NULLPTR);
public slots:
	void on_pushButton_clicked();
	void on_motorPanelButton_clicked();
private slots:
	void cut();
	void copy();
	void paste();
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private:
    Ui::CTScanClass ui;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;
	std::unique_ptr<Panel> d_panel;
	std::unique_ptr<RayPanelMotion> d_rayPanelMotion;
	std::unique_ptr<ControlerInterface> d_controller;
	std::unique_ptr<ConeScanInterface> d_scanInterface;
	std::unique_ptr<ImageWidgetManager> d_imageWidgetManager;
	std::unique_ptr<MotorControl> d_motorControl;
	size_t frontImageIndex;
};
//#ifdef TABLETRANSLATION
//#ifdef TABLERADIAL
//#ifdef DETLAYER
//#ifdef DETTRANSLATION
//#ifdef DETTRADIAL
//#ifdef RAYLAYER
//#ifdef DEFLECT
//#endif