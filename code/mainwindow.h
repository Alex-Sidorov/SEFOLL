#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "form_for_add_service.h"
#include "form_for_give_order.h"
#include "form_for_delete_service.h"
#include "form_for_change_service.h"
#include "form_for_show_order.h"

#include <QMainWindow>
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
    explicit MainWindow(QWidget *parent = 0);
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

private:
    Ui::MainWindow *ui;

    QString _name_file_data;
    QSqlDatabase data;

    FormForGiveOrder *window_for_give_order;
    FormForChangeService *window_for_change_service;
    FormForAddService *window_for_add_service;
    FormForDeleteService *window_for_delete_service;
    FormForShowOrder *window_for_show_order;

    void write_file_data();
    void read_file_data();
};

#endif // MAINWINDOW_H
