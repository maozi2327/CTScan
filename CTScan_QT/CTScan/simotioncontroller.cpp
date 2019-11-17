#include "stdafx.h"
#include "simotioncontroller.h"


SimotionControler::SimotionControler()
{
}


SimotionControler::~SimotionControler()
{
}
float SimotionControler::getAxisPostion(Axis in_axis)
{
	return 0;
}
bool SimotionControler::getReadyStatus()
{
	return true;
}
bool SimotionControler::getSaveStatus()
{
	return true;
}
bool SimotionControler::getWaitNextScanStatus()
{
	return true;
}
bool SimotionControler::getRunStatus()
{
	return true;
}
bool SimotionControler::initialConnection()
{
	return true;
}
bool SimotionControler::sendCmd(unsigned char* in_cmd, size_t in_size)
{
	return true;
}
