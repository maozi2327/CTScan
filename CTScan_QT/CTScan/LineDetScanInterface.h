#pragma once
#include <QTimer>
#include "IctHeader.h"
#include "CtrlData.h"
#include "controlerinterface.h"
class LineDetScanInterface
{
	Q_OBJECT
protected:
	QTimer d_timer;
	virtual void run() = 0;
	QString d_fileName;
	ControlerInterface* d_controler;
	virtual void createFile() = 0;
public:
	LineDetScanInterface(ControlerInterface* in_controler) : d_controler(in_controler) {}
	virtual ~LineDetScanInterface();
	void setFileName(QString& in_fileName) { d_fileName = in_fileName; };
	virtual void checkScanAble() = 0;
	virtual void startScan() = 0;
	virtual void stopScan() = 0;
};