#pragma once
#include "imagewidget.h"
#include <vector>
#include <memory>
class ImageWidgetManager
{
public:
	ImageWidgetManager();
	~ImageWidgetManager();

	bool showImageInNewWindow(unsigned char* in_imageMemory, int in_width, int in_height);
	bool showImageInFrontWindow(unsigned char* in_imageMemory, int in_width, int in_height);
	bool showImageInNewWindow(QString& in_fileName);
	bool showImageInFrontWindow(QString& in_fileName);
private:
	QString d_rootDirectory;
	std::vector<ImageWidget*> d_imageWidgetVec;
	std::size_t d_frontWidgetIndex;
};

