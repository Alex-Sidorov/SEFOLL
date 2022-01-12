#ifndef ABSTRACTORDERRW_H
#define ABSTRACTORDERRW_H

#include "order.h"

class AbstractOrderRW
{
public:
    virtual Order read_order(const int number) = 0;
    virtual QVector<Order> read_orders() = 0;
    virtual int count_orders() = 0;
    virtual bool write_order(const Order&) = 0;
    virtual bool complete_order(const int number) = 0;
    virtual bool delete_order_with_services(const int number) = 0;

    virtual ~AbstractOrderRW(){};
};

#endif // ABSTRACTORDERRW_H
