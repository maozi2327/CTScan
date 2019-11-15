#pragma once

#include <QWidget>
#include "ui_conescanwidget.h"
class ScanInterface;
class ConeScanWidget : public QWidget
{
	Q_OBJECT

public:
	ConeScanWidget(QWidget *parent = Q_NULLPTR);
	~ConeScanWidget();

private:
	Ui::ConeScanWidget ui;
	ScanInterface* d_scanInterface;
};
