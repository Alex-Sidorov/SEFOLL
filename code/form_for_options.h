#ifndef FORM_FOR_OPTIONS_H
#define FORM_FOR_OPTIONS_H

#include "ui_form_for_add_password.h"
#include "ui_form_for_change_password.h"
#include "ui_form_for_delete_password.h"
#include "ui_form_for_change_access.h"
#include "security.h"

#include <QMessageBox>
#include <QWidget>
#include <QSharedPointer>

namespace Ui {
class FormForOptions;
}

class FormForOptions : public QWidget
{
    Q_OBJECT

public:
    explicit FormForOptions(QWidget *parent = nullptr);
    FormForOptions(const FormForOptions&) = delete;
    virtual ~FormForOptions(){}

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
    QSharedPointer<Ui::FormForOptions>ui;
    QSharedPointer<Ui::FormForAddPassword> window_for_add_password;
    QSharedPointer<Ui::FormForChangePassword> window_for_change_password;
    QSharedPointer<Ui::FormForChangeAccess> window_for_change_access;
    QSharedPointer<Ui::FormForDeletePassword> window_for_delete_password;

    QSharedPointer<QWidget> _widget_for_add_password;
    QSharedPointer<QWidget> _widget_for_change_password;
    QSharedPointer<QWidget> _widget_for_change_access;
    QSharedPointer<QWidget> _widget_for_delete_password;

    static const char* RESUALT;
    static const char* ERROR;
    static const char* MESSAGE_ERROR_ADD_USER;
    static const char* MESSAGE_ERROR_DELETE_USER;
    static const char* MESSAGE_USER_WAS_ADD;
    static const char* MESSAGE_USER_WAS_DELETE;
    static const char* MESSAGE_ERROR_CHANGE_DATA;
    static const char* MESSAGE_DATA_CHANGED;

    static const int INDEX_FIRST_ACCESS;
};

#endif // FORM_FOR_OPTIONS_H
