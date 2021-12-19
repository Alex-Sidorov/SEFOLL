/****************************************************************************
** Meta object code from reading C++ file 'formforoptionsdatabase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../code/formforoptionsdatabase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formforoptionsdatabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormForOptionsDataBase_t {
    QByteArrayData data[9];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormForOptionsDataBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormForOptionsDataBase_t qt_meta_stringdata_FormForOptionsDataBase = {
    {
QT_MOC_LITERAL(0, 0, 22), // "FormForOptionsDataBase"
QT_MOC_LITERAL(1, 23, 14), // "to_main_window"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "changed_data_base"
QT_MOC_LITERAL(4, 57, 8), // "QString&"
QT_MOC_LITERAL(5, 66, 14), // "name_data_base"
QT_MOC_LITERAL(6, 81, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(7, 104, 34), // "on_select_data_base_button_cl..."
QT_MOC_LITERAL(8, 139, 34) // "on_create_data_base_button_cl..."

    },
    "FormForOptionsDataBase\0to_main_window\0"
    "\0changed_data_base\0QString&\0name_data_base\0"
    "on_back_button_clicked\0"
    "on_select_data_base_button_clicked\0"
    "on_create_data_base_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormForOptionsDataBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormForOptionsDataBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormForOptionsDataBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_main_window(); break;
        case 1: _t->changed_data_base((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_back_button_clicked(); break;
        case 3: _t->on_select_data_base_button_clicked(); break;
        case 4: _t->on_create_data_base_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormForOptionsDataBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormForOptionsDataBase::to_main_window)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormForOptionsDataBase::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormForOptionsDataBase::changed_data_base)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormForOptionsDataBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormForOptionsDataBase.data,
    qt_meta_data_FormForOptionsDataBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormForOptionsDataBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormForOptionsDataBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormForOptionsDataBase.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormForOptionsDataBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FormForOptionsDataBase::to_main_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormForOptionsDataBase::changed_data_base(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
