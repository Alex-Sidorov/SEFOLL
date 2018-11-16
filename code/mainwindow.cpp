#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _name_file_data("data.sqlite"),
    _access(GUEST)
{

    window_for_give_order = new FormForGiveOrder;
    window_for_add_service = new FormForAddService;
    window_for_change_service = new FormForChangeService;
    window_for_delete_service = new FormForDeleteService;
    window_for_show_order = new FormForShowOrder;
    window_for_options = new FormForOptions;

    connect(window_for_show_order,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_give_order,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_add_service,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_add_service,SIGNAL(new_data()),SLOT(add_service()));
    connect(window_for_delete_service,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_delete_service,SIGNAL(changed_table(QVector<int>)),SLOT(upload_table(QVector<int>)));
    connect(window_for_change_service,SIGNAL(changed_data(int)),SLOT(upload_table(int)));
    connect(window_for_change_service,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_options,SIGNAL(to_main_window()),SLOT(show_main_window()));

    ui->setupUi(this);

    data = QSqlDatabase::addDatabase("QSQLITE");
    data.setDatabaseName(_name_file_data);
    read_file_data();
}

MainWindow::~MainWindow()
{
    data.close();
    while(ui->data_services->rowCount())
    {
        delete ui->data_services->item(0,0);
        delete ui->data_services->item(0,1);
        ui->data_services->removeRow(0);
    }

    delete ui;
    delete window_for_options;
    delete window_for_add_service;
    delete window_for_change_service;
    delete window_for_delete_service;
    delete window_for_give_order;
    delete window_for_show_order;
}

void MainWindow::set_access(Access access)
{
    _access = access;
}

void MainWindow::on_give_order_button_clicked()
{
    if(_access != ADMIN &&
       _access != WORKER_TAKE_ORDER &&
       _access != CHIEF)
    {
        QMessageBox::warning(this,"Ошибка","Недостаточно прав доступа");
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
        QMessageBox::warning(this,"Ошибка","Недостаточно прав доступа");
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
        QMessageBox::warning(this,"Ошибка","Недостаточно прав доступа");
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
        QMessageBox::warning(this,"Ошибка","Недостаточно прав доступа");
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
        QMessageBox::warning(this,"Ошибка","Недостаточно прав доступа");
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
    QString request = "INSERT INTO services(price, name) VALUES(%1, '%2');";
    request = request.arg(cost.replace(QChar(','),QChar('.'))).arg(name);
    QSqlQuery query;
    if(!query.exec(request))
    {
        ui->statusBar->setWindowTitle(QString("Error add service."));
        return;
    }

    QTableWidgetItem *item_cost = new QTableWidgetItem(cost);
    QTableWidgetItem *item_name = new QTableWidgetItem(name);

    ui->data_services->insertRow(ui->data_services->rowCount());
    ui->data_services->setItem(ui->data_services->rowCount()-1,0,item_cost);
    ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_name);
}

void MainWindow::write_file_data()
{
    QFile file(_name_file_data);
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_5_2);

    if(!file.open(QIODevice::WriteOnly))
    {
        ui->statusBar->setWindowTitle(QString("Cannot write file."));
        return;
    }

    stream<<ui->data_services->rowCount();
    for(int i=0; i<ui->data_services->rowCount(); i++)
    {
        stream<<ui->data_services->item(i,0)->text()
              <<ui->data_services->item(i,1)->text();
    }
    file.close();
}

void MainWindow::read_file_data()
{
    data.open();
    if(!data.isOpen())
    {
        ui->statusBar->setWindowTitle(QString("Cannot read data."));
        return;
    }

    QSqlQuery query("SELECT * FROM services");
    if(!query.isActive())
    {
        ui->statusBar->setWindowTitle(QString("Cannot read data."));
        return;
    }

    QSqlRecord record = query.record();
    while(query.next())
    {
        QTableWidgetItem *item_cost = new QTableWidgetItem(query.value(record.indexOf("price")).toString());
        QTableWidgetItem *item_name = new QTableWidgetItem(query.value(record.indexOf("name")).toString());

        ui->data_services->insertRow(ui->data_services->rowCount());
        ui->data_services->setItem(ui->data_services->rowCount()-1,0,item_cost);
        ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_name);
    }
}

void MainWindow::upload_table(int index)
{
    const QTableWidget *table = window_for_change_service->get_table();
    QString cost = table->item(index,0)->text();
    cost.replace(QChar(','),QChar('.'));
    QString name = table->item(index,1)->text();

    QString request = "UPDATE services SET price = %1 WHERE price = %2 AND name = '%3';";
    request = request.arg(cost);
    request = request.arg(ui->data_services->item(index,0)->text());
    request = request.arg(ui->data_services->item(index,1)->text());
    QSqlQuery query;
    if(!query.exec(request))
    {
        ui->statusBar->setWindowTitle(QString("Cannot changed data."));
        return;
    }
    request = "UPDATE services SET name = '%1' WHERE price = %2 AND name = '%3';";
    request = request.arg(name);
    request = request.arg(cost);
    request = request.arg(ui->data_services->item(index,1)->text());
    if(!query.exec(request))
    {
        ui->statusBar->setWindowTitle(QString("Cannot changed data."));
        return;
    }

    ui->data_services->item(index,0)->setText(cost);
    ui->data_services->item(index,1)->setText(name);
}

void MainWindow::upload_table(const QVector<int>& index_deleted_items)
{
    int index = index_deleted_items.size()-1;
    QString request;
    QSqlQuery query;
    while(index>=0)
    {
        request = "DELETE FROM services WHERE price = %1 AND name = '%2'";
        request = request.arg(ui->data_services->item(index_deleted_items[index],0)->text());
        request = request.arg(ui->data_services->item(index_deleted_items[index],1)->text());
        if(!query.exec(request))
        {
            ui->statusBar->setWindowTitle(QString("Cannot delete data."));
            return;
        }
        index--;
    }
    index = index_deleted_items.size()-1;
    while(index>=0)
    {
        ui->data_services->removeRow(index_deleted_items[index]);
        index--;
    }
}


void MainWindow::on_options_clicked()
{
    if(_access != ADMIN)
    {
        QMessageBox::warning(this,"Ошибка","Недостаточно прав доступа");
        return;
    }
    window_for_options->show();
    this->close();
}
