#include "Empty.h"

Empty_t::Empty_t()
{
     
}

char Empty_t::getColor()
{
    return EMPTY;
}

char Empty_t::serialize()
{
    return EMPTY;
}

std::list<Move_t> Empty_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    return std::list<Move_t>();
}

void Empty_t::move(){}

bool Empty_t::hasMoved()
{
    return false;
}