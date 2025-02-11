#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack pilha;

    cout << "Inserindo o valor 1..." << endl;
    pilha.Push(1);
    cout << "Inserindo o valor 2..." << endl;
    pilha.Push(2);
    cout << "Inserindo o valor 3..." << endl;
    pilha.Push(3);

    cout << "Quantidade de elementos na pilha: " << pilha.Size() << endl;

    cout << "Removendo elemento da pilha..." << endl;
    int pilhaRemovida;
    pilha.Pop(pilhaRemovida);
    cout << "Elemento removido: " << pilhaRemovida << endl;

    cout << "Total de elementos restantes: " << pilha.Size() << endl;

    return 0;
}