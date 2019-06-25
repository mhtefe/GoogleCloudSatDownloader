/****************************************************************************
** Meta object code from reading C++ file 'landsatimagedownloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GCSatDownloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'landsatimagedownloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LandsatImageDownloader_t {
    QByteArrayData data[21];
    char stringdata0[449];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LandsatImageDownloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LandsatImageDownloader_t qt_meta_stringdata_LandsatImageDownloader = {
    {
QT_MOC_LITERAL(0, 0, 22), // "LandsatImageDownloader"
QT_MOC_LITERAL(1, 23, 21), // "afterDownloadFinished"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 3), // "str"
QT_MOC_LITERAL(4, 50, 25), // "afterAllDownloadsFinished"
QT_MOC_LITERAL(5, 76, 32), // "on_pushButton_search_LS8_clicked"
QT_MOC_LITERAL(6, 109, 31), // "on_pushButton_search_S2_clicked"
QT_MOC_LITERAL(7, 141, 30), // "on_pushButton_stop_LS8_clicked"
QT_MOC_LITERAL(8, 172, 29), // "on_pushButton_stop_S2_clicked"
QT_MOC_LITERAL(9, 202, 39), // "on_pushButton_DownloadIndex_L..."
QT_MOC_LITERAL(10, 242, 38), // "on_pushButton_DownloadIndex_S..."
QT_MOC_LITERAL(11, 281, 35), // "on_pushButton_ShowIndex_LS8_c..."
QT_MOC_LITERAL(12, 317, 39), // "on_pushButton_DownloadImage_L..."
QT_MOC_LITERAL(13, 357, 19), // "afterSearchFinished"
QT_MOC_LITERAL(14, 377, 21), // "afterStatusbarMessage"
QT_MOC_LITERAL(15, 399, 19), // "updateCurrentStatus"
QT_MOC_LITERAL(16, 419, 1), // "i"
QT_MOC_LITERAL(17, 421, 1), // "j"
QT_MOC_LITERAL(18, 423, 14), // "showFileOfItem"
QT_MOC_LITERAL(19, 438, 3), // "row"
QT_MOC_LITERAL(20, 442, 6) // "column"

    },
    "LandsatImageDownloader\0afterDownloadFinished\0"
    "\0str\0afterAllDownloadsFinished\0"
    "on_pushButton_search_LS8_clicked\0"
    "on_pushButton_search_S2_clicked\0"
    "on_pushButton_stop_LS8_clicked\0"
    "on_pushButton_stop_S2_clicked\0"
    "on_pushButton_DownloadIndex_LS8_clicked\0"
    "on_pushButton_DownloadIndex_S2_clicked\0"
    "on_pushButton_ShowIndex_LS8_clicked\0"
    "on_pushButton_DownloadImage_LS8_clicked\0"
    "afterSearchFinished\0afterStatusbarMessage\0"
    "updateCurrentStatus\0i\0j\0showFileOfItem\0"
    "row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LandsatImageDownloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       4,    0,   87,    2, 0x0a /* Public */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      15,    2,  100,    2, 0x08 /* Private */,
      18,    2,  105,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,

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
        case 10: _t->afterSearchFinished(); break;
        case 11: _t->afterStatusbarMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->updateCurrentStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->showFileOfItem_LS8((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject GCSatDownloader::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LandsatImageDownloader.data,
      qt_meta_data_LandsatImageDownloader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GCSatDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GCSatDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LandsatImageDownloader.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GCSatDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
