#include "Piece.h"

#ifndef QUEEN_H_
#define QUEEN_H_

class Queen_t : public Piece_t
{
    public:
    Queen_t(char color_);
    char getColor();
    char serialize();
    std::list<Tile_t> getMoves(Tile_t currentTile, const StaticBoard_t& board);
    void move(Tile_t tile);
    private:
    char color;
};

#endif