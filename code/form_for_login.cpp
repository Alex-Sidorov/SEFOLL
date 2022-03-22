#include "form_for_login.h"
#include "ui_form_for_login.h"

const char* FormForLogin::MESSAGE_ERROR = "Ошибка. Проверьте id и пароль.";

FormForLogin::FormForLogin(const AbstractDataUserWorker *dataBase, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForLogin),
    _dataBase(dataBase)
{
    _close = false;
    _access = GUEST;
    ui->setupUi(this);
    connect(ui->ok,SIGNAL(clicked()),SLOT(input_ok()));
    connect(ui->password,SIGNAL(returnPressed()),SLOT(input_ok()));

    setWindowIcon(QIcon(":icons/icon.png"));
}

void FormForLogin::clear_form()const
{
    ui->id->clear();
    ui->password->clear();
    ui->error->clear();
}

void FormForLogin::show()
{
    _close = true;
    QWidget::show();
}

void FormForLogin::input_ok()
{
    if(_dataBase)
    {
        QString password = ui->password->text();
        auto id = ui->id->value();

        auto user = _dataBase->read_data_user(id, password);

        if(user.id == 0)
        {
            ui->error->setText(MESSAGE_ERROR);
            return;
        }

        _access = user.access;

        clear_form();
        _close = false;
        QWidget::close();
    }
}

bool FormForLogin::is_close()const
{
    return _close;
}

Access FormForLogin::get_access()const
{
    return _access;
}

void FormForLogin::on_button_for_guest_clicked()
{
    _access = GUEST;
    _close = false;
    clear_form();
    QWidget::close();
}
