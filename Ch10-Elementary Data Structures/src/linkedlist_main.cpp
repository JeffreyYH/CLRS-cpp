#include <iostream>
#include <vector>
#include "linkedlist_double.hpp"
#include "linkedlist_single.hpp"

using namespace std;

int main()
{
    SingleLinkedList<int> listObj;
    vector<int> testArr {5, 8, 9, 10, 12};
    for (int i:testArr)
        listObj.addTail(i);
    listObj.printList();

    listObj.addHead(7);
    listObj.printList();

    // insert node with data 18 after 9,
    listObj.insertAfterElement(9, 18);
    listObj.printList();

    // insert node with data 32 after the 6th element (start with 0)
    listObj.insertAfterPosition(6, 32);
    listObj.printList();

    // delete element
    listObj.deleteNode(32);
    listObj.printList();
    cout << listObj.tail->data << endl;

    return 0;
}
