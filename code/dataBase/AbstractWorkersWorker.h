#ifndef ABSTRACTWORKERSWORKER_H
#define ABSTRACTWORKERSWORKER_H

#include <QString>
#include <QList>

class AbstractWorkersWorker
{
public:
    virtual bool add_worker(const QString& name) = 0;
    virtual bool remove_worker(const QString& name) = 0;
    virtual const QList<QString> read_workers() = 0;

    virtual ~AbstractWorkersWorker(){};
};

#endif // ABSTRACTWORKERSWORKER_H
