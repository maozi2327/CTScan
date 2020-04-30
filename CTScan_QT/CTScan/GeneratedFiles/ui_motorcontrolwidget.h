/********************************************************************************
** Form generated from reading UI file 'motorcontrolwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORCONTROLWIDGET_H
#define UI_MOTORCONTROLWIDGET_H

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

class Ui_MotorControlWidget
{
public:
    QGroupBox *motionGroupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *objTranslationLayout;
    QLabel *label_6;
    QGridLayout *objTranslationLayout_2;
    QLineEdit *objTranslationPosEdit;
    QPushButton *objTranslationNegtiveButton;
    QPushButton *objTranslationPositiveButton;
    QPushButton *objTranslationAbsPosButton;
    QVBoxLayout *objTranslationLayout3;
    QLabel *objTranslationStaticLabel;
    QSlider *objTranslationHorizontalSlider;
    QFrame *objTranslationLine;
    QVBoxLayout *verticalLayout_5;
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
    QFrame *objRotLine;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *objRadialLayout1;
    QLabel *label_7;
    QGridLayout *objRadialLayout2;
    QLineEdit *objRadialPosEdit;
    QPushButton *objRadialNegtiveButton;
    QPushButton *obRadialPositiveButton;
    QPushButton *objRadialAbsPosButton;
    QVBoxLayout *objRadialLayout3;
    QLabel *objRadialStaticLabel;
    QSlider *objRadialHorizontalSlider;
    QFrame *objRadialLine;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QLineEdit *objRotationPosEdit;
    QPushButton *objRotNegtiveButton;
    QPushButton *objRotPositiveButton;
    QPushButton *objRotAbsPosButton;
    QVBoxLayout *objRotLayout3;
    QLabel *objRotStaticLabel;
    QSlider *objRotHorizontalSlider;
    QFrame *deflectLine;
    QVBoxLayout *verticalLayout_7;
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
    QFrame *detRadialLine;
    QVBoxLayout *verticalLayout_8;
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
    QFrame *detTranslationLine;
    QVBoxLayout *verticalLayout_9;
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
    QFrame *detLayerLine;
    QVBoxLayout *verticalLayout_10;
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
    QFrame *rayLayerLine;

    void setupUi(QWidget *MotorControlWidget)
    {
        if (MotorControlWidget->objectName().isEmpty())
            MotorControlWidget->setObjectName(QStringLiteral("MotorControlWidget"));
        MotorControlWidget->resize(323, 685);
        motionGroupBox = new QGroupBox(MotorControlWidget);
        motionGroupBox->setObjectName(QStringLiteral("motionGroupBox"));
        motionGroupBox->setGeometry(QRect(10, 20, 300, 651));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(motionGroupBox->sizePolicy().hasHeightForWidth());
        motionGroupBox->setSizePolicy(sizePolicy);
        motionGroupBox->setMinimumSize(QSize(300, 0));
        motionGroupBox->setMaximumSize(QSize(300, 1000));
        layoutWidget = new QWidget(motionGroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 286, 606));
        verticalLayout_11 = new QVBoxLayout(layoutWidget);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        objTranslationLayout = new QHBoxLayout();
        objTranslationLayout->setSpacing(1);
        objTranslationLayout->setObjectName(QStringLiteral("objTranslationLayout"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(50, 0));
        label_6->setMaximumSize(QSize(50, 16777215));

        objTranslationLayout->addWidget(label_6);

        objTranslationLayout_2 = new QGridLayout();
        objTranslationLayout_2->setSpacing(6);
        objTranslationLayout_2->setObjectName(QStringLiteral("objTranslationLayout_2"));
        objTranslationPosEdit = new QLineEdit(layoutWidget);
        objTranslationPosEdit->setObjectName(QStringLiteral("objTranslationPosEdit"));
        objTranslationPosEdit->setMinimumSize(QSize(70, 25));
        objTranslationPosEdit->setMaximumSize(QSize(70, 25));

        objTranslationLayout_2->addWidget(objTranslationPosEdit, 0, 0, 1, 2);

        objTranslationNegtiveButton = new QPushButton(layoutWidget);
        objTranslationNegtiveButton->setObjectName(QStringLiteral("objTranslationNegtiveButton"));
        objTranslationNegtiveButton->setMinimumSize(QSize(25, 25));
        objTranslationNegtiveButton->setMaximumSize(QSize(25, 25));

        objTranslationLayout_2->addWidget(objTranslationNegtiveButton, 1, 0, 1, 1);

        objTranslationPositiveButton = new QPushButton(layoutWidget);
        objTranslationPositiveButton->setObjectName(QStringLiteral("objTranslationPositiveButton"));
        objTranslationPositiveButton->setMinimumSize(QSize(25, 25));
        objTranslationPositiveButton->setMaximumSize(QSize(25, 25));

        objTranslationLayout_2->addWidget(objTranslationPositiveButton, 1, 1, 1, 1);


        objTranslationLayout->addLayout(objTranslationLayout_2);

        objTranslationAbsPosButton = new QPushButton(layoutWidget);
        objTranslationAbsPosButton->setObjectName(QStringLiteral("objTranslationAbsPosButton"));
        objTranslationAbsPosButton->setMinimumSize(QSize(50, 50));
        objTranslationAbsPosButton->setMaximumSize(QSize(50, 50));

        objTranslationLayout->addWidget(objTranslationAbsPosButton);

        objTranslationLayout3 = new QVBoxLayout();
        objTranslationLayout3->setSpacing(6);
        objTranslationLayout3->setObjectName(QStringLiteral("objTranslationLayout3"));
        objTranslationStaticLabel = new QLabel(layoutWidget);
        objTranslationStaticLabel->setObjectName(QStringLiteral("objTranslationStaticLabel"));

        objTranslationLayout3->addWidget(objTranslationStaticLabel);

        objTranslationHorizontalSlider = new QSlider(layoutWidget);
        objTranslationHorizontalSlider->setObjectName(QStringLiteral("objTranslationHorizontalSlider"));
        objTranslationHorizontalSlider->setMinimumSize(QSize(100, 0));
        objTranslationHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        objTranslationHorizontalSlider->setOrientation(Qt::Horizontal);

        objTranslationLayout3->addWidget(objTranslationHorizontalSlider);


        objTranslationLayout->addLayout(objTranslationLayout3);


        verticalLayout_4->addLayout(objTranslationLayout);

        objTranslationLine = new QFrame(layoutWidget);
        objTranslationLine->setObjectName(QStringLiteral("objTranslationLine"));
        objTranslationLine->setMinimumSize(QSize(280, 2));
        objTranslationLine->setMaximumSize(QSize(280, 2));
        objTranslationLine->setLayoutDirection(Qt::LeftToRight);
        objTranslationLine->setFrameShape(QFrame::HLine);
        objTranslationLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(objTranslationLine);


        verticalLayout_11->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        deflectLayout1 = new QHBoxLayout();
        deflectLayout1->setSpacing(1);
        deflectLayout1->setObjectName(QStringLiteral("deflectLayout1"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));

        deflectLayout1->addWidget(label_2);

        deflectLayout2 = new QGridLayout();
        deflectLayout2->setSpacing(6);
        deflectLayout2->setObjectName(QStringLiteral("deflectLayout2"));
        deflectPosEdit = new QLineEdit(layoutWidget);
        deflectPosEdit->setObjectName(QStringLiteral("deflectPosEdit"));
        deflectPosEdit->setMinimumSize(QSize(70, 25));
        deflectPosEdit->setMaximumSize(QSize(70, 25));

        deflectLayout2->addWidget(deflectPosEdit, 0, 1, 1, 2);

        deflectNegtiveButton = new QPushButton(layoutWidget);
        deflectNegtiveButton->setObjectName(QStringLiteral("deflectNegtiveButton"));
        deflectNegtiveButton->setMinimumSize(QSize(25, 25));
        deflectNegtiveButton->setMaximumSize(QSize(25, 25));

        deflectLayout2->addWidget(deflectNegtiveButton, 1, 1, 1, 1);

        deflectPositiveButton = new QPushButton(layoutWidget);
        deflectPositiveButton->setObjectName(QStringLiteral("deflectPositiveButton"));
        deflectPositiveButton->setMinimumSize(QSize(25, 25));
        deflectPositiveButton->setMaximumSize(QSize(25, 25));

        deflectLayout2->addWidget(deflectPositiveButton, 1, 2, 1, 1);


        deflectLayout1->addLayout(deflectLayout2);

        deflectAbsPosButton = new QPushButton(layoutWidget);
        deflectAbsPosButton->setObjectName(QStringLiteral("deflectAbsPosButton"));
        deflectAbsPosButton->setMinimumSize(QSize(50, 50));
        deflectAbsPosButton->setMaximumSize(QSize(50, 50));

        deflectLayout1->addWidget(deflectAbsPosButton);

        deflectLayout3 = new QVBoxLayout();
        deflectLayout3->setSpacing(6);
        deflectLayout3->setObjectName(QStringLiteral("deflectLayout3"));
        deflectStaticLabel = new QLabel(layoutWidget);
        deflectStaticLabel->setObjectName(QStringLiteral("deflectStaticLabel"));

        deflectLayout3->addWidget(deflectStaticLabel);

        deflectHorizontalSlider = new QSlider(layoutWidget);
        deflectHorizontalSlider->setObjectName(QStringLiteral("deflectHorizontalSlider"));
        deflectHorizontalSlider->setMinimumSize(QSize(100, 0));
        deflectHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        deflectHorizontalSlider->setOrientation(Qt::Horizontal);

        deflectLayout3->addWidget(deflectHorizontalSlider);


        deflectLayout1->addLayout(deflectLayout3);


        verticalLayout_5->addLayout(deflectLayout1);

        objRotLine = new QFrame(layoutWidget);
        objRotLine->setObjectName(QStringLiteral("objRotLine"));
        objRotLine->setMinimumSize(QSize(280, 2));
        objRotLine->setMaximumSize(QSize(280, 2));
        objRotLine->setLayoutDirection(Qt::LeftToRight);
        objRotLine->setFrameShape(QFrame::HLine);
        objRotLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(objRotLine);


        verticalLayout_11->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        objRadialLayout1 = new QHBoxLayout();
        objRadialLayout1->setSpacing(1);
        objRadialLayout1->setObjectName(QStringLiteral("objRadialLayout1"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(50, 0));
        label_7->setMaximumSize(QSize(50, 16777215));

        objRadialLayout1->addWidget(label_7);

        objRadialLayout2 = new QGridLayout();
        objRadialLayout2->setSpacing(6);
        objRadialLayout2->setObjectName(QStringLiteral("objRadialLayout2"));
        objRadialPosEdit = new QLineEdit(layoutWidget);
        objRadialPosEdit->setObjectName(QStringLiteral("objRadialPosEdit"));
        objRadialPosEdit->setMinimumSize(QSize(70, 25));
        objRadialPosEdit->setMaximumSize(QSize(70, 25));

        objRadialLayout2->addWidget(objRadialPosEdit, 0, 1, 1, 2);

        objRadialNegtiveButton = new QPushButton(layoutWidget);
        objRadialNegtiveButton->setObjectName(QStringLiteral("objRadialNegtiveButton"));
        objRadialNegtiveButton->setMinimumSize(QSize(25, 25));
        objRadialNegtiveButton->setMaximumSize(QSize(25, 25));

        objRadialLayout2->addWidget(objRadialNegtiveButton, 1, 1, 1, 1);

        obRadialPositiveButton = new QPushButton(layoutWidget);
        obRadialPositiveButton->setObjectName(QStringLiteral("obRadialPositiveButton"));
        obRadialPositiveButton->setMinimumSize(QSize(25, 25));
        obRadialPositiveButton->setMaximumSize(QSize(25, 25));

        objRadialLayout2->addWidget(obRadialPositiveButton, 1, 2, 1, 1);


        objRadialLayout1->addLayout(objRadialLayout2);

        objRadialAbsPosButton = new QPushButton(layoutWidget);
        objRadialAbsPosButton->setObjectName(QStringLiteral("objRadialAbsPosButton"));
        objRadialAbsPosButton->setMinimumSize(QSize(50, 50));
        objRadialAbsPosButton->setMaximumSize(QSize(50, 50));

        objRadialLayout1->addWidget(objRadialAbsPosButton);

        objRadialLayout3 = new QVBoxLayout();
        objRadialLayout3->setSpacing(6);
        objRadialLayout3->setObjectName(QStringLiteral("objRadialLayout3"));
        objRadialStaticLabel = new QLabel(layoutWidget);
        objRadialStaticLabel->setObjectName(QStringLiteral("objRadialStaticLabel"));

        objRadialLayout3->addWidget(objRadialStaticLabel);

        objRadialHorizontalSlider = new QSlider(layoutWidget);
        objRadialHorizontalSlider->setObjectName(QStringLiteral("objRadialHorizontalSlider"));
        objRadialHorizontalSlider->setMinimumSize(QSize(100, 0));
        objRadialHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        objRadialHorizontalSlider->setOrientation(Qt::Horizontal);

        objRadialLayout3->addWidget(objRadialHorizontalSlider);


        objRadialLayout1->addLayout(objRadialLayout3);


        verticalLayout_6->addLayout(objRadialLayout1);

        objRadialLine = new QFrame(layoutWidget);
        objRadialLine->setObjectName(QStringLiteral("objRadialLine"));
        objRadialLine->setMinimumSize(QSize(280, 0));
        objRadialLine->setMaximumSize(QSize(280, 16777215));
        objRadialLine->setLayoutDirection(Qt::LeftToRight);
        objRadialLine->setFrameShape(QFrame::HLine);
        objRadialLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(objRadialLine);


        verticalLayout_11->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        objRotationPosEdit = new QLineEdit(layoutWidget);
        objRotationPosEdit->setObjectName(QStringLiteral("objRotationPosEdit"));
        objRotationPosEdit->setMinimumSize(QSize(70, 25));
        objRotationPosEdit->setMaximumSize(QSize(70, 25));

        gridLayout->addWidget(objRotationPosEdit, 0, 0, 1, 2);

        objRotNegtiveButton = new QPushButton(layoutWidget);
        objRotNegtiveButton->setObjectName(QStringLiteral("objRotNegtiveButton"));
        objRotNegtiveButton->setMinimumSize(QSize(25, 25));
        objRotNegtiveButton->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(objRotNegtiveButton, 1, 0, 1, 1);

        objRotPositiveButton = new QPushButton(layoutWidget);
        objRotPositiveButton->setObjectName(QStringLiteral("objRotPositiveButton"));
        objRotPositiveButton->setMinimumSize(QSize(25, 25));
        objRotPositiveButton->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(objRotPositiveButton, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        objRotAbsPosButton = new QPushButton(layoutWidget);
        objRotAbsPosButton->setObjectName(QStringLiteral("objRotAbsPosButton"));
        objRotAbsPosButton->setMinimumSize(QSize(50, 50));
        objRotAbsPosButton->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(objRotAbsPosButton);

        objRotLayout3 = new QVBoxLayout();
        objRotLayout3->setSpacing(6);
        objRotLayout3->setObjectName(QStringLiteral("objRotLayout3"));
        objRotLayout3->setSizeConstraint(QLayout::SetDefaultConstraint);
        objRotStaticLabel = new QLabel(layoutWidget);
        objRotStaticLabel->setObjectName(QStringLiteral("objRotStaticLabel"));
        sizePolicy.setHeightForWidth(objRotStaticLabel->sizePolicy().hasHeightForWidth());
        objRotStaticLabel->setSizePolicy(sizePolicy);

        objRotLayout3->addWidget(objRotStaticLabel);

        objRotHorizontalSlider = new QSlider(layoutWidget);
        objRotHorizontalSlider->setObjectName(QStringLiteral("objRotHorizontalSlider"));
        objRotHorizontalSlider->setMinimumSize(QSize(100, 0));
        objRotHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        objRotHorizontalSlider->setOrientation(Qt::Horizontal);

        objRotLayout3->addWidget(objRotHorizontalSlider);


        horizontalLayout->addLayout(objRotLayout3);


        verticalLayout_3->addLayout(horizontalLayout);

        deflectLine = new QFrame(layoutWidget);
        deflectLine->setObjectName(QStringLiteral("deflectLine"));
        deflectLine->setMinimumSize(QSize(280, 2));
        deflectLine->setMaximumSize(QSize(280, 2));
        deflectLine->setLayoutDirection(Qt::LeftToRight);
        deflectLine->setFrameShape(QFrame::HLine);
        deflectLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(deflectLine);


        verticalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        detRadialLayout1 = new QHBoxLayout();
        detRadialLayout1->setSpacing(1);
        detRadialLayout1->setObjectName(QStringLiteral("detRadialLayout1"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(50, 0));
        label_5->setMaximumSize(QSize(50, 16777215));

        detRadialLayout1->addWidget(label_5);

        detRadialLayout2 = new QGridLayout();
        detRadialLayout2->setSpacing(6);
        detRadialLayout2->setObjectName(QStringLiteral("detRadialLayout2"));
        detRadialPosEdit = new QLineEdit(layoutWidget);
        detRadialPosEdit->setObjectName(QStringLiteral("detRadialPosEdit"));
        detRadialPosEdit->setMinimumSize(QSize(70, 25));
        detRadialPosEdit->setMaximumSize(QSize(70, 25));

        detRadialLayout2->addWidget(detRadialPosEdit, 0, 0, 1, 2);

        detRadialNegtiveButton = new QPushButton(layoutWidget);
        detRadialNegtiveButton->setObjectName(QStringLiteral("detRadialNegtiveButton"));
        detRadialNegtiveButton->setMinimumSize(QSize(25, 25));
        detRadialNegtiveButton->setMaximumSize(QSize(25, 25));

        detRadialLayout2->addWidget(detRadialNegtiveButton, 1, 0, 1, 1);

        detRadialPositiveButton = new QPushButton(layoutWidget);
        detRadialPositiveButton->setObjectName(QStringLiteral("detRadialPositiveButton"));
        detRadialPositiveButton->setMinimumSize(QSize(25, 25));
        detRadialPositiveButton->setMaximumSize(QSize(25, 25));

        detRadialLayout2->addWidget(detRadialPositiveButton, 1, 1, 1, 1);


        detRadialLayout1->addLayout(detRadialLayout2);

        detRadialAbsPosButton = new QPushButton(layoutWidget);
        detRadialAbsPosButton->setObjectName(QStringLiteral("detRadialAbsPosButton"));
        detRadialAbsPosButton->setMinimumSize(QSize(50, 50));
        detRadialAbsPosButton->setMaximumSize(QSize(50, 50));

        detRadialLayout1->addWidget(detRadialAbsPosButton);

        detRadialLayout3 = new QVBoxLayout();
        detRadialLayout3->setSpacing(6);
        detRadialLayout3->setObjectName(QStringLiteral("detRadialLayout3"));
        detRadialStaticLabel = new QLabel(layoutWidget);
        detRadialStaticLabel->setObjectName(QStringLiteral("detRadialStaticLabel"));

        detRadialLayout3->addWidget(detRadialStaticLabel);

        detRadialHorizontalSlider = new QSlider(layoutWidget);
        detRadialHorizontalSlider->setObjectName(QStringLiteral("detRadialHorizontalSlider"));
        detRadialHorizontalSlider->setMinimumSize(QSize(100, 0));
        detRadialHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        detRadialHorizontalSlider->setOrientation(Qt::Horizontal);

        detRadialLayout3->addWidget(detRadialHorizontalSlider);


        detRadialLayout1->addLayout(detRadialLayout3);


        verticalLayout_7->addLayout(detRadialLayout1);

        detRadialLine = new QFrame(layoutWidget);
        detRadialLine->setObjectName(QStringLiteral("detRadialLine"));
        detRadialLine->setMinimumSize(QSize(280, 2));
        detRadialLine->setMaximumSize(QSize(280, 2));
        detRadialLine->setLayoutDirection(Qt::LeftToRight);
        detRadialLine->setFrameShape(QFrame::HLine);
        detRadialLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(detRadialLine);


        verticalLayout_11->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        detTranslationLayout1 = new QHBoxLayout();
        detTranslationLayout1->setSpacing(1);
        detTranslationLayout1->setObjectName(QStringLiteral("detTranslationLayout1"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));

        detTranslationLayout1->addWidget(label_4);

        detTranslationLayout2 = new QGridLayout();
        detTranslationLayout2->setSpacing(6);
        detTranslationLayout2->setObjectName(QStringLiteral("detTranslationLayout2"));
        detTranslationPosEdit = new QLineEdit(layoutWidget);
        detTranslationPosEdit->setObjectName(QStringLiteral("detTranslationPosEdit"));
        detTranslationPosEdit->setMinimumSize(QSize(70, 25));
        detTranslationPosEdit->setMaximumSize(QSize(70, 25));

        detTranslationLayout2->addWidget(detTranslationPosEdit, 0, 0, 1, 2);

        detTranslationNegtiveButton = new QPushButton(layoutWidget);
        detTranslationNegtiveButton->setObjectName(QStringLiteral("detTranslationNegtiveButton"));
        detTranslationNegtiveButton->setMinimumSize(QSize(25, 25));
        detTranslationNegtiveButton->setMaximumSize(QSize(25, 25));

        detTranslationLayout2->addWidget(detTranslationNegtiveButton, 1, 0, 1, 1);

        detTranslationPositiveButton = new QPushButton(layoutWidget);
        detTranslationPositiveButton->setObjectName(QStringLiteral("detTranslationPositiveButton"));
        detTranslationPositiveButton->setMinimumSize(QSize(25, 25));
        detTranslationPositiveButton->setMaximumSize(QSize(25, 25));

        detTranslationLayout2->addWidget(detTranslationPositiveButton, 1, 1, 1, 1);


        detTranslationLayout1->addLayout(detTranslationLayout2);

        detTranslationAbsPosButton = new QPushButton(layoutWidget);
        detTranslationAbsPosButton->setObjectName(QStringLiteral("detTranslationAbsPosButton"));
        detTranslationAbsPosButton->setMinimumSize(QSize(50, 50));
        detTranslationAbsPosButton->setMaximumSize(QSize(50, 50));

        detTranslationLayout1->addWidget(detTranslationAbsPosButton);

        detTranslationLayout3 = new QVBoxLayout();
        detTranslationLayout3->setSpacing(6);
        detTranslationLayout3->setObjectName(QStringLiteral("detTranslationLayout3"));
        detTranslationStaticLabel = new QLabel(layoutWidget);
        detTranslationStaticLabel->setObjectName(QStringLiteral("detTranslationStaticLabel"));

        detTranslationLayout3->addWidget(detTranslationStaticLabel);

        detTranslationHorizontalSlider = new QSlider(layoutWidget);
        detTranslationHorizontalSlider->setObjectName(QStringLiteral("detTranslationHorizontalSlider"));
        detTranslationHorizontalSlider->setMinimumSize(QSize(100, 0));
        detTranslationHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        detTranslationHorizontalSlider->setOrientation(Qt::Horizontal);

        detTranslationLayout3->addWidget(detTranslationHorizontalSlider);


        detTranslationLayout1->addLayout(detTranslationLayout3);


        verticalLayout_8->addLayout(detTranslationLayout1);

        detTranslationLine = new QFrame(layoutWidget);
        detTranslationLine->setObjectName(QStringLiteral("detTranslationLine"));
        detTranslationLine->setMinimumSize(QSize(280, 2));
        detTranslationLine->setMaximumSize(QSize(280, 2));
        detTranslationLine->setLayoutDirection(Qt::LeftToRight);
        detTranslationLine->setFrameShape(QFrame::HLine);
        detTranslationLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(detTranslationLine);


        verticalLayout_11->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        detLayerLayout1 = new QHBoxLayout();
        detLayerLayout1->setSpacing(1);
        detLayerLayout1->setObjectName(QStringLiteral("detLayerLayout1"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        detLayerLayout1->addWidget(label_3);

        detLayerLayout2 = new QGridLayout();
        detLayerLayout2->setSpacing(6);
        detLayerLayout2->setObjectName(QStringLiteral("detLayerLayout2"));
        detLayerPosEdit = new QLineEdit(layoutWidget);
        detLayerPosEdit->setObjectName(QStringLiteral("detLayerPosEdit"));
        detLayerPosEdit->setMinimumSize(QSize(70, 25));
        detLayerPosEdit->setMaximumSize(QSize(70, 25));

        detLayerLayout2->addWidget(detLayerPosEdit, 0, 0, 1, 2);

        detLayerNegtiveButton = new QPushButton(layoutWidget);
        detLayerNegtiveButton->setObjectName(QStringLiteral("detLayerNegtiveButton"));
        detLayerNegtiveButton->setMinimumSize(QSize(25, 25));
        detLayerNegtiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2->addWidget(detLayerNegtiveButton, 1, 0, 1, 1);

        detLayerPositiveButton = new QPushButton(layoutWidget);
        detLayerPositiveButton->setObjectName(QStringLiteral("detLayerPositiveButton"));
        detLayerPositiveButton->setMinimumSize(QSize(25, 25));
        detLayerPositiveButton->setMaximumSize(QSize(25, 25));

        detLayerLayout2->addWidget(detLayerPositiveButton, 1, 1, 1, 1);


        detLayerLayout1->addLayout(detLayerLayout2);

        detLayerAbsPosButton = new QPushButton(layoutWidget);
        detLayerAbsPosButton->setObjectName(QStringLiteral("detLayerAbsPosButton"));
        detLayerAbsPosButton->setMinimumSize(QSize(50, 50));
        detLayerAbsPosButton->setMaximumSize(QSize(50, 50));

        detLayerLayout1->addWidget(detLayerAbsPosButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        detLayerStaticLabel = new QLabel(layoutWidget);
        detLayerStaticLabel->setObjectName(QStringLiteral("detLayerStaticLabel"));

        verticalLayout->addWidget(detLayerStaticLabel);

        detLayerHorizontalSlider = new QSlider(layoutWidget);
        detLayerHorizontalSlider->setObjectName(QStringLiteral("detLayerHorizontalSlider"));
        detLayerHorizontalSlider->setMinimumSize(QSize(100, 0));
        detLayerHorizontalSlider->setMaximumSize(QSize(100, 16777215));
        detLayerHorizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(detLayerHorizontalSlider);


        detLayerLayout1->addLayout(verticalLayout);


        verticalLayout_9->addLayout(detLayerLayout1);

        detLayerLine = new QFrame(layoutWidget);
        detLayerLine->setObjectName(QStringLiteral("detLayerLine"));
        detLayerLine->setMinimumSize(QSize(280, 2));
        detLayerLine->setMaximumSize(QSize(280, 2));
        detLayerLine->setLayoutDirection(Qt::LeftToRight);
        detLayerLine->setFrameShape(QFrame::HLine);
        detLayerLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(detLayerLine);


        verticalLayout_11->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        detLayerLayout1_2 = new QHBoxLayout();
        detLayerLayout1_2->setSpacing(1);
        detLayerLayout1_2->setObjectName(QStringLiteral("detLayerLayout1_2"));
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


        verticalLayout_10->addLayout(detLayerLayout1_2);

        rayLayerLine = new QFrame(layoutWidget);
        rayLayerLine->setObjectName(QStringLiteral("rayLayerLine"));
        rayLayerLine->setFrameShape(QFrame::HLine);
        rayLayerLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(rayLayerLine);


        verticalLayout_11->addLayout(verticalLayout_10);


        retranslateUi(MotorControlWidget);
        QObject::connect(objRotNegtiveButton, SIGNAL(clicked()), objRotNegtiveButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MotorControlWidget);
    } // setupUi

    void retranslateUi(QWidget *MotorControlWidget)
    {
        MotorControlWidget->setWindowTitle(QApplication::translate("MotorControlWidget", "MotorControl", nullptr));
        motionGroupBox->setTitle(QApplication::translate("MotorControlWidget", "\350\277\220\345\212\250", nullptr));
        label_6->setText(QApplication::translate("MotorControlWidget", "\345\267\245\344\273\266\345\271\263\347\247\273", nullptr));
        objTranslationNegtiveButton->setText(QApplication::translate("MotorControlWidget", "<<", nullptr));
        objTranslationPositiveButton->setText(QApplication::translate("MotorControlWidget", ">>", nullptr));
        objTranslationAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        objTranslationStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
        label_2->setText(QApplication::translate("MotorControlWidget", "<html><head/><body><p>\345\267\245\344\273\266\346\227\213\350\275\254</p></body></html>", nullptr));
        deflectNegtiveButton->setText(QApplication::translate("MotorControlWidget", "<<", nullptr));
        deflectPositiveButton->setText(QApplication::translate("MotorControlWidget", ">>", nullptr));
        deflectAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        deflectStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
        label_7->setText(QApplication::translate("MotorControlWidget", "\345\267\245\344\273\266\345\276\204\345\220\221", nullptr));
        objRadialNegtiveButton->setText(QApplication::translate("MotorControlWidget", "<<", nullptr));
        obRadialPositiveButton->setText(QApplication::translate("MotorControlWidget", ">>", nullptr));
        objRadialAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        objRadialStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
        label->setText(QApplication::translate("MotorControlWidget", "<html><head/><body><p>\345\267\245\344\273\266\346\227\213\350\275\254</p></body></html>", nullptr));
        objRotNegtiveButton->setText(QApplication::translate("MotorControlWidget", "\345\217\215", nullptr));
        objRotPositiveButton->setText(QApplication::translate("MotorControlWidget", "\346\255\243", nullptr));
        objRotAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        objRotStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
        label_5->setText(QApplication::translate("MotorControlWidget", "\346\216\242\346\265\213\345\276\204\345\220\221", nullptr));
        detRadialNegtiveButton->setText(QApplication::translate("MotorControlWidget", "<<", nullptr));
        detRadialPositiveButton->setText(QApplication::translate("MotorControlWidget", ">>", nullptr));
        detRadialAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        detRadialStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
        label_4->setText(QApplication::translate("MotorControlWidget", "\346\216\242\346\265\213\345\271\263\347\247\273", nullptr));
        detTranslationNegtiveButton->setText(QApplication::translate("MotorControlWidget", "<<", nullptr));
        detTranslationPositiveButton->setText(QApplication::translate("MotorControlWidget", ">>", nullptr));
        detTranslationAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        detTranslationStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
        label_3->setText(QApplication::translate("MotorControlWidget", "\346\216\242\346\265\213\345\215\207\351\231\215", nullptr));
        detLayerNegtiveButton->setText(QApplication::translate("MotorControlWidget", "<<", nullptr));
        detLayerPositiveButton->setText(QApplication::translate("MotorControlWidget", ">>", nullptr));
        detLayerAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        detLayerStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
        label_8->setText(QApplication::translate("MotorControlWidget", "\345\260\204\347\272\277\345\215\207\351\231\215", nullptr));
        rayLayerNegtiveButton->setText(QApplication::translate("MotorControlWidget", "<<", nullptr));
        rayLayerPositiveButton->setText(QApplication::translate("MotorControlWidget", ">>", nullptr));
        rayLayerAbsPosButton->setText(QApplication::translate("MotorControlWidget", "\347\273\235\345\257\271\n"
"\345\256\232\344\275\215", nullptr));
        rayLayerStaticLabel->setText(QApplication::translate("MotorControlWidget", "0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MotorControlWidget: public Ui_MotorControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORCONTROLWIDGET_H
