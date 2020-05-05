/****************************************************************************
** Meta object code from reading C++ file 'linedetscaninterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../linedetscaninterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linedetscaninterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LineDetScanInterface_t {
    QByteArrayData data[11];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineDetScanInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineDetScanInterface_t qt_meta_stringdata_LineDetScanInterface = {
    {
QT_MOC_LITERAL(0, 0, 20), // "LineDetScanInterface"
QT_MOC_LITERAL(1, 21, 21), // "signalGraduationCount"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 8), // "in_count"
QT_MOC_LITERAL(4, 53, 13), // "infoMsgSignal"
QT_MOC_LITERAL(5, 67, 8), // "QString&"
QT_MOC_LITERAL(6, 76, 4), // "info"
QT_MOC_LITERAL(7, 81, 14), // "errorMsgSignal"
QT_MOC_LITERAL(8, 96, 5), // "error"
QT_MOC_LITERAL(9, 102, 12), // "bugMsgSignal"
QT_MOC_LITERAL(10, 115, 3) // "bug"

    },
    "LineDetScanInterface\0signalGraduationCount\0"
    "\0in_count\0infoMsgSignal\0QString&\0info\0"
    "errorMsgSignal\0error\0bugMsgSignal\0bug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineDetScanInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       7,    1,   40,    2, 0x06 /* Public */,
       9,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    8,
    QMetaType::Void, 0x80000000 | 5,   10,

       0        // eod
};

void LineDetScanInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineDetScanInterface *_t = static_cast<LineDetScanInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalGraduationCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->infoMsgSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->errorMsgSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->bugMsgSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LineDetScanInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineDetScanInterface::signalGraduationCount)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LineDetScanInterface::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineDetScanInterface::infoMsgSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LineDetScanInterface::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineDetScanInterface::errorMsgSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LineDetScanInterface::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineDetScanInterface::bugMsgSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LineDetScanInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LineDetScanInterface.data,
      qt_meta_data_LineDetScanInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LineDetScanInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineDetScanInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineDetScanInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LineDetScanInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LineDetScanInterface::signalGraduationCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LineDetScanInterface::infoMsgSignal(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LineDetScanInterface::errorMsgSignal(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LineDetScanInterface::bugMsgSignal(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
