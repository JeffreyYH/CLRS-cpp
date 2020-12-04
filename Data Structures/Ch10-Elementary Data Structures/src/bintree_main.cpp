#include <iostream>
#include "bintree.hpp"

using namespace std;

int main()
{
    // test a binary tree:
    //       A
    //     /   \
    //    B      C
    //   / \    / \
    //  D   E  F   G

    BinTree<char> bintree;

    // root
    treeNode<char> *root = new treeNode<char>('A');

    // first level
    root->left = new treeNode<char>('B');
    root->right = new treeNode<char>('C');

    // second level
    root->left->left = new treeNode<char>('D');
    root->left->right = new treeNode<char>('E');
    root->right->left = new treeNode<char>('F');
    root->right->right = new treeNode<char>('G');

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
    int level = 2;
    cout << "print tree of level " << level << endl;
    bintree.printbyLevel(root, level);
    cout << endl;

    // print the tree of level by level
    cout << "print tree of all levels " << endl;
    bintree.printAllLevels(root, depth);
    cout << endl;

    return 0;
}