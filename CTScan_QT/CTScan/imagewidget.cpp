#include "stdafx.h"		
#include "imagewidget.h"
#include "ImageWidgetManager.h"

const float ImageWidget::d_zoomRecommendRatio = 1.0f;
QVector<QRgb> ImageWidget::d_colorTable = initializeColorTable();

QVector<QRgb> ImageWidget::initializeColorTable()
{
	QVector<QRgb> colorTable;

	for (int i = 0; i != 256; ++i)
		colorTable.push_back(qRgb(i, i, i));

	return colorTable;
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_desktopWidth, int in_windowHeight, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent), d_desktopWidth(in_desktopWidth), d_desktopHeight(in_windowHeight)
{
	ui.setupUi(this);
	QString str;
	loadImage(str);
	ui.imageLabel->setAlignment(Qt::AlignCenter);
	d_desktopWidth = 1366;
	d_desktopHeight = 768;

	if (float(d_desktopWidth) / d_desktopHeight > float(d_imageWidth) / d_imageHeight)
	{
		resize(d_desktopWidth * 0.6, d_desktopHeight * 0.6 * d_imageHeight / d_imageWidth);
	}
	else
	{
		resize(d_desktopHeight * 0.6 * d_imageWidth / d_imageHeight, d_desktopHeight * 0.6);
	}
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_desktopWidth, int in_windowHeight,
	unsigned char* in_buffer, int in_width, int in_height, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent), d_desktopWidth(in_desktopWidth), d_desktopHeight(in_windowHeight)
{
	loadImage(in_buffer, in_width, in_height);
	
}
ImageWidget::ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_desktopWidth, int in_windowHeight, 
	QString& in_fileName, QWidget *parent)
	: d_manager(in_imageWidgetManager), QWidget(parent), d_desktopWidth(in_desktopWidth), d_desktopHeight(in_windowHeight)
{
	ui.setupUi(this);
	loadImage(in_fileName);
	d_desktopWidth = 1366;
	d_desktopHeight = 768;
	float wideRatio = float(d_desktopWidth) / d_imageWidth;
	float heightRatio = float(d_desktopHeight) / d_imageHeight;

	if (wideRatio >= heightRatio)
		if (heightRatio >= 2)
			d_zoomRatio = 1; //以高度为准
		else
			d_zoomRatio = 1 / heightRatio;
	else
		if (wideRatio >= 2)
			d_zoomRatio = 1; //以宽度为准
		else
			d_zoomRatio = 1 / wideRatio;
	
	d_imageTopLeftXOnImage = 0;
	d_imageTopLeftYOnImage = 0;
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
	ui.imageLabel->setAlignment(Qt::AlignCenter);
	return true;
}
void ImageWidget::showEvent(QShowEvent* in_event)
{
	d_imageScreenWidth = d_pixmap->width() * d_zoomRatio;
	d_imageScreenHeight = d_pixmap->height() * d_zoomRatio;
	int lineWidth = ui.imageLabel->lineWidth() * 2;
	ui.imageLabel->resize(d_imageScreenWidth + lineWidth, d_imageScreenHeight + lineWidth);
	ui.imageLabel->setPixmap(d_pixmap->scaledToWidth(d_imageScreenWidth));
	ui.imageLabel->setMouseTracking(true);
	setMouseTracking(true);
}
void ImageWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (!ui.imageLabel->underMouse())
		return;

	d_imageLabelRect = ui.imageLabel->geometry();
	d_mousePos = event->pos();
	int posX, posY;
	
	if (!caculateMousePosOnImage(posX, posY))
		return;

	QString mousePosStr;
	mousePosStr.sprintf("%d, %d", posX, posY);
	ui.messageLabel->setText(mousePosStr);
	d_mousePosOnImage.setX(posX);
	d_mousePosOnImage.setY(posY);
}
bool ImageWidget::caculateMousePosOnImage(int& in_posX, int& in_posY)
{
	if (d_mousePos.x() >= d_imageLabelRect.right() || d_mousePos.x() <= d_imageLabelRect.left() || 
		d_mousePos.y() >= d_imageLabelRect.bottom() || d_mousePos.y() <= d_imageLabelRect.top())
		return false;

	int labelWidth = ui.imageLabel->width();
	int labelHeight = ui.imageLabel->height();
	int imageScreenTopPos = (labelHeight - d_imageScreenHeight) / 2;
	int imageScreenDownPos = imageScreenTopPos + d_imageScreenHeight;
	int imageScreenLeftPos = (labelWidth - d_imageScreenWidth) / 2;
	int imageScreenRightPos = imageScreenLeftPos + d_imageScreenWidth;

	if (d_mousePos.x() - d_imageLabelRect.left() > imageScreenLeftPos && d_mousePos.x() - d_imageLabelRect.left() < imageScreenRightPos &&
		d_mousePos.y() - d_imageLabelRect.top() > imageScreenTopPos && d_mousePos.y() - d_imageLabelRect.top() < imageScreenDownPos)
	{
		d_mousePosToImageLeft = d_mousePos.x() - d_imageLabelRect.left() - imageScreenLeftPos;
		d_mousePosToImageRight = d_mousePos.y() - d_imageLabelRect.top() - imageScreenTopPos;
		in_posX = (d_mousePosToImageLeft + d_imageTopLeftXOnImage) / d_zoomRatio;
		in_posY = (d_mousePosToImageRight + d_imageTopLeftYOnImage) / d_zoomRatio;
		return true;
	}
	else
		return false;

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
void ImageWidget::paintEvent(QPaintEvent *event)
{
	int labelWidth = ui.imageLabel->width();
	int labelHeight = ui.imageLabel->height();
	QPixmap pixmap = d_pixmap->scaledToWidth(d_pixmap->width() * d_zoomRatio);
	QPixmap copy = pixmap.copy(d_imageTopLeftXOnImage, d_imageTopLeftYOnImage, d_imageScreenWidth, d_imageScreenHeight);
	ui.imageLabel->setPixmap(copy);
}
void ImageWidget::zoomOut()
{
	if (!ui.imageLabel->underMouse())
		return;

	if (d_zoomRatio >= d_zoomRecommendRatio)
	{
		d_zoomRatio += 0.25;
		d_mousePosOnImage.setX(d_mousePosOnImage.x() * d_zoomRatio);
		d_mousePosOnImage.setY(d_mousePosOnImage.y() * d_zoomRatio);
		d_imageTopLeftXOnImage = d_mousePosOnImage.x() - (d_mousePos.x() - (ui.imageLabel->width() - d_imageScreenWidth) / 2);
		d_imageTopLeftYOnImage = d_mousePosOnImage.y() - (d_mousePos.y() - (ui.imageLabel->height() - d_imageScreenHeight) / 2);
		
		repaint();
	}
	else
	{
		resize(d_initialdesktopWidth * d_zoomRatio, d_initialWindowHeight * d_zoomRatio);
	}
}
void ImageWidget::zoomIn()
{
	if (!ui.imageLabel->underMouse())
		return;
	
}