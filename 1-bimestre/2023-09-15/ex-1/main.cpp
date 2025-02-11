#include "list.h"
#include <iostream>
using namespace std;

int main() {
    List lista;

    cout << "==========================================" << endl;
    cout << "===        ATIVIDADE 15/09/2023        ===" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << "Gerando valores..." << endl;

    cout << "Lista: ";
    for (int i = 0; i < 10; i++) {
        cout << (i+1)*10 << " ";
        lista.Insert(i+1, (i+1)*10);
    }
    cout << endl;
    cout << endl;

    cout << "Exibindo valores com recursividade..." << endl;

    cout << "Lista: ";
    lista.ImprimeListaPub();
    cout << endl;
    cout << endl;

    cout << "Removendo elementos com recursividade..." << endl;
    int valor;
    cout << "Informe o valor a ser removido: ";
    cin >> valor;
    cout << endl;
    cout << endl;

    lista.remove_valor(valor);

    cout << "Exibindo valores com recursividade..." << endl;

    cout << "Lista: ";
    lista.ImprimeListaPub();
    cout << endl;
    cout << endl;
    
    return 0;
}