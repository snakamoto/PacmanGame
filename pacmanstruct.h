#ifndef PACMANSTRUCT_H
#define PACMANSTRUCT_H

struct PacmanStruct
{
public:
    PacmanStruct(){}

    int owner_; //owner of the tower
    int orientation;
    int state;
    int x; //x position
    int y; //y position

};

#endif
