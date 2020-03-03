#pragma once
#include "LineDetScanInterface.h"

class CT3Scan :
	public LineDetScanInterface
{
private:
	bool d_threadRun;
protected:
	void run();
public:
	CT3Scan(ControlerInterface* in_controler);
	void stopScan();
	void startScan();
};

