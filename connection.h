#ifndef CONNECTION_H
#define CONNECTION_H
#define ASSERT 2
#include "pacmanstruct.h"
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>

#include <QList>
#include "playersyncstruct.h"
#include "powerupstruct.h"
#include "pacmanstruct.h"
#include "pellet.h"
#include "monstersstruct.h"
#include "pathstruct.h";

enum PACKETTYPES{SyncPacman=5, SyncPowerUp=6, SyncPellet=7, SyncMonster=8, SyncPath=9};
class Connection : public QObject
{
    Q_OBJECT
public:
    Connection();
    Connection(QTcpSocket *s);
    void Send(PacmanStruct h);
    void Send(PowerUpStruct p);
    void Send(PelletStruct p);
    void Send(MonsterStruct m);
    void Send(PathStruct path);
    bool IsConnected();
signals:
    void OnSyncPacmanReceived(PacmanStruct s);
    void OnPowerUpReceived(PowerUpStruct p);
    void OnPelletSyncReceived(PelletStruct p);
    void OnMonsterSyncReceived(MonsterStruct m);
    void OnPathSyncReceived(PathStruct p);

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
