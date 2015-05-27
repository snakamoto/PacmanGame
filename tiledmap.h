#ifndef TILEDMAP_H
#define TILEDMAP_H
#include "tile_node.h"
#include "QString"
class TiledMap
{
public:
    TiledMap();
    TiledMap(QString fileName);
    void LoadCollisionLayer(TileNode **grid, int TILES_X);
private:
    QString filename;
};

#endif // TILEDMAP_H
