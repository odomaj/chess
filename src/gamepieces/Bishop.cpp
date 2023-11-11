#include "Bishop.h"

Bishop_t::Bishop_t(char color_)
{
    color = color_;
}

char Bishop_t::getColor()
{
    return color;
}

char Bishop_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_BISHOP;
    }
    return BLACK_BISHOP;
}