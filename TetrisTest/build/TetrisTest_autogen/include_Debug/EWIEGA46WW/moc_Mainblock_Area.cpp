/****************************************************************************
** Meta object code from reading C++ file 'Mainblock_Area.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Mainblock_Area.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mainblock_Area.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mainblock_Area_t {
    QByteArrayData data[10];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mainblock_Area_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mainblock_Area_t qt_meta_stringdata_Mainblock_Area = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Mainblock_Area"
QT_MOC_LITERAL(1, 15, 11), // "OnTheBottom"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "SingelGetScope"
QT_MOC_LITERAL(4, 43, 8), // "addScope"
QT_MOC_LITERAL(5, 52, 10), // "MainUpdate"
QT_MOC_LITERAL(6, 63, 6), // "rotate"
QT_MOC_LITERAL(7, 70, 4), // "down"
QT_MOC_LITERAL(8, 75, 17), // "translationtoLeft"
QT_MOC_LITERAL(9, 93, 18) // "translationtoRight"

    },
    "Mainblock_Area\0OnTheBottom\0\0SingelGetScope\0"
    "addScope\0MainUpdate\0rotate\0down\0"
    "translationtoLeft\0translationtoRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mainblock_Area[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mainblock_Area::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mainblock_Area *_t = static_cast<Mainblock_Area *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnTheBottom(); break;
        case 1: _t->SingelGetScope((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->MainUpdate(); break;
        case 3: _t->rotate(); break;
        case 4: _t->down(); break;
        case 5: _t->translationtoLeft(); break;
        case 6: _t->translationtoRight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Mainblock_Area::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mainblock_Area::OnTheBottom)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Mainblock_Area::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mainblock_Area::SingelGetScope)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Mainblock_Area::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Mainblock_Area.data,
      qt_meta_data_Mainblock_Area,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Mainblock_Area::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mainblock_Area::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mainblock_Area.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Mainblock_Area::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Mainblock_Area::OnTheBottom()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Mainblock_Area::SingelGetScope(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
