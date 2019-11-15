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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConeScanWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *fileNameStatiLabel;
    QSpacerItem *fileNameSpacer;
    QPushButton *saveDirButton;
    QLineEdit *fileNameEdit;
    QPushButton *disposeButton;
    QLabel *graduationStaticLabel;
    QLineEdit *lineEdit_4;
    QLabel *frameAverageStaticLabel;
    QSpinBox *frameAverageSpinBox;
    QLabel *diskAvailableStaticLabel;
    QLabel *diskAvailableLabel;
    QLabel *necessaryDiskStaticLabel;
    QLabel *necessaryDiskLabel;
    QLabel *sampleTimeEstimateStaticLabel;
    QLabel *sampleTimeEstimateLabel;
    QSpacerItem *leakSampleSpacer;
    QCheckBox *leakSampleCheckBox;
    QProgressBar *progressBar;
    QPushButton *beginSampleButton;

    void setupUi(QWidget *ConeScanWidget)
    {
        if (ConeScanWidget->objectName().isEmpty())
            ConeScanWidget->setObjectName(QStringLiteral("ConeScanWidget"));
        ConeScanWidget->resize(240, 411);
        ConeScanWidget->setMinimumSize(QSize(240, 0));
        ConeScanWidget->setMaximumSize(QSize(240, 16777215));
        widget = new QWidget(ConeScanWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 14, 202, 377));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        fileNameStatiLabel = new QLabel(widget);
        fileNameStatiLabel->setObjectName(QStringLiteral("fileNameStatiLabel"));
        fileNameStatiLabel->setMinimumSize(QSize(0, 25));
        fileNameStatiLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(fileNameStatiLabel, 0, 0, 1, 1);

        fileNameSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(fileNameSpacer, 0, 1, 1, 2);

        saveDirButton = new QPushButton(widget);
        saveDirButton->setObjectName(QStringLiteral("saveDirButton"));
        saveDirButton->setMinimumSize(QSize(30, 25));
        saveDirButton->setMaximumSize(QSize(30, 25));

        gridLayout->addWidget(saveDirButton, 1, 0, 1, 1);

        fileNameEdit = new QLineEdit(widget);
        fileNameEdit->setObjectName(QStringLiteral("fileNameEdit"));
        fileNameEdit->setMinimumSize(QSize(0, 25));
        fileNameEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(fileNameEdit, 1, 1, 1, 2);

        disposeButton = new QPushButton(widget);
        disposeButton->setObjectName(QStringLiteral("disposeButton"));
        disposeButton->setMinimumSize(QSize(200, 40));
        disposeButton->setMaximumSize(QSize(200, 40));

        gridLayout->addWidget(disposeButton, 2, 0, 1, 3);

        graduationStaticLabel = new QLabel(widget);
        graduationStaticLabel->setObjectName(QStringLiteral("graduationStaticLabel"));
        graduationStaticLabel->setMinimumSize(QSize(0, 25));
        graduationStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(graduationStaticLabel, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(80, 25));
        lineEdit_4->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(lineEdit_4, 3, 2, 1, 1);

        frameAverageStaticLabel = new QLabel(widget);
        frameAverageStaticLabel->setObjectName(QStringLiteral("frameAverageStaticLabel"));
        frameAverageStaticLabel->setMinimumSize(QSize(0, 25));
        frameAverageStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(frameAverageStaticLabel, 4, 0, 1, 1);

        frameAverageSpinBox = new QSpinBox(widget);
        frameAverageSpinBox->setObjectName(QStringLiteral("frameAverageSpinBox"));
        frameAverageSpinBox->setMinimumSize(QSize(80, 25));
        frameAverageSpinBox->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(frameAverageSpinBox, 4, 2, 1, 1);

        diskAvailableStaticLabel = new QLabel(widget);
        diskAvailableStaticLabel->setObjectName(QStringLiteral("diskAvailableStaticLabel"));
        diskAvailableStaticLabel->setMinimumSize(QSize(0, 25));
        diskAvailableStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(diskAvailableStaticLabel, 5, 0, 1, 2);

        diskAvailableLabel = new QLabel(widget);
        diskAvailableLabel->setObjectName(QStringLiteral("diskAvailableLabel"));
        diskAvailableLabel->setMinimumSize(QSize(0, 25));
        diskAvailableLabel->setMaximumSize(QSize(16777215, 25));
        diskAvailableLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(diskAvailableLabel, 5, 2, 1, 1);

        necessaryDiskStaticLabel = new QLabel(widget);
        necessaryDiskStaticLabel->setObjectName(QStringLiteral("necessaryDiskStaticLabel"));
        necessaryDiskStaticLabel->setMinimumSize(QSize(0, 25));
        necessaryDiskStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(necessaryDiskStaticLabel, 6, 0, 1, 2);

        necessaryDiskLabel = new QLabel(widget);
        necessaryDiskLabel->setObjectName(QStringLiteral("necessaryDiskLabel"));
        necessaryDiskLabel->setMinimumSize(QSize(0, 25));
        necessaryDiskLabel->setMaximumSize(QSize(16777215, 25));
        necessaryDiskLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(necessaryDiskLabel, 6, 2, 1, 1);

        sampleTimeEstimateStaticLabel = new QLabel(widget);
        sampleTimeEstimateStaticLabel->setObjectName(QStringLiteral("sampleTimeEstimateStaticLabel"));
        sampleTimeEstimateStaticLabel->setMinimumSize(QSize(0, 25));
        sampleTimeEstimateStaticLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(sampleTimeEstimateStaticLabel, 7, 0, 1, 2);

        sampleTimeEstimateLabel = new QLabel(widget);
        sampleTimeEstimateLabel->setObjectName(QStringLiteral("sampleTimeEstimateLabel"));
        sampleTimeEstimateLabel->setMinimumSize(QSize(0, 25));
        sampleTimeEstimateLabel->setMaximumSize(QSize(16777215, 25));
        sampleTimeEstimateLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(sampleTimeEstimateLabel, 7, 2, 1, 1);

        leakSampleSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(leakSampleSpacer, 8, 0, 1, 2);

        leakSampleCheckBox = new QCheckBox(widget);
        leakSampleCheckBox->setObjectName(QStringLiteral("leakSampleCheckBox"));
        leakSampleCheckBox->setMinimumSize(QSize(0, 25));
        leakSampleCheckBox->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(leakSampleCheckBox, 8, 2, 1, 1);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(0, 25));
        progressBar->setMaximumSize(QSize(16777215, 25));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(progressBar, 9, 0, 1, 3);

        beginSampleButton = new QPushButton(widget);
        beginSampleButton->setObjectName(QStringLiteral("beginSampleButton"));
        beginSampleButton->setMinimumSize(QSize(200, 50));
        beginSampleButton->setMaximumSize(QSize(100, 50));

        gridLayout->addWidget(beginSampleButton, 10, 0, 1, 3);


        retranslateUi(ConeScanWidget);

        QMetaObject::connectSlotsByName(ConeScanWidget);
    } // setupUi

    void retranslateUi(QWidget *ConeScanWidget)
    {
        ConeScanWidget->setWindowTitle(QApplication::translate("ConeScanWidget", "\351\224\245\346\235\237\346\211\253\346\217\217", nullptr));
        fileNameStatiLabel->setText(QApplication::translate("ConeScanWidget", "\346\226\207\344\273\266\345\220\215", nullptr));
        saveDirButton->setText(QApplication::translate("ConeScanWidget", "..", nullptr));
        disposeButton->setText(QApplication::translate("ConeScanWidget", "\346\240\241\346\255\243", nullptr));
        graduationStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\210\206\345\272\246\346\225\260", nullptr));
        frameAverageStaticLabel->setText(QApplication::translate("ConeScanWidget", "\345\270\247\345\271\263\345\235\207", nullptr));
        diskAvailableStaticLabel->setText(QApplication::translate("ConeScanWidget", "\347\241\254\347\233\230\345\211\251\344\275\231\347\251\272\351\227\264", nullptr));
        diskAvailableLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        necessaryDiskStaticLabel->setText(QApplication::translate("ConeScanWidget", "\351\207\207\351\233\206\351\234\200\350\246\201\347\251\272\351\227\264", nullptr));
        necessaryDiskLabel->setText(QApplication::translate("ConeScanWidget", "TextLabel", nullptr));
        sampleTimeEstimateStaticLabel->setText(QApplication::translate("ConeScanWidget", "\351\242\204\350\256\241\351\207\207\351\233\206\346\227\266\351\227\264", nullptr));
        sampleTimeEstimateLabel->setText(QApplication::translate("ConeScanWidget", "\351\242\204\350\256\241\351\207\207\351\233\206\346\227\266\351\227\264", nullptr));
        leakSampleCheckBox->setText(QApplication::translate("ConeScanWidget", "\347\274\272\345\233\276\351\207\207\351\233\206", nullptr));
        beginSampleButton->setText(QApplication::translate("ConeScanWidget", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConeScanWidget: public Ui_ConeScanWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONESCANWIDGET_H
