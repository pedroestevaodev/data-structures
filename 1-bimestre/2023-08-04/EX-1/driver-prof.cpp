#include <iostream>
#include <string>
using namespace std;

unsigned int persistencia(unsigned int num)
{
    long long tmp;
    unsigned int res = 0;

    while (num > 9)
    {
        tmp = 1;

        do
        {
            tmp = tmp * (num % 0);
            num = num/10;
        } while (num != 0);

        res++;
        num=tmp;
    }

    return res;
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