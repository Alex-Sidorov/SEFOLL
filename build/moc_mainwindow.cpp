/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/SEFOLL/code/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "on_give_order_button_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 29), // "on_add_service_button_clicked"
QT_MOC_LITERAL(4, 71, 32), // "on_change_service_button_clicked"
QT_MOC_LITERAL(5, 104, 32), // "on_delete_service_button_clicked"
QT_MOC_LITERAL(6, 137, 16), // "show_main_window"
QT_MOC_LITERAL(7, 154, 30), // "slot_clicked_options_data_base"
QT_MOC_LITERAL(8, 185, 22), // "slot_changed_data_base"
QT_MOC_LITERAL(9, 208, 8), // "QString&"
QT_MOC_LITERAL(10, 217, 14), // "name_data_base"
QT_MOC_LITERAL(11, 232, 11), // "add_service"
QT_MOC_LITERAL(12, 244, 12), // "upload_table"
QT_MOC_LITERAL(13, 257, 5), // "index"
QT_MOC_LITERAL(14, 263, 12), // "QVector<int>"
QT_MOC_LITERAL(15, 276, 28), // "on_show_order_button_clicked"
QT_MOC_LITERAL(16, 305, 18), // "on_options_clicked"
QT_MOC_LITERAL(17, 324, 27) // "on_show_data_button_clicked"

    },
    "MainWindow\0on_give_order_button_clicked\0"
    "\0on_add_service_button_clicked\0"
    "on_change_service_button_clicked\0"
    "on_delete_service_button_clicked\0"
    "show_main_window\0slot_clicked_options_data_base\0"
    "slot_changed_data_base\0QString&\0"
    "name_data_base\0add_service\0upload_table\0"
    "index\0QVector<int>\0on_show_order_button_clicked\0"
    "on_options_clicked\0on_show_data_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    1,   85,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_give_order_button_clicked(); break;
        case 1: _t->on_add_service_button_clicked(); break;
        case 2: _t->on_change_service_button_clicked(); break;
        case 3: _t->on_delete_service_button_clicked(); break;
        case 4: _t->show_main_window(); break;
        case 5: _t->slot_clicked_options_data_base(); break;
        case 6: _t->slot_changed_data_base((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->add_service(); break;
        case 8: _t->upload_table((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->upload_table((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        case 10: _t->on_show_order_button_clicked(); break;
        case 11: _t->on_options_clicked(); break;
        case 12: _t->on_show_data_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
