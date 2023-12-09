#include "Heuristic.h"

#include <iostream>

Heuristic::Heuristic()
{

}

Heuristic::~Heuristic()
{

}

int32_t Heuristic::heuristic(const StaticBoard_t& staticBoard, Move_t move, char player)
{
    GameBoard_t board = GameBoard_t(staticBoard);
    if(!board.move(move, player))
    {
        std::cout << "Problem with heuristic with the following move\n";
        std::cout << '(' << move.start.x << ", " << move.start.y << ") to (" << move.end.x << ", " << move.end.y << "): " << player << "\n";
    }

    std::list<Move_t> moves = board.getLegalMoves(player);

    int32_t score = moves.size() >> 4;

    char opponent = WHITE;
    if(player == WHITE)
    {
        opponent = BLACK;
    }

    if(board.isInCheck(opponent))
    {
        score += CHECK;
    }

    switch(staticBoard.pieces[move.end.y][move.end.x])
    {
        case WHITE_PAWN:
            score += CAPTURE_PAWN;
            break;
        case BLACK_PAWN:
            score += CAPTURE_PAWN;
            break;
        case WHITE_KNIGHT:
            score += CAPTURE_KNIGHT;
            break;
        case BLACK_KNIGHT:
            score += CAPTURE_KNIGHT;
            break;
        case WHITE_ROOK:
            score += CAPTURE_ROOK;
            break;
        case BLACK_ROOK:
            score += CAPTURE_ROOK;
            break;
        case WHITE_BISHOP:
            score += CAPTURE_BISHOP;
            break;
        case BLACK_BISHOP:
            score += CAPTURE_BISHOP;
            break;
        case WHITE_QUEEN:
            score += CAPTURE_QUEEN;
            break;
        case BLACK_QUEEN:
            score += CAPTURE_QUEEN;
            break;
        default:
            break;
    }
    
    //std::cout << '(' << move.start.x << ", " << move.start.y << ") to (" << move.end.x << ", " << move.end.y << "): " << score << '\n';

    return score;
}
