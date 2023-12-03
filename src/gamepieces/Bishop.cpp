#include "Bishop.h"

Bishop_t::Bishop_t(char color_)
{
    color = color_;
}

char Bishop_t::getColor()
{
    return color;
}

char Bishop_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_BISHOP;
    }
    return BLACK_BISHOP;
}

std::list<Tile_t> Bishop_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Tile_t> tiles;
    Move_t move;
    
    move.start = currentTile;
    move.end = currentTile;
    while(true)
    {
        move.end.x++;
        move.end.y++;
        int collision_ = collision(move, board);
        if(collision_ == 0)
        {
            break;
        }
        tiles.push_back(move.end);
        if(collision_ == 1)
        {
            break;
        }
    }

    move.end = currentTile;
    while(true)
    {
        move.end.x++;
        move.end.y--;
        int collision_ = collision(move, board);
        if(collision_ == 0)
        {
            break;
        }
        tiles.push_back(move.end);
        if(collision_ == 1)
        {
            break;
        }
    }

    move.end = currentTile;
    while(true)
    {
        move.end.x--;
        move.end.y++;
        int collision_ = collision(move, board);
        if(collision_ == 0)
        {
            break;
        }
        tiles.push_back(move.end);
        if(collision_ == 1)
        {
            break;
        }
    }

    move.end = currentTile;
    while(true)
    {
        move.end.x--;
        move.end.y--;
        int collision_ = collision(move, board);
        if(collision_ == 0)
        {
            break;
        }
        tiles.push_back(move.end);
        if(collision_ == 1)
        {
            break;
        }
    }

    return tiles;
}

void Bishop_t::move(Tile_t tile){}