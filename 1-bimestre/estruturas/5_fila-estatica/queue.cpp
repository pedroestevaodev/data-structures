#pragma once
#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue() 
{
    count = 0;
    head = 1;
    tail = 0;
}

Queue::~Queue() 
{
    cout << "Fila destruida" << endl;
}

bool Queue::Empty()
{
    return (count == 0);
}

bool Queue::Full()
{
    return (count == MaxQueue);
}

void Queue::Append(int x)
{
    if (Full())
    {
        cout << "Fila cheia" << endl;
        return;
        // abort();
    }

    tail = (tail % MaxQueue)+1;
    Entry[tail] = x;
    count++;
}

void Queue::Serve(int &x)
{
    if (Empty()) {
        cout << "Pilha vazia" << endl;
        return;
        // abort();
    }

    x = Entry[head];
    head = (head % MaxQueue) + 1;
    count--;
}

void Queue::Clear()
{
    int x;

    while (!Empty())
    {
        Serve(x);
    }
}

void Queue::Front(int &x)
{
    if (Empty())
    {
        cout << "Fila vazia" << endl;
        return;
        // abort();
    }

    x = Entry[head];
}

void Queue::Rear(int &x)
{
    if (Empty())
    {
        cout << "Fila vazia" << endl;
        return;
        // abort();
    }

    x = Entry[tail];
}

int Queue::Size()
{
    return count;
}