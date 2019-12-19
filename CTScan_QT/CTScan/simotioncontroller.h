#pragma once
#include "controlerinterface.h"
#include "TcpServer.h"
class SimotionController :
	public ControlerInterface
{
private:
	TcpServer* d_tcpNetWork;
	const static unsigned short d_port;
	const static int d_packetSize;
	
	struct tagCOMM_PACKET {
		unsigned char tagHead[3];						//包头(0x55,0xaa,0x5a)
		unsigned char typeCode;						//类型码
		unsigned short tagLen;							//包长(=参数字节数+3, 实际命令数据包长度=包长+4)
		unsigned char data[d_packetSize - 6];			//命令参数
	};
public:
	SimotionController();
	~SimotionController();

	virtual float getAxisPostion(Axis in_axis);
	virtual bool getReadyStatus();
	virtual bool getSaveStatus();
	virtual bool getWaitNextScanStatus();
	virtual bool getRunStatus();
	virtual bool initialConnection();
	virtual bool sendCmd(unsigned char* in_cmd, size_t in_size);
};

