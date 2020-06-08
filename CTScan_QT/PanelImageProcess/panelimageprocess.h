#pragma once

#include "panelimageprocess_global.h"
#include <QString>
class PANELIMAGEPROCESS_EXPORT PanelImageProcess
{
private:
	unsigned short* d_bkgData;
	unsigned short* d_airData;
	unsigned short* d_defectData;
	unsigned short* d_correctedData;
	float* d_correctedDataFloat;
	void* d_correctedDataVoid;
	QString d_bkg;
public:
	PanelImageProcess();
	int createBkgFileToFile(QString& in_sourceFile, QString& in_destFile);
	int createBkgFileToData(QString& in_sourceFile);
	int createBkgDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_line, int in_column, int in_frames);
	int createBkgDataToData(unsigned short** in_sourceData, unsigned short* in_destData, 
		int in_line, int in_column, int in_frames);

	int createAirFileToFile(QString& in_sourceFile, QString& in_destFile, QString& d_bkgFile);
	int createAirFileToData(QString& in_sourceFile, QString& d_bkgFile);
	int createAirDataToFile(unsigned short** in_sourceData, QString& in_destFile, QString& d_bkgFile, int in_line,
		int in_column, int in_frames);
	int createAirDataToData(unsigned short** in_sourceData, QString& d_bkgFile,
		int in_line, int in_column, int in_frames);

	int bkgCorrectFileToFile(QString& in_sourceFile, QString& in_destFile);
	int bkgCorrectFileToData(QString& in_sourceFile);
	int bkgCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column);
	int bkgCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	int airCorrectFileToFile(QString& in_sourceFile, QString& in_destFile);
	int airCorrectFileToData(QString& in_sourceFile);
	int airCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column);
	int airCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	int defectCorrectFileToFile(QString& in_sourceFile, QString& in_destFile);
	int defectCorrectFileToData(QString& in_sourceFile);
	int defectCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column);
	int defectCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	int binProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_binWidth, int in_binHeight);
	int binProcessFileToData(QString& in_sourceFile, int in_binWidth, int in_binHeight);
	int binProcessDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column
		, int in_binWidth, int in_binHeight);
	int binProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column
		, int in_binWidth, int in_binHeight);

	int rotateProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_iRotationType, int iRotationAngle);
	int rotateProcessFileToData(QString& in_sourceFile, int in_iRotationType, int iRotationAngle);
	int rotateProcessDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, 
		int in_column, int in_iRotationType, int iRotationAngle);
	int rotateProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column, 
		int in_iRotationType, int iRotationAngle);

	int mergeProcessFileToFile(QString& in_sourceFile, QString& in_destFile);
	int mergeProcessFileToData(QString& in_sourceFile);
	int mergeProcessDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_frames, int in_line, int in_column);
	int mergeProcessDataToData(unsigned short** in_sourceData, int in_frames, int in_line, int in_column);

	int dataSplice(QString& in_pathA, QString& in_pathB, QString& in_pathFinal, int& progress);
	bool loadBkgData(QString& d_bkgFileName);
	bool loadAirData(QString& d_bkgFileName);
};
