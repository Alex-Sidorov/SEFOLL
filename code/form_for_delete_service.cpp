#include "form_for_delete_service.h"
#include "ui_form_for_delete_service.h"

const int FormForDeleteService::INDEX_COLUMN_COST = 0;
const int FormForDeleteService::INDEX_COLUMN_NAME = 1;
const int FormForDeleteService::INDEX_FIRST_ROW = 0;

const char* FormForDeleteService::MESSAGE_REQUEST_FOR_DELETE = "Вы уверены, что хотите удалить выбранные элементы?";

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
    int count_row_table = table->rowCount();
    int count_row_data_services = 0;
    for(int i = 0; i < count_row_table; i++)
    {
        QTableWidgetItem *item_cost = new QTableWidgetItem(*(table->item(i,INDEX_COLUMN_COST)));
        QTableWidgetItem *item_name = new QTableWidgetItem(*(table->item(i,INDEX_COLUMN_NAME)));

        count_row_data_services = ui->data_services->rowCount();
        ui->data_services->insertRow(count_row_data_services);
        ui->data_services->setItem(count_row_data_services,INDEX_COLUMN_COST,item_cost);
        ui->data_services->setItem(count_row_data_services,INDEX_COLUMN_NAME,item_name);
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
    int index_item = index.row();
    if(ui->data_services->item(index_item,INDEX_COLUMN_NAME)->backgroundColor()!=Qt::blue)
    {
        ui->data_services->item(index_item,INDEX_COLUMN_COST)->setBackgroundColor(QColor(Qt::blue));
        ui->data_services->item(index_item,INDEX_COLUMN_NAME)->setBackgroundColor(QColor(Qt::blue));
        _count_delete_items++;
    }
    else
    {
        ui->data_services->item(index_item,INDEX_COLUMN_COST)->setBackgroundColor(QColor(Qt::white));
        ui->data_services->item(index_item,INDEX_COLUMN_NAME)->setBackgroundColor(QColor(Qt::white));
        _count_delete_items--;
    }

    if(_count_delete_items == 0)
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

    while(_count_delete_items != 0)
    {
        if(ui->data_services->item(index,INDEX_COLUMN_NAME)->backgroundColor()==Qt::blue)
        {
            index_deleted_item.push_back(index_main_table);
            delete ui->data_services->item(index,INDEX_COLUMN_COST);
            delete ui->data_services->item(index,INDEX_COLUMN_NAME);
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
        delete ui->data_services->item(INDEX_FIRST_ROW,INDEX_COLUMN_COST);
        delete ui->data_services->item(INDEX_FIRST_ROW,INDEX_COLUMN_NAME);
        ui->data_services->removeRow(INDEX_FIRST_ROW);
    }
}

int FormForDeleteService::request_for_delete()const
{
    QMessageBox message;
    message.setText(MESSAGE_REQUEST_FOR_DELETE);
    message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    return message.exec();
}
