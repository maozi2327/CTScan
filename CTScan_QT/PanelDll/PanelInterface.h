#pragma once
#include <qstring.h>
#include <vector>
#include "panelHeaders.h"
#include "../Public/headers/CommandQueue.h"
//面板只执行采集，返回原始数据，不负责生成文件，文件命名和文件保存
class PanelInterface
{
public:
    PanelInterface();
    virtual ~PanelInterface();

private:
    
protected:
    unsigned int d_width;
    unsigned int d_height;
    int d_depth;
    int d_frames;
    int d_sampleTime;
    int d_gainFactor;
	size_t d_frameSize;
    SampleMode d_sampleMode;
	TheQueue<unsigned char*> d_imageQueue;
public:
    virtual bool setSampleTime(int in_milliseconds) = 0;
    virtual bool setFrames(int in_frames);
    virtual bool setSampleMode(SampleMode in_sampleMode) = 0;
    virtual bool setGainFactor(int in_gainFactor) = 0;
	virtual bool setBinMode(BinMode in_binMode) = 0;
    //采集多帧时会将数据连续存储在同一内存区域
    virtual bool getPanelSize(int& out_width, int& out_height);
    virtual bool setPanelSize(int in_width, int in_height);
    virtual size_t getFramSize();
    virtual bool beginAcquire(unsigned short d_quantity) = 0;
    virtual void stopAcquire() = 0;
    virtual bool initialise() = 0;
    virtual int getImageQuantity();
    virtual bool getHeadImage(unsigned short** in_imageData);
    virtual void clearImageQueue();
};