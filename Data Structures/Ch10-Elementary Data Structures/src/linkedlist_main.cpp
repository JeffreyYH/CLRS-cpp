#include <iostream>
#include <vector>
#include "linkedlist_doubly.hpp"
#include "linkedlist_singly.hpp"
#include "linkedlist_cirDoubly.hpp"


void test_singlylist()
{
    //===== test single linked list =======//
    SinglyLinkedList<int> listObj;
    std::vector<int> testArr {5, 8, 9, 10, 12};
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
}

void test_doublylist()
{
    //===== test double linked list =======//
    DoublyLinkedList<int> dblistObj;
    dblistObj.list_insert(1);
    dblistObj.list_insert(4);
    dblistObj.list_insert(16);
    dblistObj.list_insert(9);
    dblistObj.list_print();
    dblistObj.list_insert(25);
    dblistObj.list_print();
    dblistObj.list_search(4, true);
    dblistObj.delete_element(9);
    dblistObj.list_print();
}

void test_cirDoublyList()
{
    //===== test circular double linked list =======//
    CirDoublyLinkedList<int> cirDblistObj;
    cirDblistObj.list_insert(1);
    cirDblistObj.list_insert(4);
    cirDblistObj.list_insert(16);
    cirDblistObj.list_insert(9);
    cirDblistObj.list_print();

    cirDblistObj.delete_element(1);
    cirDblistObj.list_print();
}

int main()
{
    cout << endl << "Test singly list" << endl;
    test_singlylist();

    cout << endl << "Test doubly list" << endl;
    test_doublylist();

    cout << endl << "Test circular doubly list" << endl;
    test_cirDoublyList();
    return 0;
}
