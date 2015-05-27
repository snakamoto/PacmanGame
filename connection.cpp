#include "connection.h"
#include "iostream"
#include <QDebug>

const int magic_num = 9;
Connection::Connection()
{
}

Connection::Connection(QTcpSocket *s)
{
    this->sock = s;
    connect(sock, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
    sock->blockSignals(false);
}

void Connection::Send(TowerStruct h)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::NewTower;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(h.owner_) + ":" + QString::number(h.type_)
            + ":" + QString::number(h.x) +  ":" + QString::number(h.y) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::Send(ProjectileStruct p)
{
    sock->waitForConnected();
    int packet_type = PACKETTYPES::NewProjectile;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(p.damage) + ":" + QString::number(p.end_x)
            + ":" + QString::number(p.end_y) + ":" + QString::number(p.owner_)
            + ":" + QString::number(p.start_x) +  ":" + QString::number(p.start_y)
            + ":" + QString::number(p.type_)+ ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::Send(EnemyStruct p)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::NewEnemy;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(p.owner_) + ":" + QString::number(p.type_)
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
            + ":" + QString::number(s.lives) + ":" + QString::number(s.p1_kills)
            + ":" + QString::number(s.p2_kills) + ":" + QString::number(s.p1_gold) + ":"
            + QString::number(s.p2_gold) + ":@:").toUtf8();
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

        if(packet_type == PACKETTYPES::NewTower)
        {
            TowerStruct tower;
            tower.owner_ = IntFromQByteArr(elements[2+i]);
            tower.type_ = IntFromQByteArr(elements[3+i]);
            tower.x = IntFromQByteArr(elements[4+i]);
            tower.y = IntFromQByteArr(elements[5+i]);

            qDebug() << "New Tower (" + QString::number(tower.owner_) + ","
                        +QString::number(tower.type_) + ","
                        + QString::number(tower.x) + ","
                        + QString::number(tower.y) + ")";

            emit OnNewTowerReceived(tower);
            i+=6;
        }

        if(packet_type == PACKETTYPES::RemoveEnemy)
        {
            RemoveEnemyStruct en;
            en.uid = IntFromQByteArr(elements[2+i]);

            qDebug() << "Remove Enemy (" + QString::number(en.uid)+  ")";

            emit OnRemoveEnemyRecieved(en);
            i+=3;
        }

        if(packet_type == PACKETTYPES::NewEnemy)
        {
            EnemyStruct en;
            en.owner_ = IntFromQByteArr(elements[2+i]);
            en.type_ = IntFromQByteArr(elements[3+i]);
            en.x = FloatFromQByteArr(elements[4+i]);
            en.y = FloatFromQByteArr(elements[5+i]);

            qDebug() << "New Enemy (" + QString::number(en.owner_) + ","
                        +QString::number(en.type_) + ","
                        + QString::number(en.x) + ","
                        + QString::number(en.y) + ")";

            emit OnNewEnemyReceived(en);
            i+=6;
        }

        if(packet_type == PACKETTYPES::PlayerSync)
        {
            PlayerSyncStruct s;

            s.lives = IntFromQByteArr(elements[2+i]);
            s.p1_kills = IntFromQByteArr(elements[3+i]);
            s.p2_kills = IntFromQByteArr(elements[4+i]);
            s.p1_gold = IntFromQByteArr(elements[5+i]);
            s.p2_gold = IntFromQByteArr(elements[6+i]);

            qDebug() << "Player Sync (" + QString::number(s.lives) + ","
                        + QString::number(s.p1_kills) + ","
                        + QString::number(s.p2_kills) + ","
                        + QString::number(s.p1_gold) + ","
                        + QString::number(s.p2_gold) + ")";

            emit OnNewPSyncRecieved(s);
            i+=7;
        }


        if(packet_type == PACKETTYPES::NewProjectile)
        {
            qDebug() << "New Projectile";

            ProjectileStruct proj;
            proj.damage = IntFromQByteArr(elements[2+i]);
            proj.end_x = FloatFromQByteArr(elements[3+i]);
            proj.end_y = FloatFromQByteArr(elements[4+i]);
            proj.owner_ = IntFromQByteArr(elements[5+i]);
            proj.start_x = FloatFromQByteArr(elements[6+i]);
            proj.start_y = FloatFromQByteArr(elements[7+i]);
            proj.owner_ = IntFromQByteArr(elements[8+i]);

            qDebug() << "New Projectile (" + QString::number(proj.damage) + ","
                        + QString::number(proj.end_x) + ","
                        + QString::number(proj.end_y) + ","
                        + QString::number(proj.owner_) + ","
                        + QString::number(proj.start_x) + ","
                        + QString::number(proj.start_y) + ","
                        + QString::number(proj.type_) + ")";

            emit OnNewProjectileRecieved(proj);
            i+=9;
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
