#include "stdafx.h"
#include "ConeContinusScan.h"
ConeContinusScan::ConeContinusScan(Panel* in_panel, ControlerInterface* in_controller, CTDispose* in_ctDispose):
	ConeScanInterface(in_panel, in_controller, in_ctDispose)
{
}


ConeContinusScan::~ConeContinusScan()
{
}

//获取d_panel采集的图像，并校正保存
void ConeContinusScan::scanThread(std::promise<bool>& in_promise)
{
	in_promise.set_value_at_thread_exit(true);

	while (true)
	{
		unsigned short* imagePtr;
		d_panel->getHeadImage(&imagePtr);
		d_graduation++;

		if (d_is_saveOrg)
			saveFile(imagePtr);

		if (d_is_dispose)
			d_ctDispose->dispose(imagePtr);

		saveFile(imagePtr);
		free(imagePtr);
	}
}
bool ConeContinusScan::saveFile(unsigned short* in_image)
{
	return true;
}

bool ConeContinusScan::beginScan()
{
	d_controller->sendCmd(0 , 0);
	d_ringThreadPromisePtr.reset(new std::promise<bool>);
	std::function<void()> threadFun = std::bind(&ConeContinusScan::scanThread, this, std::ref(*d_ringThreadPromisePtr));
	std::thread(threadFun).detach();
	return true;
}
bool ConeContinusScan::stopScan()
{
	return d_controller->sendCmd(0, 0);
}
