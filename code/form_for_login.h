#ifndef FORM_FOR_LOGIN_H
#define FORM_FOR_LOGIN_H

#include <QWidget>
#include <QString>
#include "security.h"

namespace Ui {
class Form_For_Login;
}

class ForForLogin : public QWidget
{
    Q_OBJECT

public:
    explicit ForForLogin(QWidget *parent = 0);
    ~ForForLogin();

    bool is_close()const;
    Access get_access()const;

public slots:
    void show();

private slots:
    void input_ok();
    void on_button_for_guest_clicked();

private:
    Ui::Form_For_Login *ui;
    QString _id;
    QString _password;
    bool _close;
    Access _access;

    void check_access();
};

#endif // FORM_FOR_LOGIN_H
