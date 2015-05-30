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
#include "powerupstruct.h"
#include "pacmanstruct.h"
#include "pellet.h"
#include "monstersstruct.h"

enum PACKETTYPES{NewProjectile=1, NewEnemy=2, PlayerSync=3, RemoveEnemy=4, SyncPacman=5, SyncPowerUp=6, SyncPellet=7, SyncMonster=8};
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
    void Send(PowerUpStruct p);
    void Send(PelletStruct p);
    void Send(MonsterStruct m);
    bool IsConnected();
signals:
    void OnNewEnemyReceived(EnemyStruct e);
    void OnNewPSyncRecieved(PlayerSyncStruct s);
    void OnRemoveEnemyRecieved(RemoveEnemyStruct s);
    void OnSyncPacmanReceived(PacmanStruct s);
    void OnPowerUpReceived(PowerUpStruct p);
    void OnPelletSyncReceived(PelletStruct p);
    void OnMonsterSyncReceived(MonsterStruct m);

private:
    QTcpSocket *sock;
    const int IntFromQByteArr(QByteArray a);
    const float FloatFromQByteArr(QByteArray a);
    bool connected;

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
