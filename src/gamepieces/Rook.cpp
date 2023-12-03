#include "Rook.h"

Rook_t::Rook_t(char color_)
{
    color = color_;
}

char Rook_t::getColor()
{
    return color;
}

char Rook_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_ROOK;
    }
    return BLACK_ROOK;
}

std::list<Tile_t> Rook_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    
}

void Rook_t::move(Tile_t tile)
{
    hasMoved = true;
}