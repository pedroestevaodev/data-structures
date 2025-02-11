#include <iostream>
#include <string>
using namespace std;

int main()
{
    int* ass = new int[2];
    unsigned int n;

    cout << "Informe a sequencia inicial: " << endl;
    cout << "Primeiro digito: ";
    cin >> ass[0];
    cout << "Segundo digito: ";
    cin >> ass[1];
    cout << "Terceiro digito: ";
    cin >> ass[2];
    cout << endl;

    cout << "Agora informe o numero de elementos a serem calculados: " << endl;
    cout << "- ";
    cin >> n;

    int* tribonacci = new int[n-1];

    for (int i = 0; i < 3; i++)
    {
        tribonacci[i] = ass[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << tribonacci[i];
    }

    return 0;
}