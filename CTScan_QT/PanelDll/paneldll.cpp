#include "paneldll.h"
#include "PanelInterface.h"
#ifdef NIMAQPANEL
#include "NimaqPanel.h"
#endif

PanelDll::PanelDll() : d_panelInterface(new REALPANEL)
{
	
}
bool PanelDll::initilise()
{
	return d_panelInterface->initialise();
}
bool PanelDll::setSampleTime(int in_milliseconds)
{
	return d_panelInterface->setSampleTime(in_milliseconds);
}
bool PanelDll::setFrames(int in_frames)
{
	return d_panelInterface->setFrames(in_frames);
}
bool PanelDll::setSampleMode(SampleMode in_sampleMode)
{
	return d_panelInterface->setSampleMode(in_sampleMode);
}
bool PanelDll::setGainFactor(int in_gainFactor) 
{
	return d_panelInterface->setGainFactor(in_gainFactor);
}

//采集多帧时会将数据连续存储在同一内存区域
bool PanelDll::getPanelSize(int& out_width, int& out_height)
{
	return d_panelInterface->getPanelSize(out_width, out_height);
}
bool PanelDll::setPanelSize(int& in_width, int& in_height)
{
	return d_panelInterface->setPanelSize(in_width, in_height);
}
unsigned long PanelDll::getFramSize()
{
	return d_panelInterface->getFramSize();
}
bool PanelDll::beginAcquire(unsigned short d_quantity)
{
	return d_panelInterface->beginAcquire(d_quantity);
}
void PanelDll::stopAcquire()
{
	d_panelInterface->stopAcquire();
}
bool PanelDll::initialise()
{
	return d_panelInterface->initialise();
}
int PanelDll::getImageQuantity()
{
	return d_panelInterface->getImageQuantity();
}
bool PanelDll::getHeadImage(unsigned short** in_imageData)
{
	return d_panelInterface->getHeadImage(in_imageData);
}
void PanelDll::clearImageQueue()
{
	return d_panelInterface->clearImageQueue();
}
