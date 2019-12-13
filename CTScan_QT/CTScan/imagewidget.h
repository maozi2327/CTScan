#pragma once

#include <QWidget>
#include "ui_imagewidget.h"

class ImageWidgetManager;
class ImageWidget : public QWidget
{
	Q_OBJECT

public:
	ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_desktopWidth, int in_windowHeight, QWidget *parent = Q_NULLPTR);
	ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_desktopWidth, int in_windowHeight, unsigned char* in_buffer,
		int in_width, int in_height, QWidget *parent = Q_NULLPTR);
	ImageWidget(ImageWidgetManager* in_imageWidgetManager, int in_desktopWidth, int in_windowHeight, QString& in_fileName,
		QWidget *parent = Q_NULLPTR);

	bool loadImage(QString& in_fileName);
	bool loadImage(unsigned char* in_buffer, int in_width, int in_height);
	~ImageWidget();
	
	void zoomOut();
	void zoomIn();
protected:
	virtual void showEvent(QShowEvent* in_event);
	virtual void resizeEvent(QResizeEvent *event);
	void keyPressEvent(QKeyEvent * in_event);
	void mouseMoveEvent(QMouseEvent *event);
	void zoomImage();
	void initialLabelAndImageSize();
private:
	Ui::ImageWidget ui;
	ImageWidgetManager* d_manager;
	QPixmap* d_pixmap;
	QPixmap d_zoomedPixMap;
	QImage* d_image;
	int d_imageWidth;
	int d_imageHeight;
	int d_imageScreenWidth;
	int d_imageScreenHeight;
	int d_desktopWidth;
	int d_desktopHeight;
	int d_initialdesktopWidth;
	int d_initialWindowHeight;
	int d_imageTopLeftXOnLabel;
	int d_imageTopLeftYOnLabel;
	int d_imageTopLeftXOnImage;
	int d_imageTopLeftYOnImage;
	int d_mousePosToImageLeft;
	int d_mousePosToImageRight;
	QPoint d_mousePos;
	QPoint d_mousePosOnImageLabel;
	QPoint d_mousePosOnImage;
	QRect d_imageLabelRect;
	static QVector<QRgb> d_colorTable;
	static QVector<QRgb> initializeColorTable();
	float d_zoomRatio = 0.7f;
	int d_zoomRatioFactor = 10;
	float d_zoomRecommendRatio;
	static const int d_initialZoomRatioFactor;
	bool caculateMousePosOnImage(int& in_posX, int& in_posY);
private slots:
	void on_foldButton_clicked();
};
