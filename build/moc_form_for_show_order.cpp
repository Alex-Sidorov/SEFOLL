/****************************************************************************
** Meta object code from reading C++ file 'form_for_show_order.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../code/form_for_show_order.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_for_show_order.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormForShowOrder_t {
    QByteArrayData data[9];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormForShowOrder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormForShowOrder_t qt_meta_stringdata_FormForShowOrder = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FormForShowOrder"
QT_MOC_LITERAL(1, 17, 14), // "to_main_window"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "slot_delete_order"
QT_MOC_LITERAL(4, 51, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(5, 74, 28), // "on_number_order_valueChanged"
QT_MOC_LITERAL(6, 103, 6), // "number"
QT_MOC_LITERAL(7, 110, 23), // "on_enter_button_clicked"
QT_MOC_LITERAL(8, 134, 26) // "on_complete_button_clicked"

    },
    "FormForShowOrder\0to_main_window\0\0"
    "slot_delete_order\0on_back_button_clicked\0"
    "on_number_order_valueChanged\0number\0"
    "on_enter_button_clicked\0"
    "on_complete_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormForShowOrder[] = {

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
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormForShowOrder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormForShowOrder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_main_window(); break;
        case 1: _t->slot_delete_order(); break;
        case 2: _t->on_back_button_clicked(); break;
        case 3: _t->on_number_order_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_enter_button_clicked(); break;
        case 5: _t->on_complete_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormForShowOrder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormForShowOrder::to_main_window)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormForShowOrder::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormForShowOrder.data,
    qt_meta_data_FormForShowOrder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormForShowOrder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormForShowOrder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormForShowOrder.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormForShowOrder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FormForShowOrder::to_main_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
