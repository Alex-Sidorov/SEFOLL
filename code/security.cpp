#include "security.h"

bool Security::check_access(QString &id, QString &password, Access &access)
{
    QString request = "SELECT * FROM security WHERE id = %1 AND password = '%2';";
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
        access = static_cast<Access>(query.value(record.indexOf("access")).toInt());
    }
    return true;
}

bool Security::change_access(QString &id, Access access)
{
    QString request = "UPDATE security SET access = %1 WHERE id = %2;";
    request = request.arg(static_cast<int>(access));
    request = request.arg(id);
    QSqlQuery query(request);
    if(!query.isActive() || !query.exec())
    {
        return false;
    }
    return true;
}

bool Security::delete_user(QString &id)
{
    QString request = "DELETE FROM security WHERE id = %1;";
    request = request.arg(id);
    QSqlQuery query(request);
    if(!query.isActive() || !query.exec())
    {
        return false;
    }
    return true;
}

bool Security::add_user(QString &id, QString &password, Access &access)
{
    QString request = "INSERT INTO security(id, access, password) VALUES(%1,%2,'%3');";
    request = request.arg(id);
    request = request.arg(static_cast<int>(access));
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
    QString request = "UPDATE security SET password = '%1' WHERE id = %2;";
    request = request.arg(password,id);
    QSqlQuery query(request);
    if(!query.isActive() || !query.exec())
    {
        return false;
    }
    return true;
}
