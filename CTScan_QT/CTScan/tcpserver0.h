#pragma once

#include <QObject>

class TcpServer0 : public QObject
{
	Q_OBJECT

public:
	TcpServer0(QObject *parent);
	~TcpServer0();
};
