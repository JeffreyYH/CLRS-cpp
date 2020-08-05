#include <iostream>
using namespace std;

template <typename Dtype>
struct doubleListNode {
    Dtype key;
    doubleListNode *prev;
    doubleListNode *next;
    doubleListNode(Dtype x) {key=x; prev=NULL; next=NULL;};
};

template <class T>
class DoubleLinkedList
{
public:
    doubleListNode<T> *head, *tail;

public:
    DoubleLinkedList() {head = NULL; tail = NULL;};   // constructor
    void list_search(T k);
    void list_insert(T x);
    void list_delete(T x);
    void list_print();
};

template <class T>
void DoubleLinkedList<T>::list_search(T k)
{
    doubleListNode<T> *xNode = this->head;
    int idx = 0;
    while (xNode != NULL)
    {
        if (xNode->key == k)
        {
            cout << "element " << k << " found in position " << idx << endl;
            return;
        }
        xNode = xNode ->next;
        idx ++;
    }
    cout << "element not found" << endl;
}

// insert a node in front of head
template <class T>
void DoubleLinkedList<T>::list_insert(T x)
{
    doubleListNode<T> *xNode = new doubleListNode(x);
    xNode->next = head;
    if (head != NULL)
        head->prev = xNode;
    head = xNode;
    xNode->prev = NULL;
}

template <class T>
void DoubleLinkedList<T>::list_delete(T k)
{

}

// print from head to tail
template <class T>
void DoubleLinkedList<T>::list_print()
{
    doubleListNode<T> *tempNode = head;
    while(tempNode)
    {
        cout << tempNode->key << " -> ";
        tempNode = tempNode->next;
    }
    cout << "NIL" << endl;
}


