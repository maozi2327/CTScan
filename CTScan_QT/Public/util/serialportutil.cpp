#include "stdafx.h"
#include "serialportutil.h"
#include <thread>

//-----------------SerialPortUtil::--------------------------------------

SerialPortUtil* SerialPortUtil::d_s_instance;
SerialPortUtil::SerialPortUtil(QObject *parent)
	: QObject(parent)
{
	
}

SerialPortUtil * SerialPortUtil::getHandle()
{
	if (d_s_instance == nullptr)
		d_s_instance = new SerialPortUtil();

	return d_s_instance;
}

SerialPortUtil::~SerialPortUtil()
{
	
}

bool SerialPortUtil::browseSerialPort(std::vector<std::pair<QString, bool>>& in_portName)
{
	const auto infos = QSerialPortInfo::availablePorts();
	in_portName.clear();

	QSerialPort* originPort = new QSerialPort();
	
	for (const QSerialPortInfo &info : infos)
	{
		originPort->setPortName(info.portName());
		in_portName.push_back({ info.portName(), originPort->isOpen()});
	}

	return true;
}

bool SerialPortUtil::openSerialPort(const QString& in_portName, QSerialPort::BaudRate in_baudRate
	, QSerialPort::DataBits in_dataBits, QSerialPort::StopBits in_stopBits
	, QSerialPort::FlowControl in_flowControl, QSerialPort::Parity in_parity)
{
	if (d_serialPortMap.find(in_portName) != d_serialPortMap.end())
	{
		QSerialPort* originPort = new QSerialPort();
		originPort->setPortName(in_portName);
		originPort->setBaudRate(in_baudRate);
		originPort->setStopBits(in_stopBits);
		originPort->setFlowControl(in_flowControl);
		originPort->setParity(in_parity);

		if (originPort->open(QIODevice::WriteOnly))
		{
			SerialPort* port = new SerialPort(this, originPort, in_portName);
			d_serialPortMap.insert({ in_portName, port });
			return true;
		}
	}

	return false;
}

bool SerialPortUtil::closeSerialPort(const QString & in_portName)
{
	if (d_serialPortMap.find(in_portName) != d_serialPortMap.end())
	{
		d_serialPortMap[in_portName]->closeSerialPort();
		d_serialPortMap.erase(in_portName);
	}

	return true;
}

bool SerialPortUtil::send(const char * in_buffer, int in_size, const QString & in_portName)
{
	if (d_serialPortMap.find(in_portName) != d_serialPortMap.end())
		if (d_serialPortMap[in_portName]->sendAsyn(in_buffer, in_size))
			return true;

	return false;
}


bool SerialPortUtil::receive(char * in_buffer, int in_size, const QString & in_portName)
{
	if (d_serialPortMap.find(in_portName) != d_serialPortMap.end())
		d_serialPortMap[in_portName]->receive(in_buffer, in_size);

	return true;
}

bool SerialPortUtil::onSerialError(QString& out_serialName)
{
	closeSerialPort(out_serialName);
	return true;
}
//-----------------SerialPortUtil::SerialPort----------------------------
SerialPort::SerialPort(SerialPortUtil* in_serialPortUtil, QSerialPort* in_port, QString in_serialPortName)
	: d_serialPortUtil(in_serialPortUtil)
{
	d_isOpen = true;
	d_isSendRunning = true;
	d_isRecvRunning = true;
	d_sendThreadPromisePtr.reset(new std::promise<bool>());
	std::function<void()> sendFunc = std::bind(&SerialPort::sendThread, this, std::ref(*d_sendThreadPromisePtr));
	std::thread(sendFunc).detach();
	
	d_recvThreadPromisePtr.reset(new std::promise<bool>());
	std::function<void()> recvFunc = std::bind(&SerialPort::recvThread, this, std::ref(*d_recvThreadPromisePtr));
	std::thread(recvFunc).detach();

	connect(this, &SerialPort::serialError, d_serialPortUtil, &SerialPortUtil::onSerialError);
}


SerialPort::~SerialPort()
{
	d_isSendRunning = false;
	d_isRecvRunning = false;
	d_sendThreadPromisePtr->get_future().get();
	d_recvThreadPromisePtr->get_future().get();
}

bool SerialPort::closeSerialPort()
{
	d_isOpen = false;
	d_isRecvRunning = false;
	d_isSendRunning = false;
	d_serialPort->close();
	return true;
}

bool SerialPort::sendAsyn(const char * in_buffer, int in_size)
{
	if (d_isOpen)
	{
		SendCommand cmd = { in_buffer, in_size };
		d_sendQueue.push(cmd);
		return true;
	}
	else
		return false;
}

bool SerialPort::receive(char * in_buffer, int in_size)
{
	RecvCommand cmd;

	if(!d_receiveQueue.pop(cmd))
		return false;
	
	in_buffer = cmd.in_buffer;
	in_size = cmd.in_size;
	return true;
}

void SerialPort::sendThread(std::promise<bool>& in_promise)
{
	in_promise.set_value_at_thread_exit(true);

	while (d_isSendRunning)
	{
		SendCommand cmd;
		int byteSend = 0;
		
		if(!d_sendQueue.pop(cmd))
			continue;

		while (d_isOpen)
		{
			byteSend = d_serialPort->write(cmd.in_buffer);

			if (byteSend != cmd.in_size)
			{
				d_isOpen = false;
				emit serialError(d_serialPortName);
				break;
			}
		}
	}
}

void SerialPort::recvThread(std::promise<bool>& in_promise)
{
	in_promise.set_value_at_thread_exit(true);

	while (d_isSendRunning)
	{
		while (d_serialPort->waitForReadyRead(1000))
		{
			QByteArray byteArray = d_serialPort->readAll();
			
			if (byteArray.size() == 0)
			{
				d_isOpen = false;
				emit serialError(d_serialPortName);
				break;
			}

			char* buf = new char[byteArray.size() + 1];
			RecvCommand cmd = { buf, byteArray.size() };
			d_receiveQueue.push(cmd);
		}
	}
}