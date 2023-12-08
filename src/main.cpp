#include "gameboard/GameBoard.h"
#include <iostream>

int main()
{
    GameBoard_t board;
    //board.print();
    //int i1, j1, i2, j2;
    //std::cin >> i1 >> j1 >> i2 >> j2;
    //std::cout << "(" << i1 << ", " << j1 << ")" << " to (" << i2 << ", " << j2 << ")\n";
    //board.print();
    std::list<Move_t> moves = board.getAllMoves(WHITE);
    for(auto it = moves.begin(); it != moves.end(); it++)
    {
        std::cout << it -> piece << ": (" << it -> start.x << ", " << it -> start.y << ")" << " to (" << it -> end.x << ", " << it -> end.y << ")\n"; 
    }
    return 0;
}