/********************************************************************************
** Form generated from reading UI file 'form_for_login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_LOGIN_H
#define UI_FORM_FOR_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForLogin
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *id;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *password;
    QPushButton *ok;
    QPushButton *button_for_guest;
    QLabel *error;

    void setupUi(QWidget *FormForLogin)
    {
        if (FormForLogin->objectName().isEmpty())
            FormForLogin->setObjectName(QString::fromUtf8("FormForLogin"));
        FormForLogin->resize(263, 154);
        verticalLayout = new QVBoxLayout(FormForLogin);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(FormForLogin);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(FormForLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        id = new QSpinBox(FormForLogin);
        id->setObjectName(QString::fromUtf8("id"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy);
        id->setMinimumSize(QSize(133, 0));
        id->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:144;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));
        id->setMaximum(1000);

        horizontalLayout->addWidget(id);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(FormForLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        password = new QLineEdit(FormForLogin);
        password->setObjectName(QString::fromUtf8("password"));
        sizePolicy.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy);
        password->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:160;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);

        ok = new QPushButton(FormForLogin);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout->addWidget(ok);

        button_for_guest = new QPushButton(FormForLogin);
        button_for_guest->setObjectName(QString::fromUtf8("button_for_guest"));
        button_for_guest->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout->addWidget(button_for_guest);

        error = new QLabel(FormForLogin);
        error->setObjectName(QString::fromUtf8("error"));
        error->setEnabled(true);

        verticalLayout->addWidget(error);


        retranslateUi(FormForLogin);

        QMetaObject::connectSlotsByName(FormForLogin);
    } // setupUi

    void retranslateUi(QWidget *FormForLogin)
    {
        FormForLogin->setWindowTitle(QCoreApplication::translate("FormForLogin", "\320\222\321\205\320\276\320\264", nullptr));
        label->setText(QCoreApplication::translate("FormForLogin", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 ID \320\270 \320\277\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\262\321\205\320\276\320\264\320\260 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("FormForLogin", "ID", nullptr));
        label_3->setText(QCoreApplication::translate("FormForLogin", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        ok->setText(QCoreApplication::translate("FormForLogin", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        button_for_guest->setText(QCoreApplication::translate("FormForLogin", "\320\222\320\276\320\271\321\202\320\270 \320\272\320\260\320\272 \320\263\320\276\321\201\321\202\321\214", nullptr));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormForLogin: public Ui_FormForLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_LOGIN_H
