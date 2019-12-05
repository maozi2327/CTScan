#include "stdafx.h"		
#include "imagewidget.h"
#include "ImageWidgetManager.h"

const float ImageWidget::d_zoomRecommendRatio = 0.7f;
QVector<QRgb> ImageWidget::d_colorTable = initializeColorTable();

QVector<QRgb> ImageWidget::initializeColorTable()
{
	QVector<QRgb> colorTable;

	for (int i = 0; i != 256; ++i)
		colorTable.push_back(qRgb(i, i, i));

	return colorTable;
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent), d_windowWidth(in_windowWidth), d_windowHeight(in_windowHeight)
{
	ui.setupUi(this);
	QString str;
	loadImage(str);
	ui.imageLabel->setAlignment(Qt::AlignCenter);
	resize(d_windowWidth * 0.6, d_windowWidth * 0.6 * d_imageHeight / d_imageWidth);
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight,
	unsigned char* in_buffer, int in_width, int in_height, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent), d_windowWidth(in_windowWidth), d_windowHeight(in_windowHeight)
{
	loadImage(in_buffer, in_width, in_height);
	resize(1366 * 0.6, 1366 * 0.6 * d_imageHeight / d_imageWidth);
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_windowWidth, int in_windowHeight, 
	QString& in_fileName, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent), d_windowWidth(in_windowWidth), d_windowHeight(in_windowHeight)
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
	d_pixmap = new QPixmap;
	d_pixmap->convertFromImage(image);
	d_imageWidth = image.width();
	d_imageHeight = image.height();
	resize(1366 * d_zoomRatio, 1366 * d_zoomRatio * d_imageHeight / d_imageWidth);
	ui.imageLabel->setAlignment(Qt::AlignCenter);
	return true;
}
void ImageWidget::showEvent(QShowEvent* in_event)
{
	QWidget::showEvent(in_event);
	int width = ui.imageLabel->width();
	ui.imageLabel->setPixmap(d_pixmap->scaledToWidth(ui.imageLabel->width()));
	setMouseTracking(true);
	ui.imageLabel->setMouseTracking(true);
}
void ImageWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (ui.imageLabel->underMouse())
		;

	d_mousePos = event->pos();
}
void ImageWidget::on_foldButton_clicked()
{
	if (ui.folderTree->isVisible())
	{
		ui.folderTree->hide();
		ui.foldButton->setText(tr("<"));
	}
	else
	{
		ui.folderTree->show();
		ui.foldButton->setText(tr(">"));
	}
}
bool ImageWidget::loadImage(unsigned char* in_buffer, int in_width, int in_height)
{
	QImage* image = new QImage(in_buffer, in_width, in_height, in_width * sizeof(unsigned int),
		QImage::Format_Indexed8);
	d_image = image;
	d_imageWidth = image->width();
	d_imageHeight = image->height();
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
		zoomIn();
		break;
	case Qt::Key_Plus:
		zoomOut();
		break;
	}
}
void ImageWidget::zoomOut()
{
	if (!ui.imageLabel->underMouse())
		return;

	d_zoomRatio += 0.1;
	QPixmap pixmap =  d_pixmap->scaledToWidth(d_pixmap->width() * d_zoomRatio);
	d_mousePosOnImage.x *= d_zoomRatio;
	d_mousePosOnImage.y *= d_zoomRatio;
	int leftTopX = d_mousePosOnImage.x - ;
	int leftTopY = 0;
}
void ImageWidget::zoomIn()
{
	if (!ui.imageLabel->underMouse())
		return;
	
}