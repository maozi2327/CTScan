/********************************************************************************
** Form generated from reading UI file 'linedetscanwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEDETSCANWIDGET_H
#define UI_LINEDETSCANWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineDetScanWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_53;
    QComboBox *comboBox_35;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLabel *label_17;
    QLineEdit *lineEdit_5;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QWidget *widget2;
    QGridLayout *gridLayout_3;
    QLabel *label_41;
    QComboBox *comboBox_27;
    QLabel *label_34;
    QComboBox *comboBox_22;
    QLabel *label_35;
    QComboBox *comboBox_23;
    QLabel *label_36;
    QComboBox *comboBox_24;
    QLabel *label_37;
    QLineEdit *lineEdit_13;
    QLabel *label_38;
    QLineEdit *lineEdit_14;
    QWidget *tab_5;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_40;
    QComboBox *comboBox_26;
    QLabel *label_39;
    QComboBox *comboBox_25;
    QLabel *label_31;
    QComboBox *comboBox_20;
    QLabel *label_30;
    QComboBox *comboBox_21;
    QLabel *label_33;
    QComboBox *comboBox_19;
    QLabel *label_32;
    QLineEdit *lineEdit_11;
    QLabel *label_29;
    QLineEdit *lineEdit_12;
    QLabel *label_18;
    QLineEdit *lineEdit_7;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QProgressBar *progressBar;
    QLabel *label_5;
    QProgressBar *progressBar_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *LineDetScanWidget)
    {
        if (LineDetScanWidget->objectName().isEmpty())
            LineDetScanWidget->setObjectName(QStringLiteral("LineDetScanWidget"));
        LineDetScanWidget->resize(300, 400);
        LineDetScanWidget->setMinimumSize(QSize(300, 400));
        LineDetScanWidget->setMaximumSize(QSize(300, 400));
        widget = new QWidget(LineDetScanWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(12, 14, 282, 372));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(280, 280));
        tabWidget->setMaximumSize(QSize(280, 280));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget1 = new QWidget(tab);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 10, 252, 204));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(10);
        label_53 = new QLabel(widget1);
        label_53->setObjectName(QStringLiteral("label_53"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_53->sizePolicy().hasHeightForWidth());
        label_53->setSizePolicy(sizePolicy);
        label_53->setMinimumSize(QSize(54, 0));
        label_53->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_53, 0, 0, 1, 1);

        comboBox_35 = new QComboBox(widget1);
        comboBox_35->setObjectName(QStringLiteral("comboBox_35"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_35->sizePolicy().hasHeightForWidth());
        comboBox_35->setSizePolicy(sizePolicy1);
        comboBox_35->setMinimumSize(QSize(80, 0));
        comboBox_35->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(comboBox_35, 0, 1, 1, 1);

        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(54, 0));
        label->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        comboBox = new QComboBox(widget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(80, 0));
        comboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(comboBox, 1, 1, 1, 1);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(54, 0));
        label_2->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        comboBox_2 = new QComboBox(widget1);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);
        comboBox_2->setMinimumSize(QSize(80, 0));
        comboBox_2->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(comboBox_2, 2, 1, 1, 1);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(54, 0));
        label_3->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        comboBox_3 = new QComboBox(widget1);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        sizePolicy1.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy1);
        comboBox_3->setMinimumSize(QSize(80, 0));
        comboBox_3->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(comboBox_3, 3, 1, 1, 1);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(54, 0));
        label_7->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(80, 0));
        lineEdit->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(lineEdit, 4, 1, 1, 1);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(54, 0));
        label_8->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_8, 5, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(80, 0));
        lineEdit_2->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(lineEdit_2, 5, 1, 1, 1);

        label_17 = new QLabel(widget1);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(54, 0));
        label_17->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_17, 6, 0, 1, 1);

        lineEdit_5 = new QLineEdit(widget1);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);
        lineEdit_5->setMinimumSize(QSize(80, 0));
        lineEdit_5->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(lineEdit_5, 6, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(widget1);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(100, 130));
        listWidget->setMaximumSize(QSize(100, 130));

        verticalLayout->addWidget(listWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget2 = new QWidget(tab_2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(12, 10, 142, 172));
        gridLayout_3 = new QGridLayout(widget2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(10);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_41 = new QLabel(widget2);
        label_41->setObjectName(QStringLiteral("label_41"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy2);
        label_41->setMinimumSize(QSize(54, 0));
        label_41->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_41, 0, 0, 1, 1);

        comboBox_27 = new QComboBox(widget2);
        comboBox_27->setObjectName(QStringLiteral("comboBox_27"));
        comboBox_27->setMinimumSize(QSize(80, 0));
        comboBox_27->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(comboBox_27, 0, 1, 1, 1);

        label_34 = new QLabel(widget2);
        label_34->setObjectName(QStringLiteral("label_34"));
        sizePolicy2.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy2);
        label_34->setMinimumSize(QSize(54, 0));
        label_34->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_34, 1, 0, 1, 1);

        comboBox_22 = new QComboBox(widget2);
        comboBox_22->setObjectName(QStringLiteral("comboBox_22"));
        comboBox_22->setMinimumSize(QSize(80, 0));
        comboBox_22->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(comboBox_22, 1, 1, 1, 1);

        label_35 = new QLabel(widget2);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy2.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy2);
        label_35->setMinimumSize(QSize(54, 0));
        label_35->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_35, 2, 0, 1, 1);

        comboBox_23 = new QComboBox(widget2);
        comboBox_23->setObjectName(QStringLiteral("comboBox_23"));
        comboBox_23->setMinimumSize(QSize(80, 0));
        comboBox_23->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(comboBox_23, 2, 1, 1, 1);

        label_36 = new QLabel(widget2);
        label_36->setObjectName(QStringLiteral("label_36"));
        sizePolicy2.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy2);
        label_36->setMinimumSize(QSize(54, 0));
        label_36->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_36, 3, 0, 1, 1);

        comboBox_24 = new QComboBox(widget2);
        comboBox_24->setObjectName(QStringLiteral("comboBox_24"));
        comboBox_24->setMinimumSize(QSize(80, 0));
        comboBox_24->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(comboBox_24, 3, 1, 1, 1);

        label_37 = new QLabel(widget2);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy2.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy2);
        label_37->setMinimumSize(QSize(54, 0));
        label_37->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_37, 4, 0, 1, 1);

        lineEdit_13 = new QLineEdit(widget2);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setMinimumSize(QSize(80, 0));
        lineEdit_13->setMaximumSize(QSize(80, 16777215));
        lineEdit_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(lineEdit_13, 4, 1, 1, 1);

        label_38 = new QLabel(widget2);
        label_38->setObjectName(QStringLiteral("label_38"));
        sizePolicy2.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy2);
        label_38->setMinimumSize(QSize(54, 0));
        label_38->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_38, 5, 0, 1, 1);

        lineEdit_14 = new QLineEdit(widget2);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy3);
        lineEdit_14->setMinimumSize(QSize(80, 0));
        lineEdit_14->setMaximumSize(QSize(80, 16777215));
        lineEdit_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(lineEdit_14, 5, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        widget3 = new QWidget(tab_5);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(10, 10, 252, 234));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(10);
        label_40 = new QLabel(widget3);
        label_40->setObjectName(QStringLiteral("label_40"));
        sizePolicy.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy);
        label_40->setMinimumSize(QSize(54, 0));
        label_40->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_40, 0, 0, 1, 1);

        comboBox_26 = new QComboBox(widget3);
        comboBox_26->setObjectName(QStringLiteral("comboBox_26"));
        sizePolicy1.setHeightForWidth(comboBox_26->sizePolicy().hasHeightForWidth());
        comboBox_26->setSizePolicy(sizePolicy1);
        comboBox_26->setMinimumSize(QSize(80, 0));
        comboBox_26->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(comboBox_26, 0, 1, 1, 1);

        label_39 = new QLabel(widget3);
        label_39->setObjectName(QStringLiteral("label_39"));
        sizePolicy.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy);
        label_39->setMinimumSize(QSize(54, 0));
        label_39->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_39, 1, 0, 1, 1);

        comboBox_25 = new QComboBox(widget3);
        comboBox_25->setObjectName(QStringLiteral("comboBox_25"));
        sizePolicy1.setHeightForWidth(comboBox_25->sizePolicy().hasHeightForWidth());
        comboBox_25->setSizePolicy(sizePolicy1);
        comboBox_25->setMinimumSize(QSize(80, 0));
        comboBox_25->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(comboBox_25, 1, 1, 1, 1);

        label_31 = new QLabel(widget3);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy);
        label_31->setMinimumSize(QSize(54, 0));
        label_31->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_31, 2, 0, 1, 1);

        comboBox_20 = new QComboBox(widget3);
        comboBox_20->setObjectName(QStringLiteral("comboBox_20"));
        sizePolicy1.setHeightForWidth(comboBox_20->sizePolicy().hasHeightForWidth());
        comboBox_20->setSizePolicy(sizePolicy1);
        comboBox_20->setMinimumSize(QSize(80, 0));
        comboBox_20->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(comboBox_20, 2, 1, 1, 1);

        label_30 = new QLabel(widget3);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);
        label_30->setMinimumSize(QSize(54, 0));
        label_30->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_30, 3, 0, 1, 1);

        comboBox_21 = new QComboBox(widget3);
        comboBox_21->setObjectName(QStringLiteral("comboBox_21"));
        sizePolicy1.setHeightForWidth(comboBox_21->sizePolicy().hasHeightForWidth());
        comboBox_21->setSizePolicy(sizePolicy1);
        comboBox_21->setMinimumSize(QSize(80, 0));
        comboBox_21->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(comboBox_21, 3, 1, 1, 1);

        label_33 = new QLabel(widget3);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy);
        label_33->setMinimumSize(QSize(54, 0));
        label_33->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_33, 4, 0, 1, 1);

        comboBox_19 = new QComboBox(widget3);
        comboBox_19->setObjectName(QStringLiteral("comboBox_19"));
        sizePolicy1.setHeightForWidth(comboBox_19->sizePolicy().hasHeightForWidth());
        comboBox_19->setSizePolicy(sizePolicy1);
        comboBox_19->setMinimumSize(QSize(80, 0));
        comboBox_19->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(comboBox_19, 4, 1, 1, 1);

        label_32 = new QLabel(widget3);
        label_32->setObjectName(QStringLiteral("label_32"));
        sizePolicy.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy);
        label_32->setMinimumSize(QSize(54, 0));
        label_32->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_32, 5, 0, 1, 1);

        lineEdit_11 = new QLineEdit(widget3);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        sizePolicy1.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy1);
        lineEdit_11->setMinimumSize(QSize(80, 0));
        lineEdit_11->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_11, 5, 1, 1, 1);

        label_29 = new QLabel(widget3);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setMinimumSize(QSize(54, 0));
        label_29->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_29, 6, 0, 1, 1);

        lineEdit_12 = new QLineEdit(widget3);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        sizePolicy1.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy1);
        lineEdit_12->setMinimumSize(QSize(80, 0));
        lineEdit_12->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_12, 6, 1, 1, 1);

        label_18 = new QLabel(widget3);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(54, 0));
        label_18->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_18, 7, 0, 1, 1);

        lineEdit_7 = new QLineEdit(widget3);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);
        lineEdit_7->setMinimumSize(QSize(80, 0));
        lineEdit_7->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_7, 7, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget_2 = new QListWidget(widget3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy4);
        listWidget_2->setMinimumSize(QSize(100, 130));
        listWidget_2->setMaximumSize(QSize(100, 130));

        verticalLayout_2->addWidget(listWidget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tab_5, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMinimumSize(QSize(100, 0));
        progressBar->setAutoFillBackground(false);
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(progressBar, 1, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        progressBar_2 = new QProgressBar(widget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        sizePolicy1.setHeightForWidth(progressBar_2->sizePolicy().hasHeightForWidth());
        progressBar_2->setSizePolicy(sizePolicy1);
        progressBar_2->setAutoFillBackground(false);
        progressBar_2->setValue(24);
        progressBar_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(progressBar_2, 2, 1, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(pushButton, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_4->addLayout(horizontalLayout, 3, 1, 1, 1);


        retranslateUi(LineDetScanWidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(LineDetScanWidget);
    } // setupUi

    void retranslateUi(QWidget *LineDetScanWidget)
    {
        LineDetScanWidget->setWindowTitle(QApplication::translate("LineDetScanWidget", "LineDetScanWidget", nullptr));
        label_53->setText(QApplication::translate("LineDetScanWidget", "\345\275\223\345\211\215/\345\244\232\345\261\202", nullptr));
        label->setText(QApplication::translate("LineDetScanWidget", "\345\233\276\345\203\217\347\237\251\351\230\265", nullptr));
        label_2->setText(QApplication::translate("LineDetScanWidget", "\350\247\206\345\234\272\347\233\264\345\276\204", nullptr));
        label_3->setText(QApplication::translate("LineDetScanWidget", "\351\207\207\346\240\267\346\254\241\346\225\260", nullptr));
        label_7->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\344\275\215", nullptr));
        label_8->setText(QApplication::translate("LineDetScanWidget", "\346\226\255\345\261\202\344\275\215\347\275\256", nullptr));
        label_17->setText(QApplication::translate("LineDetScanWidget", "\345\261\202\351\227\264\350\267\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("LineDetScanWidget", "\344\270\211\344\273\243CT", nullptr));
        label_41->setText(QApplication::translate("LineDetScanWidget", "\346\257\224\344\276\213\346\250\241\345\274\217", nullptr));
        label_34->setText(QApplication::translate("LineDetScanWidget", "\345\233\276\345\203\217\347\237\251\351\230\265", nullptr));
        label_35->setText(QApplication::translate("LineDetScanWidget", "\350\247\206\345\234\272\347\233\264\345\276\204", nullptr));
        label_36->setText(QApplication::translate("LineDetScanWidget", "\351\207\207\346\240\267\346\254\241\346\225\260", nullptr));
        label_37->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\344\275\215", nullptr));
        label_38->setText(QApplication::translate("LineDetScanWidget", "\346\226\255\345\261\202\344\275\215\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("LineDetScanWidget", "DR", nullptr));
        label_40->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\345\274\217", nullptr));
        label_39->setText(QApplication::translate("LineDetScanWidget", "\345\275\223\345\211\215/\345\244\232\345\261\202", nullptr));
        label_31->setText(QApplication::translate("LineDetScanWidget", "\345\233\276\345\203\217\347\237\251\351\230\265", nullptr));
        label_30->setText(QApplication::translate("LineDetScanWidget", "\350\247\206\345\234\272\347\233\264\345\276\204", nullptr));
        label_33->setText(QApplication::translate("LineDetScanWidget", "\351\207\207\346\240\267\346\254\241\346\225\260", nullptr));
        label_32->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\344\275\215", nullptr));
        label_29->setText(QApplication::translate("LineDetScanWidget", "\346\226\255\345\261\202\344\275\215\347\275\256", nullptr));
        label_18->setText(QApplication::translate("LineDetScanWidget", "\345\261\202\351\227\264\350\267\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("LineDetScanWidget", "\344\272\214\344\273\243CT", nullptr));
        label_4->setText(QApplication::translate("LineDetScanWidget", "\345\275\223\345\211\215\350\277\233\345\272\246", nullptr));
        label_5->setText(QApplication::translate("LineDetScanWidget", "\346\200\273\344\275\223\350\277\233\345\272\246", nullptr));
        pushButton->setText(QApplication::translate("LineDetScanWidget", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QApplication::translate("LineDetScanWidget", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineDetScanWidget: public Ui_LineDetScanWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEDETSCANWIDGET_H
