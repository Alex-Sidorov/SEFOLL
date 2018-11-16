#ifndef FORM_FOR_OPTIONS_H
#define FORM_FOR_OPTIONS_H

#include "ui_form_for_add_password.h"
#include "ui_form_for_change_password.h"
#include "ui_form_for_delete_password.h"
#include "ui_form_for_change_access.h"
#include "security.h"

#include <QMessageBox>
#include <QWidget>

namespace Ui {
class FormForOptions;
}

class FormForOptions : public QWidget
{
    Q_OBJECT

public:
    explicit FormForOptions(QWidget *parent = 0);
    ~FormForOptions();

signals:
    void to_main_window();

private slots:
    void on_back_button_clicked();
    void on_delete_password_button_clicked();
    void on_change_password_button_clicked();
    void on_change_access_button_clicked();
    void on_add_password_button_clicked();
    void slot_add_password_ok_button_clicked();
    void slot_add_password_back_button_clicked();
    void slot_delete_password_ok_button_clicked();
    void slot_delete_password_back_button_clicked();
    void slot_change_password_ok_button_clicked();
    void slot_change_password_back_button_clicked();
    void slot_change_access_ok_button_clicked();
    void slot_change_access_back_button_clicked();

private:
    Ui::FormForOptions *ui;

    Ui::FormForAddPassword *window_for_add_password;
    Ui::FormForChangePassword *window_for_change_password;
    Ui::FormForChangeAccess *window_for_change_access;
    Ui::FormForDeletePassword *window_for_delete_password;

    QWidget *_widget_for_add_password;
    QWidget *_widget_for_change_password;
    QWidget *_widget_for_change_access;
    QWidget *_widget_for_delete_password;
};

#endif // FORM_FOR_OPTIONS_H
