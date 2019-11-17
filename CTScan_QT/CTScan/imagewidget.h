#pragma once

#include <QWidget>
#include "ui_imagewidget.h"

class ImageWidgetManager;
class ImageWidget : public QWidget
{
	Q_OBJECT

public:
	ImageWidget(ImageWidgetManager* in_imageWidgetManager, QWidget *parent = Q_NULLPTR);
	~ImageWidget();
	
	bool loadImage(QString& in_fileName);
	bool loadImage(unsigned short* in_imageMemory);
private:
	Ui::ImageWidget ui;
	ImageWidgetManager* d_manager;
};
