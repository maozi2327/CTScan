/****************************************************************************
** Meta object code from reading C++ file 'linedetscanwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../linedetscanwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linedetscanwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LineDetScanWidget_t {
    QByteArrayData data[8];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineDetScanWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineDetScanWidget_t qt_meta_stringdata_LineDetScanWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "LineDetScanWidget"
QT_MOC_LITERAL(1, 18, 14), // "showMotorTable"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 25), // "on_Ct3StartButton_clicked"
QT_MOC_LITERAL(4, 60, 24), // "on_saveDirButton_clicked"
QT_MOC_LITERAL(5, 85, 44), // "on_ct3MultiLayerComboBox_curr..."
QT_MOC_LITERAL(6, 130, 7), // "in_text"
QT_MOC_LITERAL(7, 138, 30) // "on_ct3LayerPosLineEdit_returnd"

    },
    "LineDetScanWidget\0showMotorTable\0\0"
    "on_Ct3StartButton_clicked\0"
    "on_saveDirButton_clicked\0"
    "on_ct3MultiLayerComboBox_currentIndexChanged\0"
    "in_text\0on_ct3LayerPosLineEdit_returnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineDetScanWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void LineDetScanWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineDetScanWidget *_t = static_cast<LineDetScanWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMotorTable(); break;
        case 1: _t->on_Ct3StartButton_clicked(); break;
        case 2: _t->on_saveDirButton_clicked(); break;
        case 3: _t->on_ct3MultiLayerComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_ct3LayerPosLineEdit_returnd(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LineDetScanWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LineDetScanWidget.data,
      qt_meta_data_LineDetScanWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LineDetScanWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineDetScanWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineDetScanWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LineDetScanWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
