#include "Queen.h"

Queen_t::Queen_t(char color_)
{
    color = color_;
}

char Queen_t::getColor()
{
    return color;
}

char Queen_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_QUEEN;
    }
    return BLACK_QUEEN;
}

std::list<Tile_t> Queen_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    
}

void Queen_t::move(Tile_t tile){}