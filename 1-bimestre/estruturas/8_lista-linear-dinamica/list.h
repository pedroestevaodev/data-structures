// List.h
#pragma once

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
        struct ListNode
        {
            int Entry;
            ListNode *NextNode;
        };
        typedef ListNode *ListPointer;

        ListPointer head;
        int count;

        void SetPosition(int p, ListPointer &current);
};