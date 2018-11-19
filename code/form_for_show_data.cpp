#include "form_for_show_data.h"
#include "ui_form_for_show_data.h"

const char* FormForShowData::REQUEST_TAKE_TABLE_ORDERS = "SELECT * FROM orders;";

const char* FormForShowData::COLUMN_CLIENT = "client";
const char* FormForShowData::COLUMN_WORKER = "worker";
const char* FormForShowData::COLUMN_DATE =   "date";
const char* FormForShowData::COLUMN_COST =   "cost";
const char* FormForShowData::COLUMN_STATUS = "status";

const char* FormForShowData::COMPLETE_ORDER =   "Выполнен";
const char* FormForShowData::NOT_COMPLETE_ORDER = "Выполняется";

const int FormForShowData::INDEX_COLUMN_CLIENT = 0;
const int FormForShowData::INDEX_COLUMN_WORKER = 1;
const int FormForShowData::INDEX_COLUMN_DATE =   2;
const int FormForShowData::INDEX_COLUMN_COST =   3;
const int FormForShowData::INDEX_COLUMN_STATUS = 4;

FormForShowData::FormForShowData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Data)
{
    ui->setupUi(this);
}

void FormForShowData::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}

bool FormForShowData::is_need_order(QSqlQuery &query, QSqlRecord &record)const
{
    int date_before = (QString::number(ui->before_date->date().year()) +
                       QString::number(ui->before_date->date().month()) +
                       QString::number(ui->before_date->date().day())).toInt();
    int date_after = (QString::number(ui->after_date->date().year()) +
                      QString::number(ui->after_date->date().month()) +
                      QString::number(ui->after_date->date().day())).toInt();;
    QString temp = query.value(record.indexOf(COLUMN_DATE)).toString();
    while(temp.indexOf('.') != -1)
    {
        temp.remove(temp.indexOf('.'),1);
    }
    int date = temp.toInt();
    QString worker = query.value(record.indexOf(COLUMN_WORKER)).toString();
    if(!(date_before >= date && date <= date_after))
    {
        return false;
    }
    int count_worker = ui->worker_list->count();
    if(count_worker)
    {
        for(int i = 0; i < count_worker; i++)
        {
            if(worker == ui->worker_list->item(i)->text())
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

void FormForShowData::on_ok_button_clicked()
{
    QSqlQuery query(REQUEST_TAKE_TABLE_ORDERS);
    if(!query.isActive())
    {
        return;
    }
    QSqlRecord record;
    QTableWidgetItem *item_worker = NULL;
    QTableWidgetItem *item_client = NULL;
    QTableWidgetItem *item_cost = NULL;
    QTableWidgetItem *item_status = NULL;
    QTableWidgetItem *item_date = NULL;
    int count_row = 0;
    ui->data->clear();
    while(query.next())
    {
        record = query.record();
        if(is_need_order(query, record))
        {
            item_worker = new QTableWidgetItem(query.value(record.indexOf(COLUMN_WORKER)).toString());
            item_client = new QTableWidgetItem(query.value(record.indexOf(COLUMN_CLIENT)).toString());
            item_cost = new QTableWidgetItem(query.value(record.indexOf(COLUMN_COST)).toString());

            item_date = new QTableWidgetItem(query.value(record.indexOf(COLUMN_DATE)).toString());
            if(query.value(record.indexOf(COLUMN_STATUS)).toBool())
            {
                item_status = new QTableWidgetItem(COMPLETE_ORDER);
            }
            else
            {
                item_status = new QTableWidgetItem(NOT_COMPLETE_ORDER);
            }
            count_row = ui->data->rowCount();
            ui->data->insertRow(count_row);
            ui->data->setItem(count_row,INDEX_COLUMN_COST,item_cost);
            ui->data->setItem(count_row,INDEX_COLUMN_WORKER,item_worker);
            ui->data->setItem(count_row,INDEX_COLUMN_DATE,item_date);
            ui->data->setItem(count_row,INDEX_COLUMN_STATUS,item_status);
            ui->data->setItem(count_row,INDEX_COLUMN_CLIENT,item_client);
        }
    }

}

void FormForShowData::on_pushButton_clicked()
{
    ui->data->removeRow(0);
    ui->worker_line->clear();
}

void FormForShowData::on_add_worker_button_clicked()
{
    if(!ui->worker_line->text().isEmpty())
    {
        ui->worker_list->addItem(ui->worker_line->text());
    }
}

void FormForShowData::on_worker_list_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    ui->worker_list->removeItemWidget(ui->worker_list->item(index.row()));
}
