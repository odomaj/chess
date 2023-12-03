#include "Rook.h"

Rook_t::Rook_t(char color_)
{
    color = color_;
}

char Rook_t::getColor()
{
    return color;
}

char Rook_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_ROOK;
    }
    return BLACK_ROOK;
}

std::list<Tile_t> Rook_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Tile_t> tiles;
    Move_t move;
    
    move.start = currentTile;
    move.end = currentTile;
    while(true)
    {
        move.end.x++;
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

void Rook_t::move(Tile_t tile)
{
    hasMoved = true;
}