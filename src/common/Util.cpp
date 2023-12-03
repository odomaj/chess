#include "Util.h"

int collision(const Move_t& move, const StaticBoard_t& board)
{
    char color;
    switch (move.piece)
    {
    case 'p':
        color = WHITE;
        break;
    case 'r':
        color = WHITE;
        break;
    case 'n':
        color = WHITE;
        break;
    case 'b':
        color = WHITE;
        break;
    case 'q':
        color = WHITE;
        break;
    case 'k':
        color = WHITE;
        break;
    case 'P':
        color = BLACK;
        break;
    case 'R':
        color = BLACK;
        break;
    case 'N':
        color = BLACK;
        break;
    case 'B':
        color = BLACK;
        break;
    case 'Q':
        color = BLACK;
        break;
    case 'K':
        color = BLACK;
        break;
    default:
        color = EMPTY;
        break;
    }

    if(board.colors[move.end.y][move.end.x] == EMPTY)
    {
        return 2;
    }

    if(board.colors[move.end.y][move.end.x] == color)
    {
        return 0;
    }

    return 1;
}