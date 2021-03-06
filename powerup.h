#ifndef POWERUP_H
#define POWERUP_H
#include "powerupstruct.h"
#include "QGraphicsRectItem"
#include "Constants.h"
#include "QPen"

class PowerUp
{
public:
    PowerUp();
    ~PowerUp();
    const int GetX();
    const int GetY();
    const int GetType();
    const int GetEaten();
    const int GetId();
    void SetX(int x);
    void SetY(int y);
    void SetType(int t);
    void SetEaten(bool e);
    void SetId(int i);
    const PowerUpStruct GetPowerUpStruct();
    const QRectF GetBoundingBox();
    QGraphicsRectItem *sprite;
    void SetPosition(int x, int y);

    void SetType2(int t);
     int GetType2();
    int type2;

private:
    int id;
    int x;
    int y;
    int type;
    bool eaten;
};

#endif // POWERUP_H
