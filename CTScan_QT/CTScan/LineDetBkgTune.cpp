#include "stdafx.h"
#include "LineDetBkgTune.h"
#include "controlerinterface.h"
#include "../Public/util/Thread.h"
#include "LineDetImageProcess.h"
#include "LineDetNetWork.h"

LineDetBkgTune::LineDetBkgTune(ControlerInterface* in_controler) : LineDetScanInterface(in_controler)
{
}


LineDetBkgTune::~LineDetBkgTune()
{
}
