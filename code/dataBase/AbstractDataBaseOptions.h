#ifndef ABSTRACTDATABASEOPTIONS_H
#define ABSTRACTDATABASEOPTIONS_H

#include <QString>

class AbstractDataBaseOptions
{
public:
    virtual bool createDataBase(const QString& path) = 0;
    virtual bool copyDataUsers(const QString &dst) = 0;

    virtual ~AbstractDataBaseOptions(){}
};

#endif // ABSTRACTDATABASEOPTIONS_H
