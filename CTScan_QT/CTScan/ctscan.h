#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ctscan.h"
#include "imagewidgetmanager.h"
#include "conescaninterface.h"
#include "..\PanelDll\panel.h"
#include <memory>
struct SetupData;
class SetupDataParser;
class RayPanelMotion;
class MotorControlWidget;
class LineDetScanWidget;
class ControllerInterface;
class LineDetNetWork;
class MsgListBox;
class LineDetScanInterface;
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
	void controllerNetWorkStsSlot(bool sts);
	void errorMsgSlot(QString msg);
	void infoMsgSlot(QString msg);
	void bugMsgSlot(QString msg);
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private:
    Ui::CTScanClass ui;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;
	std::unique_ptr<SetupData> d_setupData;
	std::unique_ptr<SetupDataParser> d_setupDataPaser;
	std::unique_ptr<MotorControlWidget> d_motorControl;
	std::unique_ptr<ConeScanInterface> d_scanInterface;
	std::unique_ptr<ImageWidgetManager> d_imageWidgetManager;
	std::unique_ptr<Panel> d_panel;
	std::unique_ptr<LineDetScanWidget> d_line1Det1ScanWidget;
	std::unique_ptr<RayPanelMotion> d_rayPanelMotion;
	std::unique_ptr<ControllerInterface> d_controller;
	std::unique_ptr<MsgListBox> d_msg;
	std::map<int, std::unique_ptr<LineDetNetWork>> d_lineDetNetWorkMap;
	std::map<std::pair<int, int>, std::vector<std::unique_ptr<LineDetScanInterface>>> d_rayDetScanMap;
	size_t frontImageIndex;
	QSystemTrayIcon* tray;
	QString	d_workDir;
};
//#ifdef TABLETRANSLATION
//#ifdef TABLERADIAL
//#ifdef DETLAYER
//#ifdef DETTRANSLATION
//#ifdef DETTRADIAL
//#ifdef RAYLAYER
//#ifdef DEFLECT
//#endif