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
    treeNode<T>* tree_successor(treeNode<T>* xNode);
    void tree_insert(treeNode<T>* root, T z);
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

// TODO
/*template <class T>
treeNode<T>* BST<T>::tree_successor(treeNode<T>* xNode)
{
    if (xNode->right != nullptr)
        return tree_minimum(xNode->right);
    treeNode<T> *yNode = xNode->parent;
    while (yNode != nullptr && xNode == yNode->right)
    {
        xNode = yNode;
        yNode = yNode->parent;
    }
    return yNode;
}*/

template <class T>
void BST<T>::tree_insert(treeNode<T>* root, T val)
{
    treeNode<T> * xNode = root;
    treeNode<T> * parentNode = nullptr;
    treeNode<T> * tgtNode = new treeNode<T>(val);

    // find the position to insert iteratively
    while (xNode != nullptr)
    {
        parentNode = xNode;
        if (tgtNode->data < xNode->data)
            xNode = xNode ->left;
        else
            xNode = xNode->right;
    }
    tgtNode->parent = parentNode;
    if (parentNode == nullptr)
        root = tgtNode;
    else if (tgtNode->data < parentNode->data)
        parentNode->left = tgtNode;
    else
        parentNode->right = tgtNode;
}