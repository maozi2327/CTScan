#include "stdafx.h"
#include "panelimageprocess.h"
#include "../Public/headers/MicroDataCorrection.h"
#include "../Public/headers/tiffio.h"

PanelImageProcess::PanelImageProcess()
{

}

int PanelImageProcess::createBkgFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTCreateBKGData(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, 0);
}

int PanelImageProcess::createBkgFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTCreateBKGData(nullptr, sourceFileName.data(), d_correctedData, nullptr, 0, 0, 0);
}

int PanelImageProcess::createBkgDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_line, 
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

int PanelImageProcess::createAirFileToFile(QString& in_sourceFile, QString& in_destFile, QString& in_bkgFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 
		nullptr, bkgFileName.data(), 0, 0, 0);
}

int PanelImageProcess::createAirFileToData(QString& in_sourceFile, QString& in_bkgFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(nullptr, sourceFileName.data(), d_correctedDataFloat, nullptr,
		nullptr, bkgFileName.data(), 0, 0, 0);
}

int PanelImageProcess::createAirDataToFile(unsigned short** in_sourceData, QString& in_destFile, QString& in_bkgFile, int in_line,
	int in_column, int in_frames)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(in_sourceData, nullptr, nullptr, destFileName.data(),
		nullptr, bkgFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcess::createAirDataToData(unsigned short** in_sourceData, QString& in_bkgFile,
	int in_line, int in_column, int in_frames)
{
	QByteArray bkgFileName = in_bkgFile.toLocal8Bit();
	return _nCTCreateAIRData(in_sourceData, nullptr, d_correctedDataFloat, nullptr,
		nullptr, bkgFileName.data(), in_line, in_column, in_frames);
}

int PanelImageProcess::bkgCorrectFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBKGCorrection(nullptr, sourceFileName.data(), d_bkgData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcess::bkgCorrectFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTBKGCorrection(nullptr, sourceFileName.data(), d_bkgData, nullptr, d_correctedData, nullptr, 0, 0);
}

int PanelImageProcess::bkgCorrectDataToFile(unsigned short * in_sourceData, QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBKGCorrection(in_sourceData, nullptr, d_bkgData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcess::bkgCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTBKGCorrection(in_sourceData, nullptr, d_bkgData, nullptr, d_correctedData, nullptr, in_line, in_column);
}

int PanelImageProcess::airCorrectFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTAIRCorrection(nullptr, sourceFileName.data(), d_airData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcess::airCorrectFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTAIRCorrection(nullptr, sourceFileName.data(), d_airData, nullptr, d_correctedDataFloat, nullptr, 0, 0);
}

int PanelImageProcess::airCorrectDataToFile(unsigned short * in_sourceData, QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTAIRCorrection(in_sourceData, nullptr, d_airData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcess::airCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTAIRCorrection(in_sourceData, nullptr, d_bkgData, nullptr, d_correctedDataFloat, nullptr, in_line, in_column);
}

int PanelImageProcess::defectCorrectFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTDefectCorrection(nullptr, sourceFileName.data(), d_defectData, nullptr, nullptr, destFileName.data(), 0, 0);
}

int PanelImageProcess::defectCorrectFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTDefectCorrection(nullptr, sourceFileName.data(), d_defectData, nullptr, d_correctedDataVoid, nullptr, 0, 0);
}

int PanelImageProcess::defectCorrectDataToFile(unsigned short * in_sourceData, QString& in_destFile, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTDefectCorrection(in_sourceData, nullptr, d_defectData, nullptr, nullptr, destFileName.data(), in_line, in_column);
}

int PanelImageProcess::defectCorrectDataToData(unsigned short * in_sourceData, int in_line, int in_column)
{
	return _nCTDefectCorrection(in_sourceData, nullptr, d_defectData, nullptr, d_correctedDataVoid, nullptr, in_line, in_column);
}

int PanelImageProcess::binProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_binWidth, int in_binHeight)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBinModeProcess(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, in_binWidth, in_binHeight);
}

int PanelImageProcess::binProcessFileToData(QString& in_sourceFile, int in_binWidth, int in_binHeight)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTBinModeProcess(nullptr, sourceFileName.data(), d_correctedData, nullptr, 0, 0, in_binWidth, in_binHeight);
}

int PanelImageProcess::binProcessDataToFile(unsigned short * in_sourceData, QString& in_destFile,
	int in_line, int in_column, int in_binWidth, int in_binHeight)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTBinModeProcess(in_sourceData, nullptr, nullptr, destFileName.data(), in_line, in_column,
		in_binHeight, in_binHeight);
}

int PanelImageProcess::binProcessDataToData(unsigned short * in_sourceData, int in_line, int in_column
	, int in_binWidth, int in_binHeight)
{
	return _nCTBinModeProcess(in_sourceData, nullptr, d_correctedData, nullptr,
		in_line, in_column, in_binWidth, in_binHeight);
}

int PanelImageProcess::rotateProcessFileToFile(QString& in_sourceFile, QString& in_destFile
	, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTRotationProcess(nullptr, sourceFileName.data(), nullptr, destFileName.data(),
		in_iRotationType, in_iRotationAngle, 0, 0);
}

int PanelImageProcess::rotateProcessFileToData(QString& in_sourceFile, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTRotationProcess(nullptr, sourceFileName.data(), d_correctedData, nullptr,
		in_iRotationType, in_iRotationAngle, 0, 0);
}

int PanelImageProcess::rotateProcessDataToFile(unsigned short * in_sourceData, QString& in_destFile,
	int in_line, int in_column, int in_iRotationType, int in_iRotationAngle)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTRotationProcess(in_sourceData, nullptr, nullptr, destFileName.data(), 
		in_iRotationType, in_iRotationAngle, in_line, in_column);
}

int PanelImageProcess::rotateProcessDataToData(unsigned short * in_sourceData,
	int in_line, int in_column, int in_iRotationType, int in_iRotationAngle)
{
	return _nCTRotationProcess(in_sourceData, nullptr, d_correctedData, nullptr, 
		in_iRotationType, in_iRotationAngle, in_line, in_column);
}

int PanelImageProcess::mergeProcessFileToFile(QString& in_sourceFile, QString& in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTMergeFrames(nullptr, sourceFileName.data(), nullptr, destFileName.data(), 0, 0, 0);
}

int PanelImageProcess::mergeProcessFileToData(QString& in_sourceFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	return _nCTMergeFrames(nullptr, sourceFileName.data(), d_correctedData, nullptr, 0, 0, 0);
}

int PanelImageProcess::mergeProcessDataToFile(unsigned short** in_sourceData, QString& in_destFile,
	int in_frames, int in_line, int in_column)
{
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return _nCTMergeFrames(in_sourceData, nullptr, nullptr, destFileName.data(), in_frames, in_line, in_column);
}

int PanelImageProcess::mergeProcessDataToData(unsigned short** in_sourceData, int in_frames, int in_line, int in_column)
{
	return _nCTMergeFrames(in_sourceData, nullptr, d_correctedData, nullptr, in_frames, in_line, in_column);
}

int PanelImageProcess::dataSplice(QString & in_pathA, QString & in_pathB, QString& in_pathFinal, int& progress)
{
	QByteArray pathA = in_pathA.toLocal8Bit();
	QByteArray pathB = in_pathB.toLocal8Bit();
	QByteArray pathFinal = in_pathFinal.toLocal8Bit();
	return _nCTDataSplicing_Detector(pathA.data(), pathB.data(), pathFinal.data(), &progress);
}

bool PanelImageProcess::loadBkgData(QString& d_bkgFileName)
{	
	TIFF* tif = TIFFOpen("myfile.tif", "r");
	
	if (tif)
	{
		tdata_t buf;
		tstrip_t strip;
		uint32* bc;
		uint32 stripsize;

		TIFFGetField(tif, TIFFTAG_STRIPBYTECOUNTS, &bc);
		stripsize = bc[0];
		buf = _TIFFmalloc(stripsize);

		for (strip = 0; strip < TIFFNumberOfStrips(tif); strip++) 
		{
			if (bc[strip] > stripsize) {
				buf = _TIFFrealloc(buf, bc[strip]);
				stripsize = bc[strip];
			}
			TIFFReadRawStrip(tif, strip, buf, bc[strip]);
		}

		_TIFFfree(buf);
		TIFFClose(tif);
	}

	return false;
}

bool PanelImageProcess::loadAirData(QString& d_bkgFileName)
{
	return false;
}
