#pragma once
class ImageProcess
{
public:
	ImageProcess();
	~ImageProcess();

	void rotation90(unsigned short* in_image, int in_width, int in_height, int in_frames);
	void rotation180(unsigned short* in_image, int in_width, int in_height, int in_frames);
	void rotation270(unsigned short* in_image, int in_width, int in_height, int in_frames);
	void upDownReverse(unsigned short* in_image, int in_width, int in_height, int in_frames);
	void leftRightReverse(unsigned short* in_image, int in_width, int in_height, int in_frames);
	void rotation90AndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames);
	void rotation180AndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames);
	void rotation270AndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames);
	void upDownReverseAndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames);
	void leftRightReverseAndSave(unsigned short* in_image, int in_width, int in_height, QString in_fileName, int in_frames);
};

