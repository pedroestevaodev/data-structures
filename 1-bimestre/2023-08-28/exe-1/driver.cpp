#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    count = 0;
    tail = 0;
    head = 1;
}

Queue::~Queue() {
    cout << "Fila destruida!" << endl;
}

bool Queue::Full() {
    return (count == MaxQueue);
}

bool Queue::Empty() {
    return count == 0;
}

void Queue::Append(int x) {
    if(Full()) {
        cout << "Fila cheia!" << endl;
        return;
        // abort();
    }
    count++;
    tail = (tail % MaxQueue)+1;
    Entry[tail] = x;
}

void Queue::Serve(int &x) {
    if(Empty()) {
        cout << "Fila vazia!" << endl;
        return;
        // abort();
    }
    x = Entry[head];
    count--;
    head = (head % MaxQueue)+1;
}

void Queue::Rear(int &x) {
    if(Empty()) {
        cout << "Pilha vazia" << endl;
        return;
        // abort();
    }
    x = Entry[tail];
}

void Queue::Front(int &x) {
    if(Empty()) {
        cout << "Pilha vazia" << endl;
        return;
        // abort();
    }
    x = Entry[head];
}

int Queue::Size() {
    return count;
}

void Queue::Clear() {
    count = 0;
    tail = 0;
    head = 1;
}