#include <iostream>
using namespace std;

template <typename Dtype>
struct doublyListNode {
    Dtype key;
    doublyListNode *prev;
    doublyListNode *next;
    doublyListNode(Dtype x) {key=x; prev=NULL; next=NULL;};
};

template <class T>
class DoublyLinkedList
{
public:
    doublyListNode<T> *head, *tail;

public:
    DoublyLinkedList() {head = NULL; tail = NULL;};   // constructor
    doublyListNode<T>* list_search(T k, bool printSearching);
    void list_insert(T k);
    void list_delete(doublyListNode<T> *xNode);
    void delete_element(T k);
    void list_print();
};

template <class T>
doublyListNode<T>* DoublyLinkedList<T>::list_search(T k, bool printSearching)
{
    doublyListNode<T>* xNode = this->head;
    int idx = 0;
    while (xNode != NULL)
    {
        if (xNode->key == k)
        {
            if (printSearching)
                cout << "element " << k << " found in position " << idx << endl;
            return xNode;
        }
        xNode = xNode ->next;
        idx ++;
    }
    if (printSearching)
        cout << "element " << k << " not found" << endl;
}

// insert a node in front of head
template <class T>
void DoublyLinkedList<T>::list_insert(T k)
{
    doublyListNode<T> *xNode = new doublyListNode<T>(k);
    xNode->next = head;
    if (head != NULL)
        head->prev = xNode;
    head = xNode;
    xNode->prev = NULL;
}

// delete one node
template <class T>
void DoublyLinkedList<T>::list_delete(doublyListNode<T> *xNode)
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
void DoublyLinkedList<T>::delete_element(T k)
{
    doublyListNode<T>* tgtNode = list_search(k, false);
    list_delete(tgtNode);
}

// print from head to tail
template <class T>
void DoublyLinkedList<T>::list_print()
{
    doublyListNode<T> *tempNode = head;
    while(tempNode)
    {
        cout << tempNode->key << " -> ";
        tempNode = tempNode->next;
    }
    cout << "NIL" << endl;
}


