#pragma once
#include "controllerinterface.h"
#include "../Public/util/tcpserver.h"
#include <list>
#include <memory>
#include <condition_variable>
#include <mutex>
#include "../Public/headers/ctrldata.h"
#include "../Public/headers/list.h"
struct CommandType
{
	int d_cmd;
	char* d_data;
	int d_size;
	CommandType(int in_size)
	{
		d_data = new char[in_size];
		d_size = in_size;
	}

	void operator=(const CommandType& in_command)
	{
		char* temp = nullptr;
		
		if (in_command.d_size != 0)
		{
			temp = new char[in_command.d_size];
			memcpy(temp, in_command.d_data, in_command.d_size);
		}

		if (d_data != nullptr)
			delete[] d_data;

		d_data = temp;
		d_size = in_command.d_size;
		d_cmd = in_command.d_cmd;
	}

	CommandType(const char* in_data, int in_size)
	{
		d_data = new char[in_size];
		d_size = in_size;
		memcpy(d_data, in_data, in_size);
	}
	CommandType(const CommandType& in_commandType)
	{
		d_data = new char[in_commandType.d_size];
		d_size = in_commandType.d_size;
		memcpy(d_data, in_commandType.d_data, d_size);
	}

	CommandType(CommandType&& in_commandType)
	{
		d_data = in_commandType.d_data;
		d_size = in_commandType.d_size;
	}
	~CommandType()
	{
		if (d_data != nullptr)
		{
			delete[] d_data;
			d_size = 0;
			d_data = nullptr;
		}
	}
	friend bool operator==(const CommandType& in_commandLeft, const CommandType& in_commandRight)
	{
		return in_commandLeft.d_cmd == in_commandRight.d_cmd;
	}
};

struct tagCOMM_PACKET 
{
	unsigned char tagHead[3];						//包头(0x55,0xaa,0x5a)
	unsigned char typeCode;							//类型码
	unsigned short tagLen;							//包长(=参数字节数+3, 实际命令数据包长度=包长+4)
};

struct tagCOMM_PACKET1 
{
	unsigned char tagHead[3];						//包头(0x55,0xaa,0x5a)
	unsigned char typeCode;							//类型码
	unsigned short tagLen;							//包长(=参数字节数+3, 实际命令数据包长度=包长+4)
};

class SimotionController :
	public ControllerInterface, std::enable_shared_from_this<SimotionController>
{
private:
	std::unique_ptr<TcpServer> d_server;
	const static unsigned short d_port;
	const static int d_packetSize;
	
	SysStatus d_sysStatus;
	ControlSystemStatus d_ctrlSysSts;									//控制系统状态字
	List<CommandType> d_cmdList;
	std::condition_variable d_con;
	std::mutex d_mutex;
	int d_receivedCmd;
			
	bool d_save;
	bool d_ready;
	bool d_waitNextScan;
	bool d_run;
	bool d_threadRun;

	char* d_netWorkBuffer;
	int d_bytesReceived;
	void getAixsValueAndNotify(std::map<Axis, float>& in_value, char* in_data, int in_axisNum, int in_typeCode);
	void fillInCmdStructAndFillCmdList(int in_cmd, char* in_data, int in_size, bool in_consist);
protected:
	virtual bool sendCmd();
	virtual void setConnectdSts(); 
	void pocessData(char* in_package, int in_size);
public:
	SimotionController();
	~SimotionController();
	
	virtual bool getConnected();
	virtual bool checkReadyToScan();

	virtual bool initialSend();
	virtual bool stopAll();
	virtual bool initialiseController();
	virtual bool axisSeekZero(Axis in_axis);
	virtual bool axisAbsMove(Axis in_axis, float in_pos);
	virtual bool axisRelMove(Axis in_axis, float in_pos);
	virtual bool sliceMove(float in_pos);

	virtual bool readReadyStatus();
	virtual bool readSaveStatus();
	virtual bool readWaitNextScanStatus();
	virtual bool readRunStatus();
	virtual std::map<Axis, float> readAxisSpeed();
	virtual float readAxisPostion(Axis in_axis);
	virtual std::map<Axis, float> readAxisPostion();
	virtual std::map<Axis, float> readAxisWorkZero();

	virtual void getSystemStatus();
	virtual void getAxisPosition();
	virtual void getAxisSpeed();
	virtual void getAxisWorkZero();

	virtual void stopGettingAxisPostion();

	virtual void setAxisSpeed(std::map<Axis, float>& in_speed);
	virtual void setAxisWorkZero(std::map<Axis, float>& in_workZero);
	
	virtual void sendToControl(char* in_package, int in_size, bool in_consist = false);
	virtual void decodePackages(char* in_package, int in_size);
};

