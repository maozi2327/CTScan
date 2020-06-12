#pragma once
#include "../Public/util/macro.h"
#include "../Public/headers/commandqueue.h"
#include "../Public/headers/panelimageprocess.h"
class ControllerInterface;
class panelScanInterface
{
protected:
	PanelImageProcess* d_imageProcess;
	TheQueue<unsigned short*> d_imageQueue;
	ControllerInterface* d_controller;
	
	virtual void processImage(unsigned short* in_image);
	QString d_fileName;
	bool d_bkgFlag;
	bool d_airFlag;
	bool d_defectFlag;
	bool d_averageFlag;
	bool d_orgFlag;
	int d_width;
	int d_height;
	int d_frames;
	int d_graduation;
	int d_round;
public:
	panelScanInterface();
	virtual ~panelScanInterface();
	void pushImageQueue(unsigned short* im_image);
	virtual void setDisposeFlag(bool in_bkgFlag, bool in_airFlag, bool in_defectFlag, bool in_averageFlag);
	virtual void setFileName(QString in_fileName) = 0;
	virtual bool scanStart() = 0;
	virtual bool scanStop() = 0;
	virtual bool intialise() = 0;
	virtual void scanThread() = 0;
signals:
	LOGSIGNAL
};

