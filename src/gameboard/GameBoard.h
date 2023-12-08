#include <string>

#include "../gamepieces/Piece.h"
#include "../gamepieces/Pawn.h"
#include "../gamepieces/Rook.h"
#include "../gamepieces/Knight.h"
#include "../gamepieces/Bishop.h"
#include "../gamepieces/Queen.h"
#include "../gamepieces/King.h"
#include "../gamepieces/Empty.h"
#include "../common/Util.h"

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

class GameBoard_t
{
    public:
    GameBoard_t();
    ~GameBoard_t();
    void reset();
    std::string serializeBoard();
    //bool move(int i1, int j1, int i2, int j2);
    // get all moves for every piece on the board
    bool move(Move_t& move, char color);
    std::list<Move_t> getAllMoves();
    // get all moves for every piece of the specified color on the board
    std::list<Move_t> getAllMoves(char color);
    // returns a static version of the board layout
    StaticBoard_t getBoard();
    // get all moves, accounting for check
    std::list<Move_t> getLegalMoves(char color);
    bool isInCheck(char color);
    private:
    Piece_t* board[8][8];
    void clear();
    void set();
    void performMove(Move_t& move);
    bool testMove(Move_t& move);
};

#endif