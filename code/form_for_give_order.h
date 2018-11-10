#ifndef FORM_FOR_GIVE_ORDER_H
#define FORM_FOR_GIVE_ORDER_H

#include "order.h"
#include "new_spinbox.h"

#include <QWidget>
#include <QSignalMapper>

namespace Ui {
class Form_For_Give_Order;
}

class Form_For_Give_Order : public QWidget
{
    Q_OBJECT

public:
    void set_table(const QTableWidget*);
    explicit Form_For_Give_Order(QWidget *parent = 0);
    ~Form_For_Give_Order();

signals:
    void to_main_window();

private slots:
    void on_back_button_clicked();
    void slot_change_box(int);
    void enabled_button()const;
    void on_enter_button_clicked();

private:
    Ui::Form_For_Give_Order *ui;
    QVector<New_SpinBox*> _boxs;
    QSignalMapper *_mapper;
    double _cost;

    void clear_form();

};

#endif // FORM_FOR_GIVE_ORDER_H
