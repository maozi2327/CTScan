#include "stdafx.h"
#include "setupdataparser.h"
#include <regex>

bool SetupDataParser::parseLineDetSection(tinyxml2::XMLElement * in_element)
{
	auto element = in_element->FirstChildElement()->NextSiblingElement();
	d_setupData->lineDetNum = static_cast<unsigned short>(stoi(std::string(in_element->FirstChildElement()->GetText())));
	int i = 0;

	for (auto element1 = element; i != d_setupData->lineDetNum && element1 != nullptr;
		element1 = element1->NextSiblingElement(), ++i)
	{
		if (!parseLineDetData(element1, i))
			return false;
	}

	return true;
}

bool SetupDataParser::parseLineDetData(tinyxml2::XMLElement * in_element, int i)
{
	LineDetData localLineDetData;

	for (auto element = in_element->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
	{
		if (strcmp(element->Value(), "ID") == 0)
			localLineDetData.ID = atoi(element->GetText());
		else if (strcmp(element->Value(), "LineDetType") == 0)
		{
			if (strcmp(element->GetText(), "Arch") == 0)
				localLineDetData.LineDetType = 0;
			else if (strcmp(element->GetText(), "Line") == 0)
				localLineDetData.LineDetType = 1;
		}
		else if (strcmp(element->Value(), "NumberOfCalibrateHorizontalDetector") == 0)
			localLineDetData.NumberOfCalibrateHorizontalDetector = atoi(element->GetText());
		else if (strcmp(element->Value(), "BeginSerialNoOfCt2Detector") == 0)
			localLineDetData.BeginSerialNoOfCt2Detector = atoi(element->GetText());
		else if (strcmp(element->Value(), "EndSerialNoOfCt2Detector") == 0)
			localLineDetData.EndSerialNoOfCt2Detector = atoi(element->GetText());
		else if (strcmp(element->Value(), "AmplifyMultiple") == 0)
			localLineDetData.EndSerialNoOfCt2Detector = atoi(element->GetText());
		else if (strcmp(element->Value(), "IntegralTime") == 0)
			localLineDetData.IntegralTime = atoi(element->GetText());
		else if (strcmp(element->Value(), "DelayTime") == 0)
			localLineDetData.DelayTime = atoi(element->GetText());
		else if (strcmp(element->Value(), "nFIFOdepth") == 0)
			localLineDetData.nFIFOdepth = atoi(element->GetText());
		else if (strcmp(element->Value(), "nChnnelMask") == 0)
		{
			std::regex pattern("[01]+");
			std::smatch results;
			std::string str(element->GetText());
			std::string binaryStr;

			for (std::sregex_iterator it(str.begin(), str.end(), pattern), end_it; it != end_it; ++it)
				binaryStr += it->str();

			localLineDetData.nChnnelMask = stoi(binaryStr, 0, 2);
		}
		else if (strcmp(element->Value(), "HorizontalSectorAngle") == 0)
			localLineDetData.HorizontalSectorAngle = atoi(element->GetText());
		else if (strcmp(element->Value(), "HorizontalDetectorAngle") == 0)
			localLineDetData.HorizontalDetectorAngle = atoi(element->GetText());
		else if (strcmp(element->Value(), "IpAddress") == 0)
			strcpy(localLineDetData.szAcquireClientIP, element->GetText());
		else if (strcmp(element->Value(), "nBlockMapTable") == 0)
		{
			std::regex pattern("\\d+");
			std::smatch results;
			std::string str(element->GetText());

			for (auto& arr : localLineDetData.nBlockMapTable)
				arr = -1;
			
			int index = 0;

			for (std::sregex_iterator it(str.begin(), str.end(), pattern), end_it; it != end_it; ++it, ++index)
				localLineDetData.nBlockMapTable[index] = stoi(it->str());
		}
		else if (strcmp(element->Value(), "nAcquireClientPort") == 0)
			localLineDetData.nAcquireClientPort = static_cast<unsigned short>(atoi(element->GetText()));
		else if (strcmp(element->Value(), "SourceDetectorDistance") == 0)
			localLineDetData.SourceDetectorDistance = atof(element->GetText());
	}

	d_setupData->lineDetData.push_back(localLineDetData);
	return true;
}

bool SetupDataParser::parsePanelDetSection(tinyxml2::XMLElement * in_element)
{
	d_setupData->panDetNum = static_cast<unsigned short>(stoi(std::string(in_element->FirstChildElement()->GetText())));
	auto element = in_element->FirstChildElement()->NextSiblingElement();
	int i = 0;

	for (auto element1 = element; i != d_setupData->panDetNum && element1 != nullptr;
		element1 = element1->NextSiblingElement(), ++i)
	{
		if (!parsePanelDetData(element1, i))
			return false;
	}

	return true;
}

bool SetupDataParser::parsePanelDetData(tinyxml2::XMLElement * in_element, int i)
{
	PanDetData localPanDetData;

	for (auto element = in_element->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
	{
		if (strcmp(element->Value(), "ID") == 0)
			localPanDetData.ID = atoi(element->GetText());
		else if (strcmp(element->Value(), "PandetType") == 0)
			strcpy(localPanDetData.PandetType, element->GetText());
		else if (strcmp(element->Value(), "horizontalPixels") == 0)
			localPanDetData.horizontalPixels, atoi(element->GetText());
		else if (strcmp(element->Value(), "verticalPixels") == 0)
			localPanDetData.verticalPixels, atoi(element->GetText());
		else if (strcmp(element->Value(), "pixelBlockLeft") == 0)
			localPanDetData.pixelBlockLeft, atoi(element->GetText());
		else if (strcmp(element->Value(), "pixelBlockRight") == 0)
			localPanDetData.pixelBlockRight, atoi(element->GetText());
		else if (strcmp(element->Value(), "pixelSize") == 0)
			localPanDetData.pixelSize, atof(element->GetText());
		else if (strcmp(element->Value(), "pixelSize") == 0)
			localPanDetData.pixelSize, atof(element->GetText());
		else if (strcmp(element->Value(), "rotAngle") == 0)
			localPanDetData.rotAngle, char(*element->GetText());
		else if (strcmp(element->Value(), "mirror") == 0)
			localPanDetData.mirror, char(*element->GetText());
	}

	d_setupData->panDetData.push_back(localPanDetData);
	return false;
}

bool SetupDataParser::parsekVRaySection(tinyxml2::XMLElement * in_element)
{
	d_setupData->kVRayNum = static_cast<unsigned short>(stoi(std::string(in_element->FirstChildElement()->GetText())));
	auto element = in_element->FirstChildElement()->NextSiblingElement();
	int i = 0;

	for (auto element1 = element; i != d_setupData->kVRayNum && element1 != nullptr;
		element1 = element1->NextSiblingElement(), ++i)
	{
		kVRayData localData;
		
		if (parsekVRayData(element1, i, localData))
			d_setupData->kVRayData.push_back(localData);
		else
			;
	}

	return true;
}

bool SetupDataParser::parsekVRayData(tinyxml2::XMLElement * in_element, int in_number, kVRayData& in_kvRayData)
{
	for (auto element = in_element->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
	{
		if (strcmp(element->Value(), "ID") == 0)
			in_kvRayData.ID= atoi(element->GetText());
		else if (strcmp(element->Value(), "rayType") == 0)
			strcpy(in_kvRayData.rayType, element->GetText());
		else if (strcmp(element->Value(), "rayEnergy") == 0)
			in_kvRayData.rayEnergy = atof(element->GetText());
		else if (strcmp(element->Value(), "rayDoseRate") == 0)
			in_kvRayData.rayDoseRate = atof(element->GetText());
	}

	return true;
}

bool SetupDataParser::parseAcceleratorSection(tinyxml2::XMLElement * in_element)
{
	d_setupData->acceleratorNum = static_cast<unsigned short>(stoi(std::string(in_element->FirstChildElement()->GetText())));
	auto element = in_element->FirstChildElement()->NextSiblingElement();
	int i = 0;

	for (auto element1 = element; i != d_setupData->acceleratorNum && element1 != nullptr;
		element1 = element1->NextSiblingElement(), ++i)
	{
		AcceleratorData localData;

		if (!parseAcceleratorData(element1, i, localData))
			return false;
		else
			;
	}

	return true;
}

bool SetupDataParser::parseAcceleratorData(tinyxml2::XMLElement * in_element, int in_number, AcceleratorData& in_accData)
{
	for (auto element = in_element->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
	{
		if (strcmp(element->Value(), "ID") == 0)
			in_accData.ID = atoi(element->GetText());
		else if (strcmp(element->Value(), "rayType") == 0)
			strcpy(in_accData.rayType, element->GetText());
		else if (strcmp(element->Value(), "rayEnergy") == 0)
			in_accData.rayEnergy = atof(element->GetText());
		else if (strcmp(element->Value(), "rayDoseRate") == 0)
			in_accData.rayDoseRate = atof(element->GetText());
		else if (strcmp(element->Value(), "accRiseTime") == 0)
			in_accData.accRiseTime = atoi(element->GetText());
		else if (strcmp(element->Value(), "syncFreqDefine") == 0)
		{
			std::regex pattern("\\d+");
			std::smatch results;
			std::string str(element->GetText());
			int index = 0;

			for (std::sregex_iterator it(str.begin(), str.end(), pattern), end_it; it != end_it; ++it, ++index)
				in_accData.syncFreqDefine.push_back(stoi(it->str()));
		}
	}

	return true;
}
void insertNumericDataFromString(std::vector<unsigned short>& int_data, tinyxml2::XMLElement * in_element)
{
	std::regex pattern("\\d+");
	std::smatch results;
	std::string str(in_element->GetText());
	int index = 0;

	for (std::sregex_iterator it(str.begin(), str.end(), pattern), end_it; it != end_it; ++it)
		int_data.push_back(stoi(it->str()));
}
bool SetupDataParser::parseScanModeSection(tinyxml2::XMLElement * in_element)
{
	for (auto element = in_element->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
		//{
		//	int rayNum = element->FirstAttribute()->IntValue();
		//	int detNum = element->FirstAttribute()->Next->IntValue();

		//	for (auto element1 = element->FirstChildElement(); element1 != nullptr; element1 = element1->NextSiblingElement())
		//	{
		//		if (strcmp(element1->FirstAttribute()->Name(), "CT2") == 0)
		//		{
		//			rayDetScanmode mode{ std::pair<int, int>(rayNum, detNum), ScanMode::CT2_SCAN };
		//			d_setupData->rayDetCoupleScanmode.insert(mode);

		//			for (auto element11 = element1->FirstChildElement(); element11 != nullptr; element11 = element11->NextSiblingElement())
		//			{
		//				if (strcmp(element1->FirstAttribute()->Name(), "View") == 0)
		//					insertNumericDataFromString(d_setupData->scanview, element1, mode);
		//				else if (strcmp(element1->FirstAttribute()->Name(), "Matrix") == 0)
		//					insertNumericDataFromString(d_setupData->matrix, element1, mode);
		//				else if (strcmp(element1->FirstAttribute()->Name(), "translationModeDefine") == 0)
		//				{

		//				}
		//			}
		//		}
		//		else if (strcmp(element1->FirstAttribute()->Name(), "CT3") == 0)
		//		{
		//			rayDetScanmode mode{ std::pair<int, int>(rayNum, detNum), ScanMode::CT3_SCAN };
		//			d_setupData->rayDetCoupleScanmode.insert(mode);

		//			for (auto element11 = element1->FirstChildElement(); element11 != nullptr; element11 = element11->NextSiblingElement())
		//			{
		//				if (strcmp(element1->FirstAttribute()->Name(), "View") == 0)
		//					insertNumericDataFromString(d_setupData->scanview, element1, mode);
		//				else if (strcmp(element1->FirstAttribute()->Name(), "Matrix") == 0)
		//					insertNumericDataFromString(d_setupData->matrix, element1, mode);
		//				else if (strcmp(element1->FirstAttribute()->Name(), "ct3InterpolationFlag") == 0)
		//				{

		//				}
		//			}

		//		}
		//		else if (strcmp(element1->FirstAttribute()->Name(), "DR") == 0)
		//		{
		//			rayDetScanmode mode{ std::pair<int, int>(rayNum, detNum), ScanMode::DR_SCAN };
		//			d_setupData->rayDetCoupleScanmode.insert(mode);

		//		}
		//		else if (strcmp(element1->FirstAttribute()->Name(), "CONE_SCAN") == 0)
		//		{
		//			rayDetScanmode mode{ std::pair<int, int>(rayNum, detNum), ScanMode::CONE_SCAN };
		//			d_setupData->rayDetCoupleScanmode.insert(mode);
		//		}
		//		else if (strcmp(element1->FirstAttribute()->Name(), "CONE_JOINT_ROT_SCAN") == 0)
		//		{
		//			rayDetScanmode mode{ std::pair<int, int>(rayNum, detNum), ScanMode::CONE_JOINT_ROT_SCAN };
		//			d_setupData->rayDetCoupleScanmode.insert(mode);

		//		}
		//	}
		//}
	{
		if (strcmp(element->Value(), "CT2") == 0)
		{
			parseCT2Data(element);
		}
		else if (strcmp(element->Value(), "CT3") == 0)
		{
			parseCT3Data(element);
		}
		if (strcmp(element->Value(), "DR") == 0)
		{
			parseDRData(element);
		}
		else if (strcmp(element->Value(), "CONE_SCAN") == 0)
		{
			parseConeScanData(element);
		}
		if (strcmp(element->Value(), "CONE_JOINT_ROT_SCAN") == 0)
		{
			parseConeJointRotScanData(element);
		}
	}
	return false;
}

bool SetupDataParser::parseAxisDefinition(tinyxml2::XMLElement * in_element)
{
	for (auto element = in_element->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
	{
		auto itr = AxisNameMap.find(element->Value());

		if(itr != AxisNameMap.end())
			d_setupData->sysAxisDefine.push_back(itr->second);
	}

	return false;
}

bool SetupDataParser::parseCT2Data(tinyxml2::XMLElement * in_element)
{
	d_setupData->ct2DataNum = atoi(in_element->FirstChildElement()->GetText());
	int index = 0;

	for (auto element1 = in_element->FirstChildElement()->NextSiblingElement();
		element1 != nullptr && index != d_setupData->ct2DataNum; element1 = element1->NextSiblingElement())
	{
		CT2Data locaData;

		for (auto element11 = element1->FirstChildElement(); element11 != nullptr; element11 = element11->NextSiblingElement())
		{

			if (strcmp(element11->Value(), "RayId") == 0)
			{
				locaData.Ray = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "LineDetId") == 0)
			{
				locaData.Det = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "View") == 0)
			{
				insertNumericDataFromString(locaData.View, element11);
			}
			else if (strcmp(element11->Value(), "Matrix") == 0)
			{
				insertNumericDataFromString(locaData.Matrix, element11);
			}
			else if (strcmp(element11->Value(), "SampleTime") == 0)
			{
				insertNumericDataFromString(locaData.SampleTime, element11);
			}
			else if (strcmp(element11->Value(), "translationModeDefine") == 0)
			{
				locaData.translationModeDefine = atoi(element11->GetText());
			}
		}

		d_setupData->ct2Data.push_back(locaData);
	}

	return true;
}

bool SetupDataParser::parseCT3Data(tinyxml2::XMLElement * in_element)
{
	d_setupData->ct3DataNum = atoi(in_element->FirstChildElement()->GetText());
	int index = 0;

	for (auto element1 = in_element->FirstChildElement()->NextSiblingElement();
		element1 != nullptr && index != d_setupData->ct2DataNum; element1 = element1->NextSiblingElement())
	{
		CT3Data locaData;

		for (auto element11 = element1->FirstChildElement(); element11 != nullptr; element11 = element11->NextSiblingElement())
		{

			if (strcmp(element11->Value(), "RayId") == 0)
			{
				locaData.Ray = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "LineDetId") == 0)
			{
				locaData.Det = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "View") == 0)
			{
				insertNumericDataFromString(locaData.View, element11);
			}
			else if (strcmp(element11->Value(), "Matrix") == 0)
			{
				insertNumericDataFromString(locaData.Matrix, element11);
			}
			else if (strcmp(element11->Value(), "SampleTime") == 0)
			{
				insertNumericDataFromString(locaData.SampleTime, element11);
			}
			else if (strcmp(element11->Value(), "ct3InterpolationFlag") == 0)
			{
				locaData.ct3InterpolationFlag = atoi(element11->GetText());
			}
		}

		d_setupData->ct3Data.push_back(locaData);
	}

	return true;
}

bool SetupDataParser::parseDRData(tinyxml2::XMLElement * in_element)
{
	d_setupData->drDataNum = atoi(in_element->FirstChildElement()->GetText());
	int index = 0;

	for (auto element1 = in_element->FirstChildElement()->NextSiblingElement();
		element1 != nullptr && index != d_setupData->ct2DataNum; element1 = element1->NextSiblingElement())
	{
		DrScanData locaData;

		for (auto element11 = element1->FirstChildElement(); element11 != nullptr; element11 = element11->NextSiblingElement())
		{

			if (strcmp(element11->Value(), "RayId") == 0)
			{
				locaData.Ray = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "LineDetId") == 0)
			{
				locaData.Det = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "View") == 0)
			{
				insertNumericDataFromString(locaData.View, element11);
			}
			else if (strcmp(element11->Value(), "Matrix") == 0)
			{
				insertNumericDataFromString(locaData.Matrix, element11);
			}
			else if (strcmp(element11->Value(), "SampleTime") == 0)
			{
				insertNumericDataFromString(locaData.SampleTime, element11);
			}
			else if (strcmp(element11->Value(), "drScanModeDefine") == 0)
			{
				locaData.drScanModeDefine = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "drInterpolationFlag") == 0)
			{
				locaData.drInterpolationFlag = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "drScanAngleDefine") == 0)
			{
				locaData.drScanAngleDefine = atoi(element11->GetText());
			}
		}

		d_setupData->drScanData.push_back(locaData);
	}

	return true;
}

bool SetupDataParser::parseConeScanData(tinyxml2::XMLElement * in_element)
{
	d_setupData->ConeScanDataNum = atoi(in_element->FirstChildElement()->GetText());
	int index = 0;

	for (auto element1 = in_element->FirstChildElement()->NextSiblingElement();
		element1 != nullptr && index != d_setupData->ct2DataNum; element1 = element1->NextSiblingElement())
	{
		ConeScanData locaData;

		for (auto element11 = element1->FirstChildElement(); element11 != nullptr; element11 = element11->NextSiblingElement())
		{

			if (strcmp(element11->Value(), "RayId") == 0)
			{
				locaData.Ray = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "PanelDetId") == 0)
			{
				locaData.Det = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "Matrix") == 0)
			{
				insertNumericDataFromString(locaData.Matrix, element11);
			}
		}

		d_setupData->coneScanData.push_back(locaData);
	}

	return true;
}

bool SetupDataParser::parseConeJointRotScanData(tinyxml2::XMLElement * in_element)
{
	d_setupData->ConeJointRotScanDataNum = atoi(in_element->FirstChildElement()->GetText());
	int index = 0;

	for (auto element1 = in_element->FirstChildElement()->NextSiblingElement();
		element1 != nullptr && index != d_setupData->ct2DataNum; element1 = element1->NextSiblingElement())
	{
		ConeJointRotScanData locaData;

		for (auto element11 = element1->FirstChildElement(); element11 != nullptr; element11 = element11->NextSiblingElement())
		{

			if (strcmp(element11->Value(), "RayId") == 0)
			{
				locaData.Ray = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "PanelDetId") == 0)
			{
				locaData.Det = atoi(element11->GetText());
			}
			else if (strcmp(element11->Value(), "Matrix") == 0)
			{
				insertNumericDataFromString(locaData.Matrix, element11);
			}
			else if (strcmp(element11->Value(), "View") == 0)
			{
				insertNumericDataFromString(locaData.View, element11);
			}
		}

		d_setupData->coneJointRotScanData.push_back(locaData);
	}

	return true;
}

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

	for (auto element = rootElement->FirstChildElement(); element != nullptr;
		element = element->NextSiblingElement())
	{
		if (strcmp(element->Value(), "szDeviceModel") == 0)
		{
			strcpy(d_setupData->szDeviceModel, element->GetText());
			continue;
		}
		else if (strcmp(element->Value(), "LineDetSection") == 0)
		{
			parseLineDetSection(element);
			continue;
		}
		else if (strcmp(element->Value(), "PanDetSection") == 0)
		{
			parsePanelDetSection(element);
			continue;
		}
		else if (strcmp(element->Value(), "kVRaySection") == 0)
		{
			parsekVRaySection(element);
			continue;
		}
		else if (strcmp(element->Value(), "AcceleratorSection") == 0)
		{
			parseAcceleratorSection(element);
			continue;
		}
		else if (strcmp(element->Value(), "ScanModeSection") == 0)
		{
			parseScanModeSection(element);
			continue;
		}
		else if (strcmp(element->Value(), "AxisDefinition") == 0)
		{
			parseAxisDefinition(element);
			continue;
		}
	}
	
	return false;
}

bool SetupDataParser::saveSetupData()
{
	return false;
}
