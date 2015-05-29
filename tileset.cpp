#include "Tileset.h"

Tileset::Tileset()
{
}

void Tileset::Load()
{
    int m_i = w / WIDTH;
    int m_j = h / WIDTH;
    tiles = new QImage[m_i*m_j];
    QString sub = src.mid(3,src.size()-3);

    tileset = QImage(sub);
    for(int x = 0; x < w; x+=WIDTH)
        for(int y = 0; y < h; y+=WIDTH)
        {
            int i = x/WIDTH;
            int j = y/WIDTH;
            tiles[j*m_i+i] = tileset.copy(x, y, WIDTH, WIDTH);
        }
}

QImage Tileset::GetImage(int id)
{
    return tiles[id-1];
}
