/********************************************************************************
** Form generated from reading UI file 'msglistbox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGLISTBOX_H
#define UI_MSGLISTBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgListBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView;

    void setupUi(QWidget *MsgListBox)
    {
        if (MsgListBox->objectName().isEmpty())
            MsgListBox->setObjectName(QStringLiteral("MsgListBox"));
        MsgListBox->resize(350, 283);
        MsgListBox->setMinimumSize(QSize(350, 0));
        MsgListBox->setMaximumSize(QSize(350, 16777215));
        verticalLayout = new QVBoxLayout(MsgListBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MsgListBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));

        verticalLayout->addWidget(label);

        listView = new QListView(MsgListBox);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(300, 200));
        listView->setMaximumSize(QSize(16777215, 200));

        verticalLayout->addWidget(listView);


        retranslateUi(MsgListBox);

        QMetaObject::connectSlotsByName(MsgListBox);
    } // setupUi

    void retranslateUi(QWidget *MsgListBox)
    {
        MsgListBox->setWindowTitle(QApplication::translate("MsgListBox", "MsgListBox", nullptr));
        label->setText(QApplication::translate("MsgListBox", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MsgListBox: public Ui_MsgListBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGLISTBOX_H
