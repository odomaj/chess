#include "Piece.h"

#ifndef PAWN_H_
#define PAWN_H_

class Pawn_t : public Piece_t
{
    public:
    Pawn_t(char color_);
    char getColor();
    char serialize();
    private:
    char color;
};

#endif