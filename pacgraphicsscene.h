#ifndef TDGRAPHICSSCENE_H
#define TDGRAPHICSSCENE_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "QGraphicsSceneMouseEvent"
#include "QGraphicsTextItem"
#include "tile_node.h"
#include "constants.h"
#include "QKeyEvent"
#include "enemy.h"
#include "connection.h"
#include "playersyncstruct.h"
#include "enemystruct.h"
#include "removeenemystruct.h"
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

private:
    Connection *peerConnection;


    //End Networking////////////////////////////////

    //These vectors keep track of the alive entities.
    //Used for updating the entities amongst other things
    std::vector<Pacman*> pacmen;
    std::vector<Enemy*> enemies;
    std::vector<Monster*> monstersArray;

    std::vector<PowerUp*> powerups;
    std::vector<Pellet*> pellets;

    int next_orientation;
    Pacman *local_pac;
    Pacman *remote_pac;



    //pathfinding
    TileNode *pathingArr; //Matrix which is used to find path
    TileNode t_[TILES_X][TILES_Y];
    TileNode startNode;
    TileNode endNode;
    vector<Tileset*> tilesets;
    int *tile_data;


    //This path gets visually displayed for testing purposes
    //It displays the path obtained from startNode to endNode about the obstacles
    std::vector<QGraphicsItem*> testPath;


    Enemy* spawn_enemy(int x, int y);


    int last_enemy_id;

    //speedup
    bool newPath;
    std::vector<TileNode> path;

    QGraphicsRectItem *backgroundRect;
    QGraphicsTextItem *local_player_score;

    void GeneratePath();
    void SendPlayerSync();
    void SendPacmanSync(bool complete_sync = false);
    void SendPelletSync(Pellet *p);
    void SendPowerUpSync(PowerUp *p);


signals:
    void GameOver(int kills);

private slots:
    //Networking
    void on_new_enemy_received(EnemyStruct e);
    void on_new_psync_recieved(PlayerSyncStruct s);
    void on_remove_enemy_recieved(RemoveEnemyStruct en);
    void on_sync_pacman_received(PacmanStruct pac);
    void on_sync_pellet_received(PelletStruct pac);
    void on_sync_powerup_received(PowerUpStruct pac);

};

#endif // TDGRAPHICSSCENE_H
