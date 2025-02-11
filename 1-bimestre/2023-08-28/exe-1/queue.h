#ifndef QUEUE_H
#define QUEUE_H

const int MaxQueue = 100;

class Queue {
    public:
        Queue();
        ~Queue();
        void Append(int x);
        void Serve(int &x);
        bool Empty();
        bool Full();
        int Size();
        void Clear();
        void Front(int &x);
        void Rear(int &x);
    private:
        int tail;
        int head;
        int count;
        int Entry[MaxQueue + 1];
};

#endif