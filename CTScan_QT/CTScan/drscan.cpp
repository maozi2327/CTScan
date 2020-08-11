#include "stdafx.h"
#include "drscan.h"


DrScan::DrScan(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor, CT3Data& in_data) : LineDetScanInterface(in_controller, in_lineDetNetWor)
{
}


DrScan::~DrScan()
{
}
