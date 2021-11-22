/********************************************************************************
** Form generated from reading UI file 'form_for_change_access.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_CHANGE_ACCESS_H
#define UI_FORM_FOR_CHANGE_ACCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForChangeAccess
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *id;
    QComboBox *access;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ok_button;
    QPushButton *back_button;

    void setupUi(QWidget *FormForChangeAccess)
    {
        if (FormForChangeAccess->objectName().isEmpty())
            FormForChangeAccess->setObjectName(QString::fromUtf8("FormForChangeAccess"));
        FormForChangeAccess->resize(283, 111);
        verticalLayout = new QVBoxLayout(FormForChangeAccess);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 0, 2, 2);
        label = new QLabel(FormForChangeAccess);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(FormForChangeAccess);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        id = new QSpinBox(FormForChangeAccess);
        id->setObjectName(QString::fromUtf8("id"));

        horizontalLayout->addWidget(id);


        verticalLayout->addLayout(horizontalLayout);

        access = new QComboBox(FormForChangeAccess);
        access->addItem(QString());
        access->addItem(QString());
        access->addItem(QString());
        access->addItem(QString());
        access->addItem(QString());
        access->setObjectName(QString::fromUtf8("access"));
        access->setEnabled(true);

        verticalLayout->addWidget(access);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ok_button = new QPushButton(FormForChangeAccess);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));

        horizontalLayout_2->addWidget(ok_button);

        back_button = new QPushButton(FormForChangeAccess);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        horizontalLayout_2->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FormForChangeAccess);

        QMetaObject::connectSlotsByName(FormForChangeAccess);
    } // setupUi

    void retranslateUi(QWidget *FormForChangeAccess)
    {
        FormForChangeAccess->setWindowTitle(QCoreApplication::translate("FormForChangeAccess", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        label->setText(QCoreApplication::translate("FormForChangeAccess", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\203\321\200\320\276\320\262\320\275\321\217 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("FormForChangeAccess", "ID \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
        access->setItemText(0, QCoreApplication::translate("FormForChangeAccess", "\320\223\320\276\321\201\321\202\321\214", nullptr));
        access->setItemText(1, QCoreApplication::translate("FormForChangeAccess", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        access->setItemText(2, QCoreApplication::translate("FormForChangeAccess", "\320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\320\265\321\202 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        access->setItemText(3, QCoreApplication::translate("FormForChangeAccess", "\320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\267\320\260\320\272\321\200\321\213\320\262\320\260\320\265\321\202 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        access->setItemText(4, QCoreApplication::translate("FormForChangeAccess", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));

        ok_button->setText(QCoreApplication::translate("FormForChangeAccess", "\320\236\320\272", nullptr));
        back_button->setText(QCoreApplication::translate("FormForChangeAccess", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForChangeAccess: public Ui_FormForChangeAccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_CHANGE_ACCESS_H
