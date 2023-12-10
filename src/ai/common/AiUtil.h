
#include "../../common/Util.h"

#include <cstdint>

#ifndef AIUTIL_H_
#define AIUTIL_H_

typedef struct
{
    Move_t move;
    StaticBoard_t board;
    int32_t score;
    char player;
} State_t;

const uint32_t MAX_SEARCH_DEPTH = 4;

const int32_t CAPTURE_EMPTY = 0;
const int32_t CAPTURE_PAWN = 10;
const int32_t CAPTURE_ROOK = 20;
const int32_t CAPTURE_KNIGHT = 20;
const int32_t CAPTURE_BISHOP = 20;
const int32_t CAPTURE_QUEEN = 35;
const int32_t CHECK = 50;
const int32_t CHECKMATE = 1000;

const int32_t LOSE_PAWN = -1;
const int32_t LOSE_ROOK = -2;
const int32_t LOSE_KNIGHT = -2;
const int32_t LOSE_BISHOP = -2;
const int32_t LOSE_QUEEN = -4;
const int32_t GET_CHECK = -10;
const int32_t GET_CHECKMATE = -100;

#endif