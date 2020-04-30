#pragma once
#include "LineDetScanInterface.h"
#include "../Public/headers/setupdata.h"
class CT3Scan :
	public LineDetScanInterface
{
private:
	CT3Data d_ct3Data;
	float d_scanPos;
	QString d_destFileName;
	unsigned int d_correctFlag;
protected:
	void scanThread();
	void sendCmdToControl();
	virtual void saveFile();
	virtual bool setGenerialFileHeader();
	virtual bool checkScanAble();
	virtual bool canScan();
public:
	CT3Scan(ControllerInterface* in_controller, CT3Data& in_data);
	~CT3Scan();
	virtual void stopScan();
	virtual bool startScan();
	CT3Data getData();
};

