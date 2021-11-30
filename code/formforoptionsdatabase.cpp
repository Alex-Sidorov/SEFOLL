#include "formforoptionsdatabase.h"
#include "ui_formforoptionsdatabase.h"

const char* FormForOptionsDataBase::CAPTION_TEXT_SELECT = "Выбор базы данных";

const char* FormForOptionsDataBase::CAPTION_TEXT_CREATE = "Создание базы данных";
const char* FormForOptionsDataBase::FORMAT_FILE =  "Data base (*.sqlite)";

const char* FormForOptionsDataBase::COMPLETE = "Готово";
const char* FormForOptionsDataBase::COMPLETE_CREATE = "Файл создан";

const char* FormForOptionsDataBase::ERROR = "Ошибка";
const char* FormForOptionsDataBase::ERROR_CREATE_FILE = "Не удалось создать файл";

const char* FormForOptionsDataBase::REQUEST_CREATE_TABLE_ORDERS =
        "CREATE TABLE orders(number,client,worker,date,status,cost,services,discount Integer DEFAULT (0))";
const char* FormForOptionsDataBase::REQUEST_CREATE_TABLE_SECURITY =
        "CREATE TABLE security(id integer UNIQUE, access integer, password text)";
const char* FormForOptionsDataBase::REQUEST_CREATE_TABLE_SERVICES =
        "CREATE TABLE services(price, name)";

const char* FormForOptionsDataBase::REQUEST_SELECT_TABLE_SECURITY =
        "SELECT * FROM security";

const char* FormForOptionsDataBase::REQUEST_INSERT_RECORD_SECURITY =
        "INSERT INTO security(id, access, password) VALUES(:id, :access, :password);";

const char* FormForOptionsDataBase::TYPE_DATA_BASE = "QSQLITE";

const char* FormForOptionsDataBase::VALUE_ID =       ":id";
const char* FormForOptionsDataBase::VALUE_ACCESS =   ":access";
const char* FormForOptionsDataBase::VALUE_PASSWORD = ":password";

const int FormForOptionsDataBase::INDEX_VALUE_ID =       0;
const int FormForOptionsDataBase::INDEX_VALUE_ACCESS =   1;
const int FormForOptionsDataBase::INDEX_VALUE_PASSWORD = 2;

FormForOptionsDataBase::FormForOptionsDataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForOptionsDataBase)
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
    if(file.isOpen() && fill_file(file_name) && copy_passwords(file_name))
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

bool FormForOptionsDataBase::fill_file(QString &name_file)const
{
    QSqlDatabase dst = QSqlDatabase::addDatabase(TYPE_DATA_BASE,name_file);
    dst.setDatabaseName(name_file);
    dst.open();

    QSqlQuery query(dst);

    for(auto i = &REQUEST_CREATE_TABLE_ORDERS; i <= &REQUEST_CREATE_TABLE_SERVICES; i++)
    {
        if(!query.exec(*i))
        {
            dst.close();
            return false;
        }
    }
    dst.close();
    return true;
}

bool FormForOptionsDataBase::copy_passwords(QString &name_file)const
{
    QSqlQuery src(QSqlDatabase::database());
    if(!src.exec(REQUEST_SELECT_TABLE_SECURITY))
    {
        return false;
    }

    auto dst_base = QSqlDatabase::database(name_file);
    QSqlQuery dst(dst_base);
    dst_base.transaction();
    dst.prepare(REQUEST_INSERT_RECORD_SECURITY);
    while(src.next())
    {
        dst.bindValue(VALUE_ID,src.value(INDEX_VALUE_ID).toInt());
        dst.bindValue(VALUE_ACCESS,src.value(INDEX_VALUE_ACCESS).toInt());
        dst.bindValue(VALUE_PASSWORD,src.value(INDEX_VALUE_PASSWORD).toString());
        if(!dst.exec())
        {
            dst_base.rollback();
            return false;
        }
    }
    dst_base.commit();
    dst_base.close();
    return true;
}
