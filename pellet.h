#ifndef PELLET_H
#define PELLET_H
#include "pelletstruct.h"
#include "QGraphicsRectItem"
#include "constants.h"

class Pellet
{
public:
    Pellet();
    ~Pellet();
    const int GetX();
    const int GetY();
    const int GetType();
    const int GetEaten();
    const int GetId();
    void SetX(int x);
    void SetY(int y);
    void SetPosition(int x, int y);
    void SetType(int t);
    void SetEaten(bool e);
    void SetId(int i);
    const PelletStruct GetPelletStruct();
    const QRectF GetBoundingBox();
    QGraphicsRectItem *sprite;

private:
    int id;
    int x;
    int y;
    int type;
    bool eaten;
};

#endif // PELLET_H
