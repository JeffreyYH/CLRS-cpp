#include <iostream>
#include "bst.hpp"

int main()
{
    treeNode<int> * root = new treeNode(15);
    root->left = new treeNode(6);
    root->left->parent = root;
    root->left->left = new treeNode(3);
    root->left->left->parent = root->left;
    root->left->right = new treeNode(7);
    root->left->left->parent = root->left;

    root->right = new treeNode(18);
    root->right->parent = root;
    root->right->left = new treeNode(17);
    root->right->right = new treeNode(20);

    root->right->left->parent =root->right;
    root->right->right->parent = root->right;

    // search
    BST<int> bst;
    bst.tree_search(root, 17);

    // min and max
    bst.tree_minimum(root);
    bst.tree_maximum(root);
}