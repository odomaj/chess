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
        if(!board -> move(move, WHITE))
        {
            std::cout << "GAME OVER\n";
            break;
        }
        std::string serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);

        staticBoard = board -> getBoard();
        move = minimax -> getMove(staticBoard, BLACK);
        if(!board -> move(move, BLACK))
        {
            std::cout << "GAME OVER\n";
            break;
        }
        serializedBoard = board -> serializeBoard();
        io -> printBoard(serializedBoard);
   }
}