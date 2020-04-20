/********************************************************************************
** Form generated from reading UI file 'MotorControl.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORCONTROL_H
#define UI_MOTORCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotorControl
{
public:
    QGroupBox *motionGroupBox;
    QFrame *tableRadialLine;
    QFrame *tableRotLine;
    QFrame *tableTranslationLine;
    QFrame *detLayerLine;
    QFrame *detTranslationLine;
    QFrame *detRadialLine;
    QFrame *deflectLine;
    QWidget *layoutWidget;
    QHBoxLayout *detLayerLayout1_2;
    QLabel *label_8;
    QGridLayout *detLayerLayout2_2;
    QLineEdit *rayLayerPosEdit;
    QPushButton *rayLayerNegtiveButton;
    QPushButton *rayLayerPositiveButton;
    QPushButton *rayLayerAbsPosButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *rayLayerStaticLabel;
    QSlider *rayLayerHorizontalSlider;
    QFrame *line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QLineEdit *tableRotationPosEdit;
    QPushButton *tableRotNegtiveButton;
    QPushButton *tableRotPositiveButton;
    QPushButton *tableRotAbsPosButton;
    QVBoxLayout *tableRotLayout3;
    QLabel *tableRotStaticLabel;
    QSlider *tableRotHorizontalSlider;
    QWidget *widget1;
    QHBoxLayout *tableTranslationLayou1;
    QLabel *label_6;
    QGridLayout *tableTranslationLayou2;
    QLineEdit *tableTranslationPosEdit;
    QPushButton *tableTranslationNegtiveButton;
    QPushButton *tableTranslationPositiveButton;
    QPushButton *tableTranslationAbsPosButton;
    QVBoxLayout *tableTranslationLayout3;
    QLabel *tableTranslationStaticLabel;
    QSlider *tableTranslationHorizontalSlider;
    QWidget *widget2;
    QHBoxLayout *deflectLayout1;
    QLabel *label_2;
    QGridLayout *deflectLayout2;
    QLineEdit *deflectPosEdit;
    QPushButton *deflectNegtiveButton;
    QPushButton *deflectPositiveButton;
    QPushButton *deflectAbsPosButton;
    QVBoxLayout *deflectLayout3;
    QLabel *deflectStaticLabel;
    QSlider *deflectHorizontalSlider;
    QWidget *widget3;
    QHBoxLayout *tableRadialLayout1;
    QLabel *label_7;
    QGridLayout *tableRadialLayout2;
    QLineEdit *tableRadialPosEdit;
    QPushButton *tableRadialNegtiveButton;
    QPushButton *tableRadialPositiveButton;
    QPushButton *tableRadialAbsPosButton;
    QVBoxLayout *tableRadialLayout3;
    QLabel *tableRadialStaticLabel;
    QSlider *tableRadialHorizontalSlider;
    QWidget *widget4;
    QHBoxLayout *detRadialLayout1;
    QLabel *label_5;
    QGridLayout *detRadialLayout2;
    QLineEdit *detRadialPosEdit;
    QPushButton *detRadialNegtiveButton;
    QPushButton *detRadialPositiveButton;
    QPushButton *detRadialAbsPosButton;
    QVBoxLayout *detRadialLayout3;
    QLabel *detRadialStaticLabel;
    QSlider *detRadialHorizontalSlider;
    QWidget *widget5;
    QHBoxLayout *detTranslationLayout1;
    QLabel *label_4;
    QGridLayout *detTranslationLayout2;
    QLineEdit *detTranslationPosEdit;
    QPushButton *detTranslationNegtiveButton;
    QPushButton *detTranslationPositiveButton;
    QPushButton *detTranslationAbsPosButton;
    QVBoxLayout *detTranslationLayout3;
    QLabel *detTranslationStaticLabel;
    QSlider *detTranslationHorizontalSlider;
    QWidget *widget6;
    QHBoxLayout *detLayerLayout1;
    QLabel *label_3;
    QGridLayout *detLayerLayout2;
    QLineEdit *detLayerPosEdit;
    QPushButton *detLayerNegtiveButton;
    QPushButton *detLayerPositiveButton;
    QPushButton *detLayerAbsPosButton;
    QVBoxLayout *verticalLayout;
    QLabel *detLayerStaticLabel;
    QSlider *detLayerHorizontalSlider;

    void setupUi(QWidget *MotorControl)
    {
        if (MotorControl->objectName().isEmpty())
            MotorControl->setObjectName(QStringLiteral("MotorControl"));
        MotorControl->resize(329, 686);
        motionGroupBox = new QGroupBox(MotorControl);
        motionGroupBox->setObjectName(QStringLiteral("motionGroupBox"));
        motionGroupBox->setGeometry(QRect(10, 0, 300, 651));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(motionGroupBox->sizePolicy().hasHeightForWidth());
        motionGroupBox->setSizePolicy(sizePolicy);
        motionGroupBox->setMinimumSize(QSize(300, 0));
        motionGroupBox->setMaximumSize(QSize(300, 1000));
        tableRadialLine = new QFrame(motionGroupBox);
        tableRadialLine->setObjectName(QStringLiteral("tableRadialLine"));
        tableRadialLine->setGeometry(QRect(10, 89, 350, 16));
        tableRadialLine->setMinimumSize(QSize(350, 0));
        tableRadialLine->setMaximumSize(QSize(350, 16777215));
        tableRadialLine->setLayoutDirection(Qt::LeftToRight);
        tableRadialLine->setFrameShape(QFrame::HLine);
        tableRadialLine->setFrameShadow(QFrame::Sunken);
        tableRotLine = new QFrame(motionGroupBox);
        tableRotLine->setObjectName(QStringLiteral("tableRotLine"));
        tableRotLine->setGeometry(QRect(10, 165, 350, 2));
        tableRotLine->setMinimumSize(QSize(350, 2));
        tableRotLine->setMaximumSize(QSize(350, 2));
        tableRotLine->setLayoutDirection(Qt::LeftToRight);
        tableRotLine->setFrameShape(QFrame::HLine);
        tableRotLine->setFrameShadow(QFrame::Sunken);
        tableTranslationLine = new QFrame(motionGroupBox);
        tableTranslationLine->setObjectName(QStringLiteral("tableTranslationLine"));
        tableTranslationLine->setGeometry(QRect(10, 240, 350, 2));
        tableTranslationLine->setMinimumSize(QSize(350, 2));
        tableTranslationLine->setMaximumSize(QSize(350, 2));
        tableTranslationLine->setLayoutDirection(Qt::LeftToRight);
        tableTranslationLine->setFrameShape(QFrame::HLine);
        tableTranslationLine->setFrameShadow(QFrame::Sunken);
        detLayerLine = new QFrame(motionGroupBox);
        detLayerLine->setObjectName(QStringLiteral("detLayerLine"));
        detLayerLine->setGeometry(QRect(10, 314, 350, 2));
        detLayerLine->setMinimumSize(QSize(350, 2));
        detLayerLine->setMaximumSize(QSize(350, 2));
        detLayerLine->setLayoutDirection(Qt::LeftToRight);
        detLayerLine->setFrameShape(QFrame::HLine);
        detLayerLine->setFrameShadow(QFrame::Sunken);
        detTranslationLine = new QFrame(motionGroupBox);
        detTranslationLine->setObjectName(QStringLiteral("detTranslationLine"));
        detTranslationLine->setGeometry(QRect(10, 389, 350, 2));
        detTranslationLine->setMinimumSize(QSize(350, 2));
        detTranslationLine->setMaximumSize(QSize(350, 2));
        detTranslationLine->setLayoutDirection(Qt::LeftToRight);
        detTranslationLine->setFrameShape(QFrame::HLine);
        detTranslationLine->setFrameShadow(QFrame::Sunken);
        detRadialLine = new QFrame(motionGroupBox);
        detRadialLine->setObjectName(QStringLiteral("detRadialLine"));
        detRadialLine->setGeometry(QRect(10, 464, 350, 2));
        detRadialLine->setMinimumSize(QSize(350, 2));
        detRadialLine->setMaximumSize(QSize(350, 2));
        detRadialLine->setLayoutDirection(Qt::LeftToRight);
        detRadialLine->setFrameShape(QFrame::HLine);
        detRadialLine->setFrameShadow(QFrame::Sunken);
        deflectLine = new QFrame(motionGroupBox);
        deflectLine->setObjectName(QStringLiteral("deflectLine"));
        deflectLine->setGeometry(QRect(10, 539, 350, 2));
        deflectLine->setMinimumSize(QSize(350, 2));
        deflectLine->setMaximumSize(QSize(350, 2));
        deflectLine->setLayoutDirection(Qt::LeftToRight);
        deflectLine->setFrameShape(QFrame::HLine);
        deflectLine->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(motionGroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 550, 279, 60));
        detLayerLayout1_2 = new QHBoxLayout(layoutWidget);
        detLayerLayout1_2->setSpacing(1);
        detLayerLayout1_2->setContentsMargins(11, 11, 11, 11);
        detLayerLayout1_2->setObjectName(QStringLiteral("detLayerLayout1_2"));
        detLayerLayout1_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(50, 0));
        label_8->setMaximumSize(QSize(50, 16777215));

        detLayerLayout1_2->addWidget(label_8);

        detLayerLayout2_2 = new QGridLayout();
        detLayerLayout2_2->setSpacing(6);
        detLayerLayout2_2->setObjectName(QStringLiteral("detLayerLayout2_2"));
        rayLayerPosEdit = new QLineEdit(layoutWidget);
        rayLayerPosEdit->setObjectName(QStringLiteral("rayLayerPosEdit"));
        rayLayerPosEdit->setMinimumSize(QSize(70, 25));
        rayLayerPosEdit->setMaximumSize(QSize(70, 25));

        detLayerLayout2_2->addWidget(rayLayerPosEdit, 0, 0, 1, 2);

        rayLayerNegtiveButton = new QPushButton(layoutWidget);
        rayLayerNegtiveButton->setObjectName(QStringLiteral("rayLayerNegtiveButton"));
        rayLayerNegtiveButton->setMinimumSize(QSize(25, 25));
        rayLayerNegtiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2_2->addWidget(rayLayerNegtiveButton, 1, 0, 1, 1);

        rayLayerPositiveButton = new QPushButton(layoutWidget);
        rayLayerPositiveButton->setObjectName(QStringLiteral("rayLayerPositiveButton"));
        rayLayerPositiveButton->setMinimumSize(QSize(25, 25));
        rayLayerPositiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2_2->addWidget(rayLayerPositiveButton, 1, 1, 1, 1);


        detLayerLayout1_2->addLayout(detLayerLayout2_2);

        rayLayerAbsPosButton = new QPushButton(layoutWidget);
        rayLayerAbsPosButton->setObjectName(QStringLiteral("rayLayerAbsPosButton"));
        rayLayerAbsPosButton->setMinimumSize(QSize(50, 50));
        rayLayerAbsPosButton->setMaximumSize(QSize(50, 50));

        detLayerLayout1_2->addWidget(rayLayerAbsPosButton);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rayLayerStaticLabel = new QLabel(layoutWidget);
        rayLayerStaticLabel->setObjectName(QStringLiteral("rayLayerStaticLabel"));

        verticalLayout_2->addWidget(rayLayerStaticLabel);

        rayLayerHorizontalSlider = new QSlider(layoutWidget);
        rayLayerHorizontalSlider->setObjectName(QStringLiteral("rayLayerHorizontalSlider"));
        rayLayerHorizontalSlider->setMinimumSize(QSize(100, 0));
        rayLayerHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        rayLayerHorizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(rayLayerHorizontalSlider);


        detLayerLayout1_2->addLayout(verticalLayout_2);

        line = new QFrame(motionGroupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 620, 281, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(motionGroupBox);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableRotationPosEdit = new QLineEdit(widget);
        tableRotationPosEdit->setObjectName(QStringLiteral("tableRotationPosEdit"));
        tableRotationPosEdit->setMinimumSize(QSize(70, 25));
        tableRotationPosEdit->setMaximumSize(QSize(70, 25));

        gridLayout->addWidget(tableRotationPosEdit, 0, 0, 1, 2);

        tableRotNegtiveButton = new QPushButton(widget);
        tableRotNegtiveButton->setObjectName(QStringLiteral("tableRotNegtiveButton"));
        tableRotNegtiveButton->setMinimumSize(QSize(25, 25));
        tableRotNegtiveButton->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(tableRotNegtiveButton, 1, 0, 1, 1);

        tableRotPositiveButton = new QPushButton(widget);
        tableRotPositiveButton->setObjectName(QStringLiteral("tableRotPositiveButton"));
        tableRotPositiveButton->setMinimumSize(QSize(25, 25));
        tableRotPositiveButton->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(tableRotPositiveButton, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        tableRotAbsPosButton = new QPushButton(widget);
        tableRotAbsPosButton->setObjectName(QStringLiteral("tableRotAbsPosButton"));
        tableRotAbsPosButton->setMinimumSize(QSize(50, 50));
        tableRotAbsPosButton->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(tableRotAbsPosButton);

        tableRotLayout3 = new QVBoxLayout();
        tableRotLayout3->setSpacing(6);
        tableRotLayout3->setObjectName(QStringLiteral("tableRotLayout3"));
        tableRotLayout3->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableRotStaticLabel = new QLabel(widget);
        tableRotStaticLabel->setObjectName(QStringLiteral("tableRotStaticLabel"));
        sizePolicy.setHeightForWidth(tableRotStaticLabel->sizePolicy().hasHeightForWidth());
        tableRotStaticLabel->setSizePolicy(sizePolicy);

        tableRotLayout3->addWidget(tableRotStaticLabel);

        tableRotHorizontalSlider = new QSlider(widget);
        tableRotHorizontalSlider->setObjectName(QStringLiteral("tableRotHorizontalSlider"));
        tableRotHorizontalSlider->setMinimumSize(QSize(100, 0));
        tableRotHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        tableRotHorizontalSlider->setOrientation(Qt::Horizontal);

        tableRotLayout3->addWidget(tableRotHorizontalSlider);


        horizontalLayout->addLayout(tableRotLayout3);

        widget1 = new QWidget(motionGroupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        tableTranslationLayou1 = new QHBoxLayout(widget1);
        tableTranslationLayou1->setSpacing(1);
        tableTranslationLayou1->setContentsMargins(11, 11, 11, 11);
        tableTranslationLayou1->setObjectName(QStringLiteral("tableTranslationLayou1"));
        tableTranslationLayou1->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(50, 0));
        label_6->setMaximumSize(QSize(50, 16777215));

        tableTranslationLayou1->addWidget(label_6);

        tableTranslationLayou2 = new QGridLayout();
        tableTranslationLayou2->setSpacing(6);
        tableTranslationLayou2->setObjectName(QStringLiteral("tableTranslationLayou2"));
        tableTranslationPosEdit = new QLineEdit(widget1);
        tableTranslationPosEdit->setObjectName(QStringLiteral("tableTranslationPosEdit"));
        tableTranslationPosEdit->setMinimumSize(QSize(70, 25));
        tableTranslationPosEdit->setMaximumSize(QSize(70, 25));

        tableTranslationLayou2->addWidget(tableTranslationPosEdit, 0, 0, 1, 2);

        tableTranslationNegtiveButton = new QPushButton(widget1);
        tableTranslationNegtiveButton->setObjectName(QStringLiteral("tableTranslationNegtiveButton"));
        tableTranslationNegtiveButton->setMinimumSize(QSize(25, 25));
        tableTranslationNegtiveButton->setMaximumSize(QSize(25, 25));

        tableTranslationLayou2->addWidget(tableTranslationNegtiveButton, 1, 0, 1, 1);

        tableTranslationPositiveButton = new QPushButton(widget1);
        tableTranslationPositiveButton->setObjectName(QStringLiteral("tableTranslationPositiveButton"));
        tableTranslationPositiveButton->setMinimumSize(QSize(25, 25));
        tableTranslationPositiveButton->setMaximumSize(QSize(25, 25));

        tableTranslationLayou2->addWidget(tableTranslationPositiveButton, 1, 1, 1, 1);


        tableTranslationLayou1->addLayout(tableTranslationLayou2);

        tableTranslationAbsPosButton = new QPushButton(widget1);
        tableTranslationAbsPosButton->setObjectName(QStringLiteral("tableTranslationAbsPosButton"));
        tableTranslationAbsPosButton->setMinimumSize(QSize(50, 50));
        tableTranslationAbsPosButton->setMaximumSize(QSize(50, 50));

        tableTranslationLayou1->addWidget(tableTranslationAbsPosButton);

        tableTranslationLayout3 = new QVBoxLayout();
        tableTranslationLayout3->setSpacing(6);
        tableTranslationLayout3->setObjectName(QStringLiteral("tableTranslationLayout3"));
        tableTranslationStaticLabel = new QLabel(widget1);
        tableTranslationStaticLabel->setObjectName(QStringLiteral("tableTranslationStaticLabel"));

        tableTranslationLayout3->addWidget(tableTranslationStaticLabel);

        tableTranslationHorizontalSlider = new QSlider(widget1);
        tableTranslationHorizontalSlider->setObjectName(QStringLiteral("tableTranslationHorizontalSlider"));
        tableTranslationHorizontalSlider->setMinimumSize(QSize(100, 0));
        tableTranslationHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        tableTranslationHorizontalSlider->setOrientation(Qt::Horizontal);

        tableTranslationLayout3->addWidget(tableTranslationHorizontalSlider);


        tableTranslationLayou1->addLayout(tableTranslationLayout3);

        widget2 = new QWidget(motionGroupBox);
        widget2->setObjectName(QStringLiteral("widget2"));
        deflectLayout1 = new QHBoxLayout(widget2);
        deflectLayout1->setSpacing(1);
        deflectLayout1->setContentsMargins(11, 11, 11, 11);
        deflectLayout1->setObjectName(QStringLiteral("deflectLayout1"));
        deflectLayout1->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));

        deflectLayout1->addWidget(label_2);

        deflectLayout2 = new QGridLayout();
        deflectLayout2->setSpacing(6);
        deflectLayout2->setObjectName(QStringLiteral("deflectLayout2"));
        deflectPosEdit = new QLineEdit(widget2);
        deflectPosEdit->setObjectName(QStringLiteral("deflectPosEdit"));
        deflectPosEdit->setMinimumSize(QSize(70, 25));
        deflectPosEdit->setMaximumSize(QSize(70, 25));

        deflectLayout2->addWidget(deflectPosEdit, 0, 1, 1, 2);

        deflectNegtiveButton = new QPushButton(widget2);
        deflectNegtiveButton->setObjectName(QStringLiteral("deflectNegtiveButton"));
        deflectNegtiveButton->setMinimumSize(QSize(25, 25));
        deflectNegtiveButton->setMaximumSize(QSize(25, 25));

        deflectLayout2->addWidget(deflectNegtiveButton, 1, 1, 1, 1);

        deflectPositiveButton = new QPushButton(widget2);
        deflectPositiveButton->setObjectName(QStringLiteral("deflectPositiveButton"));
        deflectPositiveButton->setMinimumSize(QSize(25, 25));
        deflectPositiveButton->setMaximumSize(QSize(25, 25));

        deflectLayout2->addWidget(deflectPositiveButton, 1, 2, 1, 1);


        deflectLayout1->addLayout(deflectLayout2);

        deflectAbsPosButton = new QPushButton(widget2);
        deflectAbsPosButton->setObjectName(QStringLiteral("deflectAbsPosButton"));
        deflectAbsPosButton->setMinimumSize(QSize(50, 50));
        deflectAbsPosButton->setMaximumSize(QSize(50, 50));

        deflectLayout1->addWidget(deflectAbsPosButton);

        deflectLayout3 = new QVBoxLayout();
        deflectLayout3->setSpacing(6);
        deflectLayout3->setObjectName(QStringLiteral("deflectLayout3"));
        deflectStaticLabel = new QLabel(widget2);
        deflectStaticLabel->setObjectName(QStringLiteral("deflectStaticLabel"));

        deflectLayout3->addWidget(deflectStaticLabel);

        deflectHorizontalSlider = new QSlider(widget2);
        deflectHorizontalSlider->setObjectName(QStringLiteral("deflectHorizontalSlider"));
        deflectHorizontalSlider->setMinimumSize(QSize(100, 0));
        deflectHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        deflectHorizontalSlider->setOrientation(Qt::Horizontal);

        deflectLayout3->addWidget(deflectHorizontalSlider);


        deflectLayout1->addLayout(deflectLayout3);

        widget3 = new QWidget(motionGroupBox);
        widget3->setObjectName(QStringLiteral("widget3"));
        tableRadialLayout1 = new QHBoxLayout(widget3);
        tableRadialLayout1->setSpacing(1);
        tableRadialLayout1->setContentsMargins(11, 11, 11, 11);
        tableRadialLayout1->setObjectName(QStringLiteral("tableRadialLayout1"));
        tableRadialLayout1->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(50, 0));
        label_7->setMaximumSize(QSize(50, 16777215));

        tableRadialLayout1->addWidget(label_7);

        tableRadialLayout2 = new QGridLayout();
        tableRadialLayout2->setSpacing(6);
        tableRadialLayout2->setObjectName(QStringLiteral("tableRadialLayout2"));
        tableRadialPosEdit = new QLineEdit(widget3);
        tableRadialPosEdit->setObjectName(QStringLiteral("tableRadialPosEdit"));
        tableRadialPosEdit->setMinimumSize(QSize(70, 25));
        tableRadialPosEdit->setMaximumSize(QSize(70, 25));

        tableRadialLayout2->addWidget(tableRadialPosEdit, 0, 1, 1, 2);

        tableRadialNegtiveButton = new QPushButton(widget3);
        tableRadialNegtiveButton->setObjectName(QStringLiteral("tableRadialNegtiveButton"));
        tableRadialNegtiveButton->setMinimumSize(QSize(25, 25));
        tableRadialNegtiveButton->setMaximumSize(QSize(25, 25));

        tableRadialLayout2->addWidget(tableRadialNegtiveButton, 1, 1, 1, 1);

        tableRadialPositiveButton = new QPushButton(widget3);
        tableRadialPositiveButton->setObjectName(QStringLiteral("tableRadialPositiveButton"));
        tableRadialPositiveButton->setMinimumSize(QSize(25, 25));
        tableRadialPositiveButton->setMaximumSize(QSize(25, 25));

        tableRadialLayout2->addWidget(tableRadialPositiveButton, 1, 2, 1, 1);


        tableRadialLayout1->addLayout(tableRadialLayout2);

        tableRadialAbsPosButton = new QPushButton(widget3);
        tableRadialAbsPosButton->setObjectName(QStringLiteral("tableRadialAbsPosButton"));
        tableRadialAbsPosButton->setMinimumSize(QSize(50, 50));
        tableRadialAbsPosButton->setMaximumSize(QSize(50, 50));

        tableRadialLayout1->addWidget(tableRadialAbsPosButton);

        tableRadialLayout3 = new QVBoxLayout();
        tableRadialLayout3->setSpacing(6);
        tableRadialLayout3->setObjectName(QStringLiteral("tableRadialLayout3"));
        tableRadialStaticLabel = new QLabel(widget3);
        tableRadialStaticLabel->setObjectName(QStringLiteral("tableRadialStaticLabel"));

        tableRadialLayout3->addWidget(tableRadialStaticLabel);

        tableRadialHorizontalSlider = new QSlider(widget3);
        tableRadialHorizontalSlider->setObjectName(QStringLiteral("tableRadialHorizontalSlider"));
        tableRadialHorizontalSlider->setMinimumSize(QSize(100, 0));
        tableRadialHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        tableRadialHorizontalSlider->setOrientation(Qt::Horizontal);

        tableRadialLayout3->addWidget(tableRadialHorizontalSlider);


        tableRadialLayout1->addLayout(tableRadialLayout3);

        widget4 = new QWidget(motionGroupBox);
        widget4->setObjectName(QStringLiteral("widget4"));
        detRadialLayout1 = new QHBoxLayout(widget4);
        detRadialLayout1->setSpacing(1);
        detRadialLayout1->setContentsMargins(11, 11, 11, 11);
        detRadialLayout1->setObjectName(QStringLiteral("detRadialLayout1"));
        detRadialLayout1->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(50, 0));
        label_5->setMaximumSize(QSize(50, 16777215));

        detRadialLayout1->addWidget(label_5);

        detRadialLayout2 = new QGridLayout();
        detRadialLayout2->setSpacing(6);
        detRadialLayout2->setObjectName(QStringLiteral("detRadialLayout2"));
        detRadialPosEdit = new QLineEdit(widget4);
        detRadialPosEdit->setObjectName(QStringLiteral("detRadialPosEdit"));
        detRadialPosEdit->setMinimumSize(QSize(70, 25));
        detRadialPosEdit->setMaximumSize(QSize(70, 25));

        detRadialLayout2->addWidget(detRadialPosEdit, 0, 0, 1, 2);

        detRadialNegtiveButton = new QPushButton(widget4);
        detRadialNegtiveButton->setObjectName(QStringLiteral("detRadialNegtiveButton"));
        detRadialNegtiveButton->setMinimumSize(QSize(25, 25));
        detRadialNegtiveButton->setMaximumSize(QSize(25, 25));

        detRadialLayout2->addWidget(detRadialNegtiveButton, 1, 0, 1, 1);

        detRadialPositiveButton = new QPushButton(widget4);
        detRadialPositiveButton->setObjectName(QStringLiteral("detRadialPositiveButton"));
        detRadialPositiveButton->setMinimumSize(QSize(25, 25));
        detRadialPositiveButton->setMaximumSize(QSize(25, 25));

        detRadialLayout2->addWidget(detRadialPositiveButton, 1, 1, 1, 1);


        detRadialLayout1->addLayout(detRadialLayout2);

        detRadialAbsPosButton = new QPushButton(widget4);
        detRadialAbsPosButton->setObjectName(QStringLiteral("detRadialAbsPosButton"));
        detRadialAbsPosButton->setMinimumSize(QSize(50, 50));
        detRadialAbsPosButton->setMaximumSize(QSize(50, 50));

        detRadialLayout1->addWidget(detRadialAbsPosButton);

        detRadialLayout3 = new QVBoxLayout();
        detRadialLayout3->setSpacing(6);
        detRadialLayout3->setObjectName(QStringLiteral("detRadialLayout3"));
        detRadialStaticLabel = new QLabel(widget4);
        detRadialStaticLabel->setObjectName(QStringLiteral("detRadialStaticLabel"));

        detRadialLayout3->addWidget(detRadialStaticLabel);

        detRadialHorizontalSlider = new QSlider(widget4);
        detRadialHorizontalSlider->setObjectName(QStringLiteral("detRadialHorizontalSlider"));
        detRadialHorizontalSlider->setMinimumSize(QSize(100, 0));
        detRadialHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        detRadialHorizontalSlider->setOrientation(Qt::Horizontal);

        detRadialLayout3->addWidget(detRadialHorizontalSlider);


        detRadialLayout1->addLayout(detRadialLayout3);

        widget5 = new QWidget(motionGroupBox);
        widget5->setObjectName(QStringLiteral("widget5"));
        detTranslationLayout1 = new QHBoxLayout(widget5);
        detTranslationLayout1->setSpacing(1);
        detTranslationLayout1->setContentsMargins(11, 11, 11, 11);
        detTranslationLayout1->setObjectName(QStringLiteral("detTranslationLayout1"));
        detTranslationLayout1->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));

        detTranslationLayout1->addWidget(label_4);

        detTranslationLayout2 = new QGridLayout();
        detTranslationLayout2->setSpacing(6);
        detTranslationLayout2->setObjectName(QStringLiteral("detTranslationLayout2"));
        detTranslationPosEdit = new QLineEdit(widget5);
        detTranslationPosEdit->setObjectName(QStringLiteral("detTranslationPosEdit"));
        detTranslationPosEdit->setMinimumSize(QSize(70, 25));
        detTranslationPosEdit->setMaximumSize(QSize(70, 25));

        detTranslationLayout2->addWidget(detTranslationPosEdit, 0, 0, 1, 2);

        detTranslationNegtiveButton = new QPushButton(widget5);
        detTranslationNegtiveButton->setObjectName(QStringLiteral("detTranslationNegtiveButton"));
        detTranslationNegtiveButton->setMinimumSize(QSize(25, 25));
        detTranslationNegtiveButton->setMaximumSize(QSize(25, 25));

        detTranslationLayout2->addWidget(detTranslationNegtiveButton, 1, 0, 1, 1);

        detTranslationPositiveButton = new QPushButton(widget5);
        detTranslationPositiveButton->setObjectName(QStringLiteral("detTranslationPositiveButton"));
        detTranslationPositiveButton->setMinimumSize(QSize(25, 25));
        detTranslationPositiveButton->setMaximumSize(QSize(25, 25));

        detTranslationLayout2->addWidget(detTranslationPositiveButton, 1, 1, 1, 1);


        detTranslationLayout1->addLayout(detTranslationLayout2);

        detTranslationAbsPosButton = new QPushButton(widget5);
        detTranslationAbsPosButton->setObjectName(QStringLiteral("detTranslationAbsPosButton"));
        detTranslationAbsPosButton->setMinimumSize(QSize(50, 50));
        detTranslationAbsPosButton->setMaximumSize(QSize(50, 50));

        detTranslationLayout1->addWidget(detTranslationAbsPosButton);

        detTranslationLayout3 = new QVBoxLayout();
        detTranslationLayout3->setSpacing(6);
        detTranslationLayout3->setObjectName(QStringLiteral("detTranslationLayout3"));
        detTranslationStaticLabel = new QLabel(widget5);
        detTranslationStaticLabel->setObjectName(QStringLiteral("detTranslationStaticLabel"));

        detTranslationLayout3->addWidget(detTranslationStaticLabel);

        detTranslationHorizontalSlider = new QSlider(widget5);
        detTranslationHorizontalSlider->setObjectName(QStringLiteral("detTranslationHorizontalSlider"));
        detTranslationHorizontalSlider->setMinimumSize(QSize(100, 0));
        detTranslationHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        detTranslationHorizontalSlider->setOrientation(Qt::Horizontal);

        detTranslationLayout3->addWidget(detTranslationHorizontalSlider);


        detTranslationLayout1->addLayout(detTranslationLayout3);

        widget6 = new QWidget(motionGroupBox);
        widget6->setObjectName(QStringLiteral("widget6"));
        detLayerLayout1 = new QHBoxLayout(widget6);
        detLayerLayout1->setSpacing(1);
        detLayerLayout1->setContentsMargins(11, 11, 11, 11);
        detLayerLayout1->setObjectName(QStringLiteral("detLayerLayout1"));
        detLayerLayout1->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        detLayerLayout1->addWidget(label_3);

        detLayerLayout2 = new QGridLayout();
        detLayerLayout2->setSpacing(6);
        detLayerLayout2->setObjectName(QStringLiteral("detLayerLayout2"));
        detLayerPosEdit = new QLineEdit(widget6);
        detLayerPosEdit->setObjectName(QStringLiteral("detLayerPosEdit"));
        detLayerPosEdit->setMinimumSize(QSize(70, 25));
        detLayerPosEdit->setMaximumSize(QSize(70, 25));

        detLayerLayout2->addWidget(detLayerPosEdit, 0, 0, 1, 2);

        detLayerNegtiveButton = new QPushButton(widget6);
        detLayerNegtiveButton->setObjectName(QStringLiteral("detLayerNegtiveButton"));
        detLayerNegtiveButton->setMinimumSize(QSize(25, 25));
        detLayerNegtiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2->addWidget(detLayerNegtiveButton, 1, 0, 1, 1);

        detLayerPositiveButton = new QPushButton(widget6);
        detLayerPositiveButton->setObjectName(QStringLiteral("detLayerPositiveButton"));
        detLayerPositiveButton->setMinimumSize(QSize(25, 25));
        detLayerPositiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2->addWidget(detLayerPositiveButton, 1, 1, 1, 1);


        detLayerLayout1->addLayout(detLayerLayout2);

        detLayerAbsPosButton = new QPushButton(widget6);
        detLayerAbsPosButton->setObjectName(QStringLiteral("detLayerAbsPosButton"));
        detLayerAbsPosButton->setMinimumSize(QSize(50, 50));
        detLayerAbsPosButton->setMaximumSize(QSize(50, 50));

        detLayerLayout1->addWidget(detLayerAbsPosButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        detLayerStaticLabel = new QLabel(widget6);
        detLayerStaticLabel->setObjectName(QStringLiteral("detLayerStaticLabel"));

        verticalLayout->addWidget(detLayerStaticLabel);

        detLayerHorizontalSlider = new QSlider(widget6);
        detLayerHorizontalSlider->setObjectName(QStringLiteral("detLayerHorizontalSlider"));
        detLayerHorizontalSlider->setMinimumSize(QSize(100, 0));
        detLayerHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        detLayerHorizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(detLayerHorizontalSlider);


        detLayerLayout1->addLayout(verticalLayout);


        retranslateUi(MotorControl);
        QObject::connect(tableRotNegtiveButton, SIGNAL(clicked()), tableRotNegtiveButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MotorControl);
    } // setupUi

    void retranslateUi(QWidget *MotorControl)
    {
        MotorControl->setWindowTitle(QApplication::translate("MotorControl", "MotorControl", nullptr));
        motionGroupBox->setTitle(QApplication::translate("MotorControl", "\350\277\220\345\212\250", nullptr));
        label_8->setText(QApplication::translate("MotorControl", "\345\260\204\347\272\277\345\215\207\351\231\215", nullptr));
        rayLayerNegtiveButton->setText(QApplication::translate("MotorControl", "<<", nullptr));
        rayLayerPositiveButton->setText(QApplication::translate("MotorControl", ">>", nullptr));
        rayLayerAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        rayLayerStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
        label->setText(QApplication::translate("MotorControl", "<html><head/><body><p>\345\267\245\344\273\266\346\227\213\350\275\254</p></body></html>", nullptr));
        tableRotNegtiveButton->setText(QApplication::translate("MotorControl", "\345\217\215", nullptr));
        tableRotPositiveButton->setText(QApplication::translate("MotorControl", "\346\255\243", nullptr));
        tableRotAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        tableRotStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
        label_6->setText(QApplication::translate("MotorControl", "\345\267\245\344\273\266\345\271\263\347\247\273", nullptr));
        tableTranslationNegtiveButton->setText(QApplication::translate("MotorControl", "<<", nullptr));
        tableTranslationPositiveButton->setText(QApplication::translate("MotorControl", ">>", nullptr));
        tableTranslationAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        tableTranslationStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
        label_2->setText(QApplication::translate("MotorControl", "<html><head/><body><p>\345\267\245\344\273\266\346\227\213\350\275\254</p></body></html>", nullptr));
        deflectNegtiveButton->setText(QApplication::translate("MotorControl", "<<", nullptr));
        deflectPositiveButton->setText(QApplication::translate("MotorControl", ">>", nullptr));
        deflectAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        deflectStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
        label_7->setText(QApplication::translate("MotorControl", "\345\267\245\344\273\266\345\276\204\345\220\221", nullptr));
        tableRadialNegtiveButton->setText(QApplication::translate("MotorControl", "<<", nullptr));
        tableRadialPositiveButton->setText(QApplication::translate("MotorControl", ">>", nullptr));
        tableRadialAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        tableRadialStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
        label_5->setText(QApplication::translate("MotorControl", "\346\216\242\346\265\213\345\276\204\345\220\221", nullptr));
        detRadialNegtiveButton->setText(QApplication::translate("MotorControl", "<<", nullptr));
        detRadialPositiveButton->setText(QApplication::translate("MotorControl", ">>", nullptr));
        detRadialAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        detRadialStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
        label_4->setText(QApplication::translate("MotorControl", "\346\216\242\346\265\213\345\271\263\347\247\273", nullptr));
        detTranslationNegtiveButton->setText(QApplication::translate("MotorControl", "<<", nullptr));
        detTranslationPositiveButton->setText(QApplication::translate("MotorControl", ">>", nullptr));
        detTranslationAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        detTranslationStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
        label_3->setText(QApplication::translate("MotorControl", "\346\216\242\346\265\213\345\215\207\351\231\215", nullptr));
        detLayerNegtiveButton->setText(QApplication::translate("MotorControl", "<<", nullptr));
        detLayerPositiveButton->setText(QApplication::translate("MotorControl", ">>", nullptr));
        detLayerAbsPosButton->setText(QApplication::translate("MotorControl", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        detLayerStaticLabel->setText(QApplication::translate("MotorControl", "0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MotorControl: public Ui_MotorControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORCONTROL_H
