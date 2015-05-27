#ifndef ENEMYSTRUCT_H
#define ENEMYSTRUCT_H

class EnemyStruct
{
public:
    EnemyStruct(){}

    int type_; //type and upgrade of enemy
    int owner_; //owner of the tower
    float x; //x position
    float y; //y position
};

#endif // ENEMYSTRUCT_H
