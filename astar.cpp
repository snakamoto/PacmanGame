#include "astar.h"
#include <algorithm>

using namespace std;

AStar::AStar(int x_size, int y_size,TileNode **g)
{
    grid=g;
    this->grid_nx = x_size;
    this->grid_ny = y_size;

}

std::vector<TileNode*> AStar::GetNeighbours(TileNode &node)
{
    // this is a tiled based approach to path finding max 8 neighbors ideally
    vector<TileNode*> ret = vector<TileNode*>();

    TileNode *g;
    g = *grid;

    int x = node.x;
    int y = node.y;

    const int W = grid_nx;
    const int H = grid_ny;

    // let neigbors be only one of 4 positions
    TileNode *right = &g[W * (y) + (x+1)];
    TileNode *left = &g[W * (y) + (x-1)];
    TileNode *top = &g[W * (y-1) + (x)];
    TileNode *bottom = &g[W * (y+1) + (x)];

    // push correct neighbor in vector list
    if(x>0)
        ret.push_back(right);
    if(x<W-1)
        ret.push_back(left);
    if(y>0)
        ret.push_back(top);
    if(y<H-1)
        ret.push_back(bottom);



    return ret;
}

vector<TileNode> AStar::Search(TileNode &start, TileNode &end)
{
    vector<TileNode*> openList = vector<TileNode*>();
    vector<TileNode*> closedList = vector<TileNode*>();
    openList.push_back(&start);

    vector<TileNode> ret = vector<TileNode>();

    while(openList.size() > 0)
    {
        int i_lowf = 0; // index of best f-score
        for(int i =0; i < openList.size(); i++)
        {
            if (openList.at(i)->f() < openList.at(i_lowf)->f())
            {
                i_lowf = i;
            }
        }

        TileNode *currentNode = openList.at(i_lowf);

        // is current node the same as the end node
        // if so then we are done
        if(currentNode->x == end.x && currentNode->y==end.y)
        {
            TileNode *curr = currentNode;
            while(curr->parent)
            {
                ret.push_back(*curr);
                curr = curr->parent;
            }

            //TODO:
            //Reverse ret;

            reverse(ret.begin(),ret.end());
            return ret;
        }

        //Normal case
        //Continue minions
        openList.erase(openList.begin() + i_lowf);
        closedList.push_back(currentNode);

        vector<TileNode*> neighbors = GetNeighbours(*currentNode);


        for (int i = 0; i < neighbors.size(); i++)
        {
            TileNode *neighbor = neighbors.at(i);

            // is neighbor in closedList
            bool neighbor_in_closedList = AStar::FindGraphNode(closedList, *neighbor);

            // skip already-checked nodes and walls
            if (neighbor_in_closedList || neighbor->type == TileNode::WALL || neighbor->x ==0 || neighbor->y==0 ||neighbor->x ==grid_nx-1 ||neighbor->y==grid_ny-1)
                continue;

            int g = currentNode->g + 1;

            bool best_g = false;
            if (!FindGraphNode(openList, *neighbor))
            {
                best_g = true;
                neighbor->h = ManhattanHeuristic(*neighbor, end);
                openList.push_back(neighbor);

            }
            else if (g < neighbor->g)
            {
                best_g = true;

            }
            if (best_g)
            {

                neighbor->parent = currentNode;
                neighbor->g = g;
            }



        }

    }
    return ret;
}



bool AStar::FindGraphNode(vector<TileNode*> node_list, TileNode &node)
{
    for(int k = 0; k < node_list.size(); k++ )
    {
        TileNode* curs_node = node_list.at(k);
        if(curs_node->x == node.x && curs_node->y == node.y)
        {
            return true;
        }
    }
    return false;
}

float AStar::ManhattanHeuristic(TileNode a, TileNode b)
{
    const int D = 1;
    int dx = abs(a.x - b.x);
    int dy = abs(a.y - b.y);
    return D * (dx+dy);
}

