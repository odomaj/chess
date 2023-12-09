
#include "../common/AiUtil.h"
#include "../heuristic/Heuristic.h"

#ifndef MINIMAX_H_
#define MINIMAX_H_

class Minimax
{
    public:
    Minimax();
    ~Minimax();
    Move_t getMove(const StaticBoard_t& board, char color);
    private:
    char player;
    Heuristic heuristic;
    // min score that the player is assured of
    int32_t alpha;
    // max score that the player could potentially recieve
    int32_t beta;
    State_t minimax(const State_t& state, int16_t depth);
};

#endif