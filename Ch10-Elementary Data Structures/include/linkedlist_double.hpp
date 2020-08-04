#include <iostream>
using namespace std;

template <typename Dtype>
struct doubleListNode {
    Dtype key;
    doubleListNode *prev;
    doubleListNode *next;
    doubleListNode(Dtype x) {data=x; prev=NULL; next=NULL;};
};

template <class T>
class DoubleLinkedList
{
public:
    doubleListNode<T> *head, *tail;

public:
    // constructor
    DoubleLinkedList() {head = NULL; tail = NULL;};
    void list_search(T k);
    void list_insert(T x);
    void list_delete(T x);
};

template <class T>
void DoubleLinkedList<T>::list_search(T k)
{
    return;
}

// insert a node in front of head
template <class T>
void DoubleLinkedList<T>::list_insert(T x)
{
    doubleListNode<T> *xNode = new doubleListNode(x);
    xNode->next = head;
    if (head != NULL)
        head->prev = nNode;
    head = xNode;
    xNode->prev = NULL;
}


