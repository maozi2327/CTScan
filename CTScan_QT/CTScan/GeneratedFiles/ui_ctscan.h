/********************************************************************************
** Form generated from reading UI file 'ctscan.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTSCAN_H
#define UI_CTSCAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTScanClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CTScanClass)
    {
        if (CTScanClass->objectName().isEmpty())
            CTScanClass->setObjectName(QStringLiteral("CTScanClass"));
        CTScanClass->resize(715, 568);
        CTScanClass->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget = new QWidget(CTScanClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 80, 75, 23));
        CTScanClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CTScanClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 715, 23));
        menuBar->setDefaultUp(false);
        CTScanClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CTScanClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CTScanClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CTScanClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CTScanClass->setStatusBar(statusBar);

        retranslateUi(CTScanClass);

        QMetaObject::connectSlotsByName(CTScanClass);
    } // setupUi

    void retranslateUi(QMainWindow *CTScanClass)
    {
        CTScanClass->setWindowTitle(QApplication::translate("CTScanClass", "CTScan", nullptr));
        pushButton->setText(QApplication::translate("CTScanClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTScanClass: public Ui_CTScanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTSCAN_H
