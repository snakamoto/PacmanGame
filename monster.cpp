#include "monster.h"
#include "QDebug"

Monster::Monster()
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

    if(orient >= 0)
        sprite->setRotation(orient*90);

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

const monstersstruct Monster::GetPacmanStruct()
{
    monstersstruct s;
    s.owner_ = this->id;
    s.score = this->score;
    s.orientation = this->orientation;
    s.x = (int)this->sprite->pos().x();
    s.y = (int)this->sprite->pos().y();
    s.state = this->state;
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
            if(last_orientation != cur_orientation)
                sprite->setRotation(180);
        }
        else //Facing right
        {
            cur_orientation = 1;
           // if(last_orientation != cur_orientation)
           //     sprite->setRotation(0);
        }
    }
    else //Moving most in y dir
    {
        if (direction.y() < 0) //Facing bottom
        {
            cur_orientation = 2;
          //  if(last_orientation != cur_orientation)
           //     sprite->setRotation(270);
        }
        else //Facing top
        {
            cur_orientation = 3;
           // if(last_orientation != cur_orientation)
            //    sprite->setRotation(90);

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
    UpdatePathing(elapsed_seconds);
}

bool Monster::IsPathDone()
{
    return stage_index >= (path.GetLength() - 1);
}


