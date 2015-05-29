#include "pellet.h"

Pellet::Pellet()
{

}

Pellet::~Pellet()
{

}

const int Pellet::GetX()
{
    return x;
}

const int Pellet::GetY()
{
    return y;
}

const int Pellet::GetType()
{
    return type;
}

const int Pellet::GetEaten()
{
    return eaten;
}

void Pellet::SetX(int x)
{
    this->x = x;
}

void Pellet::SetY(int y)
{
    this->y = y;
}

void Pellet::SetType(int t)
{
    this->type = t;
}

void Pellet::SetEaten(bool e)
{
    this->eaten = e;
}

void Pellet::SetId(int i)
{
    this->id = i;
}

const int Pellet::GetId()
{
    return this->id;
}

const PelletStruct Pellet::GetPelletStruct()
{
    PelletStruct p;
    p.eaten = this->eaten;
    p.type = this->type;
    p.x = this->x;
    p.y = this->y;
    return p;
}
