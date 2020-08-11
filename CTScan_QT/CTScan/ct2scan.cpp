#include "stdafx.h"
#include "ct2scan.h"


Ct2Scan::Ct2Scan(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor, CT3Data& in_data) : LineDetScanInterface(in_controller, in_lineDetNetWor)
{
}


Ct2Scan::~Ct2Scan()
{
}
