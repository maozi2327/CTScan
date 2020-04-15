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
	d_ready = d_sysStatus.s.ready;
	return d_ready;
}

bool SimotionController::readSaveStatus()
{
	d_save = d_sysStatus.s.save;
	return d_save;
}

bool SimotionController::readWaitNextScanStatus()
{
	d_waitNextScan = d_sysStatus.s.waitNextScan;
	return d_waitNextScan;
}

bool SimotionController::readRunStatus()
{
	d_run = !d_sysStatus.s.idle;
	return d_run;
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

bool SimotionController::stopAll()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_STOP) != d_cmdList.end())
		return false;

	fillInCmdStructAndFillCmdList(CMD_STOP, nullptr, 0);
	return false;
}

bool SimotionController::initialiseController()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_SEEK_ABS_ZERO) != d_cmdList.end())
		return false;

	fillInCmdStructAndFillCmdList(CMD_SEEK_ABS_ZERO, nullptr, 0);
	return false;
}

#define FILLX55XAAX5A;	ptr->tagHead[0] = 0x55;\
						ptr->tagHead[1] = 0xaa;\
						ptr->tagHead[2] = 0x5a;

bool SimotionController::axisSeekZero(Axis in_axis)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_SEEK_AXIS_ABS_ZERO) != d_cmdList.end())
		return false;

	char data[1];
	data[0] = char(in_axis);
	fillInCmdStructAndFillCmdList(CMD_SEEK_AXIS_ABS_ZERO, data, 1);
	return true;
}

bool SimotionController::axisAbsMove(Axis in_axis, float in_pos)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_AXIS_ABS_MOVE) != d_cmdList.end())
		return false;

	char data[5];
	data[0] = char(in_axis);
	memcpy(data + 1, &in_pos, sizeof(float));
	fillInCmdStructAndFillCmdList(CMD_AXIS_ABS_MOVE, data, 5);
	return true;
}

bool SimotionController::axisRealMove(Axis in_axis, float in_pos)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_SEEK_AXIS_ABS_ZERO) != d_cmdList.end())
		return false;

	char data[5];
	data[0] = char(in_axis);
	memcpy(data + 1, &in_pos, sizeof(float));
	fillInCmdStructAndFillCmdList(CMD_AXIS_REL_MOVE, data, 5);
}

bool SimotionController::sliceMove(float in_pos)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_SLICE_ABS_MOVE) != d_cmdList.end())
		return false;

	char data[4];
	memcpy(data, &in_pos, sizeof(float));
	fillInCmdStructAndFillCmdList(CMD_SLICE_ABS_MOVE, data, 4);
	return true;
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

void SimotionController::fillInCmdStructAndFillCmdList(int in_cmd, char * in_data, int in_size)
{
	CommandType d_cmdData(sizeof(tagCOMM_PACKET));
	tagCOMM_PACKET* ptr = (tagCOMM_PACKET*)(d_cmdData.d_data);
	FILLX55XAAX5A;
	ptr->typeCode = CMD_AXIS_REL_MOVE;
	memcpy(&ptr->data[0], &in_data, in_size);
	ptr->tagLen = 3 + in_size;
	d_cmdList.push_back(d_cmdData);
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

void SimotionController::sendToControl(char * in_package, int in_size)
{
	CommandType cmd(in_package, in_size);
	d_cmdList.push_back(cmd);
}

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

	char data[1];
	data[0] = char(STS_SYSTEM_STATUS);
	fillInCmdStructAndFillCmdList(CMD_POLL_STATUS, data, 1);
}

void SimotionController::getAxisPosition()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_POLL_STATUS) != d_cmdList.end())
		return;

	char data[1];
	data[0] = char(STS_ALL_COORDINATION);
	fillInCmdStructAndFillCmdList(CMD_POLL_STATUS, data, 1);
	return;
}

void SimotionController::getAxisSpeed()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_UPLOAD_AXIS_SPEED) != d_cmdList.end())
		return;

	fillInCmdStructAndFillCmdList(CMD_UPLOAD_AXIS_SPEED, nullptr, 0);
}

void SimotionController::getAxisWorkZero()
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_UPLOAD_WORKZERO) != d_cmdList.end())
		return;

	fillInCmdStructAndFillCmdList(CMD_UPLOAD_WORKZERO, nullptr, 0);
}

void SimotionController::setAxisSpeed(std::map<Axis, float>& in_speed)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_DOWNLOAD_AXIS_SPEED) != d_cmdList.end())
		return;

	int size = in_speed.size() * 5;
	char* data = new char[size];
	int i = 0;

	for (auto& pair : in_speed)
	{
		data[i * 5] = char(pair.first);
		memcpy(data + i * 5 + 1, &pair.second, sizeof(float));
		++i;
	}
	
	fillInCmdStructAndFillCmdList(CMD_DOWNLOAD_AXIS_SPEED, data, size);
	delete[] data;
}

void SimotionController::setAxisWorkZero(std::map<Axis, float>& in_workZero)
{
	if (std::find(d_cmdList.begin(), d_cmdList.end(), CMD_DOWNLOAD_WORKZERO) != d_cmdList.end())
		return;

	int size = in_workZero.size() * 5;
	char* data = new char[size];
	int i = 0;

	for (auto& pair : in_workZero)
	{
		data[i * 5] = char(pair.first);
		memcpy(data + i * 5 + 1, &pair.second, sizeof(float));
		++i;
	}

	fillInCmdStructAndFillCmdList(CMD_DOWNLOAD_AXIS_SPEED, data, size);
	delete[] data;
}
