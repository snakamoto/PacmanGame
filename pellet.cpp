#include "pellet.h"

Pellet::Pellet()
{
    sprite = new QGraphicsRectItem();
    sprite->setRect(0,0,WIDTH/4,WIDTH/4); //Size of sprite
    sprite->setTransformOriginPoint(WIDTH/8,WIDTH/8); //To rotate about the origin

    const QColor transparent(255,150,0,0);
    QPen transPen(transparent);
    sprite->setPen(transPen); //Remove border from rect

    QPixmap pix("images/pellet.png");
    QBrush brush(pix);
    sprite->setBrush(brush);
    sprite->setRect(0,0,WIDTH,WIDTH); //Size of sprite
    sprite->setTransformOriginPoint(WIDTH/2,WIDTH/2); //To rotate about the origin



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
    sprite->setPos(x+type/4,y+type/4);
}

void Pellet::SetType(int t)
{
    this->type = (60-4*(t/2));
    sprite->setRect(0,0,WIDTH-type/2 + WIDTH/16,WIDTH-type/2 + WIDTH/16); //Size of sprite
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

