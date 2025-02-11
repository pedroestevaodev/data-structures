// Stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() 
{
    top = 0;
}

Stack::~Stack() 
{
    // Em pilhas estáticas o destrutor não é muito necessário
    cout << "Pilha destruida" << endl;
}

bool Stack::Empty() 
{
    return (top == 0);
}

bool Stack::Full()
{
    return (top == MaxStack);
}

void Stack::Push(int x)
{
    if (Full())
    {
        cout << "Pilha cheia" << endl;
        return;
        // abort();
    }

    Entry[top++] = x;
}

void Stack::Pop(int &x)
{
    if (Empty())
    {
        cout << "Pilha Vazia" << endl;
        return;
        // abort();
    }

    x = Entry[top];
    top--;
}

void Stack::Clear()
{
    int x;

    while (!Empty())
    {
        Pop(x);
    }
}

void Stack::Top(int &x)
{
    if (top == 0)
    {
        cout << "Pilha vazia" << endl;
        return;
        // abort();
    }

    x = Entry[top];
}

int Stack::Size()
{
    return top;
}