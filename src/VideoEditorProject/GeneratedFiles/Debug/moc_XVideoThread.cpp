/****************************************************************************
** Meta object code from reading C++ file 'XVideoThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XVideoThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XVideoThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XVideoThread_t {
    QByteArrayData data[7];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XVideoThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XVideoThread_t qt_meta_stringdata_XVideoThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "XVideoThread"
QT_MOC_LITERAL(1, 13, 10), // "viewImage1"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 33, 10), // "viewImage2"
QT_MOC_LITERAL(5, 44, 7), // "viewDes"
QT_MOC_LITERAL(6, 52, 7) // "saveEnd"

    },
    "XVideoThread\0viewImage1\0\0cv::Mat\0"
    "viewImage2\0viewDes\0saveEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XVideoThread[] = {

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
       5,    1,   40,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

       0        // eod
};

void XVideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XVideoThread *_t = static_cast<XVideoThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->viewImage1((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->viewImage2((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->viewDes((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->saveEnd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XVideoThread::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XVideoThread::viewImage1)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (XVideoThread::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XVideoThread::viewImage2)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (XVideoThread::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XVideoThread::viewDes)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (XVideoThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XVideoThread::saveEnd)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject XVideoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_XVideoThread.data,
      qt_meta_data_XVideoThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *XVideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XVideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XVideoThread.stringdata0))
        return static_cast<void*>(const_cast< XVideoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int XVideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void XVideoThread::viewImage1(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XVideoThread::viewImage2(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XVideoThread::viewDes(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XVideoThread::saveEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
