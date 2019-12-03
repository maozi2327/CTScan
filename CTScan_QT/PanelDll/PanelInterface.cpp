#include "PanelInterface.h"

PanelInterface::PanelInterface()
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
void PanelInterface::clearImageQueue()
{
	d_imageQueue.clear();
}
bool PanelInterface::getHeadImage(unsigned short** in_imageData)
{
	unsigned char* data;

	if (!d_imageQueue.pop(data))
		return false;

	*in_imageData = (unsigned short*)data;
	return true;
}
int PanelInterface::getImageQuantity()
{
	return d_imageQueue.size();
}