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
    ui->number->setText(QString("Номер:"));
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

    QSqlQuery query("SELECT * FROM orders;");
    if(!query.isActive())
    {
        return;
    }
    int number_order = ui->number_order->value();
    if(!query.seek(number_order - 1))
    {
        QMessageBox::warning(this,tr("ОШИБКА"),
                             tr("Неудалось найти заказ. Проверьте номер заказа."));
    }
    else
    {
        QSqlRecord record = query.record();
        ui->number->setText(QString("Номер:")+
                            QString::number(number_order));
        ui->client->setText(QString("Клиент:") +
                            query.value(record.indexOf("client")).toString());
        ui->worker->setText(QString("Исполнитель:") +
                            query.value(record.indexOf("worker")).toString());
        ui->date->setText(QString("Дата принятия заказа:") +
                            query.value(record.indexOf("date")).toString());
        ui->cost->setText(QString("Сумма:") +
                            query.value(record.indexOf("cost")).toString());

        if(query.value(record.indexOf("status")).toBool())
        {
            ui->status->setText(QString("Статус заказа: закончен."));
        }
        else
        {
            ui->status->setText(QString("Статус заказа: не закончен."));
            ui->complete_button->setEnabled(true);
        }

        QString request = "SELECT * FROM _%1_;";
        request = request.arg(query.value(record.indexOf("services")).toInt());
        if(!query.exec(request))
        {
            clear_form();
            return;
        }

        QString cost;
        QString count;
        QString name;
        while(query.next())
        {
            record = query.record();
            cost = query.value(record.indexOf("price")).toString();
            count = query.value(record.indexOf("count")).toString();
            name = query.value(record.indexOf("name")).toString();
            QTableWidgetItem *item_cost = new QTableWidgetItem(cost);
            QTableWidgetItem *item_name = new QTableWidgetItem(name);
            QTableWidgetItem *item_count = new QTableWidgetItem(count);

            ui->data_services->insertRow(ui->data_services->rowCount());
            ui->data_services->setItem(ui->data_services->rowCount()-1,0,item_count);
            ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_cost);
            ui->data_services->setItem(ui->data_services->rowCount()-1,2,item_name);
        }
    }
}

void FormForShowOrder::on_complete_button_clicked()
{
    QString request = "UPDATE orders SET status = 1 WHERE number = %1;";
    QString number = ui->number->text();
    request = request.arg(number.mid(number.indexOf(':')+1).toInt());
    QSqlQuery query(request);
    if(!query.exec())
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
