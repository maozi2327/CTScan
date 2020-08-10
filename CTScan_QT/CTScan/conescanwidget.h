#pragma once

#include <QWidget>
#include <memory>
#include "ui_conescanwidget.h"
#include "..\PanelDll\panel.h"
class PanelImageProcess;
class ConeScanInterface;
class ControllerInterface;


class ConeScanWidget : public QWidget
{
	Q_OBJECT

public:
	ConeScanWidget(ControllerInterface* in_controller, QWidget *parent = Q_NULLPTR);
	~ConeScanWidget();

private:
	Ui::ConeScanWidget ui;
	std::unique_ptr<ConeScanInterface> d_scan;
	std::unique_ptr<Panel> d_panel;
	std::unique_ptr<PanelImageProcess> d_panelImageProcess;
	ControllerInterface* d_controller;
	void setConeScanProgress(int in_progress, const QString& in_msg);
private slots:
	void on_coneScanBeginSampleButton_clicked();
	void on_scanProgressUpdated();
};
