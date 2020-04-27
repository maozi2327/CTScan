#include "stdafx.h"
#include "ctscan.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(ctscan);
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication a(argc, argv);
    CTScan w;
    w.show();
    return a.exec();
}
