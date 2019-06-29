#ifndef FORM_FOR_SHOW_ORDER_H
#define FORM_FOR_SHOW_ORDER_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSharedPointer>

namespace Ui {
class Form_For_Show_Order;
}

class FormForShowOrder : public QWidget
{
    Q_OBJECT

public:
    explicit FormForShowOrder(QWidget *parent = 0);
    virtual ~FormForShowOrder(){}

signals:
    void to_main_window();

private slots:
    void slot_delete_order();
    void on_back_button_clicked();
    void on_number_order_valueChanged(int number);
    void on_enter_button_clicked();
    void on_complete_button_clicked();

private:
    QSharedPointer<Ui::Form_For_Show_Order> ui;

    static const char* ERROR;
    static const char* ERROR_FIND_ORDER;
    static const char* ERROR_COMPLETE_ORDER;
    static const char* ERROR_DELETE_ORDER;

    static const char* MESSAGE_REQUEST_FOR_DELETE;

    static const char* LABEL_NUMBER_ORDER;
    static const char* LABEL_CLIENT;
    static const char* LABEL_WORKER;
    static const char* LABEL_DATE_ORDER;
    static const char* LABEL_COST;
    static const char* LABEL_DISCOUNT;
    static const char* LABEL_STATUS;
    static const char* LABEL_STATUS_COMPLETE;
    static const char* LABEL_STATUS_NOT_COMPLETE;

    static const char* REQUEST_TAKE_ORDER;
    static const char* REQUEST_TAKE_TABLE_ORDERS;
    static const char* REQUEST_TAKE_TABLE_SERVICES_ORDER;
    static const char* REQUEST_COMPLETE_ORDER;
    static const char* REQUEST_DELETE_TABLE_SERVICE_ORDER;
    static const char* REQUEST_DELETE_ORDER;

    static const char* COLUMN_CLIENT;
    static const char* COLUMN_WORKER;
    static const char* COLUMN_DATE;
    static const char* COLUMN_COST;
    static const char* COLUMN_STATUS;
    static const char* COLUMN_SERVICES;
    static const char* COLUMN_PRICE_SERVICE;
    static const char* COLUMN_COUNT_SERVICES;
    static const char* COLUMN_NAME_SERVICE;
    static const char* COLUMN_DISCOUNT;

    static const int INDEX_COLUMN_COUNT;
    static const int INDEX_COLUMN_COST;
    static const int INDEX_COLUMN_NAME;

    void clear_form();
    bool delete_row_order(int number_order);
    bool delete_table_order(int number_order);
    int request_for_delete()const;
};

#endif // FORM_FOR_SHOW_ORDER_H
