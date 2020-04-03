#pragma once
#include "LineDetScanInterface.h"

class CT3Scan :
	public LineDetScanInterface
{
private:
	bool d_threadRun;
	float d_scanPos;
	QString d_fileName;
protected:
	void scanThread();
	void sendCmdToControl();
	virtual void saveFile();
public:
	CT3Scan(ControlerInterface* in_controler);
	~CT3Scan();
	virtual void stopScan();
	virtual bool startScan();
	virtual bool setGenerialFileHeader();
};

