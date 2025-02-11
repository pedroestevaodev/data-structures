#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    top = 0;
}

Stack::~Stack()
{
    cout << "Chamado destrutor da pilha" << endl;
}

bool Stack::Full()
{
    return top == MaxStack;
}

bool Stack::Empty()
{
    return top == 0;
}

void Stack::Push(int x)
{
    if(Full())
    {
        cout << "A pilha esta cheia!" << endl;
        // abort();
        return;
    }

    top++;
    Entry[top] = x;
}

void Stack::Pop(int &x)
{
    if(Empty())
    {
        cout << "A pilha esta vazia! Elemento nao pode ser removido!" << endl;
        // abort()
        return;
    }

    x = Entry[top];
    top--;
}

void Stack::Top(int &x)
{
    if(Empty())
    {
        cout << "A pilha esta vazia! Não ha elemento no topo!" << endl;
        // abort()
        return;
    }

    x = Entry[top];
}