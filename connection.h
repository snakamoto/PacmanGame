#ifndef CONNECTION_H
#define CONNECTION_H
#define ASSERT 2
#include "pacmanstruct.h"
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>
#include "enemystruct.h"
#include <QList>
#include "playersyncstruct.h"
#include "removeenemystruct.h"
#include "pacmanstruct.h"

enum PACKETTYPES{NewProjectile=1, NewEnemy=2, PlayerSync=3, RemoveEnemy=4, SyncPacman=5};
class Connection : public QObject
{
    Q_OBJECT
public:
    Connection();
    Connection(QTcpSocket *s);
    void Send(PacmanStruct h);
    void Send(EnemyStruct p);
    void Send(PlayerSyncStruct s);
    void Send(RemoveEnemyStruct es);
signals:
    void OnNewEnemyReceived(EnemyStruct e);
    void OnNewPSyncRecieved(PlayerSyncStruct s);
    void OnRemoveEnemyRecieved(RemoveEnemyStruct s);
    void OnSyncPacmanReceived(PacmanStruct s);
private:
    QTcpSocket *sock;
    const int IntFromQByteArr(QByteArray a);
    const float FloatFromQByteArr(QByteArray a);

private slots:
    void on_readyRead();

    //Packet loader
    //m_number:type;data:@:
    //eg tower
    //9:0:type:owner:damage:x:y:@:

    //types
    //0 - new tower

};

#endif // CONNECTION_H
