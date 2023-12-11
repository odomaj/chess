#include "Minimax.h"

#include <iostream>

Minimax::Minimax()
{

}

Minimax::~Minimax()
{

}

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
    //return minimax(state, 1, 0).move;
    State_t check = minimax(state, 1, 0);
    //std::cout << check.score << '\n';
    return check.move;
}

/*
    calculate the heuristic for the given move on the given move (if not first call)
    if the search depth has been exceeded, return the value of the heuristic and the move (if not first call)
    otherwise update the board with the given move (if not first call)
    find all possible moves for the updated board
    call minimax on the new board with every possible move
    sum the optimum resulting minimax with the already calculated heuristic on the way down
    return that sum and the move that was passed to this function
*/
State_t Minimax::minimax(const State_t& state, int16_t depth, int32_t heuristicValue)
{
    GameBoard_t board = GameBoard_t(state.board);
    State_t nextState;
    nextState.score = heuristicValue;
    nextState.player = state.player;
    //std::cout << state.player << ':' << heuristicValue << ':' << depth << '\n';
    if(state.move.start.x != -1 || state.move.start.y != -1 || state.move.end.x != -1 || state.move.end.y != -1)
    {
        if(++depth > MAX_SEARCH_DEPTH)
        {
            StaticBoard_t staticBoard = board.getBoard();
            if(state.player == player)
            {
                nextState.score = heuristic.heuristic(staticBoard, state.move, state.player) + heuristicValue;
            }
            else
            {
                nextState.score = heuristicValue - heuristic.heuristic(staticBoard, state.move, state.player);
            }
            nextState.move = state.move;
            return nextState;
        }

        if(state.player == player)
        {
            StaticBoard_t staticBoard = board.getBoard();
            heuristicValue += heuristic.heuristic(staticBoard, state.move, state.player);
        }
        else
        {
            StaticBoard_t staticBoard = board.getBoard();
            heuristicValue -= heuristic.heuristic(staticBoard, state.move, state.player);
        }

        if(!board.move(state.move, state.player))
        {
            // should never occur
            return nextState;
        }

        nextState.player = WHITE;
        if(state.player == WHITE)
        {
            nextState.player = BLACK;
        }
    }

    std::list<Move_t> all_moves = board.getLegalMoves(nextState.player);

    if(all_moves.empty())
    {
        nextState.board = state.board;
        nextState.score = -1 * CHECKMATE;
        nextState.player = state.player;
        return nextState;
    }

    std::list<Move_t> moves;
    for(auto it = all_moves.begin(); it != all_moves.end(); it++)
    {
        if(rand() & 1)
        {
            moves.push_back(*it);
        }
        else
        {
            moves.push_front(*it);
        }
    }

    nextState.board = board.getBoard();

    State_t bestState;
    bestState.board = state.board;
    bestState.player = state.player;
    bestState.move = state.move;

    auto it = moves.begin();
    bestState.move = *it;
    nextState.move = *it;
    
    while(++it != moves.end())
    {
        nextState.move = *it;
        State_t newState = minimax(nextState, depth, heuristicValue);
        if(nextState.player == player)
        {
            if(newState.score > bestState.score)
            {
                bestState.score = newState.score;
                bestState.move = newState.move;
                alpha = max(alpha, bestState.score);
                if(alpha > beta)
                {
                    return bestState;
                }
            }
        }
        else
        {
            if(newState.score < bestState.score)
            {
                bestState.score = newState.score;
                bestState.move = newState.move;
                if(bestState.score < beta)
                {
                    beta= bestState.score;
                }
                beta = min(beta, bestState.score);
                if(beta < alpha)
                {
                    return bestState;
                }
            }
        }
    }
    //std::cout << bestState.score << ':' << bestState.player << '\n';
    return bestState;
}