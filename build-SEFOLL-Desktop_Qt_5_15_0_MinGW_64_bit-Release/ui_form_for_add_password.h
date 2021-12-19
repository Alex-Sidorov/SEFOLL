/********************************************************************************
** Form generated from reading UI file 'form_for_add_password.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_ADD_PASSWORD_H
#define UI_FORM_FOR_ADD_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForAddPassword
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QSpinBox *id;
    QLineEdit *password;
    QComboBox *access;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ok_button;
    QPushButton *back_button;

    void setupUi(QWidget *FormForAddPassword)
    {
        if (FormForAddPassword->objectName().isEmpty())
            FormForAddPassword->setObjectName(QString::fromUtf8("FormForAddPassword"));
        FormForAddPassword->resize(276, 147);
        verticalLayout_3 = new QVBoxLayout(FormForAddPassword);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(FormForAddPassword);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(FormForAddPassword);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(FormForAddPassword);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        id = new QSpinBox(FormForAddPassword);
        id->setObjectName(QString::fromUtf8("id"));
        id->setStyleSheet(QString::fromUtf8("height:20;\n"
"border-radius: 4px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"border: 1px solid grey;\n"
"border-color: rgb(0, 0, 0);\n"
""));

        verticalLayout->addWidget(id);

        password = new QLineEdit(FormForAddPassword);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEnabled(true);
        password->setStyleSheet(QString::fromUtf8("height:20;\n"
"border-radius: 4px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"border: 1px solid grey;\n"
"border-color: rgb(0, 0, 0);\n"
""));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        access = new QComboBox(FormForAddPassword);
        access->addItem(QString());
        access->addItem(QString());
        access->addItem(QString());
        access->addItem(QString());
        access->addItem(QString());
        access->setObjectName(QString::fromUtf8("access"));
        access->setEnabled(true);
        access->setStyleSheet(QString::fromUtf8("height:25;\n"
"border-radius: 4px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"border: 1px solid grey;\n"
"border-color: rgb(0, 0, 0);\n"
""));

        verticalLayout_3->addWidget(access);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ok_button = new QPushButton(FormForAddPassword);
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

        horizontalLayout_3->addWidget(ok_button);

        back_button = new QPushButton(FormForAddPassword);
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

        horizontalLayout_3->addWidget(back_button);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(FormForAddPassword);

        QMetaObject::connectSlotsByName(FormForAddPassword);
    } // setupUi

    void retranslateUi(QWidget *FormForAddPassword)
    {
        FormForAddPassword->setWindowTitle(QCoreApplication::translate("FormForAddPassword", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        label->setText(QCoreApplication::translate("FormForAddPassword", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("FormForAddPassword", "ID \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("FormForAddPassword", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        access->setItemText(0, QCoreApplication::translate("FormForAddPassword", "\320\223\320\276\321\201\321\202\321\214", nullptr));
        access->setItemText(1, QCoreApplication::translate("FormForAddPassword", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        access->setItemText(2, QCoreApplication::translate("FormForAddPassword", "\320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\320\265\321\202 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        access->setItemText(3, QCoreApplication::translate("FormForAddPassword", "\320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\267\320\260\320\272\321\200\321\213\320\262\320\260\320\265\321\202 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        access->setItemText(4, QCoreApplication::translate("FormForAddPassword", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));

        ok_button->setText(QCoreApplication::translate("FormForAddPassword", "\320\236\320\272", nullptr));
        back_button->setText(QCoreApplication::translate("FormForAddPassword", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForAddPassword: public Ui_FormForAddPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_ADD_PASSWORD_H
