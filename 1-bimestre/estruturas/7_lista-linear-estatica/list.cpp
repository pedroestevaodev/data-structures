#include "list.h"
#include <iostream>
using namespace std;

List::List()
{
    count = 0;
}

List::~List()
{
    cout << "Lista destruida" << endl;
}

bool List::Empty()
{
    return (count == 0);
}

bool List::Full()
{
    return (count == MaxList);
}

void List::Insert(int p, int x)
{
    int i;

    if (Full())
    {
        cout << "Lista cheia" << endl;
        return;
        // abort();
    }

    if (p < 1 || p > count+1)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort();
    }

    for (i = count; i >= p; i--)
    {
        Entry[i+1] = Entry[i];
    }
    
    Entry[p] = x;
    count++;
}

void List::Delete(int p, int &x)
{
    int i;

    if (Empty())
    {
        cout << "Lista vazia" << endl;
        return;
        // abort();
    }

    if (p < 1 || p > count)
    {
        cout << "Posicao invalida" << endl;
        return;
        //abort();
    }

    x = Entry[p];

    for (i = p; i < count; i++)
    {
        Entry[i] = Entry[i+1];
    }

    count--;
}

void List::Clear()
{
    count = 0;
}

int List::Size()
{
    return count;
}

void List::Retrieve(int p, int &x)
{
    if (p < 1 || p > count)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort()
    }

    x = Entry[p];
}

void List::Replace(int p, int x)
{
    if (p < 1 || p > count)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort()
    }

    Entry[p] = x;
}