#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ctscan.h"
#include "raypanelmotionwidget.h"
#include "controlerinterface.h"
#include "conescaninterface.h"
#include "ImageWidgetManager.h"
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
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private:
    Ui::CTScanClass ui;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;

	std::unique_ptr<RayPanelMotion> d_rayPanelMotion;
	std::unique_ptr<ControlerInterface> d_controller;
	std::unique_ptr<ConeScanInterface> d_scanInterface;
	std::unique_ptr<ImageWidgetManager> d_imageWidgetManager;
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