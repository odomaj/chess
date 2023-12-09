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

std::list<Move_t> Bishop_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Move_t> moves;
    Move_t move;
    
    move.start = currentTile;
    move.end = currentTile;
    move.piece = serialize();
    while(true)
    {
        move.end.x++;
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
        move.end.x++;
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

    move.end = currentTile;
    while(true)
    {
        move.end.x--;
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
        move.end.x--;
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

void Bishop_t::move(){}

bool Bishop_t::hasMoved()
{
    return false;
}