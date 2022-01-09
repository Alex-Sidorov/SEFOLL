#ifndef FORMFORWORKERS_H
#define FORMFORWORKERS_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QList>

#include "dataBase/AbstractWorkersWorker.h"

namespace Ui {
class FormForWorkers;
}

class FormForWorkers : public QWidget
{
    Q_OBJECT

public:
    explicit FormForWorkers(AbstractWorkersWorker* database = nullptr, QWidget *parent = nullptr);
    virtual ~FormForWorkers();


    const QList<QString> get_names_workers();

public slots:
    void show();

signals:
    void to_main_window();

private slots:
    void on_back_button_clicked();
    void on_addWorkerButton_clicked();
    void on_workers_itemClicked(QTableWidgetItem *item);
    void on_deleteWorkerButton_clicked();

private:
    Ui::FormForWorkers *ui;

    AbstractWorkersWorker* m_data_base;
    QList<QTableWidgetItem*> m_selected_items;

    bool m_is_first_show;

    static const Qt::GlobalColor DEFAULT_FIELD_COLOR;
    static const Qt::GlobalColor SELECT_FIELD_COLOR;

    int request_for_delete()const;

    bool init_table();
};

#endif // FORMFORWORKERS_H
