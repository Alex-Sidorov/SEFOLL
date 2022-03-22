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

const char* MainWindow::NAME_FILE_SETTINGS = "settings.conf";

const char* MainWindow::NAME_GROUP_DATA_BASE_SETTINGS = "data_base";
const char* MainWindow::SETTINGS_VALUE_PATH_DATA_BASE = "path";

const char* MainWindow::NAME_DEFAULT_DATA_BASE = "data.sqlite";
const char* MainWindow::TYPE_DATA_BASE = "QSQLITE";
const char* MainWindow::COLUMN_PRICE = "price";
const char* MainWindow::COLUMN_NAME =  "name";

const int MainWindow::INDEX_COLUMN_COST = 0;
const int MainWindow::INDEX_COLUMN_NAME = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),    
    data(QSqlDatabase::addDatabase(TYPE_DATA_BASE)),
    window_for_give_order(new FormForGiveOrder(&m_data_base)),
    window_for_change_service(new FormForChangeService(&m_data_base)),
    window_for_add_service(new FormForAddService(&m_data_base)),
    window_for_delete_service( new FormForDeleteService(&m_data_base)),
    window_for_show_order(new FormForShowOrder(&m_data_base)),
    window_for_options(new FormForOptions(&m_data_base)),
    window_for_show_data(nullptr),
    window_for_show_options_data_base(new FormForOptionsDataBase(&m_data_base)),
    window_for_workers(new FormForWorkers(&m_data_base)),
    _access(GUEST),
    _name_file_data(NAME_DEFAULT_DATA_BASE),
    _settings(NAME_FILE_SETTINGS, QSettings::IniFormat)
{
    connect(window_for_show_order.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_give_order.data(),SIGNAL(to_main_window()),SLOT(show_main_window()));
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

    window_for_show_data = QSharedPointer<FormForShowData>(new FormForShowData(&m_data_base, ui->data_services));
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

const DataBaseWorker* MainWindow::getDataBase() const
{
    return &m_data_base;
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

    QTableWidgetItem *item_cost = new QTableWidgetItem(QString::number(cost));
    QTableWidgetItem *item_name = new QTableWidgetItem(name);

    int count_row = ui->data_services->rowCount();
    ui->data_services->insertRow(count_row);
    ui->data_services->setItem(count_row,INDEX_COLUMN_COST,item_cost);
    ui->data_services->setItem(count_row,INDEX_COLUMN_NAME,item_name);
}

void MainWindow::read_file_data()
{
    auto services = m_data_base.read_services();
    if(services.isEmpty())
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
    QTableWidgetItem *item_cost = nullptr;
    QTableWidgetItem *item_name = nullptr;
    for(const auto& service : qAsConst(services))
    {
        item_cost = new QTableWidgetItem(QString::number(service.second));
        item_name = new QTableWidgetItem(service.first);

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

