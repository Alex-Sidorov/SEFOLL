#include "form_for_add_service.h"
#include "ui_form_for_add_service.h"

FormForAddService::FormForAddService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Add_Service)
{
    ui->setupUi(this);
    connect(ui->ok_button, SIGNAL(clicked()), this, SIGNAL(new_data()));
    connect(this,SIGNAL(new_data()),this,SLOT(close()));
    connect(ui->name_service,SIGNAL(textChanged(QString)),this,SLOT(slot_fields_form_changed()));
    connect(ui->cost_service,SIGNAL(valueChanged(double)),this,SLOT(slot_fields_form_changed()));
}

FormForAddService::~FormForAddService()
{
    delete ui;
}

void FormForAddService::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}

bool FormForAddService::is_empty_form()const
{
    return !ui->name_service->text().isEmpty() && !ui->cost_service->value() == 0;
}

void FormForAddService::slot_fields_form_changed()
{
    if(is_empty_form())
    {
        ui->ok_button->setEnabled(true);
    }
    else
    {
        ui->ok_button->setEnabled(false);
    }
}

void FormForAddService::clear_form()const
{
    ui->name_service->clear();
    ui->cost_service->clear();
}

void FormForAddService::show()
{
    clear_form();
    QWidget::show();
}

QString FormForAddService::get_name_service()const
{
    return ui->name_service->text();
}

QString FormForAddService::get_cost_service()const
{
    return ui->cost_service->text();
}

