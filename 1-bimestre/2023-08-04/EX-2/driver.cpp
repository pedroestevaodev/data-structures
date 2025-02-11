#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned int tamanho_vetor;

    cout << "Informe o tamanho do vetor: " << endl;
    cout << "- ";
    cin >> tamanho_vetor;
    cout << endl;

    float vetor[tamanho_vetor];

    for (int i = 0; i < tamanho_vetor; i++)
    {
        unsigned int valor_atual;

        cout << "O valor da " << (i+1) << " posicao: ";
        cin >> valor_atual;

        vetor[i] = valor_atual;
    }
    cout << endl;

    

    return 0;
}