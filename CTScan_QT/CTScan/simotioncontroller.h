#pragma once
#include "controlerinterface.h"
#include "../Public/util/TcpServer.h"
#include <list>
#include <memory>
#include <condition_variable>
#include <mutex>
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
	~CommandType()
	{
		if (d_data != nullptr)
		{
			delete[] d_data;
			d_size = 0;
		}
	}
	friend bool operator==(const CommandType& in_commandLeft, int d_cmd)
	{
		return in_commandLeft.d_cmd == d_cmd;
	}
};

struct tagCOMM_PACKET 
{
	unsigned char tagHead[3];						//包头(0x55,0xaa,0x5a)
	unsigned char typeCode;						//类型码
	unsigned short tagLen;							//包长(=参数字节数+3, 实际命令数据包长度=包长+4)
	unsigned char data[10 - 6];			//命令参数
};

struct tagCOMM_PACKET1 
{
	unsigned char tagHead[3];						//包头(0x55,0xaa,0x5a)
	unsigned char typeCode;						//类型码
	unsigned short tagLen;							//包长(=参数字节数+3, 实际命令数据包长度=包长+4)
};

class SimotionController :
	public ControlerInterface, std::enable_shared_from_this<SimotionController>
{
private:
	std::unique_ptr<TcpServer> d_server;
	const static unsigned short d_port;
	const static int d_packetSize;
	
	SysStatus d_sysStatus;
	ControlSystemStatus d_ctrlSysSts;									//控制系统状态字
	std::list<CommandType> d_cmdList;
	std::condition_variable d_con;
	std::mutex d_mutex;
	int d_receivedCmd;
	bool d_save;
	bool d_ready;
	bool d_waitNextScan;

	bool d_threadRun;

	void getAixsValueAndNotify(std::map<Axis, float>& in_value, char* in_data, int in_axisNum, int in_typeCode);
protected:
	virtual bool sendCmd();
public:
	SimotionController();
	~SimotionController();
	virtual bool initialConnection() = 0;

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

	virtual void setAxisSpeed(std::map<Axis, float>& in_speed);
	virtual void setAxisWorkZero(std::map<Axis, float>& in_workZero);
	
	virtual void decodePackages(char* in_package, int in_size);
};

