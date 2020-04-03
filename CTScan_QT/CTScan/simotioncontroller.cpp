#include "stdafx.h"
#include "simotioncontroller.h"
#include "../Public/headers/CtrlData.h"
#include <memory>
#include <thread>
#include <algorithm>
#include <functional>

const unsigned short SimotionController::d_port = 8000;
const int SimotionController::d_packetSize = 256;
SimotionController::SimotionController()
{
	std::function<void(char*, int)> decodeFun = std::bind(&SimotionController::decodePackages, this
		, std::placeholders::_1, std::placeholders::_2);

	d_server.reset(new TcpServer(sizeof(tagCOMM_PACKET1), 2, 4, decodeFun, QHostAddress::Any, d_port));
}


SimotionController::~SimotionController()
{
	d_threadRun = false;
}

template<typename T1, typename T2>
inline bool GetResult(T1& t1, T2 t2)
{
	t1 = 0;
	std::unique_lock<std::mutex> lk(d_mutex);

	if (d_con.wait_for(lk, std::chrono::milliseconds(1000), [&] { return t1 == t2; }))
		return true;
		
	return false;
}

float SimotionController::readAxisPostion(Axis in_axis)
{
	return d_axisPosition[in_axis];
}

std::map<Axis, float> SimotionController::readAxisPostion()
{
	return d_axisPosition;
}

std::map<Axis, float> SimotionController::readAxisWorkZero()
{
	if (GetResult(d_receivedCmd, STS_WORKZERO))
		return d_axisSpeed;

	return std::map<Axis, float>();
}

bool SimotionController::readReadyStatus()
{
	return d_ready;
}

bool SimotionController::readSaveStatus()
{
	return d_save;
}

bool SimotionController::readWaitNextScanStatus()
{
	return d_waitNextScan;
}

bool SimotionController::readRunStatus()
{
	return true;
}

std::map<Axis, float> SimotionController::readAxisSpeed()
{
	if (GetResult(d_receivedCmd, STS_AXIS_SPEED))
		return d_axisSpeed;

	return std::map<Axis, float>();
}

bool SimotionController::initialConnection()
{
	std::thread	( 
		[this]()
		{
			sendCmd();	
		}
	).detach();
}

void SimotionController::getAixsValueAndNotify(std::map<Axis, float>& in_value, char * in_data, int in_axisNum, int in_typeCode)
{
	for (int i = 0; i != in_axisNum; ++i)
		in_value.insert({ Axis(*(in_data + i * 5)), *(float*)((in_data + i * 5 + 1)) });

	{
		std::lock_guard<std::mutex> lock(d_mutex);
		d_receivedCmd = in_typeCode;
		d_con.notify_all();
	}
}

bool SimotionController::sendCmd()
{
	while (d_threadRun)
	{
		std::weak_ptr<SimotionController> thisWeak = shared_from_this();
		std::shared_ptr<SimotionController> shared = thisWeak.lock();

		if (shared)
			while (d_threadRun)
			{
				for (auto& cmd : d_cmdList)
					d_server->sendAsyn(cmd.d_data, cmd.d_size);
			}
	}
}

//55  AA  5A    TP          BL           DW             VS
//  包头(3B)  分类码(1B) 包长(1W)    n字节参数字      校验和(1B)

void SimotionController::decodePackages(char* in_package, int in_size)
{
	char typeCode = ((tagCOMM_PACKET1*)in_package)->typeCode;
	int dataSize = ((tagCOMM_PACKET1*)in_package)->tagLen;

	switch (typeCode) 
	{
	case	STS_SYSTEM_STATUS:
		d_sysStatus = *(SysStatus*)((in_package + sizeof(tagCOMM_PACKET1)));
		break;
	case	STS_CONTROL_SYSTEM:
		d_ctrlSysSts = *(ControlSystemStatus*)((in_package + sizeof(tagCOMM_PACKET1)));
		break;
	case	STS_GRADUATION_BASE:
		break;
	case	STS_WORKZERO:
		int axisNum = dataSize / 5;
		getAixsValueAndNotify(d_axisWorkZero, in_package + sizeof(tagCOMM_PACKET1), axisNum, typeCode);
		break;
	//(轴代号|轴坐标)|(轴代号|轴坐标)|(轴代号|轴坐标)|......(轴代号|轴坐标)|
 	// 1字节 | 4字节 |1字节 | 4字节
	case	STS_ALL_COORDINATION:
		int axisNum = dataSize / 5;
		getAixsValueAndNotify(d_axisPosition, in_package + sizeof(tagCOMM_PACKET1), axisNum, typeCode);
		break;
	case	STS_AXIS_SPEED:
		int axisNum = dataSize / 5;
		getAixsValueAndNotify(d_axisSpeed, in_package + sizeof(tagCOMM_PACKET1), axisNum, typeCode);
		break;
	case	STS_DIAGNICS_RESULT:
		break;
	case	STS_IO_REGISTER:
		break;
	case	STS_FAULT_CODE:
		break;
	case	STS_LASERMEAS_VALUE:
		break;
	default:
		break;
	}
}

void SimotionController::getSystemStatus()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_POLL_STATUS) != d_cmdList.end())
		return;

	CommandType d_cmdData(sizeof(tagCOMM_PACKET));
	tagCOMM_PACKET d_cmd;
	tagCOMM_PACKET* ptr = (tagCOMM_PACKET*)(d_cmdData.d_data);
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_POLL_STATUS;
	ptr->data[0] = STS_SYSTEM_STATUS;
	ptr->tagLen = 3 + 2 * sizeof(BYTE);
	d_cmdList.push_back(d_cmdData);
}

void SimotionController::getAxisPosition()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_POLL_STATUS) != d_cmdList.end())
		return;

	CommandType d_cmdData(sizeof(tagCOMM_PACKET));
	tagCOMM_PACKET d_cmd;
	tagCOMM_PACKET* ptr = (tagCOMM_PACKET*)(d_cmdData.d_data);
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_POLL_STATUS;
	ptr->data[0] = STS_ALL_COORDINATION;
	ptr->tagLen = 3 + 2;
	d_cmdList.push_back(d_cmdData);
	return;
}

void SimotionController::getAxisSpeed()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_UPLOAD_AXIS_SPEED) != d_cmdList.end())
		return;

	CommandType d_cmdData(sizeof(tagCOMM_PACKET));
	tagCOMM_PACKET d_cmd;
	tagCOMM_PACKET* ptr = (tagCOMM_PACKET*)(d_cmdData.d_data);
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_UPLOAD_AXIS_SPEED;
	ptr->tagLen = 3 + 0;
	d_cmdList.push_back(d_cmdData);
}

void SimotionController::getAxisWorkZero()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_UPLOAD_WORKZERO) != d_cmdList.end())
		return;

	CommandType d_cmdData(sizeof(tagCOMM_PACKET));
	tagCOMM_PACKET d_cmd;
	tagCOMM_PACKET* ptr = (tagCOMM_PACKET*)(d_cmdData.d_data);
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_UPLOAD_WORKZERO;
	ptr->tagLen = 3 + 0;
	d_cmdList.push_back(d_cmdData);
}

void SimotionController::setAxisSpeed(std::map<Axis, float>& in_speed)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_DOWNLOAD_AXIS_SPEED) != d_cmdList.end())
		return;
	
	int dataSize = in_speed.size() * 5;
	CommandType d_cmdData(sizeof(tagCOMM_PACKET) + dataSize);
	tagCOMM_PACKET d_cmd;
	tagCOMM_PACKET* ptr = (tagCOMM_PACKET*)(d_cmdData.d_data);
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_DOWNLOAD_AXIS_SPEED;
	ptr->tagLen = 3 + dataSize;	
	int i = 0;

	for (auto& pair : in_speed)
	{
		ptr->data[i * 5] = char(pair.first);
		memcpy(ptr->data + i * 5 + 1, &pair.second, sizeof(float));
	}

	d_cmdList.push_back(d_cmdData);
}

void SimotionController::setAxisWorkZero(std::map<Axis, float>& in_workZero)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_DOWNLOAD_WORKZERO) != d_cmdList.end())
		return;

	int dataSize = in_workZero.size() * 5;
	CommandType d_cmdData(sizeof(tagCOMM_PACKET) + dataSize);
	tagCOMM_PACKET d_cmd;
	tagCOMM_PACKET* ptr = (tagCOMM_PACKET*)(d_cmdData.d_data);
	ptr->tagHead[0] = 0x55;
	ptr->tagHead[1] = 0xaa;
	ptr->tagHead[2] = 0x5a;
	ptr->typeCode = CMD_DOWNLOAD_AXIS_SPEED;
	ptr->tagLen = 3 + dataSize;
	int i = 0;

	for (auto& pair : in_workZero)
	{
		ptr->data[i * 5] = char(pair.first);
		memcpy(ptr->data + i * 5 + 1, &pair.second, sizeof(float));
	}

	d_cmdList.push_back(d_cmdData);
}
