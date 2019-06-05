#ifndef FORM_FOR_SHOW_DATA_H
#define FORM_FOR_SHOW_DATA_H

#include "order.h"

#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSharedPointer>

namespace Ui {
class Form_For_Show_Data;
}

class FormForShowData : public QWidget
{
    Q_OBJECT

public:
    explicit FormForShowData(QWidget *parent = 0);
    FormForShowData(const FormForShowData&) = delete;
    virtual ~FormForShowData(){}

signals:
    void to_main_window();

private slots:
    void on_back_button_clicked();
    void on_ok_button_clicked();
    void on_clear_button_clicked();
    void on_add_worker_button_clicked();
    void on_worker_list_doubleClicked(const QModelIndex &index);

private:
    QSharedPointer<Ui::Form_For_Show_Data> ui;

    static const char* REQUEST_TAKE_TABLE_ORDERS;

    static const char* COLUMN_CLIENT;
    static const char* COLUMN_WORKER;
    static const char* COLUMN_DATE;
    static const char* COLUMN_COST;
    static const char* COLUMN_STATUS;
    static const char* COLUMN_DISCOUNT;

    static const char* COMPLETE_ORDER;
    static const char* NOT_COMPLETE_ORDER;

    static const int INDEX_COLUMN_CLIENT;
    static const int INDEX_COLUMN_WORKER;
    static const int INDEX_COLUMN_DATE;
    static const int INDEX_COLUMN_COST;
    static const int INDEX_COLUMN_STATUS;
    static const int INDEX_COLUMN_DISCOUNT;

    static const int CODE_NOT_FIND;

    bool is_need_order(QSqlQuery &query, QSqlRecord &record)const;
};

#endif // FORM_FOR_SHOW_DATA_H
