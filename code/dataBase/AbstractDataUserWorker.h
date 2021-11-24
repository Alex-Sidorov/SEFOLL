#ifndef ABSTRACTDATAUSERWORKER_H
#define ABSTRACTDATAUSERWORKER_H

#include <QString>

#include "Access.h"

struct UserData
{
    int id;
    Access access;
    QString password;
};

class AbstractDataUserWorker
{
    virtual bool add_user(const UserData& user) = 0;
    virtual UserData read_data_user(const int id, const QString& password) = 0;
    virtual bool delete_user(const int id) = 0;
    virtual bool change_password(const int id, const QString& new_password) = 0;

    virtual ~AbstractDataUserWorker();
};

#endif // ABSTRACTDATAUSERWORKER_H
