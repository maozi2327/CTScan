#include "stdafx.h"
#include "controllerinterface.h"


ControllerInterface::ControllerInterface() 
	: d_timeout(std::chrono::milliseconds(0)), d_connected(true)
{

}


ControllerInterface::~ControllerInterface()
{

}
