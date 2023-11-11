#include "Piece.h"

#ifndef QUEEN_H_
#define QUEEN_H_

class Queen_t : public Piece_t
{
    public:
    Queen_t(char color_);
    char getColor();
    private:
    char color;
};

#endif