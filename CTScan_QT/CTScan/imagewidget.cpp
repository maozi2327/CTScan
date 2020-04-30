#include "stdafx.h"		
#include "imagewidget.h"
#include "imagewidgetmanager.h"

//NOTEPAD//
//对主widget的gridlayout的sizeconstraint设置成noconstraint，然后不设置最大和最小size，
//则可以对主widget进行任意大小缩放。
//使用其他sizeconstraint例如defaultconstraint则会有限制，例如显示foldtree时会导致实际显示面积大于flodtree
//的宽度加上imagelabel的宽度，原因是设置了最大最小尺寸，如果设置了最大最小尺寸使显示面积正常，则又不能任意拉伸
//缩放。
//NOTEPAD//

//NOTEPAD//
//使用四个spacer布局在四周，且使用同样的缩放参数，可以让中间的布局始终居中显示
//NOTEPAD//

QVector<QRgb> ImageWidget::d_colorTable = initializeColorTable();
const int ImageWidget::d_initialZoomRatioFactor = 10;

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
	initialLabelAndImageSize();
}
ImageWidget::~ImageWidget()
{
}

void ImageWidget::initialLabelAndImageSize()
{
	d_desktopWidth = 1366;
	d_desktopHeight = 768;
	d_imageTopLeftXOnImage = 0;
	d_imageTopLeftYOnImage = 0;
	d_imageWidth = d_pixmap->width();
	d_imageHeight = d_pixmap->height();
	float wideRatio = float(d_desktopWidth) / d_imageWidth;
	float heightRatio = float(d_desktopHeight) / d_imageHeight;

	if (wideRatio >= heightRatio)
		if (heightRatio >= 2)
			d_zoomRatio = 1; //以高度为准
		else
			d_zoomRatio = float(d_desktopHeight) / d_imageHeight * 0.6;
	else
		if (wideRatio >= 2)
			d_zoomRatio = 1; //以宽度为准
		else
			d_zoomRatio = float(d_desktopWidth) / d_imageWidth * 0.6;

	d_zoomRecommendRatio = d_zoomRatio;
	d_imageScreenWidth = d_pixmap->width() * d_zoomRatio;
	d_imageScreenHeight = d_pixmap->height() * d_zoomRatio;
	int lineWidth = ui.imageLabel->lineWidth() * 2;
	setMouseTracking(true);
	ui.imageLabel->setFixedSize(d_imageScreenWidth + lineWidth, d_imageScreenHeight + lineWidth);
	d_zoomedPixMap = d_pixmap->scaledToWidth(d_imageScreenWidth);
	ui.imageLabel->setPixmap(d_zoomedPixMap);
	ui.imageLabel->setMouseTracking(true);
	resize(d_imageScreenWidth + lineWidth + ui.folderTree->width() + ui.foldButton->width() + 
		ui.horizontalSpacer->minimumSize().width() * 2,
		d_imageScreenHeight + lineWidth + ui.messageLabel->height() + ui.verticalSpacer->minimumSize().height() * 2);
}
bool ImageWidget::loadImage(QString& in_fileName)
{
	QImage image("D:/code/CTScan/CTScan_QT/x64/Debug/gain.tif");
	d_pixmap = new QPixmap;
	d_pixmap->convertFromImage(image);
	return true;
}
void ImageWidget::showEvent(QShowEvent* in_event)
{
}
void ImageWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (!ui.imageLabel->underMouse())
		return;

	d_mousePos = event->pos();
	int posX, posY;
	
	if (!caculateMousePosOnImage(posX, posY))
		return;

	QString mousePosStr;
	mousePosStr.sprintf("%d, %d", posX, posY);
	ui.messageLabel->setText(mousePosStr);
}
bool ImageWidget::caculateMousePosOnImage(int& in_posX, int& in_posY)
{
	d_imageLabelRect = ui.imageLabel->geometry();

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
		d_mousePosOnImageLabel.setX(d_mousePos.x() - d_imageLabelRect.left());
		d_mousePosOnImageLabel.setY(d_mousePos.y() - d_imageLabelRect.top());
		d_mousePosOnImage.setX(in_posX);
		d_mousePosOnImage.setY(in_posY);
		return true;
	}
	else
		return false;

}

void ImageWidget::resizeEvent(QResizeEvent *event)
{
}
void ImageWidget::on_foldButton_clicked()
{
	if (ui.folderTree->isVisible())
	{
		int wid = width();
		int newWidth = width() - ui.folderTree->width();
		ui.folderTree->hide();
		ui.foldButton->setText(tr("<"));
		resize(newWidth, height());
	}
	else
	{
		QLayout::SizeConstraint i  = ui.gridLayout->sizeConstraint();
		int wid = maximumWidth();
		int hei = maximumHeight();
		int floderWidth = ui.folderTree->width();
		int newWidth = width() + ui.folderTree->width();
		ui.folderTree->show();
		ui.foldButton->setText(tr(">"));
		resize(newWidth, height());
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
void ImageWidget::zoomImage()
{
	d_zoomedPixMap = d_pixmap->scaledToWidth(d_pixmap->width() * d_zoomRatio);
	QPixmap copy = d_zoomedPixMap.copy(d_imageTopLeftXOnImage, d_imageTopLeftYOnImage, d_imageScreenWidth, d_imageScreenHeight);
	ui.imageLabel->clear();
	ui.imageLabel->setPixmap(copy);
}
void ImageWidget::zoomOut()
{
	if (!ui.imageLabel->underMouse())
		return;

	if (d_zoomRatioFactor >= d_initialZoomRatioFactor)
	{
		int x = d_mousePos.x();
		int y = d_mousePos.y();
		caculateMousePosOnImage(x, y);
		d_zoomRatioFactor += 1;
		d_zoomRatio = d_zoomRecommendRatio * d_zoomRatioFactor / d_initialZoomRatioFactor;
		d_mousePosOnImage.setX(d_mousePosOnImage.x() * d_zoomRatio);
		d_mousePosOnImage.setY(d_mousePosOnImage.y() * d_zoomRatio);
		d_imageTopLeftXOnImage = d_mousePosOnImage.x() - (d_mousePosOnImageLabel.x() - (ui.imageLabel->width() - d_imageScreenWidth) / 2);
		d_imageTopLeftYOnImage = d_mousePosOnImage.y() - (d_mousePosOnImageLabel.y() - (ui.imageLabel->height() - d_imageScreenHeight) / 2);
		zoomImage();
	}
	else
	{
		int x = d_mousePos.x();
		int y = d_mousePos.y();
		caculateMousePosOnImage(x, y);
		d_zoomRatioFactor += 1;
		d_zoomRatio = d_zoomRecommendRatio * d_zoomRatioFactor / d_initialZoomRatioFactor;
		d_mousePosOnImage.setX(d_mousePosOnImage.x() * d_zoomRatio);
		d_mousePosOnImage.setY(d_mousePosOnImage.y() * d_zoomRatio);
		int lineWidth = ui.imageLabel->lineWidth() * 2;
		d_imageScreenWidth = d_pixmap->width() * d_zoomRatio;
		d_imageScreenHeight = d_pixmap->height() * d_zoomRatio;
		ui.imageLabel->setFixedSize(d_imageScreenWidth + lineWidth, d_imageScreenHeight + lineWidth);
		d_imageTopLeftXOnImage = 0;
		d_imageTopLeftYOnImage = 0;
		zoomImage();
		float ratio = float(1) / (d_zoomRatioFactor - 1);
		//float ratio = 0.1f / (d_zoomRatio + 0.1f);
		move(pos().x() - d_mousePosOnImageLabel.x() * ratio, pos().y() - d_mousePosOnImageLabel.y() * ratio);
		resize(d_imageScreenWidth + lineWidth + ui.folderTree->width() + ui.foldButton->width() +
			ui.horizontalSpacer->minimumSize().width() * 2,
			d_imageScreenHeight + lineWidth + ui.messageLabel->height() +
			ui.verticalSpacer->minimumSize().height() * 2);
	}

	zoomImage();
}
void ImageWidget::zoomIn()
{
	if (!ui.imageLabel->underMouse())
		return;

	if (d_zoomRatioFactor <= d_initialZoomRatioFactor + 1)
	{
		int x = d_mousePos.x();
		int y = d_mousePos.y();
		caculateMousePosOnImage(x, y);
		d_zoomRatioFactor -= 1;
		d_zoomRatio = d_zoomRecommendRatio * d_zoomRatioFactor / d_initialZoomRatioFactor;
		d_mousePosOnImage.setX(d_mousePosOnImage.x() * d_zoomRatio);
		d_mousePosOnImage.setY(d_mousePosOnImage.y() * d_zoomRatio);
		int lineWidth = ui.imageLabel->lineWidth() * 2;
		d_imageScreenWidth = d_pixmap->width() * d_zoomRatio;
		d_imageScreenHeight = d_pixmap->height() * d_zoomRatio;
		ui.imageLabel->setFixedSize(d_imageScreenWidth + lineWidth, d_imageScreenHeight + lineWidth);
		d_imageTopLeftXOnImage = 0;
		d_imageTopLeftYOnImage = 0;
		zoomImage();
		resize(d_imageScreenWidth + lineWidth + ui.folderTree->width() + ui.foldButton->width() +
			ui.horizontalSpacer->minimumSize().width() * 2,
			d_imageScreenHeight + lineWidth + ui.messageLabel->height() + 
			ui.verticalSpacer->minimumSize().height() * 2);

		if (d_zoomRatioFactor < d_initialZoomRatioFactor)
		{
			float ratio = float(1) / (d_zoomRatioFactor + 1);
			move(pos().x() + d_mousePosOnImageLabel.x() * ratio, pos().y() + d_mousePosOnImageLabel.y() * ratio);
		}
	}
	else
	{
		int x = d_mousePos.x();
		int y = d_mousePos.y();
		caculateMousePosOnImage(x, y);
		d_zoomRatioFactor -= 1;
		d_zoomRatio = d_zoomRecommendRatio * d_zoomRatioFactor / d_initialZoomRatioFactor;
		d_mousePosOnImage.setX(d_mousePosOnImage.x() * d_zoomRatio);
		d_mousePosOnImage.setY(d_mousePosOnImage.y() * d_zoomRatio);
		d_imageTopLeftXOnImage = d_mousePosOnImage.x() - (d_mousePosOnImageLabel.x() - (ui.imageLabel->width() - d_imageScreenWidth) / 2);
		d_imageTopLeftYOnImage = d_mousePosOnImage.y() - (d_mousePosOnImageLabel.y() - (ui.imageLabel->height() - d_imageScreenHeight) / 2);
		zoomImage();
	}
}