#include "Pawn.h"

Pawn_t::Pawn_t(char color_)
{
    color = color_;
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