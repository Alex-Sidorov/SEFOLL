#ifndef FORM_FOR_SHOW_DATA_H
#define FORM_FOR_SHOW_DATA_H

#include "order.h"

#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSharedPointer>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class Form_For_Show_Data;
}

class FormForShowData : public QWidget
{
    Q_OBJECT

public:
    explicit FormForShowData(const QTableWidget *services, QWidget *parent = 0);
    FormForShowData(const FormForShowData&) = delete;
    virtual ~FormForShowData(){}

signals:
    void to_main_window();

public slots:
    void show();

private slots:
    void on_back_button_clicked();
    void on_ok_button_clicked();
    void on_clear_button_clicked();
    void on_add_worker_button_clicked();
    void on_worker_list_doubleClicked(const QModelIndex &index);
    void on_is_number_clicked(bool checked);
    void on_is_worker_clicked(bool checked);
    void on_is_client_clicked(bool checked);
    void on_is_date_clicked(bool checked);
    void on_is_service_clicked(bool checked);
    void on_add_client_button_clicked();
    void on_client_list_doubleClicked(const QModelIndex &index);
    void on_add_service_button_clicked();
    void on_service_list_doubleClicked(const QModelIndex &index);

    void on_save_to_excel_button_clicked();

private:
    Ui::Form_For_Show_Data *ui;
    const QTableWidget *_services;

    static const char* REQUEST_TAKE_TABLE_ORDERS;
    static const char* REQUEST_TAKE_TABLE_SERVICES_ORDER;

    static const char* COLUMN_NUMBER;
    static const char* COLUMN_CLIENT;
    static const char* COLUMN_WORKER;
    static const char* COLUMN_DATE;
    static const char* COLUMN_COST;
    static const char* COLUMN_STATUS;
    static const char* COLUMN_DISCOUNT;

    static const char* COLUMN_PRICE_SERVICE;
    static const char* COLUMN_COUNT_SERVICES;
    static const char* COLUMN_NAME_SERVICE;

    static const char* COMPLETE_ORDER;
    static const char* NOT_COMPLETE_ORDER;

    static const char* CAPTION_TEXT;
    static const char* FORMAT_FILE;

    static const char* ERROR;
    static const char* ERROR_SAVE_FILE;

    static const char* COMPLETE;
    static const char* COMPLETE_SAVE;

    static const int INDEX_COLUMN_NUMBER;
    static const int INDEX_COLUMN_CLIENT;
    static const int INDEX_COLUMN_WORKER;
    static const int INDEX_COLUMN_DATE;
    static const int INDEX_COLUMN_COST;
    static const int INDEX_COLUMN_STATUS;
    static const int INDEX_COLUMN_DISCOUNT;
    static const int INDEX_COLUMN_SERVICES;

    static const int INDEX_COLUMN_COST_SERVICE;
    static const int INDEX_COLUMN_NAME_SERVICE;

    static const int INDEX_COLUMN_COUNT_SERVICES_TABLE;
    static const int INDEX_COLUMN_COST_SERVICES_TABLE;
    static const int INDEX_COLUMN_NAME_SERVICES_TABLE;

    static const int STATUS_NO_MATTER;
    static const int STATUS_WORKED;
    static const int STATUS_WORK;

    static const int CODE_NOT_FIND;

    void fill_service_box();

    bool is_need_order(QSqlQuery &query, QSqlRecord &record)const;

    bool check_date(QSqlQuery &query, QSqlRecord &record)const;
    bool check_worker(QSqlQuery &query, QSqlRecord &record)const;
    bool check_client(QSqlQuery &query, QSqlRecord &record)const;
    bool check_number(QSqlQuery &query, QSqlRecord &record)const;
    bool check_status(QSqlQuery &query, QSqlRecord &record)const;
    bool check_service(int)const;

    QTableWidget* create_service_table(int number);

    bool save_csv_file(const QString &file_name)const;
    void save_service_table(QTextStream &stream, int row)const;
};

#endif // FORM_FOR_SHOW_DATA_H
