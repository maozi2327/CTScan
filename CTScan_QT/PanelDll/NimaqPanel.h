#pragma once
#include "PanelInterface.h"
#include "niimaq.h"
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
    SESSION_ID d_NiImaqSid;
    INTERFACE_ID d_NiImaqIid;
    char d_NiImaqintfName[64];
    int d_quantityOfRingBuffer;
	int frameCount = 0;
    bool d_ringThreadRunFlag;
    bool d_serialSendRunFlag;
    TheQueue<SerialCmd> d_serialQueue;
    void serialSendThread();
    void ringThread(std::promise<bool>& in_promise);
    std::unique_ptr<std::promise<bool>> d_ringThreadPromisePtr;
    std::mutex d_ringThreadMutex;
    std::condition_variable d_ringThreadCond;
public:
    NimaqPanel();
    ~NimaqPanel();
	virtual bool setBinMode(BinMode in_binMode);
    virtual bool setSampleTime(int in_sampleTime);
    virtual bool setSampleMode(SampleMode in_sampleMode);
    virtual bool setGainFactor(int in_gainFactor);
    //采集多帧时会将数据连续存储在同一内存区域
    virtual bool beginAcquire(unsigned short d_quantity);
    virtual void stopAcquire();
    virtual bool initialise();
};

