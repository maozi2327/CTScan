#pragma once
#include "..\Public\headers\machineType.h"
class ControlerInterface
{
public:
	ControlerInterface();
	virtual ~ControlerInterface();

	virtual float getAxisPostion(Axis in_axis) = 0;
	virtual bool getReadyStatus() = 0;
	virtual bool getSaveStatus() = 0;
	virtual bool getWaitNextScanStatus() = 0;
	virtual bool getRunStatus() = 0;
	virtual bool initialConnection() = 0;
	virtual bool sendCmd(unsigned char* in_cmd, size_t in_size) = 0;
};

