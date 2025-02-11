#include "list.h"
#include <iostream>
using namespace std;

int main()
{
    List lista;

    cout << "Inserindo o valor 1..." << endl;
    lista.Insert(1);
    cout << "Inserindo o valor 2..." << endl;
    lista.Insert(2);
    cout << "Inserindo o valor 3..." << endl;
    lista.Insert(3);

    cout << "Quantidade de elementos na lista: " << lista.Size() << endl;

    cout << "Removendo elemento da lista..." << endl;
    int listaRemovida;
    lista.Delete(listaRemovida);
    cout << "Elemento removido: " << listaRemovida << endl;

    cout << "Total de elementos restantes: " << lista.Size() << endl;

    return 0;
}