#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main() {
    BinarySearchTree tree;
    int opcao = 0;

    do {
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - Procurar" << endl;
        cout << "2 - Somar" << endl;
        cout << "3 - Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                int opcao_search;
                cout << "Informe o valor a se procurar: " << endl;
                cout << "- ";
                cin >> opcao_search;

                if(tree.Search(opcao_search)) {
                    cout << "Valor encontrado" << endl;
                } else {
                    cout << "Valor nao encontrado" << endl;
                }
                
                break;

            case 2:
                cout << "Soma: " << tree.Sum() << endl;

                break;

            case 3:
                break;
            
            default:
                cout << "Opcao invalida, tente novamente: " << endl;
                break;
        }

    } while (opcao != 3);

    return 0;
}