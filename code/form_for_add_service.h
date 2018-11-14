#ifndef FORM_FOR_ADD_SERVICE_H
#define FORM_FOR_ADD_SERVICE_H

#include <QWidget>

namespace Ui {
class Form_For_Add_Service;
}

class FormForAddService : public QWidget
{
    Q_OBJECT

public:
    QString get_name_service()const;
    QString get_cost_service()const;
    void show();

    explicit FormForAddService(QWidget *parent = 0);
    ~FormForAddService();

signals:
    void to_main_window();
    void new_data();

private slots:
    void on_back_button_clicked();
    void on_name_service_textChanged(const QString &name);
    void on_cost_service_valueChanged(const QString &cost);

private:
    Ui::Form_For_Add_Service *ui;
    void clear_form()const;
};

#endif // FORM_FOR_ADD_SERVICE_H
