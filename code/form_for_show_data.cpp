#include "form_for_show_data.h"
#include "ui_form_for_show_data.h"

FormForShowData::FormForShowData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Data)
{
    ui->setupUi(this);
}

FormForShowData::~FormForShowData()
{
    delete ui;
}
