#include "PanelInterface.h"

PanelInterface::PanelInterface(): Panel()
{

}


PanelInterface::~PanelInterface()
{

}

bool PanelInterface::setFrames(int in_frames)
{
	d_frames = in_frames;
	d_frameSize = d_width * d_height * d_frames * sizeof(unsigned short);
	return true;
}
size_t PanelInterface::getFrameSize()
{
	return d_frameSize;
}
float PanelInterface::getPixelSize()
{
	return d_pixelSize;
}
void PanelInterface::setFrameCallback(std::function<void(unsigned short*)> in_imageProcessCallBack)
{
	d_imageProcCallback = in_imageProcessCallBack;
}
int PanelInterface::getSampleTime()
{
	return d_sampleTime;
}
bool PanelInterface::getPanelSize(int& out_width, int& out_height)
{
	out_width = d_width;
	out_height = d_height;
	return true;
}

bool PanelInterface::setPanelSize(int in_width, int in_height)
{
	d_width = in_width;
	d_height = in_height;
	return true;
}