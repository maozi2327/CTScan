#pragma once
#include "conescanInterface.h"

class PanelImageProcess;
class ConeScan :
	public ConeScanInterface
{
public:
	ConeScan(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose);
	~ConeScan();
	virtual void frameProcessCallback(unsigned short*);
	virtual bool stopScan();
	virtual bool intialise();

protected:
	virtual void scanThread();
	virtual bool loadAirData();

private:
	void sendCmdToController();
};

