#include "stdafx.h"
#include "rayPanelMotionWidget.h"

RayPanelMotion::RayPanelMotion()
{
	ui.setupUi(this);
    
    //setFixedHeight(500);
    //ui.widget->setFixedHeight(500);
    //QPoint point = ui.sampleChooseButton->pos();
    //QRect rect = ui.sampleChooseButton->geometry();
    //ui.widget->setFixedHeight(point.x() + rect.height());
}
RayPanelMotion::~RayPanelMotion()
{

}

void RayPanelMotion::on_sampleChooseButton_clicked()
{
}
void RayPanelMotion::showEvent(QShowEvent* event)
{
	QPoint point = ui.sampleChooseButton->pos();
	QRect rect = ui.sampleChooseButton->geometry();
	setFixedHeight(point.y() + rect.height() + 20);
}