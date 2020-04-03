#include "stdafx.h"
#include "LineDetImageProcess.h"


LineDetImageProcess::LineDetImageProcess()
{

}


LineDetImageProcess::~LineDetImageProcess()
{

}

int LineDetImageProcess::saveOrgFile(char * pcDesFile, void * pHeader, void * pListItem, int iPw)
{
	return saveOrgHeaderAndList(pcDesFile, pHeader, pListItem, iPw);
}

int LineDetImageProcess::createAirDat(QString & in_sourceFile, QString & in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return fCreateAirRatio(sourceFileName.data(), destFileName.data());
}

int LineDetImageProcess::createBkgDat(QString & in_sourceFile, QString & in_destFile)
{
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	return fCreateBkgData(sourceFileName.data(), destFileName.data());
}

int LineDetImageProcess::dispose(QString& in_installFolder, QString& in_sourceFile, QString& in_destFile)
{
	QByteArray installFolder = in_installFolder.toLocal8Bit();
	QByteArray sourceFileName = in_sourceFile.toLocal8Bit();
	QByteArray destFileName = in_destFile.toLocal8Bit();
	unsigned short setupWord = EN_BKGTUNE | EN_AIRTUNE | EN_SENSITIVE | EN_RANGE | EN_CROSSTALK 
		| EN_PULSEDOSE | EN_HARDEN | EN_ABNORMALDETECTOR;

	return fDataDispose(installFolder.data(), sourceFileName.data(), destFileName.data(), setupWord);
}

