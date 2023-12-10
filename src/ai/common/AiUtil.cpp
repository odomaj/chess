#include "AiUtil.h"

int32_t max(int32_t num1, int32_t num2)
{
    if(num2 > num1)
    {
        return num2;
    }
    return num1;
}

int32_t min(int32_t num1, int32_t num2)
{
    if(num2 < num1)
    {
        return num2;
    }
    return num1;
}