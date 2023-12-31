#include <sstream>
#include <iostream>
#include "GameBoard.h"
#include "../io/IO.h"

GameBoard_t::GameBoard_t()
{
    set();
}

GameBoard_t::GameBoard_t(const StaticBoard_t& board)
{
    generateBoard(board);
}

GameBoard_t::~GameBoard_t()
{
    clear();
}

void GameBoard_t::set()
{
    board[0][0] = new Rook_t(BLACK);
    board[0][1] = new Knight_t(BLACK);
    board[0][2] = new Bishop_t(BLACK);
    board[0][3] = new Queen_t(BLACK);
    board[0][4] = new King_t(BLACK);
    board[0][5] = new Bishop_t(BLACK);
    board[0][6] = new Knight_t(BLACK);
    board[0][7] = new Rook_t(BLACK);
    
    board[7][0] = new Rook_t(WHITE);
    board[7][1] = new Knight_t(WHITE);
    board[7][2] = new Bishop_t(WHITE);
    board[7][3] = new Queen_t(WHITE);
    board[7][4] = new King_t(WHITE);
    board[7][5] = new Bishop_t(WHITE);
    board[7][6] = new Knight_t(WHITE);
    board[7][7] = new Rook_t(WHITE);

    for(int i = 0; i < 8; i++)
    {
        board[1][i] = new Pawn_t(BLACK);
        board[6][i] = new Pawn_t(WHITE);
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = new Empty_t();
        }
    }
    getBoard();
}

void GameBoard_t::reset()
{
    clear();
    set();
}

void GameBoard_t::clear()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}

std::string GameBoard_t::serializeBoard()
{
    std::ostringstream oss;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            oss << board[i][j] -> serialize();
        }
    }
    return oss.str();
}

/*
    loops through all spaces on the board
    asks every piece for all of its possible moves and adds them to the list
    return the completed list
    does not account for check
*/
std::list<Move_t> GameBoard_t::getAllMoves()
{
    std::list<Move_t> moves;
    StaticBoard_t staticBoard = getBoard();
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Tile_t tile;
            tile.x = j;
            tile.y = i;
            std::list<Move_t> newMoves = board[i][j] -> getMoves(tile, staticBoard);
            moves.splice(moves.end(), newMoves);
        }
    }
    return moves;
}

/*
    loops through all spaces on the board
    if a given is of the given color, asks for all of its possible moves and adds them to the list
    return the completed list
    does not account for check
*/
std::list<Move_t> GameBoard_t::getAllMoves(char color)
{
    std::list<Move_t> moves;
    StaticBoard_t staticBoard = getBoard();
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] -> getColor() != color)
            {
                continue;
            }
            Tile_t tile;
            tile.x = j;
            tile.y = i;
            std::list<Move_t> newMoves = board[i][j] -> getMoves(tile, staticBoard);
            moves.splice(moves.end(), newMoves);
        }
    }
    return moves;
}

/*
    generates a static board from the board
*/
StaticBoard_t GameBoard_t::getBoard()
{
    StaticBoard_t staticBoard;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            staticBoard.colors[i][j] = board[i][j] -> getColor();
            staticBoard.pieces[i][j] = board[i][j] -> serialize();
        }
    }
    return staticBoard;
}

/*
    finds all possible moves for the opponent color
    finds the given colors king
    checks if any possible moves by the opponent land on the king's position
*/
bool GameBoard_t::isInCheck(char color)
{
    char opponentsColor = WHITE;
    if(color == WHITE)
    {
        opponentsColor = BLACK;
    }
    std::list<Move_t> opponentsMoves = getAllMoves(opponentsColor);
    Tile_t kingTile;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] -> getColor() == color)
            {
                char piece = board[i][j] -> serialize();
                if(piece == WHITE_KING || piece == BLACK_KING)
                {
                    kingTile.x = j;
                    kingTile.y = i;
                }
            }
        }
    }
    for(auto it = opponentsMoves.begin(); it != opponentsMoves.end(); it++)
    {
        if(it -> end.x == kingTile.x && it -> end.y == kingTile.y)
        {
            return true;
        }
    }

    return false;
}

/*
    uses getAllMoves to get all possible moves, then uses checkMove to remove any moves that lead to a check
*/
std::list<Move_t> GameBoard_t::getLegalMoves(char color)
{
    std::list<Move_t> allMoves = getAllMoves(color);
    auto it = allMoves.begin();
    while(it != allMoves.end())
    {
        if(!testMove(*it))
        {
            it = allMoves.erase(it);
        }
        else{
            it++;
        }
    }
    return allMoves;
}

/*
    deletes the piece in the end position
    has the end position point to the piece in the start position
    makes a new empty space for the start position to point to
*/
void GameBoard_t::performMove(Move_t& move)
{
    board[move.start.y][move.start.x] -> move();
    delete board[move.end.y][move.end.x];
    board[move.end.y][move.end.x] = board[move.start.y][move.start.x];
    board[move.start.y][move.start.x] = new Empty_t();
    
}

/*
    returns true if move is vaild
    returns false if the move leads to a check
*/
bool GameBoard_t::testMove(Move_t move)
{
    std::string s = serializeBoard();
    Piece_t* endPiece = board[move.end.y][move.end.x];
    Piece_t* startPiece = board[move.start.y][move.start.x];
    Piece_t* emptySpace = new Empty_t();

    board[move.end.y][move.end.x] = startPiece;
    board[move.start.y][move.start.x] = emptySpace;
    bool inCheck = isInCheck(startPiece -> getColor());
    board[move.end.y][move.end.x] = endPiece;
    board[move.start.y][move.start.x] = startPiece;
    delete emptySpace;
    emptySpace = nullptr;
    return !inCheck;
}

/*
    attempt to perform a move
    if the move is possible, perform the move and return true
    otherwise return false
*/
bool GameBoard_t::move(const Move_t& move, char color)
{
    std::list<Move_t> moves = getLegalMoves(color);
    for(auto it = moves.begin(); it != moves.end(); it++)
    {
        if(*it == move)
        {
            performMove(*it);
            return true;
        }
    }
    return false;
}

void GameBoard_t::generateBoard(const StaticBoard_t& board_)
{
    Tile_t tile;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            tile.x = j;
            tile.y = i;
            board[i][j] = generatePiece(board_.pieces[i][j], tile);
        }
    }
}

Piece_t* GameBoard_t::generatePiece(char serializedPiece, Tile_t tile)
{
    switch(serializedPiece)
    {
    case WHITE_PAWN:
    {
        Piece_t* piece = new Pawn_t(WHITE);
        if(tile.y != 6)
        {
            piece -> move();
        }
        return piece;
    }
    case WHITE_ROOK:
        return new Rook_t(WHITE);
    case WHITE_KNIGHT:
        return new Knight_t(WHITE);
    case WHITE_BISHOP:
        return new Bishop_t(WHITE);
    case WHITE_QUEEN:
        return new Queen_t(WHITE);
    case WHITE_KING:
        return new King_t(WHITE);
    case BLACK_PAWN:
    {
        Piece_t* piece = new Pawn_t(BLACK);
        if(tile.y != 1)
        {
            piece -> move();
        }
        return piece;
    }
    case BLACK_ROOK:
        return new Rook_t(BLACK);
    case BLACK_KNIGHT:
        return new Knight_t(BLACK);
    case BLACK_BISHOP:
        return new Bishop_t(BLACK);
    case BLACK_QUEEN:
        return new Queen_t(BLACK);
    case BLACK_KING:
        return new King_t(BLACK);
    default:
        return new Empty_t();
    }
}
