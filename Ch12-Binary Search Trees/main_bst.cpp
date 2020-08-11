#include <iostream>
#include "bst.hpp"

int main()
{
    treeNode<int> * root = new treeNode(6);
    root->left = new treeNode(5);
    root->left->left = new treeNode(2);
    root->left->right = new treeNode(5);
    root->right = new treeNode(7);
    root->right->right = new treeNode(8);
}