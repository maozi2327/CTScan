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
	LineDetAirTune(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor);
	~LineDetAirTune();
	virtual bool startScan();
	virtual void stopScan();
};

