#include "pacman.h"

Pacman::Pacman()
{

}

Pacman::~Pacman()
{

}

const int Pacman::GetScore()
{
    return food_collected + 10*kills;
}
