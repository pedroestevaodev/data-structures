// Stack.h
#pragma once

const int MaxQueue = 100;

class Queue
{
    public:
        Queue();
        ~Queue();
        void Append(int x);
        void Serve(int &x);
        bool Empty();
        bool Full();
        void Clear();
        void Front(int &x);
        void Rear(int &x);
        int Size();

    private:
        int head;
        int tail;
        int count;
        int Entry[MaxQueue + 1];
};