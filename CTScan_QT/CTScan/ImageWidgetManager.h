#pragma once
#include "imagewidget.h"
#include <vector>
#include <memory>
class ImageWidgetManager
{
public:
	ImageWidgetManager();
	~ImageWidgetManager();

	bool showImageInNewWindow(unsigned short* in_imageMemory);
	bool showImageInFrontWindow(unsigned short* in_imageMemory);
	bool showImageInNewWindow(QString& in_fileName);
	bool showImageInFrontWindow(QString& in_fileName);
private:
	QString d_rootDirectory;
	std::vector<ImageWidget*> d_imageWidgetVec;
	std::size_t d_frontWidgetIndex;
};

