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




