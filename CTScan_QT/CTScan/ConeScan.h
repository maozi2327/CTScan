#pragma once
#include "conescanInterface.h"

class PanelImageProcess;
class ConeScan :
	public ConeScanInterface
{
private:
public:
	ConeScan(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose);
	~ConeScan();
	virtual void setFileName(QString in_fileName);
	virtual void frameProcessCallback(unsigned short*);
	virtual bool beginScan();
	virtual bool stopScan();
	virtual void scanThread();
	virtual bool saveFile(unsigned short* in_image);
	virtual bool intialise();
};

