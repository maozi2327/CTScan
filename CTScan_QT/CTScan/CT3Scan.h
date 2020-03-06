#pragma once
#include "LineDetScanInterface.h"

class CT3Scan :
	public LineDetScanInterface
{
private:
	bool d_threadRun;
protected:
	void scanThread();
public:
	CT3Scan(ControlerInterface* in_controler);
	void stopScan();
	void startScan();
};

