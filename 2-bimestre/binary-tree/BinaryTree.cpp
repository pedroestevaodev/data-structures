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

void BinaryTree::Insert(int x) {

}

void BinaryTree::Delete(int x) {

}

bool BinaryTree::Search(int x) {

}

int BinaryTree::Nodes() {
    return QtdNodes(root);
}

int BinaryTree::Leaves() {
    return QtdLeaves(root);
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

int BinaryTree::QtdVertices() {
    return QtdVertices();
}

void BinaryTree::percorreArvoreEsquerda(TreePointer &current) {
    if (current != nullptr)
    {
        cout << current->Entry << " ";
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
        cout << current->Entry << " ";
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
        cout << current->Entry << " ";
    } else{
        return;
    }
}

int BinaryTree::QtdVertices(TreePointer &current) {
    if (current == NULL) {
        return 0;
    }

    return 1 + QtdVertices(current->LeftNode) + QtdVertices(current->RightNode);
}

int BinaryTree::QtdNodes(TreePointer &t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + QtdNodes(t->LeftNode) + QtdNodes(t->RightNode);
    }
}

int BinaryTree::QtdLeaves(TreePointer &t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + QtdLeaves(t->LeftNode) + QtdLeaves(t->RightNode);
    }
}