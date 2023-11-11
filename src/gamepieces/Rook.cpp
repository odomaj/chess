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