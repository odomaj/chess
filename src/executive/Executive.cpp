#include "Executive.h"

#include <iostream>
Executive::Executive()
{
    board = new GameBoard_t();
    io = new IO();
    minimax = new Minimax();
}

Executive::~Executive()
{
    delete board;
    delete io;
    delete minimax;
    board = nullptr;
    io = nullptr;
    minimax = nullptr;
}

void Executive::run()
{
    StaticBoard_t staticBoard = board -> getBoard();
    Move_t move = minimax -> getMove(staticBoard, WHITE);
    board -> move(move, WHITE);
    std::string serializedBoard = board -> serializeBoard();
    io -> printBoard(serializedBoard);
    /*
    while(true)
    {
        std::string serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);
        Move_t move = io -> getMove();
        board -> move(move, WHITE);
        serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);
    }
    */
}