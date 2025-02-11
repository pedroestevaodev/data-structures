class Stack
{
    public:
        void Push(int x);
        void Pop(int &x);
        Stack();
        ~Stack();
        bool Empty();
    private:
        typedef struct StackNode * NodePointer;
        struct StackNode {
            int Entry;
            NodePointer NextNode;
        };
        NodePointer top;
        int count;
};