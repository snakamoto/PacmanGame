#include "powerup.h"

PowerUp::PowerUp()
{
    sprite = new QGraphicsRectItem();
    sprite->setRect(0,0,WIDTH/2,WIDTH/2); //Size of sprite
    sprite->setTransformOriginPoint(WIDTH/8,WIDTH/8); //To rotate about the origin

    const QColor transparent(255,0,0,255);
    QPen transPen(transparent);
    sprite->setPen(transPen); //Remove border from rect

}

void PowerUp::SetType2(int t)
{
    this->type2 = t;

}
 int PowerUp::GetType2()
{
    return type2;
}


PowerUp::~PowerUp()
{

}

const int PowerUp::GetX()
{
    return x;
}

const QRectF PowerUp::GetBoundingBox()
{
    return sprite->sceneBoundingRect();
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
    sprite->setPos(x,y);
}
void PowerUp::SetY(int y)
{
    this->y = y;
    sprite->setPos(x,y);
}

void PowerUp::SetPosition(int x, int y)
{
    sprite->setPos(x+WIDTH/4,y+WIDTH/4);
}

void PowerUp::SetType(int t)
{
    this->type = 60-4*t;

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
