#include "stdafx.h"
#include "functions.h"
#define MB 1024*1024
QByteArray getByteArray(QString & in_fileName)
{
	QByteArray byteArray = in_fileName.toLocal8Bit();
	return byteArray;
}
quint64 getDiskFreeSpace(QString & in_folder)
{
	LPCWSTR driver = (LPCWSTR)in_folder.left(0).utf16();
	ULARGE_INTEGER freeDiskSpaceAvailable;
	GetDiskFreeSpaceEx(driver, &freeDiskSpaceAvailable, nullptr, nullptr);
	return (quint64)freeDiskSpaceAvailable.QuadPart / MB;
}
