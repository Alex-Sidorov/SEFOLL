#include "form_for_change_service.h"
#include "ui_form_for_change_service.h"

const int FormForChangeService::INDEX_COLUMN_COST = 0;
const int FormForChangeService::INDEX_COLUMN_NAME = 1;
const int FormForChangeService::INDEX_FIRST_ROW =   0;

FormForChangeService::FormForChangeService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Change_Service)
{
    _index_record = 0;

     ui->setupUi(this);

    connect(ui->cost,SIGNAL(valueChanged(double)),this,SLOT(slot_fields_form_changed()));
    connect(ui->name,SIGNAL(textChanged(QString)),this,SLOT(slot_fields_form_changed()));
}

void FormForChangeService::set_table(const QTableWidget *table)
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

const QTableWidget* FormForChangeService::get_table()const
{
    return ui->data_services;
}

void FormForChangeService::on_back_button_clicked()
{
    this->close();
    clear_form();
    emit to_main_window();
}

void FormForChangeService::on_data_services_clicked(const QModelIndex &index)
{
    ui->name->setEnabled(true);
    ui->cost->setEnabled(true);

    _index_record = index.row();
    ui->name->setText(ui->data_services->item(_index_record,INDEX_COLUMN_NAME)->text());
    ui->cost->setValue(ui->data_services->
                       item(_index_record,INDEX_COLUMN_COST)->
                       text().replace(',','.').toDouble());

}

void FormForChangeService::clear_form()const
{
    ui->name->clear();
    ui->cost->setValue(0);
    ui->name->setEnabled(false);
    ui->cost->setEnabled(false);
    ui->data_services->setRowCount(0);
}

bool FormForChangeService::is_empty_form()const
{
    return !ui->name->text().isEmpty() && !ui->cost->value() == 0;
}

void FormForChangeService::slot_fields_form_changed()
{
    if(is_empty_form())
    {
        ui->enter_change_button->setEnabled(true);
    }
    else
    {
        ui->enter_change_button->setEnabled(false);
    }
}

void FormForChangeService::on_enter_change_button_clicked()
{
    ui->data_services->item(_index_record,INDEX_COLUMN_COST)->setText(ui->cost->text());
    ui->data_services->item(_index_record,INDEX_COLUMN_NAME)->setText(ui->name->text());
    emit changed_data(_index_record);
}
