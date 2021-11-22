#include "order.h"

Order::Order()
{
    _cost = 0;
    _status = false;
}

Order::Order(const QString &name_client,
             const QString &name_worker,
             const QDateEdit *date,
             const QVector<InfoOfOrderedService> &services,
             const double cost,
             const bool status,
             const int discount):
            _cost(cost),
            _discount(discount),
            _status(status),
            _name_client(name_client),
            _name_worker(name_worker),
            _date(date->date())
{
    _services.reserve(services.size());
    for(int i=0; i<services.size(); i++)
    {
        _services.push_back(services[i]);
    }
}

void Order::set_data(const QString &name_client,
                     const QString &name_worker,
                     const QDateEdit *date,
                     const QVector<InfoOfOrderedService> &services,
                     const double cost,
                     const bool status,
                     const int discount)
{
    _name_client = name_client;
    _name_worker = name_worker;
    _date.setDate(date->date());
    _cost = cost;
    _status = status;
    _discount = discount;
    _services.clear();
    _services.reserve(services.size());
    for(int i = 0; i<services.size(); i++)
    {
        _services.push_back(services[i]);
    }
}

Order::Order(const Order &obj):
    _cost(obj._cost),
    _discount(obj._discount),
    _status(obj._status),
    _name_client(obj._name_client),
    _name_worker(obj._name_worker),
    _date(obj._date.date())
{
    _services.reserve(obj._services.size());
    for(int i = 0; i<obj._services.size(); i++)
    {
        _services.push_back(obj._services[i]);
    }
}

double Order::get_cost()const
{
    return _cost;
}

const QString& Order::get_name_worker()const
{
    return _name_worker;
}

const QString& Order::get_name_client()const
{
    return _name_client;
}

const QDateEdit& Order::get_date()const
{
    return _date;
}

const QVector<InfoOfOrderedService>& Order::get_services()const
{
    return _services;
}

bool Order::get_status()const
{
    return _status;
}

int Order::get_discount()const
{
    return _discount;
}

void Order::change_status_order()
{
    _status = !_status;
}

Order::~Order(){}
