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

std::list<Move_t> King_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Move_t> moves;
    Move_t move;
    
    move.start = currentTile;
    move.end = currentTile;
    move.piece = serialize();
    move.end.x++;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y++;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.end = currentTile;
    move.end.x++;
    move.end.y--;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.x--;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.x--;
    move.end.y++;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.x--;
    move.end.y--;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.y++;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    move.start = currentTile;
    move.end = currentTile;
    move.end.y--;
    if(collision(move, board) != COLLISION_WITH_TEAM)
    {
        moves.push_back(move);
    }

    return moves;
}

void King_t::move(Tile_t tile)
{
    hasMoved_ = true;
}

bool King_t::hasMoved()
{
    return hasMoved_;
}