/********************************************************************************
** Form generated from reading UI file 'imagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIDGET_H
#define UI_IMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *folderTree;
    QPushButton *foldButton;
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel;
    QLabel *messageLabel;

    void setupUi(QWidget *ImageWidget)
    {
        if (ImageWidget->objectName().isEmpty())
            ImageWidget->setObjectName(QStringLiteral("ImageWidget"));
        ImageWidget->resize(737, 457);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageWidget->sizePolicy().hasHeightForWidth());
        ImageWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ImageWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        folderTree = new QTreeWidget(ImageWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        folderTree->setHeaderItem(__qtreewidgetitem);
        folderTree->setObjectName(QStringLiteral("folderTree"));
        folderTree->setMinimumSize(QSize(150, 0));
        folderTree->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(folderTree);

        foldButton = new QPushButton(ImageWidget);
        foldButton->setObjectName(QStringLiteral("foldButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(foldButton->sizePolicy().hasHeightForWidth());
        foldButton->setSizePolicy(sizePolicy1);
        foldButton->setMinimumSize(QSize(15, 50));
        foldButton->setMaximumSize(QSize(15, 50));

        horizontalLayout->addWidget(foldButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        imageLabel = new QLabel(ImageWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy2);
        imageLabel->setMaximumSize(QSize(16777215, 16777215));
        imageLabel->setMouseTracking(false);
        imageLabel->setFocusPolicy(Qt::ClickFocus);
        imageLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(imageLabel);

        messageLabel = new QLabel(ImageWidget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(messageLabel->sizePolicy().hasHeightForWidth());
        messageLabel->setSizePolicy(sizePolicy3);
        messageLabel->setMinimumSize(QSize(0, 12));
        messageLabel->setMaximumSize(QSize(16777215, 12));
        messageLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(messageLabel);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);

        retranslateUi(ImageWidget);

        QMetaObject::connectSlotsByName(ImageWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageWidget)
    {
        ImageWidget->setWindowTitle(QApplication::translate("ImageWidget", "ImageWidget", nullptr));
        foldButton->setText(QApplication::translate("ImageWidget", "PushButton", nullptr));
        imageLabel->setText(QString());
        messageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageWidget: public Ui_ImageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIDGET_H
