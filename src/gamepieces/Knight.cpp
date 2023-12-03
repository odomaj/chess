#include "Knight.h"

Knight_t::Knight_t(char color_)
{
    color = color_;
}

char Knight_t::getColor()
{
    return color;
}

char Knight_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_KNIGHT;
    }
    return BLACK_KNIGHT;
}

std::list<Tile_t> Knight_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    
}

void Knight_t::move(Tile_t tile){}