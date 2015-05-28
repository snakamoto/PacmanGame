#include "pacgraphicsscene.h"
#include "astar.h"
#include "tiledmap.h"

PacGraphicsScene::PacGraphicsScene(int x, int y, int w, int h, QGraphicsView *view) :
    QGraphicsScene(x,y,w,h,view)
{
   // QPixmap pix("images/test_map.png");

    //this->addRect(0,0,TILES_X*WIDTH,TILES_Y*WIDTH,QPen(),QBrush(pix));

    startNode=TileNode(1,(TILES_Y-1)/2,nullptr); //starting position for spawned enemies
    endNode = TileNode(TILES_X-2,TILES_Y/2,nullptr); //enemies move to this position
    pathingArr = &t_[0][0];
    for(int i =0; i < TILES_X; i++)
    {
        for(int j =0; j<TILES_Y; j++)
        {
            pathingArr[j*W+i] = TileNode(i,j,nullptr);
            pathingArr[j*W+i].h = AStar::ManhattanHeuristic(pathingArr[j*W+i],endNode);
            pathingArr[j*W+i].type = 0;
        }
    }

    //backgroundRect
    backgroundRect = new QGraphicsRectItem();
    //this->addItem(backgroundRect);
    LoadMap("maps/test_map");

    newPath = true;

    local_pac = new Pacman();
    local_pac->SetPosition(0, WIDTH * 9);
    pacmen.push_back(local_pac);


    for(int i = 0; i < pacmen.size(); i++)
        this->addItem(pacmen[i]->sprite);




}

void PacGraphicsScene::GeneratePath()
{
    //Init pathfinding
    AStar starretjie = AStar(W,H,&pathingArr);

    //find path
    std::vector<TileNode> path = starretjie.Search(startNode,endNode);
    if(path.empty())
        return; //dont continue if the path is blocked

    //We need to clear the previous path that is displayed
    for(int i =0; i < testPath.size(); i++)
    {
        QGraphicsItem *qi = testPath[i];
        this->removeItem(qi);
        delete qi;
    }
    testPath.clear();
    //This path displayed is only for testing purposes and should be removed

    //Create new path to be displayed
    for(int i =0; i<path.size()-1; i++)
    {
        TileNode point = path[i];

        QGraphicsRectItem *r = new QGraphicsRectItem(point.x*WIDTH,point.y*WIDTH,WIDTH,WIDTH);
        r->setBrush(QColor(255,255,0,10));
        testPath.push_back(r);
        this->addItem(r);
    }
    //Again should actually be removed

    //Update each enemy's path; this occurs when a new obstacle is placed
    for(int i =0; i < enemies.size(); i++)
    {
        Enemy *e = enemies[i];

        //Get coordinates in matrix
        int x = (int)e->sprite->scenePos().x(); x /= WIDTH;
        int y = (int)e->sprite->scenePos().y(); y /= WIDTH;

        std::vector<TileNode> path = starretjie.Search(TileNode(x,y,nullptr),endNode);
        e->UpdatePath(path); //Update enemy path
    }
}

void PacGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{



}



void PacGraphicsScene::keyPressEvent(QKeyEvent *e)
{



    if(e->key() == Qt::Key_Left)
    {
        next_orientation = 2;

    }
    if(e->key() == Qt::Key_Up)
    {
        next_orientation = 3;


    }
    if(e->key() == Qt::Key_Down)
    {
        next_orientation = 1;

    }
    if(e->key() == Qt::Key_Right)
    {
        next_orientation = 0;

    }
}

Enemy* PacGraphicsScene::spawn_enemy(int x, int y)
{
    last_enemy_id++;

    //Create new enemy
    Enemy *e = new Enemy();
    e->SetUniqueID(last_enemy_id);
    e->SetPosition(x,y);
    this->addItem(e->sprite);

    //and give it a path to follow
    AStar starretjie = AStar(W,H,&pathingArr);

    if(newPath)
        path = starretjie.Search(startNode,endNode);
    e->UpdatePath(path);

    enemies.push_back(e);

    newPath = false;

    if(peerConnection)
        peerConnection->Send(e->GetEnemyStruct());
    return e;
}

int updates = 0;
void PacGraphicsScene::Update(float elapsed_seconds)
{

    updates++;


    //Used to remove enemies when they have reached their destination

    pacmen[0]->Update(elapsed_seconds);

    int x = local_pac->sprite->pos().x() / WIDTH;
    int y = local_pac->sprite->pos().y() / WIDTH;
    int cur_orientation = local_pac->Get_Orientation();

    if(((int)local_pac->sprite->pos().x() % WIDTH == 0 && (int)local_pac->sprite->pos().y() % WIDTH == 0) || abs(cur_orientation - next_orientation) == 2)
    {
        if(next_orientation==0)
        {
            if(pathingArr[y*W+(x+1)].type == 0)
                local_pac->Set_Orientation(next_orientation);
        }
        if(next_orientation == 1)
        {
            if(pathingArr[(y+1)*W+x].type == 0)
                local_pac->Set_Orientation(next_orientation);
        }
        if(next_orientation == 2)
        {
            if(pathingArr[y*W+(x-1)].type == 0)
                local_pac->Set_Orientation(next_orientation);
        }
        if(next_orientation == 3)\
        {
            if(pathingArr[(y-1)*W+x].type == 0)
                local_pac->Set_Orientation(next_orientation);
        }
    }

    for(int i = 0; i < pacmen.size(); i++)
    {
        if(!((int)local_pac->sprite->pos().x() % WIDTH == 0 && (int)local_pac->sprite->pos().y() % WIDTH == 0))
        {
            continue;
        }
        Pacman *paccy = pacmen[i];
        x = paccy->sprite->pos().x() / WIDTH;
        y = paccy->sprite->pos().y() / WIDTH;

        int orientation = paccy->Get_Orientation();
        if (orientation == 0 && pathingArr[y*W + x+1].type == 1)
        {
            paccy->Set_Orientation(-1);
            qDebug() << "CAnt go right";
        }
        if (orientation == 1 && pathingArr[(y+1)*W + x].type == 1)
        {
            paccy->Set_Orientation(-1);
             qDebug() << "CAnt go top";
        }
        if (orientation == 2 && pathingArr[y*W + x-1].type == 1)
        {
            paccy->Set_Orientation(-1);
             qDebug() << "CAnt go left";
        }
        if (orientation == 3 && pathingArr[(y-1)*W + x].type == 1)
        {
            paccy->Set_Orientation(-1);
             qDebug() << "CAnt go bot";
        }
    }

    //Update enemies
  //  for(int i =0; i < enemies.size(); i++)
  //  {
       // Enemy *e = enemies[i];
       // e->Update(elapsed_seconds);


            //Enemies have reached their destination. Player sucks and should be penalized!!!

            //Delete enemy

            //this->removeItem(e->sprite);

            //find enemy in enemy vector and remove since no longer needed
          //  auto item = std::find(enemies.begin(), enemies.end(), e);
          //  enemies.erase(item);

          //  delete e; //Free some valuable memory

          //  SendPlayerSync();
         //   return;



  //  }


    //Update projectiles
    QRectF playArea(0, 0, TILES_X*WIDTH, TILES_Y*WIDTH);
    //Projectiles need to be withing playArea bounds



}

void PacGraphicsScene::mouseMoveEvent(QMouseEvent *event)
{

}





void PacGraphicsScene::SetConnection(Connection *peerConn)
{
    peerConnection = peerConn;
    if(!peerConn)
    {
        p2_goldText->hide();
        p2_killsText->hide();
        return;
    }

    connect(peerConnection,SIGNAL(OnNewEnemyReceived(EnemyStruct)), this, SLOT(on_new_enemy_received(EnemyStruct)));
    connect(peerConnection,SIGNAL(OnNewProjectileRecieved(ProjectileStruct)),this,SLOT(on_new_projectile_recieved(ProjectileStruct)));
    connect(peerConnection,SIGNAL(OnNewPSyncRecieved(PlayerSyncStruct)), this, SLOT(on_new_psync_recieved(PlayerSyncStruct)));
    connect(peerConnection,SIGNAL(OnNewTowerReceived(TowerStruct)),this, SLOT(on_new_tower_received(TowerStruct)));
    connect(peerConnection,SIGNAL(OnRemoveEnemyRecieved(RemoveEnemyStruct)),this,SLOT(on_remove_enemy_recieved(RemoveEnemyStruct)));
}

void PacGraphicsScene::SetPlayerAsHost()
{
    localPlayerId = 1;
    remotePlayerId = 2;
}

void PacGraphicsScene::SetPlayerAsClient()
{
    localPlayerId = 2;
    remotePlayerId = 1;
}

void PacGraphicsScene::on_new_enemy_received(EnemyStruct es)
{
   // spawn_enemy(e.x,e.y);
    last_enemy_id++;

    Enemy *e = new Enemy();
    e->SetUniqueID(last_enemy_id);
    e->SetPosition(es.x,es.y);
    this->addItem(e->sprite);

    //and give it a path to follow
    AStar starretjie = AStar(W,H,&pathingArr);

    if(newPath)
        path = starretjie.Search(startNode,endNode);
    e->UpdatePath(path);

    enemies.push_back(e);

    newPath = false;

}


void PacGraphicsScene::on_new_psync_recieved(PlayerSyncStruct s)
{
    /*
    if(localPlayerId == 2)
    {
        lives = s.lives;
        p1_gold = s.p1_gold;
        p2_gold = s.p2_gold;
        p1_kills = s.p1_kills;
        p2_kills = s.p2_kills;
    }
    if(localPlayerId == 1)
    {
       p2_gold = s.p2_gold;
       p2_kills = s.p2_kills;
    }


    p1_goldText->setPlainText("Player 1 Gold: " + QString::number(p1_gold));
    p2_goldText->setPlainText("Player 2 Gold: " + QString::number(p2_gold));
    p1_killsText->setPlainText("Player 1 Kills: " + QString::number(p1_kills));
    p2_killsText->setPlainText("Player 2 Kills: " + QString::number(p2_kills));*/

}

void PacGraphicsScene::on_remove_enemy_recieved(RemoveEnemyStruct en)
{
    if(localPlayerId==1)
        return;

    for(int i = 0; i< enemies.size(); i++)
    {
        Enemy *e = enemies[i];
        if(e->GetUniqueID() == en.uid)
        {
            this->removeItem(e->sprite);
            //We no longer need to track the enemy within our vector
           // auto item = std::find(enemies.begin(), enemies.end(), en);
           // enemies.erase(item);
            enemies.erase(enemies.begin() + i);

            delete e;
            return;
        }
    }
}

void PacGraphicsScene::SendPlayerSync()
{
    /*
    PlayerSyncStruct ps;
    ps.lives = lives;
    ps.p1_gold = p1_gold;
    ps.p1_kills = p1_kills;
    ps.p2_gold = p2_gold;
    ps.p2_kills = p2_kills;

    if(peerConnection)
        peerConnection->Send(ps);*/
}


void PacGraphicsScene::LoadMap(QString fileName)
{
    //Clear grid
    for(int i =0; i < TILES_X; i++)
    {
        for(int j =0; j<TILES_Y; j++)
        {
            pathingArr[j*W+i] = TileNode(i,j,nullptr);
            pathingArr[j*W+i].h = AStar::ManhattanHeuristic(pathingArr[j*W+i],endNode);
            pathingArr[j*W+i].type = 0;
        }
    }

    //Set background image

    backgroundRect->setRect(0,0,TILES_X*WIDTH,TILES_Y*WIDTH);
    backgroundRect->setPen(QPen());


    QPixmap pix(fileName+".png");
    backgroundRect->setBrush(QBrush(pix));
    //this->addRect(0,0,TILES_X*WIDTH,TILES_Y*WIDTH,QPen(),QBrush(pix));

    qDebug () << "Loading map" << fileName + ".tmx";
    TiledMap m(fileName + ".tmx");
    m.LoadCollisionLayer(&pathingArr, W);
    qDebug() << "Test";


    for(int i =0; i < TILES_X; i++)
    {
        for(int j =0; j<TILES_Y; j++)
        {
            if(pathingArr[j*W+i].type==1)
            {
                QGraphicsRectItem *item = new QGraphicsRectItem(i*WIDTH,j*WIDTH,WIDTH,WIDTH);
                this->addItem(item);
            }

        }
    }

   // this->addRect(startNode.x*WIDTH,startNode.y*WIDTH,WIDTH,WIDTH, QPen(), Qt::green);
  //  this->addRect(endNode.x*WIDTH,endNode.y*WIDTH,WIDTH,WIDTH, QPen(), Qt::red);

    //LoadPostMapItems();

}

