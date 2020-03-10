#include <iostream>
#include <vector>
#include "linkedList.h"

using namespace std;

int main()
{
    List listObj;
    vector<int> testArr {5, 8, 9, 10, 12};
    for (int i:testArr)
        listObj.addTail(i);
    listObj.printList();

    listObj.addHead(7);
    listObj.printList();

    // insert node with data 18 after 9,
    listObj.insertNodeAfterElement(9, 18);
    listObj.printList();

    // insert node with data 32 after the 6th element (start with 0)
    listObj.insertNodeAfterPosition(6, 32);
    listObj.printList();

    // delete element
    listObj.deleteNode(32);
    listObj.printList();
    cout << listObj.tail->data << endl;

    return 0;
}
