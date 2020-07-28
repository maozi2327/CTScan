#include "stdafx.h"
#include "conecontinusscan.h"
#include "../Public/headers/panelimageprocess.h"
#include "controllerinterface.h"

ConeContinusScan::ConeContinusScan(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose):
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

		if (d_isSaveOrg)
			saveFile(imagePtr);

		if (d_isDispose)
			;//d_ctDispose->dispose(imagePtr);

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
	if (!canScan())
		return false;

	d_controller->sendToControl(0, 0);
	d_scanThread.reset(new Thread(std::bind(&ConeContinusScan::scanThread, this), std::ref(d_scanThreadRun)));
	d_scanThread->detach();
	d_imageProcessThread.reset(new Thread(std::bind(&ConeContinusScan::imagePrecessThread, this), std::ref(d_imageProcessThreadRun)));
	d_scanThread->detach();
	std::function<void(unsigned short *)> frameCallback = std::bind(&ConeContinusScan::frameProcessCallback, this, std::placeholders::_1);
	d_panel->setFrameCallback(frameCallback);
	d_panel->beginAcquire(0);
	return true;
}
bool ConeContinusScan::stopScan()
{
	d_controller->sendToControl(0, 0);
	return true;
}
