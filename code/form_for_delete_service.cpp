#include "form_for_delete_service.h"
#include "ui_form_for_delete_service.h"

const int FormForDeleteService::INDEX_COLUMN_COST = 0;
const int FormForDeleteService::INDEX_COLUMN_NAME = 1;
const int FormForDeleteService::INDEX_FIRST_ROW =   0;

const Qt::GlobalColor FormForDeleteService::SELECT_FIELD_COLOR  = Qt::blue;
const Qt::GlobalColor FormForDeleteService::DEFAULT_FIELD_COLOR = Qt::white;

const char* FormForDeleteService::MESSAGE_REQUEST_FOR_DELETE =
        "Вы уверены, что хотите удалить выбранные элементы?";

FormForDeleteService::FormForDeleteService(AbstractServicesWorker *data_base, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Delete_Service),
    m_data_base(data_base)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":icons/icon.png"));
}

void FormForDeleteService::set_table(const QTableWidget *table)
{
    int count_row_table = table->rowCount();
    int count_row_data_services = 0;
    QTableWidgetItem *item_cost = nullptr;
    QTableWidgetItem *item_name = nullptr;
    for(int i = 0; i < count_row_table; i++)
    {
        item_cost = new QTableWidgetItem(*(table->item(i,INDEX_COLUMN_COST)));
        item_name = new QTableWidgetItem(*(table->item(i,INDEX_COLUMN_NAME)));

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
    if(ui->data_services->item(index_item,INDEX_COLUMN_NAME)->backgroundColor()!=SELECT_FIELD_COLOR)
    {
        ui->data_services->item(index_item,INDEX_COLUMN_COST)->setBackgroundColor(SELECT_FIELD_COLOR);
        ui->data_services->item(index_item,INDEX_COLUMN_NAME)->setBackgroundColor(SELECT_FIELD_COLOR);
        index_deleted_item.push_back(index_item);
    }
    else
    {
        ui->data_services->item(index_item,INDEX_COLUMN_COST)->setBackgroundColor(DEFAULT_FIELD_COLOR);
        ui->data_services->item(index_item,INDEX_COLUMN_NAME)->setBackgroundColor(DEFAULT_FIELD_COLOR);
        index_deleted_item.removeAll(index_item);
    }

    if(index_deleted_item.size() == 0)
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
        ui->delete_button->setEnabled(false);
        emit changed_table(index_deleted_item);
        index_deleted_item.clear();
    }
}

void FormForDeleteService::delete_items()
{
    if(m_data_base)
    {
        for(auto &index : index_deleted_item)
        {
            auto name = ui->data_services->item(index,INDEX_COLUMN_NAME)->text();
            auto price = ui->data_services->item(index,INDEX_COLUMN_COST)->text().toDouble();
            if(!m_data_base->delete_service(name, price))
            {
                return;
            }
            ui->data_services->removeRow(index);
        }
    }
}

void FormForDeleteService::clear_form()
{
    ui->data_services->clearContents();
    ui->data_services->setRowCount(0);
    index_deleted_item.clear();
}

int FormForDeleteService::request_for_delete()const
{
    QMessageBox message;
    message.setText(MESSAGE_REQUEST_FOR_DELETE);
    message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    return message.exec();
}
