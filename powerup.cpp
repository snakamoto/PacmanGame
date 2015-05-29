#include "powerup.h"

PowerUp::PowerUp()
{

}

PowerUp::~PowerUp()
{

}

const int PowerUp::GetX()
{
    return x;
}

const int PowerUp::GetY()
{
    return y;
}
const int PowerUp::GetType()
{
    return type;
}
const int PowerUp::GetEaten()
{
    return eaten;
}
void PowerUp::SetX(int x)
{
    this->x = x;
}
void PowerUp::SetY(int y)
{
    this->y = y;
}
void PowerUp::SetType(int t)
{
    this->type = t;
}
void PowerUp::SetEaten(bool e)
{
    this->eaten = e;
}
void PowerUp::SetId(int i)
{
    this->id = i;
}
const int PowerUp::GetId()
{
    return this->id;
}

const PowerUpStruct PowerUp::GetPowerUpStruct()
{
    PowerUpStruct p;
    p.eaten = this->eaten;
    p.type = this->type;
    p.x = this->x;
    p.y = this->y;
    return p;
}
