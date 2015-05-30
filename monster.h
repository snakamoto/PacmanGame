#ifndef MONSTERS_H
#define MONSTERS_H

#include "QGraphicsRectItem"
#include "Constants.h"
#include "QPointF"
#include "Path.h"
#include "QBrush"
#include "QRectF"
#include "monstersstruct.h"
#include <vector>
#include <QPen>

class Monster
{
public:
    Monster();
    ~Monster();

    QGraphicsRectItem *sprite;//Teh image of teh creep
    void SetPosition(int x, int y);

    void Set_Orientation(int orient);

    const int Get_Orientation();

    const QRectF GetBoundingBox();

    const MonsterStruct GetMonsterStruct();

    const int GetScore();
    void IncrementScorePellet(int amount);

    const int GetId();
    void SetId(int id_);

    const int GetState();
    void SetState(int s);

    const int GetStateTimer();
    void DecrementStateTimer();
    int state;
    void SetStateTimer(int st);

    const float GetSpeed();
    void SetSpeed(int s);

    void UpdatePathing(float seconds);

    void UpdatePath(vector<TileNode> node_path);

    void UpdatePath(Path p);

    void Update(float elapsed_seconds);

    bool IsPathDone();

    void Reset();

private:

    int id;

    float statetimer;
    int score;

    float stage_pos;  //pos between cur and next point in path
    int stage_index; //Index of current point in path
    Path path; //path to follow
    int orientation;
    float speed;
    int last_orientation;
    int cur_orientation;
    QImage pixright, pixnextframeright,
           pixleft, pixnextframeleft,
           pixup, pixnextframeup,
           pixdown, pixnextframedown;
    float pacani,pactime;


};

#endif // MONSTERS_H



