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
   while(true)
   {
        StaticBoard_t staticBoard = board -> getBoard();
        Move_t move = minimax -> getMove(staticBoard, WHITE);
        board -> move(move, WHITE);
        std::string serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);

        staticBoard = board -> getBoard();
        move = minimax -> getMove(staticBoard, BLACK);
        board -> move(move, BLACK);
        serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);
   }
}