#pragma once
#include "conescanInterface.h"

class PanelImageProcess;
class ConeScan :
	public ConeScanInterface
{
public:
	ConeScan(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose);
	~ConeScan();
	virtual void setFileName(QString in_fileName);
	virtual void frameProcessCallback(unsigned short*);
	virtual bool beginScan();
	virtual bool stopScan();
	virtual bool saveFile(unsigned short* in_image);
	virtual bool intialise();

protected:
	virtual void scanThread();
	virtual bool loadAirData();

private:
	void sendCmdToController();
};

