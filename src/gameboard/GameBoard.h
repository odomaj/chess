#include "../gamepieces/Piece.h"
#include "../gamepieces/Pawn.h"
#include "../gamepieces/Rook.h"
#include "../gamepieces/Knight.h"
#include "../gamepieces/Bishop.h"
#include "../gamepieces/Queen.h"
#include "../gamepieces/King.h"
#include "../gamepieces/Empty.h"
#include "../common/ChessDefs.h"

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

class GameBoard_t
{
    public:
    GameBoard_t();
    ~GameBoard_t();
    void reset();
    private:
    Piece_t* board[8][8];
    void clear();
    void set();
};

#endif