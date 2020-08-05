#include <iostream>
#include <vector>
#include "linkedlist_double.hpp"
#include "linkedlist_single.hpp"
#include "linkedlist_cirDoubly.hpp"

using namespace std;

void test_singlelist()
{
    //===== test single linked list =======//
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
}

void test_doublelist()
{
    //===== test double linked list =======//
    DoubleLinkedList<int> dblistObj;
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

    //===== test circular double linked list =======//
    CirDoublyLinkedList<int> cirDblistObj;
    cirDblistObj.list_insert(1);
    cirDblistObj.list_insert(4);
    cirDblistObj.list_insert(16);
    cirDblistObj.list_insert(9);
    cirDblistObj.list_print();
}

int main()
{
    // test_singlelist();
    test_doublelist();
    return 0;
}
