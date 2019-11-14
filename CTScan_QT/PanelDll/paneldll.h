#pragma once

#include "paneldll_global.h"
#include "panelHeaders.h"
#include <memory>
class PanelInterface;
class PANELDLL_EXPORT PanelDll
{
private:
	std::unique_ptr<PanelInterface> d_panelInterface;
public:
    PanelDll();
	bool initilise();
	bool setSampleTime(int in_milliseconds);
	bool setFrames(int in_frames);
	bool setSampleMode(SampleMode in_sampleMode);
	bool setGainFactor(int in_gainFactor);

	//采集多帧时会将数据连续存储在同一内存区域
	bool getPanelSize(int& out_width, int& out_height);
	bool setPanelSize(int& in_width, int& in_height);
	unsigned long getFramSize();
	bool beginAcquire(unsigned short d_quantity);
	void stopAcquire();
	bool initialise();
	int getImageQuantity();
	bool getHeadImage(unsigned short** in_imageData);
	void clearImageQueue();
};
