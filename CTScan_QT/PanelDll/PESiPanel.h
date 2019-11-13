#pragma once
#include "PanelInterface.h"
#include "Acq.h"
#include "../Public/headers/CommandQueue.h"
class PESiPanel :
	public PanelInterface
{
private:
	QString d_dectorType;
	unsigned long d_imageMemorySize;
	char d_NiImaqintfName[64];
	int d_quantityOfRingBuffer;
	bool d_ringThreadRunFlag;
	bool d_serialSendRunFlag;
	HACQDESC d_hAcqDesc;
	std::mutex d_ringThreadMutex;
	std::condition_variable d_ringThreadCond;
	void CALLBACK OnEndPESiDetFrameCallback(HACQDESC hAcqDesc);			//声明每帧图像采集回调函数
	void CALLBACK OnEndPESiDetAcqCallback(HACQDESC hAcqDesc);
public:
	PESiPanel();
	~PESiPanel();
	bool initialise();
};

