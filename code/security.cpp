#include "security.h"

const char* Security::REQUESTE_TAKE_USER =       "SELECT * FROM security WHERE id = %1 AND password = '%2';";
const char* Security::REQUESTE_CHANGE_ACCESS =   "UPDATE security SET access = %1 WHERE id = %2;";
const char* Security::REQUESTE_DELETE_USER =     "DELETE FROM security WHERE id = %1;";
const char* Security::REQUESTE_ADD_USER =        "INSERT INTO security(id, access, password) VALUES(%1,%2,'%3');";
const char* Security::REQUESTE_FIND_USER =       "SELECT * FROM security WHERE id = %1;";
const char* Security::REQUESTE_CHANGE_PASSWORD = "UPDATE security SET password = '%1' WHERE id = %2;";

const char* Security::COLUMN_ACCESS = "access";

DataBaseWorker Security::_data_base_worker;

bool Security::check_access(QString &id, QString &password, Access &access)
{
    auto user = _data_base_worker.read_data_user(id.toInt(),password);
    bool res = access == user.access;
    access = user.access;
    return res;
}

bool Security::change_access(QString &id, Access access)
{
    return _data_base_worker.change_access(id.toInt(),access);
}

bool Security::delete_user(QString &id)
{
    return _data_base_worker.delete_user(id.toInt());
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
    return _data_base_worker.add_user(UserData{id.toInt(),access,password});
}

bool Security::change_password(QString &id, QString &password)
{
    return _data_base_worker.change_password(id.toInt(),password);
}
