#pragma once
#include <memory>
#include <mutex>
#include "../Public/util/macro.h"
#include "../PanelDll/panel.h"
#include "../Public/headers/panelimageprocess.h"
#include "../Public/headers/commandqueue.h"
#include "../Public/util/thread.h"

class ControllerInterface;
class ConeScanInterface : public QObject
{
private:
	virtual bool saveFile(unsigned short* in_image);
	bool checkMemory();
protected:
	int d_graduation;
	QString d_fileFolder;
	QString d_fileName;
	bool d_isSaveOrg;
	bool d_isDispose;
	bool d_bkgFlag;
	bool d_airFlag;
	bool d_defectFlag;
	bool d_averageFlag;
	bool d_orgFlag;
	int d_width;
	int d_height;
	int d_frames;
	int d_graduation;
	int d_round;
	int d_imageProcessSleep;


	mutable std::mutex d_hmtxQ;
	std::list<unsigned short*> d_imageList;
	Panel* d_panel;
	ControllerInterface* d_controller;
	PanelImageProcess* d_imageProcess;
	virtual void frameProcessCallback(unsigned short* in_image);
	std::unique_ptr<Thread> d_scanThread;
	virtual void scanThread() = 0;
	bool d_scanThreadRun;
	std::unique_ptr<Thread> d_imageProcessThread;
	virtual void imagePrecessThread();
	bool d_imageProcessThreadRun;
	virtual bool canScan() = 0;
public:
	ConeScanInterface(Panel* in_panel, ControllerInterface* in_controller, PanelImageProcess* in_ctDispose);
	virtual ~ConeScanInterface();

	virtual void setFileName(QString& in_fileFolder, QString& in_name);
	virtual void setDisposeFlag(bool in_bkgFlag, bool in_airFlag, bool in_defectFlag, bool in_averageFlag);
	virtual void setGraduation(int in_graduation) { d_graduation = in_graduation; };
	virtual bool stopScan() = 0;
	virtual bool intialise() = 0;
	virtual bool beginScan() = 0;

signals:
	LOGSIGNAL
};