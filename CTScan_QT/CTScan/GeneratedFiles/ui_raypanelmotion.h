/********************************************************************************
** Form generated from reading UI file 'raypanelmotion.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAYPANELMOTION_H
#define UI_RAYPANELMOTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rayPanelMotionWidget
{
public:
    QWidget *layoutWidget;
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
    QHBoxLayout *sampleChooseButtonLayout1;
    QSpacerItem *sampleChooseButtonSpacer;
    QPushButton *sampleChooseButton;
    QSpacerItem *mainStrechSpacer;

    void setupUi(QWidget *rayPanelMotionWidget)
    {
        if (rayPanelMotionWidget->objectName().isEmpty())
            rayPanelMotionWidget->setObjectName(QStringLiteral("rayPanelMotionWidget"));
        rayPanelMotionWidget->resize(400, 987);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rayPanelMotionWidget->sizePolicy().hasHeightForWidth());
        rayPanelMotionWidget->setSizePolicy(sizePolicy);
        rayPanelMotionWidget->setMinimumSize(QSize(400, 0));
        rayPanelMotionWidget->setMaximumSize(QSize(400, 16777215));
        rayPanelMotionWidget->setAutoFillBackground(false);
        layoutWidget = new QWidget(rayPanelMotionWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 14, 367, 903));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        rayTab = new QTabWidget(layoutWidget);
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

        panelGroupBox = new QGroupBox(layoutWidget);
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

        scanSetupGroupBox = new QGroupBox(layoutWidget);
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

        sampleChooseButtonLayout1 = new QHBoxLayout();
        sampleChooseButtonLayout1->setObjectName(QStringLiteral("sampleChooseButtonLayout1"));
        sampleChooseButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sampleChooseButtonLayout1->addItem(sampleChooseButtonSpacer);

        sampleChooseButton = new QPushButton(layoutWidget);
        sampleChooseButton->setObjectName(QStringLiteral("sampleChooseButton"));
        sampleChooseButton->setMinimumSize(QSize(0, 22));
        sampleChooseButton->setMaximumSize(QSize(16777215, 22));

        sampleChooseButtonLayout1->addWidget(sampleChooseButton);


        verticalLayout_2->addLayout(sampleChooseButtonLayout1);

        mainStrechSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(mainStrechSpacer);

        verticalLayout_2->setStretch(4, 1);

        retranslateUi(rayPanelMotionWidget);

        rayTab->setCurrentIndex(1);


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
        sampleChooseButton->setText(QApplication::translate("rayPanelMotionWidget", "\351\207\207\351\233\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rayPanelMotionWidget: public Ui_rayPanelMotionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYPANELMOTION_H
