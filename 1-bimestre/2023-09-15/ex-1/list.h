#pragma once

class List {
    public:
        List();
        ~List();
        void Insert(int p, int x);
        void Delete(int p, int &x);
        bool Empty();
        bool Full();
        void ImprimeListaPub();
        void remove_valor(int x);
        
    private:
        struct ListNode {
            int Entry;
            ListNode *NextNode;
        };
        typedef ListNode *ListPointer;

        ListPointer head;
        int count;

        void SetPosition(int p, ListPointer &current);
        void ImprimeListaPri(ListPointer p);
};