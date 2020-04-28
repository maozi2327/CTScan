#include "stdafx.h"
#include "MotorControl.h"
#include "controllerinterface.h"
#include "..\Public\headers\machineType.h"

MotorControl::MotorControl(ControllerInterface* in_controller, QWidget *parent)
	: QWidget(parent)
	, d_controller(in_controller)
{
	ui.setupUi(this);
	//d_controller->getAxisPosition();
}

MotorControl::~MotorControl()
{

}

void MotorControl::on_objRotAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::objRotation, ui.objRotationPosEdit->text().toFloat());
}

void MotorControl::updateAxisStatus()
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

void MotorControl::on_objRotNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::objRotation, -ui.objRotationPosEdit->text().toFloat());
}

void MotorControl::on_objRotPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::objRotation, ui.objRotationPosEdit->text().toFloat());
}

void MotorControl::on_objTranslationAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControl::on_objTranslationNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, -ui.objTranslationPosEdit->text().toFloat());
}

void MotorControl::on_objTranslationPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControl::on_objRadialAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControl::on_objRadialNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, -ui.objTranslationPosEdit->text().toFloat());
}

void MotorControl::on_objRadialPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::objTranslation, ui.objTranslationPosEdit->text().toFloat());
}

void MotorControl::on_detLayerAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::detLayer , ui.detLayerPosEdit->text().toFloat());
}

void MotorControl::on_detLayerNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::detLayer, -ui.detLayerPosEdit->text().toFloat());
}

void MotorControl::on_detLayerPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::detLayer, ui.detLayerPosEdit->text().toFloat());
}

void MotorControl::on_detTranslationAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::detTranslation, ui.detTranslationPosEdit->text().toFloat());
}

void MotorControl::on_detTranslationNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::detTranslation, -ui.detTranslationPosEdit->text().toFloat());
}

void MotorControl::on_detTranslationPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::detTranslation, ui.detTranslationPosEdit->text().toFloat());
}

void MotorControl::on_detRadialAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::detRadial, ui.detRadialPosEdit->text().toFloat());
}

void MotorControl::on_detRadialNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::detRadial, -ui.detRadialPosEdit->text().toFloat());
}

void MotorControl::on_detRadialPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::detRadial, ui.detRadialPosEdit->text().toFloat());
}

void MotorControl::on_rayLayerAbsPosButton_clicked()
{
	d_controller->axisAbsMove(Axis::rayLayer, ui.rayLayerPosEdit->text().toFloat());
}

void MotorControl::on_rayLayerNegativeButton_clicked()
{
	d_controller->axisRelMove(Axis::rayLayer, -ui.rayLayerPosEdit->text().toFloat());
}

void MotorControl::on_rayLayerPositiveButton_clicked()
{
	d_controller->axisRelMove(Axis::rayLayer, ui.rayLayerPosEdit->text().toFloat());
}
