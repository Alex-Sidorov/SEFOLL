#include "form_for_login.h"
#include "ui_form_for_login.h"

ForForLogin::ForForLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_For_Login)
{
    _close = false;
    _access = GUEST;
    ui->setupUi(this);
    connect(ui->ok,SIGNAL(clicked()),SLOT(input_ok()));
}

void ForForLogin::show()
{
    _close = true;
    ui->id->clear();
    ui->password->clear();
    ui->error->clear();
    QWidget::show();
}

void ForForLogin::input_ok()
{
    QString password = ui->password->text();
    QString id = ui->id->text();
    if(!Security::check_access(id, password, _access))
    {
        ui->error->setText("Ошибка. Проверьте id и пароль.");
    }
    _close = false;
    QWidget::close();
}

bool ForForLogin::is_close()const
{
    return _close;
}

ForForLogin::~ForForLogin()
{
    delete ui;
}

Access ForForLogin::get_access()const
{
    return _access;
}

void ForForLogin::on_button_for_guest_clicked()
{
    _close = false;
    QWidget::close();
}
