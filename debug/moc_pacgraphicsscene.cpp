/****************************************************************************
** Meta object code from reading C++ file 'pacgraphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pacgraphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pacgraphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PacGraphicsScene_t {
    QByteArrayData data[18];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PacGraphicsScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PacGraphicsScene_t qt_meta_stringdata_PacGraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PacGraphicsScene"
QT_MOC_LITERAL(1, 17, 8), // "GameOver"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "kills"
QT_MOC_LITERAL(4, 33, 21), // "on_new_enemy_received"
QT_MOC_LITERAL(5, 55, 11), // "EnemyStruct"
QT_MOC_LITERAL(6, 67, 1), // "e"
QT_MOC_LITERAL(7, 69, 21), // "on_new_psync_recieved"
QT_MOC_LITERAL(8, 91, 16), // "PlayerSyncStruct"
QT_MOC_LITERAL(9, 108, 1), // "s"
QT_MOC_LITERAL(10, 110, 24), // "on_remove_enemy_recieved"
QT_MOC_LITERAL(11, 135, 17), // "RemoveEnemyStruct"
QT_MOC_LITERAL(12, 153, 2), // "en"
QT_MOC_LITERAL(13, 156, 23), // "on_sync_pacman_received"
QT_MOC_LITERAL(14, 180, 12), // "PacmanStruct"
QT_MOC_LITERAL(15, 193, 3), // "pac"
QT_MOC_LITERAL(16, 197, 23), // "on_sync_pellet_received"
QT_MOC_LITERAL(17, 221, 12) // "PelletStruct"

    },
    "PacGraphicsScene\0GameOver\0\0kills\0"
    "on_new_enemy_received\0EnemyStruct\0e\0"
    "on_new_psync_recieved\0PlayerSyncStruct\0"
    "s\0on_remove_enemy_recieved\0RemoveEnemyStruct\0"
    "en\0on_sync_pacman_received\0PacmanStruct\0"
    "pac\0on_sync_pellet_received\0PelletStruct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacGraphicsScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
      10,    1,   53,    2, 0x08 /* Private */,
      13,    1,   56,    2, 0x08 /* Private */,
      16,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   15,

       0        // eod
};

void PacGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PacGraphicsScene *_t = static_cast<PacGraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->GameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_new_enemy_received((*reinterpret_cast< EnemyStruct(*)>(_a[1]))); break;
        case 2: _t->on_new_psync_recieved((*reinterpret_cast< PlayerSyncStruct(*)>(_a[1]))); break;
        case 3: _t->on_remove_enemy_recieved((*reinterpret_cast< RemoveEnemyStruct(*)>(_a[1]))); break;
        case 4: _t->on_sync_pacman_received((*reinterpret_cast< PacmanStruct(*)>(_a[1]))); break;
        case 5: _t->on_sync_pellet_received((*reinterpret_cast< PelletStruct(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PacGraphicsScene::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PacGraphicsScene::GameOver)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PacGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_PacGraphicsScene.data,
      qt_meta_data_PacGraphicsScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PacGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PacGraphicsScene.stringdata))
        return static_cast<void*>(const_cast< PacGraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int PacGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PacGraphicsScene::GameOver(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
