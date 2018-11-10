#include "form_for_login.h"
#include "ui_form_for_login.h"

Form_For_Login::Form_For_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Login)
{
    _close = false;
    ui->setupUi(this);
    connect(ui->ok,SIGNAL(clicked()),SLOT(input_ok()));
}

void Form_For_Login::show()
{
    _close = true;
    QWidget::show();
}

void Form_For_Login::input_ok()
{
     _close = false;
     QWidget::close();
}

bool Form_For_Login::is_close()const
{
    return _close;
}

Form_For_Login::~Form_For_Login()
{
    delete ui;
}
