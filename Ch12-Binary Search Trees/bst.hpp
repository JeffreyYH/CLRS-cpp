#include <iostream>
using namespace std;

template <typename Dtype>
struct treeNode {
    Dtype data;
    treeNode *left;
    treeNode *right;
    treeNode *parent;
    treeNode (Dtype value) {data = value; left = nullptr; right = nullptr; parent=nullptr;};
};


template <class T>
class BST
{
public:
    treeNode<T>* tree_search(treeNode<T>* xNode, T k);
    treeNode<T>* iterative_tree_search(treeNode<T>* xNode, T k);
    treeNode<T>* tree_minimum(treeNode<T>* xNode);
    treeNode<T>* tree_maximum(treeNode<T>* xNode);
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

template <class T>
treeNode<T>* BST<T>::tree_minimum(treeNode<T>* xNode)
{
    while (xNode->left != nullptr)
    {
        xNode = xNode ->left;
    }
    cout << "min of this BST: " << xNode->data << endl;
    return xNode;
}

template <class T>
treeNode<T>* BST<T>::tree_maximum(treeNode<T>* xNode)
{
    while (xNode->right != nullptr)
    {
        xNode = xNode ->right;
    }
    cout << "max of this BST " << xNode->data << endl;
    return xNode;
}
