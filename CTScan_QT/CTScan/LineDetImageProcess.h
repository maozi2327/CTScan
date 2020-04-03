#pragma once
#include "../Public/lib/CtDispose.h"

class LineDetImageProcess
{
public:
	LineDetImageProcess();
	~LineDetImageProcess();

	int saveOrgFile(char *pcDesFile, void *pHeader,	void *pListItem, int iPw);
	int createAirDat(QString& in_sourceFile, QString& in_destFile);
	int createBkgDat(QString& in_sourceFile, QString& in_destFile);
	int dispose(QString& in_installFolder, QString& in_sourceFile, QString& in_destFile);
};

