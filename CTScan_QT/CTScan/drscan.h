#pragma once
#include "linedetscaninterface.h"
class DrScan :
	public LineDetScanInterface
{
public:	
	DrScan(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor, CT3Data& in_data);
	~DrScan();
};

