#ifndef TDGRAPHICSSCENE_H
#define TDGRAPHICSSCENE_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "QGraphicsSceneMouseEvent"
#include "QGraphicsTextItem"
#include "tile_node.h"
#include "constants.h"
#include "QKeyEvent"
#include "connection.h"
#include "playersyncstruct.h"
#include "tiledmap.h"
#include "pellet.h"
#include "powerup.h"
#include "monster.h"
#include "tile_node.h"
#include "pacman.h"
#include "powerupstruct.h"


enum GAME_PHASE{ATTACK = 0, BUILD=1};

class PacGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PacGraphicsScene(int, int, int, int, QGraphicsView*);
     ~PacGraphicsScene();

    //These events are overriden from the base class
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void keyPressEvent(QKeyEvent *e);

    void Update(float elapsed_seconds);

    void SetConnection(Connection *peerConn);
    void SetPlayerAsHost();
    void SetPlayerAsClient();
    void LoadMap(QString fileName);

    const bool IsHost();
    const bool IsConnected();

    void ChooseRandomDestination(Monster *t);
    void ChooseSpecificDestination(Monster *t);



private:
    Connection *peerConnection;


    //End Networking////////////////////////////////

    //These vectors keep track of the alive entities.
    //Used for updating the entities amongst other things
    std::vector<Pacman*> pacmen;
    std::vector<Monster*> monstersArray;
    std::vector<PowerUp*> powerups;
    std::vector<Pellet*> pellets;

    // the next direction the local pacman should go
    int next_orientation;

    // my pacman and your pacman
    Pacman *local_pac;
    Pacman *remote_pac;

    //pathfinding
    TileNode *pathingArr; //Matrix which is used to find path
    TileNode t_[TILES_X][TILES_Y];
    TileNode startNode;
    TileNode endNode;
    vector<Tileset*> tilesets;
    int *tile_data;


    int last_enemy_id;

    bool gameOver = false;

    //speedup
    bool newPath;
    std::vector<TileNode> path;

    QGraphicsTextItem *local_player_score;
    QGraphicsTextItem *local_player_powerup;

    void SendPlayerSync();
    void SendPacmanSync(bool complete_sync = false);
    void SendPelletSync(Pellet *p);
    void SendPowerUpSync(PowerUp *p);
    void SendMonsterSync(Monster *m);
    void SendMonsterSync();


signals:
    void GameOver(int score);


private slots:
    // trigger when data arrives from network connection
    void on_sync_pacman_received(PacmanStruct pac);
    void on_sync_pellet_received(PelletStruct pac);
    void on_sync_powerup_received(PowerUpStruct pac);
    void on_sync_monster_received(MonsterStruct mon);
    void on_sync_path_received(PathStruct p);

};

#endif // TDGRAPHICSSCENE_H
