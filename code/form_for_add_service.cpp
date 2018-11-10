#include "form_for_add_service.h"
#include "ui_form_for_add_service.h"

Form_For_Add_Service::Form_For_Add_Service(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Add_Service)
{
    ui->setupUi(this);
    connect(ui->ok_button, SIGNAL(clicked()), this, SIGNAL(new_data()));
    connect(this,SIGNAL(new_data()),this,SLOT(close()));

}

Form_For_Add_Service::~Form_For_Add_Service()
{
    delete ui;
}

void Form_For_Add_Service::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}

void Form_For_Add_Service::on_name_service_textChanged(const QString &name)
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

void Form_For_Add_Service::on_cost_service_valueChanged(const QString &cost)
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

void Form_For_Add_Service::clear_form()const
{
    ui->name_service->clear();
    ui->cost_service->clear();
}

void Form_For_Add_Service::show()
{
    clear_form();
    QWidget::show();
}

QString Form_For_Add_Service::get_name_service()const
{
    return ui->name_service->text();
}

QString Form_For_Add_Service::get_cost_service()const
{
    return ui->cost_service->text();
}

