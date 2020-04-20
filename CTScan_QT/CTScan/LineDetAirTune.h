#pragma once
#include "LineDetScanInterface.h"
class LineDetAirTune :
	public LineDetScanInterface
{
protected:
	virtual void saveFile();
	virtual bool setGenerialFileHeader();
	virtual void scanThread();
	virtual void sendCmdToControl();
	virtual bool checkScanAble();
public:
	LineDetAirTune(ControlerInterface* in_controler);
	~LineDetAirTune();
	virtual bool startScan();
	virtual void stopScan();
};

