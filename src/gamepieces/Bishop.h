#include "Piece.h"

#ifndef BISHOP_H_
#define BISHOP_H_

class Bishop_t : public Piece_t
{
    public:
    Bishop_t(char color_);
    char getColor();
    char serialize();
    private:
    char color;
};

#endif