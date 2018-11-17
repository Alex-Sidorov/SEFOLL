#ifndef FORM_FOR_CHANGE_SERVICE_H
#define FORM_FOR_CHANGE_SERVICE_H

#include <QWidget>
#include <QTableWidget>
#include <QVector>

namespace Ui {
class Form_For_Change_Service;
}

class FormForChangeService : public QWidget
{
    Q_OBJECT

public:
    void set_table(const QTableWidget *table);
    const QTableWidget* get_table()const;
    explicit FormForChangeService(QWidget *parent = 0);
    ~FormForChangeService();

signals:
    void to_main_window();
    void changed_data(int);

private slots:
    void on_back_button_clicked();
    void on_data_services_clicked(const QModelIndex &index);
    void on_enter_change_button_clicked();
    void slot_fields_form_changed();

private:
    Ui::Form_For_Change_Service *ui;
    int _index_record;

    void clear_form()const;
    bool is_empty_form()const;

    static const int INDEX_COLUMN_COST;
    static const int INDEX_COLUMN_NAME;
    static const int INDEX_FIRST_ROW;
};

#endif // FORM_FOR_CHANGE_SERVICE_H
