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
    QLabel *label_5;
    QTabWidget *rayTab;
    QWidget *rayWrox225Tab;
    QPushButton *worx225XRayOffButton_2;
    QLabel *worx225kvStaticLabel_2;
    QLabel *worx225uaStaticLabel_2;
    QPushButton *worx225XRayOnButton_2;
    QComboBox *worx225FocusComboBox_2;
    QLineEdit *worx225EmissionCurrentEdit_2;
    QLineEdit *worx225VoltageInputEdit;
    QLabel *worx225FocusStaticLabel_2;
    QWidget *rayComet450Tab;
    QLabel *Comet450uaStaticLabel;
    QLineEdit *Comet450VoltageInputEdit;
    QLabel *Comet450kvStaticLabel;
    QPushButton *Comet450XRayOnButton;
    QLabel *Comet450FocusStaticLabel;
    QComboBox *Comet450FocusComboBox;
    QLineEdit *Comet450EmissionCurrentEdit;
    QPushButton *Comet450XRayOffButton;
    QLineEdit *fileNameEdit;
    QTabWidget *scanModeTab;
    QWidget *ct3Tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_53;
    QComboBox *ct3MultiLayerComboBox;
    QLabel *label;
    QComboBox *ct3MatrixComboBox;
    QLabel *label_2;
    QComboBox *ct3ViewComboBox;
    QLabel *label_3;
    QComboBox *ct3SampleTimeComboBox;
    QLabel *label_7;
    QLineEdit *ct3AngleLineEdit;
    QLabel *label_8;
    QLineEdit *ct3LayerPosLineEdit;
    QLabel *label_17;
    QLineEdit *ct3LayerSpaceLineEdit;
    QVBoxLayout *verticalLayout;
    QListWidget *ct3LayerPosListWidget;
    QSpacerItem *verticalSpacer_2;
    QWidget *ct2Tab;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_41;
    QComboBox *drRatioComboBox;
    QLabel *label_34;
    QComboBox *drMatrixComboBox;
    QLabel *label_35;
    QComboBox *drViewComboBox;
    QLabel *label_36;
    QComboBox *drSampleTimeComboBox;
    QLabel *label_37;
    QLineEdit *drAngleLineEdit;
    QLabel *label_38;
    QLineEdit *lineEdit_14;
    QWidget *drTab;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_40;
    QComboBox *ct2ScanModeComboBox;
    QLabel *label_39;
    QComboBox *ct2MultiLayerComboBox;
    QLabel *label_31;
    QComboBox *ct2MatrixComboBox;
    QLabel *label_30;
    QComboBox *ct2ViewComboBox;
    QLabel *label_33;
    QComboBox *ct2SampleTimeComboBox;
    QLabel *label_32;
    QLineEdit *lineEdit_11;
    QLabel *label_29;
    QLineEdit *lineEdit_12;
    QLabel *label_18;
    QLineEdit *lineEdit_7;
    QVBoxLayout *verticalLayout_2;
    QListWidget *ct2LayerPosListWidget;
    QSpacerItem *verticalSpacer;
    QPushButton *saveDirButton;
    QProgressBar *allProgressBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *stopButton;
    QProgressBar *nowProgressBar;
    QLabel *label_4;
    QPushButton *startButton;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *LineDetScanWidget)
    {
        if (LineDetScanWidget->objectName().isEmpty())
            LineDetScanWidget->setObjectName(QStringLiteral("LineDetScanWidget"));
        LineDetScanWidget->resize(300, 500);
        LineDetScanWidget->setMinimumSize(QSize(300, 500));
        LineDetScanWidget->setMaximumSize(QSize(300, 500));
        widget = new QWidget(LineDetScanWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 282, 520));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

        rayTab = new QTabWidget(widget);
        rayTab->setObjectName(QStringLiteral("rayTab"));
        rayTab->setMinimumSize(QSize(0, 80));
        rayTab->setMaximumSize(QSize(16777215, 80));
        rayWrox225Tab = new QWidget();
        rayWrox225Tab->setObjectName(QStringLiteral("rayWrox225Tab"));
        worx225XRayOffButton_2 = new QPushButton(rayWrox225Tab);
        worx225XRayOffButton_2->setObjectName(QStringLiteral("worx225XRayOffButton_2"));
        worx225XRayOffButton_2->setGeometry(QRect(288, 8, 60, 40));
        worx225XRayOffButton_2->setMinimumSize(QSize(60, 40));
        worx225XRayOffButton_2->setMaximumSize(QSize(60, 40));
        worx225kvStaticLabel_2 = new QLabel(rayWrox225Tab);
        worx225kvStaticLabel_2->setObjectName(QStringLiteral("worx225kvStaticLabel_2"));
        worx225kvStaticLabel_2->setGeometry(QRect(79, 7, 25, 18));
        worx225kvStaticLabel_2->setMinimumSize(QSize(25, 18));
        worx225kvStaticLabel_2->setMaximumSize(QSize(25, 18));
        worx225uaStaticLabel_2 = new QLabel(rayWrox225Tab);
        worx225uaStaticLabel_2->setObjectName(QStringLiteral("worx225uaStaticLabel_2"));
        worx225uaStaticLabel_2->setGeometry(QRect(176, 7, 25, 19));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(25);
        sizePolicy.setVerticalStretch(18);
        sizePolicy.setHeightForWidth(worx225uaStaticLabel_2->sizePolicy().hasHeightForWidth());
        worx225uaStaticLabel_2->setSizePolicy(sizePolicy);
        worx225uaStaticLabel_2->setMinimumSize(QSize(25, 18));
        worx225XRayOnButton_2 = new QPushButton(rayWrox225Tab);
        worx225XRayOnButton_2->setObjectName(QStringLiteral("worx225XRayOnButton_2"));
        worx225XRayOnButton_2->setGeometry(QRect(200, 8, 60, 40));
        worx225XRayOnButton_2->setMinimumSize(QSize(60, 40));
        worx225XRayOnButton_2->setMaximumSize(QSize(60, 40));
        worx225FocusComboBox_2 = new QComboBox(rayWrox225Tab);
        worx225FocusComboBox_2->setObjectName(QStringLiteral("worx225FocusComboBox_2"));
        worx225FocusComboBox_2->setGeometry(QRect(110, 32, 60, 20));
        worx225FocusComboBox_2->setMinimumSize(QSize(60, 20));
        worx225FocusComboBox_2->setMaximumSize(QSize(60, 20));
        worx225EmissionCurrentEdit_2 = new QLineEdit(rayWrox225Tab);
        worx225EmissionCurrentEdit_2->setObjectName(QStringLiteral("worx225EmissionCurrentEdit_2"));
        worx225EmissionCurrentEdit_2->setGeometry(QRect(110, 7, 60, 20));
        worx225EmissionCurrentEdit_2->setMinimumSize(QSize(60, 20));
        worx225EmissionCurrentEdit_2->setMaximumSize(QSize(60, 20));
        worx225VoltageInputEdit = new QLineEdit(rayWrox225Tab);
        worx225VoltageInputEdit->setObjectName(QStringLiteral("worx225VoltageInputEdit"));
        worx225VoltageInputEdit->setGeometry(QRect(13, 7, 60, 20));
        worx225VoltageInputEdit->setMinimumSize(QSize(60, 20));
        worx225VoltageInputEdit->setMaximumSize(QSize(60, 20));
        worx225FocusStaticLabel_2 = new QLabel(rayWrox225Tab);
        worx225FocusStaticLabel_2->setObjectName(QStringLiteral("worx225FocusStaticLabel_2"));
        worx225FocusStaticLabel_2->setGeometry(QRect(13, 32, 60, 18));
        rayTab->addTab(rayWrox225Tab, QString());
        rayComet450Tab = new QWidget();
        rayComet450Tab->setObjectName(QStringLiteral("rayComet450Tab"));
        Comet450uaStaticLabel = new QLabel(rayComet450Tab);
        Comet450uaStaticLabel->setObjectName(QStringLiteral("Comet450uaStaticLabel"));
        Comet450uaStaticLabel->setGeometry(QRect(120, 7, 25, 19));
        sizePolicy.setHeightForWidth(Comet450uaStaticLabel->sizePolicy().hasHeightForWidth());
        Comet450uaStaticLabel->setSizePolicy(sizePolicy);
        Comet450uaStaticLabel->setMinimumSize(QSize(25, 18));
        Comet450VoltageInputEdit = new QLineEdit(rayComet450Tab);
        Comet450VoltageInputEdit->setObjectName(QStringLiteral("Comet450VoltageInputEdit"));
        Comet450VoltageInputEdit->setGeometry(QRect(13, 7, 40, 20));
        Comet450VoltageInputEdit->setMinimumSize(QSize(40, 20));
        Comet450VoltageInputEdit->setMaximumSize(QSize(40, 20));
        Comet450kvStaticLabel = new QLabel(rayComet450Tab);
        Comet450kvStaticLabel->setObjectName(QStringLiteral("Comet450kvStaticLabel"));
        Comet450kvStaticLabel->setGeometry(QRect(60, 7, 25, 18));
        Comet450kvStaticLabel->setMinimumSize(QSize(25, 18));
        Comet450kvStaticLabel->setMaximumSize(QSize(25, 18));
        Comet450XRayOnButton = new QPushButton(rayComet450Tab);
        Comet450XRayOnButton->setObjectName(QStringLiteral("Comet450XRayOnButton"));
        Comet450XRayOnButton->setGeometry(QRect(210, 10, 60, 40));
        Comet450XRayOnButton->setMinimumSize(QSize(60, 40));
        Comet450XRayOnButton->setMaximumSize(QSize(60, 40));
        Comet450FocusStaticLabel = new QLabel(rayComet450Tab);
        Comet450FocusStaticLabel->setObjectName(QStringLiteral("Comet450FocusStaticLabel"));
        Comet450FocusStaticLabel->setGeometry(QRect(13, 32, 60, 18));
        Comet450FocusComboBox = new QComboBox(rayComet450Tab);
        Comet450FocusComboBox->setObjectName(QStringLiteral("Comet450FocusComboBox"));
        Comet450FocusComboBox->setGeometry(QRect(80, 32, 40, 20));
        Comet450FocusComboBox->setMinimumSize(QSize(40, 20));
        Comet450FocusComboBox->setMaximumSize(QSize(40, 20));
        Comet450EmissionCurrentEdit = new QLineEdit(rayComet450Tab);
        Comet450EmissionCurrentEdit->setObjectName(QStringLiteral("Comet450EmissionCurrentEdit"));
        Comet450EmissionCurrentEdit->setGeometry(QRect(80, 7, 40, 20));
        Comet450EmissionCurrentEdit->setMinimumSize(QSize(40, 20));
        Comet450EmissionCurrentEdit->setMaximumSize(QSize(40, 20));
        Comet450XRayOffButton = new QPushButton(rayComet450Tab);
        Comet450XRayOffButton->setObjectName(QStringLiteral("Comet450XRayOffButton"));
        Comet450XRayOffButton->setGeometry(QRect(140, 10, 60, 40));
        Comet450XRayOffButton->setMinimumSize(QSize(60, 40));
        Comet450XRayOffButton->setMaximumSize(QSize(60, 40));
        rayTab->addTab(rayComet450Tab, QString());

        gridLayout_4->addWidget(rayTab, 0, 0, 1, 4);

        fileNameEdit = new QLineEdit(widget);
        fileNameEdit->setObjectName(QStringLiteral("fileNameEdit"));
        fileNameEdit->setMinimumSize(QSize(0, 25));
        fileNameEdit->setMaximumSize(QSize(100, 25));

        gridLayout_4->addWidget(fileNameEdit, 1, 3, 1, 1);

        scanModeTab = new QTabWidget(widget);
        scanModeTab->setObjectName(QStringLiteral("scanModeTab"));
        scanModeTab->setMinimumSize(QSize(280, 280));
        scanModeTab->setMaximumSize(QSize(280, 280));
        ct3Tab = new QWidget();
        ct3Tab->setObjectName(QStringLiteral("ct3Tab"));
        layoutWidget = new QWidget(ct3Tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 252, 204));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(10);
        label_53 = new QLabel(layoutWidget);
        label_53->setObjectName(QStringLiteral("label_53"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_53->sizePolicy().hasHeightForWidth());
        label_53->setSizePolicy(sizePolicy1);
        label_53->setMinimumSize(QSize(54, 0));
        label_53->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_53, 0, 0, 1, 1);

        ct3MultiLayerComboBox = new QComboBox(layoutWidget);
        ct3MultiLayerComboBox->setObjectName(QStringLiteral("ct3MultiLayerComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ct3MultiLayerComboBox->sizePolicy().hasHeightForWidth());
        ct3MultiLayerComboBox->setSizePolicy(sizePolicy2);
        ct3MultiLayerComboBox->setMinimumSize(QSize(80, 0));
        ct3MultiLayerComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(ct3MultiLayerComboBox, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(54, 0));
        label->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        ct3MatrixComboBox = new QComboBox(layoutWidget);
        ct3MatrixComboBox->setObjectName(QStringLiteral("ct3MatrixComboBox"));
        sizePolicy2.setHeightForWidth(ct3MatrixComboBox->sizePolicy().hasHeightForWidth());
        ct3MatrixComboBox->setSizePolicy(sizePolicy2);
        ct3MatrixComboBox->setMinimumSize(QSize(80, 0));
        ct3MatrixComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(ct3MatrixComboBox, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(54, 0));
        label_2->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        ct3ViewComboBox = new QComboBox(layoutWidget);
        ct3ViewComboBox->setObjectName(QStringLiteral("ct3ViewComboBox"));
        sizePolicy2.setHeightForWidth(ct3ViewComboBox->sizePolicy().hasHeightForWidth());
        ct3ViewComboBox->setSizePolicy(sizePolicy2);
        ct3ViewComboBox->setMinimumSize(QSize(80, 0));
        ct3ViewComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(ct3ViewComboBox, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(54, 0));
        label_3->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        ct3SampleTimeComboBox = new QComboBox(layoutWidget);
        ct3SampleTimeComboBox->setObjectName(QStringLiteral("ct3SampleTimeComboBox"));
        sizePolicy2.setHeightForWidth(ct3SampleTimeComboBox->sizePolicy().hasHeightForWidth());
        ct3SampleTimeComboBox->setSizePolicy(sizePolicy2);
        ct3SampleTimeComboBox->setMinimumSize(QSize(80, 0));
        ct3SampleTimeComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(ct3SampleTimeComboBox, 3, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(54, 0));
        label_7->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        ct3AngleLineEdit = new QLineEdit(layoutWidget);
        ct3AngleLineEdit->setObjectName(QStringLiteral("ct3AngleLineEdit"));
        sizePolicy2.setHeightForWidth(ct3AngleLineEdit->sizePolicy().hasHeightForWidth());
        ct3AngleLineEdit->setSizePolicy(sizePolicy2);
        ct3AngleLineEdit->setMinimumSize(QSize(80, 0));
        ct3AngleLineEdit->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(ct3AngleLineEdit, 4, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(54, 0));
        label_8->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_8, 5, 0, 1, 1);

        ct3LayerPosLineEdit = new QLineEdit(layoutWidget);
        ct3LayerPosLineEdit->setObjectName(QStringLiteral("ct3LayerPosLineEdit"));
        sizePolicy2.setHeightForWidth(ct3LayerPosLineEdit->sizePolicy().hasHeightForWidth());
        ct3LayerPosLineEdit->setSizePolicy(sizePolicy2);
        ct3LayerPosLineEdit->setMinimumSize(QSize(80, 0));
        ct3LayerPosLineEdit->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(ct3LayerPosLineEdit, 5, 1, 1, 1);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(54, 0));
        label_17->setMaximumSize(QSize(54, 16777215));

        gridLayout_2->addWidget(label_17, 6, 0, 1, 1);

        ct3LayerSpaceLineEdit = new QLineEdit(layoutWidget);
        ct3LayerSpaceLineEdit->setObjectName(QStringLiteral("ct3LayerSpaceLineEdit"));
        sizePolicy2.setHeightForWidth(ct3LayerSpaceLineEdit->sizePolicy().hasHeightForWidth());
        ct3LayerSpaceLineEdit->setSizePolicy(sizePolicy2);
        ct3LayerSpaceLineEdit->setMinimumSize(QSize(80, 0));
        ct3LayerSpaceLineEdit->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(ct3LayerSpaceLineEdit, 6, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ct3LayerPosListWidget = new QListWidget(layoutWidget);
        ct3LayerPosListWidget->setObjectName(QStringLiteral("ct3LayerPosListWidget"));
        ct3LayerPosListWidget->setMinimumSize(QSize(100, 130));
        ct3LayerPosListWidget->setMaximumSize(QSize(100, 130));

        verticalLayout->addWidget(ct3LayerPosListWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);

        scanModeTab->addTab(ct3Tab, QString());
        ct2Tab = new QWidget();
        ct2Tab->setObjectName(QStringLiteral("ct2Tab"));
        layoutWidget1 = new QWidget(ct2Tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 10, 142, 172));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(10);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_41 = new QLabel(layoutWidget1);
        label_41->setObjectName(QStringLiteral("label_41"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy3);
        label_41->setMinimumSize(QSize(54, 0));
        label_41->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_41, 0, 0, 1, 1);

        drRatioComboBox = new QComboBox(layoutWidget1);
        drRatioComboBox->setObjectName(QStringLiteral("drRatioComboBox"));
        drRatioComboBox->setMinimumSize(QSize(80, 0));
        drRatioComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(drRatioComboBox, 0, 1, 1, 1);

        label_34 = new QLabel(layoutWidget1);
        label_34->setObjectName(QStringLiteral("label_34"));
        sizePolicy3.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy3);
        label_34->setMinimumSize(QSize(54, 0));
        label_34->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_34, 1, 0, 1, 1);

        drMatrixComboBox = new QComboBox(layoutWidget1);
        drMatrixComboBox->setObjectName(QStringLiteral("drMatrixComboBox"));
        drMatrixComboBox->setMinimumSize(QSize(80, 0));
        drMatrixComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(drMatrixComboBox, 1, 1, 1, 1);

        label_35 = new QLabel(layoutWidget1);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy3.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy3);
        label_35->setMinimumSize(QSize(54, 0));
        label_35->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_35, 2, 0, 1, 1);

        drViewComboBox = new QComboBox(layoutWidget1);
        drViewComboBox->setObjectName(QStringLiteral("drViewComboBox"));
        drViewComboBox->setMinimumSize(QSize(80, 0));
        drViewComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(drViewComboBox, 2, 1, 1, 1);

        label_36 = new QLabel(layoutWidget1);
        label_36->setObjectName(QStringLiteral("label_36"));
        sizePolicy3.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy3);
        label_36->setMinimumSize(QSize(54, 0));
        label_36->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_36, 3, 0, 1, 1);

        drSampleTimeComboBox = new QComboBox(layoutWidget1);
        drSampleTimeComboBox->setObjectName(QStringLiteral("drSampleTimeComboBox"));
        drSampleTimeComboBox->setMinimumSize(QSize(80, 0));
        drSampleTimeComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(drSampleTimeComboBox, 3, 1, 1, 1);

        label_37 = new QLabel(layoutWidget1);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy3.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy3);
        label_37->setMinimumSize(QSize(54, 0));
        label_37->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_37, 4, 0, 1, 1);

        drAngleLineEdit = new QLineEdit(layoutWidget1);
        drAngleLineEdit->setObjectName(QStringLiteral("drAngleLineEdit"));
        drAngleLineEdit->setMinimumSize(QSize(80, 0));
        drAngleLineEdit->setMaximumSize(QSize(80, 16777215));
        drAngleLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(drAngleLineEdit, 4, 1, 1, 1);

        label_38 = new QLabel(layoutWidget1);
        label_38->setObjectName(QStringLiteral("label_38"));
        sizePolicy3.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy3);
        label_38->setMinimumSize(QSize(54, 0));
        label_38->setMaximumSize(QSize(54, 16777215));

        gridLayout_3->addWidget(label_38, 5, 0, 1, 1);

        lineEdit_14 = new QLineEdit(layoutWidget1);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy4);
        lineEdit_14->setMinimumSize(QSize(80, 0));
        lineEdit_14->setMaximumSize(QSize(80, 16777215));
        lineEdit_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(lineEdit_14, 5, 1, 1, 1);

        scanModeTab->addTab(ct2Tab, QString());
        drTab = new QWidget();
        drTab->setObjectName(QStringLiteral("drTab"));
        layoutWidget2 = new QWidget(drTab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 252, 241));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(10);
        label_40 = new QLabel(layoutWidget2);
        label_40->setObjectName(QStringLiteral("label_40"));
        sizePolicy1.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy1);
        label_40->setMinimumSize(QSize(54, 0));
        label_40->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_40, 0, 0, 1, 1);

        ct2ScanModeComboBox = new QComboBox(layoutWidget2);
        ct2ScanModeComboBox->setObjectName(QStringLiteral("ct2ScanModeComboBox"));
        sizePolicy2.setHeightForWidth(ct2ScanModeComboBox->sizePolicy().hasHeightForWidth());
        ct2ScanModeComboBox->setSizePolicy(sizePolicy2);
        ct2ScanModeComboBox->setMinimumSize(QSize(80, 0));
        ct2ScanModeComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(ct2ScanModeComboBox, 0, 1, 1, 1);

        label_39 = new QLabel(layoutWidget2);
        label_39->setObjectName(QStringLiteral("label_39"));
        sizePolicy1.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy1);
        label_39->setMinimumSize(QSize(54, 0));
        label_39->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_39, 1, 0, 1, 1);

        ct2MultiLayerComboBox = new QComboBox(layoutWidget2);
        ct2MultiLayerComboBox->setObjectName(QStringLiteral("ct2MultiLayerComboBox"));
        sizePolicy2.setHeightForWidth(ct2MultiLayerComboBox->sizePolicy().hasHeightForWidth());
        ct2MultiLayerComboBox->setSizePolicy(sizePolicy2);
        ct2MultiLayerComboBox->setMinimumSize(QSize(80, 0));
        ct2MultiLayerComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(ct2MultiLayerComboBox, 1, 1, 1, 1);

        label_31 = new QLabel(layoutWidget2);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy1.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy1);
        label_31->setMinimumSize(QSize(54, 0));
        label_31->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_31, 2, 0, 1, 1);

        ct2MatrixComboBox = new QComboBox(layoutWidget2);
        ct2MatrixComboBox->setObjectName(QStringLiteral("ct2MatrixComboBox"));
        sizePolicy2.setHeightForWidth(ct2MatrixComboBox->sizePolicy().hasHeightForWidth());
        ct2MatrixComboBox->setSizePolicy(sizePolicy2);
        ct2MatrixComboBox->setMinimumSize(QSize(80, 0));
        ct2MatrixComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(ct2MatrixComboBox, 2, 1, 1, 1);

        label_30 = new QLabel(layoutWidget2);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy1.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy1);
        label_30->setMinimumSize(QSize(54, 0));
        label_30->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_30, 3, 0, 1, 1);

        ct2ViewComboBox = new QComboBox(layoutWidget2);
        ct2ViewComboBox->setObjectName(QStringLiteral("ct2ViewComboBox"));
        sizePolicy2.setHeightForWidth(ct2ViewComboBox->sizePolicy().hasHeightForWidth());
        ct2ViewComboBox->setSizePolicy(sizePolicy2);
        ct2ViewComboBox->setMinimumSize(QSize(80, 0));
        ct2ViewComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(ct2ViewComboBox, 3, 1, 1, 1);

        label_33 = new QLabel(layoutWidget2);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy1.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy1);
        label_33->setMinimumSize(QSize(54, 0));
        label_33->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_33, 4, 0, 1, 1);

        ct2SampleTimeComboBox = new QComboBox(layoutWidget2);
        ct2SampleTimeComboBox->setObjectName(QStringLiteral("ct2SampleTimeComboBox"));
        sizePolicy2.setHeightForWidth(ct2SampleTimeComboBox->sizePolicy().hasHeightForWidth());
        ct2SampleTimeComboBox->setSizePolicy(sizePolicy2);
        ct2SampleTimeComboBox->setMinimumSize(QSize(80, 0));
        ct2SampleTimeComboBox->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(ct2SampleTimeComboBox, 4, 1, 1, 1);

        label_32 = new QLabel(layoutWidget2);
        label_32->setObjectName(QStringLiteral("label_32"));
        sizePolicy1.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy1);
        label_32->setMinimumSize(QSize(54, 0));
        label_32->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_32, 5, 0, 1, 1);

        lineEdit_11 = new QLineEdit(layoutWidget2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        sizePolicy2.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy2);
        lineEdit_11->setMinimumSize(QSize(80, 0));
        lineEdit_11->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_11, 5, 1, 1, 1);

        label_29 = new QLabel(layoutWidget2);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy1.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy1);
        label_29->setMinimumSize(QSize(54, 0));
        label_29->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_29, 6, 0, 1, 1);

        lineEdit_12 = new QLineEdit(layoutWidget2);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        sizePolicy2.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy2);
        lineEdit_12->setMinimumSize(QSize(80, 0));
        lineEdit_12->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_12, 6, 1, 1, 1);

        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);
        label_18->setMinimumSize(QSize(54, 0));
        label_18->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_18, 7, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);
        lineEdit_7->setMinimumSize(QSize(80, 0));
        lineEdit_7->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_7, 7, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ct2LayerPosListWidget = new QListWidget(layoutWidget2);
        ct2LayerPosListWidget->setObjectName(QStringLiteral("ct2LayerPosListWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(ct2LayerPosListWidget->sizePolicy().hasHeightForWidth());
        ct2LayerPosListWidget->setSizePolicy(sizePolicy5);
        ct2LayerPosListWidget->setMinimumSize(QSize(100, 130));
        ct2LayerPosListWidget->setMaximumSize(QSize(100, 130));

        verticalLayout_2->addWidget(ct2LayerPosListWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);

        scanModeTab->addTab(drTab, QString());

        gridLayout_4->addWidget(scanModeTab, 2, 0, 1, 4);

        saveDirButton = new QPushButton(widget);
        saveDirButton->setObjectName(QStringLiteral("saveDirButton"));
        saveDirButton->setMinimumSize(QSize(30, 25));
        saveDirButton->setMaximumSize(QSize(80, 25));

        gridLayout_4->addWidget(saveDirButton, 1, 0, 1, 1);

        allProgressBar = new QProgressBar(widget);
        allProgressBar->setObjectName(QStringLiteral("allProgressBar"));
        sizePolicy2.setHeightForWidth(allProgressBar->sizePolicy().hasHeightForWidth());
        allProgressBar->setSizePolicy(sizePolicy2);
        allProgressBar->setAutoFillBackground(false);
        allProgressBar->setValue(24);
        allProgressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(allProgressBar, 4, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stopButton = new QPushButton(widget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(stopButton);


        gridLayout_4->addLayout(horizontalLayout, 5, 3, 1, 1);

        nowProgressBar = new QProgressBar(widget);
        nowProgressBar->setObjectName(QStringLiteral("nowProgressBar"));
        sizePolicy2.setHeightForWidth(nowProgressBar->sizePolicy().hasHeightForWidth());
        nowProgressBar->setSizePolicy(sizePolicy2);
        nowProgressBar->setMinimumSize(QSize(100, 0));
        nowProgressBar->setAutoFillBackground(false);
        nowProgressBar->setValue(24);
        nowProgressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(nowProgressBar, 3, 3, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 3, 0, 1, 1);

        startButton = new QPushButton(widget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(startButton, 5, 0, 1, 3);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 1, 1, 1);


        retranslateUi(LineDetScanWidget);

        rayTab->setCurrentIndex(0);
        scanModeTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LineDetScanWidget);
    } // setupUi

    void retranslateUi(QWidget *LineDetScanWidget)
    {
        LineDetScanWidget->setWindowTitle(QString());
        label_5->setText(QApplication::translate("LineDetScanWidget", "\346\200\273\344\275\223\350\277\233\345\272\246", nullptr));
        worx225XRayOffButton_2->setText(QApplication::translate("LineDetScanWidget", "\345\201\234\346\235\237", nullptr));
        worx225kvStaticLabel_2->setText(QApplication::translate("LineDetScanWidget", "KV", nullptr));
        worx225uaStaticLabel_2->setText(QApplication::translate("LineDetScanWidget", "\316\274A", nullptr));
        worx225XRayOnButton_2->setText(QApplication::translate("LineDetScanWidget", "\345\207\272\346\235\237", nullptr));
        worx225FocusStaticLabel_2->setText(QApplication::translate("LineDetScanWidget", "\347\204\246\347\202\271", nullptr));
        rayTab->setTabText(rayTab->indexOf(rayWrox225Tab), QApplication::translate("LineDetScanWidget", "WROX", nullptr));
        Comet450uaStaticLabel->setText(QApplication::translate("LineDetScanWidget", "\316\274A", nullptr));
        Comet450kvStaticLabel->setText(QApplication::translate("LineDetScanWidget", "KV", nullptr));
        Comet450XRayOnButton->setText(QApplication::translate("LineDetScanWidget", "\345\207\272\346\235\237", nullptr));
        Comet450FocusStaticLabel->setText(QApplication::translate("LineDetScanWidget", "\347\204\246\347\202\271", nullptr));
        Comet450XRayOffButton->setText(QApplication::translate("LineDetScanWidget", "\345\201\234\346\235\237", nullptr));
        rayTab->setTabText(rayTab->indexOf(rayComet450Tab), QApplication::translate("LineDetScanWidget", "COMET", nullptr));
        label_53->setText(QApplication::translate("LineDetScanWidget", "\345\275\223\345\211\215/\345\244\232\345\261\202", nullptr));
        label->setText(QApplication::translate("LineDetScanWidget", "\345\233\276\345\203\217\347\237\251\351\230\265", nullptr));
        label_2->setText(QApplication::translate("LineDetScanWidget", "\350\247\206\345\234\272\347\233\264\345\276\204", nullptr));
        label_3->setText(QApplication::translate("LineDetScanWidget", "\351\207\207\346\240\267\346\227\266\351\227\264", nullptr));
        label_7->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\344\275\215", nullptr));
        label_8->setText(QApplication::translate("LineDetScanWidget", "\346\226\255\345\261\202\344\275\215\347\275\256", nullptr));
        label_17->setText(QApplication::translate("LineDetScanWidget", "\345\261\202\351\227\264\350\267\235", nullptr));
        scanModeTab->setTabText(scanModeTab->indexOf(ct3Tab), QApplication::translate("LineDetScanWidget", "\344\270\211\344\273\243CT", nullptr));
        label_41->setText(QApplication::translate("LineDetScanWidget", "\346\257\224\344\276\213\346\250\241\345\274\217", nullptr));
        label_34->setText(QApplication::translate("LineDetScanWidget", "\345\233\276\345\203\217\347\237\251\351\230\265", nullptr));
        label_35->setText(QApplication::translate("LineDetScanWidget", "\350\247\206\345\234\272\347\233\264\345\276\204", nullptr));
        label_36->setText(QApplication::translate("LineDetScanWidget", "\351\207\207\346\240\267\346\227\266\351\227\264", nullptr));
        label_37->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\344\275\215", nullptr));
        label_38->setText(QApplication::translate("LineDetScanWidget", "\346\226\255\345\261\202\344\275\215\347\275\256", nullptr));
        scanModeTab->setTabText(scanModeTab->indexOf(ct2Tab), QApplication::translate("LineDetScanWidget", "DR", nullptr));
        label_40->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\345\274\217", nullptr));
        label_39->setText(QApplication::translate("LineDetScanWidget", "\345\275\223\345\211\215/\345\244\232\345\261\202", nullptr));
        label_31->setText(QApplication::translate("LineDetScanWidget", "\345\233\276\345\203\217\347\237\251\351\230\265", nullptr));
        label_30->setText(QApplication::translate("LineDetScanWidget", "\350\247\206\345\234\272\347\233\264\345\276\204", nullptr));
        label_33->setText(QApplication::translate("LineDetScanWidget", "\351\207\207\346\240\267\346\227\266\351\227\264", nullptr));
        label_32->setText(QApplication::translate("LineDetScanWidget", "\346\211\253\346\217\217\346\226\271\344\275\215", nullptr));
        label_29->setText(QApplication::translate("LineDetScanWidget", "\346\226\255\345\261\202\344\275\215\347\275\256", nullptr));
        label_18->setText(QApplication::translate("LineDetScanWidget", "\345\261\202\351\227\264\350\267\235", nullptr));
        scanModeTab->setTabText(scanModeTab->indexOf(drTab), QApplication::translate("LineDetScanWidget", "\344\272\214\344\273\243CT", nullptr));
        saveDirButton->setText(QApplication::translate("LineDetScanWidget", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        stopButton->setText(QApplication::translate("LineDetScanWidget", "\345\201\234\346\255\242", nullptr));
        label_4->setText(QApplication::translate("LineDetScanWidget", "\345\275\223\345\211\215\350\277\233\345\272\246", nullptr));
        startButton->setText(QApplication::translate("LineDetScanWidget", "\345\274\200\345\247\213", nullptr));
        label_6->setText(QApplication::translate("LineDetScanWidget", "\346\226\207\344\273\266\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineDetScanWidget: public Ui_LineDetScanWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEDETSCANWIDGET_H
