#include "mainwindow.h"
#include "ui_mainwindow.h"

const char* MainWindow::ERROR =                "Ошибка";
const char* MainWindow::ERROR_ACCESS =         "Недостаточно прав доступа";
const char* MainWindow::ERROR_ADD_SERVICE =    "В данный момент нельзя добавить данные.";
const char* MainWindow::ERROR_CHANGE_SERVICE = "В данный момент нельзя изменить данные.";
const char* MainWindow::ERROR_OPEN_DATA_BASE = "В данный момент база данных недоступна.";
const char* MainWindow::ERROR_SETTINGS =       "Ошибка при чтении настроек.";

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

const char* MainWindow::COLUMN_PRICE = "price";
const char* MainWindow::COLUMN_NAME =  "name";

const int MainWindow::INDEX_COLUMN_COST = 0;
const int MainWindow::INDEX_COLUMN_NAME = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    window_for_give_order(new FormForGiveOrder),
    window_for_change_service(new FormForChangeService),
    window_for_add_service(new FormForAddService),
    window_for_delete_service( new FormForDeleteService),
    window_for_show_order(new FormForShowOrder),
    window_for_options(new FormForOptions),
    window_for_show_data(nullptr),
    window_for_show_options_data_base(new FormForOptionsDataBase),
    _access(GUEST),
    _name_file_data(NAME_DEFAULT_DATA_BASE),
    data(QSqlDatabase::addDatabase(TYPE_DATA_BASE)),
    _settings(NAME_FILE_SETTINGS,QSettings::IniFormat)
{
    connect(window_for_show_order.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_give_order.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_add_service.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_add_service.data(),SIGNAL(new_data()),SLOT(add_service()));
    connect(window_for_delete_service.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_delete_service.data(),SIGNAL(changed_table(QVector<int>)),SLOT(upload_table(QVector<int>)));
    connect(window_for_change_service.data(),SIGNAL(changed_data(int)),SLOT(upload_table(int)));
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

    QString cost = window_for_add_service->get_cost_service();
    QString name = window_for_add_service->get_name_service();
    QString request = REQUESTE_DATA_SERVICE;
    request = request.arg(cost.replace(QChar(','),QChar('.'))).arg(name);
    QSqlQuery query;
    if(!query.exec(request))
    {
        QMessageBox::warning(this,ERROR,ERROR_ADD_SERVICE);
        return;
    }

    QTableWidgetItem *item_cost = new QTableWidgetItem(cost);
    QTableWidgetItem *item_name = new QTableWidgetItem(name);

    int count_row = ui->data_services->rowCount();
    ui->data_services->insertRow(count_row);
    ui->data_services->setItem(count_row,INDEX_COLUMN_COST,item_cost);
    ui->data_services->setItem(count_row,INDEX_COLUMN_NAME,item_name);
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

void MainWindow::upload_table(int index)
{
    const QTableWidget *table = window_for_change_service->get_table();
    QString cost = table->item(index,INDEX_COLUMN_COST)->text();
    cost.replace(QChar(','),QChar('.'));
    QString name = table->item(index,INDEX_COLUMN_NAME)->text();

    QString request = REQUESTE_UPDATE_PRICE;
    request = request.arg(cost);
    request = request.arg(ui->data_services->item(index,INDEX_COLUMN_COST)->text());
    request = request.arg(ui->data_services->item(index,INDEX_COLUMN_NAME)->text());
    QSqlQuery query;
    if(!query.exec(request))
    {
        QMessageBox::warning(this,ERROR,ERROR_CHANGE_SERVICE);
        return;
    }
    request = REQUESTE_UPDATE_NAME;
    request = request.arg(name);
    request = request.arg(cost);
    request = request.arg(ui->data_services->item(index,INDEX_COLUMN_NAME)->text());
    if(!query.exec(request))
    {
        QMessageBox::warning(this,ERROR,ERROR_CHANGE_SERVICE);
        return;
    }

    ui->data_services->item(index,INDEX_COLUMN_COST)->setText(cost);
    ui->data_services->item(index,INDEX_COLUMN_NAME)->setText(name);
}

void MainWindow::upload_table(const QVector<int>& index_deleted_items)
{
    int index = index_deleted_items.size() - 1;
    QString request;
    QSqlQuery query;
    while(index >= 0)
    {
        request = REQUESTE_DELETE_SERVICE;
        request = request.arg(ui->data_services->item(index_deleted_items[index],INDEX_COLUMN_COST)->text());
        request = request.arg(ui->data_services->item(index_deleted_items[index],INDEX_COLUMN_NAME)->text());
        if(!query.exec(request))
        {
            QMessageBox::warning(this,ERROR,ERROR_CHANGE_SERVICE);
            return;
        }
        index--;
    }
    index = index_deleted_items.size() - 1;
    while(index >= 0)
    {
        ui->data_services->removeRow(index_deleted_items[index]);
        index--;
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
    this->close();
}
