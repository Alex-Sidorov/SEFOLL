#include "mainwindow.h"
#include <QApplication>
#include <form_for_login.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int code = 0;
    MainWindow window;
    FormForLogin *login = new FormForLogin;
    while(!code)
    {
        login->show();
        code = a.exec();
        if(login->is_close() || code)
        {
            break;
        }
        window.set_access(login->get_access());
        window.show();
        code = a.exec();
    }
    return code;
}
