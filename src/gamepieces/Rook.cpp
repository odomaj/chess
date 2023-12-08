#include "Rook.h"
#include <iostream>
Rook_t::Rook_t(char color_)
{
    color = color_;
    hasMoved_ = false;
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

std::list<Move_t> Rook_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Move_t> moves;
    Move_t move;
    
    move.start = currentTile;
    move.end = currentTile;
    move.piece = serialize();
    while(true)
    {
        move.end.x++;
        char collision_ = collision(move, board);
        if(collision_ == COLLISION_WITH_TEAM)
        {
            break;
        }
        moves.push_back(move);
        if(collision_ == COLLISION_WITH_OPPONENT)
        {
            break;
        }
    }

    move.end = currentTile;
    while(true)
    {
        move.end.x--;
        char collision_ = collision(move, board);
        if(collision_ == COLLISION_WITH_TEAM)
        {
            break;
        }
        moves.push_back(move);
        if(collision_ == COLLISION_WITH_OPPONENT)
        {
            break;
        }
    }

    move.end = currentTile;
    while(true)
    {
        move.end.y++;
        char collision_ = collision(move, board);
        if(collision_ == COLLISION_WITH_TEAM)
        {
            break;
        }
        moves.push_back(move);
        if(collision_ == COLLISION_WITH_OPPONENT)
        {
            break;
        }
    }

    move.end = currentTile;
    while(true)
    {
        move.end.y--;
        char collision_ = collision(move, board);
        if(collision_ == COLLISION_WITH_TEAM)
        {
            break;
        }
        moves.push_back(move);
        if(collision_ == COLLISION_WITH_OPPONENT)
        {
            break;
        }
    }

    return moves;
}

void Rook_t::move(Tile_t tile)
{
    hasMoved_ = true;
}

bool Rook_t::hasMoved()
{
    return hasMoved_;
}