/****************************************************************************
** Meta object code from reading C++ file 'formforworkers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../code/formforworkers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formforworkers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormForWorkers_t {
    QByteArrayData data[10];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormForWorkers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormForWorkers_t qt_meta_stringdata_FormForWorkers = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FormForWorkers"
QT_MOC_LITERAL(1, 15, 14), // "to_main_window"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "show"
QT_MOC_LITERAL(4, 36, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(5, 59, 26), // "on_addWorkerButton_clicked"
QT_MOC_LITERAL(6, 86, 22), // "on_workers_itemClicked"
QT_MOC_LITERAL(7, 109, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(8, 127, 4), // "item"
QT_MOC_LITERAL(9, 132, 29) // "on_deleteWorkerButton_clicked"

    },
    "FormForWorkers\0to_main_window\0\0show\0"
    "on_back_button_clicked\0"
    "on_addWorkerButton_clicked\0"
    "on_workers_itemClicked\0QTableWidgetItem*\0"
    "item\0on_deleteWorkerButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormForWorkers[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void FormForWorkers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormForWorkers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_main_window(); break;
        case 1: _t->show(); break;
        case 2: _t->on_back_button_clicked(); break;
        case 3: _t->on_addWorkerButton_clicked(); break;
        case 4: _t->on_workers_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_deleteWorkerButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormForWorkers::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormForWorkers::to_main_window)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormForWorkers::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormForWorkers.data,
    qt_meta_data_FormForWorkers,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormForWorkers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormForWorkers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormForWorkers.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormForWorkers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FormForWorkers::to_main_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
