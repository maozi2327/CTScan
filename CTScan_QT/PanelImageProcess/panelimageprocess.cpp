#include "stdafx.h"
#include "PanelImageProcess.h"
#include "../Public/headers/MicroDataCorrection.h"
#include "../Public/headers/tiffio.h"
#include <algorithm>
#include <QFileInfo>

class PanelImageProcess::Impl
{
public:
	unsigned short* d_bkgData;
	unsigned short* d_airData;
	unsigned short* d_defectData;
	unsigned short* d_correctedData;
	float* d_correctedDataFloat;
	void* d_correctedDataVoid;
	QString d_bkg;
};

PanelImageProcess::PanelImageProcess()
{

}


PanelImageProcess::~PanelImageProcess()
{

}

bool PanelImageProcess::loadTiff(const QString & in_sourceFile, unsigned short*& in_data)
{
	QFileInfo info(in_sourceFile);
	size_t fileSize = 0;

	if (info.exists())
		fileSize = info.size();
	else
		return false;

	QByteArray fileName = in_sourceFile.toLocal8Bit();
	TIFF* tif = TIFFOpen(fileName.data(), "r");

	if (!tif)
		return false;

	int dirCount = 0;
	char* buf = new char[fileSize];
	
	size_t bytesRead = 0;

	do
	{
		++dirCount;
		unsigned long long* bc;
		TIFFGetField(tif, TIFFTAG_STRIPBYTECOUNTS, &bc);
		uint32 stripSize;
		stripSize = bc[0];
		size_t stripCount = TIFFNumberOfStrips(tif);

		for (tstrip_t strip = 0; strip < stripCount; strip++)
		{
			TIFFReadRawStrip(tif, strip, buf + bytesRead, bc[strip]);
			bytesRead += bc[strip];
		}
	}
	while (TIFFReadDirectory(tif));

	realloc(buf, bytesRead);
	TIFFClose(tif);
	in_data = (unsigned short*)(buf);
	return true;
}

bool PanelImageProcess::saveTiff(const QString & in_sourceFile)
{
	return false;
}


int PanelImageProcess::createBkgFileToFile(const QString& in_sourceFile, const QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTCreateBKGData(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, 0);
}

int PanelImageProcess::createBkgFileToData(const QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTCreateBKGData(nullptr, sourceFileName.data(), d_impl->d_correctedData, nullptr, 0, 0, 0);
}

int PanelImageProcess::createBkgDataToFile(unsigned short** in_sourceData, const QString& in_destFile, int in_line,
	int in_column, int in_frames)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTCreateBKGData(in_sourceData, nullptr, nullptr, destFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcess::createBkgDataToData(unsigned short** in_sourceData, unsigned short * in_destData,
	int in_line, int in_column, int in_frames)
{
	return _nCTCreateBKGData(in_sourceData, nullptr, in_destData, nullptr, in_line, in_column, in_frames);
}

int PanelImageProcess::createAirFileToFile(const QString& in_sourceFile, const QString& in_destFile, const QString& in_bkgFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(nullptr, sourceFileName.data(), nullptr, destFileName.data(),
		nullptr, bkgFileName.data(), 0, 0, 0);
}

int PanelImageProcess::createAirFileToData(const QString& in_sourceFile, const QString& in_bkgFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(nullptr, sourceFileName.data(), d_impl->d_correctedDataFloat, nullptr,
		nullptr, bkgFileName.data(), 0, 0, 0);
}

int PanelImageProcess::createAirDataToFile(unsigned short** in_sourceData, const QString& in_destFile, const QString& in_bkgFile, int in_line,
	int in_column, int in_frames)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(in_sourceData, nullptr, nullptr, destFileName.data(),
		nullptr, bkgFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcess::createAirDataToData(unsigned short** in_sourceData, const QString& in_bkgFile,
	int in_line, int in_column, int in_frames)
{
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(in_sourceData, nullptr, d_impl->d_correctedDataFloat, nullptr,
		nullptr, bkgFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcess::bkgCorrectFileToFile(const QString& in_sourceFile, const QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBKGCorrection(nullptr, sourceFileName.data(), d_impl->d_bkgData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcess::bkgCorrectFileToData(const QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTBKGCorrection(nullptr, sourceFileName.data(), d_impl->d_bkgData, nullptr, d_impl->d_correctedData, nullptr, 0, 0);
}

int PanelImageProcess::bkgCorrectDataToFile(unsigned short * in_sourceData, const QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBKGCorrection(in_sourceData, nullptr, d_impl->d_bkgData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcess::bkgCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTBKGCorrection(in_sourceData, nullptr, d_impl->d_bkgData, nullptr, d_impl->d_correctedData, nullptr, in_line, in_column);
}

int PanelImageProcess::airCorrectFileToFile(const QString& in_sourceFile, const QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTAIRCorrection(nullptr, sourceFileName.data(), d_impl->d_airData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcess::airCorrectFileToData(const QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTAIRCorrection(nullptr, sourceFileName.data(), d_impl->d_airData, nullptr, d_impl->d_correctedDataFloat, nullptr, 0, 0);
}

int PanelImageProcess::airCorrectDataToFile(unsigned short * in_sourceData, const QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTAIRCorrection(in_sourceData, nullptr, d_impl->d_airData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcess::airCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTAIRCorrection(in_sourceData, nullptr, d_impl->d_bkgData, nullptr, d_impl->d_correctedDataFloat, nullptr, in_line, in_column);
}

int PanelImageProcess::defectCorrectFileToFile(const QString& in_sourceFile, const QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTDefectCorrection(nullptr, sourceFileName.data(), d_impl->d_defectData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcess::defectCorrectFileToData(const QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTDefectCorrection(nullptr, sourceFileName.data(), d_impl->d_defectData, nullptr, d_impl->d_correctedDataVoid, nullptr, 0, 0);
}

int PanelImageProcess::defectCorrectDataToFile(unsigned short * in_sourceData, const QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTDefectCorrection(in_sourceData, nullptr, d_impl->d_defectData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcess::defectCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTDefectCorrection(in_sourceData, nullptr, d_impl->d_defectData, nullptr, d_impl->d_correctedDataVoid, nullptr, in_line, in_column);
}

int PanelImageProcess::binProcessFileToFile(const QString& in_sourceFile, const QString& in_destFile, int in_binWidth, int in_binHeight)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBinModeProcess(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, in_binWidth, in_binHeight);
}

int PanelImageProcess::binProcessFileToData(const QString& in_sourceFile, int in_binWidth, int in_binHeight)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTBinModeProcess(nullptr, sourceFileName.data(), d_impl->d_correctedData, nullptr, 0, 0, in_binWidth, in_binHeight);
}

int PanelImageProcess::binProcessDataToFile(unsigned short * in_sourceData, const QString& in_destFile,
	int in_line, int in_column, int in_binWidth, int in_binHeight)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBinModeProcess(in_sourceData, nullptr, nullptr, destFileName.data(), in_line, in_column,
		in_binHeight, in_binHeight);
}

int PanelImageProcess::binProcessDataToData(unsigned short * in_sourceData, int in_line, int in_column
	, int in_binWidth, int in_binHeight)
{
	return _nCTBinModeProcess(in_sourceData, nullptr, d_impl->d_correctedData, nullptr,
		in_line, in_column, in_binWidth, in_binHeight);
}

int PanelImageProcess::rotateProcessFileToFile(const QString& in_sourceFile, const QString& in_destFile
	, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTRotationProcess(nullptr, sourceFileName.data(), nullptr, destFileName.data(),
		in_iRotationType, in_iRotationAngle, 0, 0);
}

int PanelImageProcess::rotateProcessFileToData(const QString& in_sourceFile, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTRotationProcess(nullptr, sourceFileName.data(), d_impl->d_correctedData, nullptr,
		in_iRotationType, in_iRotationAngle, 0, 0);
}

int PanelImageProcess::rotateProcessDataToFile(unsigned short * in_sourceData, const QString& in_destFile,
	int in_line, int in_column, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTRotationProcess(in_sourceData, nullptr, nullptr, destFileName.data(),
		in_iRotationType, in_iRotationAngle, in_line, in_column);
}

int PanelImageProcess::rotateProcessDataToData(unsigned short * in_sourceData,
	int in_line, int in_column, int in_iRotationType, int in_iRotationAngle)
{
	return _nCTRotationProcess(in_sourceData, nullptr, d_impl->d_correctedData, nullptr,
		in_iRotationType, in_iRotationAngle, in_line, in_column);
}

int PanelImageProcess::mergeProcessFileToFile(const QString& in_sourceFile, const QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTMergeFrames(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, 0);
}

int PanelImageProcess::mergeProcessFileToData(const QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTMergeFrames(nullptr, sourceFileName.data(), d_impl->d_correctedData, nullptr, 0, 0, 0);
}

int PanelImageProcess::mergeProcessDataToFile(unsigned short** in_sourceData, const QString& in_destFile,
	int in_frames, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTMergeFrames(in_sourceData, nullptr, nullptr, destFileName.data(), in_frames, in_line, in_column);
}

int PanelImageProcess::mergeProcessDataToData(unsigned short** in_sourceData, int in_frames, int in_line, int in_column)
{
	return _nCTMergeFrames(in_sourceData, nullptr, d_impl->d_correctedData, nullptr, in_frames, in_line, in_column);
}

bool PanelImageProcess::saveMultiBitmapDataToFile(unsigned short * in_sourceData, const QString& in_destFile, int in_frames, int in_line, int in_column)
{
	return false;
}

bool PanelImageProcess::saveSingleBitmapDataToFile(unsigned short * in_sourceData, const QString& in_destFile, int in_line, int in_column)
{
	return false;
}

int PanelImageProcess::dataSplice(const QString & in_pathA, const QString & in_pathB, const QString& in_pathFinal, int& progress)
{
	QByteArray pathA = in_pathA.toLocal8Bit();
	QByteArray pathB = in_pathB.toLocal8Bit();
	QByteArray pathFinal = in_pathFinal.toLocal8Bit();
	return 0;//_nCTDataSplicing_Detector(pathA.data(), pathB.data(), pathFinal.data(), &progress);
}

bool PanelImageProcess::loadBkgData(const QString& d_bkgFileName)
{

	return false;
}

bool PanelImageProcess::loadAirData(const QString& d_airFileName)
{
	if (d_impl->d_airData)
		delete[] d_impl->d_airData;

	loadTiff(d_airFileName, d_impl->d_airData);
	return false;
}
bool PanelImageProcess::loadDefectData(const QString& d_bkgFileName)
{

	return false;
}

std::unique_ptr<PanelImageProcess> PanelImageProcessFactory::getPanelImageProcess()
{
	return std::unique_ptr<PanelImageProcess>(new PanelImageProcess);
}