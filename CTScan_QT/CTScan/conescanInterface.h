#pragma once
#include <future>
#include <memory>
#include "..\PanelDll\panel.h"
#include "PanelImageProcess.h"
#include "controllerinterface.h"

class ConeScanInterface
{
protected:
	int d_graduation;
	QString d_fileName;
	Panel* d_panel;
	PanelImageProcess* d_ctDispose;
	bool d_is_saveOrg;
	bool d_is_dispose;
	ControllerInterface* d_controller;
	std::unique_ptr<std::promise<bool>> d_ringThreadPromisePtr;
public:
	ConeScanInterface(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose);
	virtual ~ConeScanInterface();
	
	virtual void setGraduation(int in_graduation) { d_graduation = in_graduation; };
	virtual bool beginScan() = 0;
	virtual bool stopScan() = 0;
	virtual void scanThread() = 0;
	virtual bool saveFile(unsigned short* in_image) = 0;
};