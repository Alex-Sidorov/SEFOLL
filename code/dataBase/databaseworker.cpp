#include "databaseworker.h"

#include <QSqlRecord>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QDate>

bool DataBaseWorker::add_user(const UserData& user)
{
    auto password = QCryptographicHash::hash(user.password.toLatin1(),QCryptographicHash::Md5);

    QString request = REQUESTE_ADD_USER;
    request = request.arg(user.id).arg(static_cast<int>(user.access)).arg(QString(password));

    QSqlQuery query(request);
    return exec_request(query);
}

UserData DataBaseWorker::read_data_user(const int id, const QString& password)
{
    auto hash_password = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);

    QString request = REQUESTE_ADD_USER;
    request = request.arg(id).arg(QString(hash_password));

    QSqlQuery query(request);
    if(!exec_request(query) || !query.next())
    {
        return {0,GUEST,""};
    }
    auto access = static_cast<Access>(query.value(query.record().indexOf(COLUMN_ACCESS)).toInt());
    return {id,access,password};
}

bool DataBaseWorker::delete_user(const int id)
{
    QString request = REQUESTE_DELETE_USER;
    request = request.arg(id);
    QSqlQuery query(request);
    return exec_request(query);
}

bool DataBaseWorker::change_password(const int id, const QString& new_password)
{
    QString request = REQUESTE_CHANGE_PASSWORD;
    auto hash_new_password = QCryptographicHash::hash(new_password.toLatin1(),QCryptographicHash::Md5);
    request = request.arg(QString(hash_new_password)).arg(id);
    QSqlQuery query(request);
    return exec_request(query);
}

bool DataBaseWorker::change_access(const int id, const Access &access)
{
    QString request = REQUESTE_CHANGE_ACCESS;
    request = request.arg(QString::number(access)).arg(id);
    QSqlQuery query(request);
    return exec_request(query);
}


Order DataBaseWorker::read_order(const int number)
{
    Order order;
    QString request = QString(REQUEST_TAKE_ANY_ORDER).arg(number);
    QSqlQuery query(request);
    if(exec_request(query) && query.next())
    {
        QSqlRecord record = query.record();

        auto client = query.value(record.indexOf(COLUMN_CLIENT)).toString();
        auto worker = query.value(record.indexOf(COLUMN_WORKER)).toString();
        auto cost = query.value(record.indexOf(COLUMN_COST)).toDouble();
        auto dicsount = query.value(record.indexOf(COLUMN_DISCOUNT)).toInt();
        auto is_complete = query.value(record.indexOf(COLUMN_STATUS)).toBool();
        auto services = query.value(record.indexOf(COLUMN_SERVICES)).toInt();
        QStringList temp = query.value(record.indexOf(COLUMN_DATE)).toString().split('.');
        QDateEdit date(QDate(temp.at(0).toInt(),temp.at(1).toInt(),temp.at(2).toInt()));
        auto services_order = read_services_order(services);

        order.set_data(number,client,worker,&date,services_order,cost,is_complete,dicsount);
    }
    return order;
}

QVector<Order> DataBaseWorker::read_orders()
{
    QVector<Order> orders;

    QString request = QString(REQUEST_TAKE_TABLE_ORDERS);
    QSqlQuery query(request);
    if(exec_request(query))
    {
        auto count_order = query.record().count();
        for(int i = 1; i <= count_order; ++i)
        {
            orders.push_back(read_order(i));
        }
    }
    return orders;
}

bool DataBaseWorker::write_order(const Order& order)
{
    auto number_order = order.get_number();

    QString request = REQUEST_INSERT_ORDERS;
    request = request.arg(number_order);
    request = request.arg(order.get_name_client());
    request = request.arg(order.get_name_worker());
    auto &date = order.get_date();
    request = request.arg(QString::number(date.date().year()) + QChar('.') +
                          QString::number(date.date().month()) + QChar('.') +
                          QString::number(date.date().day()));
    request = request.arg(order.get_status());
    request = request.arg(order.get_cost());
    request = request.arg(number_order);
    request = request.arg(order.get_discount());

    auto data_base = QSqlDatabase::database();
    data_base.transaction();

    QSqlQuery query(request);
    if(!query.exec(request))
    {
        return false;
    }

    request = QString(REQUEST_CREATE_TABLE_ORDER).arg(number_order);
    if(!query.exec(request))
    {
        data_base.rollback();
        return false;
    }
    auto &services = order.get_services();
    for(int i = 0; i < services.size(); i++)
    {
        request = REQUEST_INSERT_SERVICE_ORDER;
        request = request.arg(number_order);
        request = request.arg(services[i].cost);
        request = request.arg(services[i].count);
        request = request.arg(services[i].name_service);
        if(!query.exec(request))
        {
            data_base.rollback();
            return false;
        }
    }
    return data_base.commit();
}


bool DataBaseWorker::delete_order_with_services(const int number)
{
    auto request = QString(REQUEST_DELETE_ORDER).arg(number);
    QSqlQuery query(request);

    auto data_base = QSqlDatabase::database();
    data_base.transaction();

    if(!exec_request(query))
    {
        return false;
    }

    request = QString(REQUEST_DELETE_TABLE_SERVICE_ORDER).arg(number);
    query.prepare(request);
    if(!exec_request(query))
    {
        data_base.rollback();
        return false;
    }
    return data_base.commit();
}

bool DataBaseWorker::complete_order(const int number)
{
    QString request = QString(REQUEST_COMPLETE_ORDER).arg(number);
    QSqlQuery query(request);
    return exec_request(query);
}

bool DataBaseWorker::add_sevice(const QString& name, const float price)
{
    QString request = REQUESTE_ADD_SERVICE;
    request = request.arg(name).arg(price);
    QSqlQuery query(request);
    return exec_request(query);
}

QVector<QPair<QString, float>> DataBaseWorker::read_services()
{
    QVector<QPair<QString, float>> services;
    QSqlQuery query(REQUESTE_TAKE_SERVICES);
    if(exec_request(query))
    {
        while(query.next())
        {
            auto record = query.record();
            auto name = query.value(record.indexOf(COLUMN_NAME)).toString();
            auto price = query.value(record.indexOf(COLUMN_PRICE)).toFloat();
            services.push_back({name,price});
        }
    }
    return services;
}

bool DataBaseWorker::change_name_service(const QString& new_name, const QString& old_name)
{
    QString request = REQUESTE_UPDATE_NAME;
    request = request.arg(new_name,old_name);
    QSqlQuery query(request);
    return exec_request(query);
}

bool DataBaseWorker::change_price_service(const QString& name, const float price)
{
    QString request = REQUESTE_UPDATE_PRICE;
    request = request.arg(price).arg(name);
    QSqlQuery query(request);
    return exec_request(query);
}

bool DataBaseWorker::delete_service(const QString& name)
{
    auto request = QString(REQUESTE_DELETE_SERVICE).arg(name);
    QSqlQuery query(request);
    return exec_request(query);
}

QVector<InfoOfOrderedService> DataBaseWorker::read_services_order(const int number)const
{
    QVector<InfoOfOrderedService> services;
    auto request = QString(REQUEST_TAKE_TABLE_SERVICES_ORDER).arg(number);
    QSqlQuery query(request);
    if(exec_request(query))
    {
        while(query.next())
        {
            auto record = query.record();
            auto cost = query.value(record.indexOf(COLUMN_PRICE_SERVICE)).toFloat();
            auto count = query.value(record.indexOf(COLUMN_COUNT_SERVICES)).toInt();
            auto name = query.value(record.indexOf(COLUMN_NAME_SERVICE)).toString();
            services.push_back({name,count,cost});
        }
    }
    return services;
}


bool DataBaseWorker::exec_request(QSqlQuery& query) const
{
    return query.isActive() && query.exec();
}

DataBaseWorker::DataBaseWorker()
{}
