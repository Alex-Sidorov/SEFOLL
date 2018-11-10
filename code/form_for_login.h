#ifndef FORM_FOR_LOGIN_H
#define FORM_FOR_LOGIN_H

#include <QWidget>
#include <QString>

namespace Ui {
class Form_For_Login;
}

class Form_For_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Form_For_Login(QWidget *parent = 0);
    ~Form_For_Login();

    bool is_close()const;

public slots:
    void show();

private slots:
    void input_ok();

private:
    Ui::Form_For_Login *ui;

    QString _id;
    QString _password;

    bool _close;

    void check_access();
};

#endif // FORM_FOR_LOGIN_H
