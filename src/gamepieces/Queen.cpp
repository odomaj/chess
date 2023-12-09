#include "Queen.h"

Queen_t::Queen_t(char color_)
{
    color = color_;
}

char Queen_t::getColor()
{
    return color;
}

char Queen_t::serialize()
{
    if(color == WHITE)
    {
        return WHITE_QUEEN;
    }
    return BLACK_QUEEN;
}

std::list<Move_t> Queen_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
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

    move.end = currentTile;
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

void Queen_t::move(){}

bool Queen_t::hasMoved()
{
    return false;
}