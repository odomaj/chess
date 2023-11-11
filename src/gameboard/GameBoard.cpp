#include <sstream>
#include <iostream>
#include "GameBoard.h"

GameBoard_t::GameBoard_t()
{
    set();
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

void GameBoard_t::print()
{
    std::string serializedBoard = serializeBoard();
    //std::cout << serializedBoard.data() << '\n';
    io.printBoard(serializedBoard.data());
}