#include "form_for_show_order.h"
#include "ui_form_for_show_order.h"

const char* FormForShowOrder::ERROR =                "ОШИБКА";
const char* FormForShowOrder::ERROR_FIND_ORDER =
        "Неудалось найти заказ. Проверьте номер заказа.";
const char* FormForShowOrder::ERROR_COMPLETE_ORDER =
        "В данный момент изменить состояние заказа не возможно.";
const char* FormForShowOrder::ERROR_DELETE_ORDER =
        "В данный момент удалить заказ не возможно.";

const char* FormForShowOrder::MESSAGE_REQUEST_FOR_DELETE =
        "Вы уверены, что хотите удалить выбранные элементы?";

const char* FormForShowOrder::LABEL_NUMBER_ORDER =        "Номер:";
const char* FormForShowOrder::LABEL_CLIENT =              "Клиент:";
const char* FormForShowOrder::LABEL_WORKER =              "Исполнитель:";
const char* FormForShowOrder::LABEL_DATE_ORDER =          "Дата принятия заказа:";
const char* FormForShowOrder::LABEL_COST =                "Сумма:";
const char* FormForShowOrder::LABEL_DISCOUNT =            "Скидка %:";
const char* FormForShowOrder::LABEL_STATUS =              "Статус заказа:";
const char* FormForShowOrder::LABEL_STATUS_COMPLETE =     "Статус заказа: закончен.";
const char* FormForShowOrder::LABEL_STATUS_NOT_COMPLETE = "Статус заказа: не закончен.";

const char* FormForShowOrder::REQUEST_TAKE_ORDER =                "SELECT * FROM orders WHERE number = %1;";
const char* FormForShowOrder::REQUEST_TAKE_TABLE_ORDERS =         "SELECT * FROM orders;";
const char* FormForShowOrder::REQUEST_TAKE_TABLE_SERVICES_ORDER = "SELECT * FROM _%1_;";
const char* FormForShowOrder::REQUEST_COMPLETE_ORDER =            "UPDATE orders SET status = 1 WHERE number = %1;";
const char* FormForShowOrder::REQUEST_DELETE_ORDER =              "DELETE FROM orders WHERE number = %1;";
const char* FormForShowOrder::REQUEST_DELETE_TABLE_SERVICE_ORDER ="DROP TABLE _%1_;";


const char* FormForShowOrder::COLUMN_CLIENT =         "client";
const char* FormForShowOrder::COLUMN_WORKER =         "worker";
const char* FormForShowOrder::COLUMN_DATE =           "date";
const char* FormForShowOrder::COLUMN_COST =           "cost";
const char* FormForShowOrder::COLUMN_DISCOUNT =       "discount";
const char* FormForShowOrder::COLUMN_STATUS =         "status";
const char* FormForShowOrder::COLUMN_SERVICES =       "services";
const char* FormForShowOrder::COLUMN_PRICE_SERVICE =  "price";
const char* FormForShowOrder::COLUMN_COUNT_SERVICES = "count";
const char* FormForShowOrder::COLUMN_NAME_SERVICE =   "name";

const int FormForShowOrder::INDEX_COLUMN_COUNT = 0;
const int FormForShowOrder::INDEX_COLUMN_COST =  1;
const int FormForShowOrder::INDEX_COLUMN_NAME =  2;

FormForShowOrder::FormForShowOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Order)
{
    ui->setupUi(this);
    connect(ui->delete_button,&QPushButton::clicked,this,&FormForShowOrder::slot_delete_order);
}

void FormForShowOrder::on_back_button_clicked()
{
    clear_form();
    this->close();
    emit to_main_window();
}

void FormForShowOrder::clear_form()
{
    ui->number_order->clear();
    ui->number->setText(LABEL_NUMBER_ORDER);
    ui->client->setText(LABEL_CLIENT);
    ui->worker->setText(LABEL_WORKER);
    ui->date->setText(LABEL_DATE_ORDER);
    ui->cost->setText(LABEL_COST);
    ui->status->setText(LABEL_STATUS);
    ui->discount->setText(LABEL_DISCOUNT);
    ui->complete_button->setEnabled(false);
    ui->data_services->setRowCount(0);
}

void FormForShowOrder::on_number_order_valueChanged(int number)
{
    if(number != 0)
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
    int number_order = ui->number_order->value();

    QSqlQuery query;
    QString request = REQUEST_TAKE_ORDER;
    request = request.arg(number_order);
    if(!query.exec(request) || !query.next())
    {
        QMessageBox::warning(this, tr(ERROR), tr(ERROR_FIND_ORDER));
    }
    else
    {
        clear_form();

        QSqlRecord record = query.record();
        ui->number->setText(LABEL_NUMBER_ORDER +
                            QString::number(number_order));
        ui->client->setText(LABEL_CLIENT +
                            query.value(record.indexOf(COLUMN_CLIENT)).toString());
        ui->worker->setText(LABEL_WORKER +
                            query.value(record.indexOf(COLUMN_WORKER)).toString());
        ui->date->setText(LABEL_DATE_ORDER +
                            query.value(record.indexOf(COLUMN_DATE)).toString());
        ui->cost->setText(LABEL_COST +
                            query.value(record.indexOf(COLUMN_COST)).toString());
        ui->discount->setText(LABEL_DISCOUNT +
                            query.value(record.indexOf(COLUMN_DISCOUNT)).toString());

        if(query.value(record.indexOf(COLUMN_STATUS)).toBool())
        {
            ui->status->setText(LABEL_STATUS_COMPLETE);
        }
        else
        {
            ui->status->setText(LABEL_STATUS_NOT_COMPLETE);
            ui->complete_button->setEnabled(true);
        }

        request = REQUEST_TAKE_TABLE_SERVICES_ORDER;
        request = request.arg(query.value(record.indexOf(COLUMN_SERVICES)).toInt());
        if(!query.exec(request))
        {
            clear_form();
            QMessageBox::warning(this, tr(ERROR), tr(ERROR_FIND_ORDER));
            return;
        }

        QString cost;
        QString count;
        QString name;
        int count_row = 0;
        QTableWidgetItem *item_cost = nullptr;
        QTableWidgetItem *item_name = nullptr;
        QTableWidgetItem *item_count = nullptr;
        while(query.next())
        {
            record = query.record();
            cost = query.value(record.indexOf(COLUMN_PRICE_SERVICE)).toString();
            count = query.value(record.indexOf(COLUMN_COUNT_SERVICES)).toString();
            name = query.value(record.indexOf(COLUMN_NAME_SERVICE)).toString();
            item_cost = new QTableWidgetItem(cost);
            item_name = new QTableWidgetItem(name);
            item_count = new QTableWidgetItem(count);

            count_row = ui->data_services->rowCount();
            ui->data_services->insertRow(count_row);
            ui->data_services->setItem(count_row,INDEX_COLUMN_COUNT,item_count);
            ui->data_services->setItem(count_row,INDEX_COLUMN_COST,item_cost);
            ui->data_services->setItem(count_row,INDEX_COLUMN_NAME,item_name);
        }
    }
    ui->delete_button->setEnabled(true);
}

void FormForShowOrder::on_complete_button_clicked()
{
    QString request = REQUEST_COMPLETE_ORDER;
    QString number = ui->number->text();
    request = request.arg(number.mid(number.indexOf(':') + 1).toInt());
    QSqlQuery query(request);
    if(!query.exec())
    {
        QMessageBox::warning(this,tr(ERROR),tr(ERROR_COMPLETE_ORDER));
    }
    else
    {
        ui->status->setText(LABEL_STATUS_COMPLETE);
        ui->complete_button->setEnabled(false);
    }
}

bool FormForShowOrder::delete_row_order(int number_order)
{
    QString request;
    QSqlQuery query;

    request = REQUEST_DELETE_ORDER;
    request = request.arg(number_order);

    if(!query.exec(request))
    {
        QMessageBox::warning(this,ERROR,ERROR_DELETE_ORDER);
        return false;
    }
    return true;
}

bool FormForShowOrder::delete_table_order(int number_order)
{
    QString request;
    QSqlQuery query;

    request = REQUEST_DELETE_TABLE_SERVICE_ORDER;
    request = request.arg(number_order);

    if(!query.exec(request))
    {
        QMessageBox::warning(this,ERROR,ERROR_DELETE_ORDER);
        return false;
    }
    return true;
}

void FormForShowOrder::slot_delete_order()
{
    int number_order = ui->number_order->value();
    if(request_for_delete() == QMessageBox::Ok && delete_row_order(number_order))
    {
        delete_table_order(number_order);
        clear_form();
    }
}

int FormForShowOrder::request_for_delete()const
{
    QMessageBox message;
    message.setText(MESSAGE_REQUEST_FOR_DELETE);
    message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    return message.exec();
}
