#include "form_for_show_data.h"
#include "ui_form_for_show_data.h"

const char* FormForShowData::REQUEST_TAKE_TABLE_ORDERS = "SELECT * FROM orders;";
const char* FormForShowData::REQUEST_TAKE_TABLE_SERVICES_ORDER = "SELECT * FROM _%1_;";

const char* FormForShowData::COLUMN_NUMBER =    "number";
const char* FormForShowData::COLUMN_CLIENT =    "client";
const char* FormForShowData::COLUMN_WORKER =    "worker";
const char* FormForShowData::COLUMN_DATE =      "date";
const char* FormForShowData::COLUMN_COST =      "cost";
const char* FormForShowData::COLUMN_STATUS =    "status";
const char* FormForShowData::COLUMN_DISCOUNT =  "discount";

const char* FormForShowData::COLUMN_PRICE_SERVICE =  "price";
const char* FormForShowData::COLUMN_COUNT_SERVICES = "count";
const char* FormForShowData::COLUMN_NAME_SERVICE =   "name";

const char* FormForShowData::COMPLETE_ORDER =     "Выполнен";
const char* FormForShowData::NOT_COMPLETE_ORDER = "Выполняется";

const char* FormForShowData::CAPTION_TEXT = "Сохранение статистики";
const char* FormForShowData::FORMAT_FILE =  "Excel (*.csv)";

const char* FormForShowData::COMPLETE = "Готово";
const char* FormForShowData::COMPLETE_SAVE = "Файл сохранён";

const char* FormForShowData::ERROR = "Ошибка";
const char* FormForShowData::ERROR_SAVE_FILE = "Не удалось сохранить файл";

const int FormForShowData::INDEX_COLUMN_NUMBER =    0;
const int FormForShowData::INDEX_COLUMN_CLIENT =    1;
const int FormForShowData::INDEX_COLUMN_WORKER =    2;
const int FormForShowData::INDEX_COLUMN_DATE =      3;
const int FormForShowData::INDEX_COLUMN_COST =      4;
const int FormForShowData::INDEX_COLUMN_DISCOUNT =  5;
const int FormForShowData::INDEX_COLUMN_STATUS =    6;
const int FormForShowData::INDEX_COLUMN_SERVICES =  7;

const int FormForShowData::INDEX_COLUMN_COST_SERVICE = 0;
const int FormForShowData::INDEX_COLUMN_NAME_SERVICE = 1;

const int FormForShowData::INDEX_COLUMN_COUNT_SERVICES_TABLE = 0;
const int FormForShowData::INDEX_COLUMN_COST_SERVICES_TABLE =  1;
const int FormForShowData::INDEX_COLUMN_NAME_SERVICES_TABLE =  2;

const int FormForShowData::STATUS_NO_MATTER = 0;
const int FormForShowData::STATUS_WORKED =    1;
const int FormForShowData::STATUS_WORK =      2;

const int FormForShowData::CODE_NOT_FIND = -1;

FormForShowData::FormForShowData(const QTableWidget *services, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Data),
    _services(services)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":icons/icon.png"));
}

void FormForShowData::show()
{
    on_clear_button_clicked();
    ui->service_box->clear();
    fill_service_box();
    QWidget::show();
}

void FormForShowData::fill_service_box()
{
    if(_services)
    {
        int count = _services->rowCount();
        for(int i = 0; i < count; i++)
        {
            ui->service_box->addItem(_services->item(i,INDEX_COLUMN_NAME_SERVICE)->text());
        }
    }
}

void FormForShowData::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}

bool FormForShowData::check_date(QSqlQuery &query, QSqlRecord &record)const
{
    if(!ui->is_date->isChecked())
    {
        return true;
    }

    int date_before = (QString::number(ui->before_date->date().year()) +
                       (ui->before_date->date().month()< 10 ? '0' +
                       QString::number(ui->before_date->date().month()):
                       QString::number(ui->before_date->date().month())) +
                       (ui->before_date->date().day() < 10 ? '0' +
                       QString::number(ui->before_date->date().day()):
                       QString::number(ui->before_date->date().day()))).toInt();
    int date_after = (QString::number(ui->after_date->date().year()) +
                      (ui->after_date->date().month()< 10 ? '0' +
                      QString::number(ui->after_date->date().month()):
                      QString::number(ui->after_date->date().month())) +
                      (ui->after_date->date().day()< 10 ? '0' +
                      QString::number(ui->after_date->date().day()):
                      QString::number(ui->after_date->date().day()))).toInt();

    QStringList temp = query.value(record.indexOf(COLUMN_DATE)).toString().split('.');
    int date = ((temp.at(0).toInt()*100) + temp.at(1).toInt())*100 + temp.at(2).toInt();

    if(!(date_before <= date && date <= date_after))
    {
        return false;
    }
    return true;
}

bool FormForShowData::check_worker(QSqlQuery &query, QSqlRecord &record)const
{
    int count_worker = ui->worker_list->count();
    if(!ui->is_worker->isChecked() || count_worker == 0)
    {
        return true;
    }
    QString worker = query.value(record.indexOf(COLUMN_WORKER)).toString().toLower();
    for(int i = 0; i < count_worker; i++)
    {
        if(worker == ui->worker_list->item(i)->text().toLower())
        {
            return true;
        }
    }
    return false;
}

bool FormForShowData::check_client(QSqlQuery &query, QSqlRecord &record)const
{
    int count_client = ui->client_list->count();
    if(!ui->is_client->isChecked() || count_client == 0)
    {
        return true;
    }
    QString client = query.value(record.indexOf(COLUMN_CLIENT)).toString().toLower();
    for(int i = 0; i < count_client; i++)
    {
        if(client == ui->client_list->item(i)->text().toLower())
        {
            return true;
        }
    }
    return false;
}

bool FormForShowData::check_number(QSqlQuery &query, QSqlRecord &record)const
{
    if(!ui->is_number->isChecked())
    {
        return true;
    }
    if(query.value(record.indexOf(COLUMN_NUMBER)).toInt()
      == ui->number_order->value())
    {
        return true;
    }
    return false;
}

bool FormForShowData::check_status(QSqlQuery &query, QSqlRecord &record)const
{
    bool status = query.value(record.indexOf(COLUMN_STATUS)).toBool();
    switch(ui->status_box->currentIndex())
    {
        case STATUS_NO_MATTER:return true;
        case STATUS_WORKED:
        {
            if(status)
            {
                return true;
            }
            return false;
        }
        case STATUS_WORK:
        {
            if(!status)
            {
                return true;
            }
            return false;
        }
        default:return true;
    }
}

bool FormForShowData::check_service(int number_order)const
{
    if(!ui->service_list->count())
    {
        return true;
    }
    QString request = REQUEST_TAKE_TABLE_SERVICES_ORDER;
    request = request.arg(number_order);
    QSqlQuery table_query;
    if(!table_query.exec(request))
    {
        return false;
    }

    QSqlRecord table_record;
    QString name_service;
    int count_service = ui->service_list->count();
    while(table_query.next())
    {
        table_record = table_query.record();
        name_service = table_query.value(table_record.indexOf(COLUMN_NAME_SERVICE)).toString();

        for (int i = 0; i < count_service; i++)
        {
            if(name_service == ui->service_list->item(i)->text())
            {
                return true;
            }
        }
    }
    return false;
}

bool FormForShowData::is_need_order(QSqlQuery &query, QSqlRecord &record)const
{
    if(!check_date(query,record)
      || !check_worker(query,record)
      || !check_number(query,record)
      || !check_client(query,record)
      || !check_status(query, record)
      || !check_service(query.value(record.indexOf(COLUMN_NUMBER)).toInt()))
    {
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
    QTableWidgetItem *item_number = nullptr;
    QTableWidgetItem *item_worker = nullptr;
    QTableWidgetItem *item_client = nullptr;
    QTableWidgetItem *item_cost =   nullptr;
    QTableWidgetItem *item_status = nullptr;
    QTableWidgetItem *item_date =   nullptr;
    QTableWidgetItem *item_discount = nullptr;
    int count_row = 0;
    ui->data->setRowCount(0);
    while(query.next())
    {
        record = query.record();
        if(is_need_order(query, record))
        {
            item_number = new QTableWidgetItem(query.value(record.indexOf(COLUMN_NUMBER)).toString());
            item_worker = new QTableWidgetItem(query.value(record.indexOf(COLUMN_WORKER)).toString());
            item_client = new QTableWidgetItem(query.value(record.indexOf(COLUMN_CLIENT)).toString());
            item_cost = new QTableWidgetItem(query.value(record.indexOf(COLUMN_COST)).toString());
            item_discount = new QTableWidgetItem(query.value(record.indexOf(COLUMN_DISCOUNT)).toString());
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
            ui->data->setItem(count_row,INDEX_COLUMN_NUMBER,item_number);
            ui->data->setItem(count_row,INDEX_COLUMN_COST,item_cost);
            ui->data->setItem(count_row,INDEX_COLUMN_WORKER,item_worker);
            ui->data->setItem(count_row,INDEX_COLUMN_DATE,item_date);
            ui->data->setItem(count_row,INDEX_COLUMN_STATUS,item_status);
            ui->data->setItem(count_row,INDEX_COLUMN_CLIENT,item_client);
            ui->data->setItem(count_row,INDEX_COLUMN_DISCOUNT,item_discount);

            auto table = create_service_table(item_number->text().toInt());
            if(table)
            {
                ui->data->setCellWidget(count_row,INDEX_COLUMN_SERVICES,table);
            }
            ui->data->setColumnWidth(INDEX_COLUMN_SERVICES,320);
            ui->data->setRowHeight(count_row,160);
        }
    }
}

QTableWidget* FormForShowData::create_service_table(int number)
{
    QSqlQuery query;
    QString request = REQUEST_TAKE_TABLE_SERVICES_ORDER;
    request = request.arg(number);
    if(query.exec(request))
    {
        QSqlRecord record = query.record();
        QTableWidget *table = new QTableWidget(0,3);//rows,cols
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

            count_row = table->rowCount();
            table->insertRow(count_row);
            table->setItem(count_row,INDEX_COLUMN_COUNT_SERVICES_TABLE,item_count);
            table->setItem(count_row,INDEX_COLUMN_COST_SERVICES_TABLE,item_cost);
            table->setItem(count_row,INDEX_COLUMN_NAME_SERVICES_TABLE,item_name);
        }

        table->setHorizontalHeaderItem(INDEX_COLUMN_COST_SERVICES_TABLE,new QTableWidgetItem("Цена"));
        table->setHorizontalHeaderItem(INDEX_COLUMN_COUNT_SERVICES_TABLE,new QTableWidgetItem("Количество"));
        table->setHorizontalHeaderItem(INDEX_COLUMN_NAME_SERVICES_TABLE,new QTableWidgetItem("Услуга"));

        return table;
    }
    return nullptr;
}

void FormForShowData::on_clear_button_clicked()
{
    ui->data->setRowCount(0);
    ui->service_list->clear();
    ui->number_order->setValue(0);

    QDate temp(2000,1,1);
    ui->before_date->setDate(temp);
    ui->after_date->setDate(temp);

    ui->worker_list->clear();
    ui->service_list->clear();
    ui->client_list->clear();
    ui->client_line->clear();
    ui->names_workers->clear();
}

void FormForShowData::set_workers(const QList<QString> &workers)
{
    ui->names_workers->addItems(workers);
}

void FormForShowData::on_add_worker_button_clicked()
{
    ui->worker_list->addItem(ui->names_workers->currentText());
}

void FormForShowData::on_worker_list_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    delete ui->worker_list->takeItem(index.row());
}

void FormForShowData::on_is_number_clicked(bool checked)
{
    if(checked)
    {
        ui->number_order->setEnabled(true);
    }
    else
    {
        ui->number_order->setEnabled(false);
    }
}

void FormForShowData::on_is_worker_clicked(bool checked)
{
    if(checked)
    {
        ui->add_worker_button->setEnabled(true);
    }
    else
    {
        ui->add_worker_button->setEnabled(false);
    }
}

void FormForShowData::on_is_client_clicked(bool checked)
{
    if(checked)
    {
        ui->add_client_button->setEnabled(true);
    }
    else
    {
        ui->add_client_button->setEnabled(false);
    }
}

void FormForShowData::on_is_date_clicked(bool checked)
{
    if(checked)
    {
        ui->after_date->setEnabled(true);
        ui->before_date->setEnabled(true);
    }
    else
    {
        ui->after_date->setEnabled(false);
        ui->before_date->setEnabled(false);
    }
}

void FormForShowData::on_is_service_clicked(bool checked)
{
    if(checked)
    {
        ui->add_service_button->setEnabled(true);
    }
    else
    {
        ui->add_service_button->setEnabled(false);
    }
}

void FormForShowData::on_add_client_button_clicked()
{
    if(!ui->client_line->text().isEmpty())
    {
        ui->client_list->addItem(ui->client_line->text());
    }
}

void FormForShowData::on_client_list_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    delete ui->client_list->takeItem(index.row());
}

void FormForShowData::on_add_service_button_clicked()
{
    ui->service_list->addItem(ui->service_box->currentText());
}

void FormForShowData::on_service_list_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    delete ui->service_list->takeItem(index.row());
}

void FormForShowData::on_save_to_excel_button_clicked()
{
    auto file_name = QFileDialog::getSaveFileName(this,CAPTION_TEXT,"",FORMAT_FILE,nullptr);
    if(!save_csv_file(file_name))
    {
        QMessageBox::warning(this,tr(ERROR),tr(ERROR_SAVE_FILE));
    }
    else
    {
        QMessageBox::information(this,tr(COMPLETE),tr(COMPLETE_SAVE));
    }
}

bool FormForShowData::save_csv_file(const QString &file_name)const
{
    QFile file(file_name);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    if(!file.isOpen())
    {
        return false;
    }
    QTextStream stream(&file);
    QStringList list;

    for (auto i = 0; i <= INDEX_COLUMN_SERVICES; i++)
    {
        list << ui->data->horizontalHeaderItem(i)->text();
    }
    stream << list.join(';') << '\n';

    auto row_count = ui->data->rowCount();
    for (auto i = 0; i < row_count; i++)
    {
        list.clear();
        for (auto j = 0; j < INDEX_COLUMN_SERVICES; j++)
        {
           list << "'\'" + ui->data->item(i,j)->text() + "'\'";
        }
        stream << list.join(';') << ';';
        save_service_table(stream,i);
        stream << "\n";
    }
    file.close();
    return true;
}

void FormForShowData::save_service_table(QTextStream &stream, int row)const
{
    auto table = static_cast<QTableWidget*>(ui->data->cellWidget(row,INDEX_COLUMN_SERVICES));
    QStringList list;

    for (auto i = 0; i <= INDEX_COLUMN_NAME_SERVICES_TABLE; i++)
    {
        list << table->horizontalHeaderItem(i)->text();
    }
    stream << list.join(';') << '\n' << QString().fill(';',INDEX_COLUMN_SERVICES);

    auto row_count = table->rowCount();
    for (auto i = 0; i < row_count; i++)
    {
        list.clear();
        for (auto j = 0; j <= INDEX_COLUMN_NAME_SERVICES_TABLE; j++)
        {
            list << "'\'" + table->item(i,j)->text() + "'\'";
        }
        stream << list.join(';') << '\n' << QString().fill(';',INDEX_COLUMN_SERVICES);
    }
}
