 #ifndef TILEDMAP_H
#define TILEDMAP_H
#include "tile_node.h"
#include "QString"
#include "tileset.h"

class TiledMap
{
public:
    TiledMap();
    TiledMap(QString fileName);
    void LoadCollisionLayer(TileNode **grid, int TILES_X);
    vector<Tileset> LoadTilesets();
private:
    QString filename;
};

#endif // TILEDMAP_H
