class stack {
    public:
        void top(int &x);
        void push(int &x);
        void pop(int &x);
        stack();
        ~stack();
        bool empty();

    private:
        int data[100+1];
        int top;
}