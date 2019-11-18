#include "stdafx.h"
#include "imagewidget.h"
#include "ImageWidgetManager.h"

ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent)
{
	ui.setupUi(this);
}

ImageWidget::~ImageWidget()
{

}

bool ImageWidget::loadImage(QString& in_fileName)
{
	QPixmap image("D:/code/CTScan/CTScan_QT/x64/Debug/gain_small.tif");
	ui.imageLabel->setPixmap(image);
	ui.imageLabel->setAlignment(Qt::AlignCenter);
	ui.imageLabel->setFixedSize(image.width(), image.height());
	show();
	return true;
}
bool ImageWidget::loadImage(unsigned short* in_imageMemory)
{
	return true;
}
