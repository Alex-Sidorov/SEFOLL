#include "form_for_show_data.h"
#include "ui_form_for_show_data.h"

Form_For_Show_Data::Form_For_Show_Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Show_Data)
{
    ui->setupUi(this);
}

Form_For_Show_Data::~Form_For_Show_Data()
{
    delete ui;
}
