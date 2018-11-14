#ifndef FORM_FOR_DELETE_SERVICE_H
#define FORM_FOR_DELETE_SERVICE_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>

namespace Ui {
class Form_For_Delete_Service;
}

class FormForDeleteService : public QWidget
{
    Q_OBJECT

public:
    void set_table(const QTableWidget*);
    explicit FormForDeleteService(QWidget *parent = 0);
    ~FormForDeleteService();

signals:
    void to_main_window();
    void changed_table(const QVector<int>&);

private slots:
    void on_back_button_clicked();
    void on_data_services_clicked(const QModelIndex &index);
    void on_delete_button_clicked();

private:
    Ui::Form_For_Delete_Service *ui;

    int _count_delete_items;
    QVector<int> index_deleted_item;

    int request_for_delete()const;
    void delete_items();
    void clear_form()const;
};

#endif // FORM_FOR_DELETE_SERVICE_H
