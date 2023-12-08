#include "../common/Util.h"

#include <string>

#ifndef IO_H_
#define IO_H_

class IO
{
    public:
    IO();
    void printBoard(const std::string& serializedBoard);
};

#endif