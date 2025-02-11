#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue Fila1;
    Fila1.Append(4);
    Fila1.Append(5);
    Fila1.Append(6);
    Fila1.Append(7);
    Fila1.Append(8);

    int x;

    Fila1.Front(x);
    cout << "Valor do front da fila1: " << x << endl;

    Fila1.Rear(x);
    cout << "Valor do rear da fila1: " << x << endl;
}