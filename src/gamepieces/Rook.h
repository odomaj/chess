#include "Piece.h"

#ifndef ROOK_H_
#define ROOK_H_

class Rook_t : public Piece_t
{
    public:
    Rook_t(char color_);
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