#include "stdafx.h"
#include "imageprocess.h"

ImageProcess::ImageProcess()
{
}


ImageProcess::~ImageProcess()
{
}

void ImageProcess::rotation90(unsigned short* in_image, int in_width, int in_height, int in_frames)
{
	size_t imageSize = in_width * in_height * sizeof(unsigned short);
	unsigned short* tempMemory = (unsigned short*)malloc(imageSize);
	memcpy(tempMemory, in_image, imageSize);
	int newWidth = in_height;
	int newHeight = in_width;
	
	for(int i = 0; i != newHeight; ++i )
		for (int j = 0; j != newWidth; ++j)
			*(in_image + i * newWidth + j) = *(tempMemory + (in_height - j - 1) * in_width + i);

	free(tempMemory);
}
void ImageProcess::rotation180(unsigned short* in_image, int in_width, int in_height, int in_frames)
{
	size_t imageSize = in_width * in_height * sizeof(unsigned short);
	unsigned short* tempMemory = (unsigned short*)malloc(imageSize);
	memcpy(tempMemory, in_image, imageSize);

	for (int i = 0; i != in_height; ++i)
		for (int j = 0; j != in_width; ++j)
			*(in_image + i * in_height + j) = *(tempMemory + (in_width - i - 1) * in_height + in_height - j - 1);

	free(tempMemory);
}
void ImageProcess::rotation270(unsigned short* in_image, int in_width, int in_height, int in_frames)
{
	size_t imageSize = in_width * in_height * sizeof(unsigned short);
	unsigned short* tempMemory = (unsigned short*)malloc(imageSize);
	memcpy(tempMemory, in_image, imageSize);
	int newWidth = in_height;
	int newHeight = in_width;

	for (int i = 0; i != newHeight; ++i)
		for (int j = 0; j != newWidth; ++j)
			*(in_image + i * newWidth + j) = *(tempMemory + (in_height - j - 1) * in_width + in_width - i - 1); 

	free(tempMemory);
}
void ImageProcess::upDownReverse(unsigned short* in_image, int in_width, int in_height, int in_frames)
{
	size_t imageSize = in_width * in_height * sizeof(unsigned short);
	unsigned short* tempMemory = (unsigned short*)malloc(imageSize);
	memcpy(tempMemory, in_image, imageSize);
	size_t sizePerLine = in_width * sizeof(unsigned short);

	for (int i = 0; i != in_height; ++i)
		memcpy(in_image + i * sizePerLine, tempMemory + (in_height - i - 1) * sizePerLine, sizePerLine);

	free(tempMemory);
}
void ImageProcess::leftRightReverse(unsigned short* in_image, int in_width, int in_height, int in_frames)
{
	size_t imageSize = in_width * in_height * sizeof(unsigned short);
	unsigned short* tempMemory = (unsigned short*)malloc(imageSize);
	memcpy(tempMemory, in_image, imageSize);
	
	for (int i = 0; i != in_height; ++i)
		for (int j = 0; j != in_width; ++j)
			*(in_image + i * in_width * sizeof(unsigned short) + j) = *(in_image + i * in_width * sizeof(unsigned short) + in_width - j - 1);

	free(tempMemory);
}
void ImageProcess::rotation90AndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames) 
{

}
void ImageProcess::rotation180AndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames)
{

}

void ImageProcess::rotation270AndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames)
{

}

void ImageProcess::upDownReverseAndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames)
{

}

void ImageProcess::leftRightReverseAndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames)
{

}

