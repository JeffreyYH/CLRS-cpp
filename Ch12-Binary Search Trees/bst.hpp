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
    treeNode<T> * root;
public:
    BST(T rootVal) { root = new treeNode<T>(rootVal); };
    treeNode<T>* tree_search(treeNode<T> * xNode, T k);
    treeNode<T>* iterative_tree_search(treeNode<T> * xNode, T k);
    treeNode<T>* tree_minimum(treeNode<T> * thisRoot);
    treeNode<T>* tree_maximum(treeNode<T> * thisRoot);
    treeNode<T>* tree_successor();

    void tree_insert(T val);
    void transplant(treeNode<T>* uNode, treeNode<T>* vNode);
    void tree_delete(treeNode<T>* zNode);
    void tree_delete_byValue(T val);
};

template <class T>
treeNode<T>* BST<T>:: tree_search(treeNode<T> * xNode, T k)
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
treeNode<T> * BST<T>::iterative_tree_search(treeNode<T> * xNode,  T k)
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
treeNode<T>* BST<T>::tree_minimum(treeNode<T> * thisRoot)
{
    treeNode<T> * xNode = thisRoot;
    while (xNode->left != nullptr)
    {
        xNode = xNode ->left;
    }
    return xNode;
}

template <class T>
treeNode<T>* BST<T>::tree_maximum(treeNode<T> * thisRoot)
{
    treeNode<T> * xNode = thisRoot;
    while (xNode->right != nullptr)
    {
        xNode = xNode ->right;
    }
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
void BST<T>::tree_insert(T val)
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

template <class T>
void BST<T>::transplant(treeNode<T>* uNode, treeNode<T>* vNode)
{
    if (uNode->parent == nullptr)
        root = vNode;
    else if (uNode == uNode->parent->left)
        uNode->parent->left = vNode;
    else
        uNode->parent->right = vNode;
    if (vNode != nullptr)
        vNode->parent = uNode->parent;
}

template <class T>
void BST<T>::tree_delete(treeNode<T> * zNode)
{
    if (zNode->left == nullptr)
        transplant(zNode, zNode->right);
    else if (zNode->right == nullptr)
        transplant(zNode, zNode->left);
    else
    {
        treeNode<T> * yNode = tree_minimum(zNode->right);
        if (yNode->parent != zNode)
        {
            transplant(yNode, yNode->right);
            yNode->right = zNode->right;
            yNode->right->parent = yNode;
        }
        transplant(zNode, yNode);
        yNode->left = zNode->left;
        yNode->left->parent = yNode;
    }
}

template <class T>
void BST<T>::tree_delete_byValue(T val)
{
    treeNode<T>* xNode = root;
    treeNode<T>* tgtNode = tree_search(xNode, val);
    tree_delete(tgtNode);
}