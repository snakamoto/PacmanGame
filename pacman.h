#ifndef PACMAN_H
#define PACMAN_H

#include "QGraphicsRectItem"
#include "constants.h"
#include "QPointF"
#include "Path.h"
#include "QBrush"
#include "QRectF"
#include "pacmanstruct.h"
#include <vector>
#include <QPen>

class Pacman
{
public:
    Pacman();
    ~Pacman();

    QGraphicsRectItem *sprite;//Teh image of teh creep
    void SetPosition(int x, int y);
    void Update(float elapsed_seconds);

    void Set_Orientation(int orient);

    const int Get_Orientation();

    const QRectF GetBoundingBox();

    const PacmanStruct GetPacmanStruct();

    const int GetScore();
    void IncrementScorePellet(int amount);

    const int GetId();
    void SetId(int id_);

    const int GetState();
    void SetState(int s);

private:
    int orientation;
    float speed;
    int id;
    int state;
    int score;

};

#endif // PACMAN_H
