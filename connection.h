#ifndef CONNECTION_H
#define CONNECTION_H
#include "towerstruct.h"
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>
#include "projectilestruct.h"
#include "enemystruct.h"
#include <QList>
#include "playersyncstruct.h"
#include "removeenemystruct.h"

enum PACKETTYPES{NewTower=0, NewProjectile=1, NewEnemy=2, PlayerSync=3, RemoveEnemy=4};
class Connection : public QObject
{
    Q_OBJECT
public:
    Connection();
    Connection(QTcpSocket *s);
    void Send(TowerStruct h);
    void Send(ProjectileStruct p);
    void Send(EnemyStruct p);
    void Send(PlayerSyncStruct s);
    void Send(RemoveEnemyStruct es);
signals:
    void OnNewTowerReceived(TowerStruct t);
    void OnNewEnemyReceived(EnemyStruct e);
    void OnNewProjectileRecieved(ProjectileStruct p);
    void OnNewPSyncRecieved(PlayerSyncStruct s);
    void OnRemoveEnemyRecieved(RemoveEnemyStruct s);
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
