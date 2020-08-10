#pragma once
#pragma comment(lib, "./public/lib/MicroDataCorrectionDll.lib")
#pragma comment(lib, "./public/lib/tiff.lib")

#include "panelimageprocess_global.h"
#include <QString>
class PANELIMAGEPROCESS_EXPORT PanelImageProcess
{
private:
	class Impl;
	std::unique_ptr<Impl> d_impl;
	bool loadTiff(const QString& in_sourceFile, unsigned short*& in_data);
	bool saveTiff(const QString& in_sourceFile);
public:
	PanelImageProcess();
	~PanelImageProcess();

	int createBkgFileToFile(const QString& in_sourceFile, const QString& in_destFile);
	int createBkgFileToData(const QString& in_sourceFile);
	int createBkgDataToFile(unsigned short** in_sourceData, const QString& in_destFile, int in_line, int in_column, int in_frames);
	int createBkgDataToData(unsigned short** in_sourceData, unsigned short* in_destData,
		int in_line, int in_column, int in_frames);

	int createAirFileToFile(const QString& in_sourceFile, const QString& in_destFile, const QString& d_bkgFile);
	int createAirFileToData(const QString& in_sourceFile, const QString& d_bkgFile);
	int createAirDataToFile(unsigned short** in_sourceData, const QString& in_destFile, const QString& d_bkgFile, int in_line,
		int in_column, int in_frames);
	int createAirDataToData(unsigned short** in_sourceData, const QString& d_bkgFile,
		int in_line, int in_column, int in_frames);

	int bkgCorrectFileToFile(const QString& in_sourceFile, const QString& in_destFile);
	int bkgCorrectFileToData(const QString& in_sourceFile);
	int bkgCorrectDataToFile(unsigned short* in_sourceData, const QString& in_destFile, int in_line, int in_column);
	int bkgCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	int airCorrectFileToFile(const QString& in_sourceFile, const QString& in_destFile);
	int airCorrectFileToData(const QString& in_sourceFile);
	int airCorrectDataToFile(unsigned short* in_sourceData, const QString& in_destFile, int in_line, int in_column);
	int airCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	int defectCorrectFileToFile(const QString& in_sourceFile, const QString& in_destFile);
	int defectCorrectFileToData(const QString& in_sourceFile);
	int defectCorrectDataToFile(unsigned short* in_sourceData, const QString& in_destFile, int in_line, int in_column);
	int defectCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	int binProcessFileToFile(const QString& in_sourceFile, const QString& in_destFile, int in_binWidth, int in_binHeight);
	int binProcessFileToData(const QString& in_sourceFile, int in_binWidth, int in_binHeight);
	int binProcessDataToFile(unsigned short* in_sourceData, const QString& in_destFile, int in_line, int in_column
		, int in_binWidth, int in_binHeight);
	int binProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column
		, int in_binWidth, int in_binHeight);

	int rotateProcessFileToFile(const QString& in_sourceFile, const QString& in_destFile, int in_iRotationType, int iRotationAngle);
	int rotateProcessFileToData(const QString& in_sourceFile, int in_iRotationType, int iRotationAngle);
	int rotateProcessDataToFile(unsigned short* in_sourceData, const QString& in_destFile, int in_line,
		int in_column, int in_iRotationType, int iRotationAngle);
	int rotateProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column,
		int in_iRotationType, int iRotationAngle);

	int mergeProcessFileToFile(const QString& in_sourceFile, const QString& in_destFile);
	int mergeProcessFileToData(const QString& in_sourceFile);
	int mergeProcessDataToFile(unsigned short** in_sourceData, const QString& in_destFile, int in_frames, int in_line, int in_column);
	int mergeProcessDataToData(unsigned short** in_sourceData, int in_frames, int in_line, int in_column);

	bool saveMultiBitmapDataToFile(unsigned short* in_sourceData, const QString& in_destFile, int in_frames, int in_line, int in_column);
	bool saveSingleBitmapDataToFile(unsigned short* in_sourceData, const QString& in_destFile, int in_line, int in_column);
	int dataSplice(const QString& in_pathA, const QString& in_pathB, const QString& in_pathFinal, int& progress);
	bool loadBkgData(const QString& d_bkgFileName);
	bool loadAirData(const QString& d_bkgFileName);
	bool loadDefectData(const QString& d_bkgFileName);
};

class PANELIMAGEPROCESS_EXPORT PanelImageProcessFactory
{
public:
	static std::unique_ptr<PanelImageProcess> getPanelImageProcess();
};