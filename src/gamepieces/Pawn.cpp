#include "Pawn.h"

Pawn_t::Pawn_t(char color_)
{
    color = color_;
    hasMoved = false;
}

char Pawn_t::getColor()
{
    return color;
}

char Pawn_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_PAWN;
    }
    return BLACK_PAWN;
}

std::list<Tile_t> Pawn_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    
}

void Pawn_t::move(Tile_t tile)
{
    hasMoved = true;
}