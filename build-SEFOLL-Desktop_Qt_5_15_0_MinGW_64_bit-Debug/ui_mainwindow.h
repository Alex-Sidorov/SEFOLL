/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *give_order_button;
    QPushButton *show_order_button;
    QPushButton *show_data_button;
    QVBoxLayout *verticalLayout;
    QTableWidget *data_services;
    QHBoxLayout *horizontalLayout;
    QPushButton *options;
    QPushButton *options_data_base;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_service_button;
    QPushButton *change_service_button;
    QPushButton *delete_service_button;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(770, 405);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 2);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        give_order_button = new QPushButton(centralWidget);
        give_order_button->setObjectName(QString::fromUtf8("give_order_button"));
        QFont font;
        font.setPointSize(10);
        give_order_button->setFont(font);
        give_order_button->setCheckable(false);
        give_order_button->setAutoRepeatDelay(300);

        horizontalLayout_2->addWidget(give_order_button);

        show_order_button = new QPushButton(centralWidget);
        show_order_button->setObjectName(QString::fromUtf8("show_order_button"));
        show_order_button->setFont(font);

        horizontalLayout_2->addWidget(show_order_button);

        show_data_button = new QPushButton(centralWidget);
        show_data_button->setObjectName(QString::fromUtf8("show_data_button"));
        show_data_button->setFont(font);

        horizontalLayout_2->addWidget(show_data_button);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        data_services = new QTableWidget(centralWidget);
        if (data_services->columnCount() < 2)
            data_services->setColumnCount(2);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font1;
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font1);
        __qtablewidgetitem->setForeground(brush);
        data_services->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font2;
        font2.setPointSize(12);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font2);
        data_services->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        data_services->setObjectName(QString::fromUtf8("data_services"));
        data_services->setEnabled(true);
        data_services->setFont(font1);
        data_services->setFocusPolicy(Qt::NoFocus);
        data_services->setContextMenuPolicy(Qt::NoContextMenu);
        data_services->setLayoutDirection(Qt::LeftToRight);
        data_services->setAutoFillBackground(false);
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
        data_services->setSelectionMode(QAbstractItemView::NoSelection);
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        options = new QPushButton(centralWidget);
        options->setObjectName(QString::fromUtf8("options"));
        options->setFont(font);
        options->setCheckable(false);
        options->setAutoRepeat(false);
        options->setAutoExclusive(false);
        options->setAutoDefault(false);
        options->setFlat(false);

        horizontalLayout->addWidget(options);

        options_data_base = new QPushButton(centralWidget);
        options_data_base->setObjectName(QString::fromUtf8("options_data_base"));
        options_data_base->setFont(font);

        horizontalLayout->addWidget(options_data_base);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add_service_button = new QPushButton(centralWidget);
        add_service_button->setObjectName(QString::fromUtf8("add_service_button"));
        add_service_button->setFont(font);

        horizontalLayout->addWidget(add_service_button);

        change_service_button = new QPushButton(centralWidget);
        change_service_button->setObjectName(QString::fromUtf8("change_service_button"));
        change_service_button->setFont(font);

        horizontalLayout->addWidget(change_service_button);

        delete_service_button = new QPushButton(centralWidget);
        delete_service_button->setObjectName(QString::fromUtf8("delete_service_button"));
        delete_service_button->setFont(font);

        horizontalLayout->addWidget(delete_service_button);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        options->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SEFOLL", nullptr));
        give_order_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        show_order_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        show_data_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        QTableWidgetItem *___qtablewidgetitem = data_services->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\246\320\225\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = data_services->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\235\320\220\320\230\320\234\320\225\320\235\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        options->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        options_data_base->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        add_service_button->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\320\273\321\203\320\263\321\203", nullptr));
        change_service_button->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\203\321\201\320\273\321\203\320\263\321\203", nullptr));
        delete_service_button->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\321\201\320\273\321\203\320\263\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
