#pragma once
#include "../Public/lib/CtDispose.h"

class LineDetImageProcess
{
public:
	LineDetImageProcess();
	~LineDetImageProcess();

	int saveOrgFile(QString& in_destFile, void *pHeader, void *pListItem, int iPw);
	int createAirDat(QString& in_sourceFile, QString& in_installDirectory);
	int createBkgDat(QString& in_sourceFile, QString& in_installDirectory);
	int dispose(QString& in_installFolder, QString& in_sourceFile, QString& in_destFile);
};

