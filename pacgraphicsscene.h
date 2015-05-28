#ifndef TDGRAPHICSSCENE_H
#define TDGRAPHICSSCENE_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "QGraphicsSceneMouseEvent"
#include "QGraphicsTextItem"
#include "tile_node.h"
#include "Constants.h"
#include "QKeyEvent"
#include "enemy.h"
#include "connection.h"
#include "playersyncstruct.h"
#include "enemystruct.h"
#include "removeenemystruct.h"
#include "tiledmap.h"
#include "pacman.h"


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

private:

    //Networking//////////////////////////////////////
    int localPlayerId;
    int remotePlayerId;

    Connection *peerConnection;


    //End Networking////////////////////////////////

    //These vectors keep track of the alive entities.
    //Used for updating the entities amongst other things
    std::vector<Pacman*> pacmen;
    std::vector<Enemy*> enemies;

    int next_orientation;
    Pacman *local_pac;

    //Just some text
    QGraphicsTextItem *p1_goldText;
    QGraphicsTextItem *p2_goldText;
    QGraphicsTextItem *p1_killsText;
    QGraphicsTextItem *p2_killsText;
    QGraphicsTextItem *phaseText;
    QGraphicsTextItem *livesText;



    //pathfinding
    TileNode *pathingArr; //Matrix which is used to find path
    TileNode t_[TILES_X][TILES_Y];
    TileNode startNode;
    TileNode endNode;
    void GeneratePath();

    //This path gets visually displayed for testing purposes
    //It displays the path obtained from startNode to endNode about the obstacles
    std::vector<QGraphicsItem*> testPath;

    void SetGold(int playerId, const int amount = 10);
    void SetKills(int playerId, const int amount=1);
    Enemy* spawn_enemy(int x, int y);
    void SendPlayerSync();

    int last_enemy_id;

    //speedup
    bool newPath;
    std::vector<TileNode> path;

    QGraphicsRectItem *backgroundRect;



signals:
    void GameOver(int kills);

private slots:
    //Networking
    void on_new_enemy_received(EnemyStruct e);
    void on_new_psync_recieved(PlayerSyncStruct s);
    void on_remove_enemy_recieved(RemoveEnemyStruct en);

};

#endif // TDGRAPHICSSCENE_H
