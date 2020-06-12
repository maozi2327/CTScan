#pragma once

#include <QObject>
#include "paneldll_global.h"
#include "panelHeaders.h"
#include <memory>
#include "../Public/util/macro.h"
#include <functional>
class PANELDLL_EXPORT Panel	: public QObject
{
	Q_OBJECT
signals:
	LOGSIGNAL
public:
    Panel(std::function<void(unsigned short*)> in_imageProcessCallBack);
	virtual ~Panel() = 0;
	virtual bool initialise() = 0;
	virtual bool setSampleTime(int in_milliseconds) = 0;
	virtual bool setFrames(int in_frames) = 0;
	virtual bool setSampleMode(SampleMode in_sampleMode) = 0;
	virtual bool setGainFactor(int in_gainFactor) = 0;

	//�ɼ���֡ʱ�Ὣ���������洢��ͬһ�ڴ�����
	virtual bool getPanelSize(int& out_width, int& out_height) = 0;
	virtual bool setPanelSize(int in_width, int in_height) = 0;
	virtual size_t getFrameSize() = 0;
	virtual bool beginAcquire(unsigned short d_quantity) = 0;
	virtual void stopAcquire() = 0;
	virtual int getImageQuantity() = 0;
	virtual bool getHeadImage(unsigned short** in_imageData) = 0;
	virtual void clearImageQueue() = 0;
};
class PANELDLL_EXPORT PanelFactory
{
public:
	static std::unique_ptr<Panel> getPanel(std::function<void(unsigned short*)> in_imageProcessCallBack);
};