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
#include "astar.h"

enum GAME_PHASE{ATTACK = 0, BUILD=1};

class PacGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PacGraphicsScene(int, int, int, int, QGraphicsView*);

    //These events are overriden from the base class
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void keyPressEvent(QKeyEvent *);
    void Update(float );
    void SetConnection(Connection *);
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
    int next_orientation;
    Pacman *local_pac;
    Pacman *remote_pac;

    //pathfinding
    TileNode *pathingArr; //Matrix which is used to find path
    TileNode t_[TILES_X][TILES_Y];
    TileNode startNode;
    TileNode endNode;


    //This path gets visually displayed for testing purposes
    //It displays the path obtained from startNode to endNode about the obstacles
    std::vector<QGraphicsItem*> testPath;
    Enemy* spawn_enemy(int x, int y);
    int last_enemy_id;

    //speedup
    bool newPath;
    std::vector<TileNode> path;
    QGraphicsRectItem *backgroundRect;

    void GeneratePath();
    void SendPlayerSync();
    void SendPacmanSync();

    // this is used to remove enemy when path is found
    int m_updates;


signals:
    void GameOver(int kills);

private slots:
    //Networking
    void on_new_enemy_received(EnemyStruct e);
    void on_new_psync_recieved(PlayerSyncStruct s);
    void on_remove_enemy_recieved(RemoveEnemyStruct en);
    void on_sync_pacman_received(PacmanStruct pac);

};

#endif // TDGRAPHICSSCENE_H
