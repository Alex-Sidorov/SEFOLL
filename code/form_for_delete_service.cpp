#include "form_for_delete_service.h"
#include "ui_form_for_delete_service.h"

FormForDeleteService::FormForDeleteService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Delete_Service)
{
    ui->setupUi(this);
    _count_delete_items = 0;
}

FormForDeleteService::~FormForDeleteService()
{
    delete ui;
}

void FormForDeleteService::set_table(const QTableWidget *table)
{
    for(int i=0; i<table->rowCount(); i++)
    {
        QTableWidgetItem *item_cost = new QTableWidgetItem(*(table->item(i,0)));
        QTableWidgetItem *item_name = new QTableWidgetItem(*(table->item(i,1)));

        ui->data_services->insertRow(ui->data_services->rowCount());
        ui->data_services->setItem(ui->data_services->rowCount()-1,0,item_cost);
        ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_name);
    }
}

void FormForDeleteService::on_back_button_clicked()
{
    clear_form();
    this->close();
    emit to_main_window();
}

void FormForDeleteService::on_data_services_clicked(const QModelIndex &index)
{
    if(ui->data_services->item(index.row(),0)->backgroundColor()!=Qt::blue)
    {
        ui->data_services->item(index.row(),0)->setBackgroundColor(QColor(Qt::blue));
        ui->data_services->item(index.row(),1)->setBackgroundColor(QColor(Qt::blue));
        _count_delete_items++;

    }
    else
    {
        ui->data_services->item(index.row(),0)->setBackgroundColor(QColor(Qt::white));
        ui->data_services->item(index.row(),1)->setBackgroundColor(QColor(Qt::white));
        _count_delete_items--;
    }

    if(_count_delete_items==0)
    {
        ui->delete_button->setEnabled(false);
    }
    else
    {
        ui->delete_button->setEnabled(true);
    }
}

void FormForDeleteService::on_delete_button_clicked()
{

    if(request_for_delete() == QMessageBox::Ok)
    {
        delete_items();
        _count_delete_items = 0;
        ui->delete_button->setEnabled(false);
    }
    emit changed_table(index_deleted_item);
}

void FormForDeleteService::delete_items()
{
    index_deleted_item.clear();
    index_deleted_item.reserve(_count_delete_items);

    int index_main_table=0;
    int index = 0;

    while(_count_delete_items!=0)
    {
        if(ui->data_services->item(index,0)->backgroundColor()==Qt::blue)
        {
            index_deleted_item.push_back(index_main_table);

            delete ui->data_services->item(index,0);//
            delete ui->data_services->item(index,1);//

            ui->data_services->removeRow(index);
            _count_delete_items--;
        }
        else
        {
            index++;
        }
        index_main_table++;
    }
}

void FormForDeleteService::clear_form()const
{
    while(ui->data_services->rowCount())
    {
        delete ui->data_services->item(0,0);//
        delete ui->data_services->item(0,1);//
        ui->data_services->removeRow(0);
    }
}

int FormForDeleteService::request_for_delete()const
{
    QMessageBox message;
    message.setText("Вы уверены, что хотите удалить выбранные элементы?");
    message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    return message.exec();
}
