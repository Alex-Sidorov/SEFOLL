/********************************************************************************
** Form generated from reading UI file 'form_for_show_data.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_FOR_SHOW_DATA_H
#define UI_FORM_FOR_SHOW_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_For_Show_Data
{
public:
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *data;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *is_number;
    QLabel *label_5;
    QSpinBox *number_order;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *is_worker;
    QLabel *label_3;
    QListWidget *worker_list;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *names_workers;
    QPushButton *add_worker_button;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *is_client;
    QLabel *label_4;
    QListWidget *client_list;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *client_line;
    QPushButton *add_client_button;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *is_date;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *before_date;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *after_date;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *is_service;
    QLabel *label_6;
    QListWidget *service_list;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *service_box;
    QPushButton *add_service_button;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_7;
    QComboBox *status_box;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ok_button;
    QPushButton *clear_button;
    QPushButton *back_button;
    QPushButton *save_to_excel_button;

    void setupUi(QWidget *Form_For_Show_Data)
    {
        if (Form_For_Show_Data->objectName().isEmpty())
            Form_For_Show_Data->setObjectName(QString::fromUtf8("Form_For_Show_Data"));
        Form_For_Show_Data->resize(668, 417);
        horizontalLayout_5 = new QHBoxLayout(Form_For_Show_Data);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        data = new QTableWidget(Form_For_Show_Data);
        if (data->columnCount() < 8)
            data->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        data->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        data->setObjectName(QString::fromUtf8("data"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(30);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(data->sizePolicy().hasHeightForWidth());
        data->setSizePolicy(sizePolicy);
        data->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);"));
        data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        data->setDragDropOverwriteMode(false);
        data->setSortingEnabled(false);
        data->setWordWrap(false);
        data->setCornerButtonEnabled(false);
        data->horizontalHeader()->setVisible(true);
        data->horizontalHeader()->setCascadingSectionResizes(false);
        data->horizontalHeader()->setStretchLastSection(false);
        data->verticalHeader()->setCascadingSectionResizes(true);

        horizontalLayout_5->addWidget(data);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        scrollArea = new QScrollArea(Form_For_Show_Data);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 723));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        is_number = new QCheckBox(scrollAreaWidgetContents);
        is_number->setObjectName(QString::fromUtf8("is_number"));

        horizontalLayout_11->addWidget(is_number);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_5);


        verticalLayout_6->addLayout(horizontalLayout_11);

        number_order = new QSpinBox(scrollAreaWidgetContents);
        number_order->setObjectName(QString::fromUtf8("number_order"));
        number_order->setEnabled(false);
        number_order->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"\n"
""));

        verticalLayout_6->addWidget(number_order);


        verticalLayout->addLayout(verticalLayout_6);

        line_4 = new QFrame(scrollAreaWidgetContents);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        is_worker = new QCheckBox(scrollAreaWidgetContents);
        is_worker->setObjectName(QString::fromUtf8("is_worker"));
        is_worker->setCheckable(true);

        horizontalLayout_7->addWidget(is_worker);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(200, 0));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_7);

        worker_list = new QListWidget(scrollAreaWidgetContents);
        worker_list->setObjectName(QString::fromUtf8("worker_list"));
        worker_list->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:50;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        verticalLayout_2->addWidget(worker_list);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        names_workers = new QComboBox(scrollAreaWidgetContents);
        names_workers->setObjectName(QString::fromUtf8("names_workers"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(names_workers->sizePolicy().hasHeightForWidth());
        names_workers->setSizePolicy(sizePolicy3);
        names_workers->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"height:20;\n"
"border-color: rgb(11, 11, 11);\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout_4->addWidget(names_workers);

        add_worker_button = new QPushButton(scrollAreaWidgetContents);
        add_worker_button->setObjectName(QString::fromUtf8("add_worker_button"));
        add_worker_button->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(add_worker_button->sizePolicy().hasHeightForWidth());
        add_worker_button->setSizePolicy(sizePolicy4);
        add_worker_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:70;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_4->addWidget(add_worker_button);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        is_client = new QCheckBox(scrollAreaWidgetContents);
        is_client->setObjectName(QString::fromUtf8("is_client"));

        horizontalLayout_10->addWidget(is_client);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_4);


        verticalLayout_3->addLayout(horizontalLayout_10);

        client_list = new QListWidget(scrollAreaWidgetContents);
        client_list->setObjectName(QString::fromUtf8("client_list"));
        client_list->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:50;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);"));

        verticalLayout_3->addWidget(client_list);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        client_line = new QLineEdit(scrollAreaWidgetContents);
        client_line->setObjectName(QString::fromUtf8("client_line"));
        client_line->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout_6->addWidget(client_line);

        add_client_button = new QPushButton(scrollAreaWidgetContents);
        add_client_button->setObjectName(QString::fromUtf8("add_client_button"));
        add_client_button->setEnabled(false);
        add_client_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:70;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_6->addWidget(add_client_button);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(verticalLayout_3);

        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        is_date = new QCheckBox(scrollAreaWidgetContents);
        is_date->setObjectName(QString::fromUtf8("is_date"));

        verticalLayout_5->addWidget(is_date);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        before_date = new QDateEdit(scrollAreaWidgetContents);
        before_date->setObjectName(QString::fromUtf8("before_date"));
        before_date->setEnabled(false);
        before_date->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout->addWidget(before_date);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        after_date = new QDateEdit(scrollAreaWidgetContents);
        after_date->setObjectName(QString::fromUtf8("after_date"));
        after_date->setEnabled(false);
        after_date->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:140;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout_2->addWidget(after_date);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_5);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        is_service = new QCheckBox(scrollAreaWidgetContents);
        is_service->setObjectName(QString::fromUtf8("is_service"));

        horizontalLayout_12->addWidget(is_service);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_6);


        verticalLayout_7->addLayout(horizontalLayout_12);

        service_list = new QListWidget(scrollAreaWidgetContents);
        service_list->setObjectName(QString::fromUtf8("service_list"));
        service_list->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:50;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        verticalLayout_7->addWidget(service_list);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        service_box = new QComboBox(scrollAreaWidgetContents);
        service_box->setObjectName(QString::fromUtf8("service_box"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(20);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(service_box->sizePolicy().hasHeightForWidth());
        service_box->setSizePolicy(sizePolicy5);
        service_box->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        horizontalLayout_13->addWidget(service_box);

        add_service_button = new QPushButton(scrollAreaWidgetContents);
        add_service_button->setObjectName(QString::fromUtf8("add_service_button"));
        add_service_button->setEnabled(false);
        add_service_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:70;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_13->addWidget(add_service_button);


        verticalLayout_7->addLayout(horizontalLayout_13);


        verticalLayout->addLayout(verticalLayout_7);

        line_5 = new QFrame(scrollAreaWidgetContents);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(230);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy6);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_7);

        status_box = new QComboBox(scrollAreaWidgetContents);
        status_box->addItem(QString());
        status_box->addItem(QString());
        status_box->addItem(QString());
        status_box->setObjectName(QString::fromUtf8("status_box"));
        status_box->setStyleSheet(QString::fromUtf8("\n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:100;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
""));

        verticalLayout_9->addWidget(status_box);


        verticalLayout->addLayout(verticalLayout_9);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_8->addWidget(scrollArea);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ok_button = new QPushButton(Form_For_Show_Data);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:70;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_3->addWidget(ok_button);

        clear_button = new QPushButton(Form_For_Show_Data);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:70;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_3->addWidget(clear_button);

        back_button = new QPushButton(Form_For_Show_Data);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{ \n"
"border-radius : 4px;\n"
"border: 1px solid;\n"
"border-color: rgb(11, 11, 11);\n"
"height:20;\n"
"width:70;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton::pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(251, 252, 255), stop: 1 #f6f7fa);\n"
"}"));

        horizontalLayout_3->addWidget(back_button);


        verticalLayout_8->addLayout(horizontalLayout_3);

        save_to_excel_button = new QPushButton(Form_For_Show_Data);
        save_to_excel_button->setObjectName(QString::fromUtf8("save_to_excel_button"));
        save_to_excel_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout_8->addWidget(save_to_excel_button);


        horizontalLayout_5->addLayout(verticalLayout_8);


        retranslateUi(Form_For_Show_Data);

        QMetaObject::connectSlotsByName(Form_For_Show_Data);
    } // setupUi

    void retranslateUi(QWidget *Form_For_Show_Data)
    {
        Form_For_Show_Data->setWindowTitle(QCoreApplication::translate("Form_For_Show_Data", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = data->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = data->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = data->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = data->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = data->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = data->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\241\320\272\320\270\320\264\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = data->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = data->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\243\321\201\320\273\321\203\320\263\320\270", nullptr));
        is_number->setText(QString());
        label_5->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267", nullptr));
        is_worker->setText(QString());
        label_3->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\230\320\274\320\265\320\275\320\260 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        add_worker_button->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        is_client->setText(QString());
        label_4->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\230\320\274\320\265\320\275\320\260 \320\272\320\273\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        add_client_button->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        is_date->setText(QString());
        label->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\236\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\224\320\276", nullptr));
        is_service->setText(QString());
        label_6->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\243\321\201\320\273\321\203\320\263\320\270", nullptr));
        add_service_button->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        status_box->setItemText(0, QCoreApplication::translate("Form_For_Show_Data", "\320\235\320\265 \320\262\320\260\320\266\320\275\320\276", nullptr));
        status_box->setItemText(1, QCoreApplication::translate("Form_For_Show_Data", "\320\222\321\213\320\277\320\276\320\273\320\275\320\265\320\275", nullptr));
        status_box->setItemText(2, QCoreApplication::translate("Form_For_Show_Data", "\320\222\321\213\320\277\320\276\320\273\320\275\321\217\320\265\321\202\321\201\321\217", nullptr));

        ok_button->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\236\320\272", nullptr));
        clear_button->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        back_button->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        save_to_excel_button->setText(QCoreApplication::translate("Form_For_Show_Data", "\320\222\321\213\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\262 Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_For_Show_Data: public Ui_Form_For_Show_Data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_FOR_SHOW_DATA_H
