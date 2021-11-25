#ifndef DATABASEWORKER_H
#define DATABASEWORKER_H

#include "AbstractDataUserWorker.h"
#include "AbstractOrderRW.h"
#include "AbstractServicesWorker.h"
#include <QSqlQuery>

class DataBaseWorker : public AbstractOrderRW, public AbstractDataUserWorker, public AbstractServicesWorker
{
public:
    DataBaseWorker();

    virtual bool add_user(const UserData& user)override;
    virtual UserData read_data_user(const int id, const QString& password)override;
    virtual bool delete_user(const int id)override;
    virtual bool change_password(const int id, const QString& new_password)override;
    virtual bool change_access(const int id, const Access& access)override;

    virtual Order read_order(const int number)override;
    virtual QVector<Order> read_orders()override;
    virtual bool write_order(const Order&)override;
    virtual bool complete_order(const int number)override;
    virtual bool delete_order_with_services(const int number)override;

    virtual bool add_sevice(const QString& name, const float price)override;
    virtual QVector<QPair<QString, float>> read_services()override;
    virtual bool change_name_service(const QString& new_name, const QString& old_name)override;
    virtual bool change_price_service(const QString& name, const float price)override;
    virtual bool delete_service(const QString& name)override;

    virtual ~DataBaseWorker(){}

private:
    static constexpr auto REQUESTE_TAKE_USER = "SELECT * FROM security WHERE id = %1 AND password = '%2';";
    static constexpr auto REQUESTE_ADD_USER = "INSERT INTO security(id, access, password) VALUES(%1,%2,'%3');";
    static constexpr auto REQUESTE_DELETE_USER = "DELETE FROM security WHERE id = %1;";
    static constexpr auto REQUESTE_CHANGE_PASSWORD = "UPDATE security SET password = '%1' WHERE id = %2;";
    static constexpr auto REQUESTE_CHANGE_ACCESS =   "UPDATE security SET access = %1 WHERE id = %2;";

    static constexpr auto REQUESTE_ADD_SERVICE =   "INSERT INTO services(price, name) VALUES(%1, '%2');";
    static constexpr auto REQUESTE_TAKE_SERVICES =  "SELECT * FROM services";
    static constexpr auto REQUESTE_UPDATE_NAME =    "UPDATE services SET name = '%1' WHERE name = '%2';";
    static constexpr auto REQUESTE_UPDATE_PRICE =   "UPDATE services SET price = %1 WHERE name = '%2';";
    static constexpr auto REQUESTE_DELETE_SERVICE = "DELETE FROM services WHERE price = %1 AND name = '%2'";

    static constexpr auto REQUEST_TAKE_TABLE_ORDERS = "SELECT * FROM orders;";
    static constexpr auto REQUEST_TAKE_ANY_ORDER = "SELECT * FROM orders WHERE id = %1;";
    static constexpr auto REQUEST_INSERT_ORDERS =
            "INSERT INTO orders(number, client, worker, date, status, cost, services, discount)"
            " VALUES(%1, '%2', '%3', '%4', %5, %6, %7, %8);";
    static constexpr auto REQUEST_TAKE_TABLE_SERVICES_ORDER = "SELECT * FROM _%1_;";
    static constexpr auto REQUEST_CREATE_TABLE_ORDER =
            "CREATE TABLE _%1_ (price NOT NULL, count NOT NULL, name TEXT);";
    static constexpr auto REQUEST_INSERT_SERVICE_ORDER =
            "INSERT INTO _%1_(price, count, name)  VALUES(%2, %3, '%4');";
    static constexpr auto REQUEST_COMPLETE_ORDER = "UPDATE orders SET status = 1 WHERE number = %1;";
    static constexpr auto REQUEST_DELETE_ORDER = "DELETE FROM orders WHERE number = %1;";
    static constexpr auto REQUEST_DELETE_TABLE_SERVICE_ORDER ="DROP TABLE _%1_;";

    static constexpr auto COLUMN_ACCESS =         "access";
    static constexpr auto COLUMN_PRICE =          "price";
    static constexpr auto COLUMN_NAME =           "name";
    static constexpr auto COLUMN_CLIENT =         "client";
    static constexpr auto COLUMN_WORKER =         "worker";
    static constexpr auto COLUMN_DATE =           "date";
    static constexpr auto COLUMN_COST =           "cost";
    static constexpr auto COLUMN_DISCOUNT =       "discount";
    static constexpr auto COLUMN_STATUS =         "status";
    static constexpr auto COLUMN_SERVICES =       "services";
    static constexpr auto COLUMN_PRICE_SERVICE =  "price";
    static constexpr auto COLUMN_COUNT_SERVICES = "count";
    static constexpr auto COLUMN_NAME_SERVICE =   "name";

    bool is_user(const UserData&);
    bool exec_request(QSqlQuery& query) const;
    QVector<InfoOfOrderedService> read_services_order(const int number)const;
};

#endif // DATABASEWORKER_H
