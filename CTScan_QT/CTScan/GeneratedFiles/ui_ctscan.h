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
    QPushButton *ray1LineDet1Button;
    QPushButton *ray1PanelDet1Button;
    QPushButton *ray2LineDet1Button;
    QPushButton *ray2PanelDet1Button;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CTScanClass)
    {
        if (CTScanClass->objectName().isEmpty())
            CTScanClass->setObjectName(QStringLiteral("CTScanClass"));
        CTScanClass->resize(166, 359);
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
        ray1LineDet1Button = new QPushButton(layoutWidget);
        ray1LineDet1Button->setObjectName(QStringLiteral("ray1LineDet1Button"));
        ray1LineDet1Button->setMinimumSize(QSize(110, 60));
        ray1LineDet1Button->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray1LineDet1Button);

        ray1PanelDet1Button = new QPushButton(layoutWidget);
        ray1PanelDet1Button->setObjectName(QStringLiteral("ray1PanelDet1Button"));
        ray1PanelDet1Button->setMinimumSize(QSize(110, 60));
        ray1PanelDet1Button->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray1PanelDet1Button);

        ray2LineDet1Button = new QPushButton(layoutWidget);
        ray2LineDet1Button->setObjectName(QStringLiteral("ray2LineDet1Button"));
        ray2LineDet1Button->setMinimumSize(QSize(110, 60));
        ray2LineDet1Button->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray2LineDet1Button);

        ray2PanelDet1Button = new QPushButton(layoutWidget);
        ray2PanelDet1Button->setObjectName(QStringLiteral("ray2PanelDet1Button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ray2PanelDet1Button->sizePolicy().hasHeightForWidth());
        ray2PanelDet1Button->setSizePolicy(sizePolicy);
        ray2PanelDet1Button->setMinimumSize(QSize(110, 60));
        ray2PanelDet1Button->setMaximumSize(QSize(110, 60));

        verticalLayout->addWidget(ray2PanelDet1Button);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 310, 75, 23));
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
        ray1LineDet1Button->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2201-\347\272\277\351\230\265", nullptr));
        ray1PanelDet1Button->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2201-\351\235\242\351\230\265", nullptr));
        ray2LineDet1Button->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2202-\347\272\277\351\230\265", nullptr));
        ray2PanelDet1Button->setText(QApplication::translate("CTScanClass", "\345\260\204\347\272\277\346\272\2202-\351\235\242\351\230\265", nullptr));
        pushButton->setText(QApplication::translate("CTScanClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTScanClass: public Ui_CTScanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTSCAN_H
