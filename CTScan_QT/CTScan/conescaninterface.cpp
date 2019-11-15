#include "stdafx.h"
#include "ConeScanInterface.h"
#include <Windows.h>

ConeScanInterface::ConeScanInterface(Panel* in_panel, ControlerInterface* in_controller, CTDispose* in_ctDispose):
	d_panel(in_panel), d_controller(in_controller), d_ctDispose(in_ctDispose)
{
	
}


ConeScanInterface::~ConeScanInterface()
{
	d_ringThreadPromisePtr->get_future().get();
}

