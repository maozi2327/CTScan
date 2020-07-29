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
		if (d_graduationCount >= d_graduation)
			d_scanThread->stopThread();
	}
}

bool ConeScan::loadAirData()
{
	return d_imageProcess->loadAirData(QString("air.tif"));
}

bool ConeScan::writeParameterFile()
{
	QFile paraFile;
	paraFile.setFileName(d_fileFolder + d_fileName + "\\" + d_parameterFileName);
	paraFile.open(QIODevice::ReadWrite);
	std::vector<QString> allLine(200);
	size_t index = 0;
	allLine[index++] = ";--------------------------------------------;\n";
	allLine[index++] = ";  扫描参数\n";
	allLine[index++] = ";--------------------------------------------;\n";
	allLine[index++] = ";--------------------------------------------;\n";
	
	allLine[index++] = ";  探测器参数\n";
	allLine[index++] = ";--------------------------------------------;\n";
	allLine[index++] = "[DETECTORS]\n";
	allLine[index++].sprintf("Width=%d\t\t\t;探测器横向单元数量\n", d_width);
	allLine[index++].sprintf("Height=%d\t\t\t;探测器纵向单元数量\n", d_height);
	allLine[index++].sprintf("UnitSize=%.6f\t\t\t;探测器单元宽度（mm）\n", d_panel->getPixelSize());
	allLine[index++] = "Binning=1;Binning方式:1-1X1,2-2X2,3-4X4,4-1X2,5-,6-1X4\n";
	allLine[index++].sprintf("SampleTime = %.3f\t\t\t; 采样积分时间（秒）\n", float(d_panel->getSampleTime()) / 1000);
	allLine[index++].sprintf("FrameCnt=%d\t\t\t;单分度采样帧数\n", d_framesPerGraduation);
	allLine[index++] = "DataType=INT16\t\t\t;采集数据类型，INT16，INT32，FLOAT\n\n";
	
	allLine[index++] = (";--------------------------------------------;\n");
	allLine[index++] = (";  扫描几何参数\n");
	allLine[index++] = (";  以转轴为z轴，垂直z轴的射线为y轴（方向指向射线源），建立全局坐标系；\n");
	allLine[index++] = (";  探测器水平方向为u轴，垂直方向为v轴，建立局部坐标系；\n");
	allLine[index++] = (";  局部坐标系绕全局系z轴旋转。\n");
	allLine[index++] = (";--------------------------------------------;\n");
	allLine[index++] = ("[GEOMETRY]\n");
	allLine[index++].sprintf("SOD=%.1f\t\t\t;射线源焦点到旋转轴的实际距离（mm）\n", setupData.geometryPara.CurSOD);
	allLine[index++].sprintf("SDD=%.1f\t\t\t;射线源焦点到探测器的实际距离（mm）\n", setupData.geometryPara.CurSDD);
	allLine[index++].sprintf("thetaY=%.2f\t\t\t;探测器绕y轴的旋转角度（度）\n", 0.0);
	allLine[index++].sprintf("thetaX=%.2f\t\t\t;探测器绕x轴的旋转角度（度）\n", 0.0);
	allLine[index++].sprintf("thetaZ=%.2f\t\t\t;探测器绕z轴的旋转角度（度）\n", thetaZ);
	allLine[index++].sprintf("uo_mm=%.1f\t\t\t;中心探测器水平坐标（mm）\n", uo_mm);
	allLine[index++].sprintf("vo_mm=%.1f\t\t\t;中心探测器垂直坐标（mm）\n", vo_mm);
	allLine[index++].sprintf("graduation=%d\t\t\t;分度数\n", setupData.scanMatrix);
	allLine[index++].sprintf("Angle00000=%d\t\t\t;0号投影的角度\n", setupData.orientIncDefine);
	allLine[index++].sprintf("…\t\t\t\t; 1-%04u号投影的角度\n", setupData.scanMatrix);
	allLine[index++].sprintf("Angle%04u=%d\t\t\t;%04u号投影的角度\n\n", setupData.scanMatrix);


	return false;
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
