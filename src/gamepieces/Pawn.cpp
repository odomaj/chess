#include "Pawn.h"

Pawn_t::Pawn_t(char color_)
{
    color = color_;
}

char Pawn_t::getColor()
{
    return color;
}