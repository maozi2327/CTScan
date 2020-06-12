#pragma once
#include "panelScanInterface.h"
 
class PanelInterface;
class ConeScan :
	public panelScanInterface
{
private:
	PanelInterface* d_panelInterface;
public:
	ConeScan();
	~ConeScan();
	virtual void setFileName(QString in_fileName);
	virtual bool scanStart();
	virtual bool scanStop();
	virtual bool intialise();
	virtual void scanThread();
};

