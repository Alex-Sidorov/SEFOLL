#include "form_for_show_data.h"
#include "ui_form_for_show_data.h"

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
const int FormForShowData::INDEX_COLUMN_PHONE =     2;
const int FormForShowData::INDEX_COLUMN_WORKER =    3;
const int FormForShowData::INDEX_COLUMN_DATE =      4;
const int FormForShowData::INDEX_COLUMN_COST =      5;
const int FormForShowData::INDEX_COLUMN_DISCOUNT =  6;
const int FormForShowData::INDEX_COLUMN_STATUS =    7;
const int FormForShowData::INDEX_COLUMN_SERVICES =  8;

const int FormForShowData::INDEX_COLUMN_COST_SERVICE = 0;
const int FormForShowData::INDEX_COLUMN_NAME_SERVICE = 1;

const int FormForShowData::INDEX_COLUMN_COUNT_SERVICES_TABLE = 0;
const int FormForShowData::INDEX_COLUMN_COST_SERVICES_TABLE =  1;
const int FormForShowData::INDEX_COLUMN_NAME_SERVICES_TABLE =  2;

const int FormForShowData::STATUS_NO_MATTER = 0;
const int FormForShowData::STATUS_WORKED =    1;
const int FormForShowData::STATUS_WORK =      2;

const int FormForShowData::CODE_NOT_FIND = -1;

FormForShowData::FormForShowData(AbstractOrderRW *database, const QTableWidget *services, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Data),
    _services(services),
    m_database(database)
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

bool FormForShowData::check_date(const QDateEdit& edit_date)const
{
    if(!ui->is_date->isChecked())
    {
        return true;
    }

    auto date_before = ui->before_date->dateTime().toString("yyyyMMdd");
    auto date_after = ui->after_date->dateTime().toString("yyyyMMdd");
    auto date = edit_date.dateTime().toString("yyyyMMdd");

    if(!(date_before <= date && date <= date_after))
    {
        return false;
    }
    return true;
}

bool FormForShowData::check_worker(const QString &worker)const
{
    int count_worker = ui->worker_list->count();
    if(!ui->is_worker->isChecked() || count_worker == 0)
    {
        return true;
    }
    for(int i = 0; i < count_worker; i++)
    {
        if(worker.toLower() == ui->worker_list->item(i)->text().toLower())
        {
            return true;
        }
    }
    return false;
}

bool FormForShowData::check_client(const QString &client)const
{
    int count_client = ui->client_list->count();
    if(!ui->is_client->isChecked() || count_client == 0)
    {
        return true;
    }
    for(int i = 0; i < count_client; i++)
    {
        if(client.toLower() == ui->client_list->item(i)->text().toLower())
        {
            return true;
        }
    }
    return false;
}

bool FormForShowData::check_number(int number)const
{
    if(!ui->is_number->isChecked())
    {
        return true;
    }
    if(number == ui->number_order->value())
    {
        return true;
    }
    return false;
}

bool FormForShowData::check_status(bool status)const
{
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

bool FormForShowData::check_service(const Order& order)const
{
    if(!ui->service_list->count())
    {
        return true;
    }

    auto &services = order.get_services();
    if(services.isEmpty())
    {
        return false;
    }

    QString name_service;
    int count_service = ui->service_list->count();
    for(const auto& service : qAsConst(services))
    {
        for (int i = 0; i < count_service; i++)
        {
            if(service.name_service == ui->service_list->item(i)->text())
            {
                return true;
            }
        }
    }
    return false;
}

bool FormForShowData::is_need_order(const Order& order)const
{
    if(!check_date(order.get_date())
      || !check_worker(order.get_name_worker())
      || !check_number(order.get_number())
      || !check_client(order.get_name_client())
      || !check_status(order.get_status())
      || !check_service(order))
    {
        return false;
    }

    return true;
}

void FormForShowData::on_ok_button_clicked()
{
    auto orders = m_database->read_orders();

    QTableWidgetItem *item_number = nullptr;
    QTableWidgetItem *item_worker = nullptr;
    QTableWidgetItem *item_client = nullptr;
    QTableWidgetItem *item_cost =   nullptr;
    QTableWidgetItem *item_status = nullptr;
    QTableWidgetItem *item_phone = nullptr;
    QTableWidgetItem *item_date =   nullptr;
    QTableWidgetItem *item_discount = nullptr;
    int count_row = 0;
    ui->data->setRowCount(0);

    m_fullPrice = 0;
    for(const auto &order : qAsConst(orders))
    {
        if(is_need_order(order))
        {
            m_fullPrice += order.get_cost();

            item_number = new QTableWidgetItem(QString::number(order.get_number()));
            item_worker = new QTableWidgetItem(order.get_name_worker());
            item_client = new QTableWidgetItem(order.get_name_client());
            item_cost = new QTableWidgetItem(QString::number(order.get_cost()));
            item_phone = new QTableWidgetItem(order.get_phone());
            item_discount = new QTableWidgetItem(QString::number(order.get_discount()));
            item_date = new QTableWidgetItem(order.get_date().dateTime().toString("dd:MM:yyyy"));
            item_status = new QTableWidgetItem(order.get_status() ? COMPLETE_ORDER : NOT_COMPLETE_ORDER);

            count_row = ui->data->rowCount();
            ui->data->insertRow(count_row);
            ui->data->setItem(count_row,INDEX_COLUMN_NUMBER,item_number);
            ui->data->setItem(count_row,INDEX_COLUMN_COST,item_cost);
            ui->data->setItem(count_row,INDEX_COLUMN_PHONE,item_phone);
            ui->data->setItem(count_row,INDEX_COLUMN_WORKER,item_worker);
            ui->data->setItem(count_row,INDEX_COLUMN_DATE,item_date);
            ui->data->setItem(count_row,INDEX_COLUMN_STATUS,item_status);
            ui->data->setItem(count_row,INDEX_COLUMN_CLIENT,item_client);
            ui->data->setItem(count_row,INDEX_COLUMN_DISCOUNT,item_discount);

            auto table = create_service_table(order);
            if(table)
            {
                ui->data->setCellWidget(count_row,INDEX_COLUMN_SERVICES,table);
            }
            ui->data->setColumnWidth(INDEX_COLUMN_SERVICES,320);
            ui->data->setRowHeight(count_row,160);
        }
    }

    ui->sumOrders->setText("Сумма: " + QString::number(m_fullPrice));
}

QTableWidget* FormForShowData::create_service_table(const Order &order)
{
    auto services = order.get_services();
    if(!services.isEmpty())
    {
        QTableWidget *table = new QTableWidget(0,3);//rows,cols
        QString cost;
        QString count;
        QString name;
        int count_row = 0;
        QTableWidgetItem *item_cost = nullptr;
        QTableWidgetItem *item_name = nullptr;
        QTableWidgetItem *item_count = nullptr;
        for(const auto& service : qAsConst(services))
        {
            cost = QString::number(service.cost);
            count = QString::number(service.count);
            name = service.name_service;
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

    ui->sumOrders->setText("Сумма: ");
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

    stream << "Сумма: " + QString::number(m_fullPrice);
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
