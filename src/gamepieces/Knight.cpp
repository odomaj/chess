#include "Knight.h"

Knight_t::Knight_t(char color_)
{
    color = color_;
}

char Knight_t::getColor()
{
    return color;
}

char Knight_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_KNIGHT;
    }
    return BLACK_KNIGHT;
}

std::list<Tile_t> Knight_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Tile_t> tiles;
    Move_t move;

    move.start = currentTile;
    move.end = currentTile;

    move.end.x += 2;
    move.end.y++;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }
    
    move.end.y -= 2;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.end = currentTile;
    move.end.x -= 2;
    move.end.y++;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }
    
    move.end.y -= 2;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y += 2;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }
    
    move.end.x -= 2;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y+=2;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }
    
    move.end.x -= 2;
    if(collision(move, board) != 0)
    {
        tiles.push_back(move.end);
    }

    return tiles;
}

void Knight_t::move(Tile_t tile){}