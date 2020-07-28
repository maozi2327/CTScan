#pragma once

#include <QObject>
#include <windows.h>
QByteArray getByteArray(QString& in_fileName);
quint64 getDiskFreeSpace(QString & in_folder);