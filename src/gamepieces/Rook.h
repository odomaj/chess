#include "Piece.h"

#ifndef ROOK_H_
#define ROOK_H_

class Rook_t : public Piece_t
{
    public:
    Rook_t(char color_);
    char getColor();
    char serialize();
    std::list<Tile_t> getMoves(Tile_t currentTile, const StaticBoard_t& board);
    void move(Tile_t tile);
    private:
    char color;
    bool hasMoved;
};

#endif