#include "bag.h"
#include <iostream>
using namespace std;

int main()
{
    Bag sacola;

    for (int i = 0; i < 21; ++i)
    {
        sacola.Insert(i);
    }

    cout << "Numero de elementos 8: " << sacola.Occurrence(8) << endl;

    sacola.Remove(10);
    cout << "Quantidade de numeros 10 apos remoção: " << sacola.Occurrence(10) << endl;

    return 0;
}