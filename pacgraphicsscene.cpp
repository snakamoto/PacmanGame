#include "pacgraphicsscene.h"
#include "astar.h"
#include "tiledmap.h"

PacGraphicsScene::PacGraphicsScene(int x, int y, int w, int h, QGraphicsView *view) :
    QGraphicsScene(x,y,w,h,view)
{
    peerConnection = nullptr;
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

    LoadMap("maps/test_map");


    newPath = true;

    local_pac = new Pacman();
    local_pac->SetPosition(3 * WIDTH, WIDTH * 9);
    local_pac->Set_Orientation(-1);
    local_pac->SetId(1);
    pacmen.push_back(local_pac);

    remote_pac = new Pacman();
    remote_pac->SetPosition(3 * WIDTH,1*WIDTH);
    remote_pac->Set_Orientation(-1);
    remote_pac->SetId(2);
    pacmen.push_back(remote_pac);


    for(int i = 0; i < pacmen.size(); i++)
        this->addItem(pacmen[i]->sprite);


    for(int i = 0; i < 3; i++)
    {
        Monster *m = new Monster();
        m->SetPosition(WIDTH*(9+i),9*WIDTH);
        m->SetId(i);
        this->addItem(m->sprite);
        monstersArray.push_back(m);

    }
    for(int i = 0; i < monstersArray.size(); i++)
    {
        Monster *t = monstersArray[i];
        AStar starretjie = AStar(W,H,&pathingArr);
        TileNode start(9,9, nullptr); TileNode end(9,9, nullptr);

        std::vector<TileNode> nodePath = starretjie.Search(start, end);
        int x = t->sprite->pos().x();
        int y = t->sprite->pos().y();
        TileNode enemyPos = TileNode(x / WIDTH, y / WIDTH, nullptr);
        nodePath.insert(nodePath.begin(), enemyPos);
        t->UpdatePath(nodePath);
        SendMonsterSync(t);

    }
    //Powerups

    //Pellet
    int k = 0;
    for(int i = 1; i < TILES_X; i++)
    {
        for(int j =1; j < TILES_Y; j++)
        {
            if(pathingArr[j*W+i].type != 0)
                continue;
            // create pellet or powerup
            if (qrand()%9!=1)
            {
            Pellet *pellet = new Pellet();
            pellet->SetEaten(false);
            pellet->SetId(k);
            pellet->SetType(qrand()%9);
            pellet->SetPosition(i*WIDTH,j*WIDTH);
            SendPelletSync(pellet);
            if(IsHost() || !IsConnected())
            {
                pellets.push_back(pellet);
                this->addItem(pellet->sprite);
                SendPelletSync(pellet);
            }

            }
            else
            {
                PowerUp *powerup = new PowerUp();
                powerup->SetEaten(false);
                powerup->SetId(k);
                powerup->SetType(qrand()%9);
                powerup->SetPosition(i*WIDTH,j*WIDTH);
                powerup->SetType(qrand()%8);
                if(IsHost() || !IsConnected())
                {
                    powerups.push_back(powerup);
                    this->addItem(powerup->sprite);
                    SendPowerUpSync(powerup);
                }
            }

             k++;
        }
    }

    local_player_score = new QGraphicsTextItem();
    local_player_score->setPlainText("Score: 0");
    QColor color(255,255,0,255);
    local_player_score->setDefaultTextColor(color);
    local_player_score->setPos(0,0);
    this->addItem(local_player_score);

}

PacGraphicsScene::~PacGraphicsScene()
{
    qDebug() << "Destructing";
    for(int i = 0; i < pacmen.size(); i++)
    {
        delete pacmen[i];
    }
    for(int i = 0; i < pellets.size(); i++)
    {
        delete pellets[i];
    }
    for(int i = 0; i < powerups.size(); i++)
    {
        delete powerups[i];
    }
    for(int i = 0; i < monstersArray.size(); i++)
    {
        delete monstersArray[i];
    }
    pacmen.clear(); powerups.clear(); monstersArray.clear(); pellets.clear();
    delete pathingArr;
    delete peerConnection;

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

int updates = 0;

void PacGraphicsScene::ChooseRandomDestination(Monster *t)
{
    AStar starretjie = AStar(W,H,&pathingArr);
    int RandomValuex=qrand()%TILES_X;
    int RandomValuey=qrand()%TILES_X;
    while (pathingArr[RandomValuex + RandomValuey].type == 0)
    {
        RandomValuex=qrand()%TILES_X;
        RandomValuey=qrand()%TILES_X;
    }
    TileNode start(t->sprite->x()/WIDTH,t->sprite->y()/WIDTH, nullptr);
    TileNode end(RandomValuex,RandomValuey, nullptr);
    std::vector<TileNode> nodePath = starretjie.Search(start, end);
    int x = t->sprite->pos().x();
    int y = t->sprite->pos().y();
    TileNode enemyPos = TileNode(x / WIDTH, y / WIDTH, nullptr);
    nodePath.insert(nodePath.begin(), enemyPos);
    t->UpdatePath(nodePath);
}


void PacGraphicsScene::ChooseSpecificDestination(Monster *t)
{


}

void PacGraphicsScene::Update(float elapsed_seconds)
{



    for(int i = 0; i < monstersArray.size(); i++)
    {

    Monster *t = monstersArray[i];
        if (t->IsPathDone())
        {
            if (i==0)
            {
                Pacman *paccy;
                //Closest pacman
                int pac_id = 0;
                float closest_dist = 1000;
                for(int j = 0; j < pacmen.size(); j++)
                {
                    Pacman *pac = pacmen[j];
                    float dx = pac->sprite->x() - t->sprite->x();
                    float dy = pac->sprite->y() - t->sprite->y();
                    float dist = sqrtf(dx*dx +dy*dy);
                    if(dist < closest_dist)
                    {
                        closest_dist = dist;
                        pac_id = j;
                    }
                }
                paccy = pacmen[pac_id];

                AStar starretjie = AStar(W,H,&pathingArr);
                TileNode start(t->sprite->x()/WIDTH,t->sprite->y()/WIDTH, nullptr);
                TileNode end(paccy->sprite->x()/WIDTH,paccy->sprite->y()/WIDTH, nullptr);
                std::vector<TileNode> nodePath = starretjie.Search(start, end);
                int x = t->sprite->pos().x();
                int y = t->sprite->pos().y();
                TileNode enemyPos = TileNode(x / WIDTH, y / WIDTH, nullptr);
                nodePath.insert(nodePath.begin(), enemyPos);
                t->UpdatePath(nodePath);
            }
            else
            {
                ChooseRandomDestination(t);
            }
            SendMonsterSync(t);
        }
    }





    updates++;
    // constantly decrease statetimer to zero
    for(int i = 0; i < pacmen.size(); i++)
    {
        Pacman *paccy = pacmen[i];
        if (paccy->GetStateTimer() > 0)
        {
            paccy->DecrementStateTimer();
        }
        //reset states
        else
        {
        paccy->SetState(0);
        }


        // powerups
        // state 2 speed
        if (paccy->GetState()==2)
        {
            if (paccy->GetSpeed() == 100)
            {
            paccy->SetSpeed(200);
            }
        }

    }

    // used to remove enemies when they have reached their destination

    int x = local_pac->sprite->pos().x() / WIDTH;
    int y = local_pac->sprite->pos().y() / WIDTH;
    int cur_orientation = local_pac->Get_Orientation();


    // set the pacman to the queued orientation if possible
    if(((int)local_pac->sprite->pos().x() % WIDTH == 0 && (int)local_pac->sprite->pos().y() % WIDTH == 0) || abs(cur_orientation - next_orientation) == 2)
    {
        if(next_orientation==0)
        {
            if(pathingArr[y*W+(x+1)].type == 0 || local_pac->state==1)
            {
                local_pac->Set_Orientation(next_orientation);

                SendPacmanSync();
            }

        }
        else if(next_orientation == 1)
        {
            if(pathingArr[(y+1)*W+x].type == 0 || local_pac->state==1)
            {
                local_pac->Set_Orientation(next_orientation);
                SendPacmanSync();
            }
        }
        else if(next_orientation == 2)
        {
            if(pathingArr[y*W+(x-1)].type == 0 || local_pac->state==1)
            {
                local_pac->Set_Orientation(next_orientation);
              SendPacmanSync();
            }
        }
        else if(next_orientation == 3)
        {
            if(pathingArr[(y-1)*W+x].type == 0 || local_pac->state==1)
            {
                local_pac->Set_Orientation(next_orientation);
                SendPacmanSync();
            }
        }
    }




    // update the pacmen
    for(int i = 0; i < pacmen.size(); i++)
    {
        Pacman *paccy = pacmen[i];
        x = paccy->sprite->pos().x() / WIDTH;
        y = paccy->sprite->pos().y() / WIDTH;
        int orientation = paccy->Get_Orientation();

        paccy->Update(elapsed_seconds);

        //Stop the pacman if it tries to ram a wall
        if(!((int)paccy->sprite->pos().x() % WIDTH == 0 && (int)paccy->sprite->pos().y() % WIDTH == 0))
        {
            continue;
        }

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
        //Loop the pacman
        //To do: Use looping positions from Tiled
        if(x == 0)
        {
            x = TILES_X - 1;
            paccy->SetPosition(x*WIDTH,y*WIDTH);
        }
        else if(x == TILES_X-1)
        {
            x = 1;
            paccy->SetPosition(x*WIDTH,y*WIDTH);
        }
        if(y == 0)
        {
            y = TILES_Y - 1;
            paccy->SetPosition(x*WIDTH,y*WIDTH);
        }
        else if(y == TILES_Y - 1)
        {
            y = 0;
            paccy->SetPosition(x*WIDTH,y*WIDTH);
        }
    }


    // collision detection
    for(int i =0; i< pacmen.size(); i++)
    {
        Pacman *paccy = pacmen[i];
        x = paccy->sprite->pos().x() / WIDTH;
        y = paccy->sprite->pos().y() / WIDTH;


        // pellet collision detection
        for(int i = 0; i < pellets.size(); i++)
        {
            Pellet *pellet = pellets[i];
            if(pellet->GetEaten()==true)
                continue;
            if(paccy->GetBoundingBox().intersects(pellet->GetBoundingBox()))
            {
                paccy->IncrementScorePellet(pellet->GetType());
                pellet->SetEaten(true);
                this->removeItem(pellet->sprite);
                qDebug() << paccy->GetScore();
                if(paccy->GetId() == local_pac->GetId())
                    local_player_score->setPlainText("Score: " + QString::number(paccy->GetScore()));
                //SendPelletSync(pellet);
            }
        }


        // powerup collision detection
        for(int j = 0; j < powerups.size(); j++)
        {
            PowerUp *powerup = powerups[j];
            if(powerup->GetEaten()==true)
                continue;
            if(paccy->GetBoundingBox().intersects(powerup->GetBoundingBox()))
            {
                int myTempValue = powerup->GetType();

                if (myTempValue < 5)
                {
                    // powerups active for 10 seconds
                    if (myTempValue==1)
                    {
                        paccy->SetState(1);
                    }
                    else
                    if (myTempValue==2)
                    {
                        paccy->SetState(2);
                    }
                    else
                    if (myTempValue==3)
                    {

                        paccy->SetState(3);
                    }
                    else
                    if (myTempValue==4)
                    {
                        paccy->SetState(4);
                    }
                    paccy->SetStateTimer(10000);

                    qDebug() << "werk2";
                }
                else
                {
                    // immediate powerups
                    if (myTempValue==5)
                    {
                        paccy->IncrementScorePellet(10000);
                    }
                    else
                    if (myTempValue==6)
                    {
                        paccy->IncrementScorePellet(-10000);
                    }
                    else
                    if (myTempValue==7)
                    {
                        for(int i = 0; i < monstersArray.size(); i++)
                        {
                            Monster *t = monstersArray[i];
                            t->SetPosition(9*WIDTH,9*WIDTH);
                            ChooseRandomDestination(t);
                        }
                    }
                }
                SendPacmanSync();
                powerup->SetEaten(true);
                this->removeItem(powerup->sprite);
                if(paccy->GetId() == local_pac->GetId())
                    local_player_score->setPlainText("Score: " + QString::number(paccy->GetScore()));
                //SendPowerUpSync(powerup);
                //Setpowerupsync kort
           }
        }

        // monster collision detection
        for(int i = 0; i < monstersArray.size(); i++)
        {
            Monster *manny = monstersArray[i];

            if(paccy->GetBoundingBox().intersects(manny->GetBoundingBox()))
            {

            if ( manny->GetState() == 3 )
            {
                manny->SetPosition(9*WIDTH,9*WIDTH);
                ChooseRandomDestination(manny);
                SendMonsterSync(manny);
            }
            else if (manny->GetState() == 4 )
            {
               //Do Nothing
            }
            else
            {
                emit GameOver(local_pac->GetScore());
                //LoseGame
             }
            }
            manny->Update(elapsed_seconds);


        }



    }



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

    connect(peerConnection,SIGNAL(OnSyncPacmanReceived(PacmanStruct)),this,SLOT(on_sync_pacman_received(PacmanStruct)));
    connect(peerConnection, SIGNAL(OnPelletSyncReceived(PelletStruct)), this, SLOT(on_sync_pellet_received(PelletStruct)));
    connect(peerConnection, SIGNAL(OnPowerUpReceived(PowerUpStruct)), this, SLOT(on_sync_powerup_received(PowerUpStruct)));
    connect(peerConnection, SIGNAL(OnMonsterSyncReceived(MonsterStruct)), this, SLOT(on_sync_monster_received(MonsterStruct)));
}

void PacGraphicsScene::SetPlayerAsHost()
{
    local_pac->SetId(1);
    remote_pac->SetId(2);

}

void PacGraphicsScene::SetPlayerAsClient()
{
    Pacman *tmp = local_pac;
    local_pac = remote_pac;
    remote_pac = tmp;

    local_pac->SetId(2);
    remote_pac->SetId(1);
}

void PacGraphicsScene::on_sync_pacman_received(PacmanStruct pac)
{
    qDebug() << "Sync Pacman Received" << pac.owner_ << pac.orientation << pac.x << pac.y;
   for(int i = 0; i < pacmen.size(); i++)
   {
       Pacman *paccy = pacmen[i];
        if(paccy->GetId() == pac.owner_)
        {

            paccy->Set_Orientation(pac.orientation);
            paccy->SetPosition(pac.x,pac.y);
            paccy->Update(0);
        }
   }
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


    qDebug () << "Loading map" << fileName + ".tmx";
    TiledMap m(fileName + ".tmx");
    m.LoadCollisionLayer(&pathingArr, W);
    tilesets = m.LoadTilesets();
    tile_data = m.LoadTiles();
    for(int i =0; i < tilesets.size(); i++)
    {
        Tileset *set = tilesets[i];
        set->Load();
    }
    qDebug() << "Test";

    for(int i =0; i < TILES_X-1; i++)
    {
        for(int j =0; j<TILES_Y-1; j++)
        {
            if(pathingArr[j*W+i].type==1)
            {

            }

            QGraphicsRectItem *item = new QGraphicsRectItem(i*WIDTH,j*WIDTH,WIDTH,WIDTH);

            int id = tile_data[j*W+i];
            Tileset *set = tilesets[0];
            QPixmap pix = QPixmap::fromImage(set->GetImage(id));

            const QColor transparent(0,0,0,0);
            QPen transPen(transparent);
            item->setPen(transPen); //Remove border from rect

            item->setBrush(QBrush(pix));  //Set brush to loaded image

            this->addItem(item);

        }
    }

   // this->addRect(startNode.x*WIDTH,startNode.y*WIDTH,WIDTH,WIDTH, QPen(), Qt::green);
  //  this->addRect(endNode.x*WIDTH,endNode.y*WIDTH,WIDTH,WIDTH, QPen(), Qt::red);

    //LoadPostMapItems();

}

const bool PacGraphicsScene::IsHost()
{
    return local_pac->GetId() == 1;
}

const bool PacGraphicsScene::IsConnected()
{
    if(!peerConnection)
        return false;
    if(peerConnection == NULL || peerConnection == nullptr)
        return false;
    return peerConnection->IsConnected();
}

void PacGraphicsScene::SendPelletSync(Pellet *p)
{
    if(!IsConnected())
        return;
    PelletStruct ps = p->GetPelletStruct();
    if(IsHost())
        peerConnection->Send(ps);
}

void PacGraphicsScene::SendPowerUpSync(PowerUp *p)
{
    if(!IsConnected())
        return;
    PowerUpStruct ps = p->GetPowerUpStruct();
    if(IsHost())
        peerConnection->Send(ps);
}

void PacGraphicsScene::SendPacmanSync(bool complete_sync)
{
    if(!IsConnected())
        return;
    if(!complete_sync)
    {
        if(peerConnection)
            peerConnection->Send(local_pac->GetPacmanStruct());
    }
    else
    {
        //Old method
        if(IsHost())
        {
            //Send all if host
            for(int i = 0; i < pacmen.size(); i++)
            {
                Pacman *pac = pacmen[i];
                PacmanStruct p = pac->GetPacmanStruct();
                if(peerConnection)
                    peerConnection->Send(p);
            }
        }
        else
        {
            //Only send the local player
            if(peerConnection)
                peerConnection->Send(local_pac->GetPacmanStruct());
        }
    }
}

void PacGraphicsScene::SendMonsterSync(Monster *m)
{
    if(!IsConnected())
        return;
    MonsterStruct ms = m->GetMonsterStruct();

    if(IsHost())
        peerConnection->Send(ms);
}

void PacGraphicsScene::on_sync_pellet_received(PelletStruct p)
{
    qDebug() << "sync_powerup rec";

    bool isFound = false;

    for(int i =0; i < pellets.size(); i++)
    {
        Pellet *pe = pellets[i];
        if(pe->GetId() == p.id)
        {
            isFound = true;
            break;
        }
    }

    if(!isFound)
    {
        Pellet *pel = new Pellet();
        pel->SetEaten(p.eaten);
        pel->SetId(p.id);
        pel->SetType(p.type);
        pel->SetPosition(p.x, p.y);
        pellets.push_back(pel);
        this->addItem(pel->sprite);
    }
}


void PacGraphicsScene::on_sync_powerup_received(PowerUpStruct p)
{
    qDebug() << "sync_powerup rec";

    bool isFound = false;

    for(int i =0; i < powerups.size(); i++)
    {
        PowerUp *pe = powerups[i];
        if(pe->GetId() == p.id)
        {
            isFound = true;
            break;
        }
    }

    if(!isFound)
    {
        PowerUp *pow = new PowerUp();
        pow->SetEaten(p.eaten);
        pow->SetId(p.id);
        pow->SetType(p.type);
        pow->SetPosition(p.x, p.y);
        powerups.push_back(pow);
        this->addItem(pow->sprite);
    }
}

void PacGraphicsScene::on_sync_monster_received(MonsterStruct m)
{
    for(int i = 0; i < monstersArray.size(); i++)
    {
        Monster *manny = monstersArray[i];
        if(m.id == manny->GetId())
        {
            manny->SetPosition(m.x, m.y);
            manny->Set_Orientation(m.orientation);
            manny->SetState(m.state);
            manny->SetStateTimer(m.state_timer);
            break;
        }
    }
}
