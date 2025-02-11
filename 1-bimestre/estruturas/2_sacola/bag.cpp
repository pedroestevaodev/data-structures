// Bag.cpp
#include "bag.h"
#include <iostream>
using namespace std;

Bag::Bag() {
    Used = 0;

    for (int i = 0; i <= CAPACITY; i++) 
    {
        Data[i] = 0;
    }
}

void Bag::Insert(int NewEntry) 
{
    if (Used == CAPACITY) {
        cout << "Sacola cheia" << endl;
        return;
        // abort();
    }

    Data[Used] = NewEntry;
    Used++;
}

int Bag::Occurrence(int Entry) const
{
    int count = 0;

    for (int i = 1; i <= Used; i++)
    {
        if (Data[i] == Entry) 
        {
            count++;
        }
    }
    return count;
}

void Bag::Remove(int Entry)
{
    for (int i = Used; i >= 1; --i)
    {
        if (Data[i] == Entry)
        {
            for (int j = 1; j < Used; ++j)
            {
                Data[j] = Data[j + 1];
            }
            Used--;
        }
    }
}

bool Bag::Full() const {
    return Used == CAPACITY;
}