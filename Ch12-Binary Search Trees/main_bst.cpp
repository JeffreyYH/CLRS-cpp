#include <iostream>
#include "bst.hpp"

int main()
{
    treeNode<int> * root = new treeNode(15);
    root->left = new treeNode(6);
    root->left->left = new treeNode(3);
    root->left->right = new treeNode(7);

    root->right = new treeNode(18);
    root->right->left = new treeNode(17);
    root->right->right = new treeNode(20);

    // search
    BST<int> bst;
    bst.tree_search(root, 17);

    // min and max
    bst.tree_minimum(root);
    bst.tree_maximum(root);
}