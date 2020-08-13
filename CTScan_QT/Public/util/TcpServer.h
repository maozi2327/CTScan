#pragma once
#include <WinSock.h>
#include <future>
#include <functional>
#include "CommandQueue.h"
#pragma comment(lib, "Ws2_32.lib")

class TcpServer
{
public:
	TcpServer(int in_packetHeadSize, int in_packetSizeLenth, int in_packetSizePos
		, std::function<void()> in_sendDataCallBack, std::function<void(char*, int in_size)> in_recvDataCallBack
		, in_addr in_hosetAddress, unsigned short in_serverPort);
	virtual ~TcpServer();
	bool sendAsyn(const char* in_buffer, int in_size);
	int sendSyn(const char* in_buffer, int in_size);
	bool receive(char* in_buffer, int in_size);
	bool getConnected();

private:
	struct command
	{
		const char* in_buffer;
		int in_size;
	};
	int d_packetSize;

	int d_packetHeadSize;
	int d_packetSizePos;
	int d_packetSizeLenth;
	std::function<void(char*, int in_size)> d_dataHandlerCallBack;
	std::function<void()> d_sendInitiliseCallBack;
	SOCKET	d_server;
	SOCKET	d_client;
	unsigned short d_serverPort;
	in_addr d_address;
	sockaddr_in d_sockaddr;
	TheQueue<command> d_sendQueue;
	TheQueue<command> d_receiveQueue;
	bool initialNetWorkForVariablePacketSize();
	void recvThreadPacketHead(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_recvThreadPromisePtr;
	bool d_isRecvRunning;
	bool d_connected;
	void sendThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_sendThreadPromisePtr;
	bool d_isSendRunning;
};

