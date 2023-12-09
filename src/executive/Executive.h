#include "../io/IO.h"
#include "../gameboard/GameBoard.h"
#include "../ai/minimax/Minimax.h"

#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_

class Executive
{
    public:
    Executive();
    ~Executive();
    void run();
    private:
    IO* io;
    GameBoard_t* board;
    Minimax* minimax;
};

#endif