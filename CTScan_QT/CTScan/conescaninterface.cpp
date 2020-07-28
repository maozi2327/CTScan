#include "stdafx.h"
#include "conescaninterface.h"
#include "controllerinterface.h"
#include "imageprocess.h"
#include "../../Public/util/functions.h"
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
		d_imageProcess->saveMultiBitmapDataToFile(in_image, d_framesPerGraduation, d_height, d_width);
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
	size_t allImageSize = size_t(d_framesPerGraduation) * d_graduation *d_width * d_height * 
		sizeof(unsigned short) / (1024 * 1024);

	if (d_isSaveOrg)
		allImageSize *= 2;
	
	return allImageSize < getDiskFreeSpace(d_fileFolder);
}

void ConeScanInterface::frameProcessCallback(unsigned short * in_image)
{
	std::lock_guard<std::mutex> lock(d_hmtxQ);
	d_imageList.push_back(in_image);
}

void ConeScanInterface::imageProcessThread()
{
	while (true)
	{
		unsigned short* imageData = nullptr;

		{
			std::lock_guard<std::mutex> lock(d_hmtxQ);

			if (d_imageList.size() != 0) 
			{
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
	QString str;
	
	if (!checkMemory)
	{
		LOG_ERROR(str.fromLocal8Bit("Ó²ÅÌ¿Õ¼ä²»×ã"));
		return false;
	}

	if (!d_controller->checkReadyToScan())
	{
		LOG_ERROR(str.fromLocal8Bit("¿ØÖÆÆ÷Î´¾ÍÐ÷"));
		return false;
	}

	if (!d_panel->getReady())
	{
		LOG_ERROR(str.fromLocal8Bit("Ì½²âÆ÷Î´¾ÍÐ÷"));
		return false;
	}

	return true;
}

bool ConeScanInterface::loadBkgData()
{
	return d_imageProcess->loadBkgData(QString("bkg.tif"));
}

bool ConeScanInterface::loadDefectData()
{
	return d_imageProcess->loadDefectData(QString("defect.tif"));
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
	if (!canScan())
		return false;

	sendCmdToController();
	d_scanThread.reset(new Thread(std::bind(&ConeScanInterface::scanThread, this), std::ref(d_scanThreadRun)));
	d_scanThread->detach();
	d_imageProcessThread.reset(new Thread(std::bind(&ConeScanInterface::imageProcessThread, this), std::ref(d_imageProcessThreadRun)));
	d_scanThread->detach();
	std::function<void(unsigned short *)> frameCallback = std::bind(&ConeScanInterface::frameProcessCallback, this, std::placeholders::_1);
	d_panel->setFrameCallback(frameCallback);
	d_panel->beginAcquire(0);
	return true;
}
