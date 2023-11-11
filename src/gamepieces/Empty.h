#include "Piece.h"

#ifndef EMPTY_H_
#define EMPTY_H_

class Empty_t : public Piece_t
{
    public:
    Empty_t();
    char getColor();
    private:
    char color;
};

#endif