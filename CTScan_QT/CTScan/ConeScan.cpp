#include "stdafx.h"
#include "ConeScan.h"
#include "../Public/headers/panelimageprocess.h"
#include "controllerinterface.h"

ConeScan::ConeScan(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose) :
	ConeScanInterface(in_panel, in_controller, in_ctDispose)
{

}
ConeScan::~ConeScan()
{

}

void ConeScan::setFileName(QString in_fileName)
{
	d_fileName = in_fileName;
}

void ConeScan::frameProcessCallback(unsigned short * in_image)
{
	ConeScanInterface::frameProcessCallback(in_image);
}

bool ConeScan::beginScan()
{
	d_controller->sendToControl(0, 0);
	d_scanThread.reset(new Thread(std::bind(&ConeScan::scanThread, this), std::ref(d_scanThreadRun)));
	d_scanThread->detach();
	d_imageProcessThread.reset(new Thread(std::bind(&ConeScan::imagePrecessThread, this), std::ref(d_imageProcessThreadRun)));
	d_scanThread->detach();
	std::function<void(unsigned short *)> frameCallback = std::bind(&ConeScan::frameProcessCallback, this, std::placeholders::_1);
	d_panel->setFrameCallback(frameCallback);
	d_panel->beginAcquire(0);
	return true;
}

bool ConeScan::stopScan()
{
	return false;
}
void ConeScan::scanThread()
{
	while (d_scanThread)
	{

	}
}
bool ConeScan::saveFile(unsigned short * in_image)
{
	return false;
}
bool ConeScan::intialise()
{
	return false;
}
