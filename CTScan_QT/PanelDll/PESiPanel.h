#pragma once
#include "Panel.h"
#include "Acq.h"
#include "panelHeaders.h"
#include "../Public/headers/CommandQueue.h"
#include <tuple>
#include <map>
#include <functional>
class PESiPanel : public Panel
{
private:
	BinMode d_binMode;
	int d_cycleTime;
	QString d_dectorType;
	char d_NiImaqintfName[64];
	int d_quantityOfRingBuffer;
	bool d_ringThreadRunFlag;
	bool d_serialSendRunFlag;
	std::mutex d_ringThreadMutex;
	std::condition_variable d_ringThreadCond;
	HACQDESC hPESiAcqDesc;
	const std::map<BinMode, std::tuple<QString, unsigned short>> d_binModeName;
	unsigned short* pPESiDetAcqBuffer;
	unsigned char* d_copyBuffer;
	int d_frameCount;
	size_t d_PESiDetBufferSize;
	PESICON_SINGLE_MODE d_PESiContinusSingleMode;
protected:
	std::function<void(unsigned short*)> d_imageProcCallback;
	unsigned int d_width;
	unsigned int d_height;
	int d_depth;
	int d_frames;
	int d_sampleTime;
	int d_gainFactor;
	size_t d_frameSize;
	SampleMode d_sampleMode;
	float d_pixelSize;
public:
	PESiPanel();
	~PESiPanel();
	virtual bool setFrames(int in_frames);
	virtual void stopAcquire();
	virtual bool initialise();
	virtual bool beginAcquire(unsigned short d_quantity) override;
	virtual bool setBinMode(BinMode in_binMode);
	virtual bool setSampleTime(int in_milliseconds) override;
	virtual bool setSampleMode(SampleMode in_sampleMode) override;
	virtual bool setGainFactor(int in_gainFactor);
	virtual void OnEndPESiDetFrameCallback(HACQDESC hAcqDesc);			//声明每帧图像采集回调函数
	virtual void OnEndPESiDetAcqCallback(HACQDESC hAcqDesc);
	virtual bool getReady();
	virtual int getSampleTime();
	virtual bool getConnected();
	virtual size_t getFrameSize();
	virtual float getPixelSize();
	virtual void setFrameCallback(std::function<void(unsigned short*)> in_imageProcessCallBack);
	virtual bool getPanelSize(int& out_width, int& out_height);
	virtual bool setPanelSize(int in_width, int in_height);
};

