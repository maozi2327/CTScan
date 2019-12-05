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
	
	void zoomOut();
	void zoomIn();
protected:
	virtual void ImageWidget::showEvent(QShowEvent* in_event);
	void keyPressEvent(QKeyEvent * in_event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	Ui::ImageWidget ui;
	ImageWidgetManager* d_manager;
	QPixmap* d_pixmap;
	QImage* d_image;
	int d_imageWidth;
	int d_imageHeight;
	int d_imageScreenWidth;
	int d_imageScreenHeight;
	int d_windowWidth;
	int d_windowHeight;
	QPoint d_mousePos;
	QPoint d_mousePosOnImage;
	static QVector<QRgb> d_colorTable;
	static QVector<QRgb> initializeColorTable();
	float d_zoomRatio = 0.7f;
	const static float d_zoomRecommendRatio;
private slots:
	void on_foldButton_clicked();
};
