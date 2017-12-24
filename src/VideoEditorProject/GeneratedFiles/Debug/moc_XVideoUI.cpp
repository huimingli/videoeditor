/****************************************************************************
** Meta object code from reading C++ file 'XVideoUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XVideoUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XVideoUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XVideoUI_t {
    QByteArrayData data[15];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XVideoUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XVideoUI_t qt_meta_stringdata_XVideoUI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "XVideoUI"
QT_MOC_LITERAL(1, 9, 4), // "open"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 11), // "sliderPress"
QT_MOC_LITERAL(4, 27, 13), // "sliderRelease"
QT_MOC_LITERAL(5, 41, 6), // "setPos"
QT_MOC_LITERAL(6, 48, 3), // "pos"
QT_MOC_LITERAL(7, 52, 3), // "set"
QT_MOC_LITERAL(8, 56, 11), // "exportVideo"
QT_MOC_LITERAL(9, 68, 9), // "exportEnd"
QT_MOC_LITERAL(10, 78, 4), // "play"
QT_MOC_LITERAL(11, 83, 5), // "pause"
QT_MOC_LITERAL(12, 89, 4), // "mark"
QT_MOC_LITERAL(13, 94, 5), // "blend"
QT_MOC_LITERAL(14, 100, 5) // "merge"

    },
    "XVideoUI\0open\0\0sliderPress\0sliderRelease\0"
    "setPos\0pos\0set\0exportVideo\0exportEnd\0"
    "play\0pause\0mark\0blend\0merge"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XVideoUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void XVideoUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XVideoUI *_t = static_cast<XVideoUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->sliderPress(); break;
        case 2: _t->sliderRelease(); break;
        case 3: _t->setPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->set(); break;
        case 5: _t->exportVideo(); break;
        case 6: _t->exportEnd(); break;
        case 7: _t->play(); break;
        case 8: _t->pause(); break;
        case 9: _t->mark(); break;
        case 10: _t->blend(); break;
        case 11: _t->merge(); break;
        default: ;
        }
    }
}

const QMetaObject XVideoUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_XVideoUI.data,
      qt_meta_data_XVideoUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *XVideoUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XVideoUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XVideoUI.stringdata0))
        return static_cast<void*>(const_cast< XVideoUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int XVideoUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
