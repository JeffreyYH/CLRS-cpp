#include <iostream>
#include "bintree.hpp"
using namespace std;

template <class T>
class BST
{
public:
    treeNode<T>* tree_search(treeNode<T>* xNode, T k);
    treeNode<T> * iterative_tree_search(treeNode<T>* xNode, T k);
    void tree_minimum(treeNode<T>* xNode);
    void tree_maximum(treeNode<T>* xNode);
    void tree_successor(treeNode<T>* xNode);
    void tree_insert(treeNode<T>* xNode, T z);
    void transplant(treeNode<T>* xNode);
    void tree_delete(treeNode<T>* xNode, T z);
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

template <class T>
treeNode<T> * BST<T>::iterative_tree_search(treeNode<T> *xNode, T k)
{
    while ( xNode != nullptr || xNode->data != k)
    {
        if (k < xNode->data)
            xNode = xNode->left;
        else
            xNode = xNode->right;
    }
    return xNode;
}