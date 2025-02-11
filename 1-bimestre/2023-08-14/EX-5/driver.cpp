#include "esfera.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Esfera esfera;

    do {
        cout << endl;
        cout << "==========================================" << endl;
        cout << "===                MENU                ===" << endl;
        cout << "==========================================" << endl;
        cout << "1 - Calcular raio" << endl;
        cout << "2 - Calcular area" << endl;
        cout << "3 - Calcular volume" << endl;
        cout << "4 - Sair" << endl;
        cout << "==========================================" << endl;
        cout << endl;

        cout << "Digite uma opcao: " << endl;
        cout << "- ";
        esfera.pegaOpcao();
        cin.ignore();

        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            
            cout << "Opcao invalida! Digite novamente: " << endl;
            cout << "- ";
            cin >> opcao;
            cin.ignore();
        }
        cout << endl;

        switch (opcao)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "==========================================" << endl;
                cout << endl;
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente!" << endl;
                break;
        }
    } while (opcao != 7);

    return 0;
}