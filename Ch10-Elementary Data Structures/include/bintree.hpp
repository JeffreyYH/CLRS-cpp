#include <iostream>
#include <algorithm>
using namespace std;

template <typename DtypeTree>
struct treeNode {
    DtypeTree data;
    treeNode *left;
    treeNode *right;
    treeNode (DtypeTree value): data(value), left(NULL), right(NULL) {};
};

template <class T>
class BinTree
{
public:
    // search for index
    int searchIdx(T arr[], int start, int end, T value);

    //=========================Three different tree traversal methods==========================//
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


// search for index
template <class T>
int BinTree<T>::searchIdx (T arr[], int start, int end, T value)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}

//=========================Three different tree traversal methods==========================//
// printer function in in-order
template <class T>
void BinTree<T>::printInorder(treeNode<T>* node)
{
    if (node == NULL)
        return;
    BinTree::printInorder(node->left);
    cout << node->data << ' ';
    BinTree::printInorder(node->right);
}

// printer function in pre-order
template <class T>
void BinTree<T>::printPreOrder(treeNode<T>* node)
{
    if (node == NULL)
        return;
    cout << node->data << ' ';
    BinTree::printPreOrder(node->left);
    BinTree::printPreOrder(node->right);
}

// printer function in post-order
template <class T>
void BinTree<T>::printPostOrder(treeNode<T>* node)
{
    if (node == NULL)
        return;
    BinTree::printPostOrder(node->left);
    BinTree::printPostOrder(node->right);
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
    BinTree::printbyLevel(root->left, level-1);
    BinTree::printbyLevel(root->right, level-1);
}

//get the depth of the tree (max depth)
template <class T>
int BinTree<T>::getDepth(treeNode<T> * node)
{
    if (node == NULL)
        return 0;
    else
    {
        // compute the depth of each subtree
        int lDepth = BinTree::getDepth(node->left);
        int rDepth = BinTree::getDepth(node->right);

        // use the larger one as the depth of the tree
        if (lDepth > rDepth)
            return(lDepth+1);
        else
            return(rDepth+1);
    }
}

template <class T>
int BinTree<T>::getDepth_2(treeNode<T> *root)
{
    // Corner case. Should never be hit unless the code is called on root = NULL
    if (root == NULL)
        return 0;

    // Base case : Leaf treeNode. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL)
        return 1;

    // If left subtree is NULL, recur for right subtree
    if (root->left == NULL)
        getDepth(root->right);

    // If right subtree is NULL, recur for left subtree
    if (root->right == NULL)
        getDepth(root->left);

    int maxDepth = max(getDepth(root->left), getDepth(root->right)) + 1;

    return maxDepth;
}

// print the whole tree level by level
template <class T>
void BinTree<T>::printAllLevels (treeNode<T> * root, int depth)
{
    for (int level=0; level < depth; level++)
    {
        BinTree::printbyLevel (root, level);
        cout << endl;
    }
}








