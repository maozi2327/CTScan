#pragma once

#include "tcpserver_global.h"
#include <QObject>
#include <QtNetWork>
#include <future>
#include <functional>
#include "../public/headers/commandqueue.h"

class TCPSERVER_EXPORT TcpServer : public QObject
{
	Q_OBJECT

public:
	TcpServer(int in_packetHeadSize, int in_packetSizeLenth, int in_packetSizePos
		, std::function<void()> in_sendDataCallBack, std::function<void(char*, int in_size)> in_recvDataCallBack
		, QHostAddress in_hosetAddress, unsigned short in_serverPort, QObject *parent = Q_NULLPTR);
	TcpServer(int in_packetSize, QHostAddress in_hosetAddress, unsigned short in_serverPort
		, std::function<void(char*, int in_size)> in_dataHandlerCallBack, QObject *parent = Q_NULLPTR);
	virtual ~TcpServer();
	bool sendAsyn(const char* in_buffer, int in_size);
	int sendSyn(const char* in_buffer, int in_size);
	bool receive(char* in_buffer, int in_size);
	void recvThreadPacketHead(std::promise<bool>& in_promise);
	bool getConnected();

signals:
	void netWorkStatusSignal(int sts);
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
	QTcpServer* d_tcpServer;
	QTcpSocket* d_tcpSocket;
	unsigned short d_serverPort;
	QHostAddress d_serverAddress;
	TheQueue<command> d_sendQueue;
	TheQueue<command> d_receiveQueue;
	bool initialNetWork();
	bool initialNetWorkForVariablePacketSize();
	void acceptCollection();
	void reAccept();
	void recvThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_recvThreadPromisePtr;
	bool d_isRecvRunning;
	bool d_connected;
	void sendThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_sendThreadPromisePtr;
	bool d_isSendRunning;
};

