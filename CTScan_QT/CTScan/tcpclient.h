#pragma once

#include <QObject>
#include <QtNetWork>
#include <future>
#include "CommandQueue.h"

class TcpClient : public QObject
{
	Q_OBJECT
private:
	QTcpSocket* d_tcpSocket;
	unsigned short d_serverPort;
	struct command
	{
		const char* in_buffer;
		int in_size;
	};
	bool d_connected;
	bool initialNetWork();
	void recvThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_recvThreadPromisePtr;
	bool d_isRecvRunning;
	
	void sendThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_sendThreadPromisePtr;
	bool d_isSendRunning;
	TheQueue<command> d_sendQueue;
public:
	TcpClient(QString& in_hostAddress, quint16 in_port, QObject *parent = Q_NULLPTR);
	~TcpClient();

	bool sendAsyn(const char* in_buffer, int in_size);
	int sendSyn(const char* in_buffer, int in_size);
	bool receive(char* in_buffer, int in_size);
};
