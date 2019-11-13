#pragma once
#include "PanelInterface.h"
#include "niimaq.h"
#include "../Public/headers/CommandQueue.h"
#include "panelHeaders.h"
#include <future>
#include <mutex>
#include <condition_variable>
class NimaqPanel :
    public PanelInterface
{
    struct SerialCmd
    {
        unsigned char* ptr;
        int size;

        SerialCmd(bool receive)
        {
            if (receive)
            {
                ptr = new unsigned char[50];
                size = 0;
            }
            else
                ;
        }
    };
private:
    unsigned long d_imageMemorySize;
    SESSION_ID d_NiImaqSid;
    INTERFACE_ID d_NiImaqIid;
    char d_NiImaqintfName[64];
    int d_quantityOfRingBuffer;
    bool d_ringThreadRunFlag;
    bool d_serialSendRunFlag;
    TheQueue<unsigned char*> d_imageQueue;
    TheQueue<SerialCmd> d_serialQueue;
    void serialSendThread();
    void ringThread(std::promise<bool>& in_promise);
    std::shared_ptr<std::promise<bool>> d_ringThreadPromisePtr;
    std::mutex d_ringThreadMutex;
    std::condition_variable d_ringThreadCond;
public:
    NimaqPanel();
    ~NimaqPanel();

    virtual bool setSampleTime(int in_sampleTime);
    virtual bool setFrames(int in_frames);
    virtual bool setSampleMode(SampleMode in_sampleMode);
    virtual bool setGainFactor(int in_gainFactor);
    //采集多帧时会将数据连续存储在同一内存区域
    virtual bool getPanelSize(int& out_width, int& out_height);
    virtual bool setPanelSize(int in_width, int in_height);
    virtual bool beginAcquire(unsigned short d_quantity);
    virtual void stopAcquire();
    virtual bool initialise();
    virtual int getImageQuantity();
    virtual bool getHeadImage(unsigned short** in_imageData);
    virtual unsigned long getImageMemorySize();
    virtual void clearImageQueue();
};

