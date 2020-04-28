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
	bool parseLineDetSection(tinyxml2::XMLElement* in_element);
	bool parseLineDetData(tinyxml2::XMLElement* in_element, int in_number);
	bool parsePanelDetSection(tinyxml2::XMLElement* in_element);
	bool parsePanelDetData(tinyxml2::XMLElement* in_element, int in_number);
	bool parsekVRaySection(tinyxml2::XMLElement* in_element);
	bool parsekVRayData(tinyxml2::XMLElement* in_element, int in_number);
	bool parseAcceleratorSection(tinyxml2::XMLElement* in_element);
	bool parseAcceleratorData(tinyxml2::XMLElement* in_element, int in_number);
	bool parseScanModeSection(tinyxml2::XMLElement* in_element);
	bool parseAxisDefinition(tinyxml2::XMLElement* in_element);
public:
	SetupDataParser(SetupData* in_setupData, QObject *parent = Q_NULLPTR);
	~SetupDataParser();
	bool parseSetupXMLFile();
	bool saveSetupData();
};
