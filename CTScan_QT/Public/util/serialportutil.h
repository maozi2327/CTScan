#pragma once

#include <QObject>
#include <future>
#include "SerialPortInterface.h"
#include "CommandQueue.h"

class SerialPortUtil;
class SerialPort : public QObject
{
	Q_OBJECT
private:
	struct SendCommand
	{
		const char* in_buffer;
		int in_size;
	};
	struct RecvCommand
	{
		char* in_buffer;
		int in_size;
	};
	TheQueue<SendCommand> d_sendQueue;
	TheQueue<RecvCommand> d_receiveQueue;
	bool d_isOpen;
	SerialPortUtil* d_serialPortUtil;
	QSerialPort* d_serialPort;
	QString d_serialPortName;
	void recvThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_recvThreadPromisePtr;
	bool d_isRecvRunning;
	void sendThread(std::promise<bool>& in_promise);
	std::unique_ptr<std::promise<bool>> d_sendThreadPromisePtr;
	bool d_isSendRunning;

signals:
	void serialError(QString& out_serialName);

public:
	SerialPort(SerialPortUtil* in_serialPortUtil, QSerialPort* in_port, QString in_serialPortName);
	~SerialPort();

	bool closeSerialPort();
	bool sendAsyn(const char* in_buffer, int in_size);
	bool receive(char* in_buffer, int in_size);
};

class SerialPortUtil : public QObject, public SerialPortInterface
{
	Q_OBJECT

private:
	SerialPortUtil(QObject *parent = NULL);
	static SerialPortUtil* d_s_instance;
	SerialPortUtil(const SerialPortUtil&) {};
	SerialPortUtil& operator=(const SerialPortUtil&) { return *this; };
public:
	static SerialPortUtil* getHandle();
	~SerialPortUtil();
public:
	bool browseSerialPort(std::vector<std::pair<QString, bool>>& in_portName);
	bool openSerialPort(const QString& in_portName, QSerialPort::BaudRate, QSerialPort::DataBits, QSerialPort::StopBits
		, QSerialPort::FlowControl, QSerialPort::Parity);
	bool closeSerialPort(const QString& in_portName);
	bool send(const char* in_buffer, int in_size, const QString& in_portName);
	bool receive(char* in_buffer, int in_size, const QString& in_portName);
public slots:
	bool onSerialError(QString& out_serialName);
private:
	std::map<QString, SerialPort*> d_serialPortMap;
	QSerialPortInfo* d_serialPortInfo;
	QByteArray d_writeData;
	QTextStream d_standardOutput;
	qint64 d_bytesWritten = 0;
	QTimer d_timer;
};
