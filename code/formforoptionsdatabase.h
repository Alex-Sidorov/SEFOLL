#ifndef FORMFOROPTIONSDATABASE_H
#define FORMFOROPTIONSDATABASE_H

#include <QWidget>
#include <QFileDialog>
#include <QDate>
#include <QMessageBox>

#include "dataBase/AbstractDataBaseOptions.h"

namespace Ui {
class FormForOptionsDataBase;
}

class FormForOptionsDataBase : public QWidget
{
    Q_OBJECT

public:
    void set_path_data_base(QString &path_data_base);
    explicit FormForOptionsDataBase(AbstractDataBaseOptions *database, QWidget *parent = nullptr);
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

    AbstractDataBaseOptions* m_database;

    static const char* CAPTION_TEXT_SELECT;

    static const char* CAPTION_TEXT_CREATE;
    static const char* FORMAT_FILE;

    static const char* ERROR;
    static const char* ERROR_CREATE_FILE;

    static const char* COMPLETE;
    static const char* COMPLETE_CREATE;
};

#endif // FORMFOROPTIONSDATABASE_H
