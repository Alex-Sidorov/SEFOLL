#include "mainwindow.h"
#include <QApplication>
#include <form_for_login.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int code = 0;
    MainWindow w;
    Form_For_Login *login = new Form_For_Login;

    while(!code)
    {
        login->show();
        code = a.exec();
        if(login->is_close() || code)
        {
            break;
        }
        w.show();
        code = a.exec();
    }

    return code;
}
