#include "mainwindow.h"
#include "form_for_login.h"

#include <QSharedPointer>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    int code = 0;
    MainWindow window;
    QSharedPointer<FormForLogin> login(new FormForLogin);
    while(!code)
    {
        login->show();
        code = application.exec();
        if(login->is_close() || code)
        {
            break;
        }
        window.set_access(login->get_access());
        window.show();
        code = application.exec();
    }
    return code;
}
