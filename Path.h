#pragma once
#include <vector>
#include "tile_node.h"
#include "QPointF"
using namespace std;

class Path
{

    //This class is used to construct the necessary points to follow when following a path
public:
    Path(vector<TileNode> nodes);
    Path();
    ~Path();

    const vector<QPointF> GetPoints();
    const vector<float> GetLengths();
    const vector<QPointF> GetDirections();

private:
    vector<QPointF> points;
    vector<float> lengths;
    vector<QPointF> directions;

    //See this function's code to see what this class is really about
    void Build();
};

