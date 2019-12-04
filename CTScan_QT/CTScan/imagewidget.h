#pragma once

#include <QWidget>
#include "ui_imagewidget.h"

class ImageWidgetManager;
class ImageWidget : public QWidget
{
	Q_OBJECT

public:
	ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight, QWidget *parent = Q_NULLPTR);
	ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight, unsigned char* in_buffer,
		int in_width, int in_height, QWidget *parent = Q_NULLPTR);
	ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight, QString& in_fileName,
		QWidget *parent = Q_NULLPTR);

	bool loadImage(QString& in_fileName);
	bool loadImage(unsigned char* in_buffer, int in_width, int in_height);
	~ImageWidget();
	
	void keyPressEvent(QKeyEvent * in_event);
	void zoomOut();
	void zoomIn();
private:
	Ui::ImageWidget ui;
	ImageWidgetManager* d_manager;
	QPixmap* d_pixmap;
	QImage* d_image;
	int d_width;
	int d_height;
	static QVector<QRgb> d_colorTable;
	static QVector<QRgb> initializeColorTable();
};
