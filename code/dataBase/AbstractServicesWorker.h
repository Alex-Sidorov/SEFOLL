#ifndef ABSTRACTSERVICESWORKER_H
#define ABSTRACTSERVICESWORKER_H

#include <QString>
#include <QVector>
#include <QPair>

class AbstractServicesWorker
{
public:
    virtual bool add_service(const QString& name, const double price) = 0;
    /**
     * @brief read_services
     * @return first value is name's services, second value is price his
     */
    virtual QVector<QPair<QString, double>> read_services() = 0;
    virtual bool change_name_service(const QString& new_name, const QString& old_name, const double price) = 0;
    virtual bool change_price_service(const QString& name, const double new_price, const double old_price) = 0;
    virtual bool delete_service(const QString& name, const double price) = 0;
    virtual ~AbstractServicesWorker(){};
};

#endif // ABSTRACTSERVICESWORKER_H
