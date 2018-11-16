#include "order.h"

unsigned long long int Order::_count_order= 0;
QString Order::_name_file = "orders";

Order::Order()
{
    _pos_in_file = 0;
    _number_order = 0;
    _cost = 0;
    _status = false;
}

Order::Order(const QString &name_client,
             const QString &name_worker,
             const QDateEdit *date,
             const QVector<InfoOfOrderedService> &services,
             const double cost,
             const bool status):
    _name_client(name_client),
    _name_worker(name_worker),
    _date(date->date()),
    _cost(cost),
    _status(status)
{
    _pos_in_file = 0;
    _number_order = 0;
    _services.reserve(services.size());
    for(int i=0; i<services.size(); i++)
    {
        _services.push_back(services[i]);
    }
}

Order::Order(quint64 pos_in_file,
             const unsigned long long int number_order,
             const QString &name_client,
             const QString &name_worker,
             const QDateEdit *date,
             const QVector<InfoOfOrderedService> &services,
             const double cost,
             const bool status):
    _pos_in_file(pos_in_file),
    _number_order(number_order),
    _name_client(name_client),
    _name_worker(name_worker),
    _date(date->date()),
    _cost(cost),
    _status(status)
{
    _services.reserve(services.size());
    for(int i=0; i<services.size(); i++)
    {
        _services.push_back(services[i]);
    }
}

void Order::set_data(quint64 pos_in_file,
                     const unsigned long long int number_order,
                     const QString &name_client,
                     const QString &name_worker,
                     const QDateEdit *date,
                     const QVector<InfoOfOrderedService> &services,
                     const double cost,
                     const bool status)
{
    _pos_in_file = pos_in_file;
    _number_order = number_order;
    _name_client = name_client;
    _name_worker = name_worker;
    _date.setDate(date->date());
    _cost = cost;
    _status = status;
    _services.clear();
    _services.reserve(services.size());
    for(int i=0; i<services.size(); i++)
    {
        _services.push_back(services[i]);
    }
}

Order::Order(const Order &obj):
    _name_client(obj._name_client),
    _name_worker(obj._name_worker),
    _date(obj._date.date()),
    _cost(obj._cost),
    _number_order(obj._number_order),
    _status(obj._status),
    _pos_in_file(obj._pos_in_file)
{
    _services.reserve(obj._services.size());
    for(int i=0; i<obj._services.size(); i++)
    {
        _services.push_back(obj._services[i]);
    }
}

Order::~Order()
{

}

unsigned long long int Order::get_count_order()
{
    return _count_order;
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

const QVector<InfoOfOrderedService>& Order::get_services()
{
    return _services;
}

bool Order::get_status()const
{
    return _status;
}

QSharedPointer<Order> Order::find_order(const unsigned long long int number)
{
    QSharedPointer<Order> order;
    QFile file(_name_file);
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_5_2);
    if(!file.open(QIODevice::ReadOnly))
    {
        return order;
    }

    unsigned long long int number_order = 0;
    unsigned long long int count_order = 0;
    double cost = 0;
    QString name_client;
    QString name_worker;
    int day = 0;
    int month = 0;
    int year = 0;
    InfoOfOrderedService temp;
    int count_services = 0;
    QVector<InfoOfOrderedService> services;
    bool status = false;
    qint64 pos_in_file = 0;

    stream>>count_order;
    for(unsigned long long int i=0; i<count_order; i++)
    {
        pos_in_file = file.pos();
        stream>>number_order;
        stream>>name_client;
        stream>>name_worker;
        stream>>day;
        stream>>month;
        stream>>year;
        stream>>status;
        stream>>cost;
        stream>>count_services;

        for(int j=0; j<count_services; j++)
        {
            stream>>temp.cost;
            stream>>temp.count;
            stream>>temp.name_service;
            services.push_back(temp);
        }

        if(number_order==number)
        {
            QDateEdit date(QDate(year,month,day));
            order = QSharedPointer<Order>(new Order(pos_in_file,
                                                    number_order,
                                                    name_client,
                                                    name_worker,
                                                    &date,services,
                                                    cost,status));
            break;
        }
        services.clear();
    }

    file.close();
    return order;
}

bool Order::write_order(Order obj)
{
    QFile file(_name_file);
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_5_2);

    if(!file.open(QIODevice::ReadWrite))
    {
        return false;
    }

    stream>>_count_order;
    _count_order++;
    obj._number_order=_count_order;
    stream.device()->seek(0);
    stream<<_count_order;

    stream.device()->seek(file.size());
    stream<<obj._number_order
          <<obj._name_client
          <<obj._name_worker
          <<obj._date.date().day()
          <<obj._date.date().month()
          <<obj._date.date().year()
          <<obj._status<<obj._cost
          <<obj._services.size();

    for(int i=0; i<obj._services.size();i++)
    {
        stream<<obj._services[i].cost
              <<obj._services[i].count
              <<obj._services[i].name_service;
    }
    file.close();
    return true;
}

bool Order::change_status_order()
{
    QFile file(_name_file);
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_5_2);

    if(!file.open(QIODevice::ReadWrite))
    {
        return false;
    }

    stream.device()->seek(_pos_in_file
                          + sizeof(qint64)
                          +sizeof(_name_client)
                          +_name_client.size()
                          *SIZE_UNICODE
                          +sizeof(_name_worker)
                          +_name_worker.size()
                          *SIZE_UNICODE+sizeof(int)
                          *3);

    _status = true;
    stream<<_status;

    file.close();
    return true;
}
