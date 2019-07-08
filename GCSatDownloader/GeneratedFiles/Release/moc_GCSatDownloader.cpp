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
    QByteArrayData data[27];
    char stringdata0[571];
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
QT_MOC_LITERAL(12, 310, 34), // "on_pushButton_ShowIndex_S2_cl..."
QT_MOC_LITERAL(13, 345, 13), // "displayFolder"
QT_MOC_LITERAL(14, 359, 4), // "_ind"
QT_MOC_LITERAL(15, 364, 13), // "checkBoxSaves"
QT_MOC_LITERAL(16, 378, 39), // "on_pushButton_DownloadImage_L..."
QT_MOC_LITERAL(17, 418, 38), // "on_pushButton_DownloadImage_S..."
QT_MOC_LITERAL(18, 457, 19), // "afterSearchFinished"
QT_MOC_LITERAL(19, 477, 21), // "afterStatusbarMessage"
QT_MOC_LITERAL(20, 499, 19), // "updateCurrentStatus"
QT_MOC_LITERAL(21, 519, 1), // "i"
QT_MOC_LITERAL(22, 521, 1), // "j"
QT_MOC_LITERAL(23, 523, 18), // "showFileOfItem_LS8"
QT_MOC_LITERAL(24, 542, 3), // "row"
QT_MOC_LITERAL(25, 546, 6), // "column"
QT_MOC_LITERAL(26, 553, 17) // "showFileOfItem_S2"

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
    "on_pushButton_ShowIndex_S2_clicked\0"
    "displayFolder\0_ind\0checkBoxSaves\0"
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
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x0a /* Public */,
       4,    0,  112,    2, 0x0a /* Public */,
       5,    0,  113,    2, 0x08 /* Private */,
       6,    0,  114,    2, 0x08 /* Private */,
       7,    0,  115,    2, 0x08 /* Private */,
       8,    0,  116,    2, 0x08 /* Private */,
       9,    0,  117,    2, 0x08 /* Private */,
      10,    0,  118,    2, 0x08 /* Private */,
      11,    0,  119,    2, 0x08 /* Private */,
      12,    0,  120,    2, 0x08 /* Private */,
      13,    1,  121,    2, 0x08 /* Private */,
      15,    0,  124,    2, 0x08 /* Private */,
      16,    0,  125,    2, 0x08 /* Private */,
      17,    0,  126,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    1,  128,    2, 0x08 /* Private */,
      20,    2,  131,    2, 0x08 /* Private */,
      23,    2,  136,    2, 0x08 /* Private */,
      26,    2,  141,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   21,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,

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
        case 9: _t->on_pushButton_ShowIndex_S2_clicked(); break;
        case 10: _t->displayFolder((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->checkBoxSaves(); break;
        case 12: _t->on_pushButton_DownloadImage_LS8_clicked(); break;
        case 13: _t->on_pushButton_DownloadImage_S2_clicked(); break;
        case 14: _t->afterSearchFinished(); break;
        case 15: _t->afterStatusbarMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->updateCurrentStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->showFileOfItem_LS8((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->showFileOfItem_S2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
