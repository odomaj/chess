
#include "../../gameboard/GameBoard.h"

#ifndef HEURISTIC_H_
#define HEURISTIC_H_

class Heuristic
{
    public:
    Heuristic();
    ~Heuristic();
    int32_t heuristic(GameBoard_t& board, Move_t move, char player);
    private:
};

#endif