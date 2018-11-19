#ifndef SECURITY_H
#define SECURITY_H

#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QCryptographicHash>

enum Access { GUEST = 0 , CHIEF , WORKER_TAKE_ORDER, WORKER_CLOSE_ORDER, ADMIN};

class Security
{
public:
    static bool check_access(QString &id, QString &password, Access &access);
    static bool change_access(QString &id, Access access);
    static bool delete_user(QString &id);
    static bool add_user(QString &id, QString &password, Access &access);
    static bool change_password(QString &id, QString &password);
    static bool is_id(QString &id);
private:
    static const char* REQUESTE_TAKE_USER;
    static const char* REQUESTE_CHANGE_ACCESS;
    static const char* REQUESTE_CHANGE_PASSWORD;
    static const char* REQUESTE_DELETE_USER;
    static const char* REQUESTE_ADD_USER;
    static const char* REQUESTE_FIND_USER;

    static const char* COLUMN_ACCESS;
};


#endif // SECURITY_H
