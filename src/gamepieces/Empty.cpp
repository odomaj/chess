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

std::list<Tile_t> Empty_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    
}

void Empty_t::move(Tile_t tile){}