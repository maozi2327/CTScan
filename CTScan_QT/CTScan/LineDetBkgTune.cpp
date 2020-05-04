#include "stdafx.h"
#include "linedetbkgtune.h"
#include "controllerinterface.h"
#include "../Public/util/Thread.h"
#include "LineDetImageProcess.h"
#include "LineDetNetWork.h"

LineDetBkgTune::LineDetBkgTune(ControllerInterface* in_controller, LineDetNetWork* in_lineDetNetWor) : LineDetScanInterface(in_controller, in_lineDetNetWor)
{
}


LineDetBkgTune::~LineDetBkgTune()
{
}
