#include "stdafx.h"
#include "simotioncontroller.h"

const unsigned short SimotionController::d_port = 8000;
const int SimotionController::d_packetSize = 256;
SimotionController::SimotionController()
{
	d_tcpNetWork = new TcpServer(d_packetSize, d_port);
}


SimotionController::~SimotionController()
{

}
float SimotionController::getAxisPostion(Axis in_axis)
{

	return 0;
}
bool SimotionController::getReadyStatus()
{
	return true;
}
bool SimotionController::getSaveStatus()
{
	return true;
}
bool SimotionController::getWaitNextScanStatus()
{
	return true;
}
bool SimotionController::getRunStatus()
{
	return true;
}
bool SimotionController::initialConnection()
{
	return true;
}
bool SimotionController::sendCmd(unsigned char* in_cmd, size_t in_size)
{
	return true;
}
