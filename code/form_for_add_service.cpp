#include "form_for_add_service.h"
#include "ui_form_for_add_service.h"

FormForAddService::FormForAddService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Add_Service)
{
    ui->setupUi(this);
    connect(ui->ok_button, SIGNAL(clicked()), this, SIGNAL(new_data()));
    connect(this,SIGNAL(new_data()),this,SLOT(close()));

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

void FormForAddService::on_name_service_textChanged(const QString &name)
{
    if(!name.isEmpty() && !ui->cost_service->text().isEmpty())
    {
        ui->ok_button->setEnabled(true);
    }
    else
    {
        ui->ok_button->setEnabled(false);
    }
}

void FormForAddService::on_cost_service_valueChanged(const QString &cost)
{
    if(!cost.isEmpty() && !ui->name_service->text().isEmpty())
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

