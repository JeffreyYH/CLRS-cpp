#include <iostream>
#include <algorithm>
using namespace std;

class BinTree
{
public:
    struct Node {
        char data;
        Node *left;
        Node *right;
    };

public:
    // search for index
    int searchIdx(char arr[], int start, int end, char value);

    // rebuild binary tree with In-order traversal in[] and Pre-order traversal pre[]
    // Initial values of idxStart and idxEnd should be 0 and len - 1
    Node *rebuildTree(char in[], char pre[], int idxStart, int idxEnd);

    //=========================Three different tree traversal methods==========================//
    // printer function in in-order
    void printInorder(Node *node);

    // printer function in pre-order
    void printPreOrder(Node *node);

    // printer function in post-order
    void printPostOrder(Node *node);

    // print tree by level
    void printbyLevel(Node *root, int level);

    //get the depth of the tree (max depth)
    static int getDepth(Node *node);

    int getDepth_2(Node *root);

    // print the whole tree level by level
    void printAllLevels(Node *root, int depth);
};



BinTree::Node* newNode(char value) {
    BinTree::Node* node = new BinTree::Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// search for index
int BinTree::searchIdx (char arr[], int start, int end, char value)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}

// rebuild binary tree with In-order traversal in[] and Pre-order traversal pre[]
// Initial values of idxStart and idxEnd should be 0 and len - 1
BinTree::Node* BinTree::rebuildTree (char in[], char pre[], int idxStart, int idxEnd)
{
    static int preIndex = 0;
    if(idxStart > idxEnd)
        return NULL;

    // allocates a new node
    // pick current node from Pre-order traversal using preIndex and increment preIndex
    Node* tNode = newNode (pre[preIndex]) ;
    preIndex ++;

    // cout << "pre index is" << endl;
    // cout << preIndex << endl;

    // if this node has no children then return
    if(idxStart  == idxEnd)
        return tNode;

    // else find the index of this node in In-order traversal to get the inIndex
    int inIndex = searchIdx(in, idxStart, idxEnd, tNode->data);

    // construct left and right subtree
    tNode->left = rebuildTree(in, pre, idxStart, inIndex-1);
    tNode->right = rebuildTree(in, pre, inIndex+1, idxEnd);

    return tNode;
}

//=========================Three different tree traversal methods==========================//
// printer function in in-order
void BinTree::printInorder(Node* node)
{
    if (node == NULL)
        return;
    BinTree::printInorder(node->left);
    cout << node->data << ' ';
    BinTree::printInorder(node->right);
}

// printer function in pre-order
void BinTree::printPreOrder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << ' ';
    BinTree::printPreOrder(node->left);
    BinTree::printPreOrder(node->right);
}

// printer function in post-order
void BinTree::printPostOrder(Node* node)
{
    if (node == NULL)
        return;
    BinTree::printPostOrder(node->left);
    BinTree::printPostOrder(node->right);
    cout << node->data << ' ';
}

// print tree by level
void BinTree::printbyLevel (Node * root, int level)
{
    if (!root || level < 0)
        return;
    if (level == 0)
        cout << root->data << ' ' ;
    BinTree::printbyLevel(root->left, level-1);
    BinTree::printbyLevel(root->right, level-1);
}

//get the depth of the tree (max depth)
int BinTree::getDepth(Node * node)
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

int BinTree::getDepth_2(Node *root)
{
    // Corner case. Should never be hit unless the code is called on root = NULL
    if (root == NULL)
        return 0;

    // Base case : Leaf Node. This accounts for height = 1.
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
void BinTree::printAllLevels (Node * root, int depth)
{
    for (int level=0; level < depth; level++)
    {
        BinTree::printbyLevel (root, level);
        cout << endl;
    }
}






