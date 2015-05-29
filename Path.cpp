#include "Path.h"
#include <cmath>
#include "constants.h"

Path::Path(vector<TileNode> nodes)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		TileNode n = nodes[i];
        QPointF vec(n.x * WIDTH, n.y * WIDTH);//Convert from pathing coords to scene coords
		points.push_back(vec);
	}
	Build();
}

Path::Path()
{
}


Path::~Path()
{
}

void Path::Build()
{
	if (points.size() == 0)
        return; //No path

	for (int i = 0; i < points.size() - 1; i++)
	{
        //Direction current point to next point
        QPointF direction = points[i + 1] - points[i];

        //Obtain length of each point and store in vector
        float length = sqrt(direction.x() *direction.x() +
            direction.y() * direction.y());
        lengths.push_back(length); //Store

        //Normalize directions and store
        direction.setX(direction.x() / length);
        direction.setY(direction.y() / length);
		directions.push_back(direction);		
	}
}

const vector<QPointF> Path::GetPoints()
{
	return points;
}
const vector<float> Path::GetLengths()
{
	return lengths;
}
const vector<QPointF> Path::GetDirections()
{
	return directions;
}
