#include "King.h"

King_t::King_t(char color_)
{
    color = color_;
}

char King_t::getColor()
{
    return color;
}

char King_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_KING;
    }
    return BLACK_KING;
}

std::list<Tile_t> King_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Tile_t> tiles;
    Move_t move;
    
    move.start = currentTile;
    move.end = currentTile;
    move.end.x++;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y++;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y--;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.x--;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.x--;
    move.end.y++;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.x--;
    move.end.y--;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.y++;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.y--;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    return tiles;
}

void King_t::move(Tile_t tile)
{
    hasMoved = true;
}