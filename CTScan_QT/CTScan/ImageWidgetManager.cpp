#include "stdafx.h"
#include "imagewidgetmanager.h"
#include "imagewidget.h"


ImageWidgetManager::ImageWidgetManager()
{

}


ImageWidgetManager::~ImageWidgetManager()
{
}
bool ImageWidgetManager::showImageInNewWindow(unsigned char* in_imageMemory, int in_width, int in_height)
{
	d_imageWidgetVec.push_back(new ImageWidget(this, 0, 0, in_imageMemory, in_width, in_height));
	auto imageWidget = d_imageWidgetVec.back();
	imageWidget->show();
	return true;
}
bool ImageWidgetManager::showImageInFrontWindow(unsigned char* in_imageMemory, int in_width, int in_height)
{
	d_imageWidgetVec.push_back(new ImageWidget(this, 0, 0, in_imageMemory, in_width, in_height));
	d_imageWidgetVec[d_frontWidgetIndex]->loadImage(in_imageMemory, in_width, in_height);
	return true;
}
bool ImageWidgetManager::showImageInNewWindow(QString& in_fileName)
{
	d_imageWidgetVec.push_back(new ImageWidget(this, 0, 0, in_fileName));
	auto imageWidget = d_imageWidgetVec.back();
	imageWidget->show();
	return true;
}
bool ImageWidgetManager::showImageInFrontWindow(QString& in_fileName)
{
	d_imageWidgetVec[d_frontWidgetIndex]->loadImage(in_fileName);
	return true;
}
