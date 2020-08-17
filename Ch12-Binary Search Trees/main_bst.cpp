#include <iostream>
#include <vector>
#include "bst.hpp"

int main()
{
    vector<int> treeData = {12, 5, 18, 2, 9, 15, 19, 13, 17};
    BST<int> bst(treeData[0]);

    // insert
    for (int i=1; i<treeData.size(); i++)
        bst.tree_insert(treeData[i]);

    // search
    bst.tree_search(bst.root, 17);

    // min and max
    bst.tree_minimum(bst.root);
    bst.tree_maximum(bst.root);

    // successor
    bst.tree_successor(bst.root);

    // delete
    bst.tree_delete_byValue(18);

    return 0;
}