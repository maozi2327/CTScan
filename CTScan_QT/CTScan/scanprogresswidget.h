#pragma once

#include <QWidget>
#include "ui_scanprogresswidget.h"

class ScanProgressWidget : public QWidget
{
	Q_OBJECT

public:
	ScanProgressWidget(QWidget *parent = Q_NULLPTR);
	~ScanProgressWidget();
	void setProgress(int in_thisRound, int in_allProgress, const QString& in_imagesCollectedAndSpaceOccupied);

private:
	Ui::ScanProgressWidget ui;
};
