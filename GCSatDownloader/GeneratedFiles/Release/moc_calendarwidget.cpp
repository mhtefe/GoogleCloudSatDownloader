/****************************************************************************
** Meta object code from reading C++ file 'calendarwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../calendarwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendarwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalendarWidget_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalendarWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalendarWidget_t qt_meta_stringdata_CalendarWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CalendarWidget"
QT_MOC_LITERAL(1, 15, 12), // "goingToFirst"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "QDate&"
QT_MOC_LITERAL(4, 36, 13), // "goingToSecond"
QT_MOC_LITERAL(5, 50, 23), // "on_okPushButton_clicked"
QT_MOC_LITERAL(6, 74, 27), // "on_cancelPushButton_clicked"
QT_MOC_LITERAL(7, 102, 7) // "setDate"

    },
    "CalendarWidget\0goingToFirst\0\0QDate&\0"
    "goingToSecond\0on_okPushButton_clicked\0"
    "on_cancelPushButton_clicked\0setDate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalendarWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   45,    2, 0x08 /* Private */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    2,

       0        // eod
};

void CalendarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CalendarWidget *_t = static_cast<CalendarWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goingToFirst((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 1: _t->goingToSecond((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: _t->on_okPushButton_clicked(); break;
        case 3: _t->on_cancelPushButton_clicked(); break;
        case 4: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CalendarWidget::*_t)(QDate & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CalendarWidget::goingToFirst)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CalendarWidget::*_t)(QDate & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CalendarWidget::goingToSecond)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CalendarWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CalendarWidget.data,
      qt_meta_data_CalendarWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CalendarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalendarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalendarWidget.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CalendarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void CalendarWidget::goingToFirst(QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CalendarWidget::goingToSecond(QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
