#include "King.h"

King_t::King_t(char color_)
{
    color = color_;
}

char King_t::getColor()
{
    return color;
}

char King_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_KING;
    }
    return BLACK_KING;
}