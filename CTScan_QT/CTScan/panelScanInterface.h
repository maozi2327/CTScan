#pragma once
class panelScanInterface
{
public:
	panelScanInterface();
	virtual ~panelScanInterface();

	virtual void setFileName(QString in_fileName) = 0;
	virtual bool scanStart() = 0;
	virtual bool scanStop() = 0;
	virtual bool intialise() = 0;
	virtual void scanThread() = 0;
};

