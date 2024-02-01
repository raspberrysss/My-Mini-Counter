/********************************************************************************
** Form generated from reading UI file 'new_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_WINDOW_H
#define UI_NEW_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_window
{
public:

    void setupUi(QWidget *new_window)
    {
        if (new_window->objectName().isEmpty())
            new_window->setObjectName(QString::fromUtf8("new_window"));
        new_window->resize(400, 300);

        retranslateUi(new_window);

        QMetaObject::connectSlotsByName(new_window);
    } // setupUi

    void retranslateUi(QWidget *new_window)
    {
        new_window->setWindowTitle(QApplication::translate("new_window", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_window: public Ui_new_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_WINDOW_H
