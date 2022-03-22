#ifndef ORDER_H
#define ORDER_H

#include "Info_of_ordered_service.h"

#include <QString>
#include <QDateEdit>
#include <QTableWidget>

class Order
{
public:
    void set_data(const int number, const QString &name_client, const QString &name_worker,
                  const QDateEdit *date,const QVector<InfoOfOrderedService> &services,
                  const double cost, const bool status, const int discount,
                  const QString &phone);
    double get_cost()const;
    const QString& get_name_worker()const;
    const QString& get_name_client()const;
    const QDateEdit& get_date()const;
    const QVector<InfoOfOrderedService>& get_services()const;
    bool get_status()const;
    int get_discount()const;
    int get_number()const;
    QString get_phone()const;

    void change_status_order();

    Order();
    Order(int number, const QString &name_client, const QString &name_worker, const QDateEdit *date,
          const QVector<InfoOfOrderedService> &services,const double cost, const bool status,
          const int discount, const QString &phone);
    Order(const Order&);
    virtual ~Order();

private:
    int _number;
    double _cost;
    int _discount;
    bool _status;
    QString _name_client;
    QString _name_worker;
    QDateEdit _date;
    QVector<InfoOfOrderedService> _services;
    QString _phone;
};

#endif // ORDER_H
