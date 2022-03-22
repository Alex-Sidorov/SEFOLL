/********************************************************************************
** Form generated from reading UI file 'form_for_give_order.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_GIVE_ORDER_H
#define UI_FORM_FOR_GIVE_ORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForGiveOrder
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *name_client;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *names_workers;
    QDateEdit *date;
    QTableWidget *data_services;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *discount;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cost;
    QSpacerItem *horizontalSpacer;
    QPushButton *enter_button;
    QPushButton *back_button;

    void setupUi(QWidget *FormForGiveOrder)
    {
        if (FormForGiveOrder->objectName().isEmpty())
            FormForGiveOrder->setObjectName(QString::fromUtf8("FormForGiveOrder"));
        FormForGiveOrder->resize(751, 365);
        verticalLayout = new QVBoxLayout(FormForGiveOrder);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FormForGiveOrder);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        name_client = new QLineEdit(FormForGiveOrder);
        name_client->setObjectName(QString::fromUtf8("name_client"));
        name_client->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"height:20;\n"
"border-color: rgb(11, 11, 11);\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout->addWidget(name_client);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FormForGiveOrder);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        names_workers = new QComboBox(FormForGiveOrder);
        names_workers->setObjectName(QString::fromUtf8("names_workers"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(names_workers->sizePolicy().hasHeightForWidth());
        names_workers->setSizePolicy(sizePolicy);
        names_workers->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"height:20;\n"
"border-color: rgb(11, 11, 11);\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout_2->addWidget(names_workers);


        verticalLayout->addLayout(horizontalLayout_2);

        date = new QDateEdit(FormForGiveOrder);
        date->setObjectName(QString::fromUtf8("date"));
        date->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        verticalLayout->addWidget(date);

        data_services = new QTableWidget(FormForGiveOrder);
        if (data_services->columnCount() < 3)
            data_services->setColumnCount(3);
        QFont font1;
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        data_services->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setForeground(brush);
        data_services->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font2;
        font2.setPointSize(12);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
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
"border-radius : 4px;\n"
"border: 1px solid;\n"
"height:20;\n"
"border-color: rgb(11, 11, 11);\n"
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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(FormForGiveOrder);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_4->addWidget(label_3);

        discount = new QSpinBox(FormForGiveOrder);
        discount->setObjectName(QString::fromUtf8("discount"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(discount->sizePolicy().hasHeightForWidth());
        discount->setSizePolicy(sizePolicy1);
        discount->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"height:20;\n"
"border-color: rgb(11, 11, 11);\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));
        discount->setMaximum(100);

        horizontalLayout_4->addWidget(discount);

        horizontalSpacer_2 = new QSpacerItem(500, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cost = new QLabel(FormForGiveOrder);
        cost->setObjectName(QString::fromUtf8("cost"));
        cost->setFont(font1);

        horizontalLayout_3->addWidget(cost);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        enter_button = new QPushButton(FormForGiveOrder);
        enter_button->setObjectName(QString::fromUtf8("enter_button"));
        enter_button->setEnabled(false);
        enter_button->setFont(font);
        enter_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_3->addWidget(enter_button);

        back_button = new QPushButton(FormForGiveOrder);
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

        horizontalLayout_3->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(FormForGiveOrder);

        QMetaObject::connectSlotsByName(FormForGiveOrder);
    } // setupUi

    void retranslateUi(QWidget *FormForGiveOrder)
    {
        FormForGiveOrder->setWindowTitle(QCoreApplication::translate("FormForGiveOrder", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label->setText(QCoreApplication::translate("FormForGiveOrder", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("FormForGiveOrder", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = data_services->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FormForGiveOrder", "\320\232\320\236\320\233\320\230\320\247\320\225\320\241\320\242\320\222\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = data_services->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FormForGiveOrder", "\320\246\320\225\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = data_services->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FormForGiveOrder", "\320\235\320\220\320\230\320\234\320\225\320\235\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        label_3->setText(QCoreApplication::translate("FormForGiveOrder", "\320\241\320\272\320\270\320\264\320\272\320\260 %", nullptr));
        cost->setText(QCoreApplication::translate("FormForGiveOrder", "\320\241\321\203\320\274\320\274\320\260:0", nullptr));
        enter_button->setText(QCoreApplication::translate("FormForGiveOrder", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        back_button->setText(QCoreApplication::translate("FormForGiveOrder", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForGiveOrder: public Ui_FormForGiveOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_GIVE_ORDER_H
