#pragma once

#include <QWidget>
#include "ui_MotorControl.h"

class ControlerInterface;
class MotorControl : public QWidget
{
	Q_OBJECT
private:
	ControlerInterface* d_controler;

public:
	MotorControl(QWidget *parent = Q_NULLPTR);
	~MotorControl();


private:
	Ui::MotorControl ui;

private slots:
	void on_tableRotAbsPosButton_clicked();
	void on_tableRotNegativeButton_clicked();
	void on_tableRotPositiveButton_clicked();

	void on_tableTranslationAbsPosButton_clicked();
	void on_tableTranslationNegativeButton_clicked();
	void on_tableTranslationPositiveButton_clicked();

	void on_tableRadialAbsPosButton_clicked();
	void on_tableRadialNegativeButton_clicked();
	void on_tableRadialPositiveButton_clicked();

	void on_detLayerAbsPosButton_clicked();
	void on_detLayerNegativeButton_clicked();
	void on_detLayerPositiveButton_clicked();

	void on_detTranslationAbsPosButton_clicked();
	void on_detTranslationNegativeButton_clicked();
	void on_detTranslationPositiveButton_clicked();

	void on_detRadialAbsPosButton_clicked();
	void on_detRadialNegativeButton_clicked();
	void on_detRadialPositiveButton_clicked();

	void on_rayLayerAbsPosButton_clicked();
	void on_rayLayerNegativeButton_clicked();
	void on_rayLayerPositiveButton_clicked();
};
