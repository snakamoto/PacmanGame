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

void Connection::Send(MonsterStruct p)
{
    sock->waitForConnected();
    //owner,orientation,x,y
    int packet_type = PACKETTYPES::SyncMonster;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(p.id) + ":" + QString::number(p.orientation)
            + ":" + QString::number(p.state) + ":" + QString::number(p.state_timer)
            + ":" + QString::number(p.x) +  ":" + QString::number(p.y) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
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


void Connection::Send(PathStruct p)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::SyncPath;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + QString::number(p.start_x) + ":" + QString::number(p.start_y) + ":"
            + QString::number(p.end_x) + ":" + QString::number(p.end_y) + ":"
            + QString::number(p.mon_id) +
                       ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    //qDebug() << data;
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

    //qDebug() << data;
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

    //qDebug() << data;
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

        if(packet_type == PACKETTYPES::SyncMonster)
        {
            MonsterStruct mon;
            mon.id = IntFromQByteArr(elements[2+i]);
            mon.orientation = IntFromQByteArr(elements[3+i]);
            mon.state = IntFromQByteArr(elements[4+i]);
            mon.state_timer = IntFromQByteArr(elements[5+i]);
            mon.x = FloatFromQByteArr(elements[6+i]);
            mon.y = FloatFromQByteArr(elements[7+i]);
#ifdef ASSERT > 2
            qDebug() << "Sync Pacman (" + QString::number(mon.id) + ","
                        + QString::number(mon.orientation) + ","
                        + QString::number(mon.state) + ","
                        + QString::number(mon.state_timer) + ","
                        + QString::number(mon.x) + ","
                        + QString::number(mon.y) + ")";
#endif
            emit OnMonsterSyncReceived(mon);
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


        if(packet_type == PACKETTYPES::SyncPath)
        {
            PathStruct p;
            p.start_x = IntFromQByteArr(elements[2+i]);
            p.start_y = IntFromQByteArr(elements[3+i]);
            p.end_x = IntFromQByteArr(elements[4+i]);
            p.end_y = FloatFromQByteArr(elements[5+i]);
            p.mon_id = FloatFromQByteArr(elements[6+i]);
#ifdef ASSERT > 2
            qDebug() << "Sync PowerUp (" + QString::number(p.start_x) + ","
                        + QString::number(p.start_y) + ","
                        + QString::number(p.end_x) + ","
                        + QString::number(p.end_x) + ","
                        + QString::number(p.end_y) + ")";
#endif
            emit OnPathSyncReceived(p);
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
