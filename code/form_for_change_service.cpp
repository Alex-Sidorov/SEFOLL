#include "form_for_change_service.h"
#include "ui_form_for_change_service.h"

FormForChangeService::FormForChangeService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Change_Service)
{
    _index_record = 0;
    ui->setupUi(this);
}

void FormForChangeService::set_table(const QTableWidget *table)
{
    for(int i = 0; i < table->rowCount(); i++)
    {
        QTableWidgetItem *item_cost = new QTableWidgetItem(*(table->item(i,0)));
        QTableWidgetItem *item_name = new QTableWidgetItem(*(table->item(i,1)));

        ui->data_services->insertRow(ui->data_services->rowCount());
        ui->data_services->setItem(ui->data_services->rowCount()-1,0,item_cost);
        ui->data_services->setItem(ui->data_services->rowCount()-1,1,item_name);
    }
}

const QTableWidget* FormForChangeService::get_table()const
{
    return ui->data_services;
}

FormForChangeService::~FormForChangeService()
{
    delete ui;
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

    ui->name->setText(ui->data_services->item(_index_record,1)->text());
    ui->cost->setValue(ui->data_services->
                       item(_index_record,0)->
                       text().replace(QChar(','),QChar('.')).toDouble());

}

void FormForChangeService::clear_form()const
{
    ui->name->clear();
    ui->cost->clear();

    ui->name->setEnabled(false);
    ui->cost->setEnabled(false);

    while(ui->data_services->rowCount())
    {
        delete ui->data_services->item(0,0);//
        delete ui->data_services->item(0,1);//
        ui->data_services->removeRow(0);
    }
}

void FormForChangeService::on_name_textChanged(const QString &name)
{
    if(!name.isEmpty() && !ui->cost->text().isEmpty())
    {
        ui->enter_change_button->setEnabled(true);
    }
    else
    {
        ui->enter_change_button->setEnabled(false);
    }
}

void FormForChangeService::on_cost_valueChanged(const QString &value)
{
    if(!value.isEmpty() && !ui->name->text().isEmpty())
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
    ui->data_services->item(_index_record,0)->setText(ui->cost->text());
    ui->data_services->item(_index_record,1)->setText(ui->name->text());
    emit changed_data(_index_record);
}
