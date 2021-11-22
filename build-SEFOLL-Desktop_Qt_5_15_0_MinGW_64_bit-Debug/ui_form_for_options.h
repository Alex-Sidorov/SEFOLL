/********************************************************************************
** Form generated from reading UI file 'form_for_options.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_OPTIONS_H
#define UI_FORM_FOR_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForOptions
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *add_password_button;
    QPushButton *change_password_button;
    QPushButton *delete_password_button;
    QPushButton *change_access_button;
    QPushButton *back_button;

    void setupUi(QWidget *FormForOptions)
    {
        if (FormForOptions->objectName().isEmpty())
            FormForOptions->setObjectName(QString::fromUtf8("FormForOptions"));
        FormForOptions->resize(403, 167);
        verticalLayout = new QVBoxLayout(FormForOptions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(FormForOptions);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        add_password_button = new QPushButton(FormForOptions);
        add_password_button->setObjectName(QString::fromUtf8("add_password_button"));

        verticalLayout->addWidget(add_password_button);

        change_password_button = new QPushButton(FormForOptions);
        change_password_button->setObjectName(QString::fromUtf8("change_password_button"));

        verticalLayout->addWidget(change_password_button);

        delete_password_button = new QPushButton(FormForOptions);
        delete_password_button->setObjectName(QString::fromUtf8("delete_password_button"));

        verticalLayout->addWidget(delete_password_button);

        change_access_button = new QPushButton(FormForOptions);
        change_access_button->setObjectName(QString::fromUtf8("change_access_button"));

        verticalLayout->addWidget(change_access_button);

        back_button = new QPushButton(FormForOptions);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        verticalLayout->addWidget(back_button);


        retranslateUi(FormForOptions);

        QMetaObject::connectSlotsByName(FormForOptions);
    } // setupUi

    void retranslateUi(QWidget *FormForOptions)
    {
        FormForOptions->setWindowTitle(QCoreApplication::translate("FormForOptions", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("FormForOptions", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        add_password_button->setText(QCoreApplication::translate("FormForOptions", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        change_password_button->setText(QCoreApplication::translate("FormForOptions", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        delete_password_button->setText(QCoreApplication::translate("FormForOptions", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        change_access_button->setText(QCoreApplication::translate("FormForOptions", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\203\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        back_button->setText(QCoreApplication::translate("FormForOptions", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForOptions: public Ui_FormForOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_OPTIONS_H
