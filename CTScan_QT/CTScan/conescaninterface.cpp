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
	QString index;
	index.sprintf("%4d", d_graduationCount);
	auto completeOrgFileName = d_fileFolder + d_fileName + "org/" + index;

	if (d_orgFlag && !d_averageFlag)
		d_imageProcess->saveMultiBitmapDataToFile(in_image, completeOrgFileName + d_fileName, d_framesPerGraduation, d_height, d_width);
	else if (d_orgFlag && !d_averageFlag)
		d_imageProcess->saveSingleBitmapDataToFile(in_image, completeOrgFileName + d_fileName, d_height, d_width);

	auto completeImageFileName = d_fileFolder + d_fileName + "ct/" + index;

	if (d_bkgFlag && !d_airFlag && !d_defectFlag)
		d_imageProcess->bkgCorrectDataToFile(in_image, completeImageFileName + d_fileName, d_height, d_width);
	else if (d_bkgFlag && d_airFlag && !d_defectFlag)
		d_imageProcess->airCorrectDataToFile(in_image, completeImageFileName + d_fileName, d_height, d_width);
	else if (d_bkgFlag && d_airFlag && d_defectFlag)
		d_imageProcess->defectCorrectDataToFile(in_image, completeImageFileName + d_fileName, d_height, d_width);

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
	d_con.notify_one();
}

void ConeScanInterface::imageProcessThread()
{
	while (true)
	{
		unsigned short* imageData = nullptr;
		{
			std::unique_lock<std::mutex> lock(d_hmtxQ);
			d_con.wait(lock, [this] { return d_imageList.size() != 0; });

			if (++d_frameCount == d_framesPerGraduation)
			{
				if (d_frameCount == 1)
				{
					imageData = d_imageList.front();
					d_imageList.pop_front();
				}
				else
				{
					char* imageMem = (char*)malloc(d_frameSize);
					int count = 0;
					
					while (count++ != d_framesPerGraduation)
					{
						memcpy(imageMem + d_frameSize * count, d_imageList.front(), d_frameSize);
						free(d_imageList.front());
						d_imageList.pop_front();
					}
					
					imageData = (unsigned short*)imageMem;
				}
				d_frameCount = 0;
			}
		}
		++d_graduationCount;
		saveFile(imageData);
	}
}

bool ConeScanInterface::canScan()
{
	QString str;
	
	if (!checkMemory())
	{
		LOG_ERROR(str.fromLocal8Bit("硬盘空间不足"));
		return false;
	}

	if (!d_controller->checkReadyToScan())
	{
		LOG_ERROR(str.fromLocal8Bit("控制器未就绪"));
		return false;
	}

	if (!d_panel->getReady())
	{
		LOG_ERROR(str.fromLocal8Bit("探测器未就绪"));
		return false;
	}

	return true;
}

bool ConeScanInterface::loadBkgData()
{
	if(!d_imageProcess->loadBkgData(QString("bkg.tif")))
	{
		LOG_ERROR("锥束扫描加载空气文件失败！");
		return false;
	}

	return true;
}

bool ConeScanInterface::writeParameterFile()
{
	QFile paraFile;
	QString parameterFileName = d_fileFolder + d_fileName + "\\" + d_parameterFileName;
	paraFile.setFileName(parameterFileName);

	if (!paraFile.open(QIODevice::ReadWrite))
	{
		LOG_ERROR("新建参数文件失败,扫描工程号：" + d_fileName);
		return false;
	}

	makeParameterText();
	QString text;

	for (auto& line : d_parameterText)
		text += line;

	paraFile.write(text.toLocal8Bit());
	paraFile.close();
	return false;
}

bool ConeScanInterface::makeParameterText()
{
	d_parameterText.resize(300);
	size_t index = 0;
	d_parameterText[index++] = ";--------------------------------------------;\n";
	d_parameterText[index++] = ";  扫描参数\n";
	d_parameterText[index++] = ";--------------------------------------------;\n";
	d_parameterText[index++] = ";--------------------------------------------;\n";

	d_parameterText[index++] = ";  探测器参数\n";
	d_parameterText[index++] = ";--------------------------------------------;\n";
	d_parameterText[index++] = "[DETECTORS]\n";
	d_parameterText[index++].sprintf("Width=%d\t\t\t;探测器横向单元数量\n", d_width);
	d_parameterText[index++].sprintf("Height=%d\t\t\t;探测器纵向单元数量\n", d_height);
	d_parameterText[index++].sprintf("UnitSize=%.6f\t\t\t;探测器单元宽度（mm）\n", d_panel->getPixelSize());
	d_parameterText[index++] = "Binning=1;Binning方式:1-1X1,2-2X2,3-4X4,4-1X2,5-,6-1X4\n";
	d_parameterText[index++].sprintf("SampleTime = %.3f\t\t\t; 采样积分时间（秒）\n", float(d_panel->getSampleTime()) / 1000);
	d_parameterText[index++].sprintf("FrameCnt=%d\t\t\t;单分度采样帧数\n", d_framesPerGraduation);
	d_parameterText[index++] = "DataType=INT16\t\t\t;采集数据类型，INT16，INT32，FLOAT\n\n";

	d_parameterText[index++] = (";--------------------------------------------;\n");
	d_parameterText[index++] = (";  扫描几何参数\n");
	d_parameterText[index++] = (";  以转轴为z轴，垂直z轴的射线为y轴（方向指向射线源），建立全局坐标系；\n");
	d_parameterText[index++] = (";  探测器水平方向为u轴，垂直方向为v轴，建立局部坐标系；\n");
	d_parameterText[index++] = (";  局部坐标系绕全局系z轴旋转。\n");
	d_parameterText[index++] = (";--------------------------------------------;\n");
	d_parameterText[index++] = ("[GEOMETRY]\n");
	d_parameterText[index++].sprintf("SOD=%.1f\t\t\t;射线源焦点到旋转轴的实际距离（mm）\n", Axis::objRadial);
	d_parameterText[index++].sprintf("SDD=%.1f\t\t\t;射线源焦点到探测器的实际距离（mm）\n", d_controller->readAxisPostion(Axis::detRadial));
	d_parameterText[index++].sprintf("thetaY=%.2f\t\t\t;探测器绕y轴的旋转角度（度）\n", 0.0f);
	d_parameterText[index++].sprintf("thetaX=%.2f\t\t\t;探测器绕x轴的旋转角度（度）\n", 0.0f);
	d_parameterText[index++].sprintf("thetaZ=%.2f\t\t\t;探测器绕z轴的旋转角度（度）\n", 0.0f);
	d_parameterText[index++].sprintf("uo_mm=%.1f\t\t\t;中心探测器水平坐标（mm）\n", d_panel->getPixelSize() * d_width / 2);
	d_parameterText[index++].sprintf("vo_mm=%.1f\t\t\t;中心探测器垂直坐标（mm）\n", d_panel->getPixelSize() * d_height / 2);
	d_parameterText[index++].sprintf("graduation=%d\t\t\t;分度数\n", d_graduation);
	d_parameterText[index++].sprintf("Angle00000=%d\t\t\t;0号投影的角度\n", d_orientInc);
	d_parameterText[index++].sprintf("…\t\t\t\t; 1-%04u号投影的角度\n", d_graduation);
	d_parameterText[index++].sprintf("Angle%04u=%d\t\t\t;%04u号投影的角度\n\n",
		d_graduation, d_orientInc + 360, d_graduation);

	d_parameterText[index++] = (";---------------------\n");
	d_parameterText[index++] = (";  重建图像参数\n");
	d_parameterText[index++] = (";---------------------\n");
	d_parameterText[index++] = ("[IMAGE PARAMETER]\n");
	d_parameterText[index++].sprintf("Width=%d\t\t\t;重建图像的宽度或直径（像素）\n", 800);
	d_parameterText[index++].sprintf("StartLayer=%d\t\t\t;重建图像的起始层（像素）\n", 0);
	d_parameterText[index++].sprintf("Height=%d\t\t\t;重建图像的高度或层数（像素）\n", 800);
	d_parameterText[index++].sprintf("SkipGraduation=%d\t\t\t;分度跳跃数\n", 1);
	d_parameterText[index++].sprintf("SkipHorizontal=%d\t\t\t;探测器水平方向跳跃数\n", 0);
	d_parameterText[index++].sprintf("SkipVertical =%d\t\t\t;探测器垂直方向跳跃数\n", 0);
	d_parameterText[index++].sprintf("rotAngle=%d\t\t\t;重建起始角度（°）\n", 0);
	d_parameterText[index++].sprintf("FirstSection=%d\t\t\t;\n", 100);
	d_parameterText[index++].sprintf("LastSection=%d\t\t\t;\n", 800);
	d_parameterText[index++].sprintf("Filename=\n");
	d_parameterText[index++].sprintf("Image Directory=%s\t\t\t;\n", "C:\\");
	d_parameterText[index++].sprintf("Sigma=%.6f\t\t\t;\n", 2.0);
	return true;
}

bool ConeScanInterface::loadDefectData()
{
	return d_imageProcess->loadDefectData(QString("defect.tif"));
}
void ConeScanInterface::setFileName(QString& in_fileFolder, QString & in_name)
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

	if(!writeParameterFile())
		return false;
	
	if (!loadBkgData())
		return false;

	if (!loadAirData())
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

void ConeScanInterface::getScanProgress(int & in_out_thisRound, int & in_out_allProgress, QString & imagesCollectedAndSpaceOccupied)
{
	in_out_thisRound = 100 * d_graduationCount / d_graduation;
	in_out_allProgress = 100 * d_graduationCount / d_graduation;
	imagesCollectedAndSpaceOccupied.sprintf("已经采集%d幅，占用硬盘空间%dm", d_graduationCount,
		size_t(d_graduation) * d_frameSize * d_framesPerGraduation / (1024 * 1024));
}
