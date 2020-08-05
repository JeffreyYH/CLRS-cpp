#include <iostream>
using namespace std;

template <typename Dtype>
struct cirDoubleListNode {
    Dtype key;
    cirDoubleListNode *prev;
    cirDoubleListNode *next;
    cirDoubleListNode(Dtype x) {key=x; prev=NULL; next=NULL;};
};

template <class T>
class CirDoublyLinkedList
{
public:
    cirDoubleListNode<T> *listNil;

public:
    CirDoublyLinkedList();   // constructor
    doubleListNode<T>* list_search(T k, bool printSearching);
    void list_insert(T k);
    void list_delete(doubleListNode<T> *xNode);
    void delete_element(T k);
    void list_print();
};

template <class T>
CirDoublyLinkedList<T>::CirDoublyLinkedList()
{
    listNil =new cirDoubleListNode(-1);
    listNil->next = listNil;
    listNil->prev = listNil;
}

template <class T>
void CirDoublyLinkedList<T>::list_insert(T k)
{
    cirDoubleListNode<T> * xNode = new cirDoubleListNode(k);
    return;
}