#pragma once

#include "ui_linedetscanwidget.h"

class LineDetScanWidget : public QWidget
{
	Q_OBJECT

public:
	LineDetScanWidget(QWidget *parent = Q_NULLPTR);
	~LineDetScanWidget();

private:
	Ui::LineDetScanWidget ui;
};
