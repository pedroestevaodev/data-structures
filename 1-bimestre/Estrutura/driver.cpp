#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack s1;
    int x;

    s1.Push(3);
    s1.Push(10);
    s1.Top(x);
    cout << x;
}