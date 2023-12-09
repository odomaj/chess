#include "IO.h"
#include <iostream>

IO::IO()
{

}

void IO::printBoard(const std::string& serializedBoard)
{

    std::cout << "  ";
    for(int i = 0; i < 8; i++)
    {
        std::cout << i;
        for(int j = 0; j < SERIALIZED_PIECE_BYTE_COUNT; j++)
        {
            std::cout << ' ';
        }
    }

    std::cout << '\n';

    for(int i = 0; i < 8; i++)
    {
        std::cout << i << ' ';
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < SERIALIZED_PIECE_BYTE_COUNT; k++)
            {
                int index = 8 * SERIALIZED_PIECE_BYTE_COUNT * i;
                index += j * SERIALIZED_PIECE_BYTE_COUNT;
                index += k;
                std::cout << serializedBoard[index] << ' '; 
            }
        }
        std::cout << '\n';
    }
}

Move_t IO::getMove()
{
    Move_t move;
    bool loop = true;
    while(loop)
    {
        loop = false;
        std::cout << "Please enter move as (x1, y1) to (x2, y2)...\n";
        std::string str;
        std::getline(std::cin, str);
        std::cout << "You entered: (" << str[1] << ", " << str[4] << ") to (" << str[11] << ", " << str[14] << ")\n";
        move.start.x = (int)(str[1] - '0');
        move.start.y = (int)(str[4] - '0');
        move.end.x = (int)(str[11] - '0');
        move.end.y = (int)(str[14] - '0');
        if(move.start.x < 0 || move.start.x > 7)
        {
            loop = true;
        }
        if(move.start.y < 0 || move.start.y > 7)
        {
            loop = true;
        }
        if(move.end.x < 0 || move.end.x > 7)
        {
            loop = true;
        }
        if(move.end.y < 0 || move.end.y > 7)
        {
            loop = true;
        }
    }
    return move;
}