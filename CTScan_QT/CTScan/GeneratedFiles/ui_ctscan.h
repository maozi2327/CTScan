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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTScanClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CTScanClass)
    {
        if (CTScanClass->objectName().isEmpty())
            CTScanClass->setObjectName(QStringLiteral("CTScanClass"));
        CTScanClass->resize(166, 334);
        CTScanClass->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget = new QWidget(CTScanClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 112, 260));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(110, 60));
        pushButton->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(110, 60));
        pushButton_2->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(110, 60));
        pushButton_3->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(110, 60));
        pushButton_4->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(pushButton_4);

        CTScanClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CTScanClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CTScanClass->setStatusBar(statusBar);

        retranslateUi(CTScanClass);

        QMetaObject::connectSlotsByName(CTScanClass);
    } // setupUi

    void retranslateUi(QMainWindow *CTScanClass)
    {
        CTScanClass->setWindowTitle(QApplication::translate("CTScanClass", "CTScan", nullptr));
        pushButton->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2201-\347\272\277\351\230\265", nullptr));
        pushButton_2->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2201-\351\235\242\351\230\265", nullptr));
        pushButton_3->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2202-\347\272\277\351\230\265", nullptr));
        pushButton_4->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2202-\351\235\242\351\230\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTScanClass: public Ui_CTScanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTSCAN_H
