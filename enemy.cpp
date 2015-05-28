#include "enemy.h"
#include "QPen"
#include <cmath>
Enemy::Enemy()
{

    sprite = new QGraphicsRectItem();
    sprite->setRect(0,0,WIDTH,WIDTH); //Size of sprite
    sprite->setTransformOriginPoint(WIDTH/2,WIDTH/2); //To rotate about the origin

    QPixmap pix(":/ims/creep1.png");

    pix=pix.scaled(WIDTH,WIDTH); //Scale image to fit BB
    sprite->setBrush(QBrush(pix));  //Set brush to loaded image
    sprite->setPen(QPen(Qt::transparent)); //Remove border from rect

    bounty = 10;
    speed = 10;

    //Initialize pathing vars
    stage_pos = 0;
    stage_index = 0;

}


void Enemy::UpdatePathing(float seconds)
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
            if(last_orientation != cur_orientation)
                sprite->setRotation(0);
        }
    }
    else //Moving most in y dir
    {
        if (direction.y() < 0) //Facing bottom
        {
            cur_orientation = 2;
            if(last_orientation != cur_orientation)
                sprite->setRotation(270);
        }
        else //Facing top
        {
            cur_orientation = 3;
            if(last_orientation != cur_orientation)
                sprite->setRotation(90);
        }
    }
    last_orientation = cur_orientation;
}

void Enemy::UpdatePath(vector<TileNode> node_path)
{
    Path p = Path(node_path);
    UpdatePath(p);
}

void Enemy::UpdatePath(Path p)
{
    stage_index = 0;
    path = p;
}

const bool Enemy::IsAlive()
{
    return isAlive;
}



void Enemy::SetPosition(int x, int y)
{
    sprite->setPos(x,y);
}

const int Enemy::GetBounty()
{
    return bounty;
}


void Enemy::Update(float elapsed_seconds)
{
    UpdatePathing(elapsed_seconds);
}

const QRectF Enemy::GetBoundingBox()
{
    return sprite->sceneBoundingRect();
}

const EnemyStruct Enemy::GetEnemyStruct()
{
    EnemyStruct s;
    s.id = id;
    s.orientation = cur_orientation;
    s.x = GetBoundingBox().x();
    s.y = GetBoundingBox().y();
    return s;
}

const int Enemy::GetUniqueID()
{
    return uniqueId;
}

void Enemy::SetUniqueID(int uid)
{
    uniqueId=uid;
}

