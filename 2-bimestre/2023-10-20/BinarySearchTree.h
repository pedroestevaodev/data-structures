#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
class BinarySearchTree{
    public:
        BinarySearchTree();
        //~BinarySearchTree();
        void PreOrder();
        void InOrder();
        void PostOrder();
        int Nodes();
        int Leaves();
        void Print();
        bool Search(int x);
        int Sum();
        void Pai(int x);

    private:
        struct TreeNode{
            int Entry;
            TreeNode* LeftNode;
            TreeNode* RightNode;
        };
        typedef TreeNode* TreePointer;
        TreePointer root;
        void PreOrder(TreePointer r);
        void InOrder(TreePointer r);
        void PostOrder(TreePointer r);
        int Nodes(TreePointer r);
        int Leaves(TreePointer r);
        void Print(TreePointer &r, int s);
        bool RSearch(int x, TreePointer &t);
        int Sum(TreePointer t);
        void Pai(int x, TreePointer &p);
};
#endif