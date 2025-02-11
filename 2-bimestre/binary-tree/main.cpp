#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    BinaryTree tree;
    int opcaoMover = 0;

    do {
        cout << "SELECIONE UMA OPCAO DE VISUALIZACAO" << endl;
        cout << "1 - Pre-order" << endl;
        cout << "2 - In-order" << endl;
        cout << "3 - Pos-order" << endl;
        cout << "4 - Ver a quantidade de vertices" << endl;
        cout << "5 - Sair" << endl;
        cout << endl;

        cout << "Digite uma opcao: " << endl;
        cout << "- ";
        cin >> opcaoMover;
        cout << endl;

        switch (opcaoMover)
        {
            case 1:
                cout << "Opcao selecionada: Pre-order" << endl;
                tree.PreOrder();
                cout << endl;
                
                break;

            case 2:
                cout << "Opcao selecionada: In-order" << endl;
                tree.InOrder();
                cout << endl;
                
                break;

            case 3:
                cout << "Opcao selecionada: Pos-order" << endl;
                tree.PostOrder();
                cout << endl;
                
                break;

            case 4:
                cout << "Opcao selecionada: Quantidade de vertices" << endl;
                tree.QtdVertices();
                cout << endl;
                
                break;

            case 5:
                break;
            
            default:
                cout << "Opcao invalida. Tente novamente!" << endl;
                cout << endl;
                break;
        }
    } while (opcaoMover != 5);

    return 0;
}