#pragma once

class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void Insert(int x);
        void Delete(int x);
        bool Search(int x);
        int Nodes();
        void Clear();
        bool Empty();
        bool Full();

    private:
        struct TreeNode {
            int Entry;
            TreeNode *LeftNode, *RightNode;
        };
        typedef TreeNode *TreePointer;
        TreePointer root;
        
        int Nodes(TreePointer &r);
        bool RSearch(int x, TreePointer r);
};