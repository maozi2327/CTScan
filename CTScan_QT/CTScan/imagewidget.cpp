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
	QPixmap image("D:/code/CTScan/CTScan_QT/x64/Debug/gain.tif");
	ui.imageLabel->setPixmap(image);
	show();
	return true;
}
bool ImageWidget::loadImage(unsigned short* in_imageMemory)
{
	return true;
}
