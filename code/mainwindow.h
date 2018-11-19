#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "form_for_add_service.h"
#include "form_for_give_order.h"
#include "form_for_delete_service.h"
#include "form_for_change_service.h"
#include "form_for_show_order.h"
#include "form_for_options.h"
#include "form_for_show_data.h"
#include "security.h"

#include <QMainWindow>
#include <QSharedPointer>
#include <QTableWidgetItem>
#include <QDoubleSpinBox>
#include <QFile>
#include <QDataStream>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlrecord.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void set_access(Access access);
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(const MainWindow&) = delete;
    ~MainWindow();

private slots:
    void on_give_order_button_clicked();
    void on_add_service_button_clicked();
    void on_change_service_button_clicked();
    void on_delete_service_button_clicked();
    void show_main_window();
    void add_service();
    void upload_table(int index);
    void upload_table(const QVector<int>&);
    void on_show_order_button_clicked();
    void on_options_clicked();

private:
    QSharedPointer<Ui::MainWindow> ui;

    QSharedPointer<FormForGiveOrder> window_for_give_order;
    QSharedPointer<FormForChangeService> window_for_change_service;
    QSharedPointer<FormForAddService> window_for_add_service;
    QSharedPointer<FormForDeleteService> window_for_delete_service;
    QSharedPointer<FormForShowOrder> window_for_show_order;
    QSharedPointer<FormForOptions> window_for_options;

    Access _access;
    QString _name_file_data;
    QSqlDatabase data;

    static const char* ERROR;
    static const char* ERROR_ACCESS;
    static const char* ERROR_ADD_SERVICE;
    static const char* ERROR_CHANGE_SERVICE;
    static const char* ERROR_OPEN_DATA_BASE;

    static const char* NAME_DATA_BASE;
    static const char* TYPE_DATA_BASE;

    static const char* REQUESTE_DATA_SERVICE;
    static const char* REQUESTE_TAKE_SERVICES;
    static const char* REQUESTE_UPDATE_NAME;
    static const char* REQUESTE_UPDATE_PRICE;
    static const char* REQUESTE_DELETE_SERVICE;

    static const char* COLUMN_PRICE;
    static const char* COLUMN_NAME;

    static const int INDEX_COLUMN_COST;
    static const int INDEX_COLUMN_NAME;

    void read_file_data();
};

#endif // MAINWINDOW_H
