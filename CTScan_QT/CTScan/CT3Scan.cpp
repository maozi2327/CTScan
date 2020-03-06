#include "stdafx.h"
#include <thread>
#include <functional>
#include <chrono>
#include "CT3Scan.h"

CT3Scan::CT3Scan(ControlerInterface* in_controler) : LineDetScanInterface(in_controler)
{

}
//更新进度条
//检查扫描结束
void CT3Scan::scanThread()
{
	while (d_threadRun)
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void CT3Scan::startScan()
{
	std::thread runThread(std::bind(&CT3Scan::run, this));
	runThread.detach();
}

void CT3Scan::stopScan()
{

}
