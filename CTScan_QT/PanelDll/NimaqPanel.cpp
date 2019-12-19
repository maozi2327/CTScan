#include "NimaqPanel.h"
#include "niimaq.h"
#include <thread>
#pragma comment(lib, "imaq.lib")

const int RINGBUFFERNUM = 5;

NimaqPanel::NimaqPanel() : d_quantityOfRingBuffer(RINGBUFFERNUM), d_NiImaqIid(0)
{
    memcpy(d_NiImaqintfName, "img0", sizeof("imag0"));
}


NimaqPanel::~NimaqPanel()
{
	stopAcquire();

	if(d_ringThreadPromisePtr)
		d_ringThreadPromisePtr->get_future().get();
}
bool NimaqPanel::initialise()
{
    int retError = 0;
    retError = imgInterfaceOpen(d_NiImaqintfName, &d_NiImaqIid);
    if (retError < 0) {
        return false;
    }
    retError = imgSessionOpen(d_NiImaqIid, &d_NiImaqSid);
    if (retError < 0) {
        return false;
    }
    retError = imgInterfaceReset(d_NiImaqIid);
    if (retError < 0) {
        return false;
    }
    retError = imgGetAttribute(d_NiImaqSid, IMG_ATTR_ROI_WIDTH, &d_width);
    if (retError < 0) {
        return false;
    }
    retError = imgGetAttribute(d_NiImaqSid, IMG_ATTR_ROI_HEIGHT, &d_height);
    if (retError < 0) {
        return false;
    }
    retError = imgGetAttribute(d_NiImaqSid, IMG_ATTR_BITSPERPIXEL, &d_depth);
    if (retError < 0) {
        return false;
    }

    d_frameSize = d_width * d_height *(d_depth >> 3);
    std::function<void()> threadFun = std::bind(&NimaqPanel::serialSendThread, this);
    std::thread(threadFun).detach();
    return true;
}
bool NimaqPanel::setBinMode(BinMode in_binMode)
{
	return true;
}
void NimaqPanel::serialSendThread()
{
    while (d_serialSendRunFlag)
    {
        SerialCmd cmd(false);

        if (d_serialQueue.pop(cmd))
        {
            imgSessionSerialFlush(d_NiImaqSid);
            Int32 ret = imgSessionSerialWrite(d_NiImaqSid, (Int8*)cmd.ptr, (uInt32*)(&cmd.size), 100 );
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
}
bool NimaqPanel::setSampleTime(int in_sampleTime)
{
    if (in_sampleTime > 25500 || in_sampleTime < 0)
        return false;

    d_sampleTime = in_sampleTime;
    SerialCmd cmd(false);
    cmd.ptr = new unsigned char[4];
    cmd.ptr[0] = 0x5A;
    cmd.ptr[1] = 0xA5;
    cmd.ptr[2] = 0x01;
    cmd.ptr[3] = unsigned char(in_sampleTime / 100);
    cmd.size = 4;
    d_serialQueue.push(cmd);
    return true;
}

bool NimaqPanel::setSampleMode(SampleMode in_sampleMode)
{
    SerialCmd cmd(false);
    cmd.ptr = new unsigned char[4];
    cmd.ptr[0] = 0x5A;
    cmd.ptr[1] = 0xA5;
    cmd.ptr[2] = 0x02;
    switch (in_sampleMode)
    {
    case SampleMode::softTrigger:
        cmd.ptr[3] = 0x00;
        break;
    case SampleMode::exTrigger:
        cmd.ptr[3] = 0x01;
        break;
    default:
        break;
    }
    cmd.size = 4;
    d_serialQueue.push(cmd);
    d_sampleMode = in_sampleMode;
    return true;
}
bool NimaqPanel::setGainFactor(int in_gainFactor)
{
    if(in_gainFactor < 0 || in_gainFactor > 8)
        d_gainFactor = in_gainFactor;
    
    SerialCmd cmd(false);
    cmd.ptr = new unsigned char[4];
    cmd.ptr[0] = 0x5A;
    cmd.ptr[1] = 0xA5;
    cmd.ptr[2] = 0x03;
    cmd.ptr[3] = unsigned char(in_gainFactor);
    cmd.size = 4;
    d_serialQueue.push(cmd);
    return true;
}

bool NimaqPanel::beginAcquire(unsigned short d_quantity)
{
    {
        std::unique_lock<std::mutex> lk(d_ringThreadMutex);

        if (d_ringThreadCond.wait_for(lk, std::chrono::milliseconds(1)) == std::cv_status::timeout)
            return false;
    }

	clearImageQueue();
    imgRingSetup(d_NiImaqSid, d_quantityOfRingBuffer, NULL, 0, TRUE);
    d_ringThreadPromisePtr.reset(new std::promise<bool>);
    std::function<void()> threadFun = std::bind(&NimaqPanel::ringThread, this, std::ref(*d_ringThreadPromisePtr));
    d_ringThreadRunFlag = true;
    std::thread(threadFun).detach();
    return true;
}

void NimaqPanel::ringThread(std::promise<bool>& in_promise)
{
    {
        std::lock_guard<std::mutex> lk(d_ringThreadMutex);
        in_promise.set_value_at_thread_exit(true);
        int NiImaqRingBufNum = 0;
        uInt32 currRingBufNum = 0;
        unsigned char* ringBufAddr;
        unsigned char* framesMem = 0;
        while (d_ringThreadRunFlag)
        {
            if (frameCount % d_frames == 0)
                framesMem = (unsigned char*)malloc(d_frameSize);

            Int32 nRet = imgSessionExamineBuffer2(d_NiImaqSid, NiImaqRingBufNum, &currRingBufNum, (void**)&ringBufAddr);

            if (nRet < 0)
                break;

            memcpy(framesMem + d_frameSize * NiImaqRingBufNum, ringBufAddr, d_frameSize);
            free(ringBufAddr);
            NiImaqRingBufNum = (++NiImaqRingBufNum) % d_quantityOfRingBuffer;

            if (++frameCount % d_frames == 0 && d_ringThreadRunFlag)
            {
                d_imageQueue.push(framesMem);
                frameCount = 0;
            }

            imgSessionReleaseBuffer(d_NiImaqSid);
        }
    }
    d_ringThreadCond.notify_all();
}
void NimaqPanel::stopAcquire()
{
    d_ringThreadRunFlag = false;
}