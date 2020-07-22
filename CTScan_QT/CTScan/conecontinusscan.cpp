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

//��ȡd_panel�ɼ���ͼ�񣬲�У������
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
	d_controller->sendToControl(0 , 0);
	d_ringThreadPromisePtr.reset(new std::promise<bool>);
	std::function<void()> threadFun = std::bind(&ConeContinusScan::scanThread, this, std::ref(*d_ringThreadPromisePtr));
	std::thread(threadFun).detach();
	return true;
}
bool ConeContinusScan::stopScan()
{
	d_controller->sendToControl(0, 0);
	return true;
}
