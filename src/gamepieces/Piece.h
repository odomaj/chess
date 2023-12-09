#include "../common/Util.h"

#include <list>

#ifndef PIECE_H_
#define PIECE_H_

class Piece_t
{
    public:
    virtual char getColor() = 0;
    virtual char serialize() = 0;
    virtual std::list<Move_t> getMoves(Tile_t currentTile, const StaticBoard_t& board) = 0;
    virtual void move() = 0;
    virtual bool hasMoved() = 0;
};

#endif