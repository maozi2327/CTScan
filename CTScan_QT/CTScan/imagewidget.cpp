#include "stdafx.h"
#include "imagewidget.h"
#include "ImageWidgetManager.h"

QVector<QRgb> ImageWidget::d_colorTable = initializeColorTable();

QVector<QRgb> ImageWidget::initializeColorTable()
{
	QVector<QRgb> colorTable;

	for (int i = 0; i != 256; ++i)
		colorTable.push_back(qRgb(i, i, i));

	return colorTable;
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent)
{
	ui.setupUi(this);
	QString str;
	loadImage(str);
	ui.imageLabel->setAlignment(Qt::AlignCenter);
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight,
	unsigned char* in_buffer, int in_width, int in_height, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent)
{
	loadImage(in_buffer, in_width, in_height);
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight, 
	QString& in_fileName, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent)
{
	ui.setupUi(this);
	loadImage(in_fileName);
}
ImageWidget::~ImageWidget()
{
}

bool ImageWidget::loadImage(QString& in_fileName)
{
	QImage image("D:/code/CTScan/CTScan_QT/x64/Debug/gain_small.tif");
	QPixmap pixmap;
	pixmap.convertFromImage(image);
	d_width = image.width();
	d_height = image.height();
	ui.imageLabel->setPixmap(pixmap);
	ui.imageLabel->setAlignment(Qt::AlignCenter);
	setFixedWidth(200);
	//ui.imageLabel->setFixedSize(image.width(), image.height());
	//show();
	return true;
}
bool ImageWidget::loadImage(unsigned char* in_buffer, int in_width, int in_height)
{
	QImage* image = new QImage(in_buffer, in_width, in_height, in_width * sizeof(unsigned int),
		QImage::Format_Indexed8);
	d_image = image;
	d_width = image->width();
	d_height = image->height();
	d_image->setColorTable(d_colorTable);
	QPixmap pixmap;
	pixmap.convertFromImage(*d_image);
	ui.imageLabel->setPixmap(pixmap);
	ui.imageLabel->setAlignment(Qt::AlignCenter);
	return true;
}
void ImageWidget::keyPressEvent(QKeyEvent* in_event)
{
	switch (in_event->key())
	{
	case Qt::Key_Minus:
		;
		break;
	case Qt::Key_Plus:
		;
		break;
	}
}
void ImageWidget::zoomOut()
{

}
void ImageWidget::zoomIn()
{

}