#include "pacman.h"
#include "QDebug"

Pacman::Pacman()
{
    sprite = new QGraphicsRectItem();
    sprite->setRect(0,0,WIDTH,WIDTH); //Size of sprite
    sprite->setTransformOriginPoint(WIDTH/2,WIDTH/2); //To rotate about the origin

     QPixmap pix("images/pacman_open.png");

    pix=pix.scaled(WIDTH,WIDTH); //Scale image to fit BB
    sprite->setBrush(QBrush(pix));  //Set brush to loaded image
    const QColor transparent(0,0,0,0);

    QPen transPen(transparent);
    sprite->setPen(transPen); //Remove border from rect

    speed = 100;
    score = 0;

    Set_Orientation(0);

}

Pacman::~Pacman()
{

}

const int Pacman::GetScore()
{
    return score;
}

void Pacman::Set_Orientation(int orient)
{
    this->orientation = orient;
    //orient 0-right - 1 -top 2-left 3 - bottom

    if(orient >= 0)
        sprite->setRotation(orient*90);

}


void Pacman::SetPosition(int x, int y)
{
    sprite->setPos(x,y);
}

void Pacman::Update(float elapsed_seconds)
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

const QRectF Pacman::GetBoundingBox()
{
     return sprite->sceneBoundingRect();
}

const int Pacman::Get_Orientation()
{
    return orientation;
}

const PacmanStruct Pacman::GetPacmanStruct()
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

const int Pacman::GetId()
{
    return this->id;
}

void Pacman::SetId(int id_)
{
    this->id = id_;
}

const int Pacman::GetState()
{
    return state;
}

void Pacman::SetState(int s)
{
    this->state = s;
}

 void Pacman::IncrementScorePellet(int amount)
 {
    this->score += amount;
 }
