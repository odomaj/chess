
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

const uint32_t MAX_SEARCH_DEPTH = 3;

const int32_t CAPTURE_EMPTY = 0;
const int32_t CAPTURE_PAWN = 50;
const int32_t CAPTURE_ROOK = 150;
const int32_t CAPTURE_KNIGHT = 160;
const int32_t CAPTURE_BISHOP = 140;
const int32_t CAPTURE_QUEEN = 300;
const int32_t CHECK = 500;
const int32_t CHECKMATE = 5000;

int32_t max(int32_t num1, int32_t num2);
int32_t min(int32_t num1, int32_t num2);

#endif