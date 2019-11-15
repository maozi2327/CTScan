#include "panel.h"
#include "PanelInterface.h"
#ifdef NIMAQPANEL
#include "NimaqPanel.h"
#endif

Panel::Panel() : d_panelInterface(new REALPANEL)
{
	
}
bool Panel::initilise()
{
	return d_panelInterface->initialise();
}
bool Panel::setSampleTime(int in_milliseconds)
{
	return d_panelInterface->setSampleTime(in_milliseconds);
}
bool Panel::setFrames(int in_frames)
{
	return d_panelInterface->setFrames(in_frames);
}
bool Panel::setSampleMode(SampleMode in_sampleMode)
{
	return d_panelInterface->setSampleMode(in_sampleMode);
}
bool Panel::setGainFactor(int in_gainFactor) 
{
	return d_panelInterface->setGainFactor(in_gainFactor);
}

//采集多帧时会将数据连续存储在同一内存区域
bool Panel::getPanelSize(int& out_width, int& out_height)
{
	return d_panelInterface->getPanelSize(out_width, out_height);
}
bool Panel::setPanelSize(int& in_width, int& in_height)
{
	return d_panelInterface->setPanelSize(in_width, in_height);
}
unsigned long Panel::getFramSize()
{
	return d_panelInterface->getFramSize();
}
bool Panel::beginAcquire(unsigned short d_quantity)
{
	return d_panelInterface->beginAcquire(d_quantity);
}
void Panel::stopAcquire()
{
	d_panelInterface->stopAcquire();
}
bool Panel::initialise()
{
	return d_panelInterface->initialise();
}
int Panel::getImageQuantity()
{
	return d_panelInterface->getImageQuantity();
}
bool Panel::getHeadImage(unsigned short** in_imageData)
{
	return d_panelInterface->getHeadImage(in_imageData);
}
void Panel::clearImageQueue()
{
	return d_panelInterface->clearImageQueue();
}
