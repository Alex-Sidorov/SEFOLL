/********************************************************************************
** Form generated from reading UI file 'form_for_delete_password.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_DELETE_PASSWORD_H
#define UI_FORM_FOR_DELETE_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForDeletePassword
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *id;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ok_button;
    QPushButton *back_button;

    void setupUi(QWidget *FormForDeletePassword)
    {
        if (FormForDeletePassword->objectName().isEmpty())
            FormForDeletePassword->setObjectName(QString::fromUtf8("FormForDeletePassword"));
        FormForDeletePassword->resize(254, 79);
        verticalLayout = new QVBoxLayout(FormForDeletePassword);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(FormForDeletePassword);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(FormForDeletePassword);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        id = new QSpinBox(FormForDeletePassword);
        id->setObjectName(QString::fromUtf8("id"));
        id->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout->addWidget(id);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ok_button = new QPushButton(FormForDeletePassword);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_2->addWidget(ok_button);

        back_button = new QPushButton(FormForDeletePassword);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_2->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FormForDeletePassword);

        QMetaObject::connectSlotsByName(FormForDeletePassword);
    } // setupUi

    void retranslateUi(QWidget *FormForDeletePassword)
    {
        FormForDeletePassword->setWindowTitle(QCoreApplication::translate("FormForDeletePassword", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        label->setText(QCoreApplication::translate("FormForDeletePassword", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("FormForDeletePassword", "ID \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
        ok_button->setText(QCoreApplication::translate("FormForDeletePassword", "\320\236\320\272", nullptr));
        back_button->setText(QCoreApplication::translate("FormForDeletePassword", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForDeletePassword: public Ui_FormForDeletePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_DELETE_PASSWORD_H
