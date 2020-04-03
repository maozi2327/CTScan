#pragma once
#include "..\Public\headers\machineType.h"
#include <vector>
#include <map>
class ControlerInterface
{
protected:
	std::map<Axis, float> d_axisSpeed;
	std::map<Axis, float> d_axisPosition;
	std::map<Axis, float> d_axisWorkZero;
	virtual bool sendCmd() = 0;
public:
	ControlerInterface();
	virtual ~ControlerInterface();
	virtual bool initialConnection() = 0;

	virtual bool readReadyStatus() = 0;
	virtual bool readSaveStatus() = 0;
	virtual bool readWaitNextScanStatus() = 0;
	virtual bool readRunStatus() = 0;
	virtual std::map<Axis, float> readAxisSpeed() = 0;
	virtual float readAxisPostion(Axis in_axis) = 0;
	virtual std::map<Axis, float> readAxisPostion() = 0;
	virtual std::map<Axis, float> readAxisWorkZero() = 0;

	virtual void getSystemStatus() = 0;
	virtual void getAxisPosition() = 0;
	virtual void getAxisSpeed() = 0;
	virtual void getAxisWorkZero() = 0;

	virtual void setAxisSpeed(std::map<Axis, float>& in_speed) = 0;
	virtual void setAxisWorkZero(std::map<Axis, float>& in_workZero) = 0;
	virtual void decodePackages(char* in_package, int in_size) = 0;
};

