#include "monster.h"
#include "QDebug"

Monster::Monster():pacani(0),pactime(10.0)
{
    sprite = new QGraphicsRectItem();
       sprite->setRect(0,0,WIDTH,WIDTH); //Size of sprite
       sprite->setTransformOriginPoint(WIDTH/2,WIDTH/2); //To rotate about the origin


    const QColor transparent(0,0,0,0);
    QPen transPen(transparent);
    sprite->setPen(transPen); //Remove border from rect

    const int random4 = (qrand()%4)*2;
    qDebug()<<random4;
    QImage sheet("images/ChomperSprites.png");
    pixright = sheet.copy(random4*32, 0, 32, 32);
    pixnextframeright = sheet.copy((random4+1)*32, 0, 32, 32);
    pixdown = sheet.copy(random4*32, 32, 32, 32);
    pixnextframedown = sheet.copy((random4+1)*32, 32, 32, 32);
    pixleft = sheet.copy(random4*32, 32*2, 32, 32);
    pixnextframeleft = sheet.copy((random4+1)*32, 32*2, 32, 32);
    pixup = sheet.copy(random4*32, 32*3, 32, 32);
    pixnextframeup = sheet.copy((random4+1)*32, 32*3, 32, 32);

    sprite->setBrush(QBrush(pixright));  //Set brush to loaded image


    state=2;
    statetimer=0;

    stage_pos = 0;
    stage_index = 0;

    Set_Orientation(0);

    speed = 100;

}

const int Monster::GetScore()
{
    return score;
}

void Monster::Set_Orientation(int orient)
{
    this->orientation = orient;
    //orient 0-right - 1 -top 2-left 3 - bottom


}

void Monster::SetPosition(int x, int y)
{
    sprite->setPos(x,y);
}

const QRectF Monster::GetBoundingBox()
{
     return sprite->sceneBoundingRect();
}

const int Monster::Get_Orientation()
{
    return orientation;
}

const MonsterStruct Monster::GetMonsterStruct()
{
    MonsterStruct s;
    s.id = this->id;
    s.state = this->state;
    s.state_timer = this->statetimer;
    s.orientation = this->orientation;
    s.x = (int)this->sprite->pos().x();
    s.y = (int)this->sprite->pos().y();

    return s;
}

const int Monster::GetId()
{
    return this->id;
}

void Monster::SetId(int id_)
{
    this->id = id_;
}

const int Monster::GetState()
{
    return state;
}

void Monster::SetState(int s)
{
    if (s==0)
    {
        speed=100;
    }
    this->state = s;
}

const float Monster::GetSpeed()
{
    return speed;
}

void Monster::SetSpeed(int s)
{
    this->speed = s;
}

const int Monster::GetStateTimer()
{
    return statetimer;
}

void Monster::DecrementStateTimer()
{
    this->statetimer -= 1;
}


Monster::~Monster()
{

}

void Monster::UpdatePathing(float seconds)
{
    //Collection of points to move to
    vector<QPointF> points = path.GetPoints();
    //Length of each point
    vector<float> lengths = path.GetLengths();
    //Normalized directions
    vector<QPointF> directions = path.GetDirections();

    if (points.size() == 0)
        return;

    if (stage_index != points.size() - 1)
    {
        stage_pos += speed * seconds;


    }
    else
    {
        //We arrived at our destination
        return;
    }
    while (stage_pos > lengths[stage_index])
    {
        //we overstepped our length,
        stage_pos -= lengths[stage_index];
        stage_index++;

        if (stage_index == points.size() - 1)
        {   //Set position to ending point
            sprite->setPos(points[stage_index]);
            return;
        }
    }

    //set position to current point plus the amount we are heeding to for to the next point
    sprite->setPos(points[stage_index] + directions[stage_index] * stage_pos);


    QPointF direction = directions[stage_index];

    //Set the correct orientation for the sprite
        if (std::abs(direction.x()) > std::abs(direction.y())) //Moving most in x dir
    {
        if (direction.x() < 0) //Facing left
        {
            //set rotation is an expensive call so we only call it when there has been a change from the previous call
            cur_orientation = 0;

        }
        else //Facing right
        {
            cur_orientation = 1;

        }
    }
    else //Moving most in y dir
    {
        if (direction.y() < 0) //Facing bottom
        {
            cur_orientation = 2;

        }
        else //Facing top
        {
            cur_orientation = 3;


        }
    }
    last_orientation = cur_orientation;
}

void Monster::UpdatePath(vector<TileNode> node_path)
{

    Path p = Path(node_path);
    UpdatePath(p);
}

void Monster::UpdatePath(Path p)
{
    stage_index = 0;
    path = p;
}

void Monster::Update(float elapsed_seconds)
{
    // animation time frame
       const float animationtime = 40.0;
       // animation time step
       pacani+=pactime*elapsed_seconds;
       // for pause let pactime = 0;
      if(pacani>animationtime*0.125)
        sprite->setBrush(QBrush(pixright));  //Set brush to loaded image
      if(pacani>animationtime*0.25)
        sprite->setBrush(QBrush(pixnextframeright));  //Set brush to loaded image
      if(pacani>animationtime*3.0/8.0)
        sprite->setBrush(QBrush(pixdown));  //Set brush to loaded image
      if(pacani>animationtime*4.0/8.0)
        sprite->setBrush(QBrush(pixnextframeleft));  //Set brush to loaded image
      if(pacani>animationtime*5.0/8.0)
        sprite->setBrush(QBrush(pixleft));  //Set brush to loaded image
      if(pacani>animationtime*6.0/8.0)
        sprite->setBrush(QBrush(pixnextframeleft));  //Set brush to loaded image
      if(pacani>animationtime*7.0/8.0)
        sprite->setBrush(QBrush(pixup));  //Set brush to loaded image
      if(pacani>animationtime)
        sprite->setBrush(QBrush(pixnextframeup));  //Set brush to loaded image
      // reset for 100% of cycle
     if(pacani > animationtime*1.1)
         pacani = 0;
    UpdatePathing(elapsed_seconds);
}

bool Monster::IsPathDone()
{
    return stage_index >= (path.GetLength() - 1);
}

void Monster::Reset()
{
    stage_pos = 0;
    stage_index = 0;
    path = Path();
}

void Monster::SetStateTimer(int st)
{
    this->statetimer = st;
}



