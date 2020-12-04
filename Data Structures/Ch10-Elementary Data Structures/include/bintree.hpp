#include <iostream>
#include <algorithm>
using namespace std;

template <typename DtypeTree>
struct treeNode {
    DtypeTree data;
    treeNode *left;
    treeNode *right;
    treeNode (DtypeTree value) {data = value; left = nullptr; right = nullptr;};
    ~treeNode () {delete left; delete right;};
};

// class treeNode
/*
template <class DtypeTree>
class treeNode {
    public:
    DtypeTree data;
    treeNode *left;
    treeNode *right;
    treeNode (DtypeTree value) {data = value; left = nullptr; right = nullptr;};
    ~treeNode () {delete left; delete right;};
};
*/

template <class T>
class BinTree
{
public:
    // printer function in in-order
    void printInorder(treeNode<T> *node);

    // printer function in pre-order
    void printPreOrder(treeNode<T> *node);

    // printer function in post-order
    void printPostOrder(treeNode<T> *node);

    // print tree by level
    void printbyLevel(treeNode<T> *root, int level);

    //get the depth of the tree (max depth)
    static int getDepth(treeNode<T> *node);

    int getDepth_2(treeNode<T> *root);

    // print the whole tree level by level
    void printAllLevels(treeNode<T> *root, int depth);
};


//=========================Three different tree traversal methods==========================//
// printer function in in-order
template <class T>
void BinTree<T>::printInorder(treeNode<T>* node)
{
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->data << ' ';
    printInorder(node->right);
}

// printer function in pre-order
template <class T>
void BinTree<T>::printPreOrder(treeNode<T>* node)
{
    if (node == nullptr)
        return;
    cout << node->data << ' ';
    printPreOrder(node->left);
    printPreOrder(node->right);
}

// printer function in post-order
template <class T>
void BinTree<T>::printPostOrder(treeNode<T>* node)
{
    if (node == nullptr)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << ' ';
}

// print tree by level
template <class T>
void BinTree<T>::printbyLevel (treeNode<T> * root, int level)
{
    if (!root || level < 0)
        return;
    if (level == 0)
        cout << root->data << ' ' ;
    printbyLevel(root->left, level-1);
    printbyLevel(root->right, level-1);
}

//get the depth of the tree (max depth)
template <class T>
int BinTree<T>::getDepth(treeNode<T> * root)
{
    if (root == nullptr)
        return 0;
    else
    {
        currDepth = std::max(getDepth(root->left), getDepth(root->right)) + 1;
        return currDepth;
    }
}

template <class T>
int BinTree<T>::getDepth_2(treeNode<T> *root)
{
    // Corner case. Should never be hit unless the code is called on root = nullptr
    if (root == nullptr)
        return 0;

    // Base case : Leaf treeNode. This accounts for height = 1.
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    // If left subtree is nullptr, recur for right subtree
    if (root->left == nullptr)
        getDepth_2(root->right);

    // If right subtree is nullptr, recur for left subtree
    if (root->right == nullptr)
        getDepth_2(root->left);

    int maxDepth = std::max(getDepth_2(root->left), getDepth_2(root->right)) + 1;

    return maxDepth;
}

// print the whole tree level by level
template <class T>
void BinTree<T>::printAllLevels (treeNode<T> * root, int depth)
{
    for (int level=0; level < depth; level++)
    {
        printbyLevel (root, level);
        cout << endl;
    }
}