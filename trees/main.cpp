#include <iostream>
#include "binTree.h"

using namespace std;

int main()
{
    // test a binary tree:
    //       A
    //     /   \
    //    B      C
    //   / \    / \
    //  D   E  F

    const int LEN = 6;
    char in[LEN] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[LEN] = {'A', 'B', 'D', 'E', 'C', 'F'};

    // create new tree node for initialization, left and right is NULL
    BinTree<char> bintree;

    // obtain the rebuilt tree
    BinTree::Node *root = bintree.rebuildTree(in, pre, 0, LEN - 1);

    // print the tree in in-order
    cout << "In-order traversal of the tree is " << endl;
    bintree.printInorder(root);
    cout << endl;

    // print the tree in pre-order
    cout << "Pre-order traversal of the tree is " << endl;
    bintree.printPreOrder(root);
    cout << endl;

    // print the tree in post-order
    cout << "Post-order traversal of the tree is " << endl;
    bintree.printPostOrder(root);
    cout << endl;

    int depth = bintree.getDepth(root);
    cout << "the depth of the tree is " << depth << endl;

    // print the tree of level 1
    int level = 1;
    cout << "print tree of level " << level << endl;
    bintree.printbyLevel(root, level);
    cout << endl;

    // print the tree of level by level
    cout << "print tree of all levels " << endl;
    bintree.printAllLevels(root, depth);
    cout << endl;

    return 0;
}


