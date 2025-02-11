#include "binarysearchtree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    Clear();
}

void BinarySearchTree::Clear() {

}

bool BinarySearchTree::Empty() {

}

bool BinarySearchTree::Full() {
    return false;
}

void BinarySearchTree::Insert(int x) {

}

void BinarySearchTree::Delete(int x) {

}

bool BinarySearchTree::Search(int x) {

}

int BinarySearchTree::Nodes() {
    return Nodes(root);
}

int BinarySearchTree::Nodes(TreePointer &r) {
    if (r == NULL) {
        return 0;
    } else {
        return 1 + Nodes(r->LeftNode) + Nodes(r->RightNode);
    }
}

bool BinarySearchTree::RSearch(int x, TreePointer r) {
    if (r == NULL) return false;

    if (x > r->Entry) {
        return RSearch(x, r->RightNode);
    }else if(x < r->Entry) {
        return RSearch(x, r->LeftNode);
    }else {
        return true;
    }
}