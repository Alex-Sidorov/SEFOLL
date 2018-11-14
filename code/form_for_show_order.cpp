#include "form_for_show_order.h"
#include "ui_form_for_show_order.h"

FormForShowOrder::FormForShowOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Order)
{
    ui->setupUi(this);
}

void FormForShowOrder::on_back_button_clicked()
{
    clear_form();
    this->close();
    emit to_main_window();
}

void FormForShowOrder::clear_form()
{
    _order.clear();
    ui->number_order->clear();
    ui->client->setText(QString("Клиент:"));
    ui->worker->setText(QString("Исполнитель:"));
    ui->date->setText(QString("Дата принятия заказа:"));
    ui->cost->setText(QString("Сумма:"));
    ui->status->setText(QString("Статус заказа:"));
    ui->complete_button->setEnabled(false);
    while(ui->data_services->rowCount())
    {
        delete ui->data_services->item(0,0);//
        delete ui->data_services->item(0,1);//
        delete ui->data_services->item(0,2);//
        ui->data_services->removeRow(0);
    }
}


FormForShowOrder::~FormForShowOrder()
{
    delete ui;
}

void FormForShowOrder::on_number_order_valueChanged(int number)
{
    if(number!=0)
    {
        ui->enter_button->setEnabled(true);
    }
    else
    {
        ui->enter_button->setEnabled(false);
    }
}

void FormForShowOrder::on_enter_button_clicked()
{
    clear_form();
    _order = Order::find_order(ui->number_order->value());

    if(!_order.data())
    {
        QMessageBox::warning(this,tr("ОШИБКА"),
                             tr("Неудалось найти заказ. Проверьте номер заказа."));
    }
    else
    {
        ui->client->setText(QString("Клиент:")
                            +_order.data()->get_name_client());
        ui->worker->setText(QString("Исполнитель:")
                            +_order.data()->get_name_worker());
        ui->date->setText(QString("Дата принятия заказа:")
                            +_order.data()->get_date().text());
        ui->cost->setText(QString("Сумма:")
                            +QString::number(_order.data()->get_cost()));

        if(_order.data()->get_status())
        {
            ui->status->setText(QString("Статус заказа: закончен."));
        }
        else
        {
            ui->status->setText(QString("Статус заказа: не закончен."));
            ui->complete_button->setEnabled(true);
        }

        const QVector<Info_Of_Ordered_Service> &services = _order.data()->get_services();

        for(int i=0; i<services.size(); i++)
        {
            QTableWidgetItem *item_cost = new QTableWidgetItem(QString::number(services[i].cost));
            QTableWidgetItem *item_name = new QTableWidgetItem(services[i].name_service);
            QTableWidgetItem *item_count = new QTableWidgetItem(QString::number(services[i].count));

            ui->data_services->insertRow(ui->data_services->rowCount());
            ui->data_services->setItem(ui->data_services->rowCount()-1,0,item_count);
            ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_cost);
            ui->data_services->setItem(ui->data_services->rowCount()-1,2,item_name);
        }
    }
}

void FormForShowOrder::on_complete_button_clicked()
{
    if(!_order.data()->change_status_order())
    {
        QMessageBox::warning(this,tr("ОШИБКА"),
                             tr("В данный момент изменить состояние заказа не возможно."));
    }
    else
    {
        ui->status->setText(QString("Статус заказа: закончен."));
        ui->complete_button->setEnabled(false);
    }
}
