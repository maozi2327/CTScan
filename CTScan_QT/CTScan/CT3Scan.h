#pragma once
#include "LineDetScanInterface.h"

class CT3Scan :
	public LineDetScanInterface
{
private:
	float d_scanPos;
	QString d_destFileName;
	unsigned int d_correctFlag;
protected:
	void scanThread();
	void sendCmdToControl();
	virtual void saveFile();
	virtual bool setGenerialFileHeader();
	virtual bool checkScanAble();
public:
	CT3Scan(ControlerInterface* in_controler);
	~CT3Scan();
	virtual void stopScan();
	virtual bool startScan();
};

