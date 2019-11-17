#pragma once
#include "conescanInterface.h"
class ConeContinusScan :
	public ConeScanInterface
{
private:
	int d_graduationCount;
public:
	ConeContinusScan(Panel* in_panel, ControlerInterface* in_controller, CTDispose* in_ctDispose);
	~ConeContinusScan();

	virtual bool beginScan();
	virtual bool stopScan();
	virtual void scanThread(std::promise<bool>& in_promise);
	virtual bool saveFile(unsigned short* in_image);
};
