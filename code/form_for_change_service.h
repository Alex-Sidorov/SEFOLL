#ifndef FORM_FOR_CHANGE_SERVICE_H
#define FORM_FOR_CHANGE_SERVICE_H

#include <QWidget>
#include <QTableWidget>
#include <QVector>

namespace Ui {
class Form_For_Change_Service;
}

class Form_For_Change_Service : public QWidget
{
    Q_OBJECT

public:
    void set_table(const QTableWidget *table);
    const QTableWidget* get_table()const;

    explicit Form_For_Change_Service(QWidget *parent = 0);
    ~Form_For_Change_Service();

signals:
    void to_main_window();
    void changed_data(int);

private slots:
    void on_back_button_clicked();
    void on_data_services_clicked(const QModelIndex &index);
    void on_name_textChanged(const QString &name);
    void on_cost_valueChanged(const QString &value);
    void on_enter_change_button_clicked();

private:
    Ui::Form_For_Change_Service *ui;
    int _index_record;

    void clear_form()const;
};

#endif // FORM_FOR_CHANGE_SERVICE_H
