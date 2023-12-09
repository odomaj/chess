
#include "../common/AiUtil.h"
#include "../heuristic/Heuristic.h"

#ifndef MINIMAX_H_
#define MINIMAX_H_

class Minimax
{
    public:
    Minimax();
    ~Minimax();
    
    private:
    Heuristic heuristic;
    int32_t alpha;
    int32_t beta;
};

#endif