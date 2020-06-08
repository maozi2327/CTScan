#include "stdafx.h"
#include "serialport.h"
#include "serialportutil.h"

SerialPortInterface* SerialPortFactory::getHandle()
{
	return SerialPortUtil::getHandle();
}