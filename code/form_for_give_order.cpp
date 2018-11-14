#include "form_for_give_order.h"
#include "ui_form_for_give_order.h"

FormForGiveOrder::FormForGiveOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Give_Order),
    _mapper(new QSignalMapper)
{
    ui->setupUi(this);
    connect(ui->name_client,SIGNAL(textChanged(QString)),SLOT(enabled_button()));
    connect(ui->name_worker,SIGNAL(textChanged(QString)),SLOT(enabled_button()));

    ui->date->setDate(QDate::currentDate());
    _cost = 0;
}

FormForGiveOrder::~FormForGiveOrder()
{
    delete _mapper;
    delete ui;
}

void FormForGiveOrder::set_table(const QTableWidget* table)
{
    _boxs.reserve(table->rowCount());
    for(int i=0; i<table->rowCount(); i++)
    {
        QTableWidgetItem *item_cost = new QTableWidgetItem(*(table->item(i,0)));
        QTableWidgetItem *item_name = new QTableWidgetItem(*(table->item(i,1)));

        ui->data_services->insertRow(ui->data_services->rowCount());
        ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_cost);
        ui->data_services->setItem(ui->data_services->rowCount()-1,2,item_name);

        New_SpinBox *new_box = new New_SpinBox;
        new_box->setMaximum(1000);
        _boxs.push_back(new_box);

        connect(new_box,SIGNAL(valueChanged(int)),_mapper,SLOT(map()));
        _mapper->setMapping(new_box,i);

        ui->data_services->setCellWidget(ui->data_services->rowCount()-1,0,new_box);
    }
    connect(_mapper,SIGNAL(mapped(int)),SLOT(slot_change_box(int)));
}

void FormForGiveOrder::clear_form()
{
    _cost = 0;
    ui->cost->setText(QString("Сумма:0"));
    ui->name_client->clear();
    ui->name_worker->clear();
    ui->date->setDate(QDate::currentDate());
    while(ui->data_services->rowCount())
    {
        delete ui->data_services->item(0,1);//
        delete ui->data_services->item(0,2);//
        ui->data_services->removeRow(0);
    }

    for(int i=0; i<_boxs.size();i++)
    {
        delete _boxs[i];
    }
    _boxs.clear();
}

void FormForGiveOrder::on_back_button_clicked()
{
    clear_form();
    this->close();
    emit to_main_window();
}

void FormForGiveOrder::enabled_button()const
{
    if(_cost!=0 &&
       !ui->name_client->text().isEmpty() &&
       !ui->name_worker->text().isEmpty())
    {
        ui->enter_button->setEnabled(true);
    }
    else
    {
        ui->enter_button->setEnabled(false);
    }
}

void FormForGiveOrder::slot_change_box(int row)
{
    _cost-=(_boxs[row]->get_prev_value()-_boxs[row]->value())
            * ui->data_services->item(row,1)->
            text().replace(QChar(','),QChar('.')).toDouble();
    _boxs[row]->set_prev_value(_boxs[row]->value());
    ui->cost->setText("Сумма:"+QString::number(_cost));
    enabled_button();
}

bool FormForGiveOrder::add_order(Order &order)
{
    QSqlQuery query("SELECT * FROM orders;");
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
    QString request = "INSERT INTO orders(number, client, worker, date, status, cost, services)";
    request += " VALUES(%1, '%2', '%3', '%4', %5, %6, %7);";
    request = request.arg(count_orders);
    request = request.arg(name_client);
    request = request.arg(name_worker);
    request = request.arg(QString::number(date.date().year()) + QChar('.') +
                          QString::number(date.date().month()) + QChar('.') +
                          QString::number(date.date().day()));
    request = request.arg(status);
    request = request.arg(cost);
    request = request.arg(count_orders);
    if(!query.exec(request))
    {
        return false;
    }
    request = QString("CREATE TABLE _%1_ (price NOT NULL, count NOT NULL, name TEXT);").arg(count_orders);
    if(!query.exec(request))
    {
        return false;
    }
    for(int i = 0; i < services.size(); i++)
    {
        request = "INSERT INTO _%1_(price, count, name)  VALUES(%2, %3, '%4');";
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

    for(int i=0; i<_boxs.size(); i++)
    {
        if(_boxs[i]->value()!=0)
        {
            services.push_back(InfoOfOrderedService{
                                   ui->data_services->item(i,2)->text(),
                                   _boxs[i]->value(),
                                   ui->data_services->item(i,1)->
                                   text().replace(QChar(','),QChar('.')).
                                   toDouble()});
        }
    }

    Order order(ui->name_client->text(),
                ui->name_worker->text(),
                ui->date,services,_cost,false);
    if(!add_order(order))
    {
        const char* message = "Неудалось зарегистрировать заказ. Попробуйте позже.";
        QMessageBox::warning(this, tr("ОШИБКА"), tr(message));
    }
}
