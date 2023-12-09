
#include "../../gameboard/GameBoard.h"
#include "../common/AiUtil.h"

#include <cstdint>

#ifndef HEURISTIC_H_
#define HEURISTIC_H_

class Heuristic
{
    public:
    Heuristic();
    ~Heuristic();
    int32_t heuristic(const StaticBoard_t& board, Move_t move, char player);
    private:
};

#endif