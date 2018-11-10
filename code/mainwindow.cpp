#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _name_file_data("data")
{

    window_for_give_order=new Form_For_Give_Order;
    window_for_add_service=new Form_For_Add_Service;
    window_for_change_service=new Form_For_Change_Service;
    window_for_delete_service=new Form_For_Delete_Service;
    window_for_show_order = new Form_For_Show_Order;

    connect(window_for_show_order,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_give_order,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_add_service,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_add_service,SIGNAL(new_data()),SLOT(add_service()));
    connect(window_for_delete_service,SIGNAL(to_main_window()),SLOT(show_main_window()));
    connect(window_for_delete_service,SIGNAL(changed_table(QVector<int>)),SLOT(upload_table(QVector<int>)));
    connect(window_for_change_service,SIGNAL(changed_data(int)),SLOT(upload_table(int)));
    connect(window_for_change_service,SIGNAL(to_main_window()),SLOT(show_main_window()));

    ui->setupUi(this);

    read_file_data();
}

MainWindow::~MainWindow()
{
    write_file_data();

    while(ui->data_services->rowCount())
    {
        delete ui->data_services->item(0,0);//
        delete ui->data_services->item(0,1);//
        ui->data_services->removeRow(0);
    }

    delete ui;
    delete window_for_add_service;
    delete window_for_change_service;
    delete window_for_delete_service;
    delete window_for_give_order;
    delete window_for_show_order;
}

void MainWindow::on_give_order_button_clicked()
{
    window_for_give_order->set_table(ui->data_services);
    window_for_give_order->show();
    this->close();
}

void MainWindow::on_add_service_button_clicked()
{
    window_for_add_service->show();
    this->close();
}

void MainWindow::on_show_order_button_clicked()
{
    window_for_show_order->show();
    this->close();
}

void MainWindow::on_change_service_button_clicked()
{
    window_for_change_service->set_table(ui->data_services);
    window_for_change_service->show();
    this->close();
}

void MainWindow::on_delete_service_button_clicked()
{
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

    QTableWidgetItem *item_cost = new QTableWidgetItem(window_for_add_service->get_cost_service());
    QTableWidgetItem *item_name = new QTableWidgetItem(window_for_add_service->get_name_service());

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
    QFile file(_name_file_data);
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_5_2);

    if(!file.open(QIODevice::ReadOnly))
    {
        ui->statusBar->setWindowTitle(QString("Cannot read file."));
        return;
    }

    int count_services = 0;
    QString cost;
    QString name;

    stream>>count_services;

    for(int i=0; i<count_services; i++)
    {
        stream>>cost;
        stream>>name;

        QTableWidgetItem *item_cost = new QTableWidgetItem(cost);
        QTableWidgetItem *item_name = new QTableWidgetItem(name);

        ui->data_services->insertRow(ui->data_services->rowCount());
        ui->data_services->setItem(ui->data_services->rowCount()-1,0,item_cost);
        ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_name);
    }
    file.close();
}

void MainWindow::upload_table(int index)
{
    const QTableWidget *table = window_for_change_service->get_table();
    ui->data_services->item(index,0)->setText(table->item(index,0)->text());
    ui->data_services->item(index,1)->setText(table->item(index,1)->text());
}

void MainWindow::upload_table(const QVector<int>& index_deleted_items)
{
    int index = index_deleted_items.size()-1;
    while(index>=0)
    {
        ui->data_services->removeRow(index_deleted_items[index]);
        index--;
    }
}

