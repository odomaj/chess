#include "Piece.h"

#ifndef KNIGHT_H_
#define KNIGHT_H_

class Knight_t : public Piece_t
{
    public:
    Knight_t(char color_);
    char getColor();
    char serialize();
    std::list<Tile_t> getMoves(Tile_t currentTile, const StaticBoard_t& board);
    void move(Tile_t tile);
    private:
    char color;
};

#endif