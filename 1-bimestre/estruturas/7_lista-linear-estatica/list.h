// List.h
#pragma once

const int MaxList = 100;

class List
{
    public:
        List();
        ~List();
        void Insert(int p, int x);
        void Delete(int p, int &x);
        bool Empty();
        bool Full();
        void Clear();
        int Size();
        void Retrieve(int p, int &x);
        void Replace(int p, int x);

    private:
        int count;
        int Entry[MaxList + 1];
};