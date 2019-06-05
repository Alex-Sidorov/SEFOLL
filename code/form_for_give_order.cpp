#include "form_for_give_order.h"
#include "ui_form_for_give_order.h"

const int FormForGiveOrder::INDEX_COLUMN_COST =  0;
const int FormForGiveOrder::INDEX_COLUMN_NAME =  1;
const int FormForGiveOrder::INDEX_COLUMN_COUNT = 0;
const int FormForGiveOrder::INDEX_FIRST_ROW =    0;

const int FormForGiveOrder::FULL_PRICE =         100;

const int FormForGiveOrder::OFFSET_INDEX = 1;

const char* FormForGiveOrder::COST_LABEL = "Сумма:";

const char* FormForGiveOrder::REQUEST_TAKE_TABLE_ORDERS = "SELECT * FROM orders;";
const char* FormForGiveOrder::REQUEST_INSERT_ORDERS =
        "INSERT INTO orders(number, client, worker, date, status, cost, services, discount)"
        " VALUES(%1, '%2', '%3', '%4', %5, %6, %7, %8);";
const char* FormForGiveOrder::REQUEST_CREATE_TABLE_ORDER =
        "CREATE TABLE _%1_ (price NOT NULL, count NOT NULL, name TEXT);";
const char* FormForGiveOrder::REQUEST_INSERT_SERVICE_ORDER =
        "INSERT INTO _%1_(price, count, name)  VALUES(%2, %3, '%4');";

const char* FormForGiveOrder::ERROR_MESSAGE =
        "Не удалось зарегистрировать заказ. Попробуйте позже.";
const char* FormForGiveOrder::ERROR = "ОШИБКА";

const char* FormForGiveOrder::REGISTRATION = "Регистрация";
const char* FormForGiveOrder::MESSAGE_NUMBER_ORDER = "Заказ оформлен.\n Номер:";

FormForGiveOrder::FormForGiveOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForGiveOrder),
    _mapper(new QSignalMapper)
{
    ui->setupUi(this);
    connect(ui->name_client,SIGNAL(textChanged(QString)),SLOT(enabled_button()));
    connect(ui->name_worker,SIGNAL(textChanged(QString)),SLOT(enabled_button()));
    connect(ui->discount,SIGNAL(valueChanged(int)),SLOT(slot_change_discount(int)));

    ui->date->setDate(QDate::currentDate());
    _cost = 0;
}

void FormForGiveOrder::set_table(const QTableWidget* table)
{
    int count_row_table = table->rowCount();
    _boxs.reserve(count_row_table);
    int count_row_data_services = 0;
    QTableWidgetItem *item_cost = nullptr;
    QTableWidgetItem *item_name = nullptr;
    for(int i = 0; i < count_row_table; i++)
    {
        item_cost = new QTableWidgetItem(*(table->item(i,INDEX_COLUMN_COST)));
        item_name = new QTableWidgetItem(*(table->item(i,INDEX_COLUMN_NAME)));

        count_row_data_services = ui->data_services->rowCount();
        ui->data_services->insertRow(count_row_data_services);
        ui->data_services->setItem(count_row_data_services,INDEX_COLUMN_COST+OFFSET_INDEX,item_cost);
        ui->data_services->setItem(count_row_data_services,INDEX_COLUMN_NAME+OFFSET_INDEX,item_name);

        QSharedPointer<NewSpinBox> new_box(new NewSpinBox);
        _boxs.push_back(new_box);

        connect(new_box.data(),SIGNAL(valueChanged(int)),_mapper.data(),SLOT(map()));
        _mapper->setMapping(new_box.data(),i);

        ui->data_services->setCellWidget(count_row_data_services,INDEX_COLUMN_COUNT,new_box.data());
    }
    connect(_mapper.data(),SIGNAL(mapped(int)),SLOT(slot_change_box(int)));
}

void FormForGiveOrder::clear_form()
{
    _cost = 0;
    ui->cost->setText(QString(COST_LABEL) + '0');
    ui->name_client->clear();
    ui->name_worker->clear();
    ui->date->setDate(QDate::currentDate());
    ui->data_services->setRowCount(0);
    _boxs.clear();
}

void FormForGiveOrder::on_back_button_clicked()
{
    clear_form();
    this->close();
    emit to_main_window();
}

bool FormForGiveOrder::check_input_fields()const
{
    return _cost != 0 &&
            !ui->name_client->text().isEmpty() &&
            !ui->name_worker->text().isEmpty();
}

void FormForGiveOrder::enabled_button()const
{
    if(check_input_fields())
    {
        ui->enter_button->setEnabled(true);
    }
    else
    {
        ui->enter_button->setEnabled(false);
    }
}

double FormForGiveOrder::get_cost_with_discount(double cost, int discont)const
{
    return (cost * (FULL_PRICE - discont))/FULL_PRICE;
}

void FormForGiveOrder::slot_change_box(int row)
{
    double cost_service = ui->
           data_services->
           item(row,INDEX_COLUMN_COST + OFFSET_INDEX)->
           text().replace(QChar(','),QChar('.')).toDouble();

    _cost-=(_boxs[row]->get_prev_value() -
            _boxs[row]->value()) *
            cost_service;

    _boxs[row]->set_prev_value(_boxs[row]->value());

    ui->cost->setText(COST_LABEL +
                      QString::number(get_cost_with_discount(_cost,ui->discount->value())));
    enabled_button();
}

void FormForGiveOrder::slot_change_discount(int)
{
    ui->cost->setText(COST_LABEL +
                      QString::number(get_cost_with_discount(_cost,ui->discount->value())));
}

bool FormForGiveOrder::add_order(Order &order)
{
    QSqlQuery query(REQUEST_TAKE_TABLE_ORDERS);
    if(!query.isActive())
    {
        return false;
    }
    query.last();
    int count_orders = query.at() < 0 ? 1 : query.at() + 2;
    query.first();

    const QVector<InfoOfOrderedService> &services = order.get_services();
    const QString &name_worker = order.get_name_worker();
    const QString &name_client = order.get_name_client();
    const QDateEdit &date = order.get_date();
    bool status = order.get_status();
    double cost = order.get_cost();
    int discount = order.get_discount();
    QString request = REQUEST_INSERT_ORDERS;
    request = request.arg(count_orders);
    request = request.arg(name_client);
    request = request.arg(name_worker);
    request = request.arg(QString::number(date.date().year()) + QChar('.') +
                          QString::number(date.date().month()) + QChar('.') +
                          QString::number(date.date().day()));
    request = request.arg(status);
    request = request.arg(cost);
    request = request.arg(count_orders);
    request = request.arg(discount);
    if(!query.exec(request))
    {
        return false;
    }
    request = QString(REQUEST_CREATE_TABLE_ORDER).arg(count_orders);
    if(!query.exec(request))
    {
        return false;
    }
    for(int i = 0; i < services.size(); i++)
    {
        request = REQUEST_INSERT_SERVICE_ORDER;
        request = request.arg(count_orders);
        request = request.arg(services[i].cost);
        request = request.arg(services[i].count);
        request = request.arg(services[i].name_service);
        if(!query.exec(request))
        {
            return false;
        }
    }
    return true;
}

void FormForGiveOrder::on_enter_button_clicked()
{
    QVector<InfoOfOrderedService> services;
    services.reserve(_boxs.size());

    InfoOfOrderedService temp;
    for(int i=0; i<_boxs.size(); i++)
    {
        if(_boxs[i]->value()!=0)
        {
            temp = InfoOfOrderedService{
                    ui->data_services->item(i,INDEX_COLUMN_NAME + OFFSET_INDEX)->text(),
                    _boxs[i]->value(),
                    ui->data_services->item(i,INDEX_COLUMN_COST + OFFSET_INDEX)->
                    text().replace(QChar(','),QChar('.')).
                    toDouble()};
            services.push_back(temp);
        }
    }

    Order order(ui->name_client->text(),
                ui->name_worker->text(),
                ui->date,services,
                _cost,
                false,
                ui->discount->value());

    if(!add_order(order))
    {
        QMessageBox::warning(this, tr(ERROR), tr(ERROR_MESSAGE));
    }
    else
    {
        QSqlQuery query(REQUEST_TAKE_TABLE_ORDERS);
        query.last();
        QString message = MESSAGE_NUMBER_ORDER + QString::number(query.at() + 1);
        QMessageBox::information(this,tr(REGISTRATION), tr(message.toStdString().c_str()));
        on_back_button_clicked();
    }
}
