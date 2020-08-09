#include <iostream>
using namespace std;

template <typename Dtype>
struct cirDbNode {
    Dtype key;
    cirDbNode *prev;
    cirDbNode *next;
    cirDbNode(Dtype x) {key=x; prev=NULL; next=NULL;};
};

template <class T>
class CirDoublyLinkedList
{
public:
    cirDbNode<T> *listNil;
public:
    CirDoublyLinkedList();   // constructor
    cirDbNode<T>* list_search(T k, bool printSearching);
    void list_insert(T k);
    void list_delete(cirDbNode<T> *xNode);
    void delete_element(T k);
    void list_print();
};

template <class T>
CirDoublyLinkedList<T>::CirDoublyLinkedList()
{
    listNil =new cirDbNode<T>(-1);
    listNil->next = listNil;
    listNil->prev = listNil;
}

template <class T>
cirDbNode<T>*  CirDoublyLinkedList<T>::list_search(T k, bool printSearching)
{
    cirDbNode<T> *xNode = listNil->next;
    int idx = 0;
    while (xNode != listNil)
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

template <class T>
void CirDoublyLinkedList<T>::list_insert(T k)
{
    cirDbNode<T> * xNode = new cirDbNode<T>(k);
    xNode->next = listNil->next;
    listNil->next->prev = xNode;
    listNil->next = xNode;
    xNode->prev = listNil;
}

template <class T>
void CirDoublyLinkedList<T>::list_delete(cirDbNode<T> *xNode)
{
    xNode->prev->next = xNode->next;
    xNode->next->prev = xNode->prev;
}

template <class T>
void CirDoublyLinkedList<T>::delete_element(T k)
{
    cirDbNode<T> *tgtNode = list_search(k, false);
    list_delete(tgtNode);
}


template <class T>
void CirDoublyLinkedList<T>::list_print()
{
    cirDbNode<T> *tempNode = listNil->next;
    while(tempNode != listNil)
    {
        cout << tempNode->key << " -> ";
        tempNode = tempNode->next;
    }
    cout << "L.nil" << endl;
}

