#pragma once
#include "ui_raypanelmotion.h"
class Panel;
class RayPanelMotion : public QWidget
{
	Q_OBJECT

public:
	RayPanelMotion();
	~RayPanelMotion();
private:
	Ui::rayPanelMotionWidget ui;
	Panel* d_panel;
protected:
	void showEvent(QShowEvent* event);
public slots:
	void on_sampleChooseButton_clicked();
};