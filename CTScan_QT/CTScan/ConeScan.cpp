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

}
bool ConeScan::scanStart()
{
	if(!d_panelInterface->setSampleMode(SampleMode::exTrigger))
		return false;

	//d_panelInterface->beginAcquire();
}
void ConeScan::scanThread()
{
	while (true)
	{
		 
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
