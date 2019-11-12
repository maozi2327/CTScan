/********************************************************************************
** Form generated from reading UI file 'raypanelmotion.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAYPANELMOTION_H
#define UI_RAYPANELMOTION_H
#include "machineType.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rayPanelMotionWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
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
    QPushButton *Comet450XRayOffButton;
    QLabel *Comet450kvStaticLabel;
    QPushButton *Comet450XRayOnButton;
    QLabel *Comet450FocusStaticLabel;
    QComboBox *Comet450FocusComboBox;
    QLineEdit *Comet450EmissionCurrentEdit;
    QGroupBox *panelGroupBox;
    QGridLayout *panelLayout1;
    QLabel *binStaticLabel;
    QComboBox *binComboBox;
    QLabel *gainStaticLabel;
    QComboBox *gainGroupBox;
    QGridLayout *panelLayout2;
    QLineEdit *sampleTimeEdit;
    QCheckBox *frameAverageCheckBox;
    QComboBox *frameAverageComboBox;
    QLabel *sampleTimeStaticLabel;
    QSpacerItem *panelHorizontalSpacer;
    QGroupBox *scanSetupGroupBox;
    QGridLayout *scanSetupLayout1;
    QLabel *sodStaticLabel;
    QLabel *sodLabel;
    QLabel *sddStaticLabel;
    QLabel *sddLabel;
    QPushButton *scanSetupButton;
    QGroupBox *motionGroupBox;
    QVBoxLayout *motionGroupLayout1;
    QHBoxLayout *tableRotLayout1;
    QGridLayout *tableRotLayout2;
    QLineEdit *tableRotationPosEdit;
    QPushButton *tableRotNegtiveButton;
    QPushButton *tableRotPositiveButton;
    QPushButton *tableRotAbsPosButton;
    QSpacerItem *tableRotSpacer;
    QVBoxLayout *tableRotLayout3;
    QLabel *tableRotStaticLabel;
    QSlider *tableRotHorizontalSlider;
    QFrame *tableRotLine;
#ifdef TABLETRANSLATION
    QHBoxLayout *tableTranslationLayou1;
    QGridLayout *tableTranslationLayou2;
    QLineEdit *tableTranslationPosEdit;
    QPushButton *tableTranslationNegtiveButton;
    QPushButton *tableTranslationPositiveButton;
    QPushButton *tableTranslationAbsPosButton;
    QSpacerItem *tableTranslationSpacer;
    QVBoxLayout *tableTranslationLayout3;
    QLabel *tableTranslationStaticLabel;
    QSlider *tableTranslationHorizontalSlider;
    QFrame *tableTranslationLine;
#endif
#ifdef TABLERADIAL
    QHBoxLayout *tableRadialLayout1;
    QGridLayout *tableRadialLayout2;
    QLineEdit *tableRadialPosEdit;
    QPushButton *tableRadialNegtiveButton;
    QPushButton *tableRadialPositiveButton;
    QPushButton *tableRadialAbsPosButton;
    QSpacerItem *tableRadialSpacer;
    QVBoxLayout *tableRadialLayout3;
    QLabel *tableRadialStaticLabel;
    QSlider *tableRadialHorizontalSlider;
    QFrame *tableRadialLine;
#endif
#ifdef DETLAYER
    QHBoxLayout *detLayerLayout1;
    QGridLayout *detLayerLayout2;
    QLineEdit *detLayerPosEdit;
    QPushButton *detLayerNegtiveButton;
    QPushButton *detLayerPositiveButton;
    QPushButton *detLayerAbsPosButton;
    QSpacerItem *detLayerSpacer;
    QVBoxLayout *detLayerLayout3;
    QLabel *detLayerStaticLabel;
    QSlider *detLayerHorizontalSlider;
    QFrame *detLayerLine;
#endif
#ifdef DETTRANSLATION
    QHBoxLayout *detTranslationLayout1;
    QGridLayout *detTranslationLayout2;
    QLineEdit *detTranslationPosEdit;
    QPushButton *detTranslationNegtiveButton;
    QPushButton *detTranslationPositiveButton;
    QPushButton *detTranslationAbsPosButton;
    QSpacerItem *detTranslationSpacer;
    QVBoxLayout *detTranslationLayout3;
    QLabel *detTranslationStaticLabel;
    QSlider *detTranslationHorizontalSlider;
    QFrame *detTranslationLine;
#endif
#ifdef DETRADIAL
    QHBoxLayout *detRadialLayout1;
    QGridLayout *detRadialLayout2;
    QLineEdit *detRadialPosEdit;
    QPushButton *detRadialNegtiveButton;
    QPushButton *detRadialPositiveButton;
    QPushButton *detRadialAbsPosButton;
    QSpacerItem *detRadialSpacer;
    QVBoxLayout *detRadialLayout3;
    QLabel *detRadialStaticLabel;
    QSlider *detRadialHorizontalSlider;
    QFrame *detRadialLine;
#endif
#ifdef RAYLAYER
    QHBoxLayout *rayLayerLayout1;
    QGridLayout *rayLayerLayout2;
    QLineEdit *rayLayerPosEdit;
    QPushButton *rayLayerNegtiveButton;
    QPushButton *rayLayerPositiveButton;
    QPushButton *rayLayerAbsPosButton;
    QSpacerItem *rayLayerSpacer;
    QVBoxLayout *rayLayerLayout3;
    QLabel *rayLayerStaticLabel;
    QSlider *rayLayerHorizontalSlider;
    QFrame *rayLayerLine;
#endif
#ifdef DEFLECT
    QHBoxLayout *deflectLayout1;
    QGridLayout *deflectLayout2;
    QLineEdit *deflectPosEdit;
    QPushButton *deflectNegtiveButton;
    QPushButton *deflectPositiveButton;
    QPushButton *deflectAbsPosButton;
    QSpacerItem *deflectSpacer;
    QVBoxLayout *deflectLayout3;
    QLabel *deflectStaticLabel;
    QSlider *deflectHorizontalSlider;
    QFrame *deflectLine;
#endif
    QHBoxLayout *sampleChooseButtonLayout1;
    QSpacerItem *sampleChooseButtonSpacer;
    QPushButton *sampleChooseButton;
    QSpacerItem *mainStrechSpacer;

    void setupUi(QWidget *rayPanelMotionWidget)
    {
        if (rayPanelMotionWidget->objectName().isEmpty())
            rayPanelMotionWidget->setObjectName(QStringLiteral("rayPanelMotionWidget"));
        rayPanelMotionWidget->resize(400, 920);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rayPanelMotionWidget->sizePolicy().hasHeightForWidth());
        rayPanelMotionWidget->setSizePolicy(sizePolicy);
        rayPanelMotionWidget->setMinimumSize(QSize(400, 0));
        rayPanelMotionWidget->setMaximumSize(QSize(400, 16777215));
        rayPanelMotionWidget->setAutoFillBackground(false);
        widget = new QWidget(rayPanelMotionWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 12, 367, 904));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
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
        worx225uaStaticLabel_2->setGeometry(QRect(176, 7, 50, 19));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(25);
        sizePolicy1.setVerticalStretch(18);
        sizePolicy1.setHeightForWidth(worx225uaStaticLabel_2->sizePolicy().hasHeightForWidth());
        worx225uaStaticLabel_2->setSizePolicy(sizePolicy1);
        worx225uaStaticLabel_2->setMinimumSize(QSize(25, 18));
        worx225XRayOnButton_2 = new QPushButton(rayWrox225Tab);
        worx225XRayOnButton_2->setObjectName(QStringLiteral("worx225XRayOnButton_2"));
        worx225XRayOnButton_2->setGeometry(QRect(224, 8, 60, 40));
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
        Comet450uaStaticLabel->setGeometry(QRect(176, 7, 50, 19));
        sizePolicy1.setHeightForWidth(Comet450uaStaticLabel->sizePolicy().hasHeightForWidth());
        Comet450uaStaticLabel->setSizePolicy(sizePolicy1);
        Comet450uaStaticLabel->setMinimumSize(QSize(25, 18));
        Comet450VoltageInputEdit = new QLineEdit(rayComet450Tab);
        Comet450VoltageInputEdit->setObjectName(QStringLiteral("Comet450VoltageInputEdit"));
        Comet450VoltageInputEdit->setGeometry(QRect(13, 7, 60, 20));
        Comet450VoltageInputEdit->setMinimumSize(QSize(60, 20));
        Comet450VoltageInputEdit->setMaximumSize(QSize(60, 20));
        Comet450XRayOffButton = new QPushButton(rayComet450Tab);
        Comet450XRayOffButton->setObjectName(QStringLiteral("Comet450XRayOffButton"));
        Comet450XRayOffButton->setGeometry(QRect(288, 8, 60, 40));
        Comet450XRayOffButton->setMinimumSize(QSize(60, 40));
        Comet450XRayOffButton->setMaximumSize(QSize(60, 40));
        Comet450kvStaticLabel = new QLabel(rayComet450Tab);
        Comet450kvStaticLabel->setObjectName(QStringLiteral("Comet450kvStaticLabel"));
        Comet450kvStaticLabel->setGeometry(QRect(79, 7, 25, 18));
        Comet450kvStaticLabel->setMinimumSize(QSize(25, 18));
        Comet450kvStaticLabel->setMaximumSize(QSize(25, 18));
        Comet450XRayOnButton = new QPushButton(rayComet450Tab);
        Comet450XRayOnButton->setObjectName(QStringLiteral("Comet450XRayOnButton"));
        Comet450XRayOnButton->setGeometry(QRect(224, 8, 60, 40));
        Comet450XRayOnButton->setMinimumSize(QSize(60, 40));
        Comet450XRayOnButton->setMaximumSize(QSize(60, 40));
        Comet450FocusStaticLabel = new QLabel(rayComet450Tab);
        Comet450FocusStaticLabel->setObjectName(QStringLiteral("Comet450FocusStaticLabel"));
        Comet450FocusStaticLabel->setGeometry(QRect(13, 32, 60, 18));
        Comet450FocusComboBox = new QComboBox(rayComet450Tab);
        Comet450FocusComboBox->setObjectName(QStringLiteral("Comet450FocusComboBox"));
        Comet450FocusComboBox->setGeometry(QRect(110, 32, 60, 20));
        Comet450FocusComboBox->setMinimumSize(QSize(60, 20));
        Comet450FocusComboBox->setMaximumSize(QSize(60, 20));
        Comet450EmissionCurrentEdit = new QLineEdit(rayComet450Tab);
        Comet450EmissionCurrentEdit->setObjectName(QStringLiteral("Comet450EmissionCurrentEdit"));
        Comet450EmissionCurrentEdit->setGeometry(QRect(110, 7, 60, 20));
        Comet450EmissionCurrentEdit->setMinimumSize(QSize(60, 20));
        Comet450EmissionCurrentEdit->setMaximumSize(QSize(60, 20));
        rayTab->addTab(rayComet450Tab, QString());

        verticalLayout_2->addWidget(rayTab);

        panelGroupBox = new QGroupBox(widget);
        panelGroupBox->setObjectName(QStringLiteral("panelGroupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(panelGroupBox->sizePolicy().hasHeightForWidth());
        panelGroupBox->setSizePolicy(sizePolicy2);
        panelGroupBox->setMinimumSize(QSize(0, 75));
        panelGroupBox->setMaximumSize(QSize(1000, 75));
        panelLayout1 = new QGridLayout(panelGroupBox);
        panelLayout1->setObjectName(QStringLiteral("panelLayout1"));
        binStaticLabel = new QLabel(panelGroupBox);
        binStaticLabel->setObjectName(QStringLiteral("binStaticLabel"));
        binStaticLabel->setMinimumSize(QSize(30, 16));
        binStaticLabel->setMaximumSize(QSize(30, 16));

        panelLayout1->addWidget(binStaticLabel, 0, 0, 1, 1);

        binComboBox = new QComboBox(panelGroupBox);
        binComboBox->setObjectName(QStringLiteral("binComboBox"));
        binComboBox->setMinimumSize(QSize(60, 20));
        binComboBox->setMaximumSize(QSize(60, 20));

        panelLayout1->addWidget(binComboBox, 0, 1, 1, 1);

        gainStaticLabel = new QLabel(panelGroupBox);
        gainStaticLabel->setObjectName(QStringLiteral("gainStaticLabel"));
        gainStaticLabel->setMinimumSize(QSize(30, 16));
        gainStaticLabel->setMaximumSize(QSize(30, 16));

        panelLayout1->addWidget(gainStaticLabel, 0, 2, 1, 1);

        gainGroupBox = new QComboBox(panelGroupBox);
        gainGroupBox->setObjectName(QStringLiteral("gainGroupBox"));
        gainGroupBox->setMinimumSize(QSize(60, 20));
        gainGroupBox->setMaximumSize(QSize(60, 20));

        panelLayout1->addWidget(gainGroupBox, 0, 3, 1, 1);

        panelLayout2 = new QGridLayout();
        panelLayout2->setObjectName(QStringLiteral("panelLayout2"));
        sampleTimeEdit = new QLineEdit(panelGroupBox);
        sampleTimeEdit->setObjectName(QStringLiteral("sampleTimeEdit"));
        sampleTimeEdit->setMinimumSize(QSize(60, 20));
        sampleTimeEdit->setMaximumSize(QSize(60, 20));

        panelLayout2->addWidget(sampleTimeEdit, 0, 1, 1, 1);

        frameAverageCheckBox = new QCheckBox(panelGroupBox);
        frameAverageCheckBox->setObjectName(QStringLiteral("frameAverageCheckBox"));
        frameAverageCheckBox->setMinimumSize(QSize(60, 16));
        frameAverageCheckBox->setMaximumSize(QSize(60, 16));

        panelLayout2->addWidget(frameAverageCheckBox, 2, 0, 1, 1);

        frameAverageComboBox = new QComboBox(panelGroupBox);
        frameAverageComboBox->setObjectName(QStringLiteral("frameAverageComboBox"));
        frameAverageComboBox->setMinimumSize(QSize(60, 20));
        frameAverageComboBox->setMaximumSize(QSize(60, 20));

        panelLayout2->addWidget(frameAverageComboBox, 2, 1, 1, 1);

        sampleTimeStaticLabel = new QLabel(panelGroupBox);
        sampleTimeStaticLabel->setObjectName(QStringLiteral("sampleTimeStaticLabel"));
        sampleTimeStaticLabel->setMinimumSize(QSize(60, 16));
        sampleTimeStaticLabel->setMaximumSize(QSize(60, 16));

        panelLayout2->addWidget(sampleTimeStaticLabel, 0, 0, 1, 1);


        panelLayout1->addLayout(panelLayout2, 0, 4, 2, 1);

        panelHorizontalSpacer = new QSpacerItem(195, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        panelLayout1->addItem(panelHorizontalSpacer, 1, 0, 1, 4);


        verticalLayout_2->addWidget(panelGroupBox);

        scanSetupGroupBox = new QGroupBox(widget);
        scanSetupGroupBox->setObjectName(QStringLiteral("scanSetupGroupBox"));
        sizePolicy2.setHeightForWidth(scanSetupGroupBox->sizePolicy().hasHeightForWidth());
        scanSetupGroupBox->setSizePolicy(sizePolicy2);
        scanSetupGroupBox->setMinimumSize(QSize(365, 60));
        scanSetupGroupBox->setMaximumSize(QSize(365, 60));
        scanSetupLayout1 = new QGridLayout(scanSetupGroupBox);
        scanSetupLayout1->setObjectName(QStringLiteral("scanSetupLayout1"));
        sodStaticLabel = new QLabel(scanSetupGroupBox);
        sodStaticLabel->setObjectName(QStringLiteral("sodStaticLabel"));

        scanSetupLayout1->addWidget(sodStaticLabel, 0, 0, 1, 1);

        sodLabel = new QLabel(scanSetupGroupBox);
        sodLabel->setObjectName(QStringLiteral("sodLabel"));
        sodLabel->setFrameShape(QFrame::Box);

        scanSetupLayout1->addWidget(sodLabel, 0, 1, 1, 1);

        sddStaticLabel = new QLabel(scanSetupGroupBox);
        sddStaticLabel->setObjectName(QStringLiteral("sddStaticLabel"));

        scanSetupLayout1->addWidget(sddStaticLabel, 0, 2, 1, 1);

        sddLabel = new QLabel(scanSetupGroupBox);
        sddLabel->setObjectName(QStringLiteral("sddLabel"));
        sddLabel->setFrameShape(QFrame::Box);

        scanSetupLayout1->addWidget(sddLabel, 0, 3, 1, 1);

        scanSetupButton = new QPushButton(scanSetupGroupBox);
        scanSetupButton->setObjectName(QStringLiteral("scanSetupButton"));

        scanSetupLayout1->addWidget(scanSetupButton, 0, 4, 1, 1);


        verticalLayout_2->addWidget(scanSetupGroupBox);

        motionGroupBox = new QGroupBox(widget);
        motionGroupBox->setObjectName(QStringLiteral("motionGroupBox"));
        sizePolicy2.setHeightForWidth(motionGroupBox->sizePolicy().hasHeightForWidth());
        motionGroupBox->setSizePolicy(sizePolicy2);
        motionGroupBox->setMinimumSize(QSize(365, 0));
        motionGroupBox->setMaximumSize(QSize(365, 1000));
        motionGroupLayout1 = new QVBoxLayout(motionGroupBox);
        motionGroupLayout1->setObjectName(QStringLiteral("motionGroupLayout1"));
        tableRotLayout1 = new QHBoxLayout();
        tableRotLayout1->setObjectName(QStringLiteral("tableRotLayout1"));
        tableRotLayout2 = new QGridLayout();
        tableRotLayout2->setObjectName(QStringLiteral("tableRotLayout2"));
        tableRotLayout2->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableRotationPosEdit = new QLineEdit(motionGroupBox);
        tableRotationPosEdit->setObjectName(QStringLiteral("tableRotationPosEdit"));
        tableRotationPosEdit->setMinimumSize(QSize(70, 25));
        tableRotationPosEdit->setMaximumSize(QSize(70, 25));

        tableRotLayout2->addWidget(tableRotationPosEdit, 0, 0, 1, 2);

        tableRotNegtiveButton = new QPushButton(motionGroupBox);
        tableRotNegtiveButton->setObjectName(QStringLiteral("tableRotNegtiveButton"));
        tableRotNegtiveButton->setMinimumSize(QSize(25, 25));
        tableRotNegtiveButton->setMaximumSize(QSize(25, 25));

        tableRotLayout2->addWidget(tableRotNegtiveButton, 1, 0, 1, 1);

        tableRotPositiveButton = new QPushButton(motionGroupBox);
        tableRotPositiveButton->setObjectName(QStringLiteral("tableRotPositiveButton"));
        tableRotPositiveButton->setMinimumSize(QSize(25, 25));
        tableRotPositiveButton->setMaximumSize(QSize(25, 25));

        tableRotLayout2->addWidget(tableRotPositiveButton, 1, 1, 1, 1);


        tableRotLayout1->addLayout(tableRotLayout2);

        tableRotAbsPosButton = new QPushButton(motionGroupBox);
        tableRotAbsPosButton->setObjectName(QStringLiteral("tableRotAbsPosButton"));
        tableRotAbsPosButton->setMinimumSize(QSize(45, 45));
        tableRotAbsPosButton->setMaximumSize(QSize(45, 45));

        tableRotLayout1->addWidget(tableRotAbsPosButton);

        tableRotSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        tableRotLayout1->addItem(tableRotSpacer);

        tableRotLayout3 = new QVBoxLayout();
        tableRotLayout3->setObjectName(QStringLiteral("tableRotLayout3"));
        tableRotLayout3->setSizeConstraint(QLayout::SetFixedSize);
        tableRotStaticLabel = new QLabel(motionGroupBox);
        tableRotStaticLabel->setObjectName(QStringLiteral("tableRotStaticLabel"));
        sizePolicy.setHeightForWidth(tableRotStaticLabel->sizePolicy().hasHeightForWidth());
        tableRotStaticLabel->setSizePolicy(sizePolicy);

        tableRotLayout3->addWidget(tableRotStaticLabel);

        tableRotHorizontalSlider = new QSlider(motionGroupBox);
        tableRotHorizontalSlider->setObjectName(QStringLiteral("tableRotHorizontalSlider"));
        tableRotHorizontalSlider->setMinimumSize(QSize(190, 0));
        tableRotHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        tableRotHorizontalSlider->setOrientation(Qt::Horizontal);

        tableRotLayout3->addWidget(tableRotHorizontalSlider);


        tableRotLayout1->addLayout(tableRotLayout3);


        motionGroupLayout1->addLayout(tableRotLayout1);

        tableRotLine = new QFrame(motionGroupBox);
        tableRotLine->setObjectName(QStringLiteral("tableRotLine"));
        tableRotLine->setMinimumSize(QSize(350, 2));
        tableRotLine->setMaximumSize(QSize(350, 2));
        tableRotLine->setLayoutDirection(Qt::LeftToRight);
        tableRotLine->setFrameShape(QFrame::HLine);
        tableRotLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(tableRotLine);
#ifdef TABLETRANSLATION
        tableTranslationLayou1 = new QHBoxLayout();
        tableTranslationLayou1->setObjectName(QStringLiteral("tableTranslationLayou1"));
        tableTranslationLayou2 = new QGridLayout();
        tableTranslationLayou2->setObjectName(QStringLiteral("tableTranslationLayou2"));
        tableTranslationPosEdit = new QLineEdit(motionGroupBox);
        tableTranslationPosEdit->setObjectName(QStringLiteral("tableTranslationPosEdit"));
        tableTranslationPosEdit->setMinimumSize(QSize(70, 25));
        tableTranslationPosEdit->setMaximumSize(QSize(70, 25));

        tableTranslationLayou2->addWidget(tableTranslationPosEdit, 0, 0, 1, 2);

        tableTranslationNegtiveButton = new QPushButton(motionGroupBox);
        tableTranslationNegtiveButton->setObjectName(QStringLiteral("tableTranslationNegtiveButton"));
        tableTranslationNegtiveButton->setMinimumSize(QSize(25, 25));
        tableTranslationNegtiveButton->setMaximumSize(QSize(25, 25));

        tableTranslationLayou2->addWidget(tableTranslationNegtiveButton, 1, 0, 1, 1);

        tableTranslationPositiveButton = new QPushButton(motionGroupBox);
        tableTranslationPositiveButton->setObjectName(QStringLiteral("tableTranslationPositiveButton"));
        tableTranslationPositiveButton->setMinimumSize(QSize(25, 25));
        tableTranslationPositiveButton->setMaximumSize(QSize(25, 25));

        tableTranslationLayou2->addWidget(tableTranslationPositiveButton, 1, 1, 1, 1);


        tableTranslationLayou1->addLayout(tableTranslationLayou2);

        tableTranslationAbsPosButton = new QPushButton(motionGroupBox);
        tableTranslationAbsPosButton->setObjectName(QStringLiteral("tableTranslationAbsPosButton"));
        tableTranslationAbsPosButton->setMinimumSize(QSize(45, 45));
        tableTranslationAbsPosButton->setMaximumSize(QSize(45, 45));

        tableTranslationLayou1->addWidget(tableTranslationAbsPosButton);

        tableTranslationSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        tableTranslationLayou1->addItem(tableTranslationSpacer);

        tableTranslationLayout3 = new QVBoxLayout();
        tableTranslationLayout3->setObjectName(QStringLiteral("tableTranslationLayout3"));
        tableTranslationStaticLabel = new QLabel(motionGroupBox);
        tableTranslationStaticLabel->setObjectName(QStringLiteral("tableTranslationStaticLabel"));

        tableTranslationLayout3->addWidget(tableTranslationStaticLabel);

        tableTranslationHorizontalSlider = new QSlider(motionGroupBox);
        tableTranslationHorizontalSlider->setObjectName(QStringLiteral("tableTranslationHorizontalSlider"));
        tableTranslationHorizontalSlider->setMinimumSize(QSize(190, 0));
        tableTranslationHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        tableTranslationHorizontalSlider->setOrientation(Qt::Horizontal);

        tableTranslationLayout3->addWidget(tableTranslationHorizontalSlider);


        tableTranslationLayou1->addLayout(tableTranslationLayout3);


        motionGroupLayout1->addLayout(tableTranslationLayou1);

        tableTranslationLine = new QFrame(motionGroupBox);
        tableTranslationLine->setObjectName(QStringLiteral("tableTranslationLine"));
        tableTranslationLine->setMinimumSize(QSize(350, 2));
        tableTranslationLine->setMaximumSize(QSize(350, 2));
        tableTranslationLine->setLayoutDirection(Qt::LeftToRight);
        tableTranslationLine->setFrameShape(QFrame::HLine);
        tableTranslationLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(tableTranslationLine);
#endif
#ifdef TABLERADIAL
        tableRadialLayout1 = new QHBoxLayout();
        tableRadialLayout1->setObjectName(QStringLiteral("tableRadialLayout1"));
        tableRadialLayout2 = new QGridLayout();
        tableRadialLayout2->setObjectName(QStringLiteral("tableRadialLayout2"));
        tableRadialPosEdit = new QLineEdit(motionGroupBox);
        tableRadialPosEdit->setObjectName(QStringLiteral("tableRadialPosEdit"));
        tableRadialPosEdit->setMinimumSize(QSize(70, 25));
        tableRadialPosEdit->setMaximumSize(QSize(70, 25));

        tableRadialLayout2->addWidget(tableRadialPosEdit, 0, 0, 1, 2);

        tableRadialNegtiveButton = new QPushButton(motionGroupBox);
        tableRadialNegtiveButton->setObjectName(QStringLiteral("tableRadialNegtiveButton"));
        tableRadialNegtiveButton->setMinimumSize(QSize(25, 25));
        tableRadialNegtiveButton->setMaximumSize(QSize(25, 25));

        tableRadialLayout2->addWidget(tableRadialNegtiveButton, 1, 0, 1, 1);

        tableRadialPositiveButton = new QPushButton(motionGroupBox);
        tableRadialPositiveButton->setObjectName(QStringLiteral("tableRadialPositiveButton"));
        tableRadialPositiveButton->setMinimumSize(QSize(25, 25));
        tableRadialPositiveButton->setMaximumSize(QSize(25, 25));

        tableRadialLayout2->addWidget(tableRadialPositiveButton, 1, 1, 1, 1);


        tableRadialLayout1->addLayout(tableRadialLayout2);

        tableRadialAbsPosButton = new QPushButton(motionGroupBox);
        tableRadialAbsPosButton->setObjectName(QStringLiteral("tableRadialAbsPosButton"));
        tableRadialAbsPosButton->setMinimumSize(QSize(45, 45));
        tableRadialAbsPosButton->setMaximumSize(QSize(45, 45));

        tableRadialLayout1->addWidget(tableRadialAbsPosButton);

        tableRadialSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        tableRadialLayout1->addItem(tableRadialSpacer);

        tableRadialLayout3 = new QVBoxLayout();
        tableRadialLayout3->setObjectName(QStringLiteral("tableRadialLayout3"));
        tableRadialStaticLabel = new QLabel(motionGroupBox);
        tableRadialStaticLabel->setObjectName(QStringLiteral("tableRadialStaticLabel"));

        tableRadialLayout3->addWidget(tableRadialStaticLabel);

        tableRadialHorizontalSlider = new QSlider(motionGroupBox);
        tableRadialHorizontalSlider->setObjectName(QStringLiteral("tableRadialHorizontalSlider"));
        tableRadialHorizontalSlider->setMinimumSize(QSize(190, 0));
        tableRadialHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        tableRadialHorizontalSlider->setOrientation(Qt::Horizontal);

        tableRadialLayout3->addWidget(tableRadialHorizontalSlider);


        tableRadialLayout1->addLayout(tableRadialLayout3);


        motionGroupLayout1->addLayout(tableRadialLayout1);

        tableRadialLine = new QFrame(motionGroupBox);
        tableRadialLine->setObjectName(QStringLiteral("tableRadialLine"));
        tableRadialLine->setMinimumSize(QSize(350, 0));
        tableRadialLine->setMaximumSize(QSize(350, 16777215));
        tableRadialLine->setLayoutDirection(Qt::LeftToRight);
        tableRadialLine->setFrameShape(QFrame::HLine);
        tableRadialLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(tableRadialLine);
#endif
#ifdef DETLAYER
        detLayerLayout1 = new QHBoxLayout();
        detLayerLayout1->setObjectName(QStringLiteral("detLayerLayout1"));
        detLayerLayout2 = new QGridLayout();
        detLayerLayout2->setObjectName(QStringLiteral("detLayerLayout2"));
        detLayerPosEdit = new QLineEdit(motionGroupBox);
        detLayerPosEdit->setObjectName(QStringLiteral("detLayerPosEdit"));
        detLayerPosEdit->setMinimumSize(QSize(70, 25));
        detLayerPosEdit->setMaximumSize(QSize(70, 25));

        detLayerLayout2->addWidget(detLayerPosEdit, 0, 0, 1, 2);

        detLayerNegtiveButton = new QPushButton(motionGroupBox);
        detLayerNegtiveButton->setObjectName(QStringLiteral("detLayerNegtiveButton"));
        detLayerNegtiveButton->setMinimumSize(QSize(25, 25));
        detLayerNegtiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2->addWidget(detLayerNegtiveButton, 1, 0, 1, 1);

        detLayerPositiveButton = new QPushButton(motionGroupBox);
        detLayerPositiveButton->setObjectName(QStringLiteral("detLayerPositiveButton"));
        detLayerPositiveButton->setMinimumSize(QSize(25, 25));
        detLayerPositiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2->addWidget(detLayerPositiveButton, 1, 1, 1, 1);


        detLayerLayout1->addLayout(detLayerLayout2);

        detLayerAbsPosButton = new QPushButton(motionGroupBox);
        detLayerAbsPosButton->setObjectName(QStringLiteral("detLayerAbsPosButton"));
        detLayerAbsPosButton->setMinimumSize(QSize(45, 45));
        detLayerAbsPosButton->setMaximumSize(QSize(45, 45));

        detLayerLayout1->addWidget(detLayerAbsPosButton);

        detLayerSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        detLayerLayout1->addItem(detLayerSpacer);

        detLayerLayout3 = new QVBoxLayout();
        detLayerLayout3->setObjectName(QStringLiteral("detLayerLayout3"));
        detLayerStaticLabel = new QLabel(motionGroupBox);
        detLayerStaticLabel->setObjectName(QStringLiteral("detLayerStaticLabel"));

        detLayerLayout3->addWidget(detLayerStaticLabel);

        detLayerHorizontalSlider = new QSlider(motionGroupBox);
        detLayerHorizontalSlider->setObjectName(QStringLiteral("detLayerHorizontalSlider"));
        detLayerHorizontalSlider->setMinimumSize(QSize(190, 0));
        detLayerHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        detLayerHorizontalSlider->setOrientation(Qt::Horizontal);

        detLayerLayout3->addWidget(detLayerHorizontalSlider);


        detLayerLayout1->addLayout(detLayerLayout3);


        motionGroupLayout1->addLayout(detLayerLayout1);

        detLayerLine = new QFrame(motionGroupBox);
        detLayerLine->setObjectName(QStringLiteral("detLayerLine"));
        detLayerLine->setMinimumSize(QSize(350, 2));
        detLayerLine->setMaximumSize(QSize(350, 2));
        detLayerLine->setLayoutDirection(Qt::LeftToRight);
        detLayerLine->setFrameShape(QFrame::HLine);
        detLayerLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(detLayerLine);
#endif
#ifdef DETTRANSLATION
        detTranslationLayout1 = new QHBoxLayout();
        detTranslationLayout1->setObjectName(QStringLiteral("detTranslationLayout1"));
        detTranslationLayout2 = new QGridLayout();
        detTranslationLayout2->setObjectName(QStringLiteral("detTranslationLayout2"));
        detTranslationPosEdit = new QLineEdit(motionGroupBox);
        detTranslationPosEdit->setObjectName(QStringLiteral("detTranslationPosEdit"));
        detTranslationPosEdit->setMinimumSize(QSize(70, 25));
        detTranslationPosEdit->setMaximumSize(QSize(70, 25));

        detTranslationLayout2->addWidget(detTranslationPosEdit, 0, 0, 1, 2);

        detTranslationNegtiveButton = new QPushButton(motionGroupBox);
        detTranslationNegtiveButton->setObjectName(QStringLiteral("detTranslationNegtiveButton"));
        detTranslationNegtiveButton->setMinimumSize(QSize(25, 25));
        detTranslationNegtiveButton->setMaximumSize(QSize(25, 25));

        detTranslationLayout2->addWidget(detTranslationNegtiveButton, 1, 0, 1, 1);

        detTranslationPositiveButton = new QPushButton(motionGroupBox);
        detTranslationPositiveButton->setObjectName(QStringLiteral("detTranslationPositiveButton"));
        detTranslationPositiveButton->setMinimumSize(QSize(25, 25));
        detTranslationPositiveButton->setMaximumSize(QSize(25, 25));

        detTranslationLayout2->addWidget(detTranslationPositiveButton, 1, 1, 1, 1);


        detTranslationLayout1->addLayout(detTranslationLayout2);

        detTranslationAbsPosButton = new QPushButton(motionGroupBox);
        detTranslationAbsPosButton->setObjectName(QStringLiteral("detTranslationAbsPosButton"));
        detTranslationAbsPosButton->setMinimumSize(QSize(45, 45));
        detTranslationAbsPosButton->setMaximumSize(QSize(45, 45));

        detTranslationLayout1->addWidget(detTranslationAbsPosButton);

        detTranslationSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        detTranslationLayout1->addItem(detTranslationSpacer);

        detTranslationLayout3 = new QVBoxLayout();
        detTranslationLayout3->setObjectName(QStringLiteral("detTranslationLayout3"));
        detTranslationStaticLabel = new QLabel(motionGroupBox);
        detTranslationStaticLabel->setObjectName(QStringLiteral("detTranslationStaticLabel"));

        detTranslationLayout3->addWidget(detTranslationStaticLabel);

        detTranslationHorizontalSlider = new QSlider(motionGroupBox);
        detTranslationHorizontalSlider->setObjectName(QStringLiteral("detTranslationHorizontalSlider"));
        detTranslationHorizontalSlider->setMinimumSize(QSize(190, 0));
        detTranslationHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        detTranslationHorizontalSlider->setOrientation(Qt::Horizontal);

        detTranslationLayout3->addWidget(detTranslationHorizontalSlider);


        detTranslationLayout1->addLayout(detTranslationLayout3);


        motionGroupLayout1->addLayout(detTranslationLayout1);

        detTranslationLine = new QFrame(motionGroupBox);
        detTranslationLine->setObjectName(QStringLiteral("detTranslationLine"));
        detTranslationLine->setMinimumSize(QSize(350, 2));
        detTranslationLine->setMaximumSize(QSize(350, 2));
        detTranslationLine->setLayoutDirection(Qt::LeftToRight);
        detTranslationLine->setFrameShape(QFrame::HLine);
        detTranslationLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(detTranslationLine);
#endif
#ifdef DETRADIAL
        detRadialLayout1 = new QHBoxLayout();
        detRadialLayout1->setObjectName(QStringLiteral("detRadialLayout1"));
        detRadialLayout2 = new QGridLayout();
        detRadialLayout2->setObjectName(QStringLiteral("detRadialLayout2"));
        detRadialPosEdit = new QLineEdit(motionGroupBox);
        detRadialPosEdit->setObjectName(QStringLiteral("detRadialPosEdit"));
        detRadialPosEdit->setMinimumSize(QSize(70, 25));
        detRadialPosEdit->setMaximumSize(QSize(70, 25));

        detRadialLayout2->addWidget(detRadialPosEdit, 0, 0, 1, 2);

        detRadialNegtiveButton = new QPushButton(motionGroupBox);
        detRadialNegtiveButton->setObjectName(QStringLiteral("detRadialNegtiveButton"));
        detRadialNegtiveButton->setMinimumSize(QSize(25, 25));
        detRadialNegtiveButton->setMaximumSize(QSize(25, 25));

        detRadialLayout2->addWidget(detRadialNegtiveButton, 1, 0, 1, 1);

        detRadialPositiveButton = new QPushButton(motionGroupBox);
        detRadialPositiveButton->setObjectName(QStringLiteral("detRadialPositiveButton"));
        detRadialPositiveButton->setMinimumSize(QSize(25, 25));
        detRadialPositiveButton->setMaximumSize(QSize(25, 25));

        detRadialLayout2->addWidget(detRadialPositiveButton, 1, 1, 1, 1);


        detRadialLayout1->addLayout(detRadialLayout2);

        detRadialAbsPosButton = new QPushButton(motionGroupBox);
        detRadialAbsPosButton->setObjectName(QStringLiteral("detRadialAbsPosButton"));
        detRadialAbsPosButton->setMinimumSize(QSize(45, 45));
        detRadialAbsPosButton->setMaximumSize(QSize(45, 45));

        detRadialLayout1->addWidget(detRadialAbsPosButton);

        detRadialSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        detRadialLayout1->addItem(detRadialSpacer);

        detRadialLayout3 = new QVBoxLayout();
        detRadialLayout3->setObjectName(QStringLiteral("detRadialLayout3"));
        detRadialStaticLabel = new QLabel(motionGroupBox);
        detRadialStaticLabel->setObjectName(QStringLiteral("detRadialStaticLabel"));

        detRadialLayout3->addWidget(detRadialStaticLabel);

        detRadialHorizontalSlider = new QSlider(motionGroupBox);
        detRadialHorizontalSlider->setObjectName(QStringLiteral("detRadialHorizontalSlider"));
        detRadialHorizontalSlider->setMinimumSize(QSize(190, 0));
        detRadialHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        detRadialHorizontalSlider->setOrientation(Qt::Horizontal);

        detRadialLayout3->addWidget(detRadialHorizontalSlider);


        detRadialLayout1->addLayout(detRadialLayout3);


        motionGroupLayout1->addLayout(detRadialLayout1);

        detRadialLine = new QFrame(motionGroupBox);
        detRadialLine->setObjectName(QStringLiteral("detRadialLine"));
        detRadialLine->setMinimumSize(QSize(350, 2));
        detRadialLine->setMaximumSize(QSize(350, 2));
        detRadialLine->setLayoutDirection(Qt::LeftToRight);
        detRadialLine->setFrameShape(QFrame::HLine);
        detRadialLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(detRadialLine);
#endif
#ifdef RAYLAYER
        rayLayerLayout1 = new QHBoxLayout();
        rayLayerLayout1->setObjectName(QStringLiteral("rayLayerLayout1"));
        rayLayerLayout2 = new QGridLayout();
        rayLayerLayout2->setObjectName(QStringLiteral("rayLayerLayout2"));
        rayLayerPosEdit = new QLineEdit(motionGroupBox);
        rayLayerPosEdit->setObjectName(QStringLiteral("rayLayerPosEdit"));
        rayLayerPosEdit->setMinimumSize(QSize(70, 25));
        rayLayerPosEdit->setMaximumSize(QSize(70, 25));

        rayLayerLayout2->addWidget(rayLayerPosEdit, 0, 0, 1, 2);

        rayLayerNegtiveButton = new QPushButton(motionGroupBox);
        rayLayerNegtiveButton->setObjectName(QStringLiteral("rayLayerNegtiveButton"));
        rayLayerNegtiveButton->setMinimumSize(QSize(25, 25));
        rayLayerNegtiveButton->setMaximumSize(QSize(25, 25));

        rayLayerLayout2->addWidget(rayLayerNegtiveButton, 1, 0, 1, 1);

        rayLayerPositiveButton = new QPushButton(motionGroupBox);
        rayLayerPositiveButton->setObjectName(QStringLiteral("rayLayerPositiveButton"));
        rayLayerPositiveButton->setMinimumSize(QSize(25, 25));
        rayLayerPositiveButton->setMaximumSize(QSize(25, 25));

        rayLayerLayout2->addWidget(rayLayerPositiveButton, 1, 1, 1, 1);


        rayLayerLayout1->addLayout(rayLayerLayout2);

        rayLayerAbsPosButton = new QPushButton(motionGroupBox);
        rayLayerAbsPosButton->setObjectName(QStringLiteral("rayLayerAbsPosButton"));
        rayLayerAbsPosButton->setMinimumSize(QSize(45, 45));
        rayLayerAbsPosButton->setMaximumSize(QSize(45, 45));

        rayLayerLayout1->addWidget(rayLayerAbsPosButton);

        rayLayerSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        rayLayerLayout1->addItem(rayLayerSpacer);

        rayLayerLayout3 = new QVBoxLayout();
        rayLayerLayout3->setObjectName(QStringLiteral("rayLayerLayout3"));
        rayLayerStaticLabel = new QLabel(motionGroupBox);
        rayLayerStaticLabel->setObjectName(QStringLiteral("rayLayerStaticLabel"));

        rayLayerLayout3->addWidget(rayLayerStaticLabel);

        rayLayerHorizontalSlider = new QSlider(motionGroupBox);
        rayLayerHorizontalSlider->setObjectName(QStringLiteral("rayLayerHorizontalSlider"));
        rayLayerHorizontalSlider->setMinimumSize(QSize(190, 0));
        rayLayerHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        rayLayerHorizontalSlider->setOrientation(Qt::Horizontal);

        rayLayerLayout3->addWidget(rayLayerHorizontalSlider);


        rayLayerLayout1->addLayout(rayLayerLayout3);


        motionGroupLayout1->addLayout(rayLayerLayout1);

        rayLayerLine = new QFrame(motionGroupBox);
        rayLayerLine->setObjectName(QStringLiteral("rayLayerLine"));
        rayLayerLine->setMinimumSize(QSize(350, 2));
        rayLayerLine->setMaximumSize(QSize(350, 2));
        rayLayerLine->setLayoutDirection(Qt::LeftToRight);
        rayLayerLine->setFrameShape(QFrame::HLine);
        rayLayerLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(rayLayerLine);
#endif
#ifdef DEFLECT
        deflectLayout1 = new QHBoxLayout();
        deflectLayout1->setObjectName(QStringLiteral("deflectLayout1"));
        deflectLayout2 = new QGridLayout();
        deflectLayout2->setObjectName(QStringLiteral("deflectLayout2"));
        deflectPosEdit = new QLineEdit(motionGroupBox);
        deflectPosEdit->setObjectName(QStringLiteral("deflectPosEdit"));
        deflectPosEdit->setMinimumSize(QSize(70, 25));
        deflectPosEdit->setMaximumSize(QSize(70, 25));

        deflectLayout2->addWidget(deflectPosEdit, 0, 0, 1, 2);

        deflectNegtiveButton = new QPushButton(motionGroupBox);
        deflectNegtiveButton->setObjectName(QStringLiteral("deflectNegtiveButton"));
        deflectNegtiveButton->setMinimumSize(QSize(25, 25));
        deflectNegtiveButton->setMaximumSize(QSize(25, 25));

        deflectLayout2->addWidget(deflectNegtiveButton, 1, 0, 1, 1);

        deflectPositiveButton = new QPushButton(motionGroupBox);
        deflectPositiveButton->setObjectName(QStringLiteral("deflectPositiveButton"));
        deflectPositiveButton->setMinimumSize(QSize(25, 25));
        deflectPositiveButton->setMaximumSize(QSize(25, 25));

        deflectLayout2->addWidget(deflectPositiveButton, 1, 1, 1, 1);


        deflectLayout1->addLayout(deflectLayout2);

        deflectAbsPosButton = new QPushButton(motionGroupBox);
        deflectAbsPosButton->setObjectName(QStringLiteral("deflectAbsPosButton"));
        deflectAbsPosButton->setMinimumSize(QSize(45, 45));
        deflectAbsPosButton->setMaximumSize(QSize(45, 45));

        deflectLayout1->addWidget(deflectAbsPosButton);

        deflectSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        deflectLayout1->addItem(deflectSpacer);

        deflectLayout3 = new QVBoxLayout();
        deflectLayout3->setObjectName(QStringLiteral("deflectLayout3"));
        deflectStaticLabel = new QLabel(motionGroupBox);
        deflectStaticLabel->setObjectName(QStringLiteral("deflectStaticLabel"));

        deflectLayout3->addWidget(deflectStaticLabel);

        deflectHorizontalSlider = new QSlider(motionGroupBox);
        deflectHorizontalSlider->setObjectName(QStringLiteral("deflectHorizontalSlider"));
        deflectHorizontalSlider->setMinimumSize(QSize(190, 0));
        deflectHorizontalSlider->setMaximumSize(QSize(190, 16777215));
        deflectHorizontalSlider->setOrientation(Qt::Horizontal);

        deflectLayout3->addWidget(deflectHorizontalSlider);


        deflectLayout1->addLayout(deflectLayout3);


        motionGroupLayout1->addLayout(deflectLayout1);

        deflectLine = new QFrame(motionGroupBox);
        deflectLine->setObjectName(QStringLiteral("deflectLine"));
        deflectLine->setMinimumSize(QSize(350, 2));
        deflectLine->setMaximumSize(QSize(350, 2));
        deflectLine->setLayoutDirection(Qt::LeftToRight);
        deflectLine->setFrameShape(QFrame::HLine);
        deflectLine->setFrameShadow(QFrame::Sunken);

        motionGroupLayout1->addWidget(deflectLine);
#endif

        verticalLayout_2->addWidget(motionGroupBox);
        sampleChooseButtonLayout1 = new QHBoxLayout();
        sampleChooseButtonLayout1->setObjectName(QStringLiteral("sampleChooseButtonLayout1"));
        sampleChooseButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sampleChooseButtonLayout1->addItem(sampleChooseButtonSpacer);

        sampleChooseButton = new QPushButton(widget);
        sampleChooseButton->setObjectName(QStringLiteral("sampleChooseButton"));

        sampleChooseButtonLayout1->addWidget(sampleChooseButton);


        verticalLayout_2->addLayout(sampleChooseButtonLayout1);


        retranslateUi(rayPanelMotionWidget);
        mainStrechSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(mainStrechSpacer);

        verticalLayout_2->setStretch(5, 1);

        rayTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(rayPanelMotionWidget);
    } // setupUi

    void retranslateUi(QWidget *rayPanelMotionWidget)
    {
        rayPanelMotionWidget->setWindowTitle(QApplication::translate("rayPanelMotionWidget", "Form", nullptr));
        worx225XRayOffButton_2->setText(QApplication::translate("rayPanelMotionWidget", "\345\201\234\346\235\237", nullptr));
        worx225kvStaticLabel_2->setText(QApplication::translate("rayPanelMotionWidget", "KV", nullptr));
        worx225uaStaticLabel_2->setText(QApplication::translate("rayPanelMotionWidget", "\316\274A", nullptr));
        worx225XRayOnButton_2->setText(QApplication::translate("rayPanelMotionWidget", "\345\207\272\346\235\237", nullptr));
        worx225FocusStaticLabel_2->setText(QApplication::translate("rayPanelMotionWidget", "\347\204\246\347\202\271", nullptr));
        rayTab->setTabText(rayTab->indexOf(rayWrox225Tab), QApplication::translate("rayPanelMotionWidget", "WROX", nullptr));
        Comet450uaStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\316\274A", nullptr));
        Comet450XRayOffButton->setText(QApplication::translate("rayPanelMotionWidget", "\345\201\234\346\235\237", nullptr));
        Comet450kvStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "KV", nullptr));
        Comet450XRayOnButton->setText(QApplication::translate("rayPanelMotionWidget", "\345\207\272\346\235\237", nullptr));
        Comet450FocusStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\347\204\246\347\202\271", nullptr));
        rayTab->setTabText(rayTab->indexOf(rayComet450Tab), QApplication::translate("rayPanelMotionWidget", "COMET", nullptr));
        panelGroupBox->setTitle(QApplication::translate("rayPanelMotionWidget", "\351\235\242\351\230\265\346\216\242\346\265\213\345\231\250", nullptr));
        binStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\345\220\210\345\271\266", nullptr));
        gainStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\345\242\236\347\233\212", nullptr));
        frameAverageCheckBox->setText(QApplication::translate("rayPanelMotionWidget", "\345\270\247\345\271\263\345\235\207", nullptr));
        sampleTimeStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
        scanSetupGroupBox->setTitle(QApplication::translate("rayPanelMotionWidget", "ScanSetup", nullptr));
        sodStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\346\272\220-\346\216\242[mm]", nullptr));
        sodLabel->setText(QApplication::translate("rayPanelMotionWidget", "TextLabel", nullptr));
        sddStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\346\272\220-\347\211\251[mm]", nullptr));
        sddLabel->setText(QApplication::translate("rayPanelMotionWidget", "TextLabel", nullptr));
        scanSetupButton->setText(QApplication::translate("rayPanelMotionWidget", "PushButton", nullptr));
        motionGroupBox->setTitle(QApplication::translate("rayPanelMotionWidget", "\350\277\220\345\212\250", nullptr));
        tableRotNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        tableRotPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        tableRotAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        tableRotStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\345\267\245\344\273\266\346\227\213\350\275\254", nullptr));
#ifdef TABLETRANSLATION
        tableTranslationNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        tableTranslationPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        tableTranslationAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        tableTranslationStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\345\267\245\344\273\266\345\271\263\347\247\273", nullptr));
#endif
#ifdef TABLERADIAL
        tableRadialNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        tableRadialPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        tableRadialAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        tableRadialStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\345\267\245\344\273\266\345\276\204\345\220\221", nullptr));
#endif
#ifdef DETLAYER
        detLayerNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        detLayerPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        detLayerAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        detLayerStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\346\216\242\346\265\213\345\215\207\351\231\215", nullptr));
#endif
#ifdef DETTRANSLATION
        detTranslationNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        detTranslationPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        detTranslationAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        detTranslationStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\346\216\242\346\265\213\345\271\263\347\247\273", nullptr));
#endif
#ifdef DETRADIAL
        detRadialNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        detRadialPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        detRadialAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        detRadialStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\346\216\242\346\265\213\345\276\204\345\220\221", nullptr));
#endif
#ifdef RAYLAYER
        rayLayerNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        rayLayerPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        rayLayerAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        rayLayerStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\345\260\204\347\272\277\345\215\207\351\231\215", nullptr));
#endif
#ifdef DEFLECT
        deflectNegtiveButton->setText(QApplication::translate("rayPanelMotionWidget", "<<", nullptr));
        deflectPositiveButton->setText(QApplication::translate("rayPanelMotionWidget", ">>", nullptr));
        deflectAbsPosButton->setText(QApplication::translate("rayPanelMotionWidget", "\347\273\235\345\257\271\n"
            "\345\256\232\344\275\215", nullptr));
        deflectStaticLabel->setText(QApplication::translate("rayPanelMotionWidget", "\345\201\217\346\221\206", nullptr));
#endif

        sampleChooseButton->setText(QApplication::translate("rayPanelMotionWidget", "\351\207\207\351\233\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rayPanelMotionWidget : public Ui_rayPanelMotionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYPANELMOTION_H
