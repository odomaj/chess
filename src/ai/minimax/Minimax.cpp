#include "Minimax.h"

#include <iostream>

Move_t Minimax::getMove(const StaticBoard_t& board, char color)
{
    player = color;
    alpha = INT32_MIN;
    beta = INT32_MAX;
    State_t state;
    state.board = board;
    state.score = 0;
    state.player = color;
    state.move.start.x = -1;
    state.move.start.y = -1;
    state.move.end.x = -1;
    state.move.end.y = -1;
    return minimax(state, 1).move;
}

/*
    calculate the heuristic for the given move on the given move (if not first call)
    if the search depth has been exceeded, return the value of the heuristic and the move (if not first call)
    otherwise update the board with the given move (if not first call)
    find all possible moves for the updated board
    call minimax on the new board with every possible move
    sum the optimum resulting minimax with the already calculated heuristic
    return that sum and the move that was passed to this function
*/
State_t Minimax::minimax(const State_t& state, int16_t depth)
{
    GameBoard_t board = GameBoard_t(state.board);

    State_t nextState;
    nextState.score = 0;

    if(state.move.start.x != -1 || state.move.start.y != -1 || state.move.end.x != -1 || state.move.end.y != -1)
    {
        if(depth++ > MAX_SEARCH_DEPTH)
        {
            nextState.score = heuristic.heuristic(board, state.move, state.player);
            return nextState;
        }

        if(!board.move(state.move, state.player))
        {
            std::cout << "bad\n";
            return nextState;
        }
    }

    std::list<Move_t> moves = board.getLegalMoves(state.player);
    if(moves.empty())
    {
        nextState.board = state.board;
        nextState.player = CHECKMATE;
        if(player == state.player)
        {
            nextState.player == GET_CHECKMATE;
        }
        return nextState;
    }

    nextState.player = WHITE;
    if(state.player == WHITE)
    {
        nextState.player = BLACK;
    }
    nextState.board = board.getBoard();

    State_t bestState;
    bestState.board = state.board;
    bestState.player = state.player;
    bestState.move = state.move;
    bestState.score = nextState.score;

    auto it = moves.begin();
    nextState.move = *it;
    bestState.score += minimax(nextState, depth).score;
    while(++it != moves.end())
    {
        nextState.move = *it;
        State_t newState = minimax(nextState, depth);
        if(nextState.player == player)
        {
            if(nextState.score > bestState.score)
            {
                bestState.score = nextState.score;
            }
        }
        else
        {
            if(nextState.score < bestState.score)
            {
                bestState.score = nextState.score;
            }
        }
    }
    
    return bestState;
}