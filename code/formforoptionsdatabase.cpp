#include "formforoptionsdatabase.h"
#include "ui_formforoptionsdatabase.h"

const char* FormForOptionsDataBase::CAPTION_TEXT_SELECT = "Выбор базы данных";

const char* FormForOptionsDataBase::CAPTION_TEXT_CREATE = "Создание базы данных";
const char* FormForOptionsDataBase::FORMAT_FILE =  "Data base (*.sqlite)";

const char* FormForOptionsDataBase::COMPLETE = "Готово";
const char* FormForOptionsDataBase::COMPLETE_CREATE = "Файл создан";

const char* FormForOptionsDataBase::ERROR = "Ошибка";
const char* FormForOptionsDataBase::ERROR_CREATE_FILE = "Не удалось создать файл";


FormForOptionsDataBase::FormForOptionsDataBase(AbstractDataBaseOptions *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForOptionsDataBase),
    m_database(database)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":icons/icon.png"));
}

FormForOptionsDataBase::~FormForOptionsDataBase()
{
    delete ui;
}

void FormForOptionsDataBase::set_path_data_base(QString &path_data_base)
{
    ui->path_data_base->setText(path_data_base);
}

void FormForOptionsDataBase::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}

void FormForOptionsDataBase::on_select_data_base_button_clicked()
{
    auto file_name = QFileDialog::getOpenFileName(this,CAPTION_TEXT_SELECT,ui->path_data_base->text(),FORMAT_FILE,nullptr);
    if(!file_name.isEmpty())
    {
        emit changed_data_base(file_name);
    }
}

void FormForOptionsDataBase::on_create_data_base_button_clicked()
{
    auto file_name = QFileDialog::getSaveFileName(this,CAPTION_TEXT_CREATE,"",FORMAT_FILE,nullptr);
    QFile file(file_name);
    file.open(QIODevice::NewOnly);
    if(file.isOpen() && m_database->createDataBase(file_name) && m_database->copyDataUsers(file_name))
    {
        QMessageBox::information(this,tr(COMPLETE),tr(COMPLETE_CREATE));
        file.close();
        return;
    }
    else if (file.isOpen())
    {
       file.close();
       file.remove();
    }
    QMessageBox::warning(this,tr(ERROR),tr(ERROR_CREATE_FILE));
}
