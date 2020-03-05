#include "stdafx.h"
#include "TcpServer.h"
#include <thread>

TcpServer::TcpServer(int in_packetSize, unsigned short in_serverPort, QObject *parent) : d_tcpServer(new QTcpServer())
	, QObject(parent)
	, d_serverPort(in_serverPort), d_packetSize(in_packetSize)
{
	initialNetWork();
	connect(d_tcpServer, SIGNAL(newConnection()), this, SLOT(acceptCollection()));
}


TcpServer::~TcpServer()
{
	d_isRecvRunning = false;
	d_isSendRunning = false;
	if (d_recvThreadPromisePtr)
		d_recvThreadPromisePtr->get_future().get();

	if (d_sendThreadPromisePtr)
		d_sendThreadPromisePtr->get_future().get();
}
bool TcpServer::initialNetWork()
{
	d_sendThreadPromisePtr.reset(new std::promise<bool>);
	std::function<void()> sendThreadFun = std::bind(&TcpServer::sendThread, this, std::ref(*d_sendThreadPromisePtr));
	std::thread(sendThreadFun).detach();
	d_recvThreadPromisePtr.reset(new std::promise<bool>);
	std::function<void()> recvThreadFun = std::bind(&TcpServer::recvThread, this, std::ref(*d_recvThreadPromisePtr));
	std::thread(recvThreadFun).detach();

	return true;
	//return d_tcpServer->listen(in_address, in_serverPort);
}
bool TcpServer::sendAsyn(const char* in_buffer, int in_size)
{
	d_sendQueue.push({ in_buffer, in_size });
	TcpServer::command cmd{ in_buffer, in_size };
	d_sendQueue.push(cmd);
	return true;
}
int TcpServer::sendSyn(const char* in_buffer, int in_size)
{
	if(d_tcpSocket)
		return d_tcpSocket->write(in_buffer, in_size);

	return -1;
}
bool TcpServer::receive(char* in_buffer, int in_size)
{
	return true;
}
void TcpServer::acceptCollection()
{
	d_tcpSocket = d_tcpServer->nextPendingConnection();
	d_tcpServer->pauseAccepting();
}
void TcpServer::recvThread(std::promise<bool>& in_promise)
{
	in_promise.set_value_at_thread_exit(true);

	while (d_isRecvRunning)
	{
		char* buffer = new char[d_packetSize];
		int byteRead = 0;

		while (d_connected)
		{
			int nRet = d_tcpSocket->read(buffer + byteRead, d_packetSize - byteRead);

			if (nRet == -1)
			{
				reAccept();
				break;
			}

			byteRead += nRet;

			if (byteRead == d_packetSize)
			{
				TcpServer::command cmd{ buffer, d_packetSize };
				d_receiveQueue.push(cmd);
			}
		}
	}
}

void TcpServer::sendThread(std::promise<bool>& in_promise)
{
	in_promise.set_value_at_thread_exit(true);

	while (d_isSendRunning)
	{
		command cmd;
		int byteSend = 0;
		d_sendQueue.pop(cmd);

		while (d_connected)
		{
			int nRet = d_tcpSocket->write(cmd.in_buffer + byteSend, cmd.in_size - byteSend);
			
			if (nRet == -1)
			{
				reAccept();
				break;
			}

			byteSend += nRet;

			if (byteSend == cmd.in_size)
				break;
		}
	}
}

void TcpServer::reAccept()
{
	d_connected = false;
	delete d_tcpSocket;
	d_tcpServer->resumeAccepting();
}