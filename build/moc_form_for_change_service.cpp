/****************************************************************************
** Meta object code from reading C++ file 'form_for_change_service.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/SEFOLL-master/code/form_for_change_service.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_for_change_service.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormForChangeService_t {
    QByteArrayData data[10];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormForChangeService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormForChangeService_t qt_meta_stringdata_FormForChangeService = {
    {
QT_MOC_LITERAL(0, 0, 20), // "FormForChangeService"
QT_MOC_LITERAL(1, 21, 14), // "to_main_window"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "changed_data"
QT_MOC_LITERAL(4, 50, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(5, 73, 24), // "on_data_services_clicked"
QT_MOC_LITERAL(6, 98, 11), // "QModelIndex"
QT_MOC_LITERAL(7, 110, 5), // "index"
QT_MOC_LITERAL(8, 116, 30), // "on_enter_change_button_clicked"
QT_MOC_LITERAL(9, 147, 24) // "slot_fields_form_changed"

    },
    "FormForChangeService\0to_main_window\0"
    "\0changed_data\0on_back_button_clicked\0"
    "on_data_services_clicked\0QModelIndex\0"
    "index\0on_enter_change_button_clicked\0"
    "slot_fields_form_changed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormForChangeService[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   48,    2, 0x08 /* Private */,
       5,    1,   49,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormForChangeService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormForChangeService *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_main_window(); break;
        case 1: _t->changed_data((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_back_button_clicked(); break;
        case 3: _t->on_data_services_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_enter_change_button_clicked(); break;
        case 5: _t->slot_fields_form_changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormForChangeService::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormForChangeService::to_main_window)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormForChangeService::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormForChangeService::changed_data)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormForChangeService::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormForChangeService.data,
    qt_meta_data_FormForChangeService,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormForChangeService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormForChangeService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormForChangeService.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormForChangeService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FormForChangeService::to_main_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormForChangeService::changed_data(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
