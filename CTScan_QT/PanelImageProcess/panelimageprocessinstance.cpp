#include "stdafx.h"
#include "PanelImageProcessInstance.h"
#include "../Public/headers/MicroDataCorrection.h"
#include "../Public/headers/tiffio.h"
#include <algorithm>
#include <QFileInfo>


PanelImageProcessInstance::PanelImageProcessInstance()
{

}


PanelImageProcessInstance::~PanelImageProcessInstance()
{

}

bool PanelImageProcessInstance::loadTiff(QString & in_sourceFile, unsigned short*& in_data)
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

bool PanelImageProcessInstance::saveTiff(QString & in_sourceFile)
{
	return false;
}


int PanelImageProcessInstance::createBkgFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTCreateBKGData(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, 0);
}

int PanelImageProcessInstance::createBkgFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTCreateBKGData(nullptr, sourceFileName.data(), d_correctedData, nullptr, 0, 0, 0);
}

int PanelImageProcessInstance::createBkgDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_line,
	int in_column, int in_frames)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTCreateBKGData(in_sourceData, nullptr, nullptr, destFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcessInstance::createBkgDataToData(unsigned short** in_sourceData, unsigned short * in_destData,
	int in_line, int in_column, int in_frames)
{
	return _nCTCreateBKGData(in_sourceData, nullptr, in_destData, nullptr, in_line, in_column, in_frames);
}

int PanelImageProcessInstance::createAirFileToFile(QString& in_sourceFile, QString& in_destFile, QString& in_bkgFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(nullptr, sourceFileName.data(), nullptr, destFileName.data(),
		nullptr, bkgFileName.data(), 0, 0, 0);
}

int PanelImageProcessInstance::createAirFileToData(QString& in_sourceFile, QString& in_bkgFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(nullptr, sourceFileName.data(), d_correctedDataFloat, nullptr,
		nullptr, bkgFileName.data(), 0, 0, 0);
}

int PanelImageProcessInstance::createAirDataToFile(unsigned short** in_sourceData, QString& in_destFile, QString& in_bkgFile, int in_line,
	int in_column, int in_frames)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(in_sourceData, nullptr, nullptr, destFileName.data(),
		nullptr, bkgFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcessInstance::createAirDataToData(unsigned short** in_sourceData, QString& in_bkgFile,
	int in_line, int in_column, int in_frames)
{
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(in_sourceData, nullptr, d_correctedDataFloat, nullptr,
		nullptr, bkgFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcessInstance::bkgCorrectFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBKGCorrection(nullptr, sourceFileName.data(), d_bkgData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcessInstance::bkgCorrectFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTBKGCorrection(nullptr, sourceFileName.data(), d_bkgData, nullptr, d_correctedData, nullptr, 0, 0);
}

int PanelImageProcessInstance::bkgCorrectDataToFile(unsigned short * in_sourceData, QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBKGCorrection(in_sourceData, nullptr, d_bkgData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcessInstance::bkgCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTBKGCorrection(in_sourceData, nullptr, d_bkgData, nullptr, d_correctedData, nullptr, in_line, in_column);
}

int PanelImageProcessInstance::airCorrectFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTAIRCorrection(nullptr, sourceFileName.data(), d_airData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcessInstance::airCorrectFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTAIRCorrection(nullptr, sourceFileName.data(), d_airData, nullptr, d_correctedDataFloat, nullptr, 0, 0);
}

int PanelImageProcessInstance::airCorrectDataToFile(unsigned short * in_sourceData, QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTAIRCorrection(in_sourceData, nullptr, d_airData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcessInstance::airCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTAIRCorrection(in_sourceData, nullptr, d_bkgData, nullptr, d_correctedDataFloat, nullptr, in_line, in_column);
}

int PanelImageProcessInstance::defectCorrectFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTDefectCorrection(nullptr, sourceFileName.data(), d_defectData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcessInstance::defectCorrectFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTDefectCorrection(nullptr, sourceFileName.data(), d_defectData, nullptr, d_correctedDataVoid, nullptr, 0, 0);
}

int PanelImageProcessInstance::defectCorrectDataToFile(unsigned short * in_sourceData, QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTDefectCorrection(in_sourceData, nullptr, d_defectData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcessInstance::defectCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTDefectCorrection(in_sourceData, nullptr, d_defectData, nullptr, d_correctedDataVoid, nullptr, in_line, in_column);
}

int PanelImageProcessInstance::binProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_binWidth, int in_binHeight)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBinModeProcess(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, in_binWidth, in_binHeight);
}

int PanelImageProcessInstance::binProcessFileToData(QString& in_sourceFile, int in_binWidth, int in_binHeight)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTBinModeProcess(nullptr, sourceFileName.data(), d_correctedData, nullptr, 0, 0, in_binWidth, in_binHeight);
}

int PanelImageProcessInstance::binProcessDataToFile(unsigned short * in_sourceData, QString& in_destFile,
	int in_line, int in_column, int in_binWidth, int in_binHeight)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBinModeProcess(in_sourceData, nullptr, nullptr, destFileName.data(), in_line, in_column,
		in_binHeight, in_binHeight);
}

int PanelImageProcessInstance::binProcessDataToData(unsigned short * in_sourceData, int in_line, int in_column
	, int in_binWidth, int in_binHeight)
{
	return _nCTBinModeProcess(in_sourceData, nullptr, d_correctedData, nullptr,
		in_line, in_column, in_binWidth, in_binHeight);
}

int PanelImageProcessInstance::rotateProcessFileToFile(QString& in_sourceFile, QString& in_destFile
	, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTRotationProcess(nullptr, sourceFileName.data(), nullptr, destFileName.data(),
		in_iRotationType, in_iRotationAngle, 0, 0);
}

int PanelImageProcessInstance::rotateProcessFileToData(QString& in_sourceFile, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTRotationProcess(nullptr, sourceFileName.data(), d_correctedData, nullptr,
		in_iRotationType, in_iRotationAngle, 0, 0);
}

int PanelImageProcessInstance::rotateProcessDataToFile(unsigned short * in_sourceData, QString& in_destFile,
	int in_line, int in_column, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTRotationProcess(in_sourceData, nullptr, nullptr, destFileName.data(),
		in_iRotationType, in_iRotationAngle, in_line, in_column);
}

int PanelImageProcessInstance::rotateProcessDataToData(unsigned short * in_sourceData,
	int in_line, int in_column, int in_iRotationType, int in_iRotationAngle)
{
	return _nCTRotationProcess(in_sourceData, nullptr, d_correctedData, nullptr,
		in_iRotationType, in_iRotationAngle, in_line, in_column);
}

int PanelImageProcessInstance::mergeProcessFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTMergeFrames(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, 0);
}

int PanelImageProcessInstance::mergeProcessFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTMergeFrames(nullptr, sourceFileName.data(), d_correctedData, nullptr, 0, 0, 0);
}

int PanelImageProcessInstance::mergeProcessDataToFile(unsigned short** in_sourceData, QString& in_destFile,
	int in_frames, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTMergeFrames(in_sourceData, nullptr, nullptr, destFileName.data(), in_frames, in_line, in_column);
}

int PanelImageProcessInstance::mergeProcessDataToData(unsigned short** in_sourceData, int in_frames, int in_line, int in_column)
{
	return _nCTMergeFrames(in_sourceData, nullptr, d_correctedData, nullptr, in_frames, in_line, in_column);
}

bool PanelImageProcessInstance::saveMultiBitmapDataToFile(unsigned short ** in_sourceData, int in_frames, int in_line, int in_column)
{
	return false;
}

bool PanelImageProcessInstance::saveSingleBitmapDataToFile(unsigned short * in_sourceData, int in_line, int in_column)
{
	return false;
}

int PanelImageProcessInstance::dataSplice(QString & in_pathA, QString & in_pathB, QString& in_pathFinal, int& progress)
{
	QByteArray pathA = in_pathA.toLocal8Bit();
	QByteArray pathB = in_pathB.toLocal8Bit();
	QByteArray pathFinal = in_pathFinal.toLocal8Bit();
	return _nCTDataSplicing_Detector(pathA.data(), pathB.data(), pathFinal.data(), &progress);
}

bool PanelImageProcessInstance::loadBkgData(QString& d_bkgFileName)
{
	return false;
}

bool PanelImageProcessInstance::loadAirData(QString& d_airFileName)
{
	if (d_airData)
		delete[] d_airData;

	loadTiff(d_airFileName, d_airData);
	return false;
}
