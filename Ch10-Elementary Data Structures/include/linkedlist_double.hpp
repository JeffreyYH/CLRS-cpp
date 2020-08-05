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
    doubleListNode<T>* list_search(T k);
    void list_insert(T k);
    void list_delete(doubleListNode<T> *xNode);
    void delete_element(T k);
    void list_print();
};

template <class T>
doubleListNode<T>* DoubleLinkedList<T>::list_search(T k)
{
    doubleListNode<T>* xNode = this->head;
    int idx = 0;
    while (xNode != NULL)
    {
        if (xNode->key == k)
        {
            cout << "element " << k << " found in position " << idx << endl;
            return xNode;
        }
        xNode = xNode ->next;
        idx ++;
    }
    cout << "element not found" << endl;
}

// insert a node in front of head
template <class T>
void DoubleLinkedList<T>::list_insert(T k)
{
    doubleListNode<T> *xNode = new doubleListNode(k);
    xNode->next = head;
    if (head != NULL)
        head->prev = xNode;
    head = xNode;
    xNode->prev = NULL;
}

// delete one node
template <class T>
void DoubleLinkedList<T>::list_delete(doubleListNode<T> *xNode)
{
    if(xNode->prev != NULL)     // xNode not head
        xNode->prev->next = xNode->next;
    else                        // xNode is head
        this->head = xNode->next;
    if (xNode->next !=NULL)     // xNode not tail
        xNode->next->prev = xNode->prev;
}

// delete node with element
template <class T>
void DoubleLinkedList<T>::delete_element(T k)
{

    return;

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


