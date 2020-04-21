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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ray1LineDetButton;
    QPushButton *ray1PanelDetButton;
    QPushButton *ray2LineDetButton;
    QPushButton *ray2PanelDetButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CTScanClass)
    {
        if (CTScanClass->objectName().isEmpty())
            CTScanClass->setObjectName(QStringLiteral("CTScanClass"));
        CTScanClass->resize(166, 334);
        CTScanClass->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget = new QWidget(CTScanClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 112, 260));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ray1LineDetButton = new QPushButton(layoutWidget);
        ray1LineDetButton->setObjectName(QStringLiteral("ray1LineDetButton"));
        ray1LineDetButton->setMinimumSize(QSize(110, 60));
        ray1LineDetButton->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray1LineDetButton);

        ray1PanelDetButton = new QPushButton(layoutWidget);
        ray1PanelDetButton->setObjectName(QStringLiteral("ray1PanelDetButton"));
        ray1PanelDetButton->setMinimumSize(QSize(110, 60));
        ray1PanelDetButton->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray1PanelDetButton);

        ray2LineDetButton = new QPushButton(layoutWidget);
        ray2LineDetButton->setObjectName(QStringLiteral("ray2LineDetButton"));
        ray2LineDetButton->setMinimumSize(QSize(110, 60));
        ray2LineDetButton->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray2LineDetButton);

        ray2PanelDetButton = new QPushButton(layoutWidget);
        ray2PanelDetButton->setObjectName(QStringLiteral("ray2PanelDetButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ray2PanelDetButton->sizePolicy().hasHeightForWidth());
        ray2PanelDetButton->setSizePolicy(sizePolicy);
        ray2PanelDetButton->setMinimumSize(QSize(110, 60));
        ray2PanelDetButton->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray2PanelDetButton);

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
        ray1LineDetButton->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2201-\347\272\277\351\230\265", nullptr));
        ray1PanelDetButton->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2201-\351\235\242\351\230\265", nullptr));
        ray2LineDetButton->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2202-\347\272\277\351\230\265", nullptr));
        ray2PanelDetButton->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2202-\351\235\242\351\230\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTScanClass: public Ui_CTScanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTSCAN_H
