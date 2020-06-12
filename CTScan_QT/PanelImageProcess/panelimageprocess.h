#pragma once

#include "panelimageprocess_global.h"
#include <QString>
class PanelImageProcess
{
public:
	PanelImageProcess() = default;
	virtual ~PanelImageProcess() = default;
	virtual int createBkgFileToFile(QString& in_sourceFile, QString& in_destFile) = 0;
	virtual int createBkgFileToData(QString& in_sourceFile) = 0 ;
	virtual int createBkgDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_line, int in_column, int in_frames) = 0 ;
	virtual int createBkgDataToData(unsigned short** in_sourceData, unsigned short* in_destData,
		int in_line, int in_column, int in_frames) = 0 ;

	virtual int createAirFileToFile(QString& in_sourceFile, QString& in_destFile, QString& d_bkgFile) = 0 ;
	virtual int createAirFileToData(QString& in_sourceFile, QString& d_bkgFile) = 0 ;
	virtual int createAirDataToFile(unsigned short** in_sourceData, QString& in_destFile, QString& d_bkgFile, int in_line,
		int in_column, int in_frames) = 0 ;
	virtual int createAirDataToData(unsigned short** in_sourceData, QString& d_bkgFile,
		int in_line, int in_column, int in_frames) = 0 ;

	virtual int bkgCorrectFileToFile(QString& in_sourceFile, QString& in_destFile) = 0 ;
	virtual int bkgCorrectFileToData(QString& in_sourceFile) = 0 ;
	virtual int bkgCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column) = 0 ;
	virtual int bkgCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column) = 0 ;

	virtual int airCorrectFileToFile(QString& in_sourceFile, QString& in_destFile) = 0 ;
	virtual int airCorrectFileToData(QString& in_sourceFile) = 0 ;
	virtual int airCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column) = 0 ;
	virtual int airCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column) = 0 ;

	virtual int defectCorrectFileToFile(QString& in_sourceFile, QString& in_destFile) = 0 ;
	virtual int defectCorrectFileToData(QString& in_sourceFile) = 0 ;
	virtual int defectCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column) = 0 ;
	virtual int defectCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column) = 0 ;

	virtual int binProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_binWidth, int in_binHeight) = 0 ;
	virtual int binProcessFileToData(QString& in_sourceFile, int in_binWidth, int in_binHeight) = 0 ;
	virtual int binProcessDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column
		, int in_binWidth, int in_binHeight) = 0 ;
	virtual int binProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column
		, int in_binWidth, int in_binHeight) = 0 ;

	virtual int rotateProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_iRotationType, int iRotationAngle) = 0 ;
	virtual int rotateProcessFileToData(QString& in_sourceFile, int in_iRotationType, int iRotationAngle) = 0 ;
	virtual int rotateProcessDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line,
		int in_column, int in_iRotationType, int iRotationAngle) = 0 ;
	virtual int rotateProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column,
		int in_iRotationType, int iRotationAngle) = 0 ;

	virtual int mergeProcessFileToFile(QString& in_sourceFile, QString& in_destFile) = 0 ;
	virtual int mergeProcessFileToData(QString& in_sourceFile) = 0 ;
	virtual int mergeProcessDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_frames, int in_line, int in_column) = 0 ;
	virtual int mergeProcessDataToData(unsigned short** in_sourceData, int in_frames, int in_line, int in_column) = 0 ;

	virtual int dataSplice(QString& in_pathA, QString& in_pathB, QString& in_pathFinal, int& progress) = 0 ;
	virtual bool loadBkgData(QString& d_bkgFileName) = 0 ;
	virtual bool loadAirData(QString& d_bkgFileName) = 0 ;
	virtual bool saveMultiBitmapDataToFile(unsigned short** in_sourceData, int in_frames, int in_line, int in_column) = 0;
};

class PANELIMAGEPROCESS_EXPORT PanelImageProcessFactory
{
public:
	static std::unique_ptr<PanelImageProcess> getPanelImageProcess();
};