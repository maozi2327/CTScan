#include "stdafx.h"
#include "ConeScan.h"
#include "../Public/headers/panelimageprocess.h"
#include "../Public/headers/setupdata.h"
#include "controllerinterface.h"


ConeScan::ConeScan(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose) :
	ConeScanInterface(in_panel, in_controller, in_ctDispose)
{

}
ConeScan::~ConeScan()
{

}

void ConeScan::setFileName(QString in_fileName)
{
	d_fileName = in_fileName;
}

void ConeScan::frameProcessCallback(unsigned short * in_image)
{
	ConeScanInterface::frameProcessCallback(in_image);
}

bool ConeScan::beginScan()
{
}

bool ConeScan::stopScan()
{
	return false;
}
void ConeScan::scanThread()
{
	while (d_scanThread)
	{
		
	}
}
bool ConeScan::loadAirData()
{
	return d_imageProcess->loadAirData(QString("air.tif"));
}
bool ConeScan::saveFile(unsigned short * in_image)
{
	return false;
}
bool ConeScan::intialise()
{
	return false;
}

void ConeScan::sendCmdToController()
{
	char buf[RTBUF_LEN];
	ConeScanCmdData	cmdData, *pCmdData;
	cmdData.stsBit.s.translationCone = 0;
	cmdData.stsBit.s.currentLayer = 1;
	cmdData.stsBit.s.coneHelix = 0;
	cmdData.projectionAmount = d_framesPerGraduation * d_graduation;
	cmdData.sampleTime = d_sampleTime;
	cmdData.orientInc = d_orientInc;
	cmdData.circleAmount = 1;
	cmdData.centerOffset = 0;
	cmdData.firstLayerOffset = 0;
	cmdData.helixSpace = 0;
	cmdData.b180Scan = 0;
	cmdData.centerOffset = 0;
	cmdData.stsBit.s.coneHelix = 0;
	COMM_PACKET* ptr = (COMM_PACKET*)buf;
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_CONE_SCAN;
	ptr->tagLen = 3 + sizeof(ConeScanCmdData);
	memcpy(buf + 6, &cmdData, sizeof(cmdData));
	d_controller->sendToControl(buf, 6 + sizeof(ConeScanCmdData));
}
