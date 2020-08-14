#include <iostream>
#include "bintree.hpp"
using namespace std;

template <class T>
class BST
{
public:
    treeNode<T>* tree_search(treeNode<T>* root, T k);
    void iterative_tree_search(treeNode<T>* root, T k);
    void tree_minimum(treeNode<T>* root);
    void tree_maximum(treeNode<T>* root);
    void tree_successor(treeNode<T>* root);
    void tree_insert(treeNode<T>* root, T z);
    void transplant(treeNode<T>* root);
    void tree_delete(treeNode<T>* root, T z);
};

template <class T>
treeNode<T>* BST<T>:: tree_search(treeNode<T>* xNode, T k)
{
    if (xNode == nullptr || k == xNode->data)
    {
        cout << xNode->data <<" found" << endl;
        return xNode;
    }
    if ( k < xNode->data)
    {
        cout << "left of " << xNode->data << endl;
        return tree_search(xNode->left, k);
    }
    else
    {
        cout << "right of " << xNode->data << endl;
        return tree_search(xNode->right, k);
    }
}