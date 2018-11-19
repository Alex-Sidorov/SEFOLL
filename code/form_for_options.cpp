#include "form_for_options.h"
#include "ui_form_for_options.h"

const int FormForOptions::INDEX_FIRST_ACCESS = 0;

const char* FormForOptions::RESUALT = "Результат";
const char* FormForOptions::ERROR = "ОШИБКА";
const char* FormForOptions::MESSAGE_ERROR_DELETE_USER = "В данный момент нельзя удалить пользователя.";
const char* FormForOptions::MESSAGE_USER_WAS_DELETE = "Пользователь id:%1 удален.";
const char* FormForOptions::MESSAGE_ERROR_ADD_USER = "В данный момент нельзя добавить пользователя.";
const char* FormForOptions::MESSAGE_USER_WAS_ADD = "Пользователь id:%1 добавлен.";
const char* FormForOptions::MESSAGE_ERROR_CHANGE_DATA = "В данный момент нельзя изменить данные.";
const char* FormForOptions::MESSAGE_DATA_CHANGED = "Данные изменены";

FormForOptions::FormForOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForOptions),
    window_for_change_access(new Ui::FormForChangeAccess),
    window_for_add_password(new Ui::FormForAddPassword),
    window_for_change_password(new Ui::FormForChangePassword),
    window_for_delete_password(new Ui::FormForDeletePassword),
    _widget_for_add_password(new QWidget),
    _widget_for_change_access(new QWidget),
    _widget_for_change_password(new QWidget),
    _widget_for_delete_password(new QWidget)
{
    ui->setupUi(this);
    window_for_add_password->setupUi(_widget_for_add_password.data());
    window_for_change_access->setupUi(_widget_for_change_access.data());
    window_for_change_password->setupUi(_widget_for_change_password.data());
    window_for_delete_password->setupUi(_widget_for_delete_password.data());

    connect(window_for_add_password->back_button,SIGNAL(clicked()), this, SLOT(slot_add_password_back_button_clicked()));
    connect(window_for_add_password->ok_button,SIGNAL(clicked()), this, SLOT(slot_add_password_ok_button_clicked()));
    connect(window_for_delete_password->back_button,SIGNAL(clicked()), this, SLOT(slot_delete_password_back_button_clicked()));
    connect(window_for_delete_password->ok_button,SIGNAL(clicked()), this, SLOT(slot_delete_password_ok_button_clicked()));
    connect(window_for_change_access->back_button,SIGNAL(clicked()), this, SLOT(slot_change_access_back_button_clicked()));
    connect(window_for_change_access->ok_button,SIGNAL(clicked()), this, SLOT(slot_change_access_ok_button_clicked()));
    connect(window_for_change_password->back_button,SIGNAL(clicked()), this, SLOT(slot_change_password_back_button_clicked()));
    connect(window_for_change_password->ok_button,SIGNAL(clicked()), this, SLOT(slot_change_password_ok_button_clicked()));
}

void FormForOptions::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}

void FormForOptions::on_add_password_button_clicked()
{
    this->close();
    _widget_for_add_password->show();
}

void FormForOptions::slot_add_password_back_button_clicked()
{
    _widget_for_add_password->close();
    window_for_add_password->id->clear();
    window_for_add_password->password->clear();
    window_for_add_password->access->setCurrentIndex(INDEX_FIRST_ACCESS);
    this->show();
}

void FormForOptions::slot_delete_password_back_button_clicked()
{
    _widget_for_delete_password->close();
    window_for_delete_password->id->clear();
    this->show();
}

void FormForOptions::slot_delete_password_ok_button_clicked()
{
    QString id = window_for_delete_password->id->text();
    if(!Security::delete_user(id))
    {
        QMessageBox::warning(this,ERROR,MESSAGE_ERROR_DELETE_USER);
    }
    else
    {
        QString message = MESSAGE_USER_WAS_DELETE;
        QMessageBox::information(this,RESUALT,message.arg(id));
    }
}

void FormForOptions::slot_add_password_ok_button_clicked()
{
    QString id = window_for_add_password->id->text();
    QString password = window_for_add_password->password->text();
    Access access = static_cast<Access>(window_for_add_password->access->currentIndex());
    if(!Security::add_user(id,password,access))
    {
        QMessageBox::warning(this,ERROR,MESSAGE_ERROR_ADD_USER);
    }
    else
    {
        QString message = MESSAGE_USER_WAS_ADD;
        QMessageBox::information(this,RESUALT,message.arg(id));
    }
}

void FormForOptions::on_delete_password_button_clicked()
{
    this->close();
    _widget_for_delete_password->show();
}

void FormForOptions::on_change_password_button_clicked()
{
    this->close();
    _widget_for_change_password->show();
}

void FormForOptions::on_change_access_button_clicked()
{
    this->close();
    _widget_for_change_access->show();
}

void FormForOptions::slot_change_password_ok_button_clicked()
{
    QString id = window_for_change_password->id->text();
    QString password = window_for_change_password->password->text();
    if(!Security::change_password(id,password))
    {
        QMessageBox::warning(this,ERROR,MESSAGE_ERROR_CHANGE_DATA);
    }
    else
    {
        QMessageBox::information(this,RESUALT,MESSAGE_DATA_CHANGED);
    }
}

void FormForOptions::slot_change_password_back_button_clicked()
{
    _widget_for_change_password->close();
    window_for_change_password->id->clear();
    window_for_change_password->password->clear();
    this->show();
}

void FormForOptions::slot_change_access_ok_button_clicked()
{
    QString id = window_for_change_access->id->text();
    Access access = static_cast<Access>(window_for_change_access->access->currentIndex());
    if(!Security::change_access(id,access))
    {
        QMessageBox::warning(this,ERROR,MESSAGE_ERROR_CHANGE_DATA);
    }
    else
    {
        QMessageBox::information(this,RESUALT,MESSAGE_DATA_CHANGED);
    }
}

void FormForOptions::slot_change_access_back_button_clicked()
{
    _widget_for_change_access->close();
    window_for_change_access->id->clear();
    window_for_change_access->access->setCurrentIndex(INDEX_FIRST_ACCESS);
    this->show();
}
