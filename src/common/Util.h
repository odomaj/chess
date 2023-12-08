#ifndef UTIL_H_
#define UTIL_H_

typedef struct
{
    int x;
    int y;
} Tile_t;

typedef struct
{
    Tile_t start;
    Tile_t end;
    char piece;
} Move_t;

typedef struct
{
    char pieces[8][8];
    char colors[8][8];
} StaticBoard_t;



const char WHITE = 'w';
const char BLACK = 'b';
const char EMPTY = 'e';

const char WHITE_PAWN = 'p';
const char WHITE_ROOK = 'r';
const char WHITE_KNIGHT = 'n';
const char WHITE_BISHOP = 'b';
const char WHITE_QUEEN = 'q';
const char WHITE_KING = 'k';

const char BLACK_PAWN = 'P';
const char BLACK_ROOK = 'R';
const char BLACK_KNIGHT = 'N';
const char BLACK_BISHOP = 'B';
const char BLACK_QUEEN = 'Q';
const char BLACK_KING = 'K';

const char NO_COLLISION = 0;
const char COLLISION_WITH_OPPONENT = 1;
const char COLLISION_WITH_TEAM = 2;

const int SERIALIZED_PIECE_BYTE_COUNT = 1;

char collision(const Move_t& move, const StaticBoard_t& board);

bool operator==(const Tile_t& tile1, const Tile_t& tile2);

bool operator==(const Move_t& move1, const Move_t& move2);

#endif