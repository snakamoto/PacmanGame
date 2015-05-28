/****************************************************************************
** Meta object code from reading C++ file 'tdgraphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tdgraphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tdgraphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TDGraphicsScene_t {
    QByteArrayData data[13];
    char stringdata[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TDGraphicsScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TDGraphicsScene_t qt_meta_stringdata_TDGraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TDGraphicsScene"
QT_MOC_LITERAL(1, 16, 8), // "GameOver"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "kills"
QT_MOC_LITERAL(4, 32, 21), // "on_new_enemy_received"
QT_MOC_LITERAL(5, 54, 11), // "EnemyStruct"
QT_MOC_LITERAL(6, 66, 1), // "e"
QT_MOC_LITERAL(7, 68, 21), // "on_new_psync_recieved"
QT_MOC_LITERAL(8, 90, 16), // "PlayerSyncStruct"
QT_MOC_LITERAL(9, 107, 1), // "s"
QT_MOC_LITERAL(10, 109, 24), // "on_remove_enemy_recieved"
QT_MOC_LITERAL(11, 134, 17), // "RemoveEnemyStruct"
QT_MOC_LITERAL(12, 152, 2) // "en"

    },
    "TDGraphicsScene\0GameOver\0\0kills\0"
    "on_new_enemy_received\0EnemyStruct\0e\0"
    "on_new_psync_recieved\0PlayerSyncStruct\0"
    "s\0on_remove_enemy_recieved\0RemoveEnemyStruct\0"
    "en"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TDGraphicsScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
      10,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void TDGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TDGraphicsScene *_t = static_cast<TDGraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->GameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_new_enemy_received((*reinterpret_cast< EnemyStruct(*)>(_a[1]))); break;
        case 2: _t->on_new_psync_recieved((*reinterpret_cast< PlayerSyncStruct(*)>(_a[1]))); break;
        case 3: _t->on_remove_enemy_recieved((*reinterpret_cast< RemoveEnemyStruct(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TDGraphicsScene::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TDGraphicsScene::GameOver)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TDGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_TDGraphicsScene.data,
      qt_meta_data_TDGraphicsScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TDGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TDGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TDGraphicsScene.stringdata))
        return static_cast<void*>(const_cast< TDGraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int TDGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
void TDGraphicsScene::GameOver(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
