#include "stdafx.h"
#include "setupdataparser.h"
#include "../Public/headers/SetupData.h"
#include <regex>

SetupDataParser::SetupDataParser(SetupData* in_setupData, QObject *parent)
	: QObject(parent), d_setupData(in_setupData), d_setupXMLName("./CTScan.xml"), d_XMLDoc(new tinyxml2::XMLDocument())
{
	parseSetupXMLFile();
}

SetupDataParser::~SetupDataParser()
{
}

bool SetupDataParser::parseSetupXMLFile()
{
	QByteArray byteArray = d_setupXMLName.toLocal8Bit();

	if(d_XMLDoc->LoadFile(byteArray.data()) != tinyxml2::XMLError::XML_SUCCESS)
		return false;

	tinyxml2::XMLElement* rootElement = d_XMLDoc->FirstChildElement();

	for (tinyxml2::XMLElement* element = rootElement->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
	{
		if (strcmp(element->Value(), "szDeviceModel") == 0)
		{
			strcpy(d_setupData->szDeviceModel, element->GetText());
			continue;
		}
		else if (strcmp(element->Value(), "LineDetData") == 0)
		{
			if (strcmp(element->Value(), "LineDetData") == 0)
			{
				std::regex reg("(\\d{4})");
			}
				;

			continue;
		}
		else if (strcmp(element->Value(), "PanDetSection") == 0)
		{
			continue;
		}
		else if (strcmp(element->Value(), "kVRaySection") == 0)
		{
			continue;
		}
		else if (strcmp(element->Value(), "AcceleratorSection") == 0)
		{
			continue;
		}
		else if (strcmp(element->Value(), "ScanModeSection") == 0)
		{
			continue;
		}
		else if (strcmp(element->Value(), "AxisDefinition") == 0)
		{
			continue;
		}
	}
	
	return false;
}

bool SetupDataParser::saveSetupData()
{
	return false;
}
