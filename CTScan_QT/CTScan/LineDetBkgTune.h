#pragma once
#include "LineDetScanInterface.h"

class ControlerInterface;
class LineDetBkgTune :
	public LineDetScanInterface
{
public:
	LineDetBkgTune(ControlerInterface* in_controler);
	~LineDetBkgTune();
};

