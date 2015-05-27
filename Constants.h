#ifndef CONSTANTS_H
#define CONSTANTS_H

//Some constants used everywhere

//Amount of horizontal tiles
const int TILES_X = 48;
//Amount of vertical tiles
const int TILES_Y = 32;
//Size per tile
const int WIDTH=32;

//Due to me being inconsistent and lazy these are the same and used interchangable and inconsistently
const int W = TILES_X;
const int H = TILES_Y;

//Size of map in pixels
const int MAP_WIDTH=TILES_X*WIDTH;
const int MAP_HEIGHT=TILES_Y*WIDTH;


#endif // CONSTANTS_H

