// Stack.h
#pragma once

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
        struct QueueNode
        {
            int Entry;
            QueueNode *NextNode;
        };
        typedef QueueNode *QueuePointer;

        QueuePointer head, tail;
};