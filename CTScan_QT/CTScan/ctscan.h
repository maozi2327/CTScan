#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ctscan.h"
#include "imagewidgetmanager.h"
#include <memory>
#include "../Public/headers/setupdata.h"
class SetupDataParser;
class RayPanelMotion;
class MotorControlWidget;
class LineDetScanWidget;
class ControllerInterface;
class LineDetNetWork;
class MsgListBox;
class LineDetScanInterface;
class ConeScanWidget;

class CTScan : public QMainWindow
{
    Q_OBJECT

public:
    CTScan(QWidget *parent = Q_NULLPTR);
	~CTScan();

private slots:
	void on_ray0LineDet0Button_clicked();
	void on_ray0PanelDet0Button_clicked();
	void on_ray1LineDet0Button_clicked();
	void on_ray1PanelDet0Button_clicked();

private slots:
	void cut();
	void copy();
	void paste();
	void controllerNetWorkStsSlot(bool sts);
	void errorMsgSlot(QString msg);
	void infoMsgSlot(QString msg);
	void bugMsgSlot(QString msg);
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
	void changeEvent(QEvent * event) override;
#endif // QT_NO_CONTEXTMENU
private:
    Ui::CTScanClass ui;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;
	std::unique_ptr<SetupData> d_setupData;
	std::unique_ptr<SetupDataParser> d_setupDataPaser;
	std::unique_ptr<ImageWidgetManager> d_imageWidgetManager;
	std::unique_ptr<RayPanelMotion> d_rayPanelMotion;
	std::unique_ptr<ControllerInterface> d_controller;
	std::unique_ptr<MotorControlWidget> d_motorControl;
	std::unique_ptr<ConeScanWidget> d_panle1Det1ScanWidget;
	std::unique_ptr<MsgListBox> d_msg;
	std::map<int, std::unique_ptr<LineDetNetWork>> d_lineDetNetWorkMap;
	std::map<std::pair<int, int>, std::vector<ScanMode>> d_lineDetScanModeMap;
	std::map<std::pair<int, int>, std::vector<ScanMode>> d_panelDetScanModeMap;
	std::map<std::pair<int, int>, std::unique_ptr<LineDetScanWidget>> d_lineDetScanWidget;
	std::map<std::pair<int, int>, std::unique_ptr<ConeScanWidget>> d_panelDetScanWidget;
	size_t frontImageIndex;
	QSystemTrayIcon* d_tray;
	QString	d_workDir;
	QWidget* d_scanWidget;
};
//#ifdef TABLETRANSLATION
//#ifdef TABLERADIAL
//#ifdef DETLAYER
//#ifdef DETTRANSLATION
//#ifdef DETTRADIAL
//#ifdef RAYLAYER
//#ifdef DEFLECT
//#endif