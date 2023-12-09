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

std::list<Move_t> Knight_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Move_t> moves;
    Move_t move;

    move.start = currentTile;
    move.end = currentTile;
    move.piece = serialize();

    move.end.x += 2;
    move.end.y++;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }
    
    move.end.y -= 2;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.end = currentTile;
    move.end.x -= 2;
    move.end.y++;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }
    
    move.end.y -= 2;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y += 2;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }
    
    move.end.x -= 2;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y-=2;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }
    
    move.end.x -= 2;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    return moves;
}

void Knight_t::move(){}

bool Knight_t::hasMoved()
{
    return false;
}