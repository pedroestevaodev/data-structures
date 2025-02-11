#pragma once

class BinaryTree 
{
    public:
        BinaryTree();
        ~BinaryTree();
        void Insert(int x);
        void Delete(int x);
        bool Search(int x);
        int Nodes();
        void PreOrder();
        void InOrder();
        void PostOrder();
        int QtdVertices();
        int Leaves();
    
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
        int QtdVertices(TreePointer &current);
        int QtdNodes(TreePointer &current);
        int QtdLeaves(TreePointer &current);
};