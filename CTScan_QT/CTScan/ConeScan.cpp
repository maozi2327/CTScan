#include "stdafx.h"
#include "ConeScan.h"
#include "../PanelDll/PanelInterface.h"

ConeScan::ConeScan()
{
}


ConeScan::~ConeScan()
{
}
void ConeScan::setFileName(QString in_fileName)
{
	d_fileName = in_fileName;
}
bool ConeScan::scanStart()
{
	if(!d_panelInterface->setSampleMode(SampleMode::exTrigger))
		return false;

	d_panelInterface->beginAcquire(0);
}
void ConeScan::scanThread()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(50));
		unsigned short* image;
		d_imageQueue.pop(image);
	}
}
bool ConeScan::scanStop()
{
	return false;
}
bool ConeScan::intialise()
{
	return false;
}
