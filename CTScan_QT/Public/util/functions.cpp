#include "stdafx.h"
#include "functions.h"

QByteArray getByteArray(QString & in_fileName)
{
	QByteArray byteArray = in_fileName.toLocal8Bit();
	return byteArray;
}
