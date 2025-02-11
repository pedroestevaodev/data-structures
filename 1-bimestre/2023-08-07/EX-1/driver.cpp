#include <iostream>
#include <string>
using namespace std;

void swap(void*& left, void*& right)
{
    void* temp = left;
    cout << "Temp: " << temp << endl;
    left = right;
    cout << "Left na funcao: " << left << endl;
    right = temp;
    cout << "Right na funcao: " << right << endl;
};

int main()
{
    void* left = new int[0];
    cout << "Left antes: " << left << endl;
    void* right = new int[0];
    cout << "Right antes: " << right << endl;
    cout << endl;

    swap(left, right);
    cout << endl;

    cout << "Left depois: " << left << endl;
    cout << "Right depois: " << right << endl;

    return 0;
}