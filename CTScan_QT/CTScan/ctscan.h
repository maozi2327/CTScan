#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ctscan.h"
#include "ImageWidgetManager.h"
#include "controllerinterface.h"
#include "conescaninterface.h"
#include "..\PanelDll\panel.h"
#include <memory>

class RayPanelMotion;
class MotorControl;
class LineDetScanWidget;
class CTScan : public QMainWindow
{
    Q_OBJECT

public:
    CTScan(QWidget *parent = Q_NULLPTR);
	~CTScan();
public slots:
	void on_ray1LineDetButton_clicked();
	void on_ray1PanelDetButton_clicked();
	void on_ray2LineDetButton_clicked();
	void on_ray2PanelDetButton_clicked();

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
	std::unique_ptr<ControllerInterface> d_controller;
	std::unique_ptr<MotorControl> d_motorControl;
	std::unique_ptr<ConeScanInterface> d_scanInterface;
	std::unique_ptr<ImageWidgetManager> d_imageWidgetManager;
	std::unique_ptr<Panel> d_panel;
	std::unique_ptr<LineDetScanWidget> d_lineDetScanWidget;
	std::unique_ptr<RayPanelMotion> d_rayPanelMotion;
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