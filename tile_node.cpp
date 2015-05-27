#include "tile_node.h"

TileNode::TileNode()
{
    x=y=g=h=0;
    parent = nullptr;
}

TileNode::TileNode(int px, int py, TileNode *parentNode)
{
    x=px;
    y=py;
    parent = parentNode;
    g=h=0;
}


const int TileNode::f()
{
   return g+h;
}

