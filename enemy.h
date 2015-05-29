#ifndef ENEMY_H
#define ENEMY_H


#include "QGraphicsRectItem"
#include "constants.h"
#include "QPointF"
#include "Path.h"
#include "QBrush"
#include "QRectF"
#include "enemystruct.h"
#include <vector>

class Enemy
{
public:
    Enemy();

public:
    QGraphicsRectItem *sprite;//Teh image of teh creep
    void SetPosition(int x, int y);

    //Gettor
    const int GetBounty();

    const bool IsAlive();


    void UpdatePath(Path p_);
    void UpdatePath(vector<TileNode> node_path);
    void Update(float elapsed_seconds);

    const int GetUniqueID();
    void SetUniqueID(int uid);

    const QRectF GetBoundingBox();

    const EnemyStruct GetEnemyStruct();


private:
    //Enemy params
    int bounty;
    int id;
    bool isAlive;
    int uniqueId;


    QPointF velocity;
    double angle_to_point(double x, double y); //If we want the enemy to face a point
    //This isn't used afaik so may be deleted

    //Pathing
    float stage_pos;  //pos between cur and next point in path
    int stage_index; //Index of current point in path
    Path path; //path to follow
    float speed; //movement speed of teh creep

    //Called in update
    void UpdatePathing(float seconds);
    //void InitWaves();

    //We only want to change our orientation when it is necessary to do so
    //Coz QT sucks and is slow
    int last_orientation;
    int cur_orientation;

   // Wave *waves;
   // int noWaves;
};

#endif // ENEMY_H


