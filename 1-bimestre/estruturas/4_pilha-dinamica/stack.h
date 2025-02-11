// Stack.h
#pragma once

const int MaxStack = 100;

class Stack
{
    public:
        Stack();
        ~Stack();
        void Push(int x);
        void Pop(int &x);
        bool Empty();
        bool Full();
        void Clear();
        void Top(int &x);
        int Size();

    private:
        struct StackNode 
        {
            int Entry;
            StackNode *NextNode;
        };
        typedef StackNode *StackPointer;

        StackPointer top;
};