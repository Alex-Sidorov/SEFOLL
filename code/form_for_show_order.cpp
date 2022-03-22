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
const char* FormForShowOrder::LABEL_PHONE =               "Телефон:";
const char* FormForShowOrder::LABEL_DISCOUNT =            "Скидка %:";
const char* FormForShowOrder::LABEL_STATUS =              "Статус заказа:";
const char* FormForShowOrder::LABEL_STATUS_COMPLETE =     "Статус заказа: закончен.";
const char* FormForShowOrder::LABEL_STATUS_NOT_COMPLETE = "Статус заказа: не закончен.";


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

FormForShowOrder::FormForShowOrder(AbstractOrderRW* database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Order),
    m_database(database)
{
    ui->setupUi(this);
    connect(ui->delete_button,&QPushButton::clicked,this,&FormForShowOrder::slot_delete_order);

    setWindowIcon(QIcon(":icons/icon.png"));

    ui->delete_button->setVisible(false);
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
    ui->phone->setText(LABEL_PHONE);
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
    if(!m_database)
    {
        return;
    }

    int number_order = ui->number_order->value();

    auto order = m_database->read_order(number_order);
    if(order.get_number() != number_order)
    {
        QMessageBox::warning(this, tr(ERROR), tr(ERROR_FIND_ORDER));
    }
    else
    {
        clear_form();

        ui->number->setText(LABEL_NUMBER_ORDER +
                            QString::number(number_order));
        ui->client->setText(LABEL_CLIENT +
                            order.get_name_client());
        ui->phone->setText(LABEL_PHONE +
                            order.get_phone());
        ui->worker->setText(LABEL_WORKER +
                            order.get_name_worker());
        ui->date->setText(LABEL_DATE_ORDER +
                            order.get_date().text());
        ui->cost->setText(LABEL_COST +
                            QString::number(order.get_cost()));
        ui->discount->setText(LABEL_DISCOUNT +
                            QString::number(order.get_discount()));

        if(order.get_status())
        {
            ui->status->setText(LABEL_STATUS_COMPLETE);
        }
        else
        {
            ui->status->setText(LABEL_STATUS_NOT_COMPLETE);
            ui->complete_button->setEnabled(true);
        }

        auto records = order.get_services();

        QString cost;
        QString count;
        QString name;
        int count_row = 0;
        QTableWidgetItem *item_cost = nullptr;
        QTableWidgetItem *item_name = nullptr;
        QTableWidgetItem *item_count = nullptr;
        for(auto &record : records)
        {
            cost = QString::number(record.cost);
            count = QString::number(record.count);
            name = record.name_service;
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
    if(m_database)
    {
        if(!m_database->complete_order(ui->number_order->value()))
        {
            QMessageBox::warning(this,tr(ERROR),tr(ERROR_COMPLETE_ORDER));
        }
        else
        {
            ui->status->setText(LABEL_STATUS_COMPLETE);
            ui->complete_button->setEnabled(false);
        }
    }
}

void FormForShowOrder::slot_delete_order()
{
    if(request_for_delete() == QMessageBox::Ok && m_database)
    {
        m_database->delete_order_with_services(ui->number_order->value());
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
