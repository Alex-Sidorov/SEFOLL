#include "form_for_login.h"
#include "ui_form_for_login.h"

FormForLogin::FormForLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForLogin)
{
    _close = false;
    _access = GUEST;
    ui->setupUi(this);
    connect(ui->ok,SIGNAL(clicked()),SLOT(input_ok()));
}

void FormForLogin::show()
{
    _close = true;
    ui->id->clear();
    ui->password->clear();
    ui->error->clear();
    QWidget::show();
}

void FormForLogin::input_ok()
{
    QString password = ui->password->text();
    QString id = ui->id->text();
    if(!Security::check_access(id, password, _access))
    {
        ui->error->setText("Ошибка. Проверьте id и пароль.");
        return;
    }
    _close = false;
    QWidget::close();
}

bool FormForLogin::is_close()const
{
    return _close;
}

FormForLogin::~FormForLogin()
{
    delete ui;
}

Access FormForLogin::get_access()const
{
    return _access;
}

void FormForLogin::on_button_for_guest_clicked()
{
    _close = false;
    QWidget::close();
}
