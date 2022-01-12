#include "form_for_add_service.h"
#include "ui_form_for_add_service.h"

FormForAddService::FormForAddService(AbstractServicesWorker* database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Add_Service),
    m_database(database)
{
    ui->setupUi(this);
    connect(this,SIGNAL(new_data()),this,SLOT(close()));
    connect(ui->name_service,SIGNAL(textChanged(QString)),this,SLOT(slot_fields_form_changed()));
    connect(ui->cost_service,SIGNAL(valueChanged(double)),this,SLOT(slot_fields_form_changed()));

    setWindowIcon(QIcon(":icons/icon.png"));
}

void FormForAddService::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}

bool FormForAddService::is_empty_form()const
{
    return ui->name_service->text().isEmpty() || ui->cost_service->value() == 0.0;
}

void FormForAddService::slot_fields_form_changed()
{
    if(!is_empty_form())
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
    ui->cost_service->setValue(0);
}

void FormForAddService::show()
{
    clear_form();
    QWidget::show();
}

void FormForAddService::on_ok_button_clicked()
{
    if(m_database)
    {
        m_database->add_service(ui->name_service->text(), ui->cost_service->value());
        this->close();
        emit new_data();

    }
}

QString FormForAddService::get_name_service()const
{
    return ui->name_service->text();
}

double FormForAddService::get_cost_service()const
{
    return ui->cost_service->value();
}

