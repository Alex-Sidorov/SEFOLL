#-------------------------------------------------
#
# Project created by QtCreator 2018-11-17T19:26:06
#
#-------------------------------------------------

QT  += core gui
QT  += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEFOLL
TEMPLATE = app


SOURCES += \
    form_for_add_service.cpp \
    form_for_change_service.cpp \
    form_for_delete_service.cpp \
    form_for_give_order.cpp \
    form_for_login.cpp \
    form_for_options.cpp \
    form_for_show_data.cpp \
    form_for_show_order.cpp \
    main.cpp \
    mainwindow.cpp \
    new_spinbox.cpp \
    order.cpp \
    security.cpp \
    formforoptionsdatabase.cpp

HEADERS  += \
    Access.h \
    dataBase/AbstractDataUserWorker.h \
    dataBase/AbstractOrderRW.h \
    dataBase/AbstractServicesWorker.h \
    form_for_add_service.h \
    form_for_change_service.h \
    form_for_delete_service.h \
    form_for_give_order.h \
    form_for_login.h \
    form_for_options.h \
    form_for_show_data.h \
    form_for_show_order.h \
    Info_of_ordered_service.h \
    mainwindow.h \
    new_spinbox.h \
    order.h \
    security.h \
    formforoptionsdatabase.h

FORMS += \
    form_for_add_password.ui \
    form_for_add_service.ui \
    form_for_change_access.ui \
    form_for_change_password.ui \
    form_for_change_service.ui \
    form_for_delete_password.ui \
    form_for_delete_service.ui \
    form_for_give_order.ui \
    form_for_login.ui \
    form_for_options.ui \
    form_for_show_data.ui \
    form_for_show_order.ui \
    mainwindow.ui \
    formforoptionsdatabase.ui
