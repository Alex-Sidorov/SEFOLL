#ifndef ORDER_H
#define ORDER_H

#include "Info_of_ordered_service.h"

#include <QString>
#include <QDateEdit>
#include <QTableWidget>
#include <QFile>
#include <QMessageBox>
#include <QSharedPointer>

const size_t SIZE_UNICODE = 2;

class Order
{
public:
    //static Order* find_order(const unsigned long long int);
    static QSharedPointer<Order> find_order(const unsigned long long int);

    static bool write_order(Order);
    static unsigned long long int get_count_order();

    void set_data(quint64 pos_in_file, const unsigned long long int number_order, const QString &name_client, const QString &name_worker,
                  const QDateEdit *date,const QVector<Info_Of_Ordered_Service> &services,const double cost, const bool status);

    double get_cost()const;
    const QString& get_name_worker()const;
    const QString& get_name_client()const;
    const QDateEdit& get_date()const;
    const QVector<Info_Of_Ordered_Service>& get_services();
    bool get_status()const;

    bool change_status_order();

    Order();
    Order(quint64 pos_in_file, const unsigned long long int number_order,const QString &name_client, const QString &name_worker, const QDateEdit *date,
          const QVector<Info_Of_Ordered_Service> &services,const double cost, const bool status);
    Order(const QString &name_client, const QString &name_worker, const QDateEdit *date,
          const QVector<Info_Of_Ordered_Service> &services,const double cost, const bool status);
    Order(const Order&);
    virtual ~Order();

private:
    unsigned long long int _number_order;
    static unsigned long long int _count_order;
    double _cost;
    QString _name_client;
    QString _name_worker;
    QDateEdit _date;
    QVector<Info_Of_Ordered_Service> _services;
    bool _status;

    quint64 _pos_in_file;

    static QString _name_file;
    void write_data(QDataStream &stream);
};

#endif // ORDER_H
