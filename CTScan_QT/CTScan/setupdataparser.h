#pragma once

#include <QObject>
#include "../Public/lib/tinyxml2.h"
struct SetupData;
class SetupDataParser : public QObject
{
	Q_OBJECT

private:
	QString d_setupXMLName;
	QString d_setupDatName;
	std::unique_ptr<tinyxml2::XMLDocument> d_XMLDoc;
	SetupData* d_setupData;
public:
	SetupDataParser(SetupData* in_setupData, QObject *parent = Q_NULLPTR);
	~SetupDataParser();
	bool parseSetupXMLFile();
	bool saveSetupData();
};
