#include "Piece.h"

#ifndef KING_H_
#define KING_H_

class King_t : public Piece_t
{
    public:
    King_t(char color_);
    char getColor();
    char serialize();
    std::list<Move_t> getMoves(Tile_t currentTile, const StaticBoard_t& board);
    void move();
    bool hasMoved();
    private:
    char color;
    bool hasMoved_;
};

#endif