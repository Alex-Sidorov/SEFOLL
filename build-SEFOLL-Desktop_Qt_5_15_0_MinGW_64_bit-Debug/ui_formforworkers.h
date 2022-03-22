/********************************************************************************
** Form generated from reading UI file 'formforworkers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFORWORKERS_H
#define UI_FORMFORWORKERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForWorkers
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *workers;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *name_worker;
    QPushButton *addWorkerButton;
    QPushButton *deleteWorkerButton;
    QPushButton *back_button;

    void setupUi(QWidget *FormForWorkers)
    {
        if (FormForWorkers->objectName().isEmpty())
            FormForWorkers->setObjectName(QString::fromUtf8("FormForWorkers"));
        FormForWorkers->resize(605, 382);
        verticalLayout = new QVBoxLayout(FormForWorkers);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        workers = new QTableWidget(FormForWorkers);
        if (workers->columnCount() < 1)
            workers->setColumnCount(1);
        QFont font;
        font.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        workers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        workers->setObjectName(QString::fromUtf8("workers"));
        workers->setFont(font);
        workers->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));
        workers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        workers->setTabKeyNavigation(false);
        workers->setProperty("showDropIndicator", QVariant(false));
        workers->setDragDropOverwriteMode(false);
        workers->setSelectionMode(QAbstractItemView::NoSelection);
        workers->horizontalHeader()->setCascadingSectionResizes(false);
        workers->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        workers->horizontalHeader()->setStretchLastSection(true);
        workers->verticalHeader()->setVisible(false);
        workers->verticalHeader()->setCascadingSectionResizes(false);
        workers->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(workers);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(FormForWorkers);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        name_worker = new QLineEdit(FormForWorkers);
        name_worker->setObjectName(QString::fromUtf8("name_worker"));
        name_worker->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout->addWidget(name_worker);

        addWorkerButton = new QPushButton(FormForWorkers);
        addWorkerButton->setObjectName(QString::fromUtf8("addWorkerButton"));
        addWorkerButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout->addWidget(addWorkerButton);

        deleteWorkerButton = new QPushButton(FormForWorkers);
        deleteWorkerButton->setObjectName(QString::fromUtf8("deleteWorkerButton"));
        deleteWorkerButton->setEnabled(false);
        deleteWorkerButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout->addWidget(deleteWorkerButton);

        back_button = new QPushButton(FormForWorkers);
        back_button->setObjectName(QString::fromUtf8("back_button"));
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

        horizontalLayout->addWidget(back_button);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FormForWorkers);

        QMetaObject::connectSlotsByName(FormForWorkers);
    } // setupUi

    void retranslateUi(QWidget *FormForWorkers)
    {
        FormForWorkers->setWindowTitle(QCoreApplication::translate("FormForWorkers", "SEFOLL", nullptr));
        QTableWidgetItem *___qtablewidgetitem = workers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FormForWorkers", "\320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("FormForWorkers", "\320\230\320\274\321\217 \320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
        addWorkerButton->setText(QCoreApplication::translate("FormForWorkers", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteWorkerButton->setText(QCoreApplication::translate("FormForWorkers", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        back_button->setText(QCoreApplication::translate("FormForWorkers", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForWorkers: public Ui_FormForWorkers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFORWORKERS_H
