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
#include <QtWidgets/QGroupBox>
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
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *singleShotSpacerStaticLabel;
    QLabel *singleShotFramesStaticLabel;
    QComboBox *singleShotFramesComboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bkgTuneButton;
    QPushButton *airTuneButton;
    QPushButton *singleShotButton;
    QTabWidget *tabWidget;
    QWidget *coneScanTab;
    QGridLayout *gridLayout;
    QPushButton *coneScanSaveDirButton;
    QLineEdit *coneScanFileNameEdit;
    QLabel *coneScanGraduationStaticLabel;
    QComboBox *coneScanMatrixComboBox;
    QLabel *coneScanFramesStaticLabel;
    QComboBox *coneScanframesComboBox;
    QLabel *coneScanFrameAverageStaticLabel;
    QSpinBox *coneScanFrameAverageSpinBox;
    QLabel *coneScanDiskAvailableStaticLabel;
    QLabel *coneScanDiskAvailableLabel;
    QLabel *coneScanNecessaryDiskStaticLabel;
    QLabel *coneScanNecessaryDiskLabel;
    QLabel *coneScanSampleTimeEstimateStaticLabel;
    QLabel *coneScanSampleTimeEstimateLabel;
    QSpacerItem *coneScanLeakSampleSpacer;
    QCheckBox *coneScanLeakSampleCheckBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *coneScanAirTuneCheckBox;
    QCheckBox *coneScanBkgTuneCheckBox;
    QCheckBox *coneScanDefectTuneCheckBox;
    QCheckBox *coneScanAllTuneCheckBox;
    QProgressBar *coneScanProgressBar;
    QPushButton *coneScanBeginSampleButton;
    QWidget *coneJointRotScanTab;
    QGridLayout *gridLayout_2;
    QPushButton *coneJointRotScanSaveDirButton;
    QLineEdit *coneJointRotScanfileNameEdit;
    QLabel *coneJointRotScanGraduationStaticLabel_2;
    QComboBox *coneJointRotScanViewSpinBox;
    QLabel *coneJointRotScanGraduationStaticLabel;
    QComboBox *coneJointRotScanMatrixComboBox;
    QLabel *coneJointRotScanFramesStaticLabel;
    QComboBox *coneJointRotScanframesComboBox;
    QLabel *coneJointRotScanFrameAverageStaticLabel;
    QSpinBox *coneJointRotScanFrameAverageSpinBox;
    QLabel *coneJointRotScandiskAvailableStaticLabel;
    QLabel *coneJointRotScanDiskAvailableLabel;
    QLabel *coneJointRotScanNecessaryDiskStaticLabel;
    QLabel *coneJointRotScanNecessaryDiskLabel;
    QLabel *coneJointRotScanSampleTimeEstimateStaticLabel;
    QLabel *coneJointRotScanSampleTimeEstimateLabel;
    QSpacerItem *coneJointRotScanleakSampleSpacer;
    QCheckBox *coneJointRotScanleakSampleCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *coneJointRotScanAirTuneCheckBox;
    QCheckBox *coneJointRotScanBkgTunecheckBox;
    QCheckBox *coneJointRotScanDefectTuneCheckBox;
    QCheckBox *coneJointRotScanAllTuneCheckBox;
    QPushButton *coneJointRotScanBeginSampleButton;
    QProgressBar *coneJointRotScanProgressBar;

    void setupUi(QWidget *ConeScanWidget)
    {
        if (ConeScanWidget->objectName().isEmpty())
            ConeScanWidget->setObjectName(QStringLiteral("ConeScanWidget"));
        ConeScanWidget->resize(289, 550);
        ConeScanWidget->setMinimumSize(QSize(280, 550));
        ConeScanWidget->setMaximumSize(QSize(50000, 550));
        ConeScanWidget->setAcceptDrops(false);
        widget = new QWidget(ConeScanWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 11, 252, 531));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(250, 100));
        groupBox->setMaximumSize(QSize(250, 100));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 6, 2, 6);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 10, -1);
        singleShotSpacerStaticLabel = new QLabel(groupBox);
        singleShotSpacerStaticLabel->setObjectName(QStringLiteral("singleShotSpacerStaticLabel"));

        horizontalLayout_3->addWidget(singleShotSpacerStaticLabel);

        singleShotFramesStaticLabel = new QLabel(groupBox);
        singleShotFramesStaticLabel->setObjectName(QStringLiteral("singleShotFramesStaticLabel"));
        singleShotFramesStaticLabel->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(singleShotFramesStaticLabel);

        singleShotFramesComboBox = new QComboBox(groupBox);
        singleShotFramesComboBox->setObjectName(QStringLiteral("singleShotFramesComboBox"));
        singleShotFramesComboBox->setMinimumSize(QSize(78, 0));
        singleShotFramesComboBox->setMaximumSize(QSize(78, 16777215));
        singleShotFramesComboBox->setInputMethodHints(Qt::ImhNone);
        singleShotFramesComboBox->setEditable(true);

        horizontalLayout_3->addWidget(singleShotFramesComboBox);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bkgTuneButton = new QPushButton(groupBox);
        bkgTuneButton->setObjectName(QStringLiteral("bkgTuneButton"));
        bkgTuneButton->setMinimumSize(QSize(60, 40));
        bkgTuneButton->setMaximumSize(QSize(60, 40));

        horizontalLayout_2->addWidget(bkgTuneButton);

        airTuneButton = new QPushButton(groupBox);
        airTuneButton->setObjectName(QStringLiteral("airTuneButton"));
        airTuneButton->setMinimumSize(QSize(60, 40));
        airTuneButton->setMaximumSize(QSize(60, 40));

        horizontalLayout_2->addWidget(airTuneButton);

        singleShotButton = new QPushButton(groupBox);
        singleShotButton->setObjectName(QStringLiteral("singleShotButton"));
        singleShotButton->setMinimumSize(QSize(80, 40));
        singleShotButton->setMaximumSize(QSize(80, 40));

        horizontalLayout_2->addWidget(singleShotButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(250, 0));
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
        coneScanSaveDirButton->setMinimumSize(QSize(30, 25));
        coneScanSaveDirButton->setMaximumSize(QSize(30, 25));

        gridLayout->addWidget(coneScanSaveDirButton, 0, 0, 1, 1);

        coneScanFileNameEdit = new QLineEdit(coneScanTab);
        coneScanFileNameEdit->setObjectName(QStringLiteral("coneScanFileNameEdit"));
        coneScanFileNameEdit->setMinimumSize(QSize(0, 25));
        coneScanFileNameEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanFileNameEdit, 0, 1, 1, 2);

        coneScanGraduationStaticLabel = new QLabel(coneScanTab);
        coneScanGraduationStaticLabel->setObjectName(QStringLiteral("coneScanGraduationStaticLabel"));
        coneScanGraduationStaticLabel->setMinimumSize(QSize(0, 25));
        coneScanGraduationStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanGraduationStaticLabel, 1, 0, 1, 1);

        coneScanMatrixComboBox = new QComboBox(coneScanTab);
        coneScanMatrixComboBox->setObjectName(QStringLiteral("coneScanMatrixComboBox"));
        coneScanMatrixComboBox->setInputMethodHints(Qt::ImhNone);
        coneScanMatrixComboBox->setEditable(true);

        gridLayout->addWidget(coneScanMatrixComboBox, 1, 2, 1, 1);

        coneScanFramesStaticLabel = new QLabel(coneScanTab);
        coneScanFramesStaticLabel->setObjectName(QStringLiteral("coneScanFramesStaticLabel"));
        coneScanFramesStaticLabel->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(coneScanFramesStaticLabel, 2, 0, 1, 1);

        coneScanframesComboBox = new QComboBox(coneScanTab);
        coneScanframesComboBox->setObjectName(QStringLiteral("coneScanframesComboBox"));
        coneScanframesComboBox->setInputMethodHints(Qt::ImhNone);
        coneScanframesComboBox->setEditable(true);

        gridLayout->addWidget(coneScanframesComboBox, 2, 2, 1, 1);

        coneScanFrameAverageStaticLabel = new QLabel(coneScanTab);
        coneScanFrameAverageStaticLabel->setObjectName(QStringLiteral("coneScanFrameAverageStaticLabel"));
        coneScanFrameAverageStaticLabel->setMinimumSize(QSize(0, 25));
        coneScanFrameAverageStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanFrameAverageStaticLabel, 3, 0, 1, 1);

        coneScanFrameAverageSpinBox = new QSpinBox(coneScanTab);
        coneScanFrameAverageSpinBox->setObjectName(QStringLiteral("coneScanFrameAverageSpinBox"));
        coneScanFrameAverageSpinBox->setMinimumSize(QSize(80, 25));
        coneScanFrameAverageSpinBox->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(coneScanFrameAverageSpinBox, 3, 2, 1, 1);

        coneScanDiskAvailableStaticLabel = new QLabel(coneScanTab);
        coneScanDiskAvailableStaticLabel->setObjectName(QStringLiteral("coneScanDiskAvailableStaticLabel"));
        coneScanDiskAvailableStaticLabel->setMinimumSize(QSize(0, 25));
        coneScanDiskAvailableStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanDiskAvailableStaticLabel, 4, 0, 1, 2);

        coneScanDiskAvailableLabel = new QLabel(coneScanTab);
        coneScanDiskAvailableLabel->setObjectName(QStringLiteral("coneScanDiskAvailableLabel"));
        coneScanDiskAvailableLabel->setMinimumSize(QSize(0, 25));
        coneScanDiskAvailableLabel->setMaximumSize(QSize(16777215, 25));
        coneScanDiskAvailableLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(coneScanDiskAvailableLabel, 4, 2, 1, 1);

        coneScanNecessaryDiskStaticLabel = new QLabel(coneScanTab);
        coneScanNecessaryDiskStaticLabel->setObjectName(QStringLiteral("coneScanNecessaryDiskStaticLabel"));
        coneScanNecessaryDiskStaticLabel->setMinimumSize(QSize(0, 25));
        coneScanNecessaryDiskStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanNecessaryDiskStaticLabel, 5, 0, 1, 2);

        coneScanNecessaryDiskLabel = new QLabel(coneScanTab);
        coneScanNecessaryDiskLabel->setObjectName(QStringLiteral("coneScanNecessaryDiskLabel"));
        coneScanNecessaryDiskLabel->setMinimumSize(QSize(0, 25));
        coneScanNecessaryDiskLabel->setMaximumSize(QSize(16777215, 25));
        coneScanNecessaryDiskLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(coneScanNecessaryDiskLabel, 5, 2, 1, 1);

        coneScanSampleTimeEstimateStaticLabel = new QLabel(coneScanTab);
        coneScanSampleTimeEstimateStaticLabel->setObjectName(QStringLiteral("coneScanSampleTimeEstimateStaticLabel"));
        coneScanSampleTimeEstimateStaticLabel->setMinimumSize(QSize(0, 25));
        coneScanSampleTimeEstimateStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanSampleTimeEstimateStaticLabel, 6, 0, 1, 2);

        coneScanSampleTimeEstimateLabel = new QLabel(coneScanTab);
        coneScanSampleTimeEstimateLabel->setObjectName(QStringLiteral("coneScanSampleTimeEstimateLabel"));
        coneScanSampleTimeEstimateLabel->setMinimumSize(QSize(0, 25));
        coneScanSampleTimeEstimateLabel->setMaximumSize(QSize(16777215, 25));
        coneScanSampleTimeEstimateLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(coneScanSampleTimeEstimateLabel, 6, 2, 1, 1);

        coneScanLeakSampleSpacer = new QSpacerItem(137, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(coneScanLeakSampleSpacer, 7, 0, 1, 2);

        coneScanLeakSampleCheckBox = new QCheckBox(coneScanTab);
        coneScanLeakSampleCheckBox->setObjectName(QStringLiteral("coneScanLeakSampleCheckBox"));
        coneScanLeakSampleCheckBox->setMinimumSize(QSize(0, 25));
        coneScanLeakSampleCheckBox->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(coneScanLeakSampleCheckBox, 7, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        coneScanAirTuneCheckBox = new QCheckBox(coneScanTab);
        coneScanAirTuneCheckBox->setObjectName(QStringLiteral("coneScanAirTuneCheckBox"));

        horizontalLayout->addWidget(coneScanAirTuneCheckBox);

        coneScanBkgTuneCheckBox = new QCheckBox(coneScanTab);
        coneScanBkgTuneCheckBox->setObjectName(QStringLiteral("coneScanBkgTuneCheckBox"));

        horizontalLayout->addWidget(coneScanBkgTuneCheckBox);

        coneScanDefectTuneCheckBox = new QCheckBox(coneScanTab);
        coneScanDefectTuneCheckBox->setObjectName(QStringLiteral("coneScanDefectTuneCheckBox"));

        horizontalLayout->addWidget(coneScanDefectTuneCheckBox);

        coneScanAllTuneCheckBox = new QCheckBox(coneScanTab);
        coneScanAllTuneCheckBox->setObjectName(QStringLiteral("coneScanAllTuneCheckBox"));

        horizontalLayout->addWidget(coneScanAllTuneCheckBox);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 3);

        coneScanProgressBar = new QProgressBar(coneScanTab);
        coneScanProgressBar->setObjectName(QStringLiteral("coneScanProgressBar"));
        coneScanProgressBar->setMinimumSize(QSize(0, 25));
        coneScanProgressBar->setMaximumSize(QSize(16777215, 25));
        coneScanProgressBar->setValue(24);
        coneScanProgressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        coneScanProgressBar->setOrientation(Qt::Horizontal);
        coneScanProgressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(coneScanProgressBar, 9, 0, 1, 3);

        coneScanBeginSampleButton = new QPushButton(coneScanTab);
        coneScanBeginSampleButton->setObjectName(QStringLiteral("coneScanBeginSampleButton"));
        coneScanBeginSampleButton->setMinimumSize(QSize(200, 50));
        coneScanBeginSampleButton->setMaximumSize(QSize(1000, 50));

        gridLayout->addWidget(coneScanBeginSampleButton, 10, 0, 1, 3);

        tabWidget->addTab(coneScanTab, QString());
        coneJointRotScanTab = new QWidget();
        coneJointRotScanTab->setObjectName(QStringLiteral("coneJointRotScanTab"));
        gridLayout_2 = new QGridLayout(coneJointRotScanTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        coneJointRotScanSaveDirButton = new QPushButton(coneJointRotScanTab);
        coneJointRotScanSaveDirButton->setObjectName(QStringLiteral("coneJointRotScanSaveDirButton"));
        coneJointRotScanSaveDirButton->setMinimumSize(QSize(30, 25));
        coneJointRotScanSaveDirButton->setMaximumSize(QSize(30, 25));

        gridLayout_2->addWidget(coneJointRotScanSaveDirButton, 0, 0, 1, 1);

        coneJointRotScanfileNameEdit = new QLineEdit(coneJointRotScanTab);
        coneJointRotScanfileNameEdit->setObjectName(QStringLiteral("coneJointRotScanfileNameEdit"));
        coneJointRotScanfileNameEdit->setMinimumSize(QSize(0, 25));
        coneJointRotScanfileNameEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanfileNameEdit, 0, 1, 1, 2);

        coneJointRotScanGraduationStaticLabel_2 = new QLabel(coneJointRotScanTab);
        coneJointRotScanGraduationStaticLabel_2->setObjectName(QStringLiteral("coneJointRotScanGraduationStaticLabel_2"));
        coneJointRotScanGraduationStaticLabel_2->setMinimumSize(QSize(0, 25));
        coneJointRotScanGraduationStaticLabel_2->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanGraduationStaticLabel_2, 1, 0, 1, 2);

        coneJointRotScanViewSpinBox = new QComboBox(coneJointRotScanTab);
        coneJointRotScanViewSpinBox->setObjectName(QStringLiteral("coneJointRotScanViewSpinBox"));
        coneJointRotScanViewSpinBox->setInputMethodHints(Qt::ImhNone);
        coneJointRotScanViewSpinBox->setEditable(true);

        gridLayout_2->addWidget(coneJointRotScanViewSpinBox, 1, 2, 1, 1);

        coneJointRotScanGraduationStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanGraduationStaticLabel->setObjectName(QStringLiteral("coneJointRotScanGraduationStaticLabel"));
        coneJointRotScanGraduationStaticLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanGraduationStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanGraduationStaticLabel, 2, 0, 1, 1);

        coneJointRotScanMatrixComboBox = new QComboBox(coneJointRotScanTab);
        coneJointRotScanMatrixComboBox->setObjectName(QStringLiteral("coneJointRotScanMatrixComboBox"));
        coneJointRotScanMatrixComboBox->setInputMethodHints(Qt::ImhNone);
        coneJointRotScanMatrixComboBox->setEditable(true);

        gridLayout_2->addWidget(coneJointRotScanMatrixComboBox, 2, 2, 1, 1);

        coneJointRotScanFramesStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanFramesStaticLabel->setObjectName(QStringLiteral("coneJointRotScanFramesStaticLabel"));
        coneJointRotScanFramesStaticLabel->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(coneJointRotScanFramesStaticLabel, 3, 0, 1, 1);

        coneJointRotScanframesComboBox = new QComboBox(coneJointRotScanTab);
        coneJointRotScanframesComboBox->setObjectName(QStringLiteral("coneJointRotScanframesComboBox"));
        coneJointRotScanframesComboBox->setInputMethodHints(Qt::ImhNone);
        coneJointRotScanframesComboBox->setEditable(true);

        gridLayout_2->addWidget(coneJointRotScanframesComboBox, 3, 2, 1, 1);

        coneJointRotScanFrameAverageStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanFrameAverageStaticLabel->setObjectName(QStringLiteral("coneJointRotScanFrameAverageStaticLabel"));
        coneJointRotScanFrameAverageStaticLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanFrameAverageStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanFrameAverageStaticLabel, 4, 0, 1, 1);

        coneJointRotScanFrameAverageSpinBox = new QSpinBox(coneJointRotScanTab);
        coneJointRotScanFrameAverageSpinBox->setObjectName(QStringLiteral("coneJointRotScanFrameAverageSpinBox"));
        coneJointRotScanFrameAverageSpinBox->setMinimumSize(QSize(80, 25));
        coneJointRotScanFrameAverageSpinBox->setMaximumSize(QSize(80, 25));

        gridLayout_2->addWidget(coneJointRotScanFrameAverageSpinBox, 4, 2, 1, 1);

        coneJointRotScandiskAvailableStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScandiskAvailableStaticLabel->setObjectName(QStringLiteral("coneJointRotScandiskAvailableStaticLabel"));
        coneJointRotScandiskAvailableStaticLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScandiskAvailableStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScandiskAvailableStaticLabel, 5, 0, 1, 2);

        coneJointRotScanDiskAvailableLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanDiskAvailableLabel->setObjectName(QStringLiteral("coneJointRotScanDiskAvailableLabel"));
        coneJointRotScanDiskAvailableLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanDiskAvailableLabel->setMaximumSize(QSize(16777215, 25));
        coneJointRotScanDiskAvailableLabel->setFrameShape(QFrame::Box);

        gridLayout_2->addWidget(coneJointRotScanDiskAvailableLabel, 5, 2, 1, 1);

        coneJointRotScanNecessaryDiskStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanNecessaryDiskStaticLabel->setObjectName(QStringLiteral("coneJointRotScanNecessaryDiskStaticLabel"));
        coneJointRotScanNecessaryDiskStaticLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanNecessaryDiskStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanNecessaryDiskStaticLabel, 6, 0, 1, 2);

        coneJointRotScanNecessaryDiskLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanNecessaryDiskLabel->setObjectName(QStringLiteral("coneJointRotScanNecessaryDiskLabel"));
        coneJointRotScanNecessaryDiskLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanNecessaryDiskLabel->setMaximumSize(QSize(16777215, 25));
        coneJointRotScanNecessaryDiskLabel->setFrameShape(QFrame::Box);

        gridLayout_2->addWidget(coneJointRotScanNecessaryDiskLabel, 6, 2, 1, 1);

        coneJointRotScanSampleTimeEstimateStaticLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanSampleTimeEstimateStaticLabel->setObjectName(QStringLiteral("coneJointRotScanSampleTimeEstimateStaticLabel"));
        coneJointRotScanSampleTimeEstimateStaticLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanSampleTimeEstimateStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanSampleTimeEstimateStaticLabel, 7, 0, 1, 2);

        coneJointRotScanSampleTimeEstimateLabel = new QLabel(coneJointRotScanTab);
        coneJointRotScanSampleTimeEstimateLabel->setObjectName(QStringLiteral("coneJointRotScanSampleTimeEstimateLabel"));
        coneJointRotScanSampleTimeEstimateLabel->setMinimumSize(QSize(0, 25));
        coneJointRotScanSampleTimeEstimateLabel->setMaximumSize(QSize(16777215, 25));
        coneJointRotScanSampleTimeEstimateLabel->setFrameShape(QFrame::Box);

        gridLayout_2->addWidget(coneJointRotScanSampleTimeEstimateLabel, 7, 2, 1, 1);

        coneJointRotScanleakSampleSpacer = new QSpacerItem(137, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(coneJointRotScanleakSampleSpacer, 8, 0, 1, 2);

        coneJointRotScanleakSampleCheckBox = new QCheckBox(coneJointRotScanTab);
        coneJointRotScanleakSampleCheckBox->setObjectName(QStringLiteral("coneJointRotScanleakSampleCheckBox"));
        coneJointRotScanleakSampleCheckBox->setMinimumSize(QSize(0, 25));
        coneJointRotScanleakSampleCheckBox->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(coneJointRotScanleakSampleCheckBox, 8, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        coneJointRotScanAirTuneCheckBox = new QCheckBox(coneJointRotScanTab);
        coneJointRotScanAirTuneCheckBox->setObjectName(QStringLiteral("coneJointRotScanAirTuneCheckBox"));

        horizontalLayout_4->addWidget(coneJointRotScanAirTuneCheckBox);

        coneJointRotScanBkgTunecheckBox = new QCheckBox(coneJointRotScanTab);
        coneJointRotScanBkgTunecheckBox->setObjectName(QStringLiteral("coneJointRotScanBkgTunecheckBox"));

        horizontalLayout_4->addWidget(coneJointRotScanBkgTunecheckBox);

        coneJointRotScanDefectTuneCheckBox = new QCheckBox(coneJointRotScanTab);
        coneJointRotScanDefectTuneCheckBox->setObjectName(QStringLiteral("coneJointRotScanDefectTuneCheckBox"));

        horizontalLayout_4->addWidget(coneJointRotScanDefectTuneCheckBox);

        coneJointRotScanAllTuneCheckBox = new QCheckBox(coneJointRotScanTab);
        coneJointRotScanAllTuneCheckBox->setObjectName(QStringLiteral("coneJointRotScanAllTuneCheckBox"));

        horizontalLayout_4->addWidget(coneJointRotScanAllTuneCheckBox);


        gridLayout_2->addLayout(horizontalLayout_4, 9, 0, 1, 3);

        coneJointRotScanBeginSampleButton = new QPushButton(coneJointRotScanTab);
        coneJointRotScanBeginSampleButton->setObjectName(QStringLiteral("coneJointRotScanBeginSampleButton"));
        coneJointRotScanBeginSampleButton->setMinimumSize(QSize(200, 50));
        coneJointRotScanBeginSampleButton->setMaximumSize(QSize(1000, 50));

        gridLayout_2->addWidget(coneJointRotScanBeginSampleButton, 11, 0, 1, 3);

        coneJointRotScanProgressBar = new QProgressBar(coneJointRotScanTab);
        coneJointRotScanProgressBar->setObjectName(QStringLiteral("coneJointRotScanProgressBar"));
        coneJointRotScanProgressBar->setMinimumSize(QSize(0, 25));
        coneJointRotScanProgressBar->setMaximumSize(QSize(16777215, 25));
        coneJointRotScanProgressBar->setValue(24);
        coneJointRotScanProgressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        coneJointRotScanProgressBar->setOrientation(Qt::Horizontal);
        coneJointRotScanProgressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_2->addWidget(coneJointRotScanProgressBar, 10, 0, 1, 3);

        tabWidget->addTab(coneJointRotScanTab, QString());
        coneJointRotScanBeginSampleButton->raise();
        coneJointRotScanProgressBar->raise();
        coneJointRotScanFramesStaticLabel->raise();
        coneJointRotScanframesComboBox->raise();

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(ConeScanWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConeScanWidget);
    } // setupUi

    void retranslateUi(QWidget *ConeScanWidget)
    {
        ConeScanWidget->setWindowTitle(QApplication::translate("ConeScanWidget", "\351\224\245\346\235\237\346\211\253\346\217\217", nullptr));
        groupBox->setTitle(QApplication::translate("ConeScanWidget", "\346\240\241\346\255\243/\346\213\215\347\211\207", nullptr));
        singleShotSpacerStaticLabel->setText(QApplication::translate("ConeScanWidget", "------------------", nullptr));
        singleShotFramesStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\346\225\260\357\274\232", nullptr));
        bkgTuneButton->setText(QApplication::translate("ConeScanWidget", "\350\203\214\346\231\257\346\240\241\346\255\243", nullptr));
        airTuneButton->setText(QApplication::translate("ConeScanWidget", "\347\251\272\346\260\224\346\240\241\346\255\243", nullptr));
        singleShotButton->setText(QApplication::translate("ConeScanWidget", "\346\213\215\347\211\207", nullptr));
        coneScanSaveDirButton->setText(QApplication::translate("ConeScanWidget", "..", nullptr));
        coneScanGraduationStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\210\206\345\272\246\346\225\260", nullptr));
        coneScanFramesStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\346\225\260", nullptr));
        coneScanFrameAverageStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\345\271\263\345\235\207", nullptr));
        coneScanDiskAvailableStaticLabel->setText(QApplication::translate("ConeScanWidget", "\347\241\254\347\233\230\345\211\251\344\275\231\347\251\272\351\227\264", nullptr));
        coneScanDiskAvailableLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        coneScanNecessaryDiskStaticLabel->setText(QApplication::translate("ConeScanWidget", "\351\207\207\351\233\206\351\234\200\350\246\201\347\251\272\351\227\264", nullptr));
        coneScanNecessaryDiskLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        coneScanSampleTimeEstimateStaticLabel->setText(QApplication::translate("ConeScanWidget", "\351\242\204\350\256\241\351\207\207\351\233\206\346\227\266\351\227\264", nullptr));
        coneScanSampleTimeEstimateLabel->setText(QApplication::translate("ConeScanWidget", "\351\242\204\350\256\241\351\207\207\351\233\206\346\227\266\351\227\264", nullptr));
        coneScanLeakSampleCheckBox->setText(QApplication::translate("ConeScanWidget", "\347\274\272\345\233\276\351\207\207\351\233\206", nullptr));
        coneScanAirTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\347\251\272\346\260\224", nullptr));
        coneScanBkgTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\350\203\214\346\231\257", nullptr));
        coneScanDefectTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\345\235\217\345\203\217\347\264\240", nullptr));
        coneScanAllTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\345\205\250\351\203\250", nullptr));
        coneScanBeginSampleButton->setText(QApplication::translate("ConeScanWidget", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(coneScanTab), QApplication::translate("ConeScanWidget", "\351\224\245\346\235\237\346\211\253\346\217\217", nullptr));
        coneJointRotScanSaveDirButton->setText(QApplication::translate("ConeScanWidget", "..", nullptr));
        coneJointRotScanGraduationStaticLabel_2->setText(QApplication::translate("ConeScanWidget", "\350\247\206\345\234\272\347\233\264\345\276\204", nullptr));
        coneJointRotScanGraduationStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\210\206\345\272\246\346\225\260", nullptr));
        coneJointRotScanFramesStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\346\225\260", nullptr));
        coneJointRotScanFrameAverageStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\345\271\263\345\235\207", nullptr));
        coneJointRotScandiskAvailableStaticLabel->setText(QApplication::translate("ConeScanWidget", "\347\241\254\347\233\230\345\211\251\344\275\231\347\251\272\351\227\264", nullptr));
        coneJointRotScanDiskAvailableLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        coneJointRotScanNecessaryDiskStaticLabel->setText(QApplication::translate("ConeScanWidget", "\351\207\207\351\233\206\351\234\200\350\246\201\347\251\272\351\227\264", nullptr));
        coneJointRotScanNecessaryDiskLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        coneJointRotScanSampleTimeEstimateStaticLabel->setText(QApplication::translate("ConeScanWidget", "\351\242\204\350\256\241\351\207\207\351\233\206\346\227\266\351\227\264", nullptr));
        coneJointRotScanSampleTimeEstimateLabel->setText(QApplication::translate("ConeScanWidget", "\351\242\204\350\256\241\351\207\207\351\233\206\346\227\266\351\227\264", nullptr));
        coneJointRotScanleakSampleCheckBox->setText(QApplication::translate("ConeScanWidget", "\347\274\272\345\233\276\351\207\207\351\233\206", nullptr));
        coneJointRotScanAirTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\347\251\272\346\260\224", nullptr));
        coneJointRotScanBkgTunecheckBox->setText(QApplication::translate("ConeScanWidget", "\350\203\214\346\231\257", nullptr));
        coneJointRotScanDefectTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\345\235\217\345\203\217\347\264\240", nullptr));
        coneJointRotScanAllTuneCheckBox->setText(QApplication::translate("ConeScanWidget", "\345\205\250\351\203\250", nullptr));
        coneJointRotScanBeginSampleButton->setText(QApplication::translate("ConeScanWidget", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(coneJointRotScanTab), QApplication::translate("ConeScanWidget", "\351\224\245\346\235\237\350\275\254\345\217\260\345\271\263\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConeScanWidget: public Ui_ConeScanWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONESCANWIDGET_H
