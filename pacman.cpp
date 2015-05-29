#include "pacman.h"
#include "QDebug"

Pacman::Pacman(): pactime(25.0)
{
        sprite = new QGraphicsRectItem();
       sprite->setRect(0,0,WIDTH,WIDTH); //Size of sprite
       sprite->setTransformOriginPoint(WIDTH/2,WIDTH/2); //To rotate about the origin

       QImage sheet("images/ChomperSprites.png");
       pixright = sheet.copy(11*32, 0, 32, 32);
       pixnextframeright = sheet.copy(10*32, 0, 32, 32);
       pixdown = sheet.copy(11*32, 32, 32, 32);
       pixnextframedown = sheet.copy(10*32, 32, 32, 32);
       pixleft = sheet.copy(11*32, 32*2, 32, 32);
       pixnextframeleft = sheet.copy(10*32, 32*2, 32, 32);
       pixup = sheet.copy(11*32, 32*3, 32, 32);
       pixnextframeup = sheet.copy(10*32, 32*3, 32, 32);
      // pix=pix.scaled(WIDTH,WIDTH); //Scale image to fit BB

       sprite->setBrush(QBrush(pixright));  //Set brush to loaded image
       const QColor transparent(0,0,0,0);

       QPen transPen(transparent);
       sprite->setPen(transPen); //Remove border from rect


    speed = 100;
    score = 0;
    state=0;
    statetimer=10000;

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

}


void Pacman::SetPosition(int x, int y)
{
    sprite->setPos(x,y);
}

void Pacman::Update(float elapsed_seconds)
{
    // animation time frame
    const float animationtime = 8.0;
    // animation time step
    pacani+=pactime*elapsed_seconds;
    // for pause let pactime = 0;

    // reset for 100% of cycle
   if(pacani > animationtime)
       pacani = 0;


     float x_inc = 0;
     float y_inc = 0;
     //orient 0 - left 1 -top 2-right 3 - bottom
     switch (orientation)
     {
         case 0:
                 x_inc += elapsed_seconds * (float)speed;
                 // duty cycle of 50%
                  if(pacani>animationtime/2.0)
                      sprite->setBrush(QBrush(pixright));  //Set brush to loaded image
                  else
                      sprite->setBrush(QBrush(pixnextframeright));  //Set brush to loaded image
                 break;
         case 1:
                 y_inc += elapsed_seconds * (float)speed;
                 // duty cycle of 50%
                  if(pacani>animationtime/2.0)
                      sprite->setBrush(QBrush(pixdown));  //Set brush to loaded image
                  else
                      sprite->setBrush(QBrush(pixnextframedown));  //Set brush to loaded image
                 break;
         case 2:
                 x_inc -= elapsed_seconds * (float)speed;
                 // duty cycle of 50%
                  if(pacani>animationtime/2.0)
                      sprite->setBrush(QBrush(pixleft));  //Set brush to loaded image
                  else
                      sprite->setBrush(QBrush(pixnextframeleft));  //Set brush to loaded image
                 break;

         case 3: y_inc -= elapsed_seconds * (float)speed;
                 // duty cycle of 50%
                  if(pacani>animationtime/2.0)
                      sprite->setBrush(QBrush(pixup));  //Set brush to loaded image
                  else
                      sprite->setBrush(QBrush(pixnextframeup));  //Set brush to loaded image
                 break;
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
    if (s==0)
    {
        speed=100;
    }



    this->state = s;
}

const float Pacman::GetSpeed()
{
    return speed;
}

void Pacman::SetSpeed(int s)
{
    this->speed = s;
}

const int Pacman::GetStateTimer()
{
    return statetimer;
}

void Pacman::DecrementStateTimer()
{
    this->statetimer -= 1;
}

void Pacman::SetStateTimer(int t)
{
    this->statetimer = t;
}

 void Pacman::IncrementScorePellet(int amount)
 {
    this->score += amount;
 }
