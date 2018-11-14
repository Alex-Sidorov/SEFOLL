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

    for(int i=0; i<_boxs.size();i++)//
    {                       //
        delete _boxs[i];//
    }               //
    _boxs.clear();//
}

void FormForGiveOrder::on_back_button_clicked()
{
    clear_form();
    this->close();
    emit to_main_window();
}

void FormForGiveOrder::enabled_button()const
{
    if(_cost!=0
       && !ui->name_client->text().isEmpty()
       && !ui->name_worker->text().isEmpty())
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


void FormForGiveOrder::on_enter_button_clicked()
{
    QVector<Info_Of_Ordered_Service> services;
    services.reserve(_boxs.size());

    for(int i=0; i<_boxs.size(); i++)
    {
        if(_boxs[i]->value()!=0)
        {
            services.push_back(Info_Of_Ordered_Service{
                                   ui->data_services->item(i,2)->text(),
                                   _boxs[i]->value(),
                                   ui->data_services->item(i,1)->
                                   text().replace(QChar(','),QChar('.')).
                                   toDouble()});
        }
    }

    if(!Order::write_order(Order(ui->name_client->text(),
                                 ui->name_worker->text(),
                                 ui->date,services,_cost,false)))
    {
        QMessageBox::warning(this,tr("ОШИБКА"),
                             tr("Неудалось зарегистрировать заказ. Попробуйте позже."));
    }
    else
    {
        QString message = "Заказ оформлен.\n Номер:"
                +QString::number(Order::get_count_order());
        QMessageBox::information(this,tr("Регистрация."),
                                 tr(message.toStdString().c_str()));
        on_back_button_clicked();
    }
}
