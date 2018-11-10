#ifndef WORK_WITH_ORDER_H
#define WORK_WITH_ORDER_H

#include <QObject>
#include <QString>
#include <QFile>

class Work_With_Order : public QObject
{
    Q_OBJECT
public:
    explicit Work_With_Order(QObject *parent = 0);

signals:

public slots:

private:
    QString _name_file;

};

#endif // WORK_WITH_ORDER_H
