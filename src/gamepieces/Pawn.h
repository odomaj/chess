#include "Piece.h"

#ifndef PAWN_H_
#define PAWN_H_

class Pawn_t : public Piece_t
{
    public:
    Pawn_t(char color_);
    char getColor();
    char serialize();
    std::list<Tile_t> getMoves(Tile_t currentTile, const StaticBoard_t& board);
    void move(Tile_t tile);
    private:
    char color;
    bool hasMoved;
};

#endif