#include <iostream>
#include "linkedlist_double.hpp"
using namespace std;

template <class T>
class DoubleLinkedList
{
public:
    cirDoublyListNode<T> *head, *tail;

public:
    DoubleLinkedList() {head = NULL; tail = NULL;};   // constructor
    doubleListNode<T>* list_search(T k, bool printSearching);
    void list_insert(T k);
    void list_delete(doubleListNode<T> *xNode);
    void delete_element(T k);
    void list_print();
};
