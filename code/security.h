#ifndef SECURITY_H
#define SECURITY_H

#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

enum Access { GUEST = 0 , CHIEF , WORKER_TAKE_ORDER, WORKER_CLOSE_ORDER, ADMIN};

class Security
{
public:
    static bool check_access(QString &id, QString &password, Access &access);
    static bool change_access(QString &id, Access access);
    static bool delete_user(QString &id);
    static bool add_user(QString &id, QString &password, Access &access);
    static bool change_password(QString &id, QString &password);
};


#endif // SECURITY_H
