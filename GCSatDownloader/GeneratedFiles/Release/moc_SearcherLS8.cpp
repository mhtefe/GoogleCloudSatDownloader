/****************************************************************************
** Meta object code from reading C++ file 'SearcherLS8.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SearcherLS8.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearcherLS8.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearcherLS8_t {
    QByteArrayData data[9];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearcherLS8_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearcherLS8_t qt_meta_stringdata_SearcherLS8 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SearcherLS8"
QT_MOC_LITERAL(1, 12, 13), // "searchStarted"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "searchFinished"
QT_MOC_LITERAL(4, 42, 13), // "currentStatus"
QT_MOC_LITERAL(5, 56, 1), // "i"
QT_MOC_LITERAL(6, 58, 1), // "j"
QT_MOC_LITERAL(7, 60, 17), // "foundElementsSize"
QT_MOC_LITERAL(8, 78, 6) // "DoWork"

    },
    "SearcherLS8\0searchStarted\0\0searchFinished\0"
    "currentStatus\0i\0j\0foundElementsSize\0"
    "DoWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearcherLS8[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    2,   41,    2, 0x06 /* Public */,
       7,    1,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SearcherLS8::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearcherLS8 *_t = static_cast<SearcherLS8 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->searchStarted(); break;
        case 1: _t->searchFinished(); break;
        case 2: _t->currentStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->foundElementsSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->DoWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SearcherLS8::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearcherLS8::searchStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SearcherLS8::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearcherLS8::searchFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SearcherLS8::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearcherLS8::currentStatus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SearcherLS8::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearcherLS8::foundElementsSize)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SearcherLS8::staticMetaObject = {
    { &SearcherBase::staticMetaObject, qt_meta_stringdata_SearcherLS8.data,
      qt_meta_data_SearcherLS8,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SearcherLS8::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearcherLS8::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearcherLS8.stringdata0))
        return static_cast<void*>(this);
    return SearcherBase::qt_metacast(_clname);
}

int SearcherLS8::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SearcherBase::qt_metacall(_c, _id, _a);
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
void SearcherLS8::searchStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SearcherLS8::searchFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SearcherLS8::currentStatus(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SearcherLS8::foundElementsSize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
