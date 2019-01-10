#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

//============================rebuild the tree=================================//
// create new tree node for initialization, left and right is NULL
Node* newNode(char value)
{
    Node * node = new Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// search for index
int searchIdx (char arr[], int start, int end, char value)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}

// rebuild binary tree with In-order traversal in[] and Pre-order traversal pre[]
// Initial values of idxStart and idxEnd should be 0 and len - 1
Node* rebuildTree (char in[], char pre[], int idxStart, int idxEnd)
{
    static int preIndex = 0;
    if(idxStart > idxEnd)
        return NULL;

    // allocates a new node
    // pick current node from Pre-order traversal using preIndex and increment preIndex
    Node* tNode =  newNode (pre[preIndex]) ;
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
void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << ' ';
    printInorder(node->right);
}

// printer function in pre-order
void printPreOrder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << ' ';
    printPreOrder(node->left);
    printPreOrder(node->right);
}

// printer function in post-order
void printPostOrder(Node* node)
{
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << ' ';
}

// print tree by level
void printbyLevel (Node * root, int level)
{
    if (!root || level < 0)
        return;
    if (level == 0)
        cout << root->data << ' ' ;
    printbyLevel(root->left, level-1);
    printbyLevel(root->right, level-1);
}

//get the depth of the tree (max depth)
int getDepth(Node * node)
{
    if (node == NULL)
        return 0;
    else
    {
        // compute the depth of each subtree
        int lDepth = getDepth(node->left);
        int rDepth = getDepth(node->right);

        // use the larger one as the depth of the tree
        if (lDepth > rDepth)
            return(lDepth+1);
        else
            return(rDepth+1);
    }
    }

    int getDepth_2(Node *root)
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
void printAllLevels (Node * root, int depth)
{
    for (int level=0; level < depth; level++)
    {
        printbyLevel (root, level);
        cout << endl;
    }
}


int main()
{
    const int LEN = 6;
    char in[LEN] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[LEN] = {'A', 'B', 'D', 'E', 'C', 'F'};

    // obtain the rebuilt tree
    Node *root = rebuildTree(in, pre, 0, LEN - 1);

    // print the tree in in-order
    cout << "In-order traversal of the tree is " << endl;
    printInorder(root);
    cout << endl;

    // print the tree in pre-order
    cout << "Pre-order traversal of the tree is " << endl;
    printPreOrder(root);
    cout << endl;

    // print the tree in post-order
    cout << "Post-order traversal of the tree is " << endl;
    printPostOrder(root);
    cout << endl;

    int depth = getDepth(root);
    cout << "the depth of the tree is " << depth << endl;

    // print the tree of level 1
    int level = 1;
    cout << "print tree of level " << level << endl;
    printbyLevel(root, level);
    cout << endl;

    // print the tree of level by level
    cout << "print tree of all levels " << endl;
    printAllLevels(root, depth);
    cout << endl;

    return 0;
}

