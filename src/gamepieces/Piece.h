#include "../common/Util.h"

#ifndef PIECE_H_
#define PIECE_H_

class Piece_t
{
    public:
    virtual char getColor() = 0;
    virtual char serialize() = 0;
};

#endif