#include "mainwindow.h"
#include "ui_mainwindow.h"

const char* MainWindow::ERROR =                "Ошибка";
const char* MainWindow::ERROR_ACCESS =         "Недостаточно прав доступа";
const char* MainWindow::ERROR_ADD_SERVICE =    "В данный момент нельзя добавить данные.";
const char* MainWindow::ERROR_CHANGE_SERVICE = "В данный момент нельзя изменить данные.";
const char* MainWindow::ERROR_OPEN_DATA_BASE = "В данный момент база данных недоступна.";
const char* MainWindow::ERROR_SETTINGS =       "Ошибка при чтении настроек.";

const char* MainWindow::ERROR_MESSAGE =
        "Не удалось зарегистрировать заказ. Попробуйте позже.";

const char* MainWindow::REGISTRATION = "Регистрация";
const char* MainWindow::MESSAGE_NUMBER_ORDER = "Заказ оформлен.\n Номер:";

const char* MainWindow::NAME_FILE_SETTINGS = "settings.conf";

const char* MainWindow::NAME_GROUP_DATA_BASE_SETTINGS = "data_base";
const char* MainWindow::SETTINGS_VALUE_PATH_DATA_BASE = "path";

const char* MainWindow::NAME_DEFAULT_DATA_BASE = "data.sqlite";
const char* MainWindow::TYPE_DATA_BASE = "QSQLITE";

const char* MainWindow::REQUESTE_DATA_SERVICE =   "INSERT INTO services(price, name) VALUES(%1, '%2');";
const char* MainWindow::REQUESTE_TAKE_SERVICES =  "SELECT * FROM services";
const char* MainWindow::REQUESTE_UPDATE_NAME =    "UPDATE services SET name = '%1' WHERE price = %2 AND name = '%3';";
const char* MainWindow::REQUESTE_UPDATE_PRICE =   "UPDATE services SET price = %1 WHERE price = %2 AND name = '%3';";
const char* MainWindow::REQUESTE_DELETE_SERVICE = "DELETE FROM services WHERE price = %1 AND name = '%2'";

const char* MainWindow::REQUEST_TAKE_TABLE_ORDERS = "SELECT * FROM orders;";
const char* MainWindow::REQUEST_INSERT_ORDERS =
        "INSERT INTO orders(number, client, worker, date, status, cost, services, discount)"
        " VALUES(%1, '%2', '%3', '%4', %5, %6, %7, %8);";
const char* MainWindow::REQUEST_CREATE_TABLE_ORDER =
        "CREATE TABLE _%1_ (price NOT NULL, count NOT NULL, name TEXT);";
const char* MainWindow::REQUEST_INSERT_SERVICE_ORDER =
        "INSERT INTO _%1_(price, count, name)  VALUES(%2, %3, '%4');";

const char* MainWindow::COLUMN_PRICE = "price";
const char* MainWindow::COLUMN_NAME =  "name";

const int MainWindow::INDEX_COLUMN_COST = 0;
const int MainWindow::INDEX_COLUMN_NAME = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),    
    data(QSqlDatabase::addDatabase(TYPE_DATA_BASE)),
    window_for_give_order(new FormForGiveOrder),
    window_for_change_service(new FormForChangeService(&m_data_base)),
    window_for_add_service(new FormForAddService),
    window_for_delete_service( new FormForDeleteService(&m_data_base)),
    window_for_show_order(new FormForShowOrder),
    window_for_options(new FormForOptions),
    window_for_show_data(nullptr),
    window_for_show_options_data_base(new FormForOptionsDataBase),
    window_for_workers(new FormForWorkers(&m_data_base)),
    _access(GUEST),
    _name_file_data(NAME_DEFAULT_DATA_BASE),
    _settings(NAME_FILE_SETTINGS,QSettings::IniFormat)
{
    connect(window_for_show_order.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_give_order.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_give_order.data(),SIGNAL(add_order(const Order&)),this,SLOT(slot_add_order_in_data_base(const Order&)));
    connect(window_for_add_service.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_add_service.data(),SIGNAL(new_data()),SLOT(add_service()));
    connect(window_for_delete_service.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_workers.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_delete_service.data(),SIGNAL(changed_table(QVector<int>)),SLOT(upload_table(QVector<int>)));
    connect(window_for_change_service.data(),SIGNAL(changed_data(int, const QString &, double)),SLOT(upload_table(int, const QString &, double)));
    connect(window_for_change_service.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_options.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_show_options_data_base.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_show_options_data_base.data(),SIGNAL(changed_data_base(QString&)),this,SLOT(slot_changed_data_base(QString&)));

    ui->setupUi(this);

    connect(ui->options_data_base,&QPushButton::clicked,this,&MainWindow::slot_clicked_options_data_base);

    window_for_show_data = QSharedPointer<FormForShowData>(new FormForShowData(ui->data_services));
    connect(window_for_show_data.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));

    read_settings();
    data.open();
    read_file_data();

    setWindowIcon(QIcon(":icons/icon.png"));
}

MainWindow::~MainWindow()
{
    data.close();
}

void MainWindow::set_access(Access access)
{
    _access = access;
}

void MainWindow::slot_changed_data_base(QString &name_data_base)
{
    data.close();
    data.setDatabaseName(name_data_base);
    if(!data.open())
    {
        QMessageBox::warning(this,ERROR,"Невозможно сменить базу данных");
        return;
    }
    read_file_data();
    _settings.setValue("data_base/path",name_data_base);
    window_for_show_options_data_base->set_path_data_base(name_data_base);
    this->close();
}

void MainWindow::slot_clicked_options_data_base()
{
    if(_access != ADMIN &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }
    window_for_show_options_data_base->show();
    this->close();
}

void MainWindow::on_give_order_button_clicked()
{
    if(_access != ADMIN &&
       _access != WORKER_TAKE_ORDER &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }

    window_for_give_order->set_workers(window_for_workers->get_names_workers());
    window_for_give_order->set_table(ui->data_services);
    window_for_give_order->show();
    this->close();
}

void MainWindow::on_add_service_button_clicked()
{
    if(_access != ADMIN &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }
    window_for_add_service->show();
    this->close();
}

void MainWindow::on_show_order_button_clicked()
{
    if(_access != ADMIN &&
       _access != WORKER_CLOSE_ORDER &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }
    window_for_show_order->show();
    this->close();
}

void MainWindow::on_change_service_button_clicked()
{
    if(_access != ADMIN &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }
    window_for_change_service->set_table(ui->data_services);
    window_for_change_service->show();
    this->close();
}

void MainWindow::on_delete_service_button_clicked()
{
    if(_access != ADMIN &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }
    window_for_delete_service->set_table(ui->data_services);
    window_for_delete_service->show();
    this->close();
}

void MainWindow::show_main_window()
{
    this->show();
}

void MainWindow::add_service()
{
    show_main_window();

    double cost = window_for_add_service->get_cost_service();
    QString name = window_for_add_service->get_name_service();
    if(!m_data_base.add_service(name, cost))
    {
        QMessageBox::warning(this,ERROR,ERROR_ADD_SERVICE);
        return;
    }

    QTableWidgetItem *item_cost = new QTableWidgetItem(QString::number(cost));
    QTableWidgetItem *item_name = new QTableWidgetItem(name);

    int count_row = ui->data_services->rowCount();
    ui->data_services->insertRow(count_row);
    ui->data_services->setItem(count_row,INDEX_COLUMN_COST,item_cost);
    ui->data_services->setItem(count_row,INDEX_COLUMN_NAME,item_name);
}

void MainWindow::slot_add_order_in_data_base(const Order& order)
{
    auto number_new_order = add_order_in_data_base(order);
    if(!number_new_order)
    {
        QMessageBox::warning(this, tr(ERROR), tr(ERROR_MESSAGE));
    }
    else
    {
        QString message = MESSAGE_NUMBER_ORDER + QString::number(number_new_order);
        QMessageBox::information(this,tr(REGISTRATION), tr(message.toStdString().c_str()));
        window_for_give_order->clear_form();
        show_main_window();
    }
}

int MainWindow::add_order_in_data_base(const Order& order)
{
    int number_new_order = 0;
    QSqlQuery query(REQUEST_TAKE_TABLE_ORDERS);
    if(!query.isActive())
    {
        return number_new_order;
    }
    query.last();
    number_new_order = query.value(query.record().indexOf("NUMBER")).toInt();
    ++number_new_order;

    query.first();

    QString request = REQUEST_INSERT_ORDERS;
    request = request.arg(number_new_order);
    request = request.arg(order.get_name_client());
    request = request.arg(order.get_name_worker());
    auto &date = order.get_date();
    request = request.arg(QString::number(date.date().year()) + QChar('.') +
                          QString::number(date.date().month()) + QChar('.') +
                          QString::number(date.date().day()));
    request = request.arg(order.get_status());
    request = request.arg(order.get_cost());
    request = request.arg(number_new_order);
    request = request.arg(order.get_discount());
    if(!query.exec(request))
    {
        return 0;
    }
    request = QString(REQUEST_CREATE_TABLE_ORDER).arg(number_new_order);
    if(!query.exec(request))
    {
        return 0;
    }
    auto &services = order.get_services();
    for(int i = 0; i < services.size(); i++)
    {
        request = REQUEST_INSERT_SERVICE_ORDER;
        request = request.arg(number_new_order);
        request = request.arg(services[i].cost);
        request = request.arg(services[i].count);
        request = request.arg(services[i].name_service);
        if(!query.exec(request))
        {
            return 0;
        }
    }
    return number_new_order;
}

void MainWindow::read_file_data()
{
    QSqlQuery query(REQUESTE_TAKE_SERVICES);
    if(!data.isOpen() || !query.isActive())
    {
        ui->statusBar->setWindowTitle(ERROR_OPEN_DATA_BASE);
        return;
    }
    else
    {
        ui->data_services->clearContents();
        ui->data_services->setRowCount(0);
        ui->statusBar->clearMessage();
    }

    int count_row = 0;
    QSqlRecord record = query.record();
    QTableWidgetItem *item_cost = nullptr;
    QTableWidgetItem *item_name = nullptr;
    while(query.next())
    {
        item_cost = new QTableWidgetItem(query.value(record.indexOf(COLUMN_PRICE)).toString());
        item_name = new QTableWidgetItem(query.value(record.indexOf(COLUMN_NAME)).toString());

        count_row = ui->data_services->rowCount();
        ui->data_services->insertRow(count_row);
        ui->data_services->setItem(count_row,INDEX_COLUMN_COST,item_cost);
        ui->data_services->setItem(count_row,INDEX_COLUMN_NAME,item_name);
    }
}

void MainWindow::read_settings()
{
    auto key = QString(NAME_GROUP_DATA_BASE_SETTINGS) +
            '/' +
            SETTINGS_VALUE_PATH_DATA_BASE;
    auto path = _settings.value(key).toString();
    if(path == ERROR_SETTINGS)
    {
        QFile ini_file(NAME_FILE_SETTINGS);
        ini_file.open(QIODevice::NewOnly);
        if(ini_file.isOpen())
        {
            ini_file.close();
            _settings.setValue(key,NAME_DEFAULT_DATA_BASE);
            path = NAME_DEFAULT_DATA_BASE;
        }
        else
        {
            QMessageBox::warning(this,ERROR,ERROR_SETTINGS);
        }
    }
    window_for_show_options_data_base->set_path_data_base(path);
    data.setDatabaseName(path);
}

void MainWindow::upload_table(int index, const QString &name, double price)
{
    ui->data_services->item(index,INDEX_COLUMN_COST)->setText(QString::number(price));
    ui->data_services->item(index,INDEX_COLUMN_NAME)->setText(name);
}

void MainWindow::upload_table(const QVector<int>& index_deleted_items)
{
    for(auto index : index_deleted_items)
    {
        ui->data_services->removeRow(index);
    }
}


void MainWindow::on_options_clicked()
{
    if(_access != ADMIN)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }
    window_for_options->show();
    this->close();
}

void MainWindow::on_show_data_button_clicked()
{
    if(_access != ADMIN &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }

    window_for_show_data->show();
    window_for_show_data->set_workers(window_for_workers->get_names_workers());
    this->close();
}

void MainWindow::on_workers_button_clicked()
{
    if(_access != ADMIN &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,ERROR,ERROR_ACCESS);
        return;
    }
    window_for_workers->show();
    this->close();
}

