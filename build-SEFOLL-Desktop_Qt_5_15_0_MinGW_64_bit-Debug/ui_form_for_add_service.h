/********************************************************************************
** Form generated from reading UI file 'form_for_add_service.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_ADD_SERVICE_H
#define UI_FORM_FOR_ADD_SERVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_For_Add_Service
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *name_service;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *cost_service;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_button;
    QPushButton *back_button;

    void setupUi(QWidget *Form_For_Add_Service)
    {
        if (Form_For_Add_Service->objectName().isEmpty())
            Form_For_Add_Service->setObjectName(QString::fromUtf8("Form_For_Add_Service"));
        Form_For_Add_Service->resize(439, 97);
        verticalLayout = new QVBoxLayout(Form_For_Add_Service);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Form_For_Add_Service);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        name_service = new QLineEdit(Form_For_Add_Service);
        name_service->setObjectName(QString::fromUtf8("name_service"));

        horizontalLayout->addWidget(name_service);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Form_For_Add_Service);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cost_service = new QDoubleSpinBox(Form_For_Add_Service);
        cost_service->setObjectName(QString::fromUtf8("cost_service"));
        cost_service->setMaximum(99999.000000000000000);

        horizontalLayout_2->addWidget(cost_service);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ok_button = new QPushButton(Form_For_Add_Service);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setEnabled(false);
        QFont font;
        font.setPointSize(10);
        ok_button->setFont(font);

        horizontalLayout_2->addWidget(ok_button);

        back_button = new QPushButton(Form_For_Add_Service);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setFont(font);

        horizontalLayout_2->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Form_For_Add_Service);

        QMetaObject::connectSlotsByName(Form_For_Add_Service);
    } // setupUi

    void retranslateUi(QWidget *Form_For_Add_Service)
    {
        Form_For_Add_Service->setWindowTitle(QCoreApplication::translate("Form_For_Add_Service", "\320\224\320\276\320\261\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("Form_For_Add_Service", "\320\235\320\220\320\230\320\234\320\225\320\235\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        label->setText(QCoreApplication::translate("Form_For_Add_Service", "\320\246\320\225\320\235\320\220", nullptr));
        ok_button->setText(QCoreApplication::translate("Form_For_Add_Service", "\320\236\320\272", nullptr));
        back_button->setText(QCoreApplication::translate("Form_For_Add_Service", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_For_Add_Service: public Ui_Form_For_Add_Service {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_ADD_SERVICE_H
