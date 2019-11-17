#include "stdafx.h"
#include "ImageWidgetManager.h"
#include "imagewidget.h"


ImageWidgetManager::ImageWidgetManager()
{

}


ImageWidgetManager::~ImageWidgetManager()
{
}
bool ImageWidgetManager::showImageInNewWindow(unsigned short* in_imageMemory)
{
	d_imageWidgetVec.push_back(new ImageWidget(this));
	return d_imageWidgetVec.back()->loadImage(in_imageMemory);
}
bool ImageWidgetManager::showImageInFrontWindow(unsigned short* in_imageMemory)
{
	return d_imageWidgetVec[d_frontWidgetIndex]->loadImage(in_imageMemory);
}
bool ImageWidgetManager::showImageInNewWindow(QString& in_fileName)
{
	d_imageWidgetVec.push_back(new ImageWidget(this));
	return d_imageWidgetVec.back()->loadImage(in_fileName);
}
bool ImageWidgetManager::showImageInFrontWindow(QString& in_fileName)
{
	d_imageWidgetVec.push_back(new ImageWidget(this));
	return d_imageWidgetVec.back()->loadImage(in_fileName);
}
