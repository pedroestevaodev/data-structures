#include "list.h"
#include <iostream>
using namespace std;

List::List() {
    head = NULL;
    count = 0;
}

List::~List() {
    ListPointer p;

    if (p == NULL) {
        return;
    }

    delete p;
}

bool List::Empty() {
    return head == NULL;
}

bool List::Full() {
    return false;
}

void List::SetPosition(int p, ListPointer &current) {
    int i;

    if (p < 1 || p > count+1) {
        return;
        // abort();
    }

    current = head;

    for (i = 2; i <= p; i++) {
        current = current->NextNode;
    }
}

void List::Insert(int p, int x) {
    ListPointer NewNode, current;

    if (p < 1 || p > count+1) {
        cout << "Posicao invalida" << endl;
        return;
        // abort()
    }

    NewNode = new ListNode;
    NewNode->Entry = x;

    if (p == 1) {
        NewNode->NextNode = head;
        head = NewNode;
    } else {
        SetPosition(p-1, current);
        NewNode->NextNode = current->NextNode;
        current->NextNode = NewNode;
    }

    count++;
}

void List::Delete(int p, int &x) {
    ListPointer Node, current;

    if (p < 1 || p > count) {
        cout << "Posicao invalida" << endl;
        return;
        // abort()
    }

    if (p == 1) {
        Node = head;
        head = head->NextNode;
    } else {
        SetPosition(p-1, current);
        Node = current->NextNode;
        current->NextNode = Node->NextNode;
    }

    x = Node->Entry;
    delete Node;
    count--;
}

void List::ImprimeListaPri(ListPointer p) {
    if (p == NULL) {
        return;
    }

    ImprimeListaPri(p->NextNode);
    cout << p->Entry << " ";
};

void List::ImprimeListaPub() {
    ImprimeListaPri(head);
}

void List::remove_valor(int x) {
    if (head == NULL) {
        return;
    }

    cout << head->Entry << endl;

    if (head->Entry == x) {
        ListPointer p = head;
        head = head->NextNode;
        delete p;
        count--;
        
        remove_valor(x);
        cout << "Valor removido: " << x << endl;
    }
}