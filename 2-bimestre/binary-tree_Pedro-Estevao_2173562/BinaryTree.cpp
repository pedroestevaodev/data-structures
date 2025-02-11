#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() 
{
    root = new TreeNode;
    root->Entry = 'A';

    root->LeftNode = new TreeNode;
    root->LeftNode->Entry = 'B';
    root->RightNode = new TreeNode;
    root->RightNode->Entry = 'C';
    
    root->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->Entry = 'D';
    root->LeftNode->LeftNode->RightNode = NULL;
    root->LeftNode->RightNode = new TreeNode;
    root->LeftNode->RightNode->Entry = 'E';
    root->LeftNode->RightNode->LeftNode = NULL;
    root->LeftNode->RightNode->RightNode = NULL;

    root->LeftNode->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->LeftNode->Entry = 'H';
    root->LeftNode->LeftNode->LeftNode->LeftNode = NULL;
    root->LeftNode->LeftNode->LeftNode->RightNode = NULL;

    root->RightNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->Entry = 'F';
    root->RightNode->RightNode = new TreeNode;
    root->RightNode->RightNode->Entry = 'G';
    root->RightNode->RightNode->LeftNode = NULL;
    root->RightNode->RightNode->RightNode = NULL;

    root->RightNode->LeftNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->RightNode = NULL;
    root->RightNode->LeftNode->LeftNode->Entry = 'I';
    root->RightNode->LeftNode->LeftNode->LeftNode = NULL;
    root->RightNode->LeftNode->LeftNode->RightNode = NULL;
}

BinaryTree::~BinaryTree() {
    delete root;
}

void BinaryTree::PreOrder() {
    percorreArvoreEsquerda(root);
}

void BinaryTree::InOrder() {
    percorreArvoreCentro(root);
}

void BinaryTree::PostOrder() {
    percorreArvoreDireita(root);
}

void BinaryTree::percorreArvoreEsquerda(TreePointer &current) {
    if (current != nullptr)
    {
        cout << current->Entry << endl;
        percorreArvoreEsquerda(current->LeftNode);
        percorreArvoreEsquerda(current->RightNode);
    } else{
        return;
    }
}

void BinaryTree::percorreArvoreCentro(TreePointer &current) {
    if (current != nullptr)
    {
        percorreArvoreCentro(current->LeftNode);
        cout << current->Entry << endl;
        percorreArvoreCentro(current->RightNode);
    } else{
        return;
    }
}

void BinaryTree::percorreArvoreDireita(TreePointer &current) {
    if (current != nullptr)
    {
        percorreArvoreDireita(current->LeftNode);
        percorreArvoreDireita(current->RightNode);
        cout << current->Entry << endl;
    } else{
        return;
    }
}