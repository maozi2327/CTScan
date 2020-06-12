#pragma once
#include "panelimageprocess.h"
class PanelImageProcessInstance :
	public PanelImageProcess
{
private:
	unsigned short* d_bkgData;
	unsigned short* d_airData;
	unsigned short* d_defectData;
	unsigned short* d_correctedData;
	float* d_correctedDataFloat;
	void* d_correctedDataVoid;
	QString d_bkg;
	bool loadTiff(QString& in_sourceFile, unsigned short*& in_data);
	bool saveTiff(QString& in_sourceFile);
public:
	PanelImageProcessInstance();
	~PanelImageProcessInstance();

	virtual int createBkgFileToFile(QString& in_sourceFile, QString& in_destFile);
	virtual int createBkgFileToData(QString& in_sourceFile);
	virtual int createBkgDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_line, int in_column, int in_frames);
	virtual int createBkgDataToData(unsigned short** in_sourceData, unsigned short* in_destData,
		int in_line, int in_column, int in_frames);

	virtual int createAirFileToFile(QString& in_sourceFile, QString& in_destFile, QString& d_bkgFile);
	virtual int createAirFileToData(QString& in_sourceFile, QString& d_bkgFile);
	virtual int createAirDataToFile(unsigned short** in_sourceData, QString& in_destFile, QString& d_bkgFile, int in_line,
		int in_column, int in_frames);
	virtual int createAirDataToData(unsigned short** in_sourceData, QString& d_bkgFile,
		int in_line, int in_column, int in_frames);

	virtual int bkgCorrectFileToFile(QString& in_sourceFile, QString& in_destFile);
	virtual int bkgCorrectFileToData(QString& in_sourceFile);
	virtual int bkgCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column);
	virtual int bkgCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	virtual int airCorrectFileToFile(QString& in_sourceFile, QString& in_destFile);
	virtual int airCorrectFileToData(QString& in_sourceFile);
	virtual int airCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column);
	virtual int airCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	virtual int defectCorrectFileToFile(QString& in_sourceFile, QString& in_destFile);
	virtual int defectCorrectFileToData(QString& in_sourceFile);
	virtual int defectCorrectDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column);
	virtual int defectCorrectDataToData(unsigned short* in_sourceData, int in_line, int in_column);

	virtual int binProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_binWidth, int in_binHeight);
	virtual int binProcessFileToData(QString& in_sourceFile, int in_binWidth, int in_binHeight);
	virtual int binProcessDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line, int in_column
		, int in_binWidth, int in_binHeight);
	virtual int binProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column
		, int in_binWidth, int in_binHeight);

	virtual int rotateProcessFileToFile(QString& in_sourceFile, QString& in_destFile, int in_iRotationType, int iRotationAngle);
	virtual int rotateProcessFileToData(QString& in_sourceFile, int in_iRotationType, int iRotationAngle);
	virtual int rotateProcessDataToFile(unsigned short* in_sourceData, QString& in_destFile, int in_line,
		int in_column, int in_iRotationType, int iRotationAngle);
	virtual int rotateProcessDataToData(unsigned short* in_sourceData, int in_line, int in_column,
		int in_iRotationType, int iRotationAngle);

	virtual int mergeProcessFileToFile(QString& in_sourceFile, QString& in_destFile);
	virtual int mergeProcessFileToData(QString& in_sourceFile);
	virtual int mergeProcessDataToFile(unsigned short** in_sourceData, QString& in_destFile, int in_frames, int in_line, int in_column);
	virtual int mergeProcessDataToData(unsigned short** in_sourceData, int in_frames, int in_line, int in_column);

	virtual bool saveMultiBitmapDataToFile(unsigned short** in_sourceData, int in_frames, int in_line, int in_column);
	virtual bool saveSingleBitmapDataToFile(unsigned short* in_sourceData, int in_line, int in_column);
	virtual int dataSplice(QString& in_pathA, QString& in_pathB, QString& in_pathFinal, int& progress);
	virtual bool loadBkgData(QString& d_bkgFileName);
	virtual bool loadAirData(QString& d_bkgFileName);
};

