#include "databaseworker.h"

#include <QSqlRecord>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QDate>
#include <QFile>

bool DataBaseWorker::add_user(const UserData& user, QSqlDatabase &dataBase)
{
    QSqlQuery query(dataBase);
    query.prepare(REQUESTE_ADD_USER);

    query.bindValue(":1",user.id);
    query.bindValue(":2",static_cast<int>(user.access));
    query.bindValue(":3",user.password);

    return exec_request(query);
}

bool DataBaseWorker::add_user(const UserData& user)
{
    QString password = QCryptographicHash::hash(user.password.toLatin1(),QCryptographicHash::Md5);

    QSqlQuery query;
    query.prepare(REQUESTE_ADD_USER);

    query.bindValue(":1",user.id);
    query.bindValue(":2",static_cast<int>(user.access));
    query.bindValue(":3",password);

    return exec_request(query);
}

UserData DataBaseWorker::read_data_user(const int id, const QString& password) const
{
    QString hash_password = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);

    QSqlQuery query;
    query.prepare(REQUESTE_TAKE_USER);

    query.bindValue(":1",id);
    query.bindValue(":2",hash_password);

    if(!exec_request(query) || !query.next())
    {
        return {0,GUEST,""};
    }
    auto access = static_cast<Access>(query.value(query.record().indexOf(COLUMN_ACCESS)).toInt());
    return {id,access,password};
}

UserData DataBaseWorker::read_data_user(const int id)
{
    QSqlQuery query;
    query.prepare(REQUESTE_TAKE_USER_BY_ONLY_ID);

    query.bindValue(":1",id);

    if(!exec_request(query) || !query.next())
    {
        return {0,GUEST,""};
    }
    auto access = static_cast<Access>(query.value(query.record().indexOf(COLUMN_ACCESS)).toInt());
    auto password = query.value(query.record().indexOf("password")).toString();
    return {id,access,password};
}

bool DataBaseWorker::delete_user(const int id)
{
    QSqlQuery query;
    query.prepare(REQUESTE_DELETE_USER);
    query.bindValue(":1",id);
    return exec_request(query);
}

bool DataBaseWorker::change_password(const int id, const QString& new_password)
{
    QString hash_new_password = QCryptographicHash::hash(new_password.toLatin1(),QCryptographicHash::Md5);
    QSqlQuery query;

    query.prepare(REQUESTE_CHANGE_PASSWORD);
    query.bindValue(":1",hash_new_password);
    query.bindValue(":2",id);

    return read_data_user(id).id && exec_request(query);
}

bool DataBaseWorker::change_access(const int id, const Access &access)
{
    QSqlQuery query;

    query.prepare(REQUESTE_CHANGE_ACCESS);
    query.bindValue(":1",static_cast<int>(access));
    query.bindValue(":2",id);

    return read_data_user(id).id && exec_request(query);
}


Order DataBaseWorker::read_order(const int number)
{
    Order order;
    QSqlQuery query;

    query.prepare(REQUEST_TAKE_ANY_ORDER);
    query.bindValue(":1",number);

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

    auto count_order = count_orders();
    if(count_order != -1)
    {
        for(int i = 1; i <= count_order; ++i)
        {
            orders.push_back(read_order(i));
        }
    }
    return orders;
}

int DataBaseWorker::count_orders()
{
    QString request = QString(REQUEST_COUNT_ORDERS);
    QSqlQuery query(request);
    if(exec_request(query) && query.next())
    {
        return query.value( query.record().indexOf("COUNT")).toInt();
    }
    return -1;
}

bool DataBaseWorker::write_order(const Order& order)
{
    auto number_order = order.get_number();

    QSqlQuery query;
    query.prepare(REQUEST_INSERT_ORDERS);

    query.bindValue(":1",number_order);
    query.bindValue(":2",order.get_name_client());
    query.bindValue(":3",order.get_name_worker());
    auto &date = order.get_date();
    query.bindValue(":4",(QString::number(date.date().year()) + QChar('.') +
                          QString::number(date.date().month()) + QChar('.') +
                          QString::number(date.date().day())));
    query.bindValue(":5",order.get_status());
    query.bindValue(":6",order.get_cost());
    query.bindValue(":7",number_order);
    query.bindValue(":8",order.get_discount());

    auto data_base = QSqlDatabase::database();
    data_base.transaction();

    if(!exec_request(query))
    {
        return false;
    }

    query.prepare(QString(REQUEST_CREATE_TABLE_ORDER).arg(number_order));

    if(!exec_request(query))
    {
        data_base.rollback();
        return false;
    }
    auto &services = order.get_services();
    auto request = QString(REQUEST_INSERT_SERVICE_ORDER).arg(number_order);
    for(int i = 0; i < services.size(); i++)
    {
        query.prepare(request);
        query.bindValue(":1",services[i].cost);
        query.bindValue(":2",services[i].count);
        query.bindValue(":3",services[i].name_service);
        if(!exec_request(query))
        {
            data_base.rollback();
            return false;
        }
    }
    return data_base.commit();
}


bool DataBaseWorker::delete_order_with_services(const int number)
{
    if(is_order(number))
    {
        auto request = QString(REQUEST_DELETE_ORDER).arg(number);
        QSqlQuery query(request);

        auto data_base = QSqlDatabase::database();
        data_base.transaction();

        if(!(exec_request(query)))
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
    return false;
}

bool DataBaseWorker::complete_order(const int number)
{
    if(is_order(number))
    {
        QSqlQuery query;
        query.prepare(REQUEST_COMPLETE_ORDER);
        query.bindValue(":1",number);
        return exec_request(query);
    }
    return false;
}

bool DataBaseWorker::is_order(const int number)const
{
    QSqlQuery query;
    query.prepare(REQUEST_FIND_ORDERS);
    query.bindValue(":1",number);
    auto t = exec_request(query);
    t = query.next();
    return t;
    //return exec_request(query) && query.next();
}

bool DataBaseWorker::add_service(const QString& name, const double price)
{
    QSqlQuery query;
    query.prepare(REQUESTE_ADD_SERVICE);
    query.bindValue(":1",name);
    query.bindValue(":2",price);
    return exec_request(query);
}

QVector<QPair<QString, double>> DataBaseWorker::read_services()
{
    QVector<QPair<QString, double>> services;
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

bool DataBaseWorker::change_name_service(const QString& new_name, const QString& old_name, const double price)
{
    QSqlQuery query;
    query.prepare(REQUESTE_UPDATE_NAME);
    query.bindValue(":1",new_name);
    query.bindValue(":2",old_name);
    query.bindValue(":3",price);
    return exec_request(query);
}

bool DataBaseWorker::change_price_service(const QString& name, const double new_price, const double old_price)
{
    QSqlQuery query;
    query.prepare(REQUESTE_UPDATE_PRICE);
    query.bindValue(":1",new_price);
    query.bindValue(":2",name);
    query.bindValue(":3",old_price);
    return exec_request(query);
}

bool DataBaseWorker::delete_service(const QString& name, const double price)
{
    QSqlQuery query;
    query.prepare(REQUESTE_DELETE_SERVICE);
    query.bindValue(":1",name);
    query.bindValue(":2",price);
    return exec_request(query);
}

QVector<InfoOfOrderedService> DataBaseWorker::read_services_order(const int number)const
{
    QVector<InfoOfOrderedService> services;
    QSqlQuery query;
    query.prepare(QString(REQUEST_TAKE_TABLE_SERVICES_ORDER).arg(number));
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

bool DataBaseWorker::add_worker(const QString& name)
{
    QSqlQuery query;
    query.prepare(REQUESTE_ADD_WORKER);
    query.bindValue(":1",name);
    return exec_request(query);
}

bool DataBaseWorker::remove_worker(const QString& name)
{
    QSqlQuery query;
    query.prepare(REQUESTE_REMOVE_WORKER);
    query.bindValue(":1",name);
    return exec_request(query);
}

const QList<QString> DataBaseWorker::read_workers()
{
    QSqlQuery query;
    query.prepare(REQUESTE_TAKE_WORKERS);

    QList<QString> workers;
    if(exec_request(query))
    {
        while(query.next())
        {
            auto record = query.record();
            auto name = query.value(record.indexOf(COLUMN_NAME)).toString();
            workers.push_back(name);
        }
    }
    return workers;

}

bool DataBaseWorker::createDataBase(const QString& path)
{
    QFile file(m_config_database);
    if(file.open(QIODevice::ReadOnly))
    {
        QString script = file.readAll();
        file.close();

        script.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
        QStringList requests = script.split(';', QString::SkipEmptyParts);

        QSqlDatabase dst = QSqlDatabase::addDatabase("QSQLITE",path);
        dst.setDatabaseName(path);
        if(dst.open())
        {
            QSqlQuery query(dst);
            for(const auto &request : requests)
            {
                query.prepare(request);
                if(!query.exec())
                {
                    return false;
                }
            }
            dst.close();
            return true;
        }
    }
    return false;
}

bool DataBaseWorker::copyDataUsers(const QString &database)
{
    QSqlDatabase dst = QSqlDatabase::addDatabase("QSQLITE",database);
    dst.setDatabaseName(database);
    if(dst.open())
    {
        QSqlQuery query;
        query.prepare(REQUESTE_TAKE_ALL_USER);
        if(exec_request(query))
        {
            QSqlQuery dst_query(dst);
            while(query.next())
            {
                auto access = static_cast<Access>(query.value(query.record().indexOf(COLUMN_ACCESS)).toInt());
                auto password = query.value(query.record().indexOf("password")).toString();
                auto id = query.value(query.record().indexOf("id")).toInt();

                if(!add_user({id,access,password}, dst))
                {
                    dst.close();
                    return false;
                }
            }
            dst.close();
            return true;
        }
        dst.close();
    }
    return false;
}

bool DataBaseWorker::exec_request(QSqlQuery& query) const
{
    return query.exec();
}

DataBaseWorker::DataBaseWorker()
{}
