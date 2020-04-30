#include "stdafx.h"
#include "motorcontrolwidget.h"
#include "controllerinterface.h"
#include "..\Public\headers\machineType.h"

MotorControlWidget::MotorControlWidget(ControllerInterface* in_controller, QWidget *parent)
	: QWidget(parent)
	, d_controller(in_controller)
{
	ui.setupUi(this);
	//d_controller->getAxisPosition();
}

MotorControlWidget::~MotorControlWidget()
{

}

void MotorControlWidget::on_objRotAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::objRotation, ui.objRotationPosEdit->text().toFloat());
}

void MotorControlWidget::updateAxisStatus()
{
	std::map<Axis, float> axisPos = d_controller->readAxisPostion();
	ui.rayLayerStaticLabel->setText(QString("%1").arg(axisPos[Axis::rayLayer]));
	ui.objRadialStaticLabel->setText(QString("%1").arg(axisPos[Axis::objRadial]));
	ui.objRotStaticLabel->setText(QString("%1").arg(axisPos[Axis::objRotation]));
	ui.objTranslationStaticLabel->setText(QString("%1").arg(axisPos[Axis::objTranslation]));
	ui.detLayerStaticLabel->setText(QString("%1").arg(axisPos[Axis::detLayer]));
	ui.detRadialStaticLabel->setText(QString("%1").arg(axisPos[Axis::detRadial]));
	ui.detTranslationStaticLabel->setText(QString("%1").arg(axisPos[Axis::detTranslation]));
}

void MotorControlWidget::on_objRotNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::objRotation, -ui.objRotationPosEdit->text().toFloat());
}

void MotorControlWidget::on_objRotPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::objRotation, ui.objRotationPosEdit->text().toFloat());
}

void MotorControlWidget::on_objTranslationAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_objTranslationNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, -ui.objTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_objTranslationPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_objRadialAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_objRadialNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, -ui.objTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_objRadialPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_detLayerAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::detLayer , ui.detLayerPosEdit->text().toFloat());
}

void MotorControlWidget::on_detLayerNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::detLayer, -ui.detLayerPosEdit->text().toFloat());
}

void MotorControlWidget::on_detLayerPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::detLayer, ui.detLayerPosEdit->text().toFloat());
}

void MotorControlWidget::on_detTranslationAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::detTranslation, ui.detTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_detTranslationNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::detTranslation, -ui.detTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_detTranslationPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::detTranslation, ui.detTranslationPosEdit->text().toFloat());
}

void MotorControlWidget::on_detRadialAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::detRadial, ui.detRadialPosEdit->text().toFloat());
}

void MotorControlWidget::on_detRadialNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::detRadial, -ui.detRadialPosEdit->text().toFloat());
}

void MotorControlWidget::on_detRadialPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::detRadial, ui.detRadialPosEdit->text().toFloat());
}

void MotorControlWidget::on_rayLayerAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::rayLayer, ui.rayLayerPosEdit->text().toFloat());
}

void MotorControlWidget::on_rayLayerNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::rayLayer, -ui.rayLayerPosEdit->text().toFloat());
}

void MotorControlWidget::on_rayLayerPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::rayLayer, ui.rayLayerPosEdit->text().toFloat());
}
