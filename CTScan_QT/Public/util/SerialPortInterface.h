#pragma once
#include <QSerialPortInfo>
#include <QSerialPort>
#include <vector>
#include <utility>
#include <memory>
class SerialPortInterface
{
public:
	virtual bool browseSerialPort(std::vector<std::pair<QString, bool>>& in_portName) = 0;
	virtual bool openSerialPort(const QString& in_portName, QSerialPort::BaudRate, QSerialPort::DataBits, QSerialPort::StopBits
		, QSerialPort::FlowControl, QSerialPort::Parity) = 0;
	virtual bool closeSerialPort(const QString& in_portName) = 0;
	virtual bool send(const char* in_buffer, int in_size, const QString& in_portName) = 0;
	virtual bool receive(char* in_buffer, int in_size, const QString& in_portName) = 0;
};
class PanelFactory
{
public:
	static SerialPortInterface* getHandle();
};
