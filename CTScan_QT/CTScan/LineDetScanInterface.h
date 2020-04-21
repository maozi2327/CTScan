#pragma once
#include <QTimer>
#include "IctHeader.h"
#include "SetupData.h"
#include "CtrlData.h"
#include "controllerinterface.h"
#include <memory>
class Thread;
class LineDetNetWork;
class LineDetImageProcess;

class LineDetScanInterface : public QObject
{
	Q_OBJECT
protected:
	QTimer d_timer;
	QString d_fileName;
	QString d_installDirectory;
	bool d_threadRun;

	ControllerInterface* d_controller;
	int	d_AccIndex;
	int d_accFrecIndex;
	int	d_TubeIndex;
	int	d_lineDetIndex;
	int d_;
	float d_SOD;
	float d_SDD;
	float d_colimateSize;
	float d_layerThickness;
	float d_sampleTime;
	float d_viewDiameter;
	bool d_standardInterpolation;
	int d_matrix;
	std::unique_ptr<LineDetNetWork> d_lineDetNetWork;
	std::unique_ptr<LineDetImageProcess> d_lineDetImageProcess;
	std::unique_ptr<Thread> d_scanThread;
	RayType d_rayType;
	SetupData* d_setupData;
	static ICT_HEADER d_ictHeader;
	virtual void scanThread() = 0;
	void saveOrgFile();
	virtual bool setGenerialFileHeader();
	virtual void sendCmdToControl() = 0;
	void CalculateView_ValidDetector(float in_diameter);
	virtual bool checkScanAble() = 0;
signals:
	void signalGraduationCount(int in_count);

public:
	LineDetScanInterface(ControllerInterface* in_controller);
	virtual ~LineDetScanInterface();
	void setFileName(QString& in_fileName) { d_fileName = in_fileName; };
	virtual bool startScan() = 0;
	virtual void stopScan() = 0;
};