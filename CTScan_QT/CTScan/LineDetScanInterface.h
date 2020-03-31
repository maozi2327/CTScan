#pragma once
#include <QTimer>
#include "IctHeader.h"
#include "SetupData.h"
#include "CtrlData.h"
#include "controlerinterface.h"
class LineDetScanInterface
{
	Q_OBJECT
protected:
	QTimer d_timer;
	QString d_fileName;
	ControlerInterface* d_controler;
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
	RayType d_rayType;
	SetupData* d_setupData;
	static ICT_HEADER d_ictHeader;
	virtual void scanThread() = 0;
	virtual void createFile() = 0;
	virtual bool setGenerialFileHeader();
	virtual void sendCmdToControl() = 0;
	void CalculateView_ValidDetector(float in_diameter);
public:
	LineDetScanInterface(ControlerInterface* in_controler) : d_controler(in_controler) {}
	virtual ~LineDetScanInterface();
	void setFileName(QString& in_fileName) { d_fileName = in_fileName; };
	virtual void setFileHeader() = 0;
	virtual void checkScanAble() = 0;
	virtual void startScan() = 0;
	virtual void stopScan() = 0;
};