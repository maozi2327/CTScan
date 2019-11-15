#pragma once
#include "ui_raypanelmotion.h"
class RayPanelMotion : public QWidget
{
	Q_OBJECT

public:
	RayPanelMotion();
	~RayPanelMotion();
private:
	Ui::rayPanelMotionWidget ui;
protected:
	void showEvent(QShowEvent* event);
public slots:
	void on_sampleChooseButton_clicked();
};