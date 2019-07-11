#ifndef FORMFOROPTIONSDATABASE_H
#define FORMFOROPTIONSDATABASE_H

#include <QWidget>
#include <QFileDialog>
#include <QDate>
#include <QMessageBox>
#include <qsqldatabase.h>
#include <QSqlQuery>

namespace Ui {
class FormForOptionsDataBase;
}

class FormForOptionsDataBase : public QWidget
{
    Q_OBJECT

public:
    void set_path_data_base(QString &path_data_base);
    explicit FormForOptionsDataBase(QWidget *parent = nullptr);
    ~FormForOptionsDataBase();

signals:
    void to_main_window();
    void changed_data_base(QString &name_data_base);

private slots:
    void on_back_button_clicked();
    void on_select_data_base_button_clicked();
    void on_create_data_base_button_clicked();

private:
    Ui::FormForOptionsDataBase *ui;

    static const char* CAPTION_TEXT_SELECT;

    static const char* CAPTION_TEXT_CREATE;
    static const char* FORMAT_FILE;

    static const char* ERROR;
    static const char* ERROR_CREATE_FILE;

    static const char* COMPLETE;
    static const char* COMPLETE_CREATE;

    static const char* REQUEST_CREATE_TABLE_ORDERS;
    static const char* REQUEST_CREATE_TABLE_SECURITY;
    static const char* REQUEST_CREATE_TABLE_SERVICES;
    static const char* REQUEST_SELECT_TABLE_SECURITY;
    static const char* REQUEST_INSERT_RECORD_SECURITY;

    static const char* TYPE_DATA_BASE;

    static const char* VALUE_ID;
    static const char* VALUE_PASSWORD;
    static const char* VALUE_ACCESS;

    static const int INDEX_VALUE_ID;
    static const int INDEX_VALUE_PASSWORD;
    static const int INDEX_VALUE_ACCESS;

    bool fill_file(QString &name_file)const;
    bool copy_passwords(QString &name_file)const;
};

#endif // FORMFOROPTIONSDATABASE_H
