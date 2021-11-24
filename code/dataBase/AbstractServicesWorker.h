#ifndef ABSTRACTSERVICESWORKER_H
#define ABSTRACTSERVICESWORKER_H

#include <QString>
#include <QVector>
#include <QPair>

class AbstractServicesWorker
{
    virtual bool add_sevices(const QString& name, const float price) = 0;
    /**
     * @brief read_services
     * @return first value is name's services, second value is price his
     */
    virtual QVector<QPair<QString, float>> read_services() = 0;
    virtual bool change_name_service(const QString& new_name, const QString& old_name) = 0;
    virtual bool change_price_service(const QString& name, const float price) = 0;
    virtual bool delete_service(const QString& name) = 0;
    virtual ~AbstractServicesWorker();
};

#endif // ABSTRACTSERVICESWORKER_H
