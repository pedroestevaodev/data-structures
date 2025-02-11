#ifndef BINARYTREE_H
#define BINARYTREE_H
class BinaryTree 
{
    public:
        BinaryTree();
        ~BinaryTree();
        void PreOrder();
        void InOrder();
        void PostOrder();
    
    private:
        struct TreeNode {
            char Entry;
            TreeNode* LeftNode;
            TreeNode* RightNode;
        };
        typedef TreeNode* TreePointer;
        TreePointer root;

        void percorreArvoreEsquerda(TreePointer &current);
        void percorreArvoreCentro(TreePointer &current);
        void percorreArvoreDireita(TreePointer &current);
};
#endif