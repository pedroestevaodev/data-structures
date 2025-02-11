#include <iostream>
#include <string>
using namespace std;

unsigned int persistencia(unsigned int num)
{
    unsigned int cont = 0;
    unsigned int constante = 1;

    while (num > 9)
    {
        constante = 1;
        while (num > 0)
        {
            constante *= num % 10;
            num /= 10;
        }
        num = constante;
        cont++;
    }

    return cont;
}

int main()
{
    unsigned int num = 0;

    cout << "Informe o numero ao qual deseja descobrir a persistencia multiplicativa: " << endl;
    cout << "- ";
    cin >> num;

    cout << "A persistencia multiplicativa de " << num << " e: " << persistencia(num) << endl;

    return 0;
}