#pragma once

#include <QObject>

class PanelImageProcess : public QObject
{
	Q_OBJECT

public:
	PanelImageProcess(QObject *parent);
	~PanelImageProcess();

	void dispose(unsigned short* in_image);
};
