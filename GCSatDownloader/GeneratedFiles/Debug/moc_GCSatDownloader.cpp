/****************************************************************************
** Meta object code from reading C++ file 'GCSatDownloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GCSatDownloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GCSatDownloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomProgressBarTableWidgetItem_t {
    QByteArrayData data[1];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomProgressBarTableWidgetItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomProgressBarTableWidgetItem_t qt_meta_stringdata_CustomProgressBarTableWidgetItem = {
    {
QT_MOC_LITERAL(0, 0, 32) // "CustomProgressBarTableWidgetItem"

    },
    "CustomProgressBarTableWidgetItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomProgressBarTableWidgetItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CustomProgressBarTableWidgetItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CustomProgressBarTableWidgetItem::staticMetaObject = {
    { &QProgressBar::staticMetaObject, qt_meta_stringdata_CustomProgressBarTableWidgetItem.data,
      qt_meta_data_CustomProgressBarTableWidgetItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CustomProgressBarTableWidgetItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomProgressBarTableWidgetItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomProgressBarTableWidgetItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QTableWidgetItem"))
        return static_cast< QTableWidgetItem*>(this);
    return QProgressBar::qt_metacast(_clname);
}

int CustomProgressBarTableWidgetItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProgressBar::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_GCSatDownloader_t {
    QByteArrayData data[23];
    char stringdata0[503];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GCSatDownloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GCSatDownloader_t qt_meta_stringdata_GCSatDownloader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GCSatDownloader"
QT_MOC_LITERAL(1, 16, 21), // "afterDownloadFinished"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "str"
QT_MOC_LITERAL(4, 43, 25), // "afterAllDownloadsFinished"
QT_MOC_LITERAL(5, 69, 32), // "on_pushButton_search_LS8_clicked"
QT_MOC_LITERAL(6, 102, 31), // "on_pushButton_search_S2_clicked"
QT_MOC_LITERAL(7, 134, 30), // "on_pushButton_stop_LS8_clicked"
QT_MOC_LITERAL(8, 165, 29), // "on_pushButton_stop_S2_clicked"
QT_MOC_LITERAL(9, 195, 39), // "on_pushButton_DownloadIndex_L..."
QT_MOC_LITERAL(10, 235, 38), // "on_pushButton_DownloadIndex_S..."
QT_MOC_LITERAL(11, 274, 35), // "on_pushButton_ShowIndex_LS8_c..."
QT_MOC_LITERAL(12, 310, 39), // "on_pushButton_DownloadImage_L..."
QT_MOC_LITERAL(13, 350, 38), // "on_pushButton_DownloadImage_S..."
QT_MOC_LITERAL(14, 389, 19), // "afterSearchFinished"
QT_MOC_LITERAL(15, 409, 21), // "afterStatusbarMessage"
QT_MOC_LITERAL(16, 431, 19), // "updateCurrentStatus"
QT_MOC_LITERAL(17, 451, 1), // "i"
QT_MOC_LITERAL(18, 453, 1), // "j"
QT_MOC_LITERAL(19, 455, 18), // "showFileOfItem_LS8"
QT_MOC_LITERAL(20, 474, 3), // "row"
QT_MOC_LITERAL(21, 478, 6), // "column"
QT_MOC_LITERAL(22, 485, 17) // "showFileOfItem_S2"

    },
    "GCSatDownloader\0afterDownloadFinished\0"
    "\0str\0afterAllDownloadsFinished\0"
    "on_pushButton_search_LS8_clicked\0"
    "on_pushButton_search_S2_clicked\0"
    "on_pushButton_stop_LS8_clicked\0"
    "on_pushButton_stop_S2_clicked\0"
    "on_pushButton_DownloadIndex_LS8_clicked\0"
    "on_pushButton_DownloadIndex_S2_clicked\0"
    "on_pushButton_ShowIndex_LS8_clicked\0"
    "on_pushButton_DownloadImage_LS8_clicked\0"
    "on_pushButton_DownloadImage_S2_clicked\0"
    "afterSearchFinished\0afterStatusbarMessage\0"
    "updateCurrentStatus\0i\0j\0showFileOfItem_LS8\0"
    "row\0column\0showFileOfItem_S2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GCSatDownloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x0a /* Public */,
       4,    0,   97,    2, 0x0a /* Public */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    1,  108,    2, 0x08 /* Private */,
      16,    2,  111,    2, 0x08 /* Private */,
      19,    2,  116,    2, 0x08 /* Private */,
      22,    2,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,

       0        // eod
};

void GCSatDownloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GCSatDownloader *_t = static_cast<GCSatDownloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->afterDownloadFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->afterAllDownloadsFinished(); break;
        case 2: _t->on_pushButton_search_LS8_clicked(); break;
        case 3: _t->on_pushButton_search_S2_clicked(); break;
        case 4: _t->on_pushButton_stop_LS8_clicked(); break;
        case 5: _t->on_pushButton_stop_S2_clicked(); break;
        case 6: _t->on_pushButton_DownloadIndex_LS8_clicked(); break;
        case 7: _t->on_pushButton_DownloadIndex_S2_clicked(); break;
        case 8: _t->on_pushButton_ShowIndex_LS8_clicked(); break;
        case 9: _t->on_pushButton_DownloadImage_LS8_clicked(); break;
        case 10: _t->on_pushButton_DownloadImage_S2_clicked(); break;
        case 11: _t->afterSearchFinished(); break;
        case 12: _t->afterStatusbarMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->updateCurrentStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->showFileOfItem_LS8((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->showFileOfItem_S2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject GCSatDownloader::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GCSatDownloader.data,
      qt_meta_data_GCSatDownloader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GCSatDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GCSatDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GCSatDownloader.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GCSatDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
