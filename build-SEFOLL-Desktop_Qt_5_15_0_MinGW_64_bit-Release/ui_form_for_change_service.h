/********************************************************************************
** Form generated from reading UI file 'form_for_change_service.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_CHANGE_SERVICE_H
#define UI_FORM_FOR_CHANGE_SERVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_For_Change_Service
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *data_services;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *name;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDoubleSpinBox *cost;
    QSpacerItem *horizontalSpacer;
    QPushButton *enter_change_button;
    QPushButton *back_button;

    void setupUi(QWidget *Form_For_Change_Service)
    {
        if (Form_For_Change_Service->objectName().isEmpty())
            Form_For_Change_Service->setObjectName(QString::fromUtf8("Form_For_Change_Service"));
        Form_For_Change_Service->resize(734, 339);
        verticalLayout = new QVBoxLayout(Form_For_Change_Service);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(Form_For_Change_Service);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        data_services = new QTableWidget(Form_For_Change_Service);
        if (data_services->columnCount() < 2)
            data_services->setColumnCount(2);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font1;
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        __qtablewidgetitem->setForeground(brush);
        data_services->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font2;
        font2.setPointSize(12);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        data_services->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        data_services->setObjectName(QString::fromUtf8("data_services"));
        data_services->setEnabled(true);
        data_services->setFont(font1);
        data_services->setMouseTracking(false);
        data_services->setFocusPolicy(Qt::NoFocus);
        data_services->setContextMenuPolicy(Qt::NoContextMenu);
        data_services->setLayoutDirection(Qt::LeftToRight);
        data_services->setAutoFillBackground(false);
        data_services->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));
        data_services->setFrameShape(QFrame::StyledPanel);
        data_services->setFrameShadow(QFrame::Plain);
        data_services->setLineWidth(2);
        data_services->setMidLineWidth(0);
        data_services->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        data_services->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        data_services->setAutoScrollMargin(20);
        data_services->setEditTriggers(QAbstractItemView::NoEditTriggers);
        data_services->setTabKeyNavigation(false);
        data_services->setProperty("showDropIndicator", QVariant(false));
        data_services->setDragDropOverwriteMode(false);
        data_services->setSelectionMode(QAbstractItemView::SingleSelection);
        data_services->setSelectionBehavior(QAbstractItemView::SelectRows);
        data_services->setTextElideMode(Qt::ElideMiddle);
        data_services->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        data_services->setShowGrid(true);
        data_services->setGridStyle(Qt::SolidLine);
        data_services->setSortingEnabled(false);
        data_services->setWordWrap(false);
        data_services->setCornerButtonEnabled(false);
        data_services->horizontalHeader()->setVisible(true);
        data_services->horizontalHeader()->setCascadingSectionResizes(false);
        data_services->horizontalHeader()->setMinimumSectionSize(10);
        data_services->horizontalHeader()->setDefaultSectionSize(100);
        data_services->horizontalHeader()->setHighlightSections(false);
        data_services->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        data_services->horizontalHeader()->setStretchLastSection(true);
        data_services->verticalHeader()->setVisible(false);
        data_services->verticalHeader()->setCascadingSectionResizes(false);
        data_services->verticalHeader()->setMinimumSectionSize(30);
        data_services->verticalHeader()->setDefaultSectionSize(30);
        data_services->verticalHeader()->setHighlightSections(true);
        data_services->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        data_services->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(data_services);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Form_For_Change_Service);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        name = new QLineEdit(Form_For_Change_Service);
        name->setObjectName(QString::fromUtf8("name"));
        name->setEnabled(false);
        name->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout_2->addWidget(name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Form_For_Change_Service);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        cost = new QDoubleSpinBox(Form_For_Change_Service);
        cost->setObjectName(QString::fromUtf8("cost"));
        cost->setEnabled(false);
        cost->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:50;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));
        cost->setMaximum(99999.000000000000000);

        horizontalLayout->addWidget(cost);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        enter_change_button = new QPushButton(Form_For_Change_Service);
        enter_change_button->setObjectName(QString::fromUtf8("enter_change_button"));
        enter_change_button->setEnabled(false);
        enter_change_button->setFont(font);
        enter_change_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:160;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout->addWidget(enter_change_button);

        back_button = new QPushButton(Form_For_Change_Service);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setFont(font);
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

        horizontalLayout->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Form_For_Change_Service);

        QMetaObject::connectSlotsByName(Form_For_Change_Service);
    } // setupUi

    void retranslateUi(QWidget *Form_For_Change_Service)
    {
        Form_For_Change_Service->setWindowTitle(QCoreApplication::translate("Form_For_Change_Service", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        label->setText(QCoreApplication::translate("Form_For_Change_Service", "\320\232\320\233\320\230\320\232\320\235\320\230\320\242\320\225 \320\235\320\220 \320\243\320\241\320\233\320\243\320\223\320\243, \320\232\320\236\320\242\320\236\320\240\320\243\320\256 \320\245\320\236\320\242\320\230\320\242\320\225 \320\230\320\227\320\234\320\225\320\235\320\230\320\242\320\254", nullptr));
        QTableWidgetItem *___qtablewidgetitem = data_services->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form_For_Change_Service", "\320\246\320\225\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = data_services->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form_For_Change_Service", "\320\235\320\220\320\230\320\234\320\225\320\235\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        label_2->setText(QCoreApplication::translate("Form_For_Change_Service", "\320\235\320\220\320\230\320\234\320\225\320\235\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        label_3->setText(QCoreApplication::translate("Form_For_Change_Service", "\320\246\320\225\320\235\320\220", nullptr));
        enter_change_button->setText(QCoreApplication::translate("Form_For_Change_Service", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        back_button->setText(QCoreApplication::translate("Form_For_Change_Service", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_For_Change_Service: public Ui_Form_For_Change_Service {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_CHANGE_SERVICE_H
