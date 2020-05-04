#pragma once
#include "LineDetScanInterface.h"

class ControllerInterface;
class LineDetBkgTune :
	public LineDetScanInterface
{
public:
	LineDetBkgTune(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor);
	~LineDetBkgTune();
};

