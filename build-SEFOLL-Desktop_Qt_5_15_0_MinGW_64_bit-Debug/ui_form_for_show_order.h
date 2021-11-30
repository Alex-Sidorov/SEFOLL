/********************************************************************************
** Form generated from reading UI file 'form_for_show_order.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_SHOW_ORDER_H
#define UI_FORM_FOR_SHOW_ORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_For_Show_Order
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *number_order;
    QLabel *number;
    QLabel *client;
    QLabel *worker;
    QLabel *date;
    QLabel *status;
    QLabel *discount;
    QTableWidget *data_services;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cost;
    QSpacerItem *horizontalSpacer;
    QPushButton *delete_button;
    QPushButton *complete_button;
    QPushButton *enter_button;
    QPushButton *back_button;

    void setupUi(QWidget *Form_For_Show_Order)
    {
        if (Form_For_Show_Order->objectName().isEmpty())
            Form_For_Show_Order->setObjectName(QString::fromUtf8("Form_For_Show_Order"));
        Form_For_Show_Order->setEnabled(true);
        Form_For_Show_Order->resize(716, 400);
        verticalLayout = new QVBoxLayout(Form_For_Show_Order);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        label = new QLabel(Form_For_Show_Order);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(900, 16777215));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        number_order = new QSpinBox(Form_For_Show_Order);
        number_order->setObjectName(QString::fromUtf8("number_order"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(number_order->sizePolicy().hasHeightForWidth());
        number_order->setSizePolicy(sizePolicy);
        number_order->setMaximumSize(QSize(16777215, 16777215));
        number_order->setSizeIncrement(QSize(0, 0));
        number_order->setBaseSize(QSize(0, 0));
        number_order->setLayoutDirection(Qt::LeftToRight);
        number_order->setStyleSheet(QString::fromUtf8(" \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));
        number_order->setMaximum(1000000);

        horizontalLayout->addWidget(number_order);


        verticalLayout->addLayout(horizontalLayout);

        number = new QLabel(Form_For_Show_Order);
        number->setObjectName(QString::fromUtf8("number"));
        number->setFont(font);

        verticalLayout->addWidget(number);

        client = new QLabel(Form_For_Show_Order);
        client->setObjectName(QString::fromUtf8("client"));
        client->setFont(font);

        verticalLayout->addWidget(client);

        worker = new QLabel(Form_For_Show_Order);
        worker->setObjectName(QString::fromUtf8("worker"));
        worker->setFont(font);

        verticalLayout->addWidget(worker);

        date = new QLabel(Form_For_Show_Order);
        date->setObjectName(QString::fromUtf8("date"));
        date->setFont(font);

        verticalLayout->addWidget(date);

        status = new QLabel(Form_For_Show_Order);
        status->setObjectName(QString::fromUtf8("status"));
        status->setFont(font);

        verticalLayout->addWidget(status);

        discount = new QLabel(Form_For_Show_Order);
        discount->setObjectName(QString::fromUtf8("discount"));
        discount->setFont(font);

        verticalLayout->addWidget(discount);

        data_services = new QTableWidget(Form_For_Show_Order);
        if (data_services->columnCount() < 3)
            data_services->setColumnCount(3);
        QFont font1;
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font1);
        data_services->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setForeground(brush);
        data_services->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font2;
        font2.setPointSize(12);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font2);
        data_services->setHorizontalHeaderItem(2, __qtablewidgetitem2);
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
        data_services->horizontalHeader()->setVisible(false);
        data_services->horizontalHeader()->setCascadingSectionResizes(false);
        data_services->horizontalHeader()->setMinimumSectionSize(10);
        data_services->horizontalHeader()->setDefaultSectionSize(150);
        data_services->horizontalHeader()->setHighlightSections(true);
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cost = new QLabel(Form_For_Show_Order);
        cost->setObjectName(QString::fromUtf8("cost"));
        cost->setFont(font1);

        horizontalLayout_3->addWidget(cost);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        delete_button = new QPushButton(Form_For_Show_Order);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        delete_button->setEnabled(false);
        delete_button->setFont(font);
        delete_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_3->addWidget(delete_button);

        complete_button = new QPushButton(Form_For_Show_Order);
        complete_button->setObjectName(QString::fromUtf8("complete_button"));
        complete_button->setEnabled(false);
        complete_button->setFont(font);
        complete_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_3->addWidget(complete_button);

        enter_button = new QPushButton(Form_For_Show_Order);
        enter_button->setObjectName(QString::fromUtf8("enter_button"));
        enter_button->setEnabled(false);
        enter_button->setFont(font);
        enter_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_3->addWidget(enter_button);

        back_button = new QPushButton(Form_For_Show_Order);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setFont(font);
        back_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_3->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Form_For_Show_Order);

        QMetaObject::connectSlotsByName(Form_For_Show_Order);
    } // setupUi

    void retranslateUi(QWidget *Form_For_Show_Order)
    {
        Form_For_Show_Order->setWindowTitle(QCoreApplication::translate("Form_For_Show_Order", "\320\227\320\260\320\272\320\260\320\267\321\213", nullptr));
        label->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267\320\260  ", nullptr));
        number->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\235\320\276\320\274\320\265\321\200:", nullptr));
        client->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\232\320\273\320\270\320\265\320\275\321\202:", nullptr));
        worker->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214:", nullptr));
        date->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\275\321\217\321\202\320\270\321\217 \320\267\320\260\320\272\320\260\320\267\320\260:", nullptr));
        status->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\267\320\260\320\272\320\260\320\267\320\260:", nullptr));
        discount->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\241\320\272\320\270\320\264\320\272\320\260 %:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = data_services->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\232\320\236\320\233\320\230\320\247\320\225\320\241\320\242\320\222\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = data_services->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\246\320\225\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = data_services->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\235\320\220\320\230\320\234\320\225\320\235\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        cost->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\241\321\203\320\274\320\274\320\260:", nullptr));
        delete_button->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        complete_button->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        enter_button->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\235\320\260\320\271\321\202\320\270 \320\267\320\260\320\272\320\260\320\267", nullptr));
        back_button->setText(QCoreApplication::translate("Form_For_Show_Order", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_For_Show_Order: public Ui_Form_For_Show_Order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_SHOW_ORDER_H
