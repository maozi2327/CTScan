#include "stdafx.h"
#include "conescaninterface.h"
#include <Windows.h>

ConeScanInterface::ConeScanInterface(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose):
	d_panel(in_panel), d_controller(in_controller), d_ctDispose(in_ctDispose)
{
	
}


ConeScanInterface::~ConeScanInterface()
{
	d_ringThreadPromisePtr->get_future().get();
}

