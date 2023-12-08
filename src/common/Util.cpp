#include "Util.h"

char collision(const Move_t& move, const StaticBoard_t& board)
{
    if(move.end.x > 7 || move.end.x < 0 || move.end.y > 7 || move.end.y < 0)
    {
        return COLLISION_WITH_TEAM;
    }
    
    char color;
    switch (move.piece)
    {
    case WHITE_PAWN:
        color = WHITE;
        break;
    case WHITE_ROOK:
        color = WHITE;
        break;
    case WHITE_KNIGHT:
        color = WHITE;
        break;
    case WHITE_BISHOP:
        color = WHITE;
        break;
    case WHITE_QUEEN:
        color = WHITE;
        break;
    case WHITE_KING:
        color = WHITE;
        break;
    case BLACK_PAWN:
        color = BLACK;
        break;
    case BLACK_ROOK:
        color = BLACK;
        break;
    case BLACK_KNIGHT:
        color = BLACK;
        break;
    case BLACK_BISHOP:
        color = BLACK;
        break;
    case BLACK_QUEEN:
        color = BLACK;
        break;
    case BLACK_KING:
        color = BLACK;
        break;
    default:
        color = EMPTY;
        break;
    }

    if(board.colors[move.end.y][move.end.x] == EMPTY)
    {
        return NO_COLLISION;
    }

    if(board.colors[move.end.y][move.end.x] == color)
    {
        return COLLISION_WITH_TEAM;
    }

    return COLLISION_WITH_OPPONENT;
}

bool operator==(const Tile_t& tile1, const Tile_t& tile2)
{
    return tile1.x == tile2.x && tile1.y == tile2.y;
}

bool operator==(const Move_t& move1, const Move_t& move2)
{
    return move1.start == move2.start && move1.end == move2.end;
}