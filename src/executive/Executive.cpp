#include "Executive.h"

#include <iostream>
Executive::Executive()
{
    board = new GameBoard_t();
    io = new IO();
}

Executive::~Executive()
{
    delete board;
    delete io;
    board = nullptr;
    io = nullptr;
}

void Executive::run()
{
    while(true)
    {
        std::string serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);
        Move_t move = io -> getMove();
        board -> move(move, WHITE);
        serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);
    }
}