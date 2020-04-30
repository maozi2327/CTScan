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
	//ui.ct2MultiLayerComboBox->addItem(str.fromLocal8Bit("��ǰ��"));
	//ui.ct2MultiLayerComboBox->addItem(str.fromLocal8Bit("�ȼ��"));
	//ui.ct2MultiLayerComboBox->addItem(str.fromLocal8Bit("���"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360��"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360�ȼ��"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("180��"));
	//ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("����"));
	//ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("�ȼ��"));
	//ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("���"));
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("�ȱ���"));
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("���ȱ���"));
}

void LineDetScanWidget::initiliseCt3Controls(CT3Data& in_data)
{
	addItemToMatixVieSample(in_data, ui.ct3MatrixComboBox, ui.ct3ViewComboBox,
		ui.ct3SampleTimeComboBox, d_rayNum, d_detNum);
	QString str;
	ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("����"));
	ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("�ȼ��"));
	ui.ct3MultiLayerComboBox->addItem(str.fromLocal8Bit("���"));
}

void LineDetScanWidget::initiliseCt2Controls()
{
	//addItemToMatixVieSample(d_setupData->ct2Data, ui.ct2MatrixComboBox, ui.ct2ViewComboBox,
	//	ui.ct2SampleTimeComboBox, d_rayNum, d_detNum);
	//QString str;
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360��"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("360�ȼ��"));
	//ui.ct2ScanModeComboBox->addItem(str.fromLocal8Bit("180��"));
}

void LineDetScanWidget::initiliseDrControls()
{
	//addItemToMatixVieSample(d_setupData->drScanData, ui.drMatrixComboBox, ui.drViewComboBox,
	//	ui.drSampleTimeComboBox, d_rayNum, d_detNum);
	//QString str;
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("�ȱ���"));
	//ui.drRatioComboBox->addItem(str.fromLocal8Bit("���ȱ���"));
}

void LineDetScanWidget::on_startButton_clicked()
{
	if(ui.scanModeTab->currentWidget() == ui.ct3Tab)
		d_scanMap[ScanMode::CT3_SCAN]->startScan();
}

void LineDetScanWidget::on_saveDirButton_clicked()
{
	auto srcDirPath = QFileDialog::getExistingDirectory(this, "choose src Directory", "/");
}

void LineDetScanWidget::showMotorTable()
{
	d_motorControlDialog->show();
}
