#include "../io/IO.h"
#include "../gameboard/GameBoard.h"

#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_

class Executive
{
    public:
    Executive();
    void run();
    private:
    IO* io;
    GameBoard_t* board;
};

#endif