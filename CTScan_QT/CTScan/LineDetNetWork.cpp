#include "stdafx.h"
#include "LineDetNetWork.h"
#include "../Public/util/TcpServer.h"
#include <chrono>
LineDetNetWork::LineDetNetWork() 
	: d_server(std::make_unique<TcpServer>(sizeof(4, 4, 0, QHostAddress::Any, 4000)))
{

}


LineDetNetWork::~LineDetNetWork()
{
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

bool LineDetNetWork::ARMTest()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_ARM_TEST;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = 0xffff;
	cmdInfo.respond_type = 1;
	d_recvType = CMD;
	d_server->sendAsyn((char*)&cmdInfo, sizeof(CMD_STRUCT));
	std::unique_lock<std::mutex> lk(d_mutex);

	if (d_con.wait_for(lk, std::chrono::milliseconds(1000), [&] { return d_cmdType == CMD_ARM_TEST; }))
		return true;
	else
		return false;
}

bool LineDetNetWork::ChannelSelect()
{
	CMD_STRUCT cmdInfo;
	cmdInfo.cmd = CMD_CHANNEL_SELECT;
	cmdInfo.cmd_len = 16;
	cmdInfo.cmd_param = d_channelMask;
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
	cmdInfo.cmd_param = (d_channelDepth + 3) * 2;
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

	return 0;
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
	cmdInfo.cmd_param = d_channelDepth;
	cmdInfo.respond_type = 1;

	std::unique_lock<std::mutex> lk(d_mutex);

	if (d_con.wait_for(lk, std::chrono::milliseconds(1000), [&] { return d_return64 == 64; }))
		return true;
	else
		return false;
}

bool LineDetNetWork::SetAmpSize()
{
	return 0;
}

bool LineDetNetWork::SetIntTime()
{
	return 0;
}

bool LineDetNetWork::SetDelayTime()
{
	return 0;
}

bool LineDetNetWork::ReadAmpSize()
{
	return 0;
}

bool LineDetNetWork::ReadIntTime()
{
	return 0;
}

bool LineDetNetWork::ReadDelayTime()
{
	return 0;
}

void LineDetNetWork::DecodePackages(char * in_buff, int in_size)
{
	CMD_STRUCT cmdFeedback;
	switch (d_recvType)
	{
	case CMD:
		if(in_size == sizeof(CMD_STRUCT))
		{
			{				
				std::lock_guard<std::mutex> lk(d_mutex);
				d_cmdType = ((CMD_STRUCT*)in_buff)->cmd;
				d_con.notify_one();
			}
		}
		break;
	case PARAMETER:
		;
		break;
	case DATA:
		;
		break;
	}
}
