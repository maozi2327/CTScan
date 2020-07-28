#pragma once
#include "PanelInterface.h"
#include "Acq.h"
#include "panelHeaders.h"
#include "../Public/headers/CommandQueue.h"
#include <tuple>
#include <map>
#include <functional>
class PESiPanel :
	public PanelInterface
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
public:
	PESiPanel();
	~PESiPanel();
	void stopAcquire();
	bool initialise();
	bool beginAcquire(unsigned short d_quantity);
	bool setBinMode(BinMode in_binMode);
	bool setSampleTime(int in_milliseconds);
	bool setSampleMode(SampleMode in_sampleMode);
	bool setGainFactor(int in_gainFactor);
	void OnEndPESiDetFrameCallback(HACQDESC hAcqDesc);			//声明每帧图像采集回调函数
	void OnEndPESiDetAcqCallback(HACQDESC hAcqDesc);
	virtual bool getReady();
	virtual bool getConnected();
};

