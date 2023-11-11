#include "Piece.h"

#ifndef KNIGHT_H_
#define KNIGHT_H_

class Knight_t : public Piece_t
{
    public:
    Knight_t(char color_);
    char getColor();
    private:
    char color;
};

#endif