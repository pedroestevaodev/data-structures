#pragma once
#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top == NULL;
}

Stack::~Stack() {
    int x;
    
    while (!Empty())
    {
        Pop(x);
    }
}

bool Stack::Empty()
{
    return (top == NULL);
}

bool Stack::Full()
{
    // Por se tratar de uma pilha dinâmica
    // não tem "limite", então retorna false
    return false;
}

void Stack::Push(int x)
{
    StackPointer p = new StackNode;

    if (p == NULL)
    {
        cout << "Memoria insulficiente" << endl;
        return;
        // abort();
    }

    p->Entry = x;
    p->NextNode = top;
    top = p;
}

void Stack::Pop(int &x)
{
    if (Empty()) {
        cout << "Pilha vazia" << endl;
        return;
        // abort();
    }

    StackPointer p = new StackNode;

    x = top->Entry;
    p = top;
    top = top->NextNode;
    delete p;
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
    if (Empty())
    {
        cout << "Pilha vazia" << endl;
        return;
        // abort();
    }

    x = top->Entry;
}

int Stack::Size()
{
    StackPointer p;
    int s = 0;

    p = top;

    while (p != NULL)
    {
        p = p->NextNode;
        s++;
    }

    return s;
}