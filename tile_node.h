#ifndef TILE_H
#define TILE_H

#include <string.h>

class TileNode
{
public:
    TileNode();
    TileNode(int px, int py, TileNode *parentNode);
    float g;
    float h;
    int x;
    int y;

    //WHY NOT ENUM THIS??!?
    static const int FREE_PATH = 0;
    static const int WALL = 1;
    static const int START = 5;
    static const int END = 6;

    int type;

    TileNode *parent;

    const int f();

};

#endif // TILE_H
