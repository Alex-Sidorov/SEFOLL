#include "form_for_options.h"
#include "ui_form_for_options.h"

Form_for_options::Form_for_options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_for_options)
{
    ui->setupUi(this);
}

Form_for_options::~Form_for_options()
{
    delete ui;
}
