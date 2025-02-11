#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    top == NULL;
}

Stack::~Stack()
{
    Clear();
}

void Stack::Push(int x)
{
    StackNode* p = new StackNode;

    if(p == NULL)
    {
        cout << "Nao ha espaco na memoria" << endl;
        return;
        // abort();
    }

    p->entry = x;
    p->nextNode = top;
    top = p;
}

void Stack::Pop(int &x)
{
    if(Empty())
    {
        cout << "Nao ha elemento para remover da pilha" << endl;
        return;
        // abort();
    }

    StackNode* p = new StackNode;
    x = top->entry;
    p = top;
    top = top->nextNode;
    delete p;
}

bool Stack::Empty()
{
    return (top == NULL);
}

bool Stack::Full()
{
    return false;
}

void Stack::Top(int &x)
{
    if(Empty())
    {
        cout << "Pilha vazia..." << endl;
        return;
        // abort();
    }
    x = top->entry;
}

void Stack::Clear()
{
    int x;
    while(!Empty())
    {
        Pop(x);
    }
}