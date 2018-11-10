#ifndef FORM_FOR_SHOW_ORDER_H
#define FORM_FOR_SHOW_ORDER_H

#include "order.h"

#include <QWidget>

namespace Ui {
class Form_For_Show_Order;
}

class Form_For_Show_Order : public QWidget
{
    Q_OBJECT

public:
    explicit Form_For_Show_Order(QWidget *parent = 0);
    ~Form_For_Show_Order();

signals:
    void to_main_window();

private slots:
    void on_back_button_clicked();
    void on_number_order_valueChanged(int number);
    void on_enter_button_clicked();
    void on_complete_button_clicked();

private:
    Ui::Form_For_Show_Order *ui;
    QSharedPointer<Order> _order;

    void clear_form();
};

#endif // FORM_FOR_SHOW_ORDER_H
