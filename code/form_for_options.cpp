#include "form_for_options.h"
#include "ui_form_for_options.h"

FormForOptions::FormForOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForOptions),
    window_for_change_access(new Ui::FormForChangeAccess),
    window_for_add_password(new Ui::FormForAddPassword),
    window_for_change_password(new Ui::FormForChangePassword),
    window_for_delete_password(new Ui::FormForDeletePassword)
{
    _widget_for_add_password = new QWidget();
    window_for_add_password->setupUi(_widget_for_add_password);
    _widget_for_change_access = new QWidget();
    window_for_change_access->setupUi(_widget_for_change_access);
    _widget_for_change_password = new QWidget();
    window_for_change_password->setupUi(_widget_for_change_password);
    _widget_for_delete_password = new QWidget();
    window_for_delete_password->setupUi(_widget_for_delete_password);

    ui->setupUi(this);
    connect(window_for_add_password->back_button,SIGNAL(clicked()), this, SLOT(slot_add_password_back_button_clicked()));
    connect(window_for_add_password->ok_button,SIGNAL(clicked()), this, SLOT(slot_add_password_ok_button_clicked()));
    connect(window_for_delete_password->back_button,SIGNAL(clicked()), this, SLOT(slot_delete_password_back_button_clicked()));
    connect(window_for_delete_password->ok_button,SIGNAL(clicked()), this, SLOT(slot_delete_password_ok_button_clicked()));
    connect(window_for_change_access->back_button,SIGNAL(clicked()), this, SLOT(slot_change_access_back_button_clicked()));
    connect(window_for_change_access->ok_button,SIGNAL(clicked()), this, SLOT(slot_change_access_ok_button_clicked()));
    connect(window_for_change_password->back_button,SIGNAL(clicked()), this, SLOT(slot_change_password_back_button_clicked()));
    connect(window_for_change_password->ok_button,SIGNAL(clicked()), this, SLOT(slot_change_password_ok_button_clicked()));
}

FormForOptions::~FormForOptions()
{
    delete window_for_add_password;
    delete window_for_change_access;
    delete window_for_change_password;
    delete window_for_delete_password;
    delete ui;
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
    window_for_add_password->access->setCurrentIndex(0);
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
        QString message = "В данный момент нельзя удалить пользователя.";
        QMessageBox::warning(this,QString("Ошибка"),message);
    }
    else
    {
        QString message = "Пользователь id:%1 удален.";
        QMessageBox::information(this,QString("Результат"),message.arg(id));
    }
}

void FormForOptions::slot_add_password_ok_button_clicked()
{
    QString id = window_for_add_password->id->text();
    QString password = window_for_add_password->password->text();
    Access access = static_cast<Access>(window_for_add_password->access->currentIndex());
    if(!Security::add_user(id,password,access))
    {
        QString message = "В данный момент нельзя добавить пользователя.";
        QMessageBox::warning(this,QString("Ошибка"),message);
    }
    else
    {
        QString message = "Пользователь id:%1 добавлен.";
        QMessageBox::information(this,QString("Результат"),message.arg(id));
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
        QString message = "В данный момент нельзя изменить данные.";
        QMessageBox::warning(this,QString("Ошибка"),message);
    }
    else
    {
        QString message = "Данные изменены.";
        QMessageBox::information(this,QString("Результат"),message);
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
        QString message = "В данный момент нельзя изменить данные.";
        QMessageBox::warning(this,QString("Ошибка"),message);
    }
    else
    {
        QString message = "Уровень доступа изменен.";
        QMessageBox::information(this,QString("Результат"),message);
    }
}

void FormForOptions::slot_change_access_back_button_clicked()
{
    _widget_for_change_access->close();
    window_for_change_access->id->clear();
    window_for_change_access->access->setCurrentIndex(0);
    this->show();
}
