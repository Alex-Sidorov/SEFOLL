#ifndef FORM_FOR_LOGIN_H
#define FORM_FOR_LOGIN_H

#include "security.h"

#include <QSharedPointer>
#include <QWidget>
#include <QString>

namespace Ui {
class FormForLogin;
}

class FormForLogin : public QWidget
{
    Q_OBJECT

public:
    bool is_close()const;
    Access get_access()const;
    explicit FormForLogin(QWidget *parent = 0);
    FormForLogin(const FormForLogin&) = delete;
    virtual ~FormForLogin(){}

public slots:
    void show();

private slots:
    void input_ok();
    void on_button_for_guest_clicked();

private:
    QSharedPointer<Ui::FormForLogin> ui;
    QString _id;
    QString _password;
    Access _access;

    static const char* MESSAGE_ERROR;
    bool _close;

    void check_access();
    void clear_form()const;
};

#endif // FORM_FOR_LOGIN_H
