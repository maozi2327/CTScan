/****************************************************************************
** Meta object code from reading C++ file 'ctscan.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../ctscan.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ctscan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CTScan_t {
    QByteArrayData data[13];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTScan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTScan_t qt_meta_stringdata_CTScan = {
    {
QT_MOC_LITERAL(0, 0, 6), // "CTScan"
QT_MOC_LITERAL(1, 7, 28), // "on_ray1LineDetButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 29), // "on_ray1PanelDetButton_clicked"
QT_MOC_LITERAL(4, 67, 28), // "on_ray2LineDetButton_clicked"
QT_MOC_LITERAL(5, 96, 29), // "on_ray2PanelDetButton_clicked"
QT_MOC_LITERAL(6, 126, 3), // "cut"
QT_MOC_LITERAL(7, 130, 4), // "copy"
QT_MOC_LITERAL(8, 135, 5), // "paste"
QT_MOC_LITERAL(9, 141, 24), // "controllerNetWorkStsSlot"
QT_MOC_LITERAL(10, 166, 3), // "sts"
QT_MOC_LITERAL(11, 170, 12), // "errorMsgSlot"
QT_MOC_LITERAL(12, 183, 3) // "msg"

    },
    "CTScan\0on_ray1LineDetButton_clicked\0"
    "\0on_ray1PanelDetButton_clicked\0"
    "on_ray2LineDetButton_clicked\0"
    "on_ray2PanelDetButton_clicked\0cut\0"
    "copy\0paste\0controllerNetWorkStsSlot\0"
    "sts\0errorMsgSlot\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTScan[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void CTScan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTScan *_t = static_cast<CTScan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ray1LineDetButton_clicked(); break;
        case 1: _t->on_ray1PanelDetButton_clicked(); break;
        case 2: _t->on_ray2LineDetButton_clicked(); break;
        case 3: _t->on_ray2PanelDetButton_clicked(); break;
        case 4: _t->cut(); break;
        case 5: _t->copy(); break;
        case 6: _t->paste(); break;
        case 7: _t->controllerNetWorkStsSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->errorMsgSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CTScan::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CTScan.data,
      qt_meta_data_CTScan,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CTScan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTScan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTScan.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CTScan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
