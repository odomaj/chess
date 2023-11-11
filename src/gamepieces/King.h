#include "Piece.h"

#ifndef KING_H_
#define KING_H_

class King_t : public Piece_t
{
    public:
    King_t(char color_);
    char getColor();
    private:
    char color;
};

#endif