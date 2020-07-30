#include "stdafx.h"
#include "scanprogresswidget.h"

ScanProgressWidget::ScanProgressWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ScanProgressWidget::~ScanProgressWidget()
{
}

void ScanProgressWidget::setProgress(int in_thisRound, int in_allProgress, const QString & in_imagesCollectedAndSpaceOccupied)
{
	ui.thisRoundProgressBar->setValue(in_thisRound);
	ui.allProgressBar->setValue(in_allProgress);
	ui.imagesCollectedAndSpaceOccupiedLabel->setText(in_imagesCollectedAndSpaceOccupied);
}
