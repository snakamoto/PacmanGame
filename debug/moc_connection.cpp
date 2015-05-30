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
    QByteArrayData data[21];
    char stringdata[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connection_t qt_meta_stringdata_Connection = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Connection"
QT_MOC_LITERAL(1, 11, 18), // "OnNewEnemyReceived"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "EnemyStruct"
QT_MOC_LITERAL(4, 43, 1), // "e"
QT_MOC_LITERAL(5, 45, 18), // "OnNewPSyncRecieved"
QT_MOC_LITERAL(6, 64, 16), // "PlayerSyncStruct"
QT_MOC_LITERAL(7, 81, 1), // "s"
QT_MOC_LITERAL(8, 83, 21), // "OnRemoveEnemyRecieved"
QT_MOC_LITERAL(9, 105, 17), // "RemoveEnemyStruct"
QT_MOC_LITERAL(10, 123, 20), // "OnSyncPacmanReceived"
QT_MOC_LITERAL(11, 144, 12), // "PacmanStruct"
QT_MOC_LITERAL(12, 157, 17), // "OnPowerUpReceived"
QT_MOC_LITERAL(13, 175, 13), // "PowerUpStruct"
QT_MOC_LITERAL(14, 189, 1), // "p"
QT_MOC_LITERAL(15, 191, 20), // "OnPelletSyncReceived"
QT_MOC_LITERAL(16, 212, 12), // "PelletStruct"
QT_MOC_LITERAL(17, 225, 21), // "OnMonsterSyncReceived"
QT_MOC_LITERAL(18, 247, 13), // "MonsterStruct"
QT_MOC_LITERAL(19, 261, 1), // "m"
QT_MOC_LITERAL(20, 263, 12) // "on_readyRead"

    },
    "Connection\0OnNewEnemyReceived\0\0"
    "EnemyStruct\0e\0OnNewPSyncRecieved\0"
    "PlayerSyncStruct\0s\0OnRemoveEnemyRecieved\0"
    "RemoveEnemyStruct\0OnSyncPacmanReceived\0"
    "PacmanStruct\0OnPowerUpReceived\0"
    "PowerUpStruct\0p\0OnPelletSyncReceived\0"
    "PelletStruct\0OnMonsterSyncReceived\0"
    "MonsterStruct\0m\0on_readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       8,    1,   60,    2, 0x06 /* Public */,
      10,    1,   63,    2, 0x06 /* Public */,
      12,    1,   66,    2, 0x06 /* Public */,
      15,    1,   69,    2, 0x06 /* Public */,
      17,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,    7,
    QMetaType::Void, 0x80000000 | 11,    7,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   14,
    QMetaType::Void, 0x80000000 | 18,   19,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Connection *_t = static_cast<Connection *>(_o);
        switch (_id) {
        case 0: _t->OnNewEnemyReceived((*reinterpret_cast< EnemyStruct(*)>(_a[1]))); break;
        case 1: _t->OnNewPSyncRecieved((*reinterpret_cast< PlayerSyncStruct(*)>(_a[1]))); break;
        case 2: _t->OnRemoveEnemyRecieved((*reinterpret_cast< RemoveEnemyStruct(*)>(_a[1]))); break;
        case 3: _t->OnSyncPacmanReceived((*reinterpret_cast< PacmanStruct(*)>(_a[1]))); break;
        case 4: _t->OnPowerUpReceived((*reinterpret_cast< PowerUpStruct(*)>(_a[1]))); break;
        case 5: _t->OnPelletSyncReceived((*reinterpret_cast< PelletStruct(*)>(_a[1]))); break;
        case 6: _t->OnMonsterSyncReceived((*reinterpret_cast< MonsterStruct(*)>(_a[1]))); break;
        case 7: _t->on_readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Connection::*_t)(EnemyStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnNewEnemyReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (Connection::*_t)(PlayerSyncStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnNewPSyncRecieved)) {
                *result = 1;
            }
        }
        {
            typedef void (Connection::*_t)(RemoveEnemyStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnRemoveEnemyRecieved)) {
                *result = 2;
            }
        }
        {
            typedef void (Connection::*_t)(PacmanStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnSyncPacmanReceived)) {
                *result = 3;
            }
        }
        {
            typedef void (Connection::*_t)(PowerUpStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnPowerUpReceived)) {
                *result = 4;
            }
        }
        {
            typedef void (Connection::*_t)(PelletStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnPelletSyncReceived)) {
                *result = 5;
            }
        }
        {
            typedef void (Connection::*_t)(MonsterStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::OnMonsterSyncReceived)) {
                *result = 6;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Connection::OnNewEnemyReceived(EnemyStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connection::OnNewPSyncRecieved(PlayerSyncStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Connection::OnRemoveEnemyRecieved(RemoveEnemyStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Connection::OnSyncPacmanReceived(PacmanStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Connection::OnPowerUpReceived(PowerUpStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Connection::OnPelletSyncReceived(PelletStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Connection::OnMonsterSyncReceived(MonsterStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
