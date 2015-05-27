#ifndef PACMAN_H
#define PACMAN_H

#include "QGraphicsRectItem"
#include "Constants.h"
#include "QPointF"
#include "Path.h"
#include "QBrush"
#include "QRectF"
#include "pacmanstruct.h"
#include <vector>

class Pacman
{
public:
    Pacman();
    ~Pacman();

    QGraphicsRectItem *sprite;//Teh image of teh creep
    void SetPosition(int x, int y);
    void Update(float elapsed_seconds);

    const QRectF GetBoundingBox();

    const PacmanStruct GetEnemyStruct();

    const int GetScore();

    int food_collected;
    int kills;

private:
    int orientation;
    float speed;

};

#endif // PACMAN_H
