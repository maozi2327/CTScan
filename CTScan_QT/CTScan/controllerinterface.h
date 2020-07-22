#pragma once
#include <QObJect>
#include "..\Public\headers\machineType.h"
#include <chrono>
#include <vector>
#include <map>
class ControllerInterface : public QObject
{
	Q_OBJECT
signals:
	void netWorkStsSginal(bool sts);
protected:
	std::map<Axis, float> d_axisSpeed;
	std::map<Axis, float> d_axisPosition;
	std::map<Axis, float> d_axisWorkZero;
	bool d_connected;
	std::chrono::milliseconds d_timeout;
	virtual void setConnectdSts() = 0;
	virtual bool sendCmd() = 0;
public:
	ControllerInterface();
	virtual ~ControllerInterface();
	
	virtual bool getConnected() = 0;
	virtual bool checkReadyToScan() = 0;

	virtual bool initialSend() = 0;
	virtual bool stopAll() = 0;
	virtual bool initialiseController() = 0;
	virtual bool axisSeekZero(Axis in_axis) = 0;
	virtual bool axisAbsMove(Axis in_axis, float in_pos) = 0;
	virtual bool axisRelMove(Axis in_axis, float in_pos) = 0;
	virtual bool sliceMove(float in_pos) = 0;
	

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

	virtual void stopGettingAxisPostion() = 0;

	virtual void setAxisSpeed(std::map<Axis, float>& in_speed) = 0;
	virtual void setAxisWorkZero(std::map<Axis, float>& in_workZero) = 0;
	virtual void sendToControl(char* in_package, int in_size, bool in_consist = false) = 0;
	virtual void decodePackages(char* in_package, int in_size) = 0;
};

