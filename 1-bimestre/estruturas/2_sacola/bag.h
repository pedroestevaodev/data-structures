// Bag.h
#pragma once
#include <iostream>

const int CAPACITY = 20;

class Bag
{
    public:
        Bag();
        void Insert(int NewEntry);
        int Occurrence(int Entry) const;
        void Remove(int element);
        bool Full() const;

    private:
        int Data[CAPACITY + 1];
        int Used;
};