#ifndef TILESET_H
#define TILESET_H
#include <QString>
#include <QPixmap>
#include <QColor>
#include <QImage>
#include <QStringRef>
#include <Constants.h>

using namespace std;

class Tileset
{
public:
    Tileset();
    int id;
    QString src;
    int w;
    int h;
    QColor color;

    void Load();
    QImage tileset;

    QImage *tiles;

    QImage GetImage(int id);
};

#endif // TILESET_H
