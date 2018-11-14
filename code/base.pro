#-------------------------------------------------
#
# Project created by QtCreator 2018-08-22T11:53:25
#
#-------------------------------------------------

QT       += core gui
QT	 += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = base
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form_for_add_service.cpp \
    form_for_change_service.cpp \
    form_for_delete_service.cpp \
    form_for_give_order.cpp \
    form_for_show_data.cpp \
    order.cpp \
    new_spinbox.cpp \
    form_for_show_order.cpp \
    form_for_login.cpp \
    form_for_options.cpp

HEADERS  += mainwindow.h \
    form_for_add_service.h \
    form_for_change_service.h \
    form_for_delete_service.h \
    form_for_give_order.h \
    form_for_show_data.h \
    order.h \
    Info_of_ordered_service.h \
    new_spinbox.h \
    form_for_show_order.h \
    form_for_login.h \
    security.h \
    form_for_options.h

FORMS    += mainwindow.ui \
    form_for_add_service.ui \
    form_for_change_service.ui \
    form_for_delete_service.ui \
    form_for_give_order.ui \
    form_for_show_data.ui \
    form_for_show_order.ui \
    form_for_login.ui \
    form_for_options.ui \
    form_for_change_password.ui \
    form_for_delete_password.ui \
    form_for_add_password.ui \
    form_for_change_access.ui
