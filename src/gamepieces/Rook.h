#include "Piece.h"

#ifndef ROOK_H_
#define ROOK_H_

class Rook_t : public Piece_t
{
    public:
    Rook_t(char color_);
    char getColor();
    private:
    char color;
};

#endif