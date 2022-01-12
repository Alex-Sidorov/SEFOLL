#ifndef FORM_FOR_ADD_SERVICE_H
#define FORM_FOR_ADD_SERVICE_H

#include <QWidget>
#include <QSharedPointer>

#include "dataBase/AbstractServicesWorker.h"

namespace Ui {
class Form_For_Add_Service;
}

class FormForAddService : public QWidget
{
    Q_OBJECT

public:
    QString get_name_service()const;
    double get_cost_service()const;
    void show();
    explicit FormForAddService(AbstractServicesWorker* database, QWidget *parent = 0);
    FormForAddService(const FormForAddService&) = delete;
    virtual ~FormForAddService(){}

signals:
    void to_main_window();
    void new_data();

private slots:
    void on_back_button_clicked();
    void slot_fields_form_changed();
    void on_ok_button_clicked();

private:
    QSharedPointer<Ui::Form_For_Add_Service> ui;
    AbstractServicesWorker* m_database;

    void clear_form()const;
    bool is_empty_form()const;
};

#endif // FORM_FOR_ADD_SERVICE_H
