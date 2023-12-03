#include "Piece.h"

#ifndef EMPTY_H_
#define EMPTY_H_

class Empty_t : public Piece_t
{
    public:
    Empty_t();
    char getColor();
    char serialize();
    std::list<Tile_t> getMoves(Tile_t currentTile, const StaticBoard_t& board);
    void move(Tile_t tile);
    private:
    char color;
};

#endif