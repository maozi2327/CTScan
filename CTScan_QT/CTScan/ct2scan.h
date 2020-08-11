#pragma once
#include "linedetscaninterface.h"
class Ct2Scan :
	public LineDetScanInterface
{
public:

	Ct2Scan(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor, CT3Data& in_data);
	~Ct2Scan();
};

