#include "form_for_give_order.h"
#include "ui_form_for_give_order.h"

const int FormForGiveOrder::INDEX_COLUMN_COST =  0;
const int FormForGiveOrder::INDEX_COLUMN_NAME =  1;
const int FormForGiveOrder::INDEX_COLUMN_COUNT = 0;
const int FormForGiveOrder::INDEX_FIRST_ROW =    0;

const int FormForGiveOrder::FULL_PRICE =         100;

const int FormForGiveOrder::OFFSET_INDEX = 1;

const char* FormForGiveOrder::COST_LABEL = "Сумма:";

FormForGiveOrder::FormForGiveOrder(AbstractOrderRW* database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForGiveOrder),
    _mapper(new QSignalMapper),
    m_database(database)
{
    ui->setupUi(this);
    connect(ui->name_client,SIGNAL(textChanged(QString)),SLOT(enabled_button()));
    connect(ui->discount,SIGNAL(valueChanged(int)),SLOT(slot_change_discount(int)));

    ui->date->setDate(QDate::currentDate());
    _cost = 0;

    setWindowIcon(QIcon(":icons/icon.png"));
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
    ui->names_workers->clear();
    ui->date->setDate(QDate::currentDate());
    ui->data_services->setRowCount(0);
    _boxs.clear();
    ui->discount->clear();
}

void FormForGiveOrder::on_back_button_clicked()
{
    clear_form();
    this->close();
    emit to_main_window();
}

bool FormForGiveOrder::check_input_fields()const
{
    return _cost != 0.0 && !ui->name_client->text().isEmpty();
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

void FormForGiveOrder::set_workers(const QList<QString> &workers)
{
    ui->names_workers->addItems(workers);
}

void FormForGiveOrder::on_enter_button_clicked()
{
    if(!m_database)
    {
        return;
    }

    auto number_order = (QDateTime::currentDateTime().toString("yyyyMM") + QString::number(m_database->count_orders())).toInt();

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


    Order order(number_order,ui->name_client->text(),
                ui->names_workers->currentText(),
                ui->date,services,
                get_cost_with_discount(_cost,ui->discount->value()),
                false,
                ui->discount->value(),
                ui->phoneLine->text());

    m_database->write_order(order);

    QString message = MESSAGE_NUMBER_ORDER + QString::number(number_order);
    QMessageBox::information(this,tr(REGISTRATION), tr(message.toStdString().c_str()));
}
