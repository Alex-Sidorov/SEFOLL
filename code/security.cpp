#include "security.h"

const char* Security::REQUESTE_TAKE_USER =       "SELECT * FROM security WHERE id = %1 AND password = '%2';";
const char* Security::REQUESTE_CHANGE_ACCESS =   "UPDATE security SET access = %1 WHERE id = %2;";
const char* Security::REQUESTE_DELETE_USER =     "DELETE FROM security WHERE id = %1;";
const char* Security::REQUESTE_ADD_USER =        "INSERT INTO security(id, access, password) VALUES(%1,%2,'%3');";
const char* Security::REQUESTE_FIND_USER =       "SELECT * FROM security WHERE id = %1;";
const char* Security::REQUESTE_CHANGE_PASSWORD = "UPDATE security SET password = '%1' WHERE id = %2;";

const char* Security::COLUMN_ACCESS = "access";

bool Security::check_access(QString &id, QString &password, Access &access)
{
    QString request = REQUESTE_TAKE_USER;
    password = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
    request = request.arg(id,password);
    QSqlQuery query(request);
    if(!query.isActive() || !query.exec())
    {
        return false;
    }
    else
    {
        if(!query.next())
        {
            return false;
        }
        QSqlRecord record = query.record();
        access = static_cast<Access>(query.value(record.indexOf(COLUMN_ACCESS)).toInt());
    }
    return true;
}

bool Security::change_access(QString &id, Access access)
{
    QString request = REQUESTE_CHANGE_ACCESS;
    request = request.arg(static_cast<int>(access));
    request = request.arg(id);
    QSqlQuery query(request);
    if(!query.isActive() || !is_id(id) || !query.exec())
    {
        return false;
    }
    return true;
}

bool Security::delete_user(QString &id)
{
    QString request = REQUESTE_DELETE_USER;
    request = request.arg(id);
    QSqlQuery query(request);
    if(!query.isActive() || !is_id(id) || !query.exec())
    {
        return false;
    }
    return true;
}

bool Security::is_id(QString &id)
{
    QString request = REQUESTE_FIND_USER;
    request = request.arg(id);
    QSqlQuery query(request);
    if(!query.isActive() || !query.exec())
    {
        return false;
    }
    else
    {
        if(!query.next())
        {
            return false;
        }
        return true;
    }
}

bool Security::add_user(QString &id, QString &password, Access &access)
{
    QString request = REQUESTE_ADD_USER;
    request = request.arg(id);
    request = request.arg(static_cast<int>(access));
    password = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
    request = request.arg(password);
    QSqlQuery query(request);
    if(!query.isActive() || !query.exec())
    {
        return false;
    }
    return true;
}

bool Security::change_password(QString &id, QString &password)
{
    QString request = REQUESTE_CHANGE_PASSWORD;
    password = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
    request = request.arg(password,id);
    QSqlQuery query(request);
    if(!query.isActive()|| !is_id(id) || !query.exec())
    {
        return false;
    }
    return true;
}
