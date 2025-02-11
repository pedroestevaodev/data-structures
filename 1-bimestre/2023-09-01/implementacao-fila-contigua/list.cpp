#include "list.h"
#include <iostream>
using namespace std;

List::List() {
    count = 0;
}

List::~List() {
    cout << "Lista destruida!" << endl;
}

bool List::Empty() {
    return count == 0;
}

bool List::Full() {
    return count == MaxList;
}

void List::Insert(int p, int x) {
    if(Full()) {
        cout << "Lista cheia!" << endl;
        return;
        // abort();
    }

    if (p<1 || p > count+1) {
        cout << "Posicao de insercao nao valida!" << endl;
        return;
        // abort();
    }

    for (int i = count; i < p; i--) {
        Entry[i+1] = Entry[i];
    }

    Entry[p] = x;
    count++;
}

void List::Delete(int p, int &x) {
    if (Empty()) {
        cout << "Lista vazia!" << endl;
        return;
        // abort();
    }

    
}