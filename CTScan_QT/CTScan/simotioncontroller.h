#pragma once
#include "controlerinterface.h"
class SimotionControler :
	public ControlerInterface
{
public:
	SimotionControler();
	~SimotionControler();

	virtual float getAxisPostion(Axis in_axis);
	virtual bool getReadyStatus();
	virtual bool getSaveStatus();
	virtual bool getWaitNextScanStatus();
	virtual bool getRunStatus();
	virtual bool initialConnection();
	virtual bool sendCmd(unsigned char* in_cmd, size_t in_size);
};

