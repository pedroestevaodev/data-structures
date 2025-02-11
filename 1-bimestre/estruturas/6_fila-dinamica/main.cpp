#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    Queue fila;

    cout << "Inserindo o valor 1..." << endl;
    fila.Append(1);
    cout << "Inserindo o valor 2..." << endl;
    fila.Append(2);
    cout << "Inserindo o valor 3..." << endl;
    fila.Append(3);

    cout << "Quantidade de elementos na fila: " << fila.Size() << endl;

    cout << "Removendo elemento da fila..." << endl;
    int filaRemovida;
    fila.Serve(filaRemovida);
    cout << "Elemento removido: " << filaRemovida << endl;

    cout << "Total de elementos restantes: " << fila.Size() << endl;

    return 0;
}