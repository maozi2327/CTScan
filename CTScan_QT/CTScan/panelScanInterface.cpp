#include "stdafx.h"
#include "panelScanInterface.h"


void panelScanInterface::pushImageQueue(unsigned short * im_image)
{
	d_imageQueue.push(im_image);
}

void panelScanInterface::processImage(unsigned short * in_image)
{
	if (d_orgFlag && !d_averageFlag)
		d_imageProcess->saveMultiBitmapDataToFile(in_image, d_frames, d_height, d_width);
	else if(d_orgFlag && !d_averageFlag)
		d_imageProcess->saveSingleBitmapDataToFile(in_image, d_height, d_width);

	if (d_bkgFlag && !d_airFlag && !d_defectFlag)
		d_imageProcess->bkgCorrectDataToFile(in_image, d_fileName, d_height, d_width);
	else if(d_bkgFlag && d_airFlag && !d_defectFlag)
		d_imageProcess->airCorrectDataToFile(in_image, d_fileName, d_height, d_width);
	else if (d_bkgFlag && d_airFlag && d_defectFlag)
		d_imageProcess->defectCorrectDataToFile(in_image, d_fileName, d_height, d_width);
}

panelScanInterface::panelScanInterface()
{
}


panelScanInterface::~panelScanInterface()
{
}

void panelScanInterface::setDisposeFlag(bool in_bkgFlag, bool in_airFlag, 
	bool in_defectFlag, bool in_averageFlag)
{
	d_bkgFlag = in_bkgFlag;
	d_airFlag = in_airFlag;
	d_defectFlag = in_defectFlag;
	d_averageFlag = in_averageFlag;
}
