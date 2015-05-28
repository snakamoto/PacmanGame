/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Connection_t {
    QByteArrayData data[13];
    char stringdata[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connection_t qt_meta_stringdata_Connection = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Connection"
QT_MOC_LITERAL(1, 11, 18), // "OnNewTowerReceived"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "PlayerSyncStruct"
QT_MOC_LITERAL(4, 48, 1), // "t"
QT_MOC_LITERAL(5, 50, 18), // "OnNewEnemyReceived"
QT_MOC_LITERAL(6, 69, 11), // "EnemyStruct"
QT_MOC_LITERAL(7, 81, 1), // "e"
QT_MOC_LITERAL(8, 83, 18), // "OnNewPSyncRecieved"
QT_MOC_LITERAL(9, 102, 1), // "s"
QT_MOC_LITERAL(10, 104, 21), // "OnRemoveEnemyRecieved"
QT_MOC_LITERAL(11, 126, 17), // "RemoveEnemyStruct"
QT_MOC_LITERAL(12, 144, 12) // "on_readyRead"

    },
    "Connection\0OnNewTowerReceived\0\0"
    "PlayerSyncStruct\0t\0OnNewEnemyReceived\0"
    "EnemyStruct\0e\0OnNewPSyncRecieved\0s\0"
    "OnRemoveEnemyRecieved\0RemoveEnemyStruct\0"
    "on_readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connection[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       8,    1,   45,    2, 0x06 /* Public */,
      10,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, 0x80000000 | 11,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Connection *_t = static_cast<Connection *>(_o);
        switch (_id) {
        case 0: _t->OnNewTowerReceived((*reinterpret_cast< PlayerSyncStruct(*)>(_a[1]))); break;
        case 1: _t->OnNewEnemyReceived((*reinterpret_cast< EnemyStruct(*)>(_a[1]))); break;
        case 2: _t->OnNewPSyncRecieved((*reinterpret_cast< PlayerSyncStruct(*)>(_a[1]))); break;
        case 3: _t->OnRemoveEnemyRecieved((*reinterpret_cast< RemoveEnemyStruct(*)>(_a[1]))); break;
        case 4: _t->on_readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Connection::*_t)(PlayerSyncStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnNewTowerReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (Connection::*_t)(EnemyStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnNewEnemyReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (Connection::*_t)(PlayerSyncStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnNewPSyncRecieved)) {
                *result = 2;
            }
        }
        {
            typedef void (Connection::*_t)(RemoveEnemyStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnRemoveEnemyRecieved)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Connection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Connection.data,
      qt_meta_data_Connection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Connection.stringdata))
        return static_cast<void*>(const_cast< Connection*>(this));
    return QObject::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Connection::OnNewTowerReceived(PlayerSyncStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connection::OnNewEnemyReceived(EnemyStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Connection::OnNewPSyncRecieved(PlayerSyncStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Connection::OnRemoveEnemyRecieved(RemoveEnemyStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
