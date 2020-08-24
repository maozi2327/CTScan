/********************************************************************************
** Form generated from reading UI file 'conescanwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONESCANWIDGET_H
#define UI_CONESCANWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConeScanWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *sampleTimeStaticLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *sampleTimeEdit;
    QLabel *gainStaticLabel;
    QComboBox *gainGroupBox;
    QLabel *singleShotFramesStaticLabel;
    QComboBox *singleShotFramesComboBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *bkgTuneCheckBox;
    QCheckBox *airTuneCheckBox;
    QCheckBox *defectTuneCheckBox;
    QCheckBox *averageCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bkgTuneButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *airTuneButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *singleShotButton;
    QPushButton *pushButton_3;
    QTabWidget *tabWidget;
    QWidget *coneScanTab;
    QGridLayout *gridLayout;
    QPushButton *coneScanSaveDirButton;
    QLineEdit *coneScanFileNameEdit;
    QPushButton *coneScanLeakSamplePushButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *coneScanGraduationStaticLabel;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *coneScanMatrixComboBox;
    QLabel *coneScanFramesStaticLabel;
    QComboBox *coneScanframesComboBox;
    QLabel *coneScanFrameAverageStaticLabel;
    QSpinBox *coneScanFrameAverageSpinBox;
    QLabel *coneScanProgressStaticLabel;
    QProgressBar *coneScanAllProgressBar;
    QPushButton *coneScanBeginSampleButton;
    QPushButton *pushButton_2;
    QWidget *coneJointRotScanTab;
    QGridLayout *gridLayout_2;
    QComboBox *coneJointRotScanframesComboBox;
    QLabel *coneJointRotScanFramesStaticLabel;
    QLineEdit *coneJointRotScanfileNameEdit;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *coneJointRotScanleakSamplePushButton;
    QLabel *coneJointRotScanProgressStaticLabel;
    QPushButton *coneJointRotScanBeginSampleButton;
    QSpinBox *coneJointRotScanFrameAverageSpinBox;
    QComboBox *coneJointRotScanMatrixComboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *coneJointRotScanFrameAverageStaticLabel;
    QPushButton *coneJointRotScanSaveDirButton;
    QLabel *coneJointRotScanGraduationStaticLabel;
    QPushButton *pushButton;
    QProgressBar *coneJointRotScanProgressBar;
    QProgressBar *coneJointRotScanAllProgressBar;

    void setupUi(QWidget *ConeScanWidget)
    {
        if (ConeScanWidget->objectName().isEmpty())
            ConeScanWidget->setObjectName(QStringLiteral("ConeScanWidget"));
        ConeScanWidget->resize(300, 566);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConeScanWidget->sizePolicy().hasHeightForWidth());
        ConeScanWidget->setSizePolicy(sizePolicy);
        ConeScanWidget->setMinimumSize(QSize(300, 470));
        ConeScanWidget->setMaximumSize(QSize(300, 1000));
        ConeScanWidget->setAcceptDrops(false);
        layoutWidget = new QWidget(ConeScanWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(23, 25, 252, 499));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        sampleTimeStaticLabel = new QLabel(layoutWidget);
        sampleTimeStaticLabel->setObjectName(QStringLiteral("sampleTimeStaticLabel"));
        sampleTimeStaticLabel->setMinimumSize(QSize(60, 16));
        sampleTimeStaticLabel->setMaximumSize(QSize(60, 16));

        gridLayout_3->addWidget(sampleTimeStaticLabel, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        sampleTimeEdit = new QLineEdit(layoutWidget);
        sampleTimeEdit->setObjectName(QStringLiteral("sampleTimeEdit"));
        sampleTimeEdit->setMinimumSize(QSize(80, 20));
        sampleTimeEdit->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(sampleTimeEdit, 0, 2, 1, 1);

        gainStaticLabel = new QLabel(layoutWidget);
        gainStaticLabel->setObjectName(QStringLiteral("gainStaticLabel"));
        gainStaticLabel->setMinimumSize(QSize(30, 16));
        gainStaticLabel->setMaximumSize(QSize(30, 16));

        gridLayout_3->addWidget(gainStaticLabel, 1, 0, 1, 1);

        gainGroupBox = new QComboBox(layoutWidget);
        gainGroupBox->setObjectName(QStringLiteral("gainGroupBox"));
        gainGroupBox->setMinimumSize(QSize(80, 20));
        gainGroupBox->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(gainGroupBox, 1, 2, 1, 1);

        singleShotFramesStaticLabel = new QLabel(layoutWidget);
        singleShotFramesStaticLabel->setObjectName(QStringLiteral("singleShotFramesStaticLabel"));
        singleShotFramesStaticLabel->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(singleShotFramesStaticLabel, 2, 0, 1, 1);

        singleShotFramesComboBox = new QComboBox(layoutWidget);
        singleShotFramesComboBox->setObjectName(QStringLiteral("singleShotFramesComboBox"));
        singleShotFramesComboBox->setMinimumSize(QSize(80, 0));
        singleShotFramesComboBox->setMaximumSize(QSize(80, 16777215));
        singleShotFramesComboBox->setInputMethodHints(Qt::ImhNone);
        singleShotFramesComboBox->setEditable(true);

        gridLayout_3->addWidget(singleShotFramesComboBox, 2, 2, 1, 1);

        gridLayout_3->setColumnStretch(1, 1);

        verticalLayout->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bkgTuneCheckBox = new QCheckBox(layoutWidget);
        bkgTuneCheckBox->setObjectName(QStringLiteral("bkgTuneCheckBox"));

        horizontalLayout->addWidget(bkgTuneCheckBox);

        airTuneCheckBox = new QCheckBox(layoutWidget);
        airTuneCheckBox->setObjectName(QStringLiteral("airTuneCheckBox"));

        horizontalLayout->addWidget(airTuneCheckBox);

        defectTuneCheckBox = new QCheckBox(layoutWidget);
        defectTuneCheckBox->setObjectName(QStringLiteral("defectTuneCheckBox"));

        horizontalLayout->addWidget(defectTuneCheckBox);

        averageCheckBox = new QCheckBox(layoutWidget);
        averageCheckBox->setObjectName(QStringLiteral("averageCheckBox"));

        horizontalLayout->addWidget(averageCheckBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bkgTuneButton = new QPushButton(layoutWidget);
        bkgTuneButton->setObjectName(QStringLiteral("bkgTuneButton"));
        bkgTuneButton->setMinimumSize(QSize(60, 30));
        bkgTuneButton->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(bkgTuneButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        airTuneButton = new QPushButton(layoutWidget);
        airTuneButton->setObjectName(QStringLiteral("airTuneButton"));
        airTuneButton->setMinimumSize(QSize(60, 30));
        airTuneButton->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(airTuneButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        singleShotButton = new QPushButton(layoutWidget);
        singleShotButton->setObjectName(QStringLiteral("singleShotButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(singleShotButton->sizePolicy().hasHeightForWidth());
        singleShotButton->setSizePolicy(sizePolicy1);
        singleShotButton->setMinimumSize(QSize(150, 30));
        singleShotButton->setMaximumSize(QSize(300, 30));

        horizontalLayout_3->addWidget(singleShotButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));
        pushButton_3->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(80, 0));
        tabWidget->setMaximumSize(QSize(250, 500));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        coneScanTab = new QWidget();
        coneScanTab->setObjectName(QStringLiteral("coneScanTab"));
        gridLayout = new QGridLayout(coneScanTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        coneScanSaveDirButton = new QPushButton(coneScanTab);
        coneScanSaveDirButton->setObjectName(QStringLiteral("coneScanSaveDirButton"));
        coneScanSaveDirButton->setMinimumSize(QSize(60, 25));
        coneScanSaveDirButton->setMaximumSize(QSize(60, 25));

        gridLayout->addWidget(coneScanSaveDirButton, 0, 0, 1, 1);

        coneScanFileNameEdit = new QLineEdit(coneScanTab);
        coneScanFileNameEdit->setObjectName(QStringLiteral("coneScanFileNameEdit"));
        coneScanFileNameEdit->setMinimumSize(QSize(0, 25));
        coneScanFileNameEdit->setMaximumSize(QSize(1000, 25));

        gridLayout->addWidget(coneScanFileNameEdit, 0, 1, 1, 3);

        coneScanLeakSamplePushButton = new QPushButton(coneScanTab);
        coneScanLeakSamplePushButton->setObjectName(QStringLiteral("coneScanLeakSamplePushButton"));
        coneScanLeakSamplePushButton->setMinimumSize(QSize(60, 25));
        coneScanLeakSamplePushButton->setMaximumSize(QSize(60, 25));

        gridLayout->addWidget(coneScanLeakSamplePushButton, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 3);

        coneScanGraduationStaticLabel = new QLabel(coneScanTab);
        coneScanGraduationStaticLabel->setObjectName(QStringLiteral("coneScanGraduationStaticLabel"));
        coneScanGraduationStaticLabel->setMinimumSize(QSize(0, 25));
        coneScanGraduationStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanGraduationStaticLabel, 2, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 1, 1, 1);

        coneScanMatrixComboBox = new QComboBox(coneScanTab);
        coneScanMatrixComboBox->setObjectName(QStringLiteral("coneScanMatrixComboBox"));
        coneScanMatrixComboBox->setMinimumSize(QSize(80, 0));
        coneScanMatrixComboBox->setMaximumSize(QSize(80, 16777215));
        coneScanMatrixComboBox->setInputMethodHints(Qt::ImhNone);
        coneScanMatrixComboBox->setEditable(true);

        gridLayout->addWidget(coneScanMatrixComboBox, 2, 2, 1, 2);

        coneScanFramesStaticLabel = new QLabel(coneScanTab);
        coneScanFramesStaticLabel->setObjectName(QStringLiteral("coneScanFramesStaticLabel"));
        coneScanFramesStaticLabel->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(coneScanFramesStaticLabel, 3, 0, 1, 1);

        coneScanframesComboBox = new QComboBox(coneScanTab);
        coneScanframesComboBox->setObjectName(QStringLiteral("coneScanframesComboBox"));
        coneScanframesComboBox->setMinimumSize(QSize(80, 0));
        coneScanframesComboBox->setMaximumSize(QSize(80, 16777215));
        coneScanframesComboBox->setInputMethodHints(Qt::ImhNone);
        coneScanframesComboBox->setEditable(true);

        gridLayout->addWidget(coneScanframesComboBox, 3, 2, 1, 2);

        coneScanFrameAverageStaticLabel = new QLabel(coneScanTab);
        coneScanFrameAverageStaticLabel->setObjectName(QStringLiteral("coneScanFrameAverageStaticLabel"));
        coneScanFrameAverageStaticLabel->setMinimumSize(QSize(0, 25));
        coneScanFrameAverageStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanFrameAverageStaticLabel, 4, 0, 1, 1);

        coneScanFrameAverageSpinBox = new QSpinBox(coneScanTab);
        coneScanFrameAverageSpinBox->setObjectName(QStringLiteral("coneScanFrameAverageSpinBox"));
        coneScanFrameAverageSpinBox->setMinimumSize(QSize(80, 25));
        coneScanFrameAverageSpinBox->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(coneScanFrameAverageSpinBox, 4, 2, 1, 2);

        coneScanProgressStaticLabel = new QLabel(coneScanTab);
        coneScanProgressStaticLabel->setObjectName(QStringLiteral("coneScanProgressStaticLabel"));
        coneScanProgressStaticLabel->setMinimumSize(QSize(0, 15));
        coneScanProgressStaticLabel->setMaximumSize(QSize(1000, 15));
        coneScanProgressStaticLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(coneScanProgressStaticLabel, 5, 0, 1, 1);

        coneScanAllProgressBar = new QProgressBar(coneScanTab);
        coneScanAllProgressBar->setObjectName(QStringLiteral("coneScanAllProgressBar"));
        coneScanAllProgressBar->setValue(24);
        coneScanAllProgressBar->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(coneScanAllProgressBar, 6, 0, 1, 4);

        coneScanBeginSampleButton = new QPushButton(coneScanTab);
        coneScanBeginSampleButton->setObjectName(QStringLiteral("coneScanBeginSampleButton"));
        coneScanBeginSampleButton->setMinimumSize(QSize(150, 50));
        coneScanBeginSampleButton->setMaximumSize(QSize(150, 50));

        gridLayout->addWidget(coneScanBeginSampleButton, 7, 0, 1, 3);

        pushButton_2 = new QPushButton(coneScanTab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_2, 7, 3, 1, 1);

        tabWidget->addTab(coneScanTab, QString());
        coneJointRotScanTab = new QWidget();
        coneJointRotScanTab->setObjectName(QStringLiteral("coneJointRotScanTab"));
        gridLayout_2 = new QGridLayout(coneJointRotScanTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        coneJointRotScanframesComboBox = new QComboBox(coneJointRotScanTab);
        coneJointRotScanframesComboBox->setObjectName(QStringLiteral("coneJointRotScanframesComboBox"));
        coneJointRotScanframesComboBox->setMinimumSize(QSize(80, 0));
        coneJointRotScanframesComboBox->setMaximumSize(QSize(80, 16777215));
        coneJointRotScanframesComboBox->setInputMethodHints(Qt::ImhNone);
        coneJointRotScanframesComboBox->setEditable(true);

        gridLayout_2->addWidget(coneJointRotScanframesComboBox, 3, 2, 1, 2);

        coneJointRotScanFramesStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanFramesStaticLabel->setObjectName(QStringLiteral("coneJointRotScanFramesStaticLabel"));
        coneJointRotScanFramesStaticLabel->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(coneJointRotScanFramesStaticLabel, 3, 0, 1, 1);

        coneJointRotScanfileNameEdit = new QLineEdit(coneJointRotScanTab);
        coneJointRotScanfileNameEdit->setObjectName(QStringLiteral("coneJointRotScanfileNameEdit"));
        coneJointRotScanfileNameEdit->setMinimumSize(QSize(0, 25));
        coneJointRotScanfileNameEdit->setMaximumSize(QSize(1000, 25));

        gridLayout_2->addWidget(coneJointRotScanfileNameEdit, 0, 1, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 1, 1, 1);

        coneJointRotScanleakSamplePushButton = new QPushButton(coneJointRotScanTab);
        coneJointRotScanleakSamplePushButton->setObjectName(QStringLiteral("coneJointRotScanleakSamplePushButton"));
        coneJointRotScanleakSamplePushButton->setMinimumSize(QSize(60, 25));
        coneJointRotScanleakSamplePushButton->setMaximumSize(QSize(60, 25));

        gridLayout_2->addWidget(coneJointRotScanleakSamplePushButton, 1, 0, 1, 1);

        coneJointRotScanProgressStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanProgressStaticLabel->setObjectName(QStringLiteral("coneJointRotScanProgressStaticLabel"));
        coneJointRotScanProgressStaticLabel->setMinimumSize(QSize(0, 15));
        coneJointRotScanProgressStaticLabel->setFrameShape(QFrame::Box);

        gridLayout_2->addWidget(coneJointRotScanProgressStaticLabel, 5, 0, 1, 1);

        coneJointRotScanBeginSampleButton = new QPushButton(coneJointRotScanTab);
        coneJointRotScanBeginSampleButton->setObjectName(QStringLiteral("coneJointRotScanBeginSampleButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(coneJointRotScanBeginSampleButton->sizePolicy().hasHeightForWidth());
        coneJointRotScanBeginSampleButton->setSizePolicy(sizePolicy3);
        coneJointRotScanBeginSampleButton->setMinimumSize(QSize(150, 50));
        coneJointRotScanBeginSampleButton->setMaximumSize(QSize(150, 50));

        gridLayout_2->addWidget(coneJointRotScanBeginSampleButton, 8, 0, 1, 3);

        coneJointRotScanFrameAverageSpinBox = new QSpinBox(coneJointRotScanTab);
        coneJointRotScanFrameAverageSpinBox->setObjectName(QStringLiteral("coneJointRotScanFrameAverageSpinBox"));
        coneJointRotScanFrameAverageSpinBox->setMinimumSize(QSize(80, 25));
        coneJointRotScanFrameAverageSpinBox->setMaximumSize(QSize(80, 25));

        gridLayout_2->addWidget(coneJointRotScanFrameAverageSpinBox, 4, 2, 1, 2);

        coneJointRotScanMatrixComboBox = new QComboBox(coneJointRotScanTab);
        coneJointRotScanMatrixComboBox->setObjectName(QStringLiteral("coneJointRotScanMatrixComboBox"));
        coneJointRotScanMatrixComboBox->setMinimumSize(QSize(80, 0));
        coneJointRotScanMatrixComboBox->setMaximumSize(QSize(80, 16777215));
        coneJointRotScanMatrixComboBox->setInputMethodHints(Qt::ImhNone);
        coneJointRotScanMatrixComboBox->setEditable(true);

        gridLayout_2->addWidget(coneJointRotScanMatrixComboBox, 2, 2, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 3);

        coneJointRotScanFrameAverageStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanFrameAverageStaticLabel->setObjectName(QStringLiteral("coneJointRotScanFrameAverageStaticLabel"));
        coneJointRotScanFrameAverageStaticLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanFrameAverageStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanFrameAverageStaticLabel, 4, 0, 1, 1);

        coneJointRotScanSaveDirButton = new QPushButton(coneJointRotScanTab);
        coneJointRotScanSaveDirButton->setObjectName(QStringLiteral("coneJointRotScanSaveDirButton"));
        coneJointRotScanSaveDirButton->setMinimumSize(QSize(60, 25));
        coneJointRotScanSaveDirButton->setMaximumSize(QSize(60, 25));

        gridLayout_2->addWidget(coneJointRotScanSaveDirButton, 0, 0, 1, 1);

        coneJointRotScanGraduationStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanGraduationStaticLabel->setObjectName(QStringLiteral("coneJointRotScanGraduationStaticLabel"));
        coneJointRotScanGraduationStaticLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanGraduationStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanGraduationStaticLabel, 2, 0, 1, 1);

        pushButton = new QPushButton(coneJointRotScanTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(pushButton, 8, 3, 1, 1);

        coneJointRotScanProgressBar = new QProgressBar(coneJointRotScanTab);
        coneJointRotScanProgressBar->setObjectName(QStringLiteral("coneJointRotScanProgressBar"));
        coneJointRotScanProgressBar->setValue(24);

        gridLayout_2->addWidget(coneJointRotScanProgressBar, 6, 0, 1, 4);

        coneJointRotScanAllProgressBar = new QProgressBar(coneJointRotScanTab);
        coneJointRotScanAllProgressBar->setObjectName(QStringLiteral("coneJointRotScanAllProgressBar"));
        coneJointRotScanAllProgressBar->setValue(24);

        gridLayout_2->addWidget(coneJointRotScanAllProgressBar, 7, 0, 1, 4);

        tabWidget->addTab(coneJointRotScanTab, QString());
        coneJointRotScanSaveDirButton->raise();
        coneJointRotScanfileNameEdit->raise();
        coneJointRotScanleakSamplePushButton->raise();
        coneJointRotScanBeginSampleButton->raise();
        coneJointRotScanGraduationStaticLabel->raise();
        coneJointRotScanMatrixComboBox->raise();
        coneJointRotScanFrameAverageStaticLabel->raise();
        coneJointRotScanFrameAverageSpinBox->raise();
        coneJointRotScanFramesStaticLabel->raise();
        coneJointRotScanframesComboBox->raise();
        pushButton->raise();
        coneJointRotScanProgressBar->raise();
        coneJointRotScanAllProgressBar->raise();
        coneJointRotScanProgressStaticLabel->raise();

        verticalLayout->addWidget(tabWidget);


        retranslateUi(ConeScanWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConeScanWidget);
    } // setupUi

    void retranslateUi(QWidget *ConeScanWidget)
    {
        ConeScanWidget->setWindowTitle(QApplication::translate("ConeScanWidget", "\351\224\245\346\235\237\346\211\253\346\217\217", nullptr));
        sampleTimeStaticLabel->setText(QApplication::translate("ConeScanWidget", "\346\233\235\345\205\211\346\227\266\351\227\264\357\274\232", nullptr));
        gainStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\242\236\347\233\212\357\274\232", nullptr));
        singleShotFramesStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\346\225\260\357\274\232", nullptr));
        bkgTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\350\203\214\346\231\257", nullptr));
        airTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\347\251\272\346\260\224", nullptr));
        defectTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\345\235\217\345\203\217\347\264\240", nullptr));
        averageCheckBox->setText(QApplication::translate("ConeScanWidget", "\345\270\247\345\271\263\345\235\207", nullptr));
        bkgTuneButton->setText(QApplication::translate("ConeScanWidget", "\350\203\214\346\231\257\346\240\241\346\255\243", nullptr));
        airTuneButton->setText(QApplication::translate("ConeScanWidget", "\347\251\272\346\260\224\346\240\241\346\255\243", nullptr));
        singleShotButton->setText(QApplication::translate("ConeScanWidget", "\346\213\215\347\211\207", nullptr));
        pushButton_3->setText(QApplication::translate("ConeScanWidget", "\345\256\236\346\227\266", nullptr));
        coneScanSaveDirButton->setText(QApplication::translate("ConeScanWidget", "..", nullptr));
        coneScanLeakSamplePushButton->setText(QApplication::translate("ConeScanWidget", "\347\274\272\345\233\276\351\207\207\351\233\206", nullptr));
        coneScanGraduationStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\210\206\345\272\246\346\225\260", nullptr));
        coneScanFramesStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\346\225\260", nullptr));
        coneScanFrameAverageStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\345\271\263\345\235\207", nullptr));
        coneScanProgressStaticLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        coneScanBeginSampleButton->setText(QApplication::translate("ConeScanWidget", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        pushButton_2->setText(QApplication::translate("ConeScanWidget", "\345\201\234\346\255\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(coneScanTab), QApplication::translate("ConeScanWidget", "\351\224\245\346\235\237\346\211\253\346\217\217", nullptr));
        coneJointRotScanFramesStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\346\225\260", nullptr));
        coneJointRotScanleakSamplePushButton->setText(QApplication::translate("ConeScanWidget", "\347\274\272\345\233\276\351\207\207\351\233\206", nullptr));
        coneJointRotScanProgressStaticLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        coneJointRotScanBeginSampleButton->setText(QApplication::translate("ConeScanWidget", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        coneJointRotScanFrameAverageStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\345\271\263\345\235\207", nullptr));
        coneJointRotScanSaveDirButton->setText(QApplication::translate("ConeScanWidget", "..", nullptr));
        coneJointRotScanGraduationStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\210\206\345\272\246\346\225\260", nullptr));
        pushButton->setText(QApplication::translate("ConeScanWidget", "\345\201\234\346\255\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(coneJointRotScanTab), QApplication::translate("ConeScanWidget", "\351\224\245\346\235\237\350\275\254\345\217\260\345\271\263\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConeScanWidget: public Ui_ConeScanWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONESCANWIDGET_H
