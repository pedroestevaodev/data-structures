#include "stack.h"

stack::stack() {
    top = 0;
}

bool stack::empty() {
    return top == 0;
}