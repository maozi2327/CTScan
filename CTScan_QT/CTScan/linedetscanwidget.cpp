#include "stdafx.h"
#include "linedetscanwidget.h"
#include "motorcontrolwidget.h"
#include "simotioncontroller.h"
#include "../Public/headers/setupData.h"
#include "ct3scan.h"
LineDetScanWidget::LineDetScanWidget(MotorControlWidget* in_motorControl, std::vector<LineDetScanInterface*>& in_scan,
	SetupData* in_setupData, QWidget *parent)
	: QWidget(parent), d_motorControlDialog(in_motorControl)
	, d_detNum(1), d_rayNum(1), d_setupData(in_setupData)
{
	ui.setupUi(this);
	initiliseControls();

	for (auto itr : in_scan)
	{
		if (auto scan = dynamic_cast<CT3Scan*>(itr))
		{
			CT3Data data{ scan->getData() };
			initiliseCt3Controls(data);
			d_scanMap.insert({ ScanMode::CT3_SCAN, itr });
		}
	}

	connect(ui.ct3LayerPosLineEdit, &QLineEdit::returnPressed, this, &LineDetScanWidget::on_ct3LayerPosLineEdit_returnd);
}

LineDetScanWidget::~LineDetScanWidget()
{

}

void LineDetScanWidget::onNetworkStsChanged(bool in_netWorkSts)
{
	//ui.startButton->setEnabled(in_netWorkSts);
	//ui.startButton->setEnabled(in_netWorkSts);
	//ui.scanModeTab->setEnabled(in_netWorkSts);
}

void LineDetScanWidget::contextMenuEvent(QContextMenuEvent * event)
{
	showMotorTableAction = new QAction(tr("&paste"), this);
	connect(showMotorTableAction, &QAction::triggered, this, &LineDetScanWidget::showMotorTable);
	QMenu menu(this);
	menu.addAction(showMotorTableAction);
	menu.exec(event->globalPos());
}

void LineDetScanWidget::disableAllControls()
{

}

template<typename T>
void addItemToMatixVieSample(T& in_data, QComboBox* in_matrix, QComboBox* in_view, QComboBox* in_sampleTime,
	int in_rayNum, int in_detNum)
{
	//for(auto& matrixItr : in_data)
	//	if (matrixItr != in_data.end())
	//	{
	for (auto& value : in_data.Matrix)
		in_matrix->addItem(QString::number(value));

	for (auto& value : in_data.View)
		in_view->addItem(QString::number(value));

	for (auto& value : in_data.SampleTime)
		in_sampleTime->addItem(QString::number(value));
		//}
}
void LineDetScanWidget::initiliseControls()
{
	//addItemToMatixVieSample(d_setupData->ct2Data, ui.ct2MatrixComboBox, ui.ct2ViewComboBox,
	//	ui.ct2SampleTimeComboBox, d_rayNum, d_detNum);
	//addItemToMatixVieSample(d_setupData->ct3Data, ui.ct3MatrixComboBox, ui.ct3ViewComboBox, 
	//	ui.ct3SampleTimeComboBox, d_rayNum, d_detNum);
	//addItemToMatixVieSample(d_setupData->drScanData, ui.drMatrixComboBox, ui.drViewComboBox, 
	//	ui.drSampleTimeComboBox, d_rayNum, d_detNum);
	//QString str;
	//ui.ct2MultiLayerComboBox->addItem(str.fromLocal8Bit("当前层"));
	//ui.ct2MultiLayerComboBox->addItem(str.fromLocal8Bit("等间距"));
	//ui.ct2MultiLayerComboBox->addItem(str.fromLocal8Bit("多层"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360度"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360度间隔"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("180度"));
	//ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("单层"));
	//ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("等间距"));
	//ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("多层"));
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("等比例"));
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("不等比例"));
	ui.ct3LayerPosListWidget->setSortingEnabled(true);
	ui.scanModeTab->setCurrentWidget(ui.ct3Tab);
}

void LineDetScanWidget::initiliseCt3Controls(CT3Data& in_data)
{
	addItemToMatixVieSample(in_data, ui.ct3MatrixComboBox, ui.ct3ViewComboBox,
		ui.ct3SampleTimeComboBox, d_rayNum, d_detNum);
	QString str;
	ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("单层"));
	ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("多层等间距"));
	ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("多层不等间距"));
	ui.ct3MultiLayerComboBox->setCurrentText(str.fromLocal8Bit("单层"));
}

void LineDetScanWidget::initiliseCt2Controls()
{
	//addItemToMatixVieSample(d_setupData->ct2Data, ui.ct2MatrixComboBox, ui.ct2ViewComboBox,
	//	ui.ct2SampleTimeComboBox, d_rayNum, d_detNum);
	//QString str;
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360度"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360度间隔"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("180度"));
}

void LineDetScanWidget::initiliseDrControls()
{
	//addItemToMatixVieSample(d_setupData->drScanData, ui.drMatrixComboBox, ui.drViewComboBox,
	//	ui.drSampleTimeComboBox, d_rayNum, d_detNum);
	//QString str;
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("等比例"));
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("不等比例"));
}

void LineDetScanWidget::on_startButton_clicked()
{
	if (ui.scanModeTab->currentWidget() == ui.ct3Tab)
	{
		QString str;
		float layer;

		if (ui.ct3MultiLayerComboBox->currentText() == str.fromLocal8Bit("单层"))
			layer = ui.ct3LayerPosLineEdit->text().toFloat();
		else
			layer = ui.ct3LayerPosListWidget->item(0)->text().toFloat();

		int matrix = ui.ct3MatrixComboBox->currentText().toInt();
		int view = ui.ct3ViewComboBox->currentText().toInt();
		int sampleTime = ui.ct3SampleTimeComboBox->currentText().toInt();
		float angle = ui.ct3AngleLineEdit->text().toFloat();
		auto ct3 = d_scanMap[ScanMode::CT3_SCAN];
	
		if (dynamic_cast<CT3Scan*>(ct3)->setScanParameter(layer, matrix, view, sampleTime, angle))
			ct3->startScan();
	}
}

void LineDetScanWidget::on_saveDirButton_clicked()
{
	auto srcDirPath = QFileDialog::getExistingDirectory(this, "choose src Directory", "/");
}

void LineDetScanWidget::on_ct3MultiLayerComboBox_currentIndexChanged(const QString& in_text)
{
	QString str;
	
	if (in_text == str.fromLocal8Bit("单层"))
	{
		ui.ct3LayerPosLineEdit->show();
		ui.ct3LayerSpaceLineEdit->hide();
		ui.ct3SpaceNumLineEdit->hide();
		ui.ct3SpaceNumLabel->hide();
		ui.ct3LayerSpaceLabel->hide();
	}
	else if (in_text == str.fromLocal8Bit("多层等间距"))
	{
		ui.ct3LayerPosLineEdit->show();
		ui.ct3LayerSpaceLineEdit->show();
		ui.ct3SpaceNumLineEdit->show();
		ui.ct3SpaceNumLabel->show();
		ui.ct3LayerSpaceLabel->show();
	}
	else if (in_text == str.fromLocal8Bit("多层不等间距"))
	{
		ui.ct3LayerPosLineEdit->show();
		ui.ct3LayerSpaceLineEdit->hide();
		ui.ct3SpaceNumLineEdit->hide();
		ui.ct3SpaceNumLabel->hide();
		ui.ct3LayerSpaceLabel->hide();
	}
}

void LineDetScanWidget::on_ct3LayerPosLineEdit_returnd()
{
	QString value;
	ui.ct3LayerPosListWidget->addItem(QString::number(ui.ct3LayerPosLineEdit->text().toFloat(), 10, 1));
}

void LineDetScanWidget::showMotorTable()
{
	d_motorControlDialog->show();
}
