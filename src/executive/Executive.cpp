#include "Executive.h"

#include <iostream>
Executive::Executive()
{
    board = GameBoard_t();
    io = IO();
}

void Executive::run()
{
    while(true)
    {
        std::string serializedBoard = board.serializeBoard();
        io.printBoard(serializedBoard);
        Move_t move;// = io.getMove();
        move.start.x = 1;
        move.start.y = 6;
        move.end.x = 1;
        move.end.y = 4;
        //std::cout << move.start.x << move.start.y << move.end.x << move.end.y << '\n';
        //io.printBoard(serializedBoard);
        board.move(move, WHITE);
        //board.getAllMoves(WHITE);
    }
}