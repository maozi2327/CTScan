#include "stdafx.h"
#include "LineDetBkgTune.h"
#include "controllerinterface.h"
#include "../Public/util/Thread.h"
#include "LineDetImageProcess.h"
#include "LineDetNetWork.h"

LineDetBkgTune::LineDetBkgTune(ControllerInterface* in_controller) : LineDetScanInterface(in_controller)
{
}


LineDetBkgTune::~LineDetBkgTune()
{
}
