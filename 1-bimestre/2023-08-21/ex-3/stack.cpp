void Stack(int &x)
{
    if(top == 0)
    {
        cout << "Pilha vazia" << endl;
        // abort()
        return;
    }
    x = Entry[top];
}