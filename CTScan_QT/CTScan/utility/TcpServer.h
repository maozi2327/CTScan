#pragma once
#include <QObject>
#include <QtNetWork>
#include <future>
#include "CommandQueue.h"
class TcpServer  : public QObject
{
	Q_OBJECT

public:
	TcpServer(int in_packetSize, unsigned short in_serverPort, QObject *parent = Q_NULLPTR);
	virtual ~TcpServer();
	bool initialNetWork();
	bool sendAsyn(const char* in_buffer, int in_size);
	int sendSyn(const char* in_buffer, int in_size);
	bool receive(char* in_buffer, int in_size);
private:
	struct command
	{
		const char* in_buffer;
		int in_size;
	};
	bool d_connected;
	int d_packetSize;
	QTcpServer* d_tcpServer;
	QTcpSocket* d_tcpSocket;
	unsigned short d_serverPort;
	QHostAddress d_serverAddress;
	TheQueue<command> d_sendQueue;
	TheQueue<command> d_receiveQueue;
	void acceptCollection();
	void reAccept();
	void recvThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_recvThreadPromisePtr;
	bool d_isRecvRunning;
	void sendThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_sendThreadPromisePtr;
	bool d_isSendRunning;
};

