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
		LOG_ERROR(str.fromLocal8Bit("Ӳ�̿ռ䲻��"));
		return false;
	}

	if (!d_controller->checkReadyToScan())
	{
		LOG_ERROR(str.fromLocal8Bit("������δ����"));
		return false;
	}

	if (!d_panel->getReady())
	{
		LOG_ERROR(str.fromLocal8Bit("̽����δ����"));
		return false;
	}

	return true;
}

bool ConeScanInterface::loadBkgData()
{
	if(!d_imageProcess->loadBkgData(QString("bkg.tif")))
	{
		LOG_ERROR("׶��ɨ����ؿ����ļ�ʧ�ܣ�");
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
		LOG_ERROR("�½������ļ�ʧ��,ɨ�蹤�̺ţ�" + d_fileName);
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
	d_parameterText[index++] = ";  ɨ�����\n";
	d_parameterText[index++] = ";--------------------------------------------;\n";
	d_parameterText[index++] = ";--------------------------------------------;\n";

	d_parameterText[index++] = ";  ̽��������\n";
	d_parameterText[index++] = ";--------------------------------------------;\n";
	d_parameterText[index++] = "[DETECTORS]\n";
	d_parameterText[index++].sprintf("Width=%d\t\t\t;̽��������Ԫ����\n", d_width);
	d_parameterText[index++].sprintf("Height=%d\t\t\t;̽��������Ԫ����\n", d_height);
	d_parameterText[index++].sprintf("UnitSize=%.6f\t\t\t;̽������Ԫ��ȣ�mm��\n", d_panel->getPixelSize());
	d_parameterText[index++] = "Binning=1;Binning��ʽ:1-1X1,2-2X2,3-4X4,4-1X2,5-,6-1X4\n";
	d_parameterText[index++].sprintf("SampleTime = %.3f\t\t\t; ��������ʱ�䣨�룩\n", float(d_panel->getSampleTime()) / 1000);
	d_parameterText[index++].sprintf("FrameCnt=%d\t\t\t;���ֶȲ���֡��\n", d_framesPerGraduation);
	d_parameterText[index++] = "DataType=INT16\t\t\t;�ɼ��������ͣ�INT16��INT32��FLOAT\n\n";

	d_parameterText[index++] = (";--------------------------------------------;\n");
	d_parameterText[index++] = (";  ɨ�輸�β���\n");
	d_parameterText[index++] = (";  ��ת��Ϊz�ᣬ��ֱz�������Ϊy�ᣨ����ָ������Դ��������ȫ������ϵ��\n");
	d_parameterText[index++] = (";  ̽����ˮƽ����Ϊu�ᣬ��ֱ����Ϊv�ᣬ�����ֲ�����ϵ��\n");
	d_parameterText[index++] = (";  �ֲ�����ϵ��ȫ��ϵz����ת��\n");
	d_parameterText[index++] = (";--------------------------------------------;\n");
	d_parameterText[index++] = ("[GEOMETRY]\n");
	d_parameterText[index++].sprintf("SOD=%.1f\t\t\t;����Դ���㵽��ת���ʵ�ʾ��루mm��\n", Axis::objRadial);
	d_parameterText[index++].sprintf("SDD=%.1f\t\t\t;����Դ���㵽̽������ʵ�ʾ��루mm��\n", d_controller->readAxisPostion(Axis::detRadial));
	d_parameterText[index++].sprintf("thetaY=%.2f\t\t\t;̽������y�����ת�Ƕȣ��ȣ�\n", 0.0f);
	d_parameterText[index++].sprintf("thetaX=%.2f\t\t\t;̽������x�����ת�Ƕȣ��ȣ�\n", 0.0f);
	d_parameterText[index++].sprintf("thetaZ=%.2f\t\t\t;̽������z�����ת�Ƕȣ��ȣ�\n", 0.0f);
	d_parameterText[index++].sprintf("uo_mm=%.1f\t\t\t;����̽����ˮƽ���꣨mm��\n", d_panel->getPixelSize() * d_width / 2);
	d_parameterText[index++].sprintf("vo_mm=%.1f\t\t\t;����̽������ֱ���꣨mm��\n", d_panel->getPixelSize() * d_height / 2);
	d_parameterText[index++].sprintf("graduation=%d\t\t\t;�ֶ���\n", d_graduation);
	d_parameterText[index++].sprintf("Angle00000=%d\t\t\t;0��ͶӰ�ĽǶ�\n", d_orientInc);
	d_parameterText[index++].sprintf("��\t\t\t\t; 1-%04u��ͶӰ�ĽǶ�\n", d_graduation);
	d_parameterText[index++].sprintf("Angle%04u=%d\t\t\t;%04u��ͶӰ�ĽǶ�\n\n",
		d_graduation, d_orientInc + 360, d_graduation);

	d_parameterText[index++] = (";---------------------\n");
	d_parameterText[index++] = (";  �ؽ�ͼ�����\n");
	d_parameterText[index++] = (";---------------------\n");
	d_parameterText[index++] = ("[IMAGE PARAMETER]\n");
	d_parameterText[index++].sprintf("Width=%d\t\t\t;�ؽ�ͼ��Ŀ�Ȼ�ֱ�������أ�\n", 800);
	d_parameterText[index++].sprintf("StartLayer=%d\t\t\t;�ؽ�ͼ�����ʼ�㣨���أ�\n", 0);
	d_parameterText[index++].sprintf("Height=%d\t\t\t;�ؽ�ͼ��ĸ߶Ȼ���������أ�\n", 800);
	d_parameterText[index++].sprintf("SkipGraduation=%d\t\t\t;�ֶ���Ծ��\n", 1);
	d_parameterText[index++].sprintf("SkipHorizontal=%d\t\t\t;̽����ˮƽ������Ծ��\n", 0);
	d_parameterText[index++].sprintf("SkipVertical =%d\t\t\t;̽������ֱ������Ծ��\n", 0);
	d_parameterText[index++].sprintf("rotAngle=%d\t\t\t;�ؽ���ʼ�Ƕȣ��㣩\n", 0);
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
	imagesCollectedAndSpaceOccupied.sprintf("�Ѿ��ɼ�%d����ռ��Ӳ�̿ռ�%dm", d_graduationCount,
		size_t(d_graduation) * d_frameSize * d_framesPerGraduation / (1024 * 1024));
}
