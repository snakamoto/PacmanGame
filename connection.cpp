#include "connection.h"
#include "iostream"
#include <QDebug>

const int magic_num = 9;
Connection::Connection()
{
}

Connection::Connection(QTcpSocket *s)
{
    connected = false;
    if(s)
    {
        this->sock = s;
        connect(sock, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
        sock->blockSignals(false);
        connected = true;
    }
}

bool Connection::IsConnected()
{
    return connected;
}


void Connection::Send(PacmanStruct p)
{
    sock->waitForConnected();
    //owner,orientation,x,y
    int packet_type = PACKETTYPES::SyncPacman;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(p.owner_) + ":" + QString::number(p.orientation)
            + ":" + QString::number(p.state) + ":" + QString::number(p.score)
            + ":" + QString::number(p.x) +  ":" + QString::number(p.y) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::Send(EnemyStruct p)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::NewEnemy;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(p.id) + ":" + QString::number(p.orientation)
            + ":" + QString::number(p.x) +  ":" + QString::number(p.y) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::Send(RemoveEnemyStruct es)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::RemoveEnemy;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(es.uid) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::Send(PlayerSyncStruct s)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::PlayerSync;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + QString::number(s.p1_score) + ":" + QString::number(s.p2_score)+ ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::Send(PowerUpStruct p)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::SyncPowerUp;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(p.id) + ":" + QString::number(p.type) + ":" + QString::number(p.eaten)
            + ":" + QString::number(p.x) +  ":" + QString::number(p.y) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::Send(PelletStruct p)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::SyncPellet;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(p.id) + ":" + QString::number(p.type) + ":" + QString::number(p.eaten)
            + ":" + QString::number(p.x) +  ":" + QString::number(p.y) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::on_readyRead()
{
    qDebug() << "ONREAD";

    QByteArray buffer;
    qint64 n = sock->bytesAvailable();
    buffer = sock->read(n);

    QList<QByteArray> elements = buffer.split(':');

    bool isData = true;
    int i =0;
    while(isData)
    {
        int magic = IntFromQByteArr(elements[0+i]);

        if(magic != magic_num)
        {
            //Some error
        }

        int packet_type = IntFromQByteArr(elements[1+i]);

        if(packet_type == PACKETTYPES::RemoveEnemy)
        {
            qDebug () << buffer;
            RemoveEnemyStruct en;
            en.uid = IntFromQByteArr(elements[2+i]);
#ifdef ASSERT > 2
            qDebug() << "Remove Enemy (" + QString::number(en.uid)+  ")";
#endif
            emit OnRemoveEnemyRecieved(en);
            i+=3;
        }

        if(packet_type == PACKETTYPES::NewEnemy)
        {
            qDebug () << buffer;
            EnemyStruct en;
            en.id = IntFromQByteArr(elements[2+i]);
            en.orientation = IntFromQByteArr(elements[3+i]);
            en.x = FloatFromQByteArr(elements[4+i]);
            en.y = FloatFromQByteArr(elements[5+i]);

#ifdef ASSERT > 2
            qDebug() << "New Enemy (" + QString::number(en.id) + ","
                        +QString::number(en.orientation) + ","
                        + QString::number(en.x) + ","
                        + QString::number(en.y) + ")";
#endif
            emit OnNewEnemyReceived(en);
            i+=6;
        }
        //owner,orientation,x,y
        if(packet_type == PACKETTYPES::SyncPacman)
        {
            PacmanStruct pac;
            pac.owner_ = IntFromQByteArr(elements[2+i]);
            pac.orientation = IntFromQByteArr(elements[3+i]);
            pac.state = IntFromQByteArr(elements[4+i]);
            pac.score = IntFromQByteArr(elements[5+i]);
            pac.x = FloatFromQByteArr(elements[6+i]);
            pac.y = FloatFromQByteArr(elements[7+i]);
#ifdef ASSERT > 2
            qDebug() << "Sync Pacman (" + QString::number(pac.owner_) + ","
                        + QString::number(pac.orientation) + ","
                        + QString::number(pac.state) + ","
                        + QString::number(pac.score) + ","
                        + QString::number(pac.x) + ","
                        + QString::number(pac.y) + ")";
#endif
            emit OnSyncPacmanReceived(pac);
            i+=8;
        }

        if(packet_type == PACKETTYPES::SyncPowerUp)
        {
            PowerUpStruct p;
            p.id = IntFromQByteArr(elements[2+i]);
            p.type = IntFromQByteArr(elements[3+i]);
            p.eaten = IntFromQByteArr(elements[4+i]);
            p.x = FloatFromQByteArr(elements[5+i]);
            p.y = FloatFromQByteArr(elements[6+i]);
#ifdef ASSERT > 2
            qDebug() << "Sync PowerUp (" + QString::number(p.id) + ","
                        + QString::number(p.type) + ","
                        + QString::number(p.eaten) + ","
                        + QString::number(p.x) + ","
                        + QString::number(p.y) + ")";
#endif
            emit OnPowerUpReceived(p);
            i+=7;
        }

        if(packet_type == PACKETTYPES::SyncPellet)
        {
            PelletStruct p;
            p.id = IntFromQByteArr(elements[2+i]);
            p.type = IntFromQByteArr(elements[3+i]);
            p.eaten = IntFromQByteArr(elements[4+i]);
            p.x = FloatFromQByteArr(elements[5+i]);
            p.y = FloatFromQByteArr(elements[6+i]);
#ifdef ASSERT > 2
            qDebug() << "Sync Pellet (" + QString::number(p.id) + ","
                        + QString::number(p.type) + ","
                        + QString::number(p.eaten) + ","
                        + QString::number(p.x) + ","
                        + QString::number(p.y) + ")";
#endif
            emit OnPelletSyncReceived(p);
            i+=7;
        }

        if(packet_type == PACKETTYPES::PlayerSync)
        {
            PlayerSyncStruct s;

            s.p1_score = IntFromQByteArr(elements[2+i]);
            s.p2_score = IntFromQByteArr(elements[3+i]);
#ifdef ASSERT > 2
            qDebug() << "Player Sync (" + QString::number(s.p1_score) + ","
                        + QString::number(s.p2_score);
#endif
            emit OnNewPSyncRecieved(s);
            i+=7;
        }

        i++;
        isData = (elements[i].toInt() == magic_num);

    }

}

const int Connection::IntFromQByteArr(QByteArray a)
{
    return a.toInt();
}

const float Connection::FloatFromQByteArr(QByteArray a)
{
    return a.toFloat();
}
