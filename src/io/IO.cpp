#include "IO.h"
#include <iostream>

IO::IO()
{

}

void IO::printBoard(const char* serialized_board)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < SERIALIZED_PIECE_BYTE_COUNT; k++)
            {
                int index = 8 * SERIALIZED_PIECE_BYTE_COUNT * i;
                index += j * SERIALIZED_PIECE_BYTE_COUNT;
                index += k;
                std::cout << serialized_board[index]; 
            }
        }
        std::cout << '\n';
    }
}