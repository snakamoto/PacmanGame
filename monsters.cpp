#include "monsters.h"
#include "QDebug"

monsters::monsters()
{
    sprite = new QGraphicsRectItem();
    sprite->setRect(0,0,WIDTH,WIDTH); //Size of sprite
    sprite->setTransformOriginPoint(WIDTH/2,WIDTH/2); //To rotate about the origin

     QPixmap pix("images/monster.png");

    pix=pix.scaled(WIDTH,WIDTH); //Scale image to fit BB
    sprite->setBrush(QBrush(pix));  //Set brush to loaded image
    const QColor transparent(0,0,0,0);

    QPen transPen(transparent);
    sprite->setPen(transPen); //Remove border from rect

    speed = 100;
    score = 0;
    state=2;
    statetimer=10000;

    Set_Orientation(0);

}



const int monsters::GetScore()
{
    return score;
}

void monsters::Set_Orientation(int orient)
{
    this->orientation = orient;
    //orient 0-right - 1 -top 2-left 3 - bottom

    if(orient >= 0)
        sprite->setRotation(orient*90);

}


void monsters::SetPosition(int x, int y)
{
    sprite->setPos(x,y);
}

void monsters::Update(float elapsed_seconds)
{
    //orient 0 - left 1 -top 2-right 3 - bottom
    float x_inc = 0;
    float y_inc = 0;
    switch (orientation)
    {
        case 0: x_inc += elapsed_seconds * (float)speed; break;
        case 1: y_inc += elapsed_seconds * (float)speed; break;
        case 2: x_inc -= elapsed_seconds * (float)speed; break;
        case 3: y_inc -= elapsed_seconds * (float)speed; break;
        case -1: y_inc = 0; x_inc = 0; break;

    }

    QPointF pos = sprite->pos();
    pos.setX(pos.x() + x_inc);
    pos.setY(pos.y() + y_inc);
   this->sprite->setPos(pos);
}

const QRectF monsters::GetBoundingBox()
{
     return sprite->sceneBoundingRect();
}

const int monsters::Get_Orientation()
{
    return orientation;
}

const PacmanStruct monsters::GetPacmanStruct()
{
    PacmanStruct s;
    s.owner_ = this->id;
    s.score = this->score;
    s.orientation = this->orientation;
    s.x = (int)this->sprite->pos().x();
    s.y = (int)this->sprite->pos().y();
    s.state = this->state;
    return s;
}

const int monsters::GetId()
{
    return this->id;
}

void monsters::SetId(int id_)
{
    this->id = id_;
}

const int monsters::GetState()
{
    return state;
}



void monsters::SetState(int s)
{
    if (s==0)
    {
        speed=100;
    }



    this->state = s;
}

const float monsters::GetSpeed()
{
    return speed;
}

void monsters::SetSpeed(int s)
{
    this->speed = s;
}

const int monsters::GetStateTimer()
{
    return statetimer;
}

void monsters::DecrementStateTimer()
{
    this->statetimer -= 1;
}

 void monsters::IncrementScorePellet(int amount)
 {
    this->score += amount;
 }


monsters::~monsters()
{

}

