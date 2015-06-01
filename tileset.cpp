#include "Tileset.h"
#include <QDebug>;

Tileset::Tileset()
{
}

void Tileset::Load()
{
    int m_i = w / WIDTH;
    int m_j = h / WIDTH;
    tiles = new QImage[m_i*m_j];
    QString sub = src.mid(3,src.length()-3);
    qDebug() << src;
    tileset = QImage(sub);
    qDebug() << "m_x" << w << "m_y" << h;
    qDebug() << "m_x" << tileset.width() << "m_y" << tileset.height();

    for(int x = 0; x < w; x+=WIDTH)
        for(int y = 0; y < h; y+=WIDTH)
        {
            int i = x/WIDTH;
            int j = y/WIDTH;
            qDebug() << x << y << WIDTH, WIDTH;
            //tiles[j*m_i+i] = QImage(WIDTH, WIDTH, QImage::Format_RGB888);
        }

    for(int x = 0; x < w; x+=WIDTH)
        for(int y = 0; y < h; y+=WIDTH)
        {
            int i = x/WIDTH;
            int j = y/WIDTH;
            qDebug() << x << y << WIDTH, WIDTH;
            tiles[j*m_i+i] = tileset.copy(x, y, WIDTH, WIDTH);
        }
}

QImage Tileset::GetImage(int id)
{
    qDebug() << id;
    if(id>0)
        id--;
    return tiles[id];
}
