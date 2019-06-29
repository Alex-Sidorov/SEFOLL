#ifndef FORM_FOR_GIVE_ORDER_H
#define FORM_FOR_GIVE_ORDER_H

#include "order.h"
#include "new_spinbox.h"

#include <QWidget>
#include <QSignalMapper>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSharedPointer>
#include <QMessageBox>

namespace Ui {
class FormForGiveOrder;
}

class FormForGiveOrder : public QWidget
{
    Q_OBJECT

public:
    void set_table(const QTableWidget*);
    explicit FormForGiveOrder(QWidget *parent = 0);
    FormForGiveOrder(const FormForGiveOrder&) = delete;
    virtual ~FormForGiveOrder(){}

signals:
    void to_main_window();

private slots:
    void on_back_button_clicked();
    void slot_change_box(int);
    void enabled_button()const;
    void on_enter_button_clicked();
    void slot_change_discount(int);

private:
    QSharedPointer<Ui::FormForGiveOrder> ui;
    QVector< QSharedPointer<NewSpinBox> > _boxs;
    QSharedPointer<QSignalMapper> _mapper;
    double _cost;

    static const int INDEX_COLUMN_COST;
    static const int INDEX_COLUMN_NAME;
    static const int INDEX_COLUMN_COUNT;
    static const int INDEX_FIRST_ROW;
    static const int OFFSET_INDEX;
    static const int FULL_PRICE;

    static const char *COLUMN_NUMBER;
    static const char *COST_LABEL;
    static const char *REQUEST_TAKE_TABLE_ORDERS;
    static const char *REQUEST_INSERT_ORDERS;
    static const char *REQUEST_CREATE_TABLE_ORDER;
    static const char *REQUEST_INSERT_SERVICE_ORDER;
    static const char *ERROR_MESSAGE;
    static const char *ERROR;
    static const char *REGISTRATION;
    static const char *MESSAGE_NUMBER_ORDER;

    bool add_order(Order &order);
    void clear_form();
    bool check_input_fields()const;
    double get_cost_with_discount(double cost, int discont)const;
};

#endif // FORM_FOR_GIVE_ORDER_H
