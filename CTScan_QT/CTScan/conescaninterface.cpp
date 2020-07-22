#include "stdafx.h"
#include "conescaninterface.h"
#include "controllerinterface.h"
#include "imageprocess.h"

ConeScanInterface::ConeScanInterface(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_imageProcess):
	d_panel(in_panel), d_controller(in_controller), d_imageProcess(in_imageProcess),
	d_imageProcessSleep(300)
{
	
}

ConeScanInterface::~ConeScanInterface()
{
	
}

bool ConeScanInterface::saveFile(unsigned short * in_image)
{
	if (d_orgFlag && !d_averageFlag)
		d_imageProcess->saveMultiBitmapDataToFile(in_image, d_frames, d_height, d_width);
	else if (d_orgFlag && !d_averageFlag)
		d_imageProcess->saveSingleBitmapDataToFile(in_image, d_height, d_width);

	if (d_bkgFlag && !d_airFlag && !d_defectFlag)
		d_imageProcess->bkgCorrectDataToFile(in_image, d_fileName, d_height, d_width);
	else if (d_bkgFlag && d_airFlag && !d_defectFlag)
		d_imageProcess->airCorrectDataToFile(in_image, d_fileName, d_height, d_width);
	else if (d_bkgFlag && d_airFlag && d_defectFlag)
		d_imageProcess->defectCorrectDataToFile(in_image, d_fileName, d_height, d_width);

	return false;
}

bool ConeScanInterface::checkMemory()
{
	size_t allImageSize = size_t(d_frames) * d_width * d_height * sizeof(unsigned short);

	if (d_isSaveOrg)
		allImageSize *= 2;

	return false;
}

void ConeScanInterface::frameProcessCallback(unsigned short * in_image)
{
	std::lock_guard<std::mutex> lock(d_hmtxQ);
	d_imageList.push_back(in_image);
}

void ConeScanInterface::imagePrecessThread()
{
	while (true)
	{
		unsigned short* imageData = nullptr;

		{
			std::lock_guard<std::mutex> lock(d_hmtxQ);

			if (d_imageList.size() != 0) {
				imageData = d_imageList.front();
				d_imageList.pop_front();
			}
		}

		if (imageData != nullptr)
			saveFile(imageData);
	}
}

bool ConeScanInterface::canScan()
{
	return d_controller->checkReadyToScan() && checkMemory() && d_panel->getConnected();
}

void ConeScanInterface::setFileName(QString & in_fileFolder, QString & in_name)
{
	d_fileFolder = in_fileFolder;
	d_fileName = in_name;
}

void ConeScanInterface::setDisposeFlag(bool in_bkgFlag, bool in_airFlag,
	bool in_defectFlag, bool in_averageFlag)
{
	d_bkgFlag = in_bkgFlag;
	d_airFlag = in_airFlag;
	d_defectFlag = in_defectFlag;
	d_averageFlag = in_averageFlag;
}

bool ConeScanInterface::beginScan()
{
	d_controller->checkReadyToScan();
	return false;
}
