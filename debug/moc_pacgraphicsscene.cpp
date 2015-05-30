/****************************************************************************
** Meta object code from reading C++ file 'pacgraphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pacgraphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pacgraphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PacGraphicsScene_t {
    QByteArrayData data[17];
    char stringdata[228];
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
QT_MOC_LITERAL(3, 27, 5), // "score"
QT_MOC_LITERAL(4, 33, 23), // "on_sync_pacman_received"
QT_MOC_LITERAL(5, 57, 12), // "PacmanStruct"
QT_MOC_LITERAL(6, 70, 3), // "pac"
QT_MOC_LITERAL(7, 74, 23), // "on_sync_pellet_received"
QT_MOC_LITERAL(8, 98, 12), // "PelletStruct"
QT_MOC_LITERAL(9, 111, 24), // "on_sync_powerup_received"
QT_MOC_LITERAL(10, 136, 13), // "PowerUpStruct"
QT_MOC_LITERAL(11, 150, 24), // "on_sync_monster_received"
QT_MOC_LITERAL(12, 175, 13), // "MonsterStruct"
QT_MOC_LITERAL(13, 189, 3), // "mon"
QT_MOC_LITERAL(14, 193, 21), // "on_sync_path_received"
QT_MOC_LITERAL(15, 215, 10), // "PathStruct"
QT_MOC_LITERAL(16, 226, 1) // "p"

    },
    "PacGraphicsScene\0GameOver\0\0score\0"
    "on_sync_pacman_received\0PacmanStruct\0"
    "pac\0on_sync_pellet_received\0PelletStruct\0"
    "on_sync_powerup_received\0PowerUpStruct\0"
    "on_sync_monster_received\0MonsterStruct\0"
    "mon\0on_sync_path_received\0PathStruct\0"
    "p"
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
       9,    1,   53,    2, 0x08 /* Private */,
      11,    1,   56,    2, 0x08 /* Private */,
      14,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, 0x80000000 | 10,    6,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void PacGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PacGraphicsScene *_t = static_cast<PacGraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->GameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_sync_pacman_received((*reinterpret_cast< PacmanStruct(*)>(_a[1]))); break;
        case 2: _t->on_sync_pellet_received((*reinterpret_cast< PelletStruct(*)>(_a[1]))); break;
        case 3: _t->on_sync_powerup_received((*reinterpret_cast< PowerUpStruct(*)>(_a[1]))); break;
        case 4: _t->on_sync_monster_received((*reinterpret_cast< MonsterStruct(*)>(_a[1]))); break;
        case 5: _t->on_sync_path_received((*reinterpret_cast< PathStruct(*)>(_a[1]))); break;
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
