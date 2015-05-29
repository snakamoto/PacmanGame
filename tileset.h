#ifndef TILESET_H
#define TILESET_H
#include <QString>
#include <QColor>

using namespace std;

struct Tileset
{
public:
    Tileset(){}
    int id;
    QString src;
    int w;
    int h;
    QColor color;

    void Load();

};

#endif // TILESET_H
