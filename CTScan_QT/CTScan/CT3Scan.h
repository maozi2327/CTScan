#pragma once
#include "LineDetScanInterface.h"

class CT3Scan :
	public LineDetScanInterface
{
private:
	bool d_threadRun;
	float d_scanPos;
protected:
	void scanThread();
	void sendCmdToControl();
public:
	CT3Scan(ControlerInterface* in_controler);
	void stopScan();
	void startScan();
	virtual bool setGenerialFileHeader();
};

