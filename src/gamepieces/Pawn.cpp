#include "Pawn.h"

Pawn_t::Pawn_t(char color_)
{
    color = color_;
    hasMoved_ = false;
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

std::list<Move_t> Pawn_t::getMoves(Tile_t currentTile, const StaticBoard_t& board)
{
    std::list<Move_t> moves;
    Move_t move;
    int direction = 1;
    if(board.colors[currentTile.y][currentTile.x] == WHITE)
    {
        direction = -1;
    }
    move.start = currentTile;
    move.end = currentTile;
    move.piece = serialize();

    move.end.y += direction;
    if(collision(move, board) == NO_COLLISION)
    {
        moves.push_back(move);
    }

    move.end.x++;
    if(collision(move, board) == COLLISION_WITH_OPPONENT)
    {
        moves.push_back(move);
    }

    move.end.x-=2;
    if(collision(move, board) == COLLISION_WITH_OPPONENT)
    {
        moves.push_back(move);
    }

    if(!hasMoved_)
    {
        move.end.x++;
        move.end.y += direction;
        if(collision(move, board) == NO_COLLISION)
        {
            moves.push_back(move);
        }
    }
    return moves; 
}

void Pawn_t::move(Tile_t tile)
{
    hasMoved_ = true;
}

bool Pawn_t::hasMoved()
{
    return hasMoved_;
}