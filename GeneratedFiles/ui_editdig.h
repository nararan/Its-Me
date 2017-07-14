/********************************************************************************
** Form generated from reading UI file 'editdig.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIG_H
#define UI_EDITDIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editDig
{
public:

    void setupUi(QWidget *editDig)
    {
        if (editDig->objectName().isEmpty())
            editDig->setObjectName(QStringLiteral("editDig"));
        editDig->resize(400, 300);

        retranslateUi(editDig);

        QMetaObject::connectSlotsByName(editDig);
    } // setupUi

    void retranslateUi(QWidget *editDig)
    {
        editDig->setWindowTitle(QApplication::translate("editDig", "editDig", 0));
    } // retranslateUi

};

namespace Ui {
    class editDig: public Ui_editDig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIG_H
