#include "stdafx.h"
#include "SerialPortInterface.h"
#include "serialportutil.h"

SerialPortInterface* PanelFactory::getHandle()
{
	return SerialPortUtil::getHandle();
}