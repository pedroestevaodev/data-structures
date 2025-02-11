#pragma once
#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue() 
{
    head = tail = NULL;
}

Queue::~Queue() 
{
    int x;

    while (!Empty())
    {
        Serve(x);
    }
}

bool Queue::Empty()
{
    return (head == NULL);
}

bool Queue::Full()
{
    return false;
}

void Queue::Append(int x)
{
    QueuePointer p = new QueueNode;

    if (p == NULL)
    {
        cout << "Memoria insulficiente" << endl;
        return;
        // abort();
    }

    p->Entry = x;

    if (Empty())
    {
        head = tail = p;
    } else {
        tail->NextNode = p;
        tail = p;
    }

    p->NextNode = NULL;
}

void Queue::Serve(int &x)
{
    if (Empty()) {
        cout << "Fila vazia" << endl;
        return;
        // abort();
    }

    QueuePointer p;

    x = head->Entry;
    p = head;
    head = head->NextNode;
    delete p;

    if (head == NULL)
    {
        tail = NULL;
    }
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

    x = head->Entry;
}

void Queue::Rear(int &x)
{
    if (Empty())
    {
        cout << "Fila vazia" << endl;
        return;
        // abort();
    }

    x = tail->Entry;
}

int Queue::Size()
{
    int count = 0;
    QueuePointer p;
    p = head;

    while (p != NULL)
    {
        count++;
        p = p->NextNode;
    }

    return count;
}