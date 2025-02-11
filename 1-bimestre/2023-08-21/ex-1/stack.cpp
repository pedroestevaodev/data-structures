#include "stack.h"

void Stack::Clear()
{
    int x;
    while (!Empty)
    {
        Pop(x);
    }
}

void Stack::Clear()
{
    top = 0;
}