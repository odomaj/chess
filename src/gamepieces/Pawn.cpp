#include "Pawn.h"

Pawn_t::Pawn_t(char color_)
{
    color = color_;
    hasMoved = false;
}

char Pawn_t::getColor()
{
    return color;
}

char Pawn_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_PAWN;
    }
    return BLACK_PAWN;
}

std::list<Tile_t> Pawn_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Tile_t> tiles;
    Move_t move;
    int direction = 1;
    if(board.colors[currentTile.y][currentTile.x] == WHITE)
    {
        direction = -1;
    }
    move.start = currentTile;
    move.end = currentTile;

    move.end.y += direction;
    if(collision(move, board) == 0)
    {
        tiles.push_back(move.end);
    }

    move.end.x++;
    if(collision(move, board) == 0)
    {
        tiles.push_back(move.end);
    }

    move.end.x-=2;
    if(collision(move, board) == 0)
    {
        tiles.push_back(move.end);
    }

    if(!hasMoved)
    {
        move.end.y += direction;
        if(collision(move, board) == 0)
        {
            tiles.push_back(move.end);
        }

        move.end.x+= 2;
        if(collision(move, board) == 0)
        {
            tiles.push_back(move.end);
        }

        move.end.x-=2;
        if(collision(move, board) == 0)
        {
            tiles.push_back(move.end);
        }
    }
    return tiles; 
}

void Pawn_t::move(Tile_t tile)
{
    hasMoved = true;
}