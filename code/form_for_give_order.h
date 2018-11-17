#ifndef FORM_FOR_GIVE_ORDER_H
#define FORM_FOR_GIVE_ORDER_H

#include "order.h"
#include "new_spinbox.h"

#include <QWidget>
#include <QSignalMapper>
#include <QSqlQuery>
#include <QSqlRecord>

namespace Ui {
class Form_For_Give_Order;
}

class FormForGiveOrder : public QWidget
{
    Q_OBJECT

public:
    void set_table(const QTableWidget*);
    explicit FormForGiveOrder(QWidget *parent = 0);
    ~FormForGiveOrder();

signals:
    void to_main_window();

private slots:
    void on_back_button_clicked();
    void slot_change_box(int);
    void enabled_button()const;
    void on_enter_button_clicked();

private:
    Ui::Form_For_Give_Order *ui;
    QVector<NewSpinBox*> _boxs;
    QSignalMapper *_mapper;
    double _cost;

    bool add_order(Order &order);
    void clear_form();
    bool check_input_fields()const;

    static const int INDEX_COLUMN_COST;
    static const int INDEX_COLUMN_NAME;
    static const int INDEX_COLUMN_COUNT;
    static const int INDEX_FIRST_ROW;
    static const int OFFSET_INDEX;

    static const char *COST_LABEL;
    static const char *REQUEST_TAKE_TABLE_ORDERS;
    static const char *REQUEST_INSERT_ORDERS;
    static const char *REQUEST_CREATE_TABLE_ORDER;
    static const char *REQUEST_INSERT_SERVICE_ORDER;
    static const char *ERROR_MESSAGE;
    static const char *ERROR;
    static const char* REGISTRATION;
    static const char* MESSAGE_NUMBER_ORDER;
};

#endif // FORM_FOR_GIVE_ORDER_H
