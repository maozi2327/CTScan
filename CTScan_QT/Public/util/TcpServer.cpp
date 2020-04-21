#include "stdafx.h"
#include "TcpServer.h"
#include <thread>

TcpServer::TcpServer(int in_packetHeadSize, int in_packetSizeLenth, int in_packetSizePos, std::function<void(char*, int in_size)> in_dataHandlerCallBack
	, QHostAddress in_hosetAddress, unsigned short in_serverPort, QObject *parent)
	: d_tcpServer(new QTcpServer())
	, QObject(parent)
	, d_packetHeadSize(in_packetHeadSize), d_packetSize(in_packetSizeLenth), d_packetSizePos(in_packetSizePos)
	, d_serverAddress(in_hosetAddress), d_serverPort(in_serverPort)
	, d_dataHandlerCallBack(in_dataHandlerCallBack)
	, d_connected(false)
{
	initialNetWorkForVariablePacketSize();
	connect(d_tcpServer, SIGNAL(newConnection()), this, SLOT(acceptCollection()));
}

TcpServer::TcpServer(int in_packetSize, QHostAddress in_hosetAddress, unsigned short in_serverPort
	, std::function<void(char*, int in_size)> in_dataHandlerCallBack, QObject *parent)
	: d_tcpServer(new QTcpServer())
	, QObject(parent)
	, d_serverAddress(in_hosetAddress), d_serverPort(in_serverPort), d_packetSize(in_packetSize)
	, d_dataHandlerCallBack(in_dataHandlerCallBack)
	, d_connected(false)
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

	return d_tcpServer->listen(d_serverAddress, d_serverPort);
}
bool TcpServer::initialNetWorkForVariablePacketSize()
{
	d_sendThreadPromisePtr.reset(new std::promise<bool>);
	//std::thread([this]() { sendThread(*d_sendThreadPromisePtr); });
	std::function<void()> sendThreadFun = std::bind(&TcpServer::sendThread, this, std::ref(*d_sendThreadPromisePtr));
	std::thread(sendThreadFun).detach();
	d_recvThreadPromisePtr.reset(new std::promise<bool>);
	std::function<void()> recvThreadFun = std::bind(&TcpServer::recvThreadPacketHead, this, std::ref(*d_recvThreadPromisePtr));
	std::thread(recvThreadFun).detach();

	return d_tcpServer->listen(d_serverAddress, d_serverPort);
}
bool TcpServer::sendAsyn(const char* in_buffer, int in_size)
{
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
	d_connected = true;
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
				byteRead = 0;
			}
		}
	}
}
void TcpServer::recvThreadPacketHead(std::promise<bool>& in_promise)
{
	in_promise.set_value_at_thread_exit(true);

	while (d_isRecvRunning)
	{
		int byteRead = 0;

		while (d_connected)
		{
			char* headBuffer = new char[d_packetHeadSize];
			int nRet = d_tcpSocket->read(headBuffer, d_packetHeadSize);

			if (nRet == -1)
			{
				reAccept();
				break;
			}

			byteRead += nRet;
			unsigned int packetSize = 0;
			memcpy(&packetSize, headBuffer + d_packetSizePos, d_packetSizeLenth);
			char* buffer = new char[packetSize];
			memcpy(buffer, headBuffer, d_packetHeadSize);
			delete[] headBuffer;

			while (byteRead != packetSize)
			{
				int nRet = d_tcpSocket->read(buffer + byteRead, d_packetHeadSize);

				if (nRet == -1)
				{
					reAccept();
					break;
				}

				byteRead += nRet;
			}

			if (byteRead == packetSize)
			{
				d_dataHandlerCallBack(buffer, d_packetSize);
				byteRead = 0;
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