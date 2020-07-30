#pragma once
#include "conescanInterface.h"
class PanelImageProcess;
class ConeContinusScan :
	public ConeScanInterface
{
private:
	int d_graduationCount;
public:
	ConeContinusScan(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose);
	~ConeContinusScan();

	virtual bool stopScan();
	virtual void scanThread(std::promise<bool>& in_promise);
};

