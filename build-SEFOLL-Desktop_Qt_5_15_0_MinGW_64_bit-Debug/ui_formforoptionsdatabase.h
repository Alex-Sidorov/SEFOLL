/********************************************************************************
** Form generated from reading UI file 'formforoptionsdatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFOROPTIONSDATABASE_H
#define UI_FORMFOROPTIONSDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForOptionsDataBase
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *path_data_base;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *select_data_base_button;
    QPushButton *create_data_base_button;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *back_button;

    void setupUi(QWidget *FormForOptionsDataBase)
    {
        if (FormForOptionsDataBase->objectName().isEmpty())
            FormForOptionsDataBase->setObjectName(QString::fromUtf8("FormForOptionsDataBase"));
        FormForOptionsDataBase->resize(389, 100);
        verticalLayout = new QVBoxLayout(FormForOptionsDataBase);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        path_data_base = new QLabel(FormForOptionsDataBase);
        path_data_base->setObjectName(QString::fromUtf8("path_data_base"));

        verticalLayout->addWidget(path_data_base);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        select_data_base_button = new QPushButton(FormForOptionsDataBase);
        select_data_base_button->setObjectName(QString::fromUtf8("select_data_base_button"));
        QFont font;
        font.setPointSize(10);
        select_data_base_button->setFont(font);

        horizontalLayout_2->addWidget(select_data_base_button);

        create_data_base_button = new QPushButton(FormForOptionsDataBase);
        create_data_base_button->setObjectName(QString::fromUtf8("create_data_base_button"));
        create_data_base_button->setFont(font);

        horizontalLayout_2->addWidget(create_data_base_button);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        back_button = new QPushButton(FormForOptionsDataBase);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(back_button->sizePolicy().hasHeightForWidth());
        back_button->setSizePolicy(sizePolicy);
        back_button->setMinimumSize(QSize(0, 0));
        back_button->setBaseSize(QSize(0, 0));
        back_button->setFont(font);

        horizontalLayout->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FormForOptionsDataBase);

        QMetaObject::connectSlotsByName(FormForOptionsDataBase);
    } // setupUi

    void retranslateUi(QWidget *FormForOptionsDataBase)
    {
        FormForOptionsDataBase->setWindowTitle(QCoreApplication::translate("FormForOptionsDataBase", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        path_data_base->setText(QString());
        select_data_base_button->setText(QCoreApplication::translate("FormForOptionsDataBase", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        create_data_base_button->setText(QCoreApplication::translate("FormForOptionsDataBase", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        back_button->setText(QCoreApplication::translate("FormForOptionsDataBase", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForOptionsDataBase: public Ui_FormForOptionsDataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFOROPTIONSDATABASE_H
