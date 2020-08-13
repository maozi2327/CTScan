#include "stdafx.h"
#include "LineDetNetWork.h"
#include "../Public/util/TcpServer.h"
#include <chrono>
#include <algorithm>
LineDetNetWork::LineDetNetWork(unsigned short in_port)
	: d_server
	(
		nullptr
		//new TcpServer(4, 4, 0
		//, [] {; }
		//, [this](char* in_char, int in_size) { DecodePackages(in_char, in_size); }
		//, QHostAddress::Any, 4000)
	)
{
	//connect(d_server.get(), SIGNAL(netWorkStatusSignal(bool)), this, SLOT(netWorkStatusSlot));
}


LineDetNetWork::~LineDetNetWork()
{

}

void LineDetNetWork::netWorkStatusSlot(bool sts)
{
	emit netWorkStatusSignal(sts);
}

bool LineDetNetWork::getConnected()
{
	return d_server->getConnected();
}

bool LineDetNetWork::recvServer_DATA()
{
	return 0;
}

bool LineDetNetWork::NetCheck()
{
	return 0;
}

bool LineDetNetWork::NetSetup()
{
	return 0;
}

template<typename T1, typename T2>
inline bool GetResult(T1& t1, T2 t2, std::condition_variable& in_con, std::mutex& in_mutex)
{
	t1 = 0;
	std::unique_lock<std::mutex> lk(in_mutex);

	if (in_con.wait_for(lk, std::chrono::milliseconds(1000), [&] { return t1 == t2; }))
		return true;
	else
		return false;
}

bool LineDetNetWork::ARMTest()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_ARM_TEST;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = 0xffff;
	cmdInfo.respond_type = 1;
	d_recvType = CMD;

	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_cmdType, CMD_ARM_TEST, d_con, d_mutex);

	return false;
	
}

bool LineDetNetWork::ChannelSelect()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_CHANNEL_SELECT;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = d_smallBoardNum;
	cmdInfo.respond_type = 0;
	
	if (d_server->sendSyn((char*)(&cmdInfo), sizeof(cmdInfo)) == sizeof(cmdInfo))
		return true;

	return false;
}

bool LineDetNetWork::ChannelDepthSet()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_CHANNEL_DEPTH_SET;
	cmdInfo.cmd_len = 16;

	//实际FIFO的深度，也是单采样脉冲下ARM读FIFO的次数(16位总线位宽、67个整型数据，将进行134次读操作)
	//此处channel_depth+3是数据中包含分度号、脉冲序号和校验和3个数据
	cmdInfo.cmd_param = (d_smallBoardChannel + 3) * 2;
	cmdInfo.respond_type = 0;
	
	if (d_server->sendSyn((char*)(&cmdInfo), sizeof(cmdInfo)) == sizeof(cmdInfo))
		return true;

	return false;
}

bool LineDetNetWork::StartCI()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_START_CI;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = 0;
	cmdInfo.respond_type = 0;

	if (d_server->sendSyn((char*)(&cmdInfo), sizeof(cmdInfo)) == sizeof(cmdInfo))
		return true;

	return false;
}

bool LineDetNetWork::FPGATest()
{
	return 0;
}

bool LineDetNetWork::DetectorTest()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_DETECTOR_TEST;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = d_smallBoardChannel;
	cmdInfo.respond_type = 1;
	
	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_return64, 64, d_con, d_mutex);

	return false;
}

bool LineDetNetWork::SetAmpSize(int in_ampSize)
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_SET_AMP_SIZE;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = in_ampSize;
	cmdInfo.respond_type = 1;
	d_recvType = PARAMETER;

	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_returnSize, d_dataSizePerPulse, d_con, d_mutex);

	return false;
}

bool LineDetNetWork::SetIntTime(int in_intTime)
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_SET_INT_TIME;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = in_intTime;
	cmdInfo.respond_type = 1;
	d_recvType = PARAMETER;

	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_returnSize, d_dataSizePerPulse, d_con, d_mutex);

	return false;
}

bool LineDetNetWork::SetDelayTime(int in_delayTime)
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_SET_DELAY_TIME;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = in_delayTime;
	cmdInfo.respond_type = 1;
	d_recvType = PARAMETER;

	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_returnSize, d_dataSizePerPulse, d_con, d_mutex);

	return false;
}

bool LineDetNetWork::ReadAmpSize()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_READ_AMP_SIZE;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = 0x0;
	cmdInfo.respond_type = 1;
	d_recvType = PARAMETER;

	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_returnSize, d_dataSizePerPulse, d_con, d_mutex);

	return false;
}

bool LineDetNetWork::ReadIntTime()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_READ_INT_TIME;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = 0x0;
	cmdInfo.respond_type = 1;
	d_recvType = PARAMETER;
	
	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_returnSize, d_dataSizePerPulse, d_con, d_mutex);

	return false;
}

bool LineDetNetWork::ReadDelayTime()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_READ_DELAY_TIME;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = 0x0;
	cmdInfo.respond_type = 1;
	d_recvType = PARAMETER;
	
	if(d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT)))
		return GetResult(d_returnSize, d_dataSizePerPulse, d_con, d_mutex);

	return false;
}

bool LineDetNetWork::startExtTrigAcquire()
{
	clearRowList();

	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_INTERNAL_COLLECT;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = 1;
	cmdInfo.respond_type = 0;

	if (d_server->sendSyn((char*)(&cmdInfo), sizeof(cmdInfo)) == sizeof(cmdInfo))
		return true;

	return false;
}

void LineDetNetWork::DecodePackages(char * in_buff, int in_size)
{
	CMD_STRUCT cmdFeedback;
	switch (d_recvType)
	{
	case CMD:
		if(in_size == sizeof(CMD_STRUCT))
		{
			std::lock_guard<std::mutex> lk(d_mutex);
			d_cmdType = ((CMD_STRUCT*)in_buff)->cmd;
			d_con.notify_one();
		}
		break;
	case PARAMETER:
		d_returnSize = CollectUsefulData(in_buff, in_size);
		break;
	case DATA:
		CollectUsefulData(in_buff, in_size);
		break;
	}
}

int LineDetNetWork::getGraduationCount()
{
	return 0;
}

int LineDetNetWork::CollectUsefulData(char * in_buff, int in_size)
{
	int pulseNum = in_size / d_dataSizePerPulse;
	int smallBS = d_smallBoardChannel * sizeof(unsigned int);

	for (int pulseIndex = 0; pulseIndex != pulseNum; ++pulseIndex)
	{
		//总通道数+分度计数+脉冲计数
		unsigned long* item = new unsigned long[d_channelNum + 2];
		int smIndex = 0;

		
		for (int smIndex = 0; smIndex != d_smallBoardNum; ++smIndex)
		{
			memmove(in_buff + 2 * sizeof(unsigned int) + smIndex * smallBS
				, in_buff + 2 * sizeof(unsigned int) + pulseIndex * d_dataSizePerPulse + smIndex * smallBS
				, smallBS);
		}

		unsigned long* dataHead = item + 2;
		int nonBlockDataIndex = 0;
		memcpy(item, in_buff, 2 * sizeof(unsigned int));

		for(auto& moduleIndex : d_nonBlockModuleMap )
		{
			memcpy(dataHead + nonBlockDataIndex * smallBS, in_buff + moduleIndex * smallBS, smallBS);
			++nonBlockDataIndex;
		}

		d_dataList.push_back(item);
	}

	delete[] in_buff;
	return in_size;
}

LineDetList * LineDetNetWork::getRowList()
{
	return d_dataList.getList();
}

void LineDetNetWork::clearRowList()
{
	d_dataList.clear();
}
