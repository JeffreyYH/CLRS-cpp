#include <iostream>
#include "bintree.hpp"
using namespace std;

template <class T>
class BST
{
public:
    void tree_search(treeNode<T>* root, T k);
    void iterative_tree_search(treeNode<T>* root, T k);
    void tree_minimum(treeNode<T>* root);
    void tree_maximum(treeNode<T>* root);
    void tree_successor(treeNode<T>* root);
    void tree_insert(treeNode<T>* root, T z);
    void transplant(treeNode<T>* root);
    void tree_delete(treeNode<T>* root, T z);
};