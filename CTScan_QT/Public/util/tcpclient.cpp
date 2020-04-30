#include "stdafx.h"
#include "tcpclient.h"

TcpClient::TcpClient(QString& in_hostAddress, quint16 in_port, QObject *parent)
	: QObject(parent)
	, d_tcpSocket(new QTcpSocket)
{
	d_tcpSocket->connectToHost(in_hostAddress, in_port);
}

TcpClient::~TcpClient()
{
	d_isRecvRunning = true;
	d_isSendRunning = true;
	if (d_recvThreadPromisePtr)
		d_recvThreadPromisePtr->get_future().get();

	if (d_sendThreadPromisePtr)
		d_sendThreadPromisePtr->get_future().get();
}

bool TcpClient::sendAsyn(const char* in_buffer, int in_size)
{
	TcpClient::command cmd{ in_buffer, in_size };
	d_sendQueue.push(cmd);
	return true;
}

bool TcpClient::initialNetWork()
{
	d_sendThreadPromisePtr.reset(new std::promise<bool>);
	std::function<void()> sendThreadFun = std::bind(&TcpClient::sendThread, this, std::ref(*d_sendThreadPromisePtr));
	std::thread(sendThreadFun).detach();
	d_recvThreadPromisePtr.reset(new std::promise<bool>);
	std::function<void()> recvThreadFun = std::bind(&TcpClient::recvThread, this, std::ref(*d_recvThreadPromisePtr));
	std::thread(recvThreadFun).detach();

	return true;
	//return d_tcpServer->listen(in_address, in_serverPort);
}

int TcpClient::sendSyn(const char* in_buffer, int in_size)
{
	return 0;
}

bool TcpClient::receive(char* in_buffer, int in_size)
{
	return 0;
}
void TcpClient::sendThread(std::promise<bool>& in_promise)
{
	in_promise.set_value_at_thread_exit(true);

	while (d_isSendRunning)
	{
		command cmd;
		int byteSend = 0;

		if(!d_sendQueue.pop(cmd))
			continue;

		while (d_connected)
		{
			int nRet = d_tcpSocket->write(cmd.in_buffer + byteSend, cmd.in_size - byteSend);

			if (nRet == -1)
			{
				d_tcpSocket->close();
				break;
			}

			byteSend += nRet;

			if (byteSend == cmd.in_size)
				break;
		}
	}
}
void TcpClient::recvThread(std::promise<bool>& in_promise)
{

}