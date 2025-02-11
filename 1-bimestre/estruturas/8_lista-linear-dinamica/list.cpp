#include "list.h"
#include <iostream>
using namespace std;

List::List()
{
    head = NULL;
    count = 0;
}

List::~List()
{
    Clear();
}

bool List::Empty()
{
    return (head == NULL);
}

bool List::Full()
{
    return false;
}

void List::SetPosition(int p, ListPointer &current)
{
    int i;

    if (p < 1 || p > count+1)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort();
    }

    current = head;

    for (i = 2; i <= p; i++)
    {
        current = current->NextNode;
    }
}

void List::Insert(int p, int x)
{
    ListPointer NewNode, current;

    if (p < 1 || p > count+1)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort();
    }

    NewNode = new ListNode;
    NewNode->Entry = x;

    if (p == 1)
    {
        NewNode->NextNode = head;
        head = NewNode;
    } else {
        SetPosition(p-1, current);
        NewNode->NextNode = current->NextNode;
        current->NextNode = NewNode;
    }
    
    count++;
}

void List::Delete(int p, int &x)
{
    ListPointer Node, current;

    if (p < 1 || p > count)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort();
    }

    if (p == 1)
    {
        Node = head;
        head = Node->NextNode;
    } else {
        SetPosition(p - 1, current);
        Node = current->NextNode;
        current->NextNode = Node->NextNode;
    }

    x = Node->Entry;
    delete Node;
    count--;
}

void List::Clear()
{
    ListPointer q;

    while (head != NULL)
    {
        q = head;
        head = head->NextNode;
        delete q;
    }

    count = 0;
}

int List::Size()
{
    return count;
}

void List::Retrieve(int p, int &x)
{
    ListPointer q;

    if (p < 1 || p > count)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort()
    }

    SetPosition(p, q);
    x = q->Entry;
}

void List::Replace(int p, int x)
{   
    ListPointer q;

    if (p < 1 || p > count)
    {
        cout << "Posicao invalida" << endl;
        return;
        // abort()
    }

    SetPosition(p, q);
    q->Entry = x;
}