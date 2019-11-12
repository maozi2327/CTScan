#include "stdafx.h"
#include "ctscan.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CTScan w;
    w.show();
    return a.exec();
}
