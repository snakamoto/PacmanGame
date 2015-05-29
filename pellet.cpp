#include "pellet.h"

Pellet::Pellet()
{
    sprite = new QGraphicsRectItem();
    sprite->setRect(0,0,WIDTH/4,WIDTH/4); //Size of sprite
    sprite->setTransformOriginPoint(WIDTH/8,WIDTH/8); //To rotate about the origin


    //sprite->setPen(QPen(Qt::transparent)); //Remove border from rect
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
    sprite->setPos(x,y);
}

void Pellet::SetY(int y)
{
    this->y = y;
    sprite->setPos(x,y);
}

void Pellet::SetPosition(int x, int y)
{
    sprite->setPos(x+WIDTH/4,y+WIDTH/4);
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
    p.id = this->id;
    p.eaten = this->eaten;
    p.type = this->type;
    p.x = this->x;
    p.y = this->y;
    return p;
}

const QRectF Pellet::GetBoundingBox()
{
    return sprite->sceneBoundingRect();
}

