#include "stack.h"
#include <iostream>

Stack::Stack()
{
    top = NULL;
}

bool Stack::Empty()
{
    return top == NULL;
}