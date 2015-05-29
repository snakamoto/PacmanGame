 #ifndef TILEDMAP_H
#define TILEDMAP_H
#include "tile_node.h"
#include "QString"
#include "tileset.h"
#include "Constants.h"

class TiledMap
{
public:
    TiledMap();
    TiledMap(QString fileName);
    void LoadCollisionLayer(TileNode **grid, int TILES_X);
    vector<Tileset> LoadTilesets();
    int* LoadTiles();
private:
    QString filename;
};

#endif // TILEDMAP_H
