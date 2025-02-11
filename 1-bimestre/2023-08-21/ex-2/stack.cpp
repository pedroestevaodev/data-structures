void Stack::Top(int &x)
{
    if(Empty())
    {
        cout << "Pilha vazia" << endl;
        // abort()
        return;
    }
    Pop(x);
    Push(x);
}