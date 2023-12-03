#include "Piece.h"

#ifndef BISHOP_H_
#define BISHOP_H_

class Bishop_t : public Piece_t
{
    public:
    Bishop_t(char color_);
    char getColor();
    char serialize();
    std::list<Tile_t> getMoves(Tile_t currentTile, const StaticBoard_t& board);
    void move(Tile_t tile);
    private:
    char color;
};

#endif