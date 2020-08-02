#include <iostream>
#include "bintree.hpp"
using namespace std;

template <typename T>
int searchIdx (T arr[], int start, int end, T value)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}

// rebuild binary tree with In-order traversal in[] and Pre-order traversal pre[]
// Initial values of idxStart and idxEnd should be 0 and len - 1
template <typename T>
treeNode<T>* rebuildTree (T in[], T pre[], int idxStart, int idxEnd)
{
    static int preIndex = 0;
    if(idxStart > idxEnd)
        return NULL;

    // allocates a new node
    // pick current node from Pre-order traversal using preIndex and increment preIndex
    treeNode<T> *tNode = new treeNode (pre[preIndex]) ;
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

int main() {
    // rebuild a binary tree:
    //       A
    //     /   \
    //    B      C
    //   / \    / \
    //  D   E  F

    const int LEN = 6;
    char in[LEN] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[LEN] = {'A', 'B', 'D', 'E', 'C', 'F'};

    BinTree<char> bintreeUtils;

    // obtain the rebuilt tree
    treeNode<char> *root = rebuildTree(in, pre, 0, LEN - 1);

    // print the tree of level by level
    int depth = bintreeUtils.getDepth(root);
    cout << "print tree of all levels " << endl;
    bintreeUtils.printAllLevels(root, depth);
    cout << endl;
}

