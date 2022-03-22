#include "form_for_options.h"
#include "ui_form_for_options.h"

const int FormForOptions::INDEX_FIRST_ACCESS = 0;

const char* FormForOptions::RESUALT = "Результат";
const char* FormForOptions::ERROR =   "ОШИБКА";

const char* FormForOptions::MESSAGE_ERROR_DELETE_USER = "В данный момент нельзя удалить пользователя.";
const char* FormForOptions::MESSAGE_USER_WAS_DELETE =   "Пользователь id:%1 удален.";
const char* FormForOptions::MESSAGE_ERROR_ADD_USER =    "В данный момент нельзя добавить пользователя.";
const char* FormForOptions::MESSAGE_USER_WAS_ADDED =      "Пользователь id:%1 добавлен.";
const char* FormForOptions::MESSAGE_ERROR_CHANGE_DATA = "В данный момент нельзя изменить данные.";
const char* FormForOptions::MESSAGE_DATA_CHANGED =      "Данные изменены";

FormForOptions::FormForOptions(AbstractDataUserWorker *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForOptions),
    window_for_add_password(new Ui::FormForAddPassword),
    window_for_change_password(new Ui::FormForChangePassword),
    window_for_change_access(new Ui::FormForChangeAccess),
    window_for_delete_password(new Ui::FormForDeletePassword),
    _widget_for_add_password(new QWidget),
    _widget_for_change_password(new QWidget),    
    _widget_for_change_access(new QWidget),
    _widget_for_delete_password(new QWidget),
    m_database(database)
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

    QIcon icon(":icons/icon.png");
    setWindowIcon(icon);
    _widget_for_add_password->setWindowIcon(icon);
    _widget_for_change_access->setWindowIcon(icon);
    _widget_for_change_password->setWindowIcon(icon);
    _widget_for_delete_password->setWindowIcon(icon);
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
    int id = window_for_delete_password->id->value();
    if(!m_database || id == 1 || m_database->delete_user(id))
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
    UserData user;
    user.id = window_for_add_password->id->value();
    user.password = window_for_add_password->password->text();
    user.access = static_cast<Access>(window_for_add_password->access->currentIndex());
    if(!m_database || !m_database->add_user(user))
    {
        QMessageBox::warning(this,ERROR,MESSAGE_ERROR_ADD_USER);
    }
    else
    {
        QString message = MESSAGE_USER_WAS_ADDED;
        QMessageBox::information(this,RESUALT,message.arg(user.id));
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
    auto id = window_for_change_password->id->value();
    QString password = window_for_change_password->password->text();
    if(!m_database || !m_database->change_password(id, password))
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
    int id = window_for_change_access->id->value();
    Access access = static_cast<Access>(window_for_change_access->access->currentIndex());
    if(!m_database || !m_database->change_access(id, access))
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
